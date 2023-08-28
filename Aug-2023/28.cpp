// this is leetcode daily challenge of 28 Aug 2023
// problem link : https://leetcode.com/problems/implement-stack-using-queues/description/

class MyStack {
public:

    queue<int> q1,q2;
    int last=-1;

    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        last=x;
    }
    
    int pop() {

        if(q1.empty())
            return -1;

        int x;
        while(q1.size()>1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        x=q1.front();
        q1.pop();

        while(q2.size()>1)
        {
            q1.push(q2.front());
            q2.pop();
        }

        if(!q2.empty())
        {
            last=q2.front();
            q1.push(q2.front());
            q2.pop();
        }

        return x;
    }
    
    int top() {
        return last;
    }
    
    bool empty() {
        if(q1.empty())
            return true;
        return false;
    }
};
