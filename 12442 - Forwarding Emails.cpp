#include<bits/stdc++.h>

using namespace std;

#define N 50005
#define INF 1000000007
#define fi first
#define se second
#define pii pair<int , int>
#define ll long long
#define pll pair<ll, ll >
#define pb push_back

int nxt[N];
int dis[N];

pii dfs(int node , int d){
    dis[node] = -2; // grey

    int other = nxt[node];

    if(dis[other] == -2){ // cycle
        dis[node] = d;
        return pii(d , 1);
    }

    if(dis[other] != -1){
        dis[node] = dis[other] + 1;
        return pii(dis[node] , 0);
    }

    pii temp = dfs(other , d + 1);
    if(temp.se == 1){
        dis[node] = temp.fi;
        return temp;
    }

    dis[node] = temp.fi + 1;
    return pii(dis[node] , 0);
}

int main(){
    ios_base :: sync_with_stdio(false);

    int testcase;
    cin >> testcase;
    int n , x , y;
    for(int t = 1 ; t <= testcase ; t++){
        cin >> n;

        for(int i = 0 ; i <= n ; i++)
            dis[i] = -1;

        for(int i = 0 ; i < n ; i++){
            cin >> x >> y ;
            nxt[x] = y;
        }

        for(int i = 1 ; i <= n ; i++){
            if(dis[i] == -1)
                dfs(i , 1);
        }

        int mx = -1;
        int idx;
        for(int i = 1 ; i <= n ; i++){
            //cout << i << ' ' << dis[i] << endl;
            if(dis[i] > mx){
                mx = dis[i] ;
                idx = i;
            }
        }

        cout << "Case " << t << ": " << idx << endl;
    }
}
