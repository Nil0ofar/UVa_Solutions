#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define N 1005
#define ll long long
#define pii pair<int , int>
#define fi first
#define se second
#define mod 998244353LL
#define INF 2000000007
#define pci pair<char , int>
#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag,tree_order_statistics_node_update>

int n , len , C;
pii dp[1024][512];
int t[1024];
inline int p2(int x){return x * x;}

pii f(int idx , int rem){
    if(idx == n){
        if(rem == 0)
            return {0 , 0};
        if(rem <= 10)
            return {0 , -C};
        return {0 , p2(rem - 10)};
    }

    pii &ref = dp[idx][rem] ;
    pii temp;

    if(ref.fi != -1)
        return ref;

    if(rem == 0){
        ref = f(idx , len);
        ref.fi++;
    }
    else if(rem < t[idx]){
        ref = f(idx , len);
        ref.fi++;
        if(rem <= 10)
            ref.se -= C;
        else
            ref.se += p2(rem - 10);
    }
    else{
        ref = f(idx + 1 , rem - t[idx]);
        temp = f(idx, len);
        temp.fi++;

        if(rem <= 10)
            temp.se -= C;
        else
            temp.se += p2(rem - 10);

        if(temp.fi < ref.fi || (temp.fi == ref.fi && temp.se < ref.se))
            ref = temp;
    }
    return ref;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    int tc = 1;
    while(cin >> n && n != 0){
        cin >> len >> C;

        for(int i = 0 ; i < n ; i++)
            cin >> t[i];

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j <= len ; j++)
                dp[i][j] = {-1 , -1};
        }
        if(tc > 1)
            cout << endl;
        cout << "Case " << tc++ << ":\n";
        cout << "Minimum number of lectures: " << f(0 , 0).fi << endl;
        cout << "Total dissatisfaction index: " << f(0 , 0).se << endl;
    }
    return 0;
}
