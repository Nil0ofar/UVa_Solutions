#include<bits/stdc++.h>

using namespace std;

int n , m;
int v[1005];

bool ok(int lim){
    int cnt = 1;
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        if(v[i] > lim)
            return false;
        if(v[i] + sum <= lim)
            sum += v[i];
        else{
            cnt++;
            sum = v[i];
        }
    }
    if(cnt <= m)
        return true;
    return false;
}

int main(){
    while(cin >> n >> m){
        for(int i = 0 ; i < n ; i++)
            cin >> v[i];

        int ii = 1 , jj = 1e9 + 5;
        while(ii < jj){
            int mid = (ii + jj) / 2;
            if(ok(mid))
                jj = mid;
            else
                ii = mid + 1;
        }
        cout << ii << endl;
    }
    return 0;
}
