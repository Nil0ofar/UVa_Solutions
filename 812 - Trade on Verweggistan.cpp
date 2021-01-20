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

int w , n;
vector<int> vec[55];
int a[25];
bool check[55][1005];
bool mark[1005];

pii find_mx(){
    int last = -1;
    int sum = 0;
    int mx = 0;
    for(int i = 0 ; i < n ; i++){
        sum += a[i];
        if(sum > mx){
            mx = sum;
            last = i;
        }
    }
    return pii(mx , last);
}

void set_vec(int idx , int last){
    vec[idx].clear();
    vec[idx].pb(0);

    int sum = 0;
    for(int i = last + 1 ; i < n ; i++){
        sum += a[i];
        if(sum == 0)
            vec[idx].pb((i - last));
    }
}

void f(int idx , int sum){
    if(idx == w){
        mark[sum] = true;
        return;
    }

    if(check[idx][sum])
        return;

    for(auto v : vec[idx]){
        f(idx + 1 , sum + v);
        //cout << v << endl;
    }
    check[idx][sum] = true;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    bool first = true;
    int sum , cnt;
    vector<int> num;
    int tc = 1;
    while(cin >> w && w != 0){
        if(!first)
            cout << endl;
        first = false;
        sum = 0 , cnt = 0;
        for(int i = 0 ; i < w ; i++){
            cin >> n ;
            for(int j = 0 ; j < n ; j++){
                cin >> a[j];
                a[j] = 10 - a[j];
            }

            pii p = find_mx();
            sum += p.fi;
            cnt += (p.se + 1);
            set_vec(i , p.se);

        }

        memset(mark , false ,sizeof mark);
        memset(check , false , sizeof check);
        f(0 , 0);
        num.clear();
        for(int i = 0 ; i < 1005 ; i++){
            if(mark[i])
                num.pb(cnt + i);
        }

        cout << "Workyards " << tc++ << endl;
        cout << "Maximum profit is " << sum << ".\n";
        cout << "Number of pruls to buy:";
        for(int i = 0 ; i < (int)num.size() ; i++){
            if(i == 10)
                break;
            cout << ' ' << num[i];
        }
        cout << endl;
    }
    return 0;
}
