#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define N 100005
#define ll long long
#define pii pair<int , int>
#define fi first
#define se second
#define mod 998244353LL
#define INF 2000000007
#define pci pair<char , int>
#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag,tree_order_statistics_node_update>

int n = 4;

int num(int x , int y){
    return x * n + y;
}

int dp[N];


bool f(int mask){
    if(mask == 0)
        return true;

    if(dp[mask] != -1)
        return (dp[mask] == 1);

    bool lose = true;
    int no;
    for(int x = 0 ; x < n ; x++){
        for(int y = 0 ; y < n ; y++){
            no = num(x , y);
            if((mask & (1 << num(x , y))) != 0){
                mask ^= (1 << num(x , y));
                if(!f(mask))
                    lose = false;
                if(no == 5 || no == 6 || no == 9 || no == 10){
                    mask ^= (1 << num(x , y));
                    continue;
                }
                if(no < 4 && x + 1 < n && (mask & (1 << num(x + 1 , y))) != 0){
                    mask ^= (1 << num(x + 1 , y));
                    if(!f(mask))
                        lose = false;
                    if(x + 2 < n && (mask & (1 << num(x + 2 , y))) != 0){
                        mask ^= (1 << num(x + 2 , y));
                        if(!f(mask))
                            lose = false;
                        mask ^= (1 << num(x + 2 , y));
                    }
                    mask ^= (1 << num(x + 1 , y));
                }

                if(no >= 12 && x - 1 >= 0 && (mask & (1 << num(x - 1 , y))) != 0){
                    mask ^= (1 << num(x - 1 , y));
                    if(!f(mask))
                        lose = false;
                    if(x - 2 < n && (mask & (1 << num(x - 2 , y))) != 0){
                        mask ^= (1 << num(x - 2 , y));
                        if(!f(mask))
                            lose = false;
                        mask ^= (1 << num(x - 2 , y));
                    }
                    mask ^= (1 << num(x - 1 , y));
                }

                if(no % 4 == 0 && y + 1 < n && (mask & (1 << num(x , y + 1))) != 0){
                    mask ^= (1 << num(x , y + 1));
                    if(!f(mask))
                        lose = false;
                    if(y + 1 < n && ( mask & (1 << num(x , y + 2))) != 0){
                        mask ^= (1 << num(x , y + 2));
                        if(!f(mask))
                            lose = false;
                        mask ^= (1 << num(x , y + 2));
                    }
                    mask ^= (1 << num(x , y + 1));
                }

                if(no % 4 == 3 && y - 1 < n && (mask & (1 << num(x , y - 1))) != 0){
                    mask ^= (1 << num(x , y - 1));
                    if(!f(mask))
                        lose = false;
                    if(y - 1 < n && ( mask & (1 << num(x , y - 2))) != 0){
                        mask ^= (1 << num(x , y - 2));
                        if(!f(mask))
                            lose = false;
                        mask ^= (1 << num(x , y - 2));
                    }
                    mask ^= (1 << num(x , y - 1));
                }
                mask ^= (1 << num(x , y));
            }
        }
    }
    if(!lose)
        dp[mask] = 1;
    else
        dp[mask] = 0;
    return !lose;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    memset(dp , -1 , sizeof dp);

    int t;
    cin >> t;
    string s;
    while(t--){
        int mask = 0;
        for(int i = 0 ; i < n ; i++){
            cin >> s;
            for(int j = 0 ; j < n ; j++){
                if(s[j] == '.')
                    mask |= (1 << num(i , j));
            }
        }

        if(f(mask))
            cout << "WINNING\n";
        else
            cout << "LOSING\n";

    }
}
