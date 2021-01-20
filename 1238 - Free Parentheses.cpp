#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define N 6005
#define ll long long
#define pii pair<int , int>
#define fi first
#define se second
#define mod 1000000007
#define INF 2000000007
#define pci pair<char , int>
#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag,tree_order_statistics_node_update>
#define double long double

bool check[N][32][32];
int sgn[32];
int val[32];
bool mark[N];
int n;

void f(int sum , int idx , int m){
    if(idx == n){
        mark[sum] = true;
        return ;
    }

    if(check[sum][idx][m])
        return;

    check[sum][idx][m] = true;

    if(m % 2 == 0) // no effect
        sum += sgn[idx] * val[idx];
    else
        sum -= sgn[idx] * val[idx];

    if(sgn[idx] == -1)
        m++;

    for(int i = m ; i >= 0 ; i--)
        f(sum , idx + 1 , i);

}

int main()
{
    ios_base :: sync_with_stdio(false);
    string s;
    char c;
    while(getline(cin , s)){
        stringstream ss(s);
        ss >> val[0];
        sgn[0] = 1;
        n = 1;
        while(ss >> c){
            if(c == '-')
                sgn[n] = -1;
            else
                sgn[n] = 1;
            ss >> val[n];
            n++;
        }
        memset(check , false , sizeof check);
        memset(mark , false , sizeof mark);

        f(3000 , 0 , 0);

        int cnt = 0;
        for(int i = 0 ; i < N ; i++)
            if(mark[i])
                cnt++;

        cout << cnt << endl;
    }
    return 0;
}
