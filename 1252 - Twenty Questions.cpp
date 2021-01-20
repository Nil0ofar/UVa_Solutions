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
#define pdd pair<double , double>
#define N (1 << 12)
#define mod 1000000007
#define Base 3002
#define double long double
#define ret(x) return cout << x << endl , 0
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pci pair<char , int>
#define double long double
#define all(x) (x).begin() , (x).end()

int m , n ;
string num[130];
int dp[N][N];
set<int> mark ;

int f(int mask , int ones){
    //cout << mask << ' ' << ones <<endl;
    if(dp[mask][ones] != -1)
        return dp[mask][ones];

    vector<int> idx ;
    int temp = 0;
    mark.clear();
    bool flag ;

    for(int i = 0; i < n; i++){
        flag = true;
        for(int j = 0 ; j < m ; j++){
            if(((mask & (1 << j)) == 0 && (ones & (1 << j)) != 0 && num[i][j] == '0') ||
                ((mask & (1 << j)) == 0 && (ones & (1 << j)) == 0 && num[i][j] == '1')){
                    flag  = false;
                    break;
            }
        }
        if(flag)
            idx.pb(i);
    }

    if((int)idx.size() == 1){
        dp[mask][ones] = 0;
    }
    else{
        int new_mask ;
        int &ans = dp[mask][ones];
        ans = m;
        for(int i = 0 ; i < m ; i++){
            if((mask & (1 << i))){
                new_mask = mask - (1 << i) ;
                ans = min(ans , 1 + max(f(new_mask , ones) , f(new_mask , ones + (1 << i))));
            }
        }
    }
    return dp[mask][ones];

}

int main(){
    ios_base :: sync_with_stdio(false);
    while(cin >> m >> n && (n | m) != 0){
        for(int i = 0 ; i < n ; i++)
            cin >> num[i];

        memset(dp , -1 , sizeof dp);
        cout << f((1 << m) - 1 , 0) << endl;

    }
    return 0;
}

/*
8 1
11010101
11 4
00111001100
01001101011
01010000011
01100110001
11 16
01000101111
01011000000
01011111001
01101101001
01110010111
01110100111
10000001010
10010001000
10010110100
10100010100
10101010110
10110100010
11001010011
11011001001
11111000111
11111011101

*/
