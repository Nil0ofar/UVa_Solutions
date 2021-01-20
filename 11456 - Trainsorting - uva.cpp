#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair(int , int)

int n;
int a[2005];
int dp_inc[2005];
int dp_dec[2005];

int f_inc(int idx){
    if(idx == n)
        return 0;
    if(dp_inc[idx] != -1)
        return dp_inc[idx];
    int ans = 1;
    for(int i = idx + 1 ; i < n ; i++){
        if(a[i] > a[idx])
            ans = max(ans, 1 + f_inc(i));
    }
    dp_inc[idx] = ans;
    return ans;
}

int f_dec(int idx){
    if(idx == n)
        return 0;
    if(dp_dec[idx] != -1)
        return dp_dec[idx];
    int ans = 0;
    for(int i = idx + 1 ; i < n ; i++){
        if(a[i] < a[idx])
            ans = max(ans,1 + f_dec(i));
    }
    dp_dec[idx] = ans;
    return ans;
}

int main(){
    int testcase;
    cin >> testcase;
    while(testcase--){
        cin >> n;
        memset(dp_inc , -1 , sizeof dp_inc);
        memset(dp_dec , -1 , sizeof dp_dec);
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            //cout<<i<<' '<<f_inc(i)<<' '<<f_dec(i)<<endl;
            ans = max(ans , f_inc(i) + f_dec(i));
        }
        cout<<ans<<endl;
    }
}
