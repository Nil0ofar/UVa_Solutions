#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int , int>
#define pll pair<long long , long long>
#define fi first
#define se second
//#define N 200005
#define mod 1000000007
#define double long double
#define INF 1e18 + 7


int main(){
    string s;
    stack<string> r , D;
    int N;
    string temp;
    while(cin >> s && s != "0"){
        N = 0;
        for(int i = 0 ; i < (int)s.size() ; i++){
            if(s[i] == 'N')
                N++;

            else if(s[i] >= 'A' && s[i] <= 'Z'){
                temp = "";
                temp += s[i];
                D.push(temp);
            }
            else{
                temp = "";
                temp += s[i];
                r.push(temp);
            }
        }

        if((int)r.size() == 0){
            cout << "no WFF possible\n";
            continue;
        }
        string ans = "";
        for(int i = 0 ; i < N ; i++)
            ans += 'N';
        ans += r.top();
        r.pop();
        r.push(ans);

        ans = "";
        int x = min(D.size() ,r.size() - 1) ;
        for(int i = 0 ; i < x; i++){

            ans += D.top();
            D.pop();
            ans += r.top();
            r.pop();
        }
        ans += r.top();
        cout << ans << endl;
        while(!D.empty())
            D.pop();
        while(!r.empty())
            r.pop();
    }
}
