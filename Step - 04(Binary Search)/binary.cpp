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

int sum(vector<int> arr){
    int add = 0;
    for(int i=0 ; i<arr.size() ; i++){
        add += arr[i];
    }
    return add;
}

int days_to_ship_all_products(vector<int> arr , int capacity_of_ship){
    int days = 0;
    int total_weight = 0;

    for(int i=0 ; i<arr.size() ; i++){
        if((total_weight+arr[i])<=capacity_of_ship){  // ship me space hai to bharte jao
            total_weight += arr[i];
        } else {  // when the ship is full
            days += 1;
            total_weight = 0;
            total_weight += arr[i];  // for next ship
        }
    }
    if(total_weight>0) days += 1;
    
    return days;
}

int least_capacity(vector<int> arr , int days){
    if(days==0) return -1;

    for(int i=max_el(arr) ; i<=sum(arr) ; i++){
        if(days_to_ship_all_products(arr,i)<=days){
            return i;
        }
    }
    return -1;
}

int least_capacity_best(vector<int> arr , int days){
    if(days==0) return -1;

    int ans = -1;
    int st = max_el(arr);
    int end = sum(arr);
    while(st<=end){
        int capacity = (st+end)/2;

        if(days_to_ship_all_products(arr,capacity)<=days){
            ans = capacity;
            end = capacity-1;
        } else{
            st = capacity+1;
        }
    }
    return ans;
}

int kth_missing_number(vector<int> arr , int k){
    int ans = k;
    int n = arr.size();

    for(int i=0 ; i<n-1 ; i++){
        if(arr[i]>ans){
            break;
        }
        else{
            ans++;
        }
    }
    return ans;
}

int kth_missing_number_best(vector<int> arr , int k){
    int n = arr.size();

    int st = 0;
    int end = n-1;
    while(st<=end){
        int mid = (st+end)/2;
        int missing = arr[mid]-mid-1;
        if(missing<k){
            st = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return end+1+k;
}

bool all_cows_can_fit(vector<int> arr , int distance_btw_cows , int cows){
    sort(arr.begin(),arr.end());

    int count = 1;
    int last_cow = arr[0];

    for(int i=1 ; i<arr.size() ; i++){
        if(arr[i]-last_cow>=distance_btw_cows){
            count++;
            last_cow = arr[i];
        }

        if(count>=cows){
            return true;
        }
    }

    return false;
}

int aggressive_cows(vector<int> arr , int cows){
    for(int i=1 ; i<=arr[arr.size()-1]-arr[0] ; i++){
        if(all_cows_can_fit(arr,i,cows)){
            continue;
        } else{
            return i-1;
        }
    }

    return -1;
}

int aggressive_cows_best(vector<int> arr , int cows){
    if(arr.size()<2) return -1;
    if(arr.size()<cows) return -1;
    if(arr.size()==cows) return 1;
    if(cows==1) return 0;

    int st = 1;
    int end = arr[arr.size()-1]-arr[0];
    int ans = 0;
    
    while(st<=end){
        int dist = (st+end)/2;
        if(all_cows_can_fit(arr , dist , cows)){
            ans = dist;
            st = dist + 1;
        } else {
            end = dist - 1;
        }
    }
    
    return ans;
}

int count_students(vector<int> arr , int max_pages){
    int pages = 0;
    int students = 0;

    for(int i=0 ; i<arr.size() ; i++){
        if(pages+arr[i]<=max_pages){
            pages += arr[i];
        } else{
            students += 1;
            pages = arr[i];
        }
    }

    if(pages>0) students += 1;

    return students;
}

int book_allocation(vector<int> arr , int students){
    if(arr.size()<students) return -1;

    for(int i=max_el(arr) ; i<sum(arr) ; i++){
        if(count_students(arr,i) == students) return i; 
    }

    return -1;
}

int book_allocation_best(vector<int> arr , int students){
    if(arr.size()<students) return -1;

    int st = max_el(arr);
    int end = sum(arr);
    while(st<=end){
        int max_pages = (st+end)/2; 
        if(count_students(arr,max_pages) > students){
            st = max_pages + 1;
        }
        else {
            end = max_pages-1;
        }
    }

    if(count_students(arr,st) == students) return st;
    else return -1;
}

int count_painters(vector<int> arr , int max_area){
    int area = 0;
    int painters = 0;

    for(int i=0 ; i<arr.size() ; i++){
        if(area+arr[i]<=max_area){
            area += arr[i];
        } else{
            painters += 1;
            area = arr[i];
        }
    }

    if(area>0) painters += 1;

    return painters;
}

int painters_partition(vector<int> arr , int painters){
    if(arr.size()<painters) return -1;

    for(int i=max_el(arr) ; i<=sum(arr) ; i++){
        if(count_painters(arr,i) == painters) return i;
    }
    return -1;
}


int main(){
    vector<int> arr1;
    vector<int> arr2;
    arr1 = {10,13,9,37,13};
    arr2 = {1,2,3,5,8,8,11};
    cout << painters_partition(arr1,2);
}    