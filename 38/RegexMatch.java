import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Solution {
    public String countAndSay(int n) {
        String curStr = "1";
        Pattern pattern = Pattern.compile("(.)\\1+");
        for (int i = 1; i < n; ++i) {
            Matcher m = pattern.matcher(curStr);
            StringBuilder nextSbd = new StringBuilder();
            while (m.find()) {
                nextSbd.append(String.valueOf(m.group().length()));
                nextSbd.append(m.group().charAt(0));
            }
            curStr = nextSbd.toString();
        }
        
        return curStr;
    }
}

public class RegexMatch {
    public static void main(String[] args) {
        int n = 4;
        String res = new Solution().countAndSay(n);
        System.out.println(res);
    }
}
