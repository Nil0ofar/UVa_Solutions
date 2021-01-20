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
#define N 400000 + 5
#define mod 1000000007
#define Base 3002
#define double long double
#define ret(x) return cout << x << endl , 0
#define ordered_set tree<pll, null_type, less<pll>, rb_tree_tag,tree_order_statistics_node_update>
#define pci pair<char , int>
#define double long double


int main(){
    ios_base :: sync_with_stdio(false);
    int tc;
    scanf("%d" , &tc);
    for(int t = 1 ; t <= tc ; t++){
        int n ;
        scanf("%d" , &n);
        int a1 , a2 , a , b1 , b2 , b ;
        set<pii> st;
        for(int i = 0 ; i < n ; i++){
            scanf("%d.%d %d.%d" , &a1 , &a2 , &b1 , &b2);
            a = a1 * 100 + a2 ;
            b = b1 * 100 + b2 ;
            st.insert({a , b});
        }

        vector<pii> vec;
        for(auto s : st)
            vec.pb(s);
        n = vec.size();
        int mx = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == j)
                    continue;
                a1 = vec[i].fi - vec[j].fi ;
                b1 = vec[i].se - vec[j].se ;
                a1 = abs(a1);
                b1 = abs(b1);
                int gcd = __gcd(a1 , b1);
                a1 /= gcd;
                b1 /= gcd;
                bool pos = (a1 * b1 >= 0);
                int cnt = 0;

                for(int k = 0 ; k < n ; k++){
                    if(k == i || k == j)
                        continue;
                    a2 = vec[i].fi - vec[k].fi;
                    b2 = vec[i].se - vec[k].se;
                    a2 = abs(a2);
                    b2 = abs(b2);
                    int gcd = __gcd(a2 , b2);
                    a2 /= gcd;
                    b2 /= gcd;
                    bool pos_2 = (a2 * b2 >= 0);
                    if(a1 == a2 && b1 == b2 && pos_2 == pos)
                        cnt++;
                }

                mx = max(mx , cnt);
            }
        }

        printf("Data set #%d contains " , t) ;
        if(n == 1)
            printf("a single gnu.\n");
        else
            printf("%d gnus, out of which a maximum of %d are aligned.\n" , n , mx + 2);

    }
    return 0;
}


