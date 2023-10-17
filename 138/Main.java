import java.util.HashMap;
import java.util.Map;

class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}

class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) return null;

        Map<Node, Node> myMap = new HashMap<>();
        Node origin = head;
        myMap.put(origin, new Node(origin.val));
        while (origin != null) {
            if (origin.next != null && !myMap.containsKey(origin.next))
                myMap.put(origin.next, new Node(origin.next.val));
            if (origin.random != null && !myMap.containsKey(origin.random))
                myMap.put(origin.random, new Node(origin.random.val));
            if (origin.next != null) myMap.get(origin).next = myMap.get(origin.next);
            if (origin.random != null) myMap.get(origin).random = myMap.get(origin.random);

            origin = origin.next;
        }
        return myMap.get(head);
    }
}

public class Main {
    public static void main(String[] args) {
        // System.out.println(res);
        return;
    }
}
