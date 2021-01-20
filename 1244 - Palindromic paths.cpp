#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000000
#define fi first
#define se second
#define ll long long
#define pll pair<ll , ll>
#define pii pair<int , ll>
#define pb push_back
#define N 55
#define mod 1000000007
#define ordered_set tree<pll, null_type,greater<pll>, rb_tree_tag,tree_order_statistics_node_update>

struct Ret{
    bool seen;
    string s;
    string mid;
    Ret(){
        s = "";
        mid = "";
        seen = false;
    }

    int get_sz(){
        return (int)s.size() * 2 + (int)mid.size();
    }
} dp[N][N];
string mat[N];

bool comp(string a , string b){
    reverse(a.begin() , a.end());
    reverse(b.begin() , b.end());
    return a > b;
}

Ret f(int l , int r){
    Ret &ref = dp[l][r];
    if(l == r){
        ref.seen = true;
        return ref;
    }

    if(ref.seen)
        return ref;

    ref.seen = true;
    ref.mid += mat[l][r];
    Ret temp;

    for(int i = l + 1 ; i < r ; i++){
        for(int j = r - 1 ; j >= i ; j--){
            if(mat[l][i] == mat[r][j]){
                temp = f(i , j);
                temp.s += mat[l][i];
                if(ref.get_sz() < temp.get_sz())
                    ref = temp;

                else if(ref.get_sz() == temp.get_sz()){
                    if(comp(ref.s , temp.s))
                        ref = temp;
                    else if(ref.s == temp.s && ref.mid > temp.mid)
                        ref = temp;
                }
            }
        }
    }
    return ref;
}

int main(){
    //ios_base :: sync_with_stdio(false);
    int t , n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0 ; i < n ; i++)
            cin >> mat[i];
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++)
                dp[i][j] = Ret();
        }
        Ret ans = f(0 , n - 1);
        string temp = ans.s;
        reverse(temp.begin() , temp.end());
        cout <<temp << ans.mid << ans.s << endl;
    }

    return 0;
}
