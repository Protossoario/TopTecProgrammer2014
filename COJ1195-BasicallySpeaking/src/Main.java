import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		String num;
		int inRadix, outRadix;
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			num = in.next();
			inRadix = in.nextInt();
			outRadix = in.nextInt();
			String result = Integer.toString(Integer.parseInt(num, inRadix), outRadix);
			if (result.length() > 7) {
				System.out.println("  ERROR");
			}
			else {
				for (int i = result.length(); i < 7; i++) {
					System.out.print(" ");
				}
				System.out.println(result.toUpperCase());
			}
		}
		in.close();
	}
}
