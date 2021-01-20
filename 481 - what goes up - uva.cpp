#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair(int , int)

vector< int > arr;
vector< int > parent;
vector< int > temp;
int n = 0;
int len = 0;

int bs(int i , int j , int key){
    if(i==j){
        if(arr[temp[i]] >= key)
            return i;
        if(arr[temp[i]] < key)
            return i+1;
    }
    int mid = (i + j) / 2;
    if(arr[temp[mid]] == key)
        return mid;
    if(arr[temp[mid]] < key)
        return bs(mid + 1 , j , key);
    else
        return bs(i , mid , key);
}

void print(int x){
    if(x == -1)
        return;
    print(parent[x]);
    cout<<arr[x]<<endl;
}

int main()
{
    int x;
    while(cin >> x){
        arr.pb(x);
        parent.pb(-1);
        n++;
        if(n == 11)
            break;
    }

    temp.pb(0);
    len = 1;
    for(int i = 1 ; i < n ; i++){
        x = bs(0 , len - 1 , arr[i]);
        //cout<<i<<' '<<x<<endl;
        if(x == len){
            len++;
            temp.pb(i);
        }
        else{
            temp[x] = i;
        }
        if(x >= 1)
            parent[i] = temp[x - 1];
    }
    cout<<len<<endl<<'-'<<endl;
    x = temp[len - 1];
    print(x);
}
