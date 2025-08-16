#include<iostream>
using namespace std;


// sum of n numbers
int sum(int n){
    if(n==1){
        return 1;
    }
    return n+sum(n-1);
}

// reverse an array using loop
void rever(int *arr, int n){
    for(int i=0 ; i<=n/2-1 ; i++){
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-1-i] = temp;
    }
}

// reverse an array using recursion
void reverse(int *arr,int i, int j){
    if(i>=j){
        return;
    }
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    reverse(arr,i+1,j-1);
}

// check for palindrome
bool pal(string s,int i){
    int n = s.size();
    if(i>=n/2){
        return true;
    }
    if(s[i] != s[n-i-1]){
        return false;
    }
    return pal(s,i+1);
}


int main() {
    string s = "papaap";
    cout << pal(s,0);
}


