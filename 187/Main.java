import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

// TLE at case 30
class Solution {
    Set<Integer> posSet = new HashSet<>();
    Set<String> strSet = new HashSet<>();

    boolean KMpSearch(String pat, String txt, int start_pos) {
        int M = pat.length(), N = txt.length();
        int[] lps = computeLPSArray(pat);
        int i = 0, j = 0;
        int foundTimes = 0;
        while ((N - i) >= (M - j)) {
            if (pat.charAt(j) == txt.charAt(i)) {
                j++;
                i++;
            }
            if (j == M) {
                if (posSet.contains(i - j)) {
                    return false;
                } else {
                    posSet.add(i - j);
                    foundTimes++;
                    j = lps[j - 1];
                }
            } else if (i < N && pat.charAt(j) != txt.charAt(i)) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return foundTimes > 1;
    }

    int[] computeLPSArray(String pat) {
        int M = pat.length();
        int len = 0;
        int i = 1;
        int[] lps = new int[M];

        while (i < M) {
            if (pat.charAt(i) == pat.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = len;
                    i++;
                }
            }
        }
        return lps;
    }

    public List<String> findRepeatedDnaSequences(String s) {
        List<String> res = new ArrayList<>();
        for (int i = 0; i <= s.length() - 10; i++) {
            String pat = s.substring(i, i + 10);
            if (strSet.contains(pat)) continue;
            strSet.add(pat);
            if (KMpSearch(pat, s, i)) {
                res.add(pat);
            }
        }
        return res;
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
        List<String> res = new Solution().findRepeatedDnaSequences(s);
        System.out.println(res);
    }
}
