#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;


int main(){
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);*/
    int mn , mx , t;
    int a[10005];
    int mod, temp;
    while(cin >> mn >> mx >> t){
        memset(a , -1, sizeof a);
        if(mn > mx)
            swap(mn, mx);
        for(int i = 0 ; i <= t/mx ; i++){
            temp = t - i * mx;
            mod = temp % mn;
            if(a[mod] == -1)
                a[mod] = temp / mn + i;

        }
        for(int i = 0 ; i < mn ; i++){
            if(a[i] == -1)
                continue;
            cout<<a[i];
            if(i!=0)
                cout<<' '<<i<<endl;
            else
                cout<<endl;
            break;
        }
    }
}
