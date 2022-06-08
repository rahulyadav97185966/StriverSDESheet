#include<bits/stdc++.h>
using namespace std;

int pivotSearch(int arr[], int n){
    int start = 0;
    int end = n-1;
    while(start <= end){
        int mid = (start+end)/2; //or we can user start + (end - start)/2
        
        if(arr[mid] > arr[mid+1] && mid+1 != n){
            return mid;
        }
        if(arr[mid] < arr[mid-1] && mid-1 >= 0) {
            return mid-1;
        }

        if(arr[mid] > arr[0]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
}
int binarySearch(int arr[], int s,int n, int target){
    int start = s;
    int end = n;
    while(start <= end){
        int mid = (start+end)/2; //or we can user start + (end - start)/2
        if(arr[mid] == target)
        {
            return mid;
        }
        if(target > arr[mid]) {
            start = mid+1;
        }
        else {
            end = mid-1;
        }
    }
    return -1;
}
int search(int* arr, int n, int key) {
    // Write your code here.
    
    int k = pivotSearch(arr,n);
    int r = binarySearch(arr,0,k,key);
    if(r != -1){
        return r;
    }
    else{
        int secondhalf = binarySearch(arr,k+1,n-1,key);
        if(secondhalf != -1){
            return secondhalf;
        }
        else{
            return -1;
        }
    }
}
