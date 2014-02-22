import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static final BigInteger TWO = new BigInteger("2");
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		BigInteger N;
		while (in.hasNext()) {
			N = in.nextBigInteger();
			if (N.compareTo(BigInteger.ONE) != 0) {
				N = N.add(N.subtract(TWO));
			}
			System.out.println(N);
		}
		in.close();
	}
}
