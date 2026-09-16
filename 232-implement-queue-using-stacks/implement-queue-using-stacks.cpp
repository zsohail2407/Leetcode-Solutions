class MyQueue {
public:
    stack<int> a, b;
    MyQueue()
    {  
        
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        moveIfNeeded();
        int front = b.top();
        b.pop();
        return front;
    }
    
    int peek() {
        moveIfNeeded();
        return b.top();
    }
    
    bool empty() {
        return a.empty() && b.empty();
    }

private:
    void moveIfNeeded() {
        if (b.empty()) {
            while (!a.empty()) {
                b.push(a.top());
                a.pop();
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */