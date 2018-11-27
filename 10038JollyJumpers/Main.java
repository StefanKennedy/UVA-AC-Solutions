import java.util.Scanner;
import java.util.Collections;
import java.util.List;
import java.util.ArrayList;
class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    while (s.hasNext()) {
      int n = s.nextInt();
      if (n == 0) continue;
      int last = s.nextInt();
      List<Integer> absolutes = new ArrayList<Integer>();
      for (int i = 1; i < n; i++) {
        int neww = s.nextInt();
        absolutes.add(Math.abs(last - neww));
        last = neww;
      }
      Collections.sort(absolutes);
      for (int i = 0; i < n; i++) {
        if (i == n-1) {
          System.out.println("Jolly");
          break;
        }
        if (absolutes.get(i) != (i+1)) {
          System.out.println("Not jolly");
          break;
        }
      }
    }
  }
}
