class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
          if(st.empty() && (c==')' || c=='}' || c==']'))
            return false;
          switch (c) {
            case ')':
              if(st.top()=='(')
                st.pop();
              else
                st.push(c);
              break;
            case '}':
              if(st.top()=='{')
                st.pop();
              else
                st.push(c);
              break;
            case ']':
              if(st.top()=='[')
                st.pop();
              else
                st.push(c);
              break;
            default:
              st.push(c);
          }
        }
        if(st.empty())
          return true;
        else
          return false;
    }
};