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

int main(){
    string s;
    while(cin >> s && s != "0"){
        int n = s.size() ;
        int e = 0 , o = 0;
        for(int i = 0 ; i < n ; i++){
            if(i % 2 == 0)
                e += (s[i] - '0');
            else
                o += (s[i] - '0');
        }
        if(e % 11 == o % 11)
            cout << s << " is a multiple of 11.\n";
        else
            cout << s << " is not a multiple of 11.\n";
    }
    return 0;
}
