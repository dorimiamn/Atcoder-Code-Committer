import fs from 'fs';
import { setTimeout } from 'timers/promises';
import {By,Builder,Browser} from 'selenium-webdriver';

// fetch("https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions?user=adomine&from_second=8075009")
//     .then((response)=>response.json())
//     .then((data)=>console.log(data));

//拡張子を決定する関数

function decideExtension(language){
    let languages={   
        'C\\+\\+':'cpp',
        'C#':'cs',
        'C':'c',
        'Python':'py',
        'Java':'java',
    }

    for (let languageName in languages){
        let reg=new RegExp(`^${languageName}`);
        if(reg.test(language)){
            console.log(language,'に該当する拡張子として ' + languages[languageName] +' を決定');
            return languages[languageName];
        }
    }
    return 'txt';
}

//user_id と time を引数として、AtCoder Problems API を叩く
//最大500件の提出をJSONで返す
async function getSubmissions(user_id,time){
    const response= await fetch("https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions?user="+ user_id+"&from_second="+time);
    const submissions=await response.json();

    console.log(Object.keys(submissions).length);

    return submissions;
}

//取得した提出からAtCoderからコードを取得する関数
async function getSubmissionCode(contest_id,submission_id){
    const driver = await new Builder().forBrowser('chrome').build();
    await driver.get('https://atcoder.jp/contests/' + contest_id +'/submissions/' + submission_id);

    const code = await driver.findElement(By.id('for_copy0'));

    const content=await code.getAttribute('textContent');

    // console.log(content);

    await driver.quit();

    return content;
}

//取得したコードをファイルに保存する関数
//コンテストごとにフォルダを作成
async function writeSubmissionCode(contest_id,problem_id,extension,code){
    const dirPath='./code/' + contest_id;
    const filePath= dirPath + '/' + problem_id + '.' + extension;
    if(!fs.existsSync(dirPath)){
        console.log('ディレクトリは存在しません');
        fs.mkdirSync(dirPath,{recursive:true});
    }
    fs.writeFileSync(filePath,code);
    console.log(filePath,"ファイル書き出し完了");
}

//処理の中心となる関数

let unix_second=0;

//取得したACコードをカウンt

async function main(){
    //提出をJSONで複数件取得する
    //最新の提出のunix_secondと取得した提出の最新unix_secondが同じであれば処理を終了する？
    //取得した提出件数が0であれば処理を終了させる
    let isContinue=true;

    while(isContinue){
        console.log('処理開始');

        await getSubmissions('adomine',unix_second).then(async (submissions)=>{
            const len=Object.keys(submissions).length;
            if(len===0){
                isContinue=false;
                return ;
            }
            for(let i=0;i<len;i++){
                console.log(i + '件目のsubmission処理');
                unix_second=submissions[i]["epoch_second"];
                
                if(submissions[i]["result"]!=="AC")continue;
                const submission_id=submissions[i]["id"];
                const contest_id=submissions[i]["contest_id"];
                const problem_id=submissions[i]["problem_id"];
                const language = submissions[i]["language"];

                const extension=decideExtension(language);

                const dirPath='./code/' + contest_id;
                const filePath= dirPath + '/' + problem_id + '.' + extension;
                if(!fs.existsSync(dirPath)){
                    console.log('ディレクトリは存在しません');
                    fs.mkdirSync(dirPath,{recursive:true});
                }
                if(fs.existsSync(filePath)){
                    console.log(filePath,'ファイルは存在します');
                    continue ;
                }
                
                await getSubmissionCode(contest_id,submission_id).then(async(code)=>{
                    console.log(i);
                    await writeSubmissionCode(contest_id,problem_id,extension,code);
                })
                console.log("コード取得処理終了:"+i);
                console.log("unix_second:",unix_second);
                await setTimeout(5000);
            }
            console.log(len + '件の処理終了');
            return ;
        })
        console.log('取得したsubmissionsの処理終了');
        await setTimeout(10000);
    }
    console.log('処理終了');
}

// getSubmissions("adomine",0);
// getSubmissionCode('abc217','b').then((code)=>{
    // writeSubmissionCode('abc217', 'b', code);
// })
// writeSubmissionCode(getSubmissionCode('0','0'));

// getSubmissions("adomine",0)

main();

// decideExtension('C++ (GCC 5.4.1)');