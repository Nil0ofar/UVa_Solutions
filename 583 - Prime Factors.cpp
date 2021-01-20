#include<bits/stdc++.h>

using namespace std;


#define INF 2000000005
#define fi first
#define se second
#define ll unsigned long long
#define pii pair<int , int>
#define pic pair<int , char>
#define pb push_back
#define N 100005
#define mod 1000000007

int f(int x){
    int cnt = 0;
    for(int i = 1 ; i <= sqrt(x) ; i++){
        if(x % i == 0){
            if(i * i == x)
                cnt++;
            else
                cnt += 2;
        }
    }
    return cnt;
}

int main(){
    int t;
    int l , r;
    scanf("%d" , &t);
    int mx , ans , cnt  , temp , x;
    while(t--){
        scanf("%d%d" , &l , &r);
        mx = -1;
        for(int x = l ; x <= r ; x++){
            temp = f(x);
            if(temp > mx){
                mx = temp;
                ans = x;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n" , l , r , ans , mx);
    }

    return 0;
}
