import java.util.HashSet;
import java.util.Set;



class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null) return null;
        Set<ListNode> mySet = new HashSet<>();
        mySet.add(head);
        for (ListNode curNode = head.next; curNode != null; curNode = curNode.next){
            if (!mySet.contains(curNode)) {
                mySet.add(curNode);
            } else {
                return curNode;
            }
        }
        return null;
    }
}

public class Main {
    public static void main(String[] args) {
        // System.out.println(res);
        return;
    }
}
