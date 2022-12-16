class MinStack {
public:
  
    stack<pair<int,int>>s;
    int mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
         s.push({val,mini});
        mini=min(mini,val);
    }
    
    void pop() {
        mini=s.top().second;
       s.pop();
    }
    
    int top() {
      return s.top().first;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */