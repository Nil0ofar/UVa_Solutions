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
#define N 1000000 + 5
#define mod 1000000007
#define Base 3002
#define double long double
#define ret(x) return cout << x << endl , 0
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pci pair<char , int>
#define double long double

ordered_set os;

int main(){
    ios_base :: sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        int n , x;
        cin >> n ;
        os.clear();

        for(int i = 1 ; i <= n ; i++)
            os.insert(i);

        for(int i = 0 ; i < n ; i++){
            cin >> x ;
            if(i != 0)
                cout << ' ' ;
            auto it = os.find_by_order(x) ;
            cout << *it ;
            os.erase(it);
        }
        cout << endl;
    }
    return 0;
}


