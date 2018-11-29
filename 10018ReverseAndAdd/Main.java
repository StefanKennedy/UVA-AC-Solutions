import java.util.Scanner;
class Main {
  static long reverseInt(long in) {
    long reversed = in % 10;
    while (true) {
      in /= 10;
      if (in == 0) break;
      reversed = reversed * 10 + (in % 10);
    }
    return reversed;
  }

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    s.nextInt();
    while(s.hasNext()) {
      long a = s.nextInt();
      int i = 0;
      while (true) {
        long reversed = reverseInt(a);
        if (i > 0 && a == reversed) break;
        i++;
        a = a + reversed;
      }
      System.out.println(i + " "+ a);
    }
  }
}
