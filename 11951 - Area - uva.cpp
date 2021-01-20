// rahe hal n^4 ham acc shod , vali zamanesh 2s bod, vali in n^3 va zamanesh 0.040s ast

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int , int>

const int N = 105;
int n , m , p;
int mat[N][N];
ll a[N];
ll cost = 0;
ll cost_temp = 0;

ll f(){
    int i = 0 ,  j = 1;
    ll len = 0;
    cost_temp = 0;
    while(j <= n){
        if(a[j] - a[i] <= p)
            j++;

        else{
            if(len < j - i - 1 ){
                len = j - i - 1;
                cost_temp = a[j-1] - a[i];
            }
            else if( len == j - i - 1)
                cost_temp = min(cost_temp , a[j-1] - a[i]);
            i++;
        }
        //cout<<"here  "<<i<<' '<<j<<' '<<len<<endl;
    }
    if(len < j - i - 1){
        len = j - i - 1 ;
        cost_temp = a[j-1] - a[i];
    }
    else if(len == j - i - 1)
        cost_temp = min(cost_temp, a[j-1] - a[i]);
    return len;
}

int main()
{
    int testcase ;
    cin >> testcase;
    ll temp;
    ll ans;
    for(int t = 1 ; t <= testcase ; t++){
        cin >> n >> m >> p;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++)
                cin >> mat[i][j];
        }

        ans = 0;

        for(int i = 1 ; i <= m ; i++){
            memset(a , 0 , sizeof a);
            for(int j = i ; j <= m ; j++){
                temp = 0;
                for(int k = 1 ; k <= n ; k++){
                    temp += mat[k][j];
                    a[k] += temp;
                }

                temp = f();
                if(ans < temp * (j - i + 1)){
                    //cout<<ans<<' '<<temp<<' '<<j<<' '<<i<<endl;
                    ans = temp * (j - i + 1);
                    cost = cost_temp;
                }
                else if(ans == temp * (j - i + 1)){
                    cost = min(cost , cost_temp);
                }

            }
        }
        cout<<"Case #"<<t<<": "<<ans<<' '<<cost<<endl;
    }
    return 0;
}
