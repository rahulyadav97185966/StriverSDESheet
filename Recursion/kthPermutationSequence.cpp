#include<bits/stdc++.h>
using namespace std;
//this permutation using the recursion takes n!*n time which is very high no onw is going to accept this 
// so we will not be using this and will use some different solution

// This is optimise solution
// time completxity TC O(n) // for numbers 
// then we are spliing by selecting one and this takes O(n) time
// So time O(n)*O(n) == O(n^2) and space for vector O(n);
string PermutationOptimsie(int n,int k,string output) {

    int fact = 1;
    vector<int> numbers;
    for(int i=1;i<n;i++){
        fact = fact*i; //this for total number of permutation
        numbers.push_back(i);
    }
    numbers.push_back(n);
    k = k -1;
    while(true) {
        output = output + to_string(numbers[k/fact]);
        numbers.erase(numbers.begin() + k /fact);
        if(numbers.size() == 0){
            break;
        }
        k = k%fact;
        fact = fact / numbers.size();
    }
    return output;
}
string kthPermutation(int n, int k) {
    string out = "";
    return PermutationOptimsie(n,k,out);
}
