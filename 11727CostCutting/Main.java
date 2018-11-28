import java.util.Scanner;
class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    s.nextInt();
    int i = 0;
    while(s.hasNext()) {
      i++;
      int a = s.nextInt(), b = s.nextInt(), c = s.nextInt();
      if ((a > b && a < c) || (a > c && a < b)) {
        System.out.println("Case " + i + ": " + a);
      }
      if ((b > a && b < c) || (b < a && b > c)) {
        System.out.println("Case " + i + ": " + b);
      }
      if ((c > a && c < b) || (c < a && c > b)) {
        System.out.println("Case " + i + ": " + c);
      }
    }
  }
}
