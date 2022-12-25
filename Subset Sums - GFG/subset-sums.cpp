//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
vector<int> ans;
    void f(int i,vector<int> arr,int sum){
        if(i==0){
            ans.push_back(sum);
            sum+=arr[i];
            ans.push_back(sum);
            return;
        }
        f(i-1,arr,sum);
        f(i-1,arr,sum+arr[i]);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
       f(N-1,arr,0);
       return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends