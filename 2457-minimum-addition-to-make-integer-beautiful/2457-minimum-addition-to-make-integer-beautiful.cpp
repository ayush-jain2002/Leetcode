class Solution {
public:
    long long power(int x){
        long long ans=1;
        while(x){
            ans*=10;
            x--;
        }
        return ans;
    }
    long long f(long long x){
         long long sum=0;
       
        while(x){
            sum+=x%10;
            x/=10;
        }
        return sum;
    }
    long long makeIntegerBeautiful(long long n, long long target) {
       long long s=f(n);
        if(s<=target) return 0;
       long long cpy=n;
        long long i=1;
        long long  ans;
        while(true){
              long long rem=cpy%power(i);
              long long sum=f(rem);
              if(s+1-sum<=target){
                  ans=power(i)-rem;
                  break;
              }
            i++;
        }
        return ans;
    }
};