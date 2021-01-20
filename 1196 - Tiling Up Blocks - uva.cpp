#include <bits/stdc++.h>

using namespace std;

#define pii pair<int , int>
#define ll long long
#define pb push_back
#define pli pair<long long , int >

struct Block{
    int x, y;
    Block(){}
    Block(int _x , int _y){
        x = _x;
        y = _y;
    }
    const bool operator<(const Block &block)const{
        if(x < block.x)
            return true;
        if(x == block.x && y < block.y)
            return true;
        return false;
    }
};

int n ;
Block block[10005];
int dp[10005];

int f(int idx){
    if(dp[idx] != -1)
        return dp[idx];
    int ans = 1;
    for(int i = idx + 1 ; i < n ; i ++){
        if(block[i].x >= block[idx].x && block[i].y >= block[idx].y)
            ans = max(ans , 1 + f(i));
    }
    dp[idx] = ans;
    return ans;
}

int main(){
    int x, y;
    while(cin >> n , n != 0){
        for(int i = 0 ; i < n ; i++){
            cin >> x >> y;
            block[i] = Block(x, y);
        }
        sort(block , block + n);
        memset(dp, -1 , sizeof dp);
        int ans = -1;
        for(int i = 0 ; i < n ; i++){
            ans = max(ans, f(i));
        }
        cout<<ans<<endl;
    }
    cout<<'*'<<endl;
    return 0;
}
