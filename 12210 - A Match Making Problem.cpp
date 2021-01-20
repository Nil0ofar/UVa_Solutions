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


int main(){
    int n , m;
    int d[N];
    int k[N];
    while(cin >> n >> m){
        if(n == 0 && m == 0)
            break;
        for(int i = 0 ; i < n ; i++)
            cin >> d[i];

        for(int i = 0 ; i < m ; i++)
            cin >> k[i];

        sort(d , d + n);
        sort(k , k + m);

        int ii = 0 , jj = 0;
        ll sum = 0;
        while(jj < m && ii < n){
            if(d[ii] <= k[jj]){
                sum += k[jj];
                ii++ , jj++;
            }

            else
                jj++;
        }

        if(ii == n)
            cout << sum << endl;
        else
            cout << "Loowater is doomed!\n" ;
    }
    return 0;
}
