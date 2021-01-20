#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define N 20000005
#define ll long long
#define mod 1000000007
#define pii pair<int , int>
#define fi first
#define se second

bool mark[N];
vector<int> pr;

void find_pr(){
    for(int i = 2 ; i < N ; i++){
        if(mark[i] == false){
            pr.pb(i);

            for(int j = 2 ; i * j < N ; j++)
                mark[i * j] = true;
        }
    }
}

vector<pii> pair_ ;

void set_pair(){
    for(int i = 0 ; i < (int)pr.size() - 1 ; i++){
        if(pr[i + 1] - pr[i] == 2)
            pair_.pb(pii(pr[i] , pr[i + 1]));
    }
}


int main()
{
    ios_base :: sync_with_stdio(false);
    find_pr();
    set_pair();

    int n;
    while(scanf("%d" , &n) != EOF){
        printf("(%d, %d)\n" , pair_[n - 1].fi , pair_[n - 1].se);
    }
    return 0;
}
