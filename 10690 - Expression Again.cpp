#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define N 500005
#define ll long long
#define pii pair<ll , int>
#define fi first
#define se second
#define mod 998244353LL
#define INF 2000000007
#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag,tree_order_statistics_node_update>
#define Base 5000

int total;
vector<int> a;
bool dp[10002][102][52];
int mx , dif;
int n , m;

void f(int sum , int idx , int t){

    if(t == 0){
        //cout << sum << endl;
        int temp = abs(total - 2 * sum);
        //cout << 't' << temp << endl;
        if(dif == -1){
            dif = temp;
            mx = sum;
        }
        else if(dif > temp){
            mx = sum;
            dif = temp;
        }

    }

    if(idx == n + m)
        return ;

    if(dp[sum + Base][idx][t])
        return;

    f(sum + a[idx] , idx + 1 , t - 1);
    f(sum , idx + 1 , t);
    dp[sum + Base][idx][t] = true;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    int x;
    int mn , temp;
    while(cin >> n >> m){
        total = 0;
        a.clear();
        for(int i = 0 ; i < n + m ; i++){
            cin >> x;
            a.pb(x);
            total += x;
        }

        sort(a.begin() , a.end());
        mn = INF;
        temp = 0;
        for(int i = 0 ; i < max(n , m) ; i++){
            temp += a[i];
            if(i == n - 1 || i == m - 1)
                mn = min(mn , temp);
        }

        mn *= (total - mn);

        memset(dp , false , sizeof dp);
        dif = -1;
        f(0 , 0 , min(n , m));
        mx *= (total - mx);
        cout << mx << ' ' << mn << endl;
    }
}


