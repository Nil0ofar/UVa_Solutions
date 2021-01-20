#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testcase;
    string input;
    getline(cin,input);
    stringstream ss(input);
    ss>>testcase;
    getline(cin,input);
    int p,t;
    int x,y;
    set<int> st[105];
    int parent[105];
    while(testcase){
        getline(cin,input);
        cout<<input<<endl;
        stringstream ss(input);
        ss>>p>>t;
        cout<<p<<t<<endl;
        for(int i=1;i<=p;i++){
            st[i].clear();
            parent[i]=i;
        }
        while(getline(cin,input) && input!=""){
            stringstream ss(input);
            ss>>x>>y;
            st[x].insert(y);
        }
        int cnt=0;
        for(int i=1;i<p;i++){
            if(parent[i]==i){
                cnt++;
                for(int j=i+1;j<=p;j++){
                    if(st[i]==st[j])
                        parent[j]=parent[i];
                }
            }
        }
        cout<<cnt<<endl;
        testcase--;
    }
    return 0;
}
