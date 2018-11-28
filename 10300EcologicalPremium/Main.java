import java.util.Scanner;
class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    for (int i = 0; i < n; i++) {
      int f = scanner.nextInt();
      int sum = 0;
      for (int j = 0; j < f; j++) {
        sum+= (scanner.nextInt() + (0*scanner.nextInt())) * scanner.nextInt();
      }
      System.out.println(sum);
    }
  }
}
