#include<bits/stdc++.h>

void Permutation(string &s, vector<string> &ans, int index) {
    if(index >= s.length()){
        ans.push_back(s);
        return;
    }
    for(int j=index;j<s.length();j++) {
        swap(s[j],s[index]);
        Permutation(s,ans,index+1);
        swap(s[j],s[index]);
    }
}


vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    Permutation(s,ans,0);
    return ans;
}
