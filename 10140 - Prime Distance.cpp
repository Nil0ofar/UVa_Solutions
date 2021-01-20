#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define N 700005
#define ll long long
#define mod 1000000007
#define pii pair<int , int>
#define fi first
#define se second


vector<ll> pr;
bool mark[N];

void find_pr(){
    for(int i = 2 ; i < N ; i++){
        if(!mark[i]){
            pr.pb(i);
            for(int j = 2 ; j * i < N ; j++)
                mark[i * j] = true;
        }
    }
}

bool is_pr(ll x){
    if(x < N)
        return !mark[x] ;

    for(int i = 0 ; i < (int)pr.size() ; i++){
        if(pr[i] * pr[i] > x)
            return true;
        if(x % pr[i] == 0)
            return false;
    }
}

vector<ll> vec;

int main()
{
    ios_base :: sync_with_stdio(false);
    find_pr();
    ll idx , l , r , mx , mn;
    ll a , b , c ,d ,x , y;

    while(scanf("%lld%lld" , &x , &y) == 2){
        if(x <= N && y <= N){
            l = lower_bound(pr.begin() , pr.end() , x) - pr.begin();
            r = upper_bound(pr.begin() , pr.end() , y) - pr.begin() - 1;
            mn = 1e9;
            mx = -1;

            for(int i = l + 1 ; i <= r ; i++){
                if(pr[i] - pr[i - 1] > mx){
                    mx = pr[i] - pr[i - 1];
                    c = pr[i - 1];
                    d = pr[i];
                }

                if(pr[i] - pr[i - 1] < mn){
                    mn = pr[i] - pr[i - 1];
                    a = pr[i - 1];
                    b = pr[i];
                }
            }
            if(r - l + 1 < 2)
                printf("There are no adjacent primes.\n");
            else
                printf("%lld,%lld are closest, %lld,%lld are most distant.\n" , a , b , c , d);
        }

        else{
            vec.clear();
            for(ll i = x ; i <= y ; i++){
                if(is_pr(i)){
                    vec.pb(i);
                }
            }

            mn = 1e9;
            mx = -1;
            for(int i = 1 ; i < (int)vec.size() ; i++){
                if(vec[i] - vec[i - 1] > mx){
                    mx = vec[i] - vec[i - 1];
                    c = vec[i - 1];
                    d = vec[i];
                }

                if(vec[i] - vec[i - 1] < mn){
                    mn = vec[i] - vec[i - 1];
                    a = vec[i - 1];
                    b = vec[i];
                }
            }

            if((int)vec.size() < 2)
                printf("There are no adjacent primes.\n");
            else
                printf("%lld,%lld are closest, %lld,%lld are most distant.\n" , a , b , c , d);
        }
    }
    return 0;
}
