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
        // for(int i=0;i<n;i++){
        //     cout<<sl[i]<<" "<<sr[i]<<endl;
        // }
        long long sum=0;
        for(int i=0;i<n;i++){
            long long total=calc(sr[i]-sl[i]-1);
            long long left=calc(i-sl[i]-1);
            long long right=calc(sr[i]-i-1);
            sum+=(arr[i])*1LL*(total-left-right);
        }
        return sum%(1000000007);
    }
};