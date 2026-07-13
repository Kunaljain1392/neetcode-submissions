class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        for(int i=0;i<n;i++) {
            char sr = s[i];
            if(sr == '[' || sr == '{' || sr == '(') {
                st.push(sr);
            } else {
                if(st.empty()) {
                    return false;
                }

                if(sr == ')' && st.top() != '(') {
                    return false;
                }
                if(sr == '}' && st.top() != '{' ) {
                    return false;
                }
                if(sr == ']' && st.top() != '[' ) {
                    return false;
                }
                st.pop();
            }

        }
        return st.empty();
    }
};
