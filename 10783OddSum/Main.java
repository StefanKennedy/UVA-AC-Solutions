import java.util.Scanner;
class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    for(int i = 0; i < n; i++) {
      int j = s.nextInt();
      if (j%2==0) j++;
      int k = s.nextInt();
      int sum = 0;
      for (;j<=k;j+=2) {
        sum+=j;
      }
      System.out.println("Case " + (i+1) + ": " + sum);
    }
  }
}
