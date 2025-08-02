#include<bits/stdc++.h>
using namespace std;

int pascal(int n , int m){
    int ans = 1;
    for(int i=1 ; i<m ; i++){
        ans *= (n-i+1)/i;        
    }
    return ans;
}

vector<int> pascal_row(int n){
    vector<int> ans;
    int current = 1;
    ans.push_back(current);
    for(int i=0 ; i<n ; i++){
        current *= (n-i);
        current /= (i+1);
        ans.push_back(current);        
    }
    return ans;   
}

vector<vector<int>> pascal_traingle(int n){
    vector<vector<int>> ans;
    for(int i=0 ; i<=n ; i++){
        vector<int> temp = pascal_row(i);
        ans.push_back(temp);
    }
    return ans;
}

vector<int> maj(vector<int> arr , int n){
    vector<int> ans;
    for(int i=0 ; i<n ; i++){
        int count = 0;
        for(int j=0 ; j<n ; j++){
            if(arr[i]==arr[j]){
                count++;
            }
            if(count>n/3){
                if(ans.size()==0 || ans[0] != arr[i])
                    ans.push_back(arr[i]);
            }
            if(ans.size()>=2){
                return ans;
            }
        }
    }
    return ans;
}

vector<int> maj_better(vector<int> arr , int n){
    vector<int> ans;
    map<int,int> m;
    for(int i=0 ; i<n ; i++){
        m[arr[i]]++;
        if(m[arr[i]]>n/3){
            ans.push_back(arr[i]);
        }
        if(ans.size()>=2){
            return ans;
        }
    }
    return ans;
}

vector<int> maj_best(vector<int> arr , int n){
    vector<int> ans;
    int cnt1 = 0 , cnt2 = 0;
    int el1 = -1 , el2 = -1;
    for(int i=0 ; i<n ; i++){
        if(cnt1==0 && el2 != arr[i]){
            cnt1 = 1;
            el1 = arr[i];
        }
        else if(cnt2==0 && el1 != arr[i]){
            cnt2 = 1;
            el2 = arr[i];
        }
        else if(arr[i]==el1){
            cnt1++;
        }
        else if(arr[i]==el2){
            cnt2++;
        }
        else{
            cnt1 --;
            cnt2 --;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    for(int i=0 ; i<n ; i++){
        if(arr[i]==el1){
            cnt1++;
        }
        else if(arr[i]==el2){
            cnt2++;
        }
    }
    if(cnt1 > n/3){
        ans.push_back(el1);
    }
    if(cnt2 > n/3){
        ans.push_back(el2);
    }
    return ans;
}

vector<vector<int>> sum_3(vector<int> arr , int n){
    set<vector<int>> s;
    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            for(int k=j+1 ; k<n ; k++){
                if(arr[i]+arr[j]+arr[k]==0){
                    vector<int> temp;
                    temp = {arr[i],arr[j],arr[k]};
                    sort(temp.begin() , temp.end());
                    s.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans;
    for(auto it : s){
        ans.push_back(it);
    }
    return ans;
}

vector<vector<int>> sum_3_better(vector<int> arr , int n){
    set<vector<int>> s;
    for(int i=0 ; i<n ; i++){
        unordered_map<int,int> m;
        for(int j=i+1 ; j<n ; j++){
            int k = -(arr[i]+arr[j]);
            if(m.find(k) != m.end() ){
                vector<int> temp;
                temp = {arr[i],arr[j],k};
                sort(temp.begin() , temp.end());
                s.insert(temp);
            }
            m[arr[j]] = j;
        }
    }
    vector<vector<int>> ans;
    for(auto it : s){
        ans.push_back(it);
    }
    return ans;   
}

vector<vector<int>> sum_3_best(vector<int> arr , int n){
    if(n<3){
        return {};
    }
    vector<vector<int>> ans;
    sort(arr.begin() ,arr.end());
    for(int i=0 ; i<n ; i++){
        if(i>0 && arr[i]==arr[i-1]){
            continue;
        }
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];
            if(sum>0){
                k--;
            }
            else if(sum<0){
                j++;
            }
            else{
                ans.push_back({arr[i],arr[j],arr[k]});
                j++;
                k--;
                while(j<k && arr[j]==arr[j-1]){
                    j++;
                }
                while(j<k && arr[k]==arr[k+1]){
                    k--;
                }
            }
        }
    }
    return ans;
}

vector<vector<int>> sum_4(vector<int> arr , int n){
    set<vector<int>> s;
    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            for(int k=j+1 ; k<n ; k++){
                for(int l=k+1 ; l<n ; l++){
                    if(arr[i]+arr[j]+arr[k]+arr[l]==0){
                    vector<int> temp;
                    temp = {arr[i],arr[j],arr[k],arr[l]};
                    sort(temp.begin() , temp.end());
                    s.insert(temp);
                }
                }
            }
        }
    }
    vector<vector<int>> ans;
    for(auto it : s){
        ans.push_back(it);
    }
    return ans;
}

vector<vector<int>> sum_4_better(vector<int> arr , int n){
    set<vector<int>> s;
    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            unordered_map<int,int> m;
            for(int k=j+1 ; k<n ; k++){
                int l = -(arr[i]+arr[j]+arr[k]);
                if(m.find(l) != m.end() ){
                    vector<int> temp;
                    temp = {arr[i],arr[j],arr[k],l};
                    sort(temp.begin() , temp.end());
                    s.insert(temp);
                }
                m[arr[k]] = k;
            }
        }
    }
    vector<vector<int>> ans;
    for(auto it : s){
        ans.push_back(it);
    }
    return ans;   
}

vector<vector<int>> sum_4_best(vector<int> arr , int n){
    if(n<4){
        return {};
    }
    vector<vector<int>> ans;
    sort(arr.begin() ,arr.end());
    for(int i=0 ; i<n ; i++){
        if(i>0 && arr[i]==arr[i-1]){
            continue;
        }
        for(int j=i+1 ; j<n ; j++){
            if(j>i+1 && arr[j]==arr[j-1]){
            continue;
            }
            int k = j+1;
            int l = n-1;
            while(k<l){
                int sum=arr[i]+arr[j]+arr[k]+arr[l];
                if(sum>0){
                    l--;
                }
                else if(sum<0){
                    k++;
                }
                else{
                    ans.push_back({arr[i],arr[j],arr[k],arr[l]});
                    k++;
                    l--;
                    while(k<l && arr[k]==arr[k-1]){
                        k++;
                    }
                    while(k<l && arr[l]==arr[l+1]){
                        l--;
                    }
                }
            }
        }
    }
    return ans;
}

int larg_sub_0(vector<int> arr , int n){
    int sum = 0;
    int max = 0;
    for(int i=0 ; i<n ; i++){
        int count = 0;
        for(int j=0 ; j<n ; j++){
            sum += arr[j];
            count++;
            if(sum==0 && count>max){
                max = count;
            }
        }
    }
    return max;
}

int larg_sub_0_best(vector<int> arr , int n){
    int sum = 0;
    int max = 0;
    map<int,int> pre;
    for(int i=0 ; i<n ; i++){
        sum += arr[i];
        if(sum==0){
            if(i+1>max){
                max=i+1;
            }
        }
        int rem = sum;
        if(pre.find(rem) != pre.end()){
            int idx = pre[rem];
            if(i-idx>max){
                max = i-idx;
            }
        }
        else{
            pre[sum] = i;
        }
    }
    return max;
}

int number_of_sub_xor(vector<int> arr , int n , int target){
    int cnt = 0;
    for(int i=0 ; i<n ; i++){
        int x = 0;
        for(int j=i ; j<n ; j++){
            x ^= arr[j];
            if(x==target){
                cnt++;
            }
        }
    }
    return cnt;
}

int number_of_sub_xor_best(vector<int> arr , int n , int target){
    int cnt = 0;
    int x = 0;
    map<int,int> prexor;
    for(int i=0 ; i<n ; i++){
        x ^= arr[i];
        if(x==target){
            cnt++;
        }
        int xrem = x^target;   // xrem^k = x  =>  (xrem^k)^k = x^k  =>  xrem = x^k  => k is our target
        if(prexor.find(xrem) != prexor.end()){  // check if xrem have ever appeared before?
            cnt += prexor[xrem];  // how many times xrem came before
        }
        prexor[x]++;
    }
    return cnt;
}

vector<vector<int>> merge_overlapping_subintervals(vector<vector<int>> arr){
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0 ; i<arr.size() ; i++){
        int st = arr[i][0];
        int end = arr[i][1];
        if(ans.size()!=0 && end<=ans.back()[1]){
            continue;
        }
        else{
            for(int j=i+1 ; j<arr.size() ; j++){
                if(end>=arr[j][0]){
                    end = max(end,arr[j][1]);
                }
                else{
                    break;
                }
            }
            ans.push_back({st,end});
        }
    }
    return ans;
}

vector<vector<int>> merge_overlapping_subintervals_best(vector<vector<int>> arr){
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0 ; i<arr.size() ; i++){
        int st = arr[i][0];
        int end = arr[i][1];
        if(ans.size()!=0 && ans.back()[1]>=end){
            continue;
        }
        else if(ans.size()==0 || st>ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1] = max(end,ans.back()[1]);
        }
    }
    return ans;
}

void merge_sorted_arrays(vector<int> &arr1 , vector<int> &arr2){
    int n = arr1.size();
    int m = arr2.size();
    int i = 0;
    int j = 0;
    vector<int> new_arr;
    while(i<n && j<m){
        if(arr1[i]>arr2[j]){
            new_arr.push_back(arr2[j]);
            j++;
        }
        else{
            new_arr.push_back(arr1[i]);
            i++;
        }
    }
    while(i<n){
        new_arr.push_back(arr1[i]);
        i++;
    }
    while(j<m){
        new_arr.push_back(arr2[j]);
        j++;
    }

    i = 0;
    for(auto it : new_arr){
        if(i<n){
            arr1[i] = it;
            i++;
        }
        else{
            arr2[i-n] = it;
            i++;
        }
    }
}

void merge_sorted_arrays_best1(vector<int> &arr1 , vector<int> &arr2){
    int n = arr1.size();
    int m = arr2.size();
    int i = n-1;
    int j = 0;
    while(j<m && i>=0){
        if(arr1[i]>arr2[j]){
            swap(arr1[i],arr2[j]);
        }
        else{
            break;
        }
        i--;
        j++;
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
}

void merge_sorted_arrays_best2(vector<int> &arr1 , vector<int> &arr2){
    int n = arr1.size();
    int m = arr2.size();
    int len = n+m;
    int gap = (len)/2 + (len)%2;    // ceil division
    while(gap>0){
        int i = 0;
        int j = i+gap;
        while(j<len){
            if(i<n && j<n){   // both in arr1
                if(arr1[i]>arr1[j]){
                    swap(arr1[i],arr1[j]);
                }
            }
            else if(i<n && j>=n){  // i is in arr1 and j is in arr2
                if(arr1[i]>arr2[j-n]){
                    swap(arr1[i],arr2[j-n]);
                }
            }
            else{
                if(arr2[i-n]>arr2[j-n]){   // both in arr2
                    swap(arr2[i-n],arr2[j-n]);
                }
            }
            i++;
            j++;
        }
        if(gap==1) return;
        gap = (gap/2) + (gap%2);    // ceil division
    }
}

vector<int> missing_and_repeating(vector<int> arr){
    int n = arr.size();
    int x = 0;
    int y = 0;
    for(int i=1 ; i<=n ; i++){
        int cnt = 0;
        for(int j=0 ; j<n ; j++){
            if(i==arr[j]){
                cnt++;
            }
        }
        if(cnt==0){
            x = i;
        }
        if(cnt==2){
            y = i;
        }
    }
    return {x,y};
}

vector<int> missing_and_repeating_better(vector<int> arr){
    int n = arr.size();
    int x = 0;
    int y = 0;
    vector<int> check(n+1);
    for(int i=0 ; i<n ; i++){
        check[arr[i]]++;
    }
    for(int i=0 ; i<check.size() ; i++){
        if(check[i]==0){
            x = i;
        }
        if(check[i]==2){
            y = i;
        }
    }
    return {x,y};
}

vector<int> missing_and_repeating_best(vector<int> arr){
    int n = arr.size();
    int x = 0;
    int y = 0;
    int sum = 0;
    int sum_n = 0;
    int sum_2 = 0;
    int sum_n_2 = 0;
    for(int i=0 ; i<n ; i++){
        sum += arr[i];
        sum_n += i+1;
        sum_2 += arr[i]*arr[i];
        sum_n_2 += (i+1)*(i+1);
    }
    int x_y = sum_n - sum;
    int x_p_y = (sum_n_2 - sum_2)/x_y;
    x = (x_p_y+x_y)/2;
    y = x - x_y;
    return {x,y};
}

int count_inversions(vector<int> arr){
    int n = arr.size();
    int count = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }
    }
    return count; 
}

int merge(vector<int> &arr , int st , int mid , int end){
    int x = st;
    int y = mid+1;
    int cnt = 0;
    vector<int> temp;
    while(x<=mid && y<=end){
        if(arr[x]<=arr[y]){
            temp.push_back(arr[x]);
            x++;
        }
        else{
            temp.push_back(arr[y]);
            y++;
            cnt += (mid-x)+1;
        }
    }
    while(x<=mid){
        temp.push_back(arr[x]);
        x++;
    }
    while(y<=end){
        temp.push_back(arr[y]);
        y++;
    }
    for(int i=st ; i<=end ; i++){
        arr[i]=temp[i-st];
    }
    return cnt;
}

int count_inversions_best(vector<int> &arr , int st , int end){
    int mid = (st+end)/2;
    int cnt = 0;
    if(st==end) return cnt;
    cnt += count_inversions_best(arr,st,mid);
    cnt += count_inversions_best(arr,mid+1,end);
    cnt += merge(arr,st,mid,end);
    return cnt;
}

int reverse_pairs(vector<int> arr){
    int cnt = 0;
    int n = arr.size();
    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            if(arr[i]>2*arr[j]){
                cnt++;
            }
        }
    }
    return cnt;
}

void merge_(vector<int> &arr , int st , int mid , int end){
    int x = st;
    int y = mid+1;
    vector<int> temp;
    while(x<=mid && y<=end){
        if(arr[x]<=arr[y]){
            temp.push_back(arr[x]);
            x++;
        }
        else{
            temp.push_back(arr[y]);
            y++;
        }
    }
    while(x<=mid){
        temp.push_back(arr[x]);
        x++;
    }
    while(y<=end){
        temp.push_back(arr[y]);
        y++;
    }
    for(int i=st ; i<=end ; i++){
        arr[i]=temp[i-st];
    }
}

int count_pairs(vector<int> &arr , int st , int mid , int end){
    int cnt = 0;
    int j = mid+1;
    for(int i=st ; i<=mid ; i++){
        while(j<=end && arr[i]>2*arr[j]){
            j++;
        }
        cnt += j-(mid+1);
    }
    return cnt;
}

int reverse_pairs_best(vector<int> &arr , int st , int end){
    int cnt = 0;
    if(st==end) return cnt;
    int mid = (st+end)/2;
    cnt += reverse_pairs_best(arr,st,mid);
    cnt += reverse_pairs_best(arr,mid+1,end);
    cnt += count_pairs(arr,st,mid,end);
    merge_(arr,st,mid,end);
    return cnt;
}

int max_product(vector<int> arr){
    int n = arr.size();
    int max = 0;
    for(int i=0 ; i<n ; i++){
        int prod = 1;
        for(int j=i ; j<n ; j++){
            prod *= arr[j];
            if(prod>max){
                max = prod;
            }
        }
    }
    return max;
}

int max_product_best(vector<int> arr){
    int n = arr.size();
    int maxi = INT_MIN;
    int prefix_prod = 1;
    int suffix_prod = 1;
    for(int i=0 ; i<n ; i++){
        prefix_prod *= arr[i];
        suffix_prod *= arr[n-i-1];
        if(prefix_prod==0){
            prefix_prod=1;
        }
        if(suffix_prod==0){
            suffix_prod=1;
        }
        maxi = max(maxi,max(prefix_prod,suffix_prod));
    }
    return maxi;
}


 
int main(){
    vector<int> arr1;
    vector<int> arr2;
    arr1 = {3,-4,0,1,5};
    arr2 = {1,2,10,11};
    
    
    cout << max_product_best(arr1);
    // for(int i=0 ; i<ans.size() ; i++){
    //     cout << ans[i] << " ";
    // }
}