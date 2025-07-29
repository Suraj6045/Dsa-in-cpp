#include<bits/stdc++.h>
using namespace std;

int remove(vector<int> &arr , int n){
    int j=0;
    for(int i=0 ; i<n ; i++){
        if(arr[i] != arr[j]){
            arr[j+1] = arr[i];
            j++;
        }
    }
    return j+1;
}

int left_rotate_1(vector<int> &arr , int n){
    int temp = arr[0];
    for(int i=1 ; i<n ; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}

int left_rotate_k(vector<int> &arr , int n , int k){
    vector<int> temp;
    k = k%n;
    for(int i=0 ; i<k ; i++){
        temp.push_back(arr[i]);
    }
    for(int i=k ; i<n ; i++){
        arr[i-k] = arr[i];
    }
    for(int i=n-k ; i<n ; i++){
        arr[i] = temp[i-(n-k)];
    }

}

int rev(vector<int> &arr , int st , int end){
    int i = st;
    int j = end;
    while(i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

int left_rotate_k_optimized(vector<int> &arr , int n , int k){
    k = k%n;
    rev(arr,0,k-1);
    rev(arr,k,n-1);
    rev(arr,0,n-1);

}

int move_zeroes(vector<int> &arr , int n){
    vector<int> temp;
    for(int i=0 ; i<n ; i++){
        if(arr[i] != 0){
            temp.push_back(arr[i]);
        }
    }
    int i=0;
    for(auto it : temp){
        arr[i] = it;
        i++;
    }
    for(int j=i ; j<n ; j++){
        arr[j] = 0;
    }

}

void move_zeroes_optimized(vector<int> &arr , int n){
    int i = 0;
    for(int j=0 ; j<n ; j++){
        if(arr[j] == 0){
            i=j;
            break;
        }
    }
    for(int j=i+1 ; j<n ; j++){
        if(arr[j] != 0){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
}

int linear_search(vector<int> &arr , int n , int target){
    for(int i=0 ; i<n ; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

vector<int> union_brute(vector<int> a1 , vector<int> a2 , int n1 , int n2){
    set<int> s;
    vector<int> new_arr;
    for(int i=0 ; i<n1 ; i++){
        s.insert(a1[i]);
    }
    for(int i=0 ; i<n2 ; i++){
        s.insert(a2[i]);
    }
    for(auto it : s){
        new_arr.push_back(it);
    }
    return new_arr;
}

vector<int> union_optimized(vector<int> a1 , vector<int> a2 , int n1 , int n2){
    vector<int> new_arr;
    int i = 0 , j = 0;
    while(i<n1 && j<n2){
        if(a1[i]<a2[j]){
            if(new_arr.size()==0 || a1[i]!=new_arr.back()){
                new_arr.push_back(a1[i]);
            }
            i++;
        }
        else{
            if(new_arr.size()==0 || a2[j]!=new_arr.back()){
                new_arr.push_back(a2[j]);
            }
            j++;
        }
    }
    while(i<n1){
        if(new_arr.size()==0 || a1[i]!=new_arr.back()){
            new_arr.push_back(a1[i]);
            i++;
        }
    }
    while(j<n2){
        if(new_arr.size()==0 || a2[j]!=new_arr.back()){
                new_arr.push_back(a2[j]);
                j++;
            }
    }
    return new_arr;
}

vector<int> intersection_brute(vector<int> a1 , vector<int> a2 , int n1 , int n2){
    vector<int> ans;
    vector<int> vis(n2);
    for(int i=0 ; i<n1 ; i++){
        for(int j=0 ; j<n2 ; j++){
            if(a1[i]==a2[j] && vis[j]==0){
                ans.push_back(a1[i]);
                vis[j] = 1;
                break;
            }
            if(a1[i]<a2[j]){
                break;
            }
        }
    }
    return ans;
}

vector<int> intersection_optimized(vector<int> a1 , vector<int> a2 , int n1 , int n2){
    vector<int> ans;
    int i = 0;
    int j = 0;
    while(i<n1 && j<n2){
        if(a1[i]<a2[j]){
            i++;
        }
        else if(a1[i]>a2[j]){
            j++;
        }
        else{
            ans.push_back(a1[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int missing_num(vector<int> arr , int n){
    for(int i=1 ; i<=n ; i++){
        int cnt = 0;
        for(int j=0 ; j<n ; j++){
            if(arr[j]==i){
                cnt++;
            }
        }
        if(cnt==0){
            return i;
        }
    }
    return -1;
}

int missing_num_better(vector<int> arr , int n){
    vector<int> hash(n+1);
    for(int i=0 ; i<n ; i++){
        hash[arr[i]] = 1;
    }
    for(int j=1 ; j<n+1 ; j++){
        if(hash[j]==0){
            return j;
        }
    }
    return -1;
    
}

int missing_num_optimized_1(vector<int> arr , int n){
    int sum = arr[n-1]*(arr[n-1]+1)/2;
    int calcu = 0;
    for(int i=0 ; i<n ; i++){
        calcu += arr[i];
    }
    return sum-calcu;
}

int missing_num_optimized_2(vector<int> arr , int n){
    int x1 = 0;
    int x2 = 0;
    for(int i=0 ; i<n ; i++){
        x1 = x1^arr[i];
        x2 = x2^(i+1);
    }
    x2 = x2^(n+1);
    return x1^x2;
}

int max_consec_ones(vector<int> arr , int n){
    int max = 0;
    int cnt = 0;
    for(int i=0 ; i<n ; i++){
        if(arr[i]==1){
            cnt++;
        }
        else{
            cnt = 0; 
        }
        if(cnt>max){
            max = cnt;
        }
    }
    return max;
}

int num_appear_once(vector<int> arr , int n){
    for(int i=0 ; i<n ; i++){
        int cnt = 0;
        for(int j=0 ; j<n ; j++){
            if(arr[i]==arr[j]){
                cnt++;
            }
        }
        if(cnt==1){
            return arr[i];
        }
    }
    return -1;
}

int num_appear_once_optimized(vector<int> arr , int n){
    int x = 0;
    for(int i=0 ; i<n ; i++){
        x = x^arr[i];
    }
    return x;
}

int long_sub(vector<int> arr , int n , int k){
    int max = 0;
    for(int i=0 ; i<n ; i++){
        int sum = 0;
        for(int j=i ; j<n ; j++){
            sum += arr[j];
            if(sum==k && (j-i+1)>max){
                max = j-i+1;
            }
        }
    }
    return max;
}

int long_sub_better(vector<int> arr , int n , int k){
    map<int,int> m;
    int maxlen = 0 , sum = 0;
    for(int i=0 ; i<n ; i++){
        sum += arr[i];
        if(sum == k && maxlen<i+1){
            maxlen = i+1;
        }
        int rem = sum - k;
        if(m.find(rem) != m.end() && maxlen<i-m[rem]){
            maxlen = i-m[rem];
        }
        if(m.find(sum) == m.end()){
            m[sum]=i;
        }
    }
    return maxlen;
}

int long_sub_best(vector<int> arr , int n , int k){
    int maxlen = 0 , sum = arr[0];
    int i = 0 , j = 0;
    while(i<n){
        while(sum>k && i>=j){
            sum -= arr[j];
            j++;
        }

        if(sum == k && maxlen<i-j){
            maxlen = i-j+1;
        }

        i++;
        sum += arr[i];
    }
    return maxlen;
}


int main(){
    vector<int> arr1,arr2;
    arr1 = {1,1,0,1,6,1,1,1,5};
    arr2 = {1,1,1,0,0,1,5,1};
    cout << long_sub_best(arr2,8,3);
    
}