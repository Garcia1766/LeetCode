import java.util.HashMap;
import java.util.Map;

class ListNode {
    int key;
    int val;
    ListNode prev;
    ListNode next;

    public ListNode() {
        this.key = -1;
        this.val = -1;
    }

    public ListNode(int _key, int _val) {
        this.key = _key;
        this.val = _val;
    }

    public ListNode(int _key, int _val, ListNode _prev, ListNode _next) {
        this.key = _key;
        this.val = _val;
        this.prev = _prev;
        this.next = _next;
    }
}

class LRUCache {
    int capacity;
    Map<Integer, ListNode> dic; // <key, ListNode>
    ListNode head;
    ListNode tail;
    
    public LRUCache(int capacity) {
        this.capacity = capacity;
        dic = new HashMap<>();
        head = new ListNode();
        tail = new ListNode();
        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        if (!dic.containsKey(key)) return -1;
        ListNode tar = dic.get(key);
        remove(tar);
        add(tar);
        return tar.val;
    }
    
    public void put(int key, int value) {
        if (dic.containsKey(key)) {
            ListNode tar = dic.get(key);
            tar.val = value;
            remove(tar);
            add(tar);
        } else {
            ListNode tar = new ListNode(key, value);
            dic.put(key, tar);
            add(tar);
            if (dic.size() > capacity) {
                dic.remove(head.next.key);
                remove(head.next);
            }
        }
    }

    private void add(ListNode node) {
        node.prev = tail.prev;
        node.next = tail;
        tail.prev.next = node;
        tail.prev = node;
    }

    private void remove(ListNode node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
public class Main2 {
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
