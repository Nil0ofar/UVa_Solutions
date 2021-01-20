#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define fi first
#define se second
#define ll unsigned long long
#define pii pair<int , int>
#define pb push_back
#define N 1000005
#define mod 1000000007

vector<int> pr;
bool mark[N];

void set_pr(){
    memset(mark , true , sizeof mark);
    mark[0] = mark[1] = false;
    for(int i = 2 ; i < N ; i++){
        if(mark[i]){
            pr.pb(i);
            for(int j = 2 ; i * j < N ; j++)
                mark[i * j] = false;
        }
    }
}

int main(){
    int n ;
    set_pr();
    cout << pr.size() << endl;
    while(cin >> n && n != 0){
        for(int i = 1 ; i <= n ; i++){
            if(mark[n - pr[i]]){
                printf("%d = %d + %d\n" , n , pr[i] , n - pr[i]);
                break;
            }
        }
    }
    return 0;
}
