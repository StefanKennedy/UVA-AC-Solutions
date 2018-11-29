import java.util.Scanner;
import java.util.LinkedList;
class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    for (int i = 0; i < n; i++) {
      int t = s.nextInt();
      LinkedList<Integer> l = new LinkedList<Integer>();
      for (int j = 0; j < t; j++) {
        l.addLast(s.nextInt());
      }
      int sum = 0;
      for (int j = 1; j <= t; j++) {
        sum += l.indexOf(j);
        l.remove((Object)j);
      }
      System.out.println("Optimal train swapping takes " + sum + " swaps.");
    }
  }
}
