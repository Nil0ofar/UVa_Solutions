#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, long long>
#define pb push_back
#define fi first
#define se second
#define N 305
#define ll long long

vector<int> edge[N];
int color[N];

bool dfs(int node , int c){
    color[node] = c;
    int other;

    for(int i = 0 ; i < (int)edge[node].size() ; i++){
        other = edge[node][i];
        if(color[other] == c)
            return false;
        if(color[other] == 0 && !dfs(other , -c))
            return false;
    }
    return true;
}


int main(){
    ios_base :: sync_with_stdio(false);
    int n;
    int x, y;
    while(cin >> n && n != 0){
        //init
        for(int i = 0 ; i <= n ; i++){
            edge[i].clear();
            color[i] = 0;
        }
        //input
        while(cin >> x >> y){
            if(x == 0 && y == 0)
                break;
            edge[x].pb(y);
            edge[y].pb(x);
        }

        //solve
        if(dfs(1 , 1))
            cout << "YES\n";
        else
            cout << "NO\n";

    }
    return 0;
}
