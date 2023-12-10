import java.util.HashMap;
import java.util.Map;

class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        StringBuilder sbd = new StringBuilder();
        if (numerator < 0 ^ denominator < 0) sbd.append("-");

        long dividend = Math.abs(Long.valueOf(numerator));
        long divisor = Math.abs(Long.valueOf(denominator));
        sbd.append(String.valueOf(dividend / divisor));
        long reminder = dividend % divisor;
        if (reminder == 0) return sbd.toString();
        sbd.append(".");
        Map<Long, Integer> map = new HashMap<>();
        while (reminder != 0) {
            if (map.containsKey(reminder)) {
                sbd.insert(map.get(reminder), "(");
                sbd.append(")");
                break;
            }
            map.put(reminder, sbd.length());
            reminder *= 10;
            sbd.append(String.valueOf(reminder / divisor));
            reminder %= divisor;
        }
        
        return sbd.toString();
    }
}


public class Main {
    public static void main(String[] args) {
        int numerator = 4, denominator = 333;
        String res = new Solution().fractionToDecimal(numerator, denominator);
        System.out.println(res);
    }
}
