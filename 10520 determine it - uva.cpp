#include<bits/stdc++.h>

#define DIM 307
#define oo 2000000000L

using namespace std;

long N,T1,T2;
long A[307];
int B[33][DIM],C[33][DIM];
long D[33][DIM];
int R[33][DIM];
int Res[33];

int ReadData()
{ long i,j;
  cin>>T1>>T2;
  if(T1==0 && T2==0) return 0;
  cin>>N;
  for(i=1;i<=N;i++)
  {
    cin>>A[i];
    for(j=1;j<=A[i];j++) cin>>B[i][j];
    for(j=1;j<=A[i];j++) cin>>C[i][j];
  }
  return 1;
}

void Solve()
{ long s,k,p,i,j;
  for(i=0;i<33;i++)
    for(j=0;j<DIM;j++) D[i][j]=0;
  s=0;
  for(i=1;i<=N;i++)
  { s+=A[i];
    for(j=0;j<=T1;j++)
    { D[i][j]=oo;
      p=j; if(A[i]<j) p=A[i];
      for(k=0;k<=p;k++)
	if(D[i][j]>D[i-1][j-k]+B[i][k]+C[i][A[i]-k])
	{
	  D[i][j] = D[i-1][j-k]+B[i][k]+C[i][A[i]-k];
	  R[i][j] = k;
	}
    }
  }
  cout<<D[N][T1]<<endl;
  p=T1;
  for(i=N;i>=1;i--)
  { Res[i]=R[i][p];
    p=p-R[i][p];
  }
  for(i=1;i<=N;i++) cout<<Res[i]<<' ';
  cout<<endl<<endl;
}

int main()
{
  while(ReadData()) Solve();
  return 0;
}
