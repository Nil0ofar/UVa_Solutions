#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int , int>
#define pll pair<long long , long long>
#define fi first
#define se second
#define N 505
#define mod 1000000007
#define double long double
#define INF 1e18 + 7

int a[10005];
int num[1000005];
vector<int> vec[10005];

int main(){
    int n;
    int mx;
    bool first = true;
    while(cin >> n && n != 0){
        if(!first){
            cout << endl;
        }
        first = false;
        memset(num , 0 , sizeof num);
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
            num[a[i]]++;
        }
        sort(a , a+ n);
        mx = *max_element(num , num + 1000002);
        for(int i = 0 ; i < mx ; i++)
            vec[i].clear();

        for(int i = 0 ; i < n ; i++){
            vec[i % mx].pb(a[i]);
        }

        cout << mx << endl;
        for(int i = 0 ; i < mx ; i++){
            for(int j = 0 ; j < vec[i].size() ; j++){
                if(j != 0)
                    cout << ' ' ;
                cout << vec[i][j];
            }
            cout << endl;
        }

    }
    return 0;
}
