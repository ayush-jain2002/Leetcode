class Solution {
public:
    bool check(char ch){
        if(ch=='A' || ch=='a' || ch=='E' || ch=='e' || ch=='I' || ch=='i' || ch=='O' || ch=='o' || ch=='U' || ch=='u') return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int i=0,j=s.size()/2;
        int a=0,b=0;
        for(;j<s.size();){
            if(check(s[i++])) a++;
            if(check(s[j++])) b++;
        }
        return a==b;
    }
};