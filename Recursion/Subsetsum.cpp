
void Solve(vector<int> &num, vector<int> &ans, int sum, int n, int index) {
    if(index >= n){
        ans.push_back(sum);
        return ;
    }
    //exclude
    Solve(num, ans, sum, n, index+1);
    //include
    sum += num[index];
    Solve(num, ans, sum, n, index+1);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> ans;
    Solve(num, ans, 0 , num.size(), 0);
    sort(ans.begin(),ans.end());
    return ans;
}
