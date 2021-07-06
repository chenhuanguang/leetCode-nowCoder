class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() 
    {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        pushSt.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
        if (popSt.size() == 0)
        {
            if (pushSt.size() == 0)
            {
                return -1;
            }
            else
            {
                while (pushSt.size() != 0)
                {
                    popSt.push(pushSt.top());
                    pushSt.pop();
                }
            }
        }
        int val = popSt.top();
        popSt.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() 
    {
        if (popSt.size() == 0)
        {
            if (pushSt.size() == 0)
            {
                return -1;
            }
            else
            {
                while (pushSt.size() != 0)
                {
                    popSt.push(pushSt.top());
                    pushSt.pop();
                }
            }
        }
        int val = popSt.top();
        return val;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() 
    {
        return pushSt.empty() && popSt.empty();
    }

private:
    stack<int> pushSt;
    stack<int> popSt;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */