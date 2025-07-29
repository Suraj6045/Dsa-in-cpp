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



 
int main(){
    vector<vector<int>> arr1;
    vector<int> arr2;
    arr1 = {
        {1,2,3,4},
        {3,4,5,5},
        {2,7,6,6},
        {1,9,8,7}
        };
    arr2 = {-2,0,4,-4,1,-1,0,2,0,2,1};

    cout << larg_sub_0_best(arr2,arr2.size());
    
    // for(int i=0 ; i<ans.size() ; i++){
    //     for(int j=0 ; j<ans[0].size() ; j++){
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}