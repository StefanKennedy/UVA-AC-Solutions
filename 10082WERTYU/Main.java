import java.util.Scanner;
import java.util.HashMap;
class Main {
  public static void main(String[] args) {
    HashMap<String, String> m = new HashMap<String, String>();
    m.put("W", "Q");
    m.put("E", "W");
    m.put("R", "E");
    m.put("T", "R");
    m.put("Y", "T");
    m.put("U", "Y");
    m.put("I", "U");
    m.put("O", "I");
    m.put("P", "O");
    m.put("S", "A");
    m.put("D", "S");
    m.put("F", "D");
    m.put("G", "F");
    m.put("H", "G");
    m.put("J", "H");
    m.put("K", "J");
    m.put("L", "K");
    m.put("X", "Z");
    m.put("C", "X");
    m.put("V", "C");
    m.put("B", "V");
    m.put("N", "B");
    m.put("M", "N");
    m.put("/", ".");
    m.put(",", "M");
    m.put(".", ",");
    m.put(";", "L");
    m.put("'", ";");
    m.put("'", ";");
    m.put("[", "P");
    m.put("]", "[");
    m.put("\\", "]");
    m.put("2", "1");
    m.put("3", "2");
    m.put("4", "3");
    m.put("5", "4");
    m.put("6", "5");
    m.put("7", "6");
    m.put("8", "7");
    m.put("9", "8");
    m.put("0", "9");
    m.put("-", "0");
    m.put("=", "-");
    m.put("1", "`");

    Scanner s = new Scanner(System.in);
    while (s.hasNext()) {
    char[] cs = s.nextLine().toCharArray();
    for (char c : cs) {
      if (m.containsKey(c+"")) {
        System.out.print(m.get(c+""));
      } else if (c == ' ') {
        System.out.print(c);
      }
    }
    System.out.println();
    }
  }
}
