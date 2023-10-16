import java.util.List;
import java.util.Map;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}

class Solution {
    public Node cloneGraph(Node node) {
        if (node == null) return null;

        Map<Node, Node> visited = new HashMap<>();
        Queue<Node> que = new LinkedList<>();
        que.offer(node);
        visited.put(node, new Node(node.val, new ArrayList<>()));
        while (!que.isEmpty()) {
            Node curNode = que.poll();
            for (Node neighbor: curNode.neighbors) {
                if (!visited.containsKey(neighbor)) {
                    que.offer(neighbor);
                    visited.put(neighbor, new Node(neighbor.val, new ArrayList<>()));
                }
                visited.get(curNode).neighbors.add(visited.get(neighbor));
            }
        }

        return visited.get(node);
    }
}

public class Main {
    public static void main(String[] args) {
        return;
    }
}
