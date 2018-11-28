import java.util.Scanner;
class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    while(s.hasNext()) {
      String line = s.nextLine();
      int sum = 0;
      boolean flag = false;
      for (int i = 0; i < line.length(); i++) {
        if (Character.isLetter(line.charAt(i))) {
          if (!flag) sum++;
          flag = true;
        } else {
          flag = false;
        }
      }
      System.out.println(sum);
    }
  }
}
