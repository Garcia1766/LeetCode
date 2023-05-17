import java.util.Arrays;
import java.util.stream.Collectors;

class Solution {
    private String addVerticalLine(String s) {
        StringBuilder sbd = new StringBuilder();
        sbd.append('|');
        for (int i = 0; i < s.length(); ++i) {
            sbd.append(s.charAt(i));
            sbd.append('|');
        }
        return sbd.toString();
    }

    private String removeVerticalLine(String S) {
        StringBuilder sbd = new StringBuilder();
        for (int i = 0; i < S.length(); ++i) {
            if (i % 2 == 1) {
                sbd.append(S.charAt(i));
            }
        }
        return sbd.toString();
    }

    public String longestPalindrome(String s) {
        String S = addVerticalLine(s);

        int n = S.length();
        String[] palindromes = new String[n];
        int[] palindromeRadi = new int[n];
        
        int center = 0;
        int radius = 0;
        while (center < n) {
            while (center - (radius + 1) >= 0 && center + (radius + 1) < n
                && S.charAt(center - (radius + 1)) == S.charAt(center + (radius + 1))) {
                    radius += 1;
            }
            palindromeRadi[center] = radius;
            palindromes[center] = S.substring(center - radius, center + radius + 1);

            int oldCenter = center;
            int oldRadius = radius;
            center += 1;

            radius = 0;
            while (center <= oldCenter + oldRadius) {
                int mirroredCenter = oldCenter - (center - oldCenter);
                int maxMirroredRadius = oldCenter + oldRadius - center;

                if (palindromeRadi[mirroredCenter] < maxMirroredRadius) {
                    palindromeRadi[center] = palindromeRadi[mirroredCenter];
                    palindromes[center] = S.substring(center - palindromeRadi[center], center + palindromeRadi[center] + 1);
                    center += 1;
                } else if (palindromeRadi[mirroredCenter] > maxMirroredRadius) {
                    palindromeRadi[center] = maxMirroredRadius;
                    palindromes[center] = S.substring(center - palindromeRadi[center], center + palindromeRadi[center] + 1);
                    center += 1;
                } else { // palindromeRadi[mirroredCenter] == maxMirroredRadius
                    radius = maxMirroredRadius;
                    break;
                }
            }
        }

        int targetIndex = Arrays.stream(palindromeRadi).boxed().collect(Collectors.toList()).indexOf(
            Arrays.stream(palindromeRadi).max().getAsInt());

        return removeVerticalLine(palindromes[targetIndex]);
    }
}

public class Manacher {
    public static void main(String[] args) {
        String s = "aacabdkacaa";
        String res = new Solution().longestPalindrome(s);
        System.out.println(res);
    }
}
