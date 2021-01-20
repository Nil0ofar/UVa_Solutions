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

bool check[N][16][130];
vector<int> pr;
bool seen[1005];
vector<int> path;

bool comp(int x , int y){
    stringstream s1;
    stringstream s2;
    s1 << x;
    s2 << y;
    string sx , sy;
    s1 >> sx;
    s2 >> sy;
    return sx < sy;
}

void find_pr(){
    bool seen[305];
    memset(seen , false , sizeof seen);
    for(int i = 2 ; i < 300 ; i++){
        if(!seen[i]){
            pr.pb(i);
            if(i != 2)
                pr.pb(i);
            for(int j = 2 ; j * i < 300 ; j++)
                seen[i * j] = true;
        }
    }
}

bool f(int sum , int t , int idx){
    //cout << sum << ' ' << t << ' ' << idx << endl;
    if(t == 0){
        if(sum == 0)
            return true;
        return false;
    }

    if(sum <= 0)
        return false;

    if(idx == (int)pr.size())
        return false;

    if(check[sum][t][idx])
        return false;

    if(f(sum - pr[idx] , t - 1 , idx + 1)){
        path.pb(pr[idx]);
        return true;
    }

    if(f(sum , t , idx + 1))
        return true;

    check[sum][t][idx] = true;
    return false;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    find_pr();
    int p = pr.size();
    vector<int> v1 , v2;
    sort(pr.begin() , pr.end() , comp);

    int tc = 1;
    int n , t;

    while(cin >> n >> t && n != 0){
        cout << "CASE " << tc++ <<":\n";
        path.clear();
        memset(check , false , sizeof check);
        if(!f(n , t , 0))
            cout << "No Solution.\n";
        else{
            for(int i = t - 1 ; i >= 0 ; i--){
                cout << path[i] ;
                if(i != 0)
                    cout << '+';
            }
            cout << endl;
        }
    }
}
