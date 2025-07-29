#include<bits/stdc++.h>
using namespace std;

vector<int> two_sum(vector<int> arr , int target){
    vector<int> ans;
    int n = arr.size();
    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            if(arr[i]+arr[j]==target){
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    return ans;
}

vector<int> two_sum_better(vector<int> arr , int target){
    vector<int> ans;
    map<int,int> m;
    int n = arr.size();
    for(int i=0 ; i<n ; i++){
        int rem = target - arr[i];
        if(m.find(rem) != m.end()){
            ans.push_back(i);
            ans.push_back(m[rem]);
        }
        m[arr[i]] = i;
    }
    return ans;
}

bool two_sum_best(vector<int> &arr , int target){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    int i = 0 , j = n-1;
    while(i<j){
        if(arr[i]+arr[j]>target){
            j--;
        }
        else if(arr[i]+arr[j]<target){
            i++;
        }
        else{
            return true;
        }
    }
    return false;
    
}

void merge_help(vector<int> &arr , int start , int mid , int end){
    vector<int> temp;
    int i = mid+1;
    int j = start;
    while(start<=mid && i<=end){
        if(arr[start]>=arr[i]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[start]);
            start++;
        }
    }
    while(start<=mid){
        temp.push_back(arr[start]);
        start++;
    }

    while(i<=end){
        temp.push_back(arr[i]);
        i++;
    }

    
    for(int i=j ; i<=end ; i++){
        arr[i] = temp[i-j];
    }
}

void sort_0_1_2(vector<int> &arr , int start , int end){
    int mid = (start+end)/2;
    if(start>=end){
        return;
    }
    sort_0_1_2(arr , start , mid);
    sort_0_1_2(arr , mid+1 , end);
    merge_help(arr , start , mid , end);
}

void quick_sort(vector<int>& arr, int start, int end){
    if(start >= end) return;

    int pivot = arr[start];
    int i = start + 1;
    int j = end;

    while(i <= j){
        while(i <= end && arr[i] <= pivot) i++;
        while(j > start && arr[j] > pivot) j--;
        if(i < j) swap(arr[i], arr[j]);
    }

    swap(arr[start], arr[j]);  // place pivot correctly

    quick_sort(arr, start, j - 1);
    quick_sort(arr, j + 1, end);
}


void sort_0_1_2_best(vector<int> &arr , int n){
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid<=high){
        if(arr[mid]==0){
            int temp = arr[mid];
            arr[mid] = arr[low];
            arr[low] = temp;
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }
}

int maj(vector<int> arr , int n){
    for(int i=0 ; i<n ; i++){
        int count = 0;
        for(int j=0 ; j<n ; j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count>n/2){
            return arr[i];
        }
    }
    return -1;
}

int maj_better(vector<int> arr , int n){
    map<int,int> m;
    for(int i=0 ; i<n ; i++){
        m[arr[i]]++;
    }
    for(auto it : m){
        if(it.second>n/2){
            return it.first;
        }
    }
    return -1;
}

int maj_best(vector<int> arr , int n){
    int cnt = 0;
    int maj = arr[0];
    int i = 0; 
    while(i<n){
        if(cnt==0){
            maj=arr[i];
        }
        if(arr[i]==maj){
            cnt++;
        }
        else{
            cnt--;
        }
        i++;
    }
    if(cnt>0){
        int count=0;
        for(int j=0 ; j<n ; j++){
            if(arr[j]==maj){
                count++;
            }
        }
        if(count>n/2){
            return maj;
        }
        else{
            return -1;
        }
    }
    else{
        return -1;
    }
}

int maxi(vector<int> arr , int n){
    int maxim = 0;
    for(int i=0 ; i<n ; i++){
        int sum = 0;
        for(int j=i ; j<n ; j++){
            sum += arr[j];
            if(sum>maxim){
                maxim = sum;
            }
        }
    }
    return maxim;
}


int maxi_best(vector<int> arr , int n){
    int maxim = 0;
    int sum = 0;
    for(int i=0 ; i<n ; i++){
        sum += arr[i];
        if(sum<0){
            sum=0;
        }
        if(sum>maxim){
            maxim=sum;
        }
    }
    return maxim;
}

vector<int> maxi_subarray_best(vector<int> arr , int n){
    int sum = 0;
    int maxim = 0;
    vector<int> ans;
    int ans_st = 0;
    int st = 0;
    int ans_end = 0;
    for(int i=0 ; i<n ; i++){
        if(sum==0){
            st = i ;
        }
        sum += arr[i];
        if(sum<0){
            sum=0;
        }
        if(sum>maxim){
            maxim = sum;
            ans_st=st;
            ans_end = i;
        }
    }
    for(int j=ans_st ; j<=ans_end; j++){
        ans.push_back(arr[j]);
    }
    return ans;
}

vector<int> stock(vector<int> arr , int n){
    int maxi = 0;
    int buy_day = 0;
    int sell_day = 0;
    vector<int> ans;
    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            if(arr[j]-arr[i]>maxi && j>i){
                maxi = arr[j] - arr[i];
                buy_day = i+1;
                sell_day = j+1;
            }
        }
    }
    ans.push_back(buy_day);
    ans.push_back(sell_day);
    return ans;
}

int stock_better(vector<int> arr , int n){
    int mini = arr[0];
    int maxi = 0;
    for(int i=1 ; i<n ; i++){
        if(maxi<arr[i]-mini){
            maxi = arr[i]-mini;
        }
        if(mini>arr[i]){
            mini = arr[i];
        }
    }
    return maxi;
}

void rearr(vector<int> &arr , int n){
    vector<int> pos;
    vector<int> neg;
    int i = 0;
    int j = 0;
    for(int i=0 ; i<n ; i++){
        if(arr[i]>=0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    for(int i=0 ; i<n/2 ; i++){
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
    }
}

vector<int> rearr_better(vector<int> &arr , int n){
    vector<int> ans(n);
    int k=0;
    int i=0;
    int j=1;
    while(i<n && j<n){
        if(arr[k]>=0){
            ans[i]=arr[k];
            i += 2;
            k++;
        }
        else{
            ans[j] = arr[k];
            j += 2;
            k++;
        }
    }
    while(i<n){
        ans[i]=arr[k];
        i += 2;
        k++;
    }
    while(j<n){
        ans[j] = arr[k];
        j += 2;
        k++;
    }
    return ans;
}

vector<int> leader(vector<int> arr , int n){
    vector<int> ans;
    for(int i=0 ; i<n-1 ; i++){
        int lead = true;
        for(int j=0 ; j<n ; j++){
            if(arr[j]>arr[i]){
                lead = false;
            }
        }
        if(lead == true){
            ans.push_back(arr[i]);
        }
    }
    ans.push_back(arr[n-1]);
    return ans;
}

vector<int> leader_best(vector<int> arr , int n){
    vector<int> ans;
    int max = INT_MIN;
    for(int i=n-1 ; i>=0 ; i--){
        if(arr[i]>max){
            ans.push_back(arr[i]);
            max = arr[i];
        }
    }
    return ans;
}

bool linear(vector<int> &arr , int target){
    for(int i=0 ; i<arr.size() ; i++){
        if(arr[i]==target){
            return true;
        }
    }
    return false;
}

int long_cons_seq(vector<int> arr , int n){
    int count = 1;
    int max = 1;
    for(int i=0 ; i<n ; i++){
        int x = arr[i];
        while(linear(arr,x+1)){
            count ++;
            x++;
        }
        if(count>max){
            max = count;
        }
        count = 1;
    }
    return max;
}

int long_cons_seq_better(vector<int> arr , int n){
    sort(arr.begin() , arr.end());
    int count = 1;
    int max = 1;
    int prev = arr[0];
    for(int i=1 ; i<n ; i++){
        if(prev == arr[i]-1){
            count++;
            prev = arr[i];
        }
        else if(prev == arr[i]){
            continue;
        }
        else{
            count = 1;
            prev = arr[i];
        }
        if(count>max){
            max = count;
        }
    }
    return max;
}

int long_cons_seq_best(vector<int> arr , int n){
    unordered_set<int> s;
    int max = 1;
    if(n==0){
        return 0;
    }
    for(int i=0 ; i<n ; i++){
        s.insert(arr[i]);
    }
    for(int i=0 ; i<n ; i++){
        int count = 1;
        if(s.find(arr[i]-1) == s.end()){
            int x = arr[i];
            while(s.find(x+1) != s.end()){
                count++;
                x++;
            }
            if(count>max){
                max = count;
            }
        }
    }
    return max;
}

void set_row(vector<vector<int>> &arr , int n , int m , int x){
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(arr[x][j] != 0){
                arr[x][j] = -1;
            }
        }
    }
}

void set_column(vector<vector<int>> &arr , int n , int m , int y){
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(arr[i][y] != 0){
                arr[i][y] = -1;
            }
        }
    }
}

void set_zeroes(vector<vector<int>> &arr , int n , int m){
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(arr[i][j] == 0){
                set_row(arr,n,m,i);
                set_column(arr,n,m,j);
            }
        }
    }
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(arr[i][j] == -1){
                arr[i][j] = 0;
            }
        }
    }
}

void set_zeroes_better(vector<vector<int>> &arr , int n , int m){
    vector<int> row(n);
    vector<int> column(m);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(arr[i][j] == 0){
                row[i] = 1;
                column[i] = 1;
            }
        }
    }

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(row[i]==1 || column[j]==1){
                arr[i][j] = 0;
            }
        }
    }

}

void set_zeroes_best(vector<vector<int>> &arr , int n , int m){
    int col0 = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(arr[i][j]==0){
                arr[i][0] = 0;
                if(j != 0){
                    arr[0][j] = 0;
                }
                else {
                    col0 = 0;
                }
            }
        }
    }

    for(int i=1 ; i<n ; i++){
        for(int j=1 ; j<m ; j++){
            if(arr[0][j]==0 || arr[i][0]==0){
                arr[i][j] = 0;
            }
        }
    }

    for(int i=0 ; i<n ; i++){
        if(arr[0][0]==0){
            arr[i][0]=0;
        }
    }

    for(int i=0 ; i<m ; i++){
        if(col0==0){
            arr[0][i] = 0;
        }
    }
}

vector<vector<int>> rotate(vector<vector<int>> arr , int n , int m){
    vector<vector<int>> ans(n, vector<int>(m, 0));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            ans[j][n-i-1] = arr[i][j];
        }
    }
    return ans;
}

void rotate_best(vector<vector<int>> &arr , int n , int m){
    for(int i=0 ; i<=n-1 ; i++){
        for(int j=i+1 ; j<m ; j++){
            int temp = arr[j][i];
            arr[j][i] = arr[i][j];
            arr[i][j] = temp;
        }
    }

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m/2 ; j++){
            int temp = arr[i][j];
            arr[i][j] = arr[i][n-1-j];
            arr[i][n-1-j] = temp;
        }
    }
}

void sprial(vector<vector<int>>arr , int n , int m){
    int left = 0;
    int right = m-1;
    int top = 0;
    int bottom = n-1;
    int count = 0;
    while(count<n*m){
        for(int i=left ; i<=right ; i++){
            cout << arr[top][i] << " ";
            count++;
        }
        top++;
        for(int i=top ; i<=bottom ; i++){
            cout << arr[i][right] << " ";
            count++;
        }
        right--;
        for(int i=right ; i>=left ; i--){
            cout << arr[bottom][i] << " ";
            count++;
        }
        bottom--;
        for(int i=bottom ; i>=top ; i--){
            cout << arr[i][left] << " ";
            count++;
        }
        left++;
    }
}

int count_sub_sum(vector<int> arr , int n , int target){
    int count = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=i ; j<n ; j++){
            int sum = 0;
            for(int k=i ; k<=j ; k++){
                sum += arr[k];
            }
            if(sum==target){
                count++;
            }
        }
    }
    return count;
}

int count_sub_sum_better(vector<int> arr , int n , int target){
    int count = 0;
    for(int i=0 ; i<n ; i++){
        int sum = 0;
        for(int j=i ; j<n ; j++){
            sum += arr[j];
            if(sum==target){
                count++;
            }
        }
    }
    return count;
}

int count_sub_sum_best(vector<int> arr , int n , int target){
    int count = 0;
    map<int,int> m;
    int presum = 0;
    m[0]++;
    for(int i=0 ; i<n ; i++){
        presum += arr[i];
        int check = presum-target;
        if(m.find(check) != m.end()){
            count += m[check];
        }
        m[presum]++;
    }
    return count;
}


int main(){
    vector<vector<int>> arr1;
    vector<int> arr2;
    arr1 = {
        {1,2,3,4},
        {3,4,5,5},
        {2,7,6,6},
        {1,9,8,7}
        };
    arr2 = {1,2,3,-3,1,1,1,4,2,-3};


    cout << count_sub_sum_best(arr2 , 10 , 3);
    // for(int i=0 ; i<4 ; i++){
    //     for(int j=0 ; j<4 ; j++){
    //         cout << arr1[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}