import java.util.LinkedList;
import java.util.Queue;

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
    public Node connect(Node root) {
        if (root == null) return null;

        Queue<Node> que = new LinkedList<>();
        que.offer(root);
        int cnt = 0, expected = 1, next_expected = 1;
        while (!que.isEmpty()) {
            Node cur = que.poll();
            cnt++;
            if (cur.left != null) {
                que.offer(cur.left);
                next_expected++;
            }
            if (cur.right != null) {
                que.offer(cur.right);
                next_expected++;
            }
            
            if (cnt == expected) {
                cur.next = null;
                expected = next_expected;
            } else {
                cur.next = que.peek();
            }
        }

        return root;
    }
}

public class Main {
    public static void main(String[] args) {
        return;
    }
}
