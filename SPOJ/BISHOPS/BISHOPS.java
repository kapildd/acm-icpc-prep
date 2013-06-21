import java.io.*;
import java.util.*;
//2n-2 bishops
//   B _ _ _ _ _ _ _
//   B _ _ _ _ _ _ B
//   B _ _ _ _ _ _ B
//   B _ _ _ _ _ _ B
//   B _ _ _ _ _ _ B
//   B _ _ _ _ _ _ B
//   B _ _ _ _ _ _ B
//   B _ _ _ _ _ _ _
import java.util.*;
import java.math.*;

class BISHOPS {
    public void run() {
        Scanner in = new Scanner(System.in);
        while (in.hasNextBigInteger()) {
            BigInteger N = in.nextBigInteger();
            if (N.compareTo(BigInteger.ONE) > 0) {
                BigInteger two = new BigInteger("2");
                N = N.multiply(two).subtract(two);
            }
            System.out.println(N);
        }
    }

    public static void main(String[] args) {
        (new Main()).run();
    }
}


