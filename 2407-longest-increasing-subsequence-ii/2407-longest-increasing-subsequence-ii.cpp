class Solution {
public:
    vector<int>seg;
    int n;
    void update(int index,int val,int left,int right,int pos){
            if(index<left || index>right) return;
           if(left==right){
                   if(index==left) seg[pos]=max(seg[pos],val);
                   return;
           }
            int mid=left+(right-left)/2;
            update(index,val,left,mid,2*pos+1);
             update(index,val,mid+1,right,2*pos+2);
            seg[pos]=max(seg[2*pos+1],seg[2*pos+2]);
    }
    int maxi(int l,int r,int left,int right,int ind){
            if(l<=left && r>=right) return seg[ind];
            if(l>right || r<left) return INT_MIN;
               int mid=left+(right-left)/2;
           return max( maxi(l,r,left,mid,2*ind+1),
             maxi(l,r,mid+1,right,2*ind+2));
           
    }    
    int lengthOfLIS(vector<int>& nums, int k) {
        n=1e5;
        seg.resize(2*(1<<17),0);
        int mx=1;
            for(auto i:nums){
                    
                    int curr=max(0,i-k);
                    int lcs=maxi(curr,i-1,0,n,0)+1;
                     mx=max(mx,lcs);
                    update(i,lcs,0,n,0);
                   
                   
            }
         return mx;   
    }
};