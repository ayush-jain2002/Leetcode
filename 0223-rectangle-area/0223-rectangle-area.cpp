class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        vector<pair<int,int>>v1(2);
          vector<pair<int,int>>v2(2);
        v1[0]={ax1,ax2};v1[1]={ay1,ay2};
          v2[0]={bx1,bx2};v2[1]={by1,by2};
      if(ax1>bx1){
         v2[0]={ax1,ax2};v2[1]={ay1,ay2};
          v1[0]={bx1,bx2};v1[1]={by1,by2};
      }
        int minus;
       if(v1[0].second<=v2[0].first ||(abs(v1[1].first-v1[1].second)+abs(v2[1].first-v2[1].second)<=abs(min(v1[1].first,v2[1].first)-max(v1[1].second,v2[1].second)))){
           // cout<<(v1[0].second<=v2[0].first)<<endl;
           // cout<<(abs(v1[1].first-v1[1].second)+abs(v2[1].first-v2[1].second)<=abs(min(v1[1].first,v2[1].first)-max(v1[1].second,v2[1].second)))<<endl;
          minus=0;
           
       }
        else{
        int x1=max(v1[0].first,v2[0].first);
        int x2=min(v1[0].second,v2[0].second);
        int y1=max(v1[1].first,v2[1].first);
        int y2=min(v1[1].second,v2[1].second);
        minus=(x2-x1)*(y2-y1);
        }
        int total=(((v1[0].second-v1[0].first)*(v1[1].second-v1[1].first))+(v2[0].second-v2[0].first)*(v2[1].second-v2[1].first));
        return total-minus;
     
    }
};