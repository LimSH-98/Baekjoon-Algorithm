import java.util.Scanner;

public class main {
	
	public static void main(String[] args) {
		int n, m, i = 0, dif, sum2 = 0;
		int blackJ[];
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		
		m = scanner.nextInt();
		
		blackJ = new int [n];
		
		while(i != n) {
			blackJ[i++] = scanner.nextInt();
		}
		
		dif = m;
		
		for(int j=0;j<n;j++) {
			for(int k=j+1;k<n;k++) {
				for(int p=k+1;p<n;p++) {
					int sum = blackJ[j] + blackJ[k] + blackJ[p];
					int dif2 = m - sum;
					if(sum <= m &&  dif2 < dif) {
						dif = dif2;
						sum2 = sum;
					}
				}
			}
		}
		
		System.out.println(sum2);
	}
}
