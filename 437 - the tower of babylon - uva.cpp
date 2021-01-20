#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair(int , int)

struct Block{
    int x, y, z;
    Block(int _x, int _y , int _z){
        x = _x;
        y = _y;
        z = _z;
    }
    const bool operator<(const Block &block)const{
        if(x > block.x)
            return true;
        if(x == block.x && y > block.y)
            return true;
        return false;
    }
};
int n;
vector<Block> block;
vector<ll> dp;

void setBlock(int x, int y , int z){
    block.pb(Block(x, y , z));
    block.pb(Block(x, z , y));
    block.pb(Block(y, x , z));
    block.pb(Block(y, z, x));
    block.pb(Block(z, x, y));
    block.pb(Block(z, y, x));
    for(int i = 0 ; i < 6 ; i++)
        dp.pb(-1);
}

ll f(int idx){
    if(idx == n){
        return 0;
    }
    if(dp[idx] != -1)
        return dp[idx];
    ll ans = block[idx].z;
    for(int i = idx + 1 ; i < n ; i++){
        if(block[i].x < block[idx].x && block[i].y < block[idx].y)
            ans = max(ans, block[idx].z + f(i));
    }
    dp[idx] = ans;
    return ans;
}

int main()
{
    int testcase = 1;
    int x, y , z;
    while(cin >> n , n != 0){
        block.clear();
        dp.clear();
        for(int i = 0 ; i < n ; i++){
            cin >> x >> y >> z;
            setBlock(x, y , z);
        }
        sort(block.begin(), block.end());
        n*=6;
        ll ans = -1;
        for(int i = 0 ; i < n ; i++){
            ans = max(ans, f(i));
        }
        printf("Case %d: maximum height = %lld\n" , testcase , ans);
        testcase++;
    }
}
