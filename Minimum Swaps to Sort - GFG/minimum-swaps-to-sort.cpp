//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n=nums.size();
	    vector<pair<int,int>>v(n);
	    int c=0;
	    for(int i=0;i<n;i++){
	        v[i]={nums[i],i};
	    }
	    sort(begin(v),end(v));
	    for(int i=0;i<n;i++){
	        
	        if(v[i].second==i)continue;
	        else{
	            swap(v[i].first,v[v[i].second].first);
	            swap(v[i].second,v[v[i].second].second);
	           
	        }
	        if(v[i].second!=i) i--;
	        c++;
	    }
	    return c;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends