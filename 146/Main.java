import java.util.HashMap;
import java.util.Map;

class LRUCache {
    private int[] elem;
    private int[] order;
    private Map<Integer, Integer> myMap; // <key, pos>
    private int count = 0;

    public LRUCache(int capacity) {
        this.elem = new int[capacity];
        this.order = new int[capacity];
        this.myMap = new HashMap<>();
    }
    
    public int get(int key) {
        if (myMap.containsKey(key)) {
            order[myMap.get(key)] = count++;
            return elem[myMap.get(key)];
        } else {
            return -1;
        }
    }
    
    public void put(int key, int value) {
        if (myMap.containsKey(key)) {
            elem[myMap.get(key)] = value;
            order[myMap.get(key)] = count++;
        } else {
            if (myMap.size() < elem.length) {
                myMap.put(key, myMap.size());
                elem[myMap.get(key)] = value;
                order[myMap.get(key)] = count++;
            } else {
                int k = getLeastKey();
                myMap.put(key, myMap.get(k));
                myMap.remove(k);
                elem[myMap.get(key)] = value;
                order[myMap.get(key)] = count++;
            }
        }
    }

    private int getLeastKey() {
        if (order.length == 0) return -1;
        int curLeastKey = 0, curLeastVal = Integer.MAX_VALUE;
        for (int key : myMap.keySet()) {
            if (order[myMap.get(key)] < curLeastVal) {
                curLeastKey = key;
                curLeastVal = order[myMap.get(key)];
            }
        }
        return curLeastKey;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

public class Main {
    public static void main(String[] args) {
        int capacity = 2;
        LRUCache obj = new LRUCache(capacity);
        obj.put(1,1);
        obj.put(2,2);
        System.out.println(obj.get(1));
        obj.put(3,3);
        System.out.println(obj.get(2));
        obj.put(4,4);
        System.out.println(obj.get(1));
        System.out.println(obj.get(3));
        System.out.println(obj.get(4));
        
        // System.out.println(res);
        return;
    }
}
