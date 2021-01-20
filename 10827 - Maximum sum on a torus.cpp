// rahe hal n^4 ham acc shod , vali zamanesh 2s bod, vali in n^3 va zamanesh 0.040s ast

#include <bits/stdc++.h>

using namespace std;

const int N = 80;
int mat[N][N];
int n;
int a[N];
int dp[N];
int dp_min[N];
bool mark[N];

int find_min(int idx){
    if(idx == n)
        return 0;
    if(mark[idx])
        return dp_min[idx];
    int ans = min(a[idx] , a[idx] + find_min(idx + 1));
    mark[idx] = true;
    dp_min[idx] = ans;
    return ans;
}

int f(int idx ){
    if(idx == n )
        return 0;
    if(mark[idx])
        return dp[idx];
    int ans = max(a[idx] , a[idx] + f(idx + 1));
    mark[idx] = true;
    dp[idx] = ans;
    return ans;
}

int main()
{
    int testcase ;
    cin >> testcase;

    int ans;
    bool first_min;
    int mn;
    int sum;

    while(testcase--){
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cin >> mat[i][j];
            }
        }
        bool first = true;

        for(int i = 0 ; i < n ; i++){
            int j = i;
            memset(a , 0 , sizeof a);
            for(int k = 0 ; k < n ; k++){
                sum = 0;
                for(int h = 0 ; h < n ; h++){
                    a[h] += mat[j][h];
                    sum += a[h];
                }
                j++;
                j%=n;
                first_min = true;
                memset(mark , false, sizeof mark);
                for(int h = 0 ; h < n ; h++){
                    if(first_min){
                        first_min = false;
                        mn = find_min(h);
                    }
                    else
                        mn = min(mn , find_min(h));
                }
                memset(mark, false, sizeof mark);
                if(first){
                    ans = sum - mn;
                    first = false;
                }
                else
                    ans = max(ans , sum - mn);
                for(int h = 0 ; h < n ; h++){
                    ans = max(ans , f(h));
                }
            }
        }

        cout<<ans<<endl;

    }
    return 0;
}
