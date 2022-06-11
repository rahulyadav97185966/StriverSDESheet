#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
      vector<vector<long long int >>v;
      v.push_back({1});
    if(n==1) return v;
    v.push_back({1,1});
    if(n==2) return v;
    for(int i=2;i<n;i++)
    {
        int k=v[i-1].size();
        vector<long long int>s(k+1,1);
        for(int j=1;j<v[i-1].size();j++)
        {
            s[j]=v[i-1][j]+v[i-1][j-1];
        }
        v.push_back(s);
    }
    return v;
}
