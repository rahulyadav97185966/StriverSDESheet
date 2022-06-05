#include<algorithm>
void Solve(vector<int> &arr, int n, int target, vector<vector<int>> &ans, vector<int> &output, int index) {
    if(target == 0){
        ans.push_back(output);
        return ;
    }
    if(target < 0 || index >= n){
        return;
    }
    for(int i=index;i<arr.size();i++){
        if(i > index && arr[i] == arr[i-1]) continue;
        output.push_back(arr[i]);
        Solve(arr,n,target-arr[i],ans,output, i+1);
        output.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
    vector<vector<int>> ans;
    vector<int> output;
    sort(arr.begin(), arr.end());
    Solve(arr,n, target, ans, output, 0);
    return ans;
}
