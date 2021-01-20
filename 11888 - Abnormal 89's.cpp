#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define N 200005
#define ll long long
#define pii pair<int , int>
#define fi first
#define se second
#define Base 31
#define mod 1000000007

string s;
int n ;
ll hash_r[N] , hash_l[N];

ll power(int a , int b){
    if(b == 0)
        return 1;
    ll ans = power(a , b / 2);
    ans *= ans;
    ans %= mod;
    if(b % 2 == 1)
        ans *= a;
    ans %= mod;
    return ans;
}

void set_hl(){

    for(int i = 1 ; i <= n ; i++){
        hash_l[i] = hash_l[i - 1] * Base + (s[i - 1] - 'a' + 1);
        hash_l[i] %= mod;
    }
}

void set_hr(){
    for(int i = n ; i > 0 ; i--){
        hash_r[i] = hash_r[i + 1] * Base + (s[i - 1] - 'a' + 1);
        hash_r[i] %= mod;
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        cin >> s;
        n = s.size();

        for(int i = 0 ; i <= n + 1 ; i++)
            hash_r[i] = hash_l[i] = 0;

        set_hr();
        set_hl();

        bool ali = false;
        for(int i = 1 ; i < n ; i++){
            if((hash_l[i] == (hash_r[1] - (hash_r[i + 1] * power(Base , i))%mod + mod) % mod) &&
                (hash_r[i + 1] == (hash_l[n] - (hash_l[i] * power(Base , n - i))%mod + mod) % mod)){
                    ali = true;
                    break;
            }
        }

        if(ali){
            cout << "alindrome\n";
        }
        else{
            if(hash_l[n] == hash_r[1])
                cout << "palindrome\n";
            else
                cout << "simple\n";
        }
    }
    return 0;
}
