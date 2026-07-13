class Solution {
public:

    int help(int a, int b, string s) {
        if(s == "+") {
            return a + b;
        } else if(s == "-") {
            return a - b;
        } else if(s == "*") {
            return a*b;
        } else {
            return a/b;
        }
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans;
        int n = tokens.size();
        for(int i=0;i<n;i++) {
            // agr operator hai to
            string s = tokens[i];
            if(s == "+" || s == "-" || s =="*" || s == "/" ) {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                int num = help(left,right,s);
                st.push(num);
            }
            // agr number hai to
            else {
                int num = stoi(tokens[i]);
                st.push(num);
            }
        }
        return st.top();
    }
};
