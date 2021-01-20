#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair(int , int)

int n;
vector<ll> a;
vector<ll> w;
vector<ll> dp_inc;
vector<ll> dp_dec;

ll f_inc(int idx){
    if(dp_inc[idx] != -1)
        return dp_inc[idx];
    ll ans = w[idx];
    for(int i = idx + 1 ; i < n ; i++){
        if(a[i] > a[idx]){
            ans = max(ans , w[idx] + f_inc(i));
        }
    }
    dp_inc[idx] = ans;
    return ans;
}

ll f_dec(int idx){
    if(dp_dec[idx] != -1)
        return dp_dec[idx];
    ll ans = w[idx];
    for(int i = idx + 1 ; i < n ; i++){
        if(a[i] < a[idx]){
            ans = max(ans , w[idx] + f_dec(i));
        }
    }
    dp_dec[idx] = ans;
    return ans;
}


int main(){
    int testcase;
    cin >> testcase;
    ll temp;
    for(int t = 1 ; t <= testcase ; t++){
        cin >> n;
        dp_inc.clear();
        dp_dec.clear();
        a.clear();
        w.clear();
        ll dec = 0;
        ll inc = 0;
        for(int i = 0 ; i < n; i ++){
            cin >> temp;
            a.pb(temp);
            dp_dec.pb(-1);
            dp_inc.pb(-1);
        }
        for(int i = 0 ; i < n; i ++){
            cin >> temp;
            w.pb(temp);
        }

        for(int i = 0 ; i < n ; i++){
            inc = max(inc , f_inc(i));
            dec = max(dec , f_dec(i));
        }

        if(inc >= dec){
            printf("Case %d. Increasing (%lld). Decreasing (%lld).\n" , t , inc, dec);
        }
        else{
            printf("Case %d. Decreasing (%lld). Increasing (%lld).\n" , t , dec, inc);
        }

    }
    return 0;
}
