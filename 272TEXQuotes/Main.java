import java.util.Scanner;
class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    boolean flag = true;
    while(scanner.hasNext()){
      String newString = "";
      String string = scanner.nextLine();
      for (int i = 0; i < string.length(); i++) {
        char ithChar = string.charAt(i);
        if (ithChar == '"') {
          if (flag) newString += "``";
          else newString += "''";
          flag = !flag;
        } else newString += ithChar;
      }
      System.out.println(newString);
    }
  }
}
