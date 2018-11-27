//import java.util.Scanner;
import java.io.DataInputStream;
import java.io.DataOutputStream;
class Main {
  public static void main(String[] args) {
    //Scanner s = new Scanner(System.in);
    DataInputStream in = new DataInputStream(System.in);
    DataOutputStream out = new DataOutputStream(System.out);
    while(true) {
      try {
        byte b = in.readByte();
        if (b == -1) break;
        if (b == 10) out.writeByte(10);
        else out.writeByte(b-7);
        out.flush();
      } catch (java.io.IOException e) {
        break;
      }
    }
  }
}
