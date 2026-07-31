class Solution {
public:
    bool isValid(string str) {
        stack<char> st; // list of stack
        for (int i = 0; i < str.size(); i++) {
            // for opening check to ush to the stack
            if (str[i] == '(' || str[i] == '{' || str[i]=='[') {
                st.push(str[i]);
            } else {
                    if (st.size() == 0) {
                        return false;
                    }
                    //for closing checkk up 
                    if ((st.top() == '(' && str[i] == ')') ||
                        (st.top() == '{' && str[i] == '}') ||
                        (st.top() == '[' && str[i] == ']')) {
                        st.pop();
                    } else {
                        return false;  // no match and its invalid paranthesis
                    }
                }
        }
        return st.size()==0;
    }
};