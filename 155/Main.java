import java.util.ArrayList;
import java.util.List;

class MinStack {
    List<Integer> stk;
    List<Integer> minStk;

    public MinStack() {
        this.stk = new ArrayList<>();
        this.minStk = new ArrayList<>();
    }
    
    public void push(int val) {
        stk.add(val);
        if (stk.size() == 1) {
            minStk.add(val);
        } else { // stk.size() >= 2
            minStk.add(Math.min(minStk.get(minStk.size() - 1), val));
        }
    }
    
    public void pop() {
        stk.remove(stk.size() - 1);
        minStk.remove(minStk.size() - 1);
    }
    
    public int top() {
        return stk.get(stk.size() - 1);
    }
    
    public int getMin() {
        return minStk.get(minStk.size() - 1);
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

public class Main {
    public static void main(String[] args) {
        MinStack minStack = new MinStack();
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        minStack.getMin(); // return -3
        minStack.pop();
        minStack.top();    // return 0
        minStack.getMin(); // return -2
    }
}
