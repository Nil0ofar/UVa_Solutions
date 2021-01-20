#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, long long>
#define pb push_back
#define fi first
#define se second
#define N 55
#define ll long long
#define mod 998244353
#define double long double
#define INF 1e9

struct Node{
    int x, y , d;
    Node(int _x , int _y , int _d){
        x = _x;
        y = _y;
        d = _d;
    }
};

int mat[N][N];
int dis[N][N][4];
map<string , int> mp;
int n , m;
int idx_x[] = {1, 1 , 0};
int idx_y[] = {1 , 0 , 1};

int bfs(int xs , int ys , int xd , int yd , int  d){
    dis[xs][ys][d] = 0;
    queue<Node> q;
    q.push(Node(xs , ys , d));
    int xo , yo , x , y  , od;

    while(!q.empty()){
        x = q.front().x;
        y = q.front().y;
        d = q.front().d;
        if(x == xd && y == yd){
            //cout << d << endl;
            return dis[x][y][d];
        }
        q.pop();

        if(d == 0){
            for(int i = 1 ; i <= 3 ; i++){
                xo = x + i;
                if(xo > n)
                    break;
                if(mat[xo][y] == 1)
                    break;
                if(dis[xo][y][d] != INF)
                    continue;
                dis[xo][y][d] = dis[x][y][d] + 1;
                q.push(Node(xo , y , d));
            }
        }

        if(d == 2){
            for(int i = 1 ; i <= 3 ; i++){
                xo = x - i;
                if(xo < 0)
                    break;
                if(mat[xo][y] == 1)
                    break;
                if(dis[xo][y][d] != INF)
                    continue;
                dis[xo][y][d] = dis[x][y][d] + 1;
                q.push(Node(xo , y , d));
            }
        }

        if(d == 1){
            for(int i = 1 ; i <= 3 ; i++){
                yo = y + i;
                if(yo > m)
                    break;
                if(mat[x][yo] == 1)
                    break;
                if(dis[x][yo][d] != INF)
                    continue;
                dis[x][yo][d] = dis[x][y][d] + 1;
                q.push(Node(x , yo , d));
            }
        }

        if(d == 3){
            for(int i = 1 ; i <= 3 ; i++){
                yo = y - i;
                if(yo < 0)
                    break;
                if(mat[x][yo] == 1)
                    break;
                if(dis[x][yo][d] != INF)
                    continue;
                dis[x][yo][d] = dis[x][y][d] + 1;
                q.push(Node(x , yo , d));
            }
        }

        od = (d + 1) % 4 ;
        if(dis[x][y][od] == INF){
            dis[x][y][od] = dis[x][y][d] + 1;
            q.push(Node(x , y , od));
        }

        od = (d - 1 + 4) % 4;
        if(dis[x][y][od] == INF){
            dis[x][y][od] = dis[x][y][d] + 1;
            q.push(Node(x , y , od));
        }

    }
    return INF;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    mp["south"] = 0 , mp["east"] = 1 , mp["north"] = 2 , mp["west"] = 3;
    vector<pii> vec;
    int xs, ys , xd , yd , x , y , xo , yo;
    string dir;
    int d;

    while(cin >> n >> m){
        if(n == 0 && m == 0)
            break;
        memset(mat , 0 , sizeof mat);
        vec.clear();
        for(int i = 0 ; i <= n ; i ++){
            for(int j = 0 ; j <= m ; j++)
                for(int k = 0 ; k < 4 ; k++)
                    dis[i][j][k] = INF;
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                cin >> x;
                if(x == 1)
                    vec.pb(pii(i , j));
            }
        }

        for(int i = 0 ; i < (int)vec.size() ; i++){
            x = vec[i].fi;
            y = vec[i].se;
            mat[x][y] = 1;

            for(int j = 0 ; j < 3 ; j++){
                xo = x + idx_x[j];
                yo = y + idx_y[j];

                if(xo > n || yo > m || xo < 0 || yo < 0)
                    continue;
                else
                    mat[xo][yo] = 1;
            }
        }

        for(int i = 0 ; i <= n ; i++){
            mat[i][0] = mat[i][m] = 1;
        }

        for(int i = 0 ; i <= m ; i++){
            mat[0][i] = mat[n][i] = 1;
        }

        /*for(int i = 0 ; i <= n ; i++){
            for(int j = 0 ; j <= m ; j++)
                cout << mat[i][j] << ' ' ;
            cout << endl;
        }*/

        cin >> xs >> ys >> xd >> yd;
        cin >> dir;

        if(mat[xs][ys] == 1 || mat[xd][yd] == 1){
            cout << -1 << endl;
            continue;
        }
        int ans = bfs(xs , ys , xd , yd , mp[dir]);
        if(ans == INF)
            cout << -1 << endl;
        else
            cout << ans << endl;

    }

    return 0;
}

/*
9 10
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 1 0
0 0 0 1 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 1 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 1 0
7 2 2 7 south
*/
