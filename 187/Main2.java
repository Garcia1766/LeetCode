import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

// TLE at case 30
class Solution {
    Map<Character, Integer> c2iMap;
    Map<Integer, Character> i2cMap;
    Set<Integer> patSet;

    Solution() {
        c2iMap = new HashMap<>();
        c2iMap.put('A', 0);
        c2iMap.put('C', 1);
        c2iMap.put('G', 2);
        c2iMap.put('T', 3);

        i2cMap = new HashMap<>();
        i2cMap.put(0, 'A');
        i2cMap.put(1, 'C');
        i2cMap.put(2, 'G');
        i2cMap.put(3, 'T');

        patSet = new HashSet<>();
    }

    int string2Int(String dna) { // dna.length()==10
        int res = 0;
        for (int i = 0; i < dna.length(); ++i) {
            res = (res << 2) + c2iMap.get(dna.charAt(i));
        }
        return res;
    }

    String int2String(int val) {
        StringBuilder sbd = new StringBuilder();
        for (int i = 0; i < 10; ++i) {
            sbd.append(i2cMap.get(val % 4));
            val >>= 2;
        }
        return sbd.reverse().toString();
    }

    boolean searchPattern(int pat, String s, int start_pos) {
        for (int i = 0; i <= s.length() - 10; ++i) {
            if (i == start_pos) continue;
            if (string2Int(s.substring(i, i + 10)) == pat) {
                return true;
            }
        }
        return false;
    }

    public List<String> findRepeatedDnaSequences(String s) {
        List<String> res = new ArrayList<>();
        for (int i = 0; i <= s.length() - 10; i++) {
            int pat = string2Int(s.substring(i, i + 10));
            if (patSet.contains(pat)) continue;
            patSet.add(pat);
            if (searchPattern(pat, s, i)) {
                res.add(s.substring(i, i + 10));
            }
        }
        return res;
    }
}

public class Main2 {
    public static void main(String[] args) {
        String s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
        List<String> res = new Solution().findRepeatedDnaSequences(s);
        System.out.println(res);
    }
}
