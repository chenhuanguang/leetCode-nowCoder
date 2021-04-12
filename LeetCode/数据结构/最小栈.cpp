class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() 
    {

    }
    
    void push(int val) 
    {
        _st1.push(val);
        if (_st2.empty() || _st1.top() <= _st2.top())
        {
            _st2.push(val);
        }
    }
    
    void pop() 
    {
        if (_st1.top() == _st2.top())
        {
            _st2.pop();
        }
        _st1.pop();
    }
    
    int top() 
    {
        return _st1.top();
    }
    
    int getMin() 
    {
        return _st2.top();
    }
private:
    stack<int> _st1;//普通栈
    stack<int> _st2;//辅助栈
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */