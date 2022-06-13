#include <bits/stdc++.h>
vector<int> nextPermutation(vector<int> &permutation, int n)
{
   int cnt=0;
   for(int i=0;i<n-1;i++){
       if(permutation[i]>permutation[i+1])cnt++;
   }
   if(cnt==n-1)
   {
       sort(permutation.begin(),permutation.end());
       return permutation;
   }
   else{
       int j=n-1;
    for(int i=n-1;i>=1;i--){
           if(permutation[i]>permutation[i-1])
           {
               j=i-1;
               break;
           }
       }
       int k=n-1;
       for(int i=n-1;i>j;i--){
           if(permutation[i]>permutation[j])
           {
               k=i;
               break;
           }
       }
       swap(permutation[j],permutation[k]);
       sort(permutation.begin()+j+1,permutation.end());
       return permutation;
   }
}
