import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		int n = stdIn.nextInt();
		long[] a = new long[n];
		for(int i = 0; i < n; i++) {
			a[i] = stdIn.nextLong();
		}
		
		long[]s = new long[n+1];
		for(int i = 0; i < n; i++) {
			s[i+1] = s[i] + a[i];
		}
		Map<Long,Long> map = new HashMap<>();
		
		for(int i = 0; i < n+1; i++) {
			if(!map.containsKey(s[i])) {
				map.put(s[i], (long)0);
			}
			map.put(s[i], map.get(s[i])+1);
		}
		long cnt = 0;
		
		/*for(int i = 0; i < map.size(); i++) {
			if(map.get(s[i]) < 2) {
				continue;
			}else {
				cnt += map.get(s[i])*(map.get(s[i])-1)/2;
			}
		}*/
		
		for(long ss: map.keySet()) {
			if(map.get(ss) < 1) {
				continue;
			}else {
              	long x=map.get(ss);
				cnt += x*(x-1)/2;
			}
		}
		
		System.out.println(cnt);
		
	}

}