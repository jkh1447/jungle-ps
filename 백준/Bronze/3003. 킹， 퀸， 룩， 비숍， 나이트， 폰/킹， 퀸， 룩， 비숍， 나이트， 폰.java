import java.util.Scanner;

public class Main
{
	public static void main(String[] args) {
	    int[] chess = new int[6];
		Scanner sc = new Scanner(System.in);
		for(int i = 0; i<6; i++){
		    chess[i] = sc.nextInt();
		}
		chess[0] = 1 - chess[0];
		chess[1] = 1 - chess[1];
		chess[2] = 2 - chess[2];
		chess[3] = 2 - chess[3];
		chess[4] = 2 - chess[4];
		chess[5] = 8 - chess[5];
		for(int i=0; i<6; i++){
		    if(i<5)
		        System.out.print(chess[i]+" ");
		    else
		        System.out.print(chess[i]);
		    
		}
	}
}
