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

int once(vector<int> arr){
    int n = arr.size();
    if(n==1){
        return arr[0];
    }
    for(int i=0 ; i<n ; i++){
        if(i==0){
            if(arr[1] != arr[0]) return arr[0];
        }
        else if(i==n-1){
            if(arr[n-1] != arr[n-2]) return arr[n-1];
        }
        else {
            if(arr[i] != arr[i-1] && arr[i] != arr[i+1]){
                return arr[i];
            } 
        }
    }
    return -1;
}

int once_best(vector<int> arr){
    int n = arr.size();
    if(arr[1] != arr[0]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];
    int st = 1;
    int end = n-2;
    while(st<=end){
        int mid = (st+end)/2;
        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]){
            return arr[mid];
        }
        if((mid%2==0 && arr[mid] == arr[mid+1]) || (mid%2==1 && arr[mid] == arr[mid-1])){
            st=mid+1;
        }
        else{
            end = mid-1;
        } 
    }
    return -1;
}

int peak(vector<int> arr){
    int n = arr.size();
    int st = 1;
    int end = n-2;
    if(arr[0]>arr[1]) return arr[0];
    if(arr[n-1]>arr[n-2]) return arr[n-1];
    while(st<=end){
        int mid = (st+end)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return arr[mid];
        }
        else if(arr[mid]>arr[mid-1]){
            st=mid+1;
        }
        else{
            end = mid-1;
        }
    }
}

int sqrt(int num){
    int ans=1;
    int st=1;
    int end = pow(num,0.5);
    while(st<=end){
        int mid = (st+end)/2;
        if(pow(mid,2)<=num){
            ans = mid;
            st = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
}

int count_hours(vector<int> arr , int k){
    int hours = 0;
    for(int i=0 ; i<arr.size() ; i++){
        hours += ceil(double(arr[i])/k);
    }
    return hours;
}

int max_el(vector<int> arr){
    int maxi = INT_MIN;
    for(int i=0 ; i<arr.size() ; i++){
        if(arr[i]>maxi){
            maxi=arr[i];
        }
    }
    return maxi;
}

int min_el(vector<int> arr){
    int min = INT_MAX;
    for(int i=0 ; i<arr.size() ; i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    return min;
}


int koko_eating_bananas(vector<int> arr , int max_hours){
    for(int i=1 ; i<=max_el(arr) ; i++){
        if(count_hours(arr,i)<=max_hours){
            return i;
        }
    }
    return -1;
}

int koko_eating_bananas_best(vector<int> arr , int max_hours){
    int st = 1;
    int end = max_el(arr);
    int ans = -1;
    while(st<=end){
        int mid = (st+end)/2;
        if(count_hours(arr,mid)<=max_hours){
            ans = mid;
            end = mid-1;
        }
        else{
            st = mid+1;
        }
    }
    return ans;
}

int max_no_of_bouquets(vector<int> arr , int consecutive_flowers){
    int n = arr.size();
    int max_bouquets = n/consecutive_flowers;
    return max_bouquets;
}

int min_days(vector<int> arr , int bouquets , int consecutive_flowers){
    if(max_no_of_bouquets(arr,consecutive_flowers)<bouquets){
        return -1;
    }

    for(int day=min_el(arr) ; day<=max_el(arr) ; day++){
        int count_boquets = 0;
        int count = 0;

        for(int j=0 ; j<arr.size() ; j++){
            if(day<arr[j]){  // if flower at j index isn't bloomed
                count_boquets += count/consecutive_flowers;
                count = 0;
            } else{  // if flower at j index is bloomed
                count++;
            }

            if(j==arr.size()-1){
                count_boquets += count/consecutive_flowers;
            }
        }

        if(count_boquets>=bouquets){
            return day;
        }
    }
    return -1;
}

int min_days_best(vector<int> arr , int reqd_bouquets , int consecutive_flowers){
    if(max_no_of_bouquets(arr,consecutive_flowers)<reqd_bouquets){
        return -1;
    }

    int min_day = -1;
    int st = min_el(arr);
    int end = max_el(arr);
    while(st<=end){
        int current_day = (st+end)/2;
        int made_boquets = 0;
        int day_streak = 0;

        for(int bloom_day = 0 ; bloom_day<arr.size() ; bloom_day++){
            if(current_day<arr[bloom_day]){
                made_boquets += day_streak/consecutive_flowers;
                day_streak = 0;
            } else {
                day_streak++;
            }
        }
        made_boquets += day_streak/consecutive_flowers;

        if(made_boquets<reqd_bouquets){
            st = current_day+1;
        } else{
            min_day = current_day;
            end = current_day-1;
        }
    }
    return min_day;
}

int smallest_divisor(vector<int> arr , int threshold){
    for(int i=1 ; i<=max_el(arr) ; i++){
        int sum = 0;
        for(int j=0 ; j<arr.size() ; j++){
            sum += ceil(double(arr[j])/i);
        }
        if(sum<=threshold){
            return i;
        }
    }
    return -1;
}

int smallest_divisor_best(vector<int> arr , int threshold){
    if(threshold<arr.size()) return -1;
    
    int ans = INT_MAX;
    int st = 1;
    int end = max_el(arr);

    while(st<=end){
        int mid = (st+end)/2;
        int sum = 0;

        for(int j=0 ; j<arr.size() ; j++){
            sum += ceil(double(arr[j])/mid);
        }

        if(sum<=threshold){
            ans = min(mid,ans);
            end = mid -1;
        } else {
            st = mid+1;
        }
    }
    return ans;
}


int main(){
    vector<int> arr1;
    vector<int> arr2;
    arr1 = {1,2,3,10,15};
    arr2 = {1,2,3,5,8,8,11};
    cout << smallest_divisor_best(arr1,8);
}    