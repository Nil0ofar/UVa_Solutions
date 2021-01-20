#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, long long>
#define pb push_back
#define fi first
#define se second
#define N 1000005
#define ll long long
#define mod 998244353
#define double long double

ll p2(ll x){
    return x * x;
}


int main()
{
    ios_base :: sync_with_stdio(false);
    int testcase;
    string s;
    getline(cin , s);
    stringstream ss(s);
    ss >> testcase;
    getline(cin , s);

    ll x, y , xs , ys , xf , yf;
    double dis;
    while(testcase--){
        getline(cin , s);
        dis = 0;
        stringstream ss2(s);
        ss2 >> x >> y ;
        while(getline(cin , s) && s != ""){
            stringstream ss3(s);
            ss3 >> xs >> ys >> xf >> yf;
            dis += sqrt(p2(xf - xs) + p2(yf - ys)) * 2.0;
        }

        ll h = dis / 20000.0;
        dis -= (h * 20000.0);
        dis *= 3.0;
        ll m = round(dis/1000);
        if(m == 60){
            m = 0 ;
            h++;
        }
        cout << h << ":" << setfill('0') << setw(2) << m << endl;
        if(testcase != 0)
            cout << endl;
    }

    return 0;
}

