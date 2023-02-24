//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      unordered_set<int> rows, cols;
      long long int nb_zero_beg = n*n;
      vector<long long int> count_zero;
      for (int i = 0; i < k; i++) {
          
        int r, c;
        
        r = arr[i][0];
        c = arr[i][1];
        
        long long int nb_1_rows = 0;
        long long int nb_1_cols = 0;
        long long int nb_1 = 0;
        
        if(rows.find(r) == rows.end()) {
            rows.insert(r);
            nb_1_rows = n;
            nb_1_rows -= cols.size();
        }
        
        
        if(cols.find(c) == cols.end()) {
            cols.insert(c);
            nb_1_cols = n;
            nb_1_cols -= rows.size();
        }
        
        
        if (nb_1_rows < 0) nb_1_rows = 0;
        if (nb_1_cols < 0) nb_1_cols = 0;
        
        nb_1 = nb_1_cols + nb_1_rows;
        
        nb_zero_beg -= nb_1;
        
        count_zero.push_back(nb_zero_beg);
      }
      
      return count_zero;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends