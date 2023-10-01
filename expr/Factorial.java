import java.math.BigDecimal;

public class Factorial {
    private static BigDecimal factorial(int num) {
        if (num == 1)
            return new BigDecimal(1);
        else
            return (new BigDecimal(num)).multiply(factorial(num - 1));
    }
    public static void main(String[] args) {
        BigDecimal result = factorial(199);
        System.out.println("result  = "+ result.toString());
    }
}
