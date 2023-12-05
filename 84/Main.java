import java.util.Stack;

class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        Stack<Integer> stk = new Stack<>();
        int maxArea = 0;
        stk.push(-1);
        for (int i = 0; i < n; i++) {
            while (stk.peek() != -1 && heights[i] < heights[stk.peek()]) {
                int curHeight = heights[stk.pop()];
                int curWidth = i - stk.peek() - 1;
                maxArea = Math.max(maxArea, curWidth * curHeight);
            }
            stk.push(i);
        }
        while (stk.peek() != -1) {
            int curHeight = heights[stk.pop()];
            int curWidth = n - stk.peek() - 1;
            maxArea = Math.max(maxArea, curWidth * curHeight);
        }

        return maxArea;
    }
} 

public class Main {
    public static void main(String[] args) {
        return;
    }
}
