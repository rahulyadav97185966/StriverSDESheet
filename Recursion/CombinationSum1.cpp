#include<bits/stdc++.h>
using namespace std;
void CombinationSum(vector<int>& arr, int target, vector<vector<int>> &ans, vector<int> &output, int index) {
    if(target == 0) {
        //sort(output.begin(),output.end());
        ans.push_back(output);
        return ;
    }
    if(target < 0 || index >= arr.size() ){
        return ;
    }
    //exclude
    CombinationSum(arr, target, ans, output, index+1);
    //include
    output.push_back(arr[index]);
    CombinationSum(arr, target-arr[index], ans, output, index);
    output.pop_back();
}
vector<vector<int>> combSum(vector<int>& ARR, int B)
{
	// Write your code here
	// Return a vector of sorted vectors/combinations
    sort(ARR.begin(), ARR.end());
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    CombinationSum(ARR, B, ans, output, index);
    reverse(ans.begin(), ans.end());
    return ans;
}
