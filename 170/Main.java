import java.util.ArrayList;
import java.util.List;

class TwoSum {
    List<Integer> list;

    public TwoSum() {
        this.list = new ArrayList<>();
    }
    
    public void add(int number) {
        if (list.size() == 0) {
            list.add(number);
            return;
        }

        int l = 0, r = list.size() - 1;
        if (number <= list.get(l)) {
            list.add(0, number);
            return;
        }
        if (number >= list.get(r)) {
            list.add(number);
            return;
        }

        while (l < r - 1) {
            int mid = (l + r) >> 1;
            if (list.get(mid) < number) {
                l = mid;
            } else if (list.get(mid) > number) {
                r = mid;
            } else {
                list.add(mid, number);
                return;
            }
        }
        list.add(r, number);
    }
    
    public boolean find(int value) {
        int l = 0, r = list.size() - 1;
        while (l < r) {
            if (list.get(l) + list.get(r) < value) {
                l++;
            } else if (list.get(l) + list.get(r) > value) {
                r--;
            } else {
                return true;
            }
        }
        return false;
    }

    public void print_list() {
        System.out.print("{");
        for (int i = 0; i < list.size() - 1; ++i) {
            System.out.printf("%d,", list.get(i));
        }
        System.out.printf("%d}\n", list.get(list.size() - 1));
    }
}

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * boolean param_2 = obj.find(value);
 */

public class Main {
    public static void main(String[] args) {
        String[] actions = {"add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find","find"};
        int[] vals = {-12,25,-20,-22,12,-39,11,-15,25,47,-24,18,21,-21,32,-11,-35,37,-8,-18,42,17,16,-46,-27,-34,43,31,-13,44,-6,10,19,12,-11,-12,-25,-39,40,36,-19,-43,12,42,-39,3,-33,-5,0,48,-34,-41,-18,16,43,43,21,-1,-7,7,-13,26,17,-33,-47,23,-7,38,-4,-29,-40,-11,-6,-34,-32,46,25,-6,22,0,-45,-20,-36,3,-46,39,15,19,28,0,29,9,34,22,-8,1,-28,0,40,47,-20,20,3,-42,14,-1,-38,31,40,-31,-26,41,16,-30,-20,24,2,8,32,42,2,4,-50,30,-11,-50,-9,-38,41,-28,-44,-8,27,-35,-8,19,-36,29,-21,24,-43,-30,-11,48,30,49,26,-32,-41,39,40,-46,-28,-15,2,23,-39,-28,-15,42,-1,44,-46,-9,-6,39,9,37,-49,3,14,43,-36,-46,23,2,-6,-48,6,6,40,25,47,2,11,-13,29,24,-21,26,-19,-8,-31,-30,-20,-18,-13,-27,-47,-11};
        TwoSum twoSum = new TwoSum();
        for (int i = 0; i < actions.length; ++i) {
            if (actions[i] == "add") {
                twoSum.add(vals[i]);
                System.out.printf("Add %d: ", vals[i]);
                twoSum.print_list();
            } else if (actions[i] == "find") {
                boolean res = twoSum.find(vals[i]);
                System.out.printf("Find %d: ", vals[i]);
                System.out.println(res);
            }
        }
    }
}
