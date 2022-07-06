class MinStack {
public:
    /** initialize your data structure here. */
    int q[110], q_min[110], t1 = -1, t2 = -1;
    MinStack() {

    }
    
    void push(int x) {
        q[++t1] = x;
        if (t2 < 0 || x < q_min[t2]) q_min[++t2] = x;
        else q_min[t2 + 1] = q_min[t2], t2++; 
    }
    
    void pop() {
        t1--, t2--;
    }
    
    int top() {
        return q[t1];
    }
    
    int getMin() {
        return q_min[t2];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */