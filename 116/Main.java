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
        int cnt = 0, expected = 1;
        Node prev = null;
        while (!que.isEmpty()) {
            Node cur = que.poll();
            cnt++;
            if (cnt == expected) {
                if (prev != null) prev.next = cur;
                cur.next = null;
                prev = null;
                expected = (expected << 1) + 1;
            } else {
                if (prev != null) prev.next = cur;
                prev = cur;
            }
            if (cur.left != null) que.offer(cur.left);
            if (cur.right != null) que.offer(cur.right);
        }

        return root;
    }
}

public class Main {
    public static void main(String[] args) {
        return;
    }
}
