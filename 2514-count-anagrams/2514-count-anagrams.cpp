class Solution {
public:
    const int mod=1000000007;
       vector<string> word(string &str)
{
    vector<string>ans;
    istringstream ss(str);
    string word;
    while (ss >> word)
    {
       ans.push_back(word);
    }
    return ans;
}
  int binexp(int a,int b){
      int result=1;
      while(b>0){
          if(b&1){
              result=(result*1LL*a)%mod;
          }
        a=(a*1LL*a)%mod;
          b>>=1;
      }
      return result;
  }
    int countAnagrams(string s) {
        long long fact[100001];
        fact[0]=1;
        for(long long i=1;i<=100000;i++){
            fact[i]=fact[i-1]*i;
            fact[i]%=mod;
        }
        long long ans=1;
        vector<string>v=word(s);
        for(auto &i:v){
            long long a=fact[i.size()]%mod;
            vector<long long>vec;
            unordered_map<char,long long>mp;
            for(auto &it:i) mp[it]++;
            for(auto &it:mp) vec.push_back(it.second);
            long long b=1;
            
            for(auto &it:vec) b*=fact[it],b%=mod;
            ans*=(a*binexp(b,mod-2)%mod);
 
            ans%=mod;
        }
        return ans%mod;
    }
};