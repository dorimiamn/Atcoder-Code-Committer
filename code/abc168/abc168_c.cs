using System;

class C{
  public static void Main(){
	int[] Ar = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
    int A = Ar[0], B = Ar[1], H = Ar[2], M = Ar[3];
    double shortr = 30 * H;
    shortr += M * 0.5;
    double longr = 6 * M;
    double abs = Math.Abs(longr - shortr);
    double min = Math.Min(abs, 360 - abs);
    double aji = (A * A) + (B * B);
    decimal minus = ((decimal)Math.Cos(min * (Math.PI / 180))* 2 * B * A);
    double ans = Math.Sqrt(aji - (double)minus);
    Console.WriteLine(ans);
  }
}
