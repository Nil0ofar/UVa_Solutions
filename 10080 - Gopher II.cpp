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
#define N 1000 * 1000 + 5
#define mod 1000000007
#define Base 3002
#define double long double
#define ret(x) return cout << x << endl , 0
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int n , m ;
int s , v ;

inline bool ok(pdd g , double x, double y){
    return (g.fi - x) * (g.fi - x) + (g.se - y) * (g.se - y) <= (s * v) * (s * v);
}

pdd gopher[105];
vector<int> adj[205];
bool mark[205];
int Rmatch[205];

bool bpm(int node){
    for(auto other : adj[node]){
        if(mark[other])
            continue;

        mark[other] = true;
        if(Rmatch[other] == -1 || bpm(Rmatch[other])){
            Rmatch[other] = node;
            return true;
        }
    }
    return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
    double x , y ;
    while(cin >> n >> m >> s >> v){

        for(int i = 0 ; i < n ; i++)
            cin >> gopher[i].fi >> gopher[i].se;

        for(int i = 0 ; i <= n + m ; i++)
            adj[i].clear();
        memset(Rmatch , -1 , sizeof Rmatch);

        for(int i = n ; i < m + n ; i++){
            cin >> x >> y ;
            for(int j = 0 ; j < n ; j++){
                if(ok(gopher[j] , x , y )){
                    adj[i].pb(j);
                    adj[j].pb(i);
                }
            }
        }

        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            memset(mark , false , sizeof mark);
            if(bpm(i))
                cnt++;
        }
        cout << n - cnt << endl;
    }
    return 0;
}
