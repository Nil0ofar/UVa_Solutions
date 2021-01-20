#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back

const int N = 70000;
int n , p , q;
int pos[N];
vector<int> arr;
vector<int> t;

int bs(int i , int j , int key){
    if(i == j){
        if(t[i] > key)
            return i;
        return i + 1;
    }

    int mid = (i + j) / 2;
    if(t[mid] > key)
        return bs(i , mid , key);
    return bs(mid + 1 , j , key);
}

int f(){
    if(arr.size() == 0)
        return 0;
    t.clear();
    t.pb(arr[0]);
    int idx;
    for(int i = 1 ; i < arr.size() ; i++){
        idx = bs( 0 , t.size() - 1 , arr[i]);
        if(idx == t.size())
            t.pb(arr[i]);
        else
            t[idx] = arr[i];
        //cout<<t[idx]<<endl;
    }
    return t.size();
}

int main(){
    int testcase;
    int x;
    cin >> testcase;

    for(int t = 1 ; t <= testcase ; t++){
        cin >> n >> p >> q;
        memset(pos , -1 , sizeof pos);
        arr.clear();

        for(int i = 0 ; i <= p ; i++){
            cin >> x;
            pos[x] = i;
        }

        for(int i = 0 ; i <= q ; i++){
            cin >> x;
            if(pos[x] != -1){
                arr.pb(pos[x]);
            }
        }

        cout<<"Case "<< t<<": "<< f() << "\n";

    }
    return 0;
}
