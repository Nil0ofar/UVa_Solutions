#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, long long>
#define pb push_back
#define fi first
#define se second
#define N 205
#define ll long long

int white , black;
vector<int> edge[N];
int color[N];

bool dfs(int node , int c){
    color[node] = c;

    if(c == 1)
        white++;
    else
        black++;

    int other;

    for(int i = 0 ; i < (int) edge[node].size() ; i++){
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
    int testcase;
    cin >> testcase;
    int n , m , x , y ;
    int ans ;
    while(testcase--){
        cin >> n >> m;

        //init
        for(int i = 0 ; i <= n ; i++){
            edge[i].clear();
            color[i] = 0;
            ans = 0;
        }

        //input
        for(int i = 0 ; i < m ; i++){
            cin >> x >> y ;
            edge[x].pb(y);
            edge[y].pb(x);
        }

        //solve
        for(int i = 0 ; i < n ; i++){
            if(color[i] == 0){
                white = black = 0;

                if(!dfs(i , 1)){
                    ans = -1;
                    break;
                }
                if(min(white , black) == 0)
                    ans++;
                else
                    ans += min(white , black);
            }
        }

        cout << ans << endl;
    }
    return 0;
}
