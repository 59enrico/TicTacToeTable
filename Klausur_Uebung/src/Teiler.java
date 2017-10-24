
public class Teiler {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

			
		for(int i = 0; i<=1000; i++){
			if(i%42==0){					//gib alle zahlen aus die durch 42 teilbar sind
				System.out.print(i);
				if(i%5==0){					//schreibe hinter alle Zahlen die zusätzlich durch 5 teilbar sind ein !
					System.out.print("!");
				}
				System.out.println();
			}
		}
		
		
	}

}
