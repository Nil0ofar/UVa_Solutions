#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define ll long long
#define pll pair<ll , ll>
#define pii pair<int , int>
#define pbl pair<bool , ll>
#define pb push_back
#define N 1000 * 1000 + 5
#define mod 1000000007
#define Base 3002
#define ret(x) return cout << x << endl , 0
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const int INF = 1e9;
int n;
int board[64][32];
int ans ;
bool check[64][32][6005];

void f(int row , int idx , int sum){
    if(row == 2 * n - 2){
        ans = min(ans , abs(sum - Base));
        return;
    }

    if(check[row][idx][sum])
        return;

    check[row][idx][sum] = true;
    if(row < n - 1){
        f(row + 1 , idx , sum + board[row + 1][idx]);
        f(row + 1 , idx , sum - board[row + 1][idx]);
        f(row + 1 , idx + 1 , sum + board[row + 1][idx + 1]);
        f(row + 1 , idx + 1 , sum - board[row + 1][idx + 1]);
    }
    else{
        if(idx != 0){
            f(row + 1 , idx - 1 , sum + board[row + 1][idx - 1]);
            f(row + 1 , idx - 1 , sum - board[row + 1][idx - 1]);
        }
        if(idx != 2 * n - 2 - row){
            f(row + 1 , idx , sum + board[row + 1][idx]);
            f(row + 1 , idx , sum - board[row + 1][idx]);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    while(cin >> n && n != 0){

        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j <= i ; j++)
                cin >> board[i][j];

        for(int i = n - 1  ; i >= 0 ; i--)
            for(int j = 0 ; j < i ; j++)
                cin >> board[2 * n - i - 1][j];

        ans = INF;
        memset(check , false , sizeof check);
        f(0 , 0 , Base + board[0][0]);
        f(0 , 0 , Base - board[0][0]);
        cout << ans << endl;

    }
    return 0;
}
