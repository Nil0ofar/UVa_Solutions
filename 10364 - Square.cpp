#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define N 200015
#define ll long long
#define pii pair<int , int>
#define fi first
#define se second
#define mod 998244353LL
#define pci pair<char , int>
#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag,tree_order_statistics_node_update>
#define INF 1e8

int n , len;
int val[25];
bool check[2000000];

bool f(int mask){
    if(mask == 0)
        return true;
    if(check[mask])
        return false;
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        if((mask & (1 << i)) == 0)
            sum += val[i];
    }
    sum %= len;
    for(int i = 0 ; i < n ; i++){
        if((mask & (1 << i)) != 0){
            if(sum + val[i] <= len){
                if(f((mask ^ (1 << i))))
                    return true;
            }
        }
    }
    check[mask] = true;
    return false;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    int t;
    cin >> t ;
    while(t--){
        cin >> n ;
        memset(check , false, sizeof check);
        len = 0;

        for(int i = 0 ; i < n ; i++){
            cin >> val[i];
            len += val[i];
        }
        if(len % 4 != 0){
            cout << "no\n";
            continue;
        }
        len /= 4;
        int mask = (1 << n) - 1;
        cout << (f(mask) ? "yes\n" : "no\n");
    }
    return 0;
}
