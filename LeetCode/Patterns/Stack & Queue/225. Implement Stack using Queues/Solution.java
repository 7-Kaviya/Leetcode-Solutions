import java.util.*;

public class MyStack {
    private Queue<Integer> q1;
    private Queue<Integer> q2;

    public MyStack() {
        q1 = new LinkedList<>();
        q2 = new LinkedList<>();
    }

    public void push(int x) {
        q1.add(x);

        // Move existing stack elements behind x
        while (!q2.isEmpty()) {
            q1.add(q2.remove());
        }

        // Move everything back to q2
        while (!q1.isEmpty()) {
            q2.add(q1.remove());
        }
    }

    public int pop() {
        return q2.remove();
    }

    public int top() {
        return q2.peek();
    }

    public boolean empty() {
        return q2.isEmpty();
    }
}