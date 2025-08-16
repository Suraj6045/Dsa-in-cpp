#include<iostream>
using namespace std;

int main(){
    int arr[5] = {1,2,3,4,5};
    int hash_arr[6] = {0};
    for(int i=0 ; i<5 ; i++){
        hash_arr[arr[i]] += 1;
    }

    for(int i=0 ; i<6 ; i++){
        cout << hash_arr[i];
    }
}