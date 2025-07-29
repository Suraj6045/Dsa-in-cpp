#include<iostream>
#include<vector>
using namespace std;

void selec_sort(int *arr,int n){
    for(int i=0 ; i<n-1 ; i++){
        int min = i;
        for(int j=i ; j<n ; j++){
            if(arr[min]>arr[j]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void bub_sort(int *arr,int n){
    for(int i=0 ; i<n-1 ; i++){
        for(int j=0 ; j<n-i-1 ; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }
        }
    }
}

void insert_sort(int *arr,int n){
    for(int i=0 ; i<n ; i++){
        int j = i;
        while(j>0 && arr[j]<arr[j-1]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}

void recur_bub_sort(int *arr , int n , int i = 0 , int j = 0,int didswap = 0){
    if(i==n-1){
        return;
    }
    else if(j==n-i-1){
        if(arr[j]>arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            didswap++;
        }
        if(didswap==0){
            cout << "no swap";
            return;
        }
        recur_bub_sort(arr,n,i+1,0,0);
    }
    else {
        if(arr[j]>arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            didswap++;
        }
        recur_bub_sort(arr,n,i,j+1,didswap);
    }
}

void recur_inser_sort(int *arr , int n , int i){
    if(i==n){
        return;
    }
    int j=i;
    while(j>0 && arr[j-1]>arr[j]){
        int temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
        j--;
    }
    recur_inser_sort(arr,n,i+1);
}

void merge(int *arr , int start , int mid , int end){
    vector<int> temp;
    int st = start;
    int x = mid+1;
    while(st<=mid && x<=end){
        if(arr[st]<arr[x]){
            temp.push_back(arr[st]);
            st++;
        }
        else{
            temp.push_back(arr[x]);
            x++;
        }
    }
    while(st<=mid){
        temp.push_back(arr[st]);
        st++;
    }
    while(x<=end){
        temp.push_back(arr[x]);
        x++;
    }
    for(int i=start ; i<=end ; i++){
        arr[start+i] = temp[i];
    }
    
}

void merge_sort(int*arr , int start , int end){
    if(start>=end){
        return;
    }
    int mid = (start+end)/2;
    int x = mid+1;
    merge_sort(arr,start,mid);
    merge_sort(arr,x,end);
    merge(arr,start,mid,end);
}

int main(){
    int arr1[5] = {10,15,32,9,6};
    int arr2[5] = {8,9,12,13,14};
    merge_sort(arr1,0,5);
    for(int i=0 ; i<5 ; i++){
        cout << arr1[i] << " ";
    }
}