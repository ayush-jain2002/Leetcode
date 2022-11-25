class Solution {
public:
    long long calc(long long d){
        return d*(d+1)/2;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>sl(n,-1);
        vector<int>sr(n,n);
        stack<int>st;
        sl[0]=-1;
        sr[n-1]=n;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                sr[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
      stack<int>s;
        s.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                sl[s.top()]=i;
                s.pop();
            }
            s.push(i);
            
        }
       
        long long sum=0;
        for(int i=0;i<n;i++){
           
            int  left=(i-sl[i]);
            int right=(sr[i]-i);
            sum+=(arr[i])*1LL*(left*right);
        }
        return sum%(1000000007);
    }
};