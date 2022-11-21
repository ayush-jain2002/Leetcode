class Solution {
public:
    int calculate(string s) {
         int n = s.size();
         int number=0;
         int result=0;
         int sign=1;
         stack<int>st;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                number=number*10 + (s[i]-'0');
            }
            else if(s[i] == '+'){
                result+=(number * sign);
                number=0;
                sign=1;
            }
            else if(s[i] == '-'){
                result+=(number * sign);
                number=0;
                sign=-1;
            }
            else if(s[i] == '('){
                st.push(result);
                st.push(sign);
                number=0;
                result=0;
                sign=1;
            }
            else if(s[i] == ')'){
                result+=(number * sign);
                int prev_sign = st.top();
                st.pop();
                int prev_res = st.top();
                st.pop();
                result *= prev_sign;
                result+=prev_res;
                number=0;
            }
        }
        result+=(number * sign);
        return result;
    }
};