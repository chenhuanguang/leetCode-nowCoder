class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const auto&str : tokens)
        {
            if (str == "+" || str == "-"
                || str == "*" || str == "/")
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                if (str == "+")
                    st.push(left + right);
                else if (str == "-")
                    st.push(left - right);
                else if (str == "*")
                    st.push(left * right);
                else
                    st.push(left / right);
            }
            else
            {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};