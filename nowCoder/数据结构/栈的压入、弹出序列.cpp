class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> st;
        int sz = pushV.size();
        int pushIdx = 0;
        int popIdx = 0;
        
        for (int i = 0; i < sz; ++i)
        {
            st.push(pushV[pushIdx++]);
            while (!st.empty() && st.top() == popV[popIdx])
            {
                st.pop();
                ++popIdx;
            }
        }
        return st.empty();
    }
};