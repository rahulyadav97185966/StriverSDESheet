#include <bits/stdc++.h>

void Solve(vector<int>& nums, vector<int> output, int index, set<vector<int>> &s) {
        if(index >= nums.size()){
            s.insert(output);
            return;
        }
        //exclude
        Solve(nums,output, index+1,s);
        //include
        output.push_back(nums[index]);
        Solve(nums,output, index+1,s);
        output.pop_back();
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<int> output;
    int index = 0;
    sort(arr.begin(),arr.end());
    set<vector<int>> s;
    Solve(arr,output, index, s);
    return vector<vector<int>>(s.begin(),s.end());
}
