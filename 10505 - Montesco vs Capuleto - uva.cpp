#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, long long>
#define pb push_back
#define fi first
#define se second
#define N 205
#define ll long long

int n ;
vector<int> edge[N];
int color[N];
int ans , white , black;

void init(){
    memset(color , 0 , sizeof color);
    for(int i = 0 ; i < N ; i++)
        edge[i].clear();
    ans = 0;
}

void read(){
    cin >> n ;
    int m , x ;
    for(int i = 1 ; i <= n ; i++){
        cin >> m ;
        for(int j = 0 ; j < m ; j++){
            cin >> x ; // emkan dare 'x' k inja mide meghdari bishtar az 'n' dashte bashe ... -> WA
            if(x > n)
                continue;
            edge[x].pb(i);
            edge[i].pb(x);
        }
    }
}

bool dfs(int node , int c){
    color[node] = c;
    if(c == 1)
        white++;
    else
        black++;

    int other;
    for(int i = 0 ; i < (int)edge[node].size() ; i++){
        other = edge[node][i];

        if(color[other] == 0){
            if(!dfs(other , -c))
                return false;
        }
        else if(color[other] == c)
            return false;
    }
    return true;
}

void del(int node){
    color[node] = 2;
    int other;
    for(int i = 0 ; i < (int)edge[node].size() ; i ++){
        other = edge[node][i];
        if(color[other] == 2)
            continue;
        del(other);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    int testcase;
    cin >> testcase;
    while(testcase--){
        init();
        read();

        for(int i = 1 ; i <= n ; i++){
            if(color[i] == 0){
                white = black = 0;
                if(dfs(i , 1))
                    ans += max(white , black);
                del(i);
            }
        }

        cout << ans << endl;
    }
    return 0;
}
