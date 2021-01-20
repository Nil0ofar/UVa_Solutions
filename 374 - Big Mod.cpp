#include<bits/stdc++.h>

using namespace std;

#define INF 2000000005
#define fi first
#define se second
#define ll unsigned long long
#define pii pair<int , int>
#define pic pair<int , char>
#define pb push_back
#define N 100005
#define mod 1000000007

ll f(ll b , ll p , ll m){
    if(p == 1)
        return b % m;

    ll ans = f(b , p / 2 , m) % m;
    ans = (ans * ans) % m;
    if(p % 2 == 1)
        ans = (ans * b) % m;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    ll b , p , m;
    ll res;
    while(scanf("%lld%lld%lld" , &b , &p , &m) != EOF){
        res = f(b , p , m);
        printf("%lld\n" , res);
    }

    return 0;
}
