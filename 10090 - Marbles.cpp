#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define fi first
#define se second
#define ll long long
#define pii pair<int , int>
#define pb push_back
#define N 505
#define mod 1000000007

ll GCD(ll a , ll b , ll *x , ll *y){
    if(a == 0){
        *x = 0;
        *y = 1;
        return b;
    }

    ll x1 , y1;
    ll gcd = GCD(b % a , a , &x1 , &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int main(){
    ios_base :: sync_with_stdio(false);
    ll n;
    ll c1 , c2 , a , b;
    ll x , y ;
    while(cin >> n && n != 0){
        cin >> c1 >> a >> c2 >> b ;
        // ax + by = gcd
        ll gcd = GCD(a , b , &x , &y);
        if(n % gcd != 0)
            cout << "failed\n";
        else{
            bool swp = false;
            x *= (n / gcd);
            y *= (n / gcd);

            if(y < x){
                swp = true;
                swap(x , y);
                swap(a , b);
                swap(c1 , c2);
            }
            ll kmm = (a * b) / gcd;
            ll cnt = (y / (kmm / b));
            y -= cnt * (kmm / b);
            x += cnt * (kmm / a);

            if(x < 0){
                cout << "failed\n";
                continue;
            }

            if(c1 * b > a * c2){
                cnt = (x / (kmm / a));
                x -= cnt * (kmm / a);
                y += cnt * (kmm / b);
            }
            if(!swp)
                cout << x << ' ' << y << endl;
            else
                cout << y << ' ' << x << endl;
        }
    }
    return 0;
}
