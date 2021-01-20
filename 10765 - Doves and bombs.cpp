#include<bits/stdc++.h>

using namespace std;

#define N 100005
#define INF 1000000007
#define fi first
#define se second
#define pii pair<int , int>
#define ll long long
#define pll pair<ll, ll >
#define pb push_back


struct PAIR{
    int num , val;
    PAIR(int _n , int _v){
        num = _n ;
        val = _v ;
    }
    const bool operator<(const PAIR &p)const{
        if(val > p.val)
            return true;
        if(val == p.val)
            return num < p.num ;
        return false;
    }
};

vector<int> edge[N];
int par[N];
int low[N];
int num[N];
vector<PAIR> ans;
int tim;
int n;

void dfs(int node){
    num[node] = low[node] = ++tim;
    int other;
    int child = 0;
    int cnt = 1 ;

    for(int i = 0 ; i < (int)edge[node].size() ; i++){
        other = edge[node][i];

        if(other == par[node])
            continue;

        if(par[other] != -1){ //already has visited --> back edge
            low[node] = min(low[node] , num[other]);
            continue;
        }

        par[other] = node;
        dfs(other);
        child++;

        if(low[other] > low[node]){ // critical
            cnt++;
        }
        else{
            low[node] = min(low[node] , low[other]);
        }
    }

    if(par[node] == -2){ //root
        ans.pb(PAIR(node , child));
    }
    else{
        ans.pb(PAIR(node , cnt));
    }
}

int main()
{
    int m;
    int x, y;
    while(cin >> n >> m){
        if(n == 0 && m == 0)
            break;

        for(int i = 0 ; i <= n ; i++){
            edge[i].clear();
            par[i] = -1;
        }

        while(cin >> x >> y){
            if(x == -1 && y == -1)
                break;
            edge[x].pb(y);
            edge[y].pb(x);
        }

        tim = 0;
        ans.clear();
        par[0] = -2; //root
        dfs(0);

        sort(ans.begin() , ans.end());

        for(int i = 0 ; i < m ; i++)
            cout << ans[i].num << ' ' << ans[i].val << endl;
        cout << endl;

    }
}
