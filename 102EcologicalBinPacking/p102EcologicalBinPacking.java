import java.util.Scanner;

public class p102EcologicalBinPacking {

	public static <T> void p(T o){
		System.out.print(o);
	}
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		while(s.hasNext()){
			int b1 = s.nextInt(), g1 = s.nextInt(), c1 = s.nextInt(),
					b2 = s.nextInt(), g2 = s.nextInt(), c2 = s.nextInt(),
					b3 = s.nextInt(), g3 = s.nextInt(), c3 = s.nextInt();
			
			int numBGC = b2 + b3 + g1 + g3 + c1 + c2;
			int numBCG = b2 + b3 + c1 + c3 + g1 + g2;
			int numGBC = b1 + b3 + c1 + c2 + g2 + g3;
			int numGCB = b1 + b2 + c1 + c3 + g2 + g3;
			int numCBG = b1 + b3 + c2 + c3 + g1 + g2;
			int numCGB = b1 + b2 + c2 + c3 + g1 + g3;
			
			int min = Math.min(numBGC, Math.min(numBCG, Math.min(numGBC, Math.min(numGCB, Math.min(numCBG, numCGB)))));
	
			if(min == numBCG){
				p("BCG ");
			}else if(min == numBGC){
				p("BGC "); 
			}else if(min == numCBG){
				p("CBG ");
			}else if(min == numCGB){
				p("CGB ");
			}else if(min == numGBC){
				p("GBC ");
			}else if(min == numGCB){
				p("GCB ");
			}
			p(min);
			System.out.println();
		}
		
		s.close();
	}

}
