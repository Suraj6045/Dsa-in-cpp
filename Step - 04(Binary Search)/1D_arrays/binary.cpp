#include<bits/stdc++.h>
using namespace std;

int binary_search_iterative(vector<int> arr , int target){
    int n = arr.size();
    int st = 0;
    int end = n-1;
    for(int i=0 ; i<n ; i++){
        int mid = (st+end)/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid]>target) end = mid-1;
        else st=mid+1; 
    }
    return -1;
}

int binary_search_recursive(vector<int> arr , int target , int st , int end){
    while(st<=end){
        int mid = (st+end)/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid]>target) return binary_search_recursive(arr,target,0,mid-1);
        else return binary_search_recursive(arr,target,mid+1,end); 
    }
    return -1;
}

int times_array_rotated(vector<int> arr){
    int st = 0;
    int end = arr.size()-1;
    int min = INT_MAX;
    while(st<=end){
        int mid = (st+end)/2;
        if(arr[mid]==arr[st] && arr[mid]==arr[end]){
            st++;
            end--;
        }
        if(arr[mid]>arr[st]){
            min = st;
            st = mid+1;
        }
        else {
            min = mid;
            end = mid-1;
        }
    }
    return min+1;
}

int main(){
    vector<int> arr1;
    vector<int> arr2;
    arr1 = {6,2,3,4,5};
    arr2 = {1,2,3,5,8,8,11};
    cout << times_array_rotated(arr1);
}    