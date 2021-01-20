#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int , int>
#define pll pair<long long , long long>
#define fi first
#define se second
#define N 10005
#define mod 1000000007
#define double long double
#define INF 1e9 + 7


int main(){
    ios_base :: sync_with_stdio(false);
    ll sum;
    ll a[N];
    int n;
    while(cin >> n){
        sum = 0;
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
            sum += a[i];
        }

        if(sum % n != 0){
            cout << -1 << endl;
        }
        else{
            ll goal = sum / n;
            ll pos = 0;
            ll ans = 0;
            for(int i = 0 ; i < n ; i++){
                if(a[i] > goal)
                    ans += (a[i] - goal);
            }
            cout << ans + 1 << endl;
        }
    }
}
