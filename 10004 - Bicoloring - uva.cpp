#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, long long>
#define pb push_back
#define fi first
#define se second
#define N 205
#define ll long long

vector<int> edge[N];
int color[N];

bool dfs(int node , int c){
    color[node] = c;
    int other;
    for(int i = 0; i < (int)edge[node].size() ; i++){
        other = edge[node][i];
        if(color[other] == c)
            return false;
        else if(color[other] == 0){
            if(!dfs(other , -c))
                return false;
        }
    }
    return true;
}

int main(){
    ios_base :: sync_with_stdio(false);
    int n , m , x , y;
    while(cin >> n && n != 0){
        cin >> m ;

        for(int i = 0 ; i <= n ; i++){
            edge[i].clear();
            color[i] = 0;
        }

        for(int i = 0 ; i < m ; i++){
            cin >> x >> y ;
            edge[x].pb(y);
            edge[y].pb(x);
        }

        if(dfs(0 , 1))
            cout << "BICOLORABLE.\n";
        else
            cout << "NOT BICOLORABLE.\n";
    }

    return 0;
}
