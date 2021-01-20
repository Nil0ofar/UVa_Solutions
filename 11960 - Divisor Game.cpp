#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define ll long long
#define pll pair<ll , ll>
#define pii pair<int , int>
#define pbl pair<bool , ll>
#define pb push_back
#define pdd pair<double , double>
#define N 1000000 + 5
#define mod 1000000007
#define Base 3002
#define double long double
#define ret(x) return cout << x << endl , 0
#define ordered_set tree<pll, null_type, less<pll>, rb_tree_tag,tree_order_statistics_node_update>
#define pci pair<char , int>
#define double long double

int cnt[N] ;
int ans[N] ;

int main(){
    ios_base :: sync_with_stdio(false);
    for(int i = 1 ; i < N ; i++){
        for(int j = i ; j < N ; j += i)
            cnt[j]++;
    }

    for(int i = 1 ; i < N ; i++)
        ans[i] = (cnt[ans[i - 1]] <= cnt[i] ? i : ans[i - 1]);

    int t;
    cin >> t;
    while(t--){
        int n ;
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}


