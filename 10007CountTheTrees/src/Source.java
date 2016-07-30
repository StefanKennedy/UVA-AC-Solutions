import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;


public class Main {

	public static BigInteger fact(BigInteger toFact){
		BigInteger result = BigInteger.valueOf(1);
		for(int i = 1; i <= toFact.longValue(); i++){
			BigInteger mult = BigInteger.valueOf(i);
			result = result.multiply(mult);
		}
		return result;
	}
	
	public static void main(String[] args){
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		try {
			int input = Integer.parseInt(br.readLine());
			
			while(input != 0){
				
				BigInteger TwoNChooseN = fact(BigInteger.valueOf(input).multiply(BigInteger.valueOf(2))).divide(fact(BigInteger.valueOf(input))).divide(fact(BigInteger.valueOf(input)));
				
				System.out.println(TwoNChooseN.multiply(fact(BigInteger.valueOf(input))).divide(BigInteger.valueOf(input + 1)));
				
				input = Integer.parseInt(br.readLine());
			}
			
			
		} catch (NumberFormatException | IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
}
