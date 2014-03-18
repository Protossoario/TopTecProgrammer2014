import java.util.Scanner;
import java.util.GregorianCalendar;
class Main {
	public static void main(String [] args) {
		Scanner in = new Scanner(System.in);
		int D, H, M;
		GregorianCalendar start = new GregorianCalendar(2011, GregorianCalendar.NOVEMBER, 11, 11, 11);
		D = in.nextInt();
		H = in.nextInt();
		M = in.nextInt();
		GregorianCalendar end = new GregorianCalendar(2011, GregorianCalendar.NOVEMBER, D, H, M);
		long diff = end.getTimeInMillis() - start.getTimeInMillis();
		if (diff < 0) {
			System.out.println("-1");
		}
		else {
			System.out.println(diff / 60000);
		}
		in.close();
	}
}
