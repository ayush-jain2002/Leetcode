class Solution {
public:
    
    int totalStrength(vector<int>& arr) {
          int mod=1000000007;
        int n=arr.size();
        vector<long long>prefix(n+1,0);
        vector<long long>pp(n+2,0);
       for(int i=0;i<n;i++){
           prefix[i+1]=(prefix[i]+arr[i])%mod;
       }
        for(int i=0;i<=n;i++){
           pp[i+1]=(pp[i]+prefix[i])%mod;
       }
        
        vector<int>sl(n,-1);
        vector<int>sr(n,n);
        stack<int>st;
        sl[0]=-1;
        sr[n-1]=n;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                sr[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
      stack<int>s;
        s.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!s.empty() && arr[s.top()]>arr[i]){
                sl[s.top()]=i;
                s.pop();
            }
            s.push(i);
            
        }
       
        long long sum=0;
        for(int i=0;i<n;i++){
           
            sum+=((pp[sr[i]+1]-pp[i+1])*(i-sl[i])%mod+mod-(pp[i+1]-pp[sl[i]+1])*(sr[i]-i)%mod)*arr[i];
           if(sum<0) sum+=mod;
            sum%=mod;
        }
        return sum%mod;
    }

    
};