#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, long long>
#define pb push_back
#define fi first
#define se second
#define N 105
#define ll long long
#define mod 998244353
#define double long double
#define INF 1e9


int main()
{
    ios_base :: sync_with_stdio(false);
    int n , k;
    int cnt ,sum;
    int ii , jj;
    int a[605];

    while(cin >> n >> k){
        ii = 0;
        jj = 3000;
        for(int i = 0 ; i < n + 1 ; i++){
            cin >> a[i];
            ii = max(ii , a[i]);
        }

        while(ii < jj){
            int mid = (ii + jj) / 2;

            cnt = 0;
            sum = 0;
            for(int i = 0 ; i < n + 1 ; i++){
                if(sum + a[i] > mid){
                    cnt++;
                    sum = a[i];
                }
                else{
                    sum += a[i];
                }
            }

            if(cnt <= k)
                jj = mid;
            else
                ii = mid + 1;
        }

        cout << ii << endl;

    }
    return 0;
}

