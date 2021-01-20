#include <bits/stdc++.h>

using namespace std;

#define pii pair<int , int>
#define ll long long
#define pb push_back
#define pli pair<long long , int >

int const N = 10005;

int n ;
vector<int> temp;
int dp_r[N];
int dp_l[N];
int a[N];

int bs(int i , int j , int key){
    if(i == j){
        if(a[temp[i]] >= key)
            return i;
        return i + 1;
    }
    int mid = (i + j) /2;
    if(a[temp[mid]] == key)
        return mid;
    if(a[temp[mid]] < key)
        return bs(mid + 1 , j , key);
    return bs(i , mid, key);
}

void f_r(){
    temp.clear();
    temp.pb(0);
    dp_r[0] = 0;
    int idx;
    for(int i = 1 ; i < n ; i++){
        idx = bs(0 , temp.size() - 1 , a[i]);
        dp_r[i] = idx;
        if(idx == temp.size()){
            temp.pb(i);
        }
        else{
            temp[idx] = i;
        }
    }
}

void f_l(){
    temp.clear();
    temp.pb(n-1);
    dp_l[n-1] = 0;
    int idx;
    for(int i = n-2 ; i >= 0 ; i--){
        idx = bs(0 , temp.size() - 1,a[i]);
        dp_l[i] = idx;
        if(idx == temp.size()){
            temp.pb(i);
        }
        else{
            temp[idx] = i;
        }
    }
}

int main()
{
    int res;
    while(cin >> n){
        for(int i = 0 ; i < n ; i++)
            cin >> a[i];

        memset(dp_r , -1 , sizeof dp_r);
        memset(dp_l , -1 , sizeof dp_l);
        f_r();
        f_l();
        int res = 0;

        for(int i = 0 ; i < n ; i++){
            res = max( res , min(dp_l[i] , dp_r[i]));
        }
        res += (res + 1);
        cout<<res<<endl;


    }
    return 0;
}
