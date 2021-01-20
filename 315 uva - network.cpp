#include<bits/stdc++.h>

using namespace std;

#define N 300005
#define INF 1000000007
#define fi first
#define se second
#define pii pair<int , int>
#define ll long long
#define pll pair<ll, ll >
#define pb push_back
#define N 105

vector<int> edge[N];
int cnt;
int tim ;
int par[N];
int low[N] , num[N];

void dfs(int node){
    num[node] = low[node] = ++tim;
    bool isArticulation = false;
    int other;
    int child = 0;

    for(int i = 0 ; i < (int)edge[node].size() ; i++){
        other = edge[node][i];

        if(other == par[node])
            continue;

        if(par[other] != -1){ // already visited
            low[node] = min(low[node] , num[other]);
        }

        else{
            par[other] = node;
            dfs(other);
            child ++;

            if(low[other] < num[node]) // there is a back edge
                low[node] = min(low[node] , low[other]);

            else
                isArticulation = true;
        }
    }

    if(par[node] == -2){ // root
        if(child >= 2)
            cnt++;
    }
    else{
        if(isArticulation)
            cnt++;
    }
}


int main()
{
    string s;
    int n , x , y;

    while(getline(cin , s) && s != "0"){
        stringstream ss(s) ;
        ss >> n;

        for(int i = 0 ; i <= n ; i++){
            edge[i].clear();
            par[i] = -1;
        }
        tim = cnt = 0;

        while(getline(cin , s) && s != "0"){
            stringstream ss(s);
            ss >> x;
            while(ss >> y){
                edge[x].pb(y);
                edge[y].pb(x);
            }
        }

        par[1] = -2;
        dfs(1);
        cout << cnt << endl;
    }
}
