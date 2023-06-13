import java.util.ArrayList;

class Solution {
    private ArrayList<ArrayList<Integer>> dict;

    private ArrayList<Integer> multiplyOneDigit(StringBuilder firstNum, char secondNumDigit, int numZeros) {
        ArrayList<Integer> res = new ArrayList<>();
        if (secondNumDigit == '0') {
            res.add(0);
            return res;
        }

        for (int i = 0; i < numZeros; ++i) {
            res.add(0);
        }
        int carry = 0;
        for (int i = 0; i < firstNum.length(); ++i) {
            int tmp = (secondNumDigit - '0') * (firstNum.charAt(i) - '0') + carry;
            res.add(tmp % 10);
            carry = tmp / 10;
        }
        if (carry > 0) {
            res.add(carry);
        }
        return res;
    }

    private void constructDict(StringBuilder firstNum) {
        dict = new ArrayList<>();
        ArrayList<Integer> zeroArrayList = new ArrayList<>();
        zeroArrayList.add(0);
        dict.add(zeroArrayList);
        for (int i = 1; i <= 9; ++i) {
            ArrayList<Integer> newArrayList = new ArrayList<>();
            int carry = 0;
            for (int j = 0; j < firstNum.length(); ++j) {
                int tmp = i * (firstNum.charAt(j) - '0') + carry;
                newArrayList.add(tmp % 10);
                carry = tmp / 10;
            }
            if (carry > 0) {
                newArrayList.add(carry);
            }
            dict.add(newArrayList);
        }
    }

    private ArrayList<Integer> multiplyOneDigit2(StringBuilder firstNum, char secondNumDigit, int numZeros) {
        ArrayList<Integer> res = new ArrayList<>();
        if (secondNumDigit == '0') {
            res.add(0);
            return res;
        }
        
        for (int i = 0; i < numZeros; ++i) {
            res.add(0);
        }
        ArrayList<Integer> value = dict.get(secondNumDigit - '0');
        res.addAll(value);
        return res;
    }

    private StringBuilder sumResults(ArrayList<ArrayList<Integer>> results) {
        ArrayList<Integer> ans = new ArrayList<>(results.get(0));
        ArrayList<Integer> newAns = new ArrayList<>();

        for (int i = 1; i < results.size(); ++i) {
            ArrayList<Integer> curNum = results.get(i);
            int carry = 0;
            for (int j = 0; j < ans.size() || j < curNum.size(); ++j) {
                int digit1 = j < ans.size() ? ans.get(j) : 0;
                int digit2 = j < curNum.size() ? curNum.get(j) : 0;
                int sum = digit1 + digit2 + carry;
                carry = sum / 10;
                newAns.add(sum % 10);
            }
            if (carry > 0) {
                newAns.add(carry);
            }
            ans = newAns;
            newAns = new ArrayList<>();
        }
        
        StringBuilder ansSbd = new StringBuilder();
        for (int digit : ans) {
            ansSbd.append(digit);
        }
        return ansSbd;
    }

    public String multiply(String num1, String num2) {
        if (num1.equals("0")|| num2.equals("0")) return "0";
        if (num1.length() < num2.length()) return multiply(num2, num1);

        StringBuilder firstNum = new StringBuilder(num1);
        StringBuilder secondNum = new StringBuilder(num2);
        firstNum.reverse();
        secondNum.reverse();

        ArrayList<ArrayList<Integer>> results = new ArrayList<>();
        if (secondNum.length() <= 9) {
            for (int j = 0; j < secondNum.length(); ++j) {
                results.add(multiplyOneDigit(firstNum, secondNum.charAt(j), j));
            }
        } else {
            for (int j = 0; j < secondNum.length(); ++j) {
                constructDict(firstNum);
                results.add(multiplyOneDigit2(firstNum, secondNum.charAt(j), j));
            }
        }
        StringBuilder ans = sumResults(results);

        return ans.reverse().toString();
    }
}

public class Main2 {
    public static void main(String[] args) {
        String num1 = "123", num2 = "456";
        String res = new Solution().multiply(num1, num2);
        System.out.println(res);
    }
}
