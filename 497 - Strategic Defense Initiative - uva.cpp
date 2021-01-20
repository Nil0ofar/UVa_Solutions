#include <bits/stdc++.h>

using namespace std;

#define pii pair<int , int>
#define ll long long
#define pb push_back
#define pli pair<long long , int >

const int N = 1000000;
int a[N];
int parent[N];
vector<int> temp;
int n;

int bs(int i , int  j , int key){
    if(i == j){
        if(a[temp[i]] >= key)
            return i;
        return i + 1;
    }
    int mid = (i + j) / 2;
    if (a[temp[mid]] == key)
        return mid;
    if(a[temp[mid]] > key)
        return bs(i , mid , key);
    return bs(mid + 1, j , key);
}

int f(){
    temp.clear();
    memset(parent , - 1, sizeof parent);
    temp.pb(0);
    int idx ;
    for(int i = 1 ; i < n ; i++){
        idx = bs(0 , temp.size() - 1 , a[i]);
        if(idx == temp.size())
            temp.pb(i);
        else
            temp[idx] = i;
        if(idx != 0)
            parent[i] = temp[idx - 1];
    }
    return temp.size();
}

void print(int x){
    if(parent[x] != -1)
        print(parent[x]);
    cout<<a[x]<<endl;
}

int main()
{
    int testcase;
    bool first = true;
    string s;
    getline(cin , s);
    stringstream ss(s);
    ss >> testcase;
    getline(cin,s);
    while(testcase--){
        if(first)
            first = false;
        else
            cout<<endl;
        n = 0;
        while(getline(cin , s) && s!=""){
            stringstream ss(s);
            ss >> a[n++];
        }
        cout<<"Max hits: " << f() <<endl;
        print(temp[temp.size() - 1]);
    }
    return 0;
}
