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
#define N 200000 + 5
#define mod 1000000007
#define Base 3002
#define double long double
#define ret(x) return cout << x << endl , 0
#define ordered_set tree<pll, null_type, less<pll>, rb_tree_tag,tree_order_statistics_node_update>
#define pci pair<char , int>

int n , m ;
int nuts;
vector<pii> vec;
string mat[21];
int dp[70000][20];

int dis(int i , int j){
    int a = abs(vec[i].fi - vec[j].fi);
    int b = abs(vec[i].se - vec[j].se);
    return  max(a , b);
}

int f(int mask , int last){

    if(mask == (1 << nuts) - 1)
        return dis(last , nuts - 1);

    int &ans = dp[mask][last];
    if(ans != -1)
        return dp[mask][last];

    ans = 1e9;
    for(int i = 0 ; i < nuts ; i++){
        if((mask & (1 << i)) == 0){
            ans = min(ans , dis(last , i) + f((mask | (1 << i)) , i));
        }
    }
    return ans;
}

int main(){
    ios_base :: sync_with_stdio(false);

    while(cin >> n >> m ){

        for(int i = 0 ; i < n ; i++)
            cin >> mat[i];

        int xs , ys;
        vec.clear();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 'L')
                    xs = i , ys = j;

                else if(mat[i][j] == '#')
                    vec.pb({i , j});
            }
        }

        vec.pb({xs , ys});
        nuts = (int)vec.size();
        memset(dp , -1 , sizeof dp);
        cout << f((1 << (nuts - 1)) , nuts - 1) << endl;
    }
    return 0;
}
