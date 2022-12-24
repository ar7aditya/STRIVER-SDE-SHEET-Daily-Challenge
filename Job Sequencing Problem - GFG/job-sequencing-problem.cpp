//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends

class Solution 
{
    public:
    static bool compare(Job a ,Job b){
        if(a.profit>b.profit) return true;
        return false;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int maxDeadLine=0,profit=0;
        for(int i=0;i<n;i++){
            maxDeadLine=max(maxDeadLine,arr[i].dead);
        }
        vector<int> ans(maxDeadLine+1,-1);
        sort(arr,arr+n,compare);
        int k=0;
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
               if(ans[j]==-1){
                   ans[j]=i;
                   profit+=arr[i].profit;
                   k++;
                   break;
               }
            }
            
        }
        return {k,profit};
        
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends