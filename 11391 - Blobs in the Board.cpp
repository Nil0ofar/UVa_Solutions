#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define N 200005
#define ll long long
#define pii pair<int , int>
#define fi first
#define se second
#define mod 1000000007
#define INF 2000000007
#define pci pair<char , int>
#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag,tree_order_statistics_node_update>
#define double long double

int idx_x[] = {0 , 1 , 1 , 1 , 0 , -1 , -1 , -1};
int idx_y[] = {1 , 1 , 0 , -1 , -1 , -1 , 0 , 1};
int mat[5][5];
int dp[N];

int r , c , n;

int cnt(int mask){
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
        if((mask & (1 << i)) != 0)
            ans++;
    return ans;
}

int f(int mask){

    if(cnt(mask) == 1)
        return 1;

    if(dp[mask] != -1)
        return dp[mask];

    int xo , yo , xm , ym;
    int ans = 0;

    for(int x = 0 ; x < r ; x++){
        for(int y = 0 ; y < c ; y++){
            if(mat[x][y] == 1){
                mat[x][y] = 0;
                mask ^= (1 << (x * c + y));

                for(int i = 0 ; i < 8 ; i++){
                    xo = x + idx_x[i] * 2;
                    yo = y + idx_y[i] * 2;
                    xm = x + idx_x[i];
                    ym = y + idx_y[i];

                    if(xo < 0 || yo < 0 || xo >= r || yo >= c || mat[xo][yo] == 1 || mat[xm][ym] == 0)
                        continue;

                    mat[xo][yo] = 1;
                    mat[xm][ym] = 0;
                    mask ^= (1 << (xo * c + yo));
                    mask ^= (1 << (xm * c + ym));

                    ans += f(mask);

                    mat[xo][yo] = 0;
                    mat[xm][ym] = 1;
                    mask ^= (1 << (xo * c + yo));
                    mask ^= (1 << (xm * c + ym));

                }

                mat[x][y] = 1;
                mask ^= (1 << (x * c + y));
            }
        }
    }
    dp[mask] = ans;
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    int tc;
    cin >> tc;
    int b , x , y;
    for(int t = 1 ; t <= tc ; t++){
        cin >> r >> c >> b;
        n = r * c;
        int mask = 0;

        memset(mat , 0 , sizeof mat);
        memset(dp , -1 , sizeof dp);

        for(int i = 0 ; i < b ; i++){
            cin >> x >> y ;
            x-- , y--;
            mat[x][y] = 1;
            mask ^= (1 << (x * c + y));
        }

        cout << "Case " << t << ": " << f(mask) << endl;
    }
    return 0;
}


