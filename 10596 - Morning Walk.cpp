#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define fi first
#define se second
#define ll long long
#define pii pair<ll , ll>
#define pli pair<ll, int >
#define pb push_back
#define N 205

vector<int> edge[N];
int deg[N];
bool mark[N];

void dfs(int node){
    mark[node] = true;
    int other;

    for(int i = 0 ; i < (int)edge[node].size() ; i++){
        other = edge[node][i];
        if(mark[other] == false)
            dfs(other);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    int n , m;
    int cnt ;
    int x , y;

    while(cin >> n >> m){
        for(int i = 0 ; i <= n ; i ++){
            edge[i].clear();
            deg[i] = 0;
            mark[i] = false;
        }

        for(int i = 0 ; i < m ; i++){
            cin >> x >> y ;
            edge[x].pb(y);
            edge[y].pb(x);
            deg[x]++;
            deg[y]++;
        }

        if(m == 0){ // I got 10 wrong answers for not having this stupid block :)))))
            cout << "Not Possible\n";
            continue;
        }

        bool flag = true;

        for(int i = 0 ; i < n ; i++){
            if(deg[i] % 2 == 1){
                cout << "Not Possible\n";
                flag = false;
                break;
            }
        }

        if(!flag)
            continue;

        cnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(deg[i] != 0 && !mark[i]){
                dfs(i);
                cnt++;
            }
        }

        if(cnt > 1)
            cout << "Not Possible\n";
        else
            cout << "Possible\n";
    }
    return 0;
}
