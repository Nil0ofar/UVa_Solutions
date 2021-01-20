#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define fi first
#define se second
#define ll unsigned long long
#define pii pair<int , int>
#define pb push_back
#define N 200005
#define mod 1000000007

int gcd(int a , int b , int *x , int *y){
    if(a == 0){
        *x = 0 ;
        *y = 1;
        return b;
    }

    int x1 , y1;
    int g = gcd(b % a , a , &x1 , &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return g;
}

int main(){
    int a , b;
    int x , y , g;
    bool sw;
    while(cin >> a >> b){
        sw = false;
        if(a >= b){
            swap(a , b);
            sw = true;
        }

        g = gcd(a , b , &x , &y);
        if(!sw)
            cout << x << ' ' << y << ' ' << g << endl;
        else
            cout << y << ' ' << x << ' ' << g << endl;
    }
    return 0;
}
