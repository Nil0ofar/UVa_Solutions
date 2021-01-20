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
#define pii pair<int , int>
#define pb push_back
#define N 25005
#define mod 998244353
#define Base 31LL
#define ordered_set tree<pll, null_type,greater<pll>, rb_tree_tag,tree_order_statistics_node_update>

string word[N];
int sz[N];
vector<int> vec[N];
map<string ,int> mp;
int dp[N];
int n ;


int main(){
    ios_base :: sync_with_stdio(false);
    n = 1;
    string s;
    while(cin >> s && s != "@@"){
        word[n] = s;
        sz[n] = s.size();
        dp[n] = 1;
        mp[word[n]] = n;
        n++;
    }

    char temp ;
    int p;

    for(int idx = 1 ; idx < n ; idx++){
        for(int i = 0 ; i < sz[idx] ; i++){
            s = word[idx];
            while(s[i] < 'z'){ //change
                s[i]++;
                if(mp.count(s) == 0)
                    continue;
                vec[idx].pb(mp[s]);
                break;
            }
        }
        s = word[idx];
        s += 'a';
        for(int i = sz[idx] ; i >= 0 ; i--){
            s[i] = 'a';
            while(s[i] <= 'z'){

                if(mp.count(s)){
                    p = mp[s];

                    if(p > idx) // add
                        vec[idx].pb(p);

                    if(p < idx) //delete
                        vec[p].pb(idx);
                }
                s[i]++;
            }
            if(i > 0)
                swap(s[i] , s[i - 1]);
        }
    }

    int ans = 0;

    for(int i = 1 ; i < n ; i++){
        for(auto p : vec[i]){
            dp[p] = max(dp[p] , dp[i] + 1);
        }
    }

    cout << *max_element(dp + 1 , dp + n ) << endl;
    return 0;
}
