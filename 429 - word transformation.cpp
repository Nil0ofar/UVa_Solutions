#include<bits/stdc++.h>

using namespace std;

int mat[205][205];
map<int,string> mp_itos;
map<string,int> mp_stoi;
int dis[205];
int n=0;

void bfs(int start)
{
    queue<int> q;
    dis[start]=0;
    q.push(start);
    int cn;
    while(!q.empty())
    {
        cn=q.front();
        q.pop();
        for(int i=0; i<n; i++)
        {
            if(mat[cn][i]==1 && dis[i]==-1)
            {
                dis[i]=dis[cn]+1;
                q.push(i);
            }
        }
    }
}
int main()
{
    int testcases;
    string s;
    getline(cin,s);
    stringstream ss(s);
    ss>>testcases;
    string a,b;
    int start,ending;
    getline(cin,s);
    while(testcases)
    {
        memset(mat,0,sizeof mat);
        n=0;
        getline(cin,s);
        while(s!="*")
        {
            mp_itos[n]=s;
            mp_stoi[s]=n;
            n++;
            getline(cin,s);
        }
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(mp_itos[i].size()!=mp_itos[j].size())
                    continue;
                int cnt=0;
                for(int k=0; k<mp_itos[i].size(); k++)
                {
                    if(mp_itos[i][k]!=mp_itos[j][k])
                        cnt++;
                }
                if(cnt==1)
                    mat[i][j] = mat[j][i]=1;
            }
        }
        while(getline(cin,s) && s!="")
        {
            memset(dis,-1,sizeof dis);
            stringstream ss(s);
            ss>>a;
            ss>>b;
            start = mp_stoi[a];
            ending = mp_stoi[b];
            bfs(start);
            cout<<a<<' '<<b<<' '<<dis[ending]<<endl;
        }
        if(testcases!=1)
            cout<<endl;
        testcases--;
    }
}
