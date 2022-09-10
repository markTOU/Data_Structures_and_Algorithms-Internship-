#include<cstdio>
#include<ctime>//必写
#include<cstdlib>//必写
#include<iostream>
using namespace std;
int max11=0;
int main()
{
  freopen("test1.data","w",stdout);
	srand(time(NULL));//必写
        int maxn=500001,n,m;
    n=rand()%maxn;m=rand()%maxn;
	printf("%d %d\n",n,m);
  for(int i=1;i<=n;i++)
    { int x1=rand();
      max11=max(x1,max11);
      printf("%d ",x1);}
  for(int i=1;i<=m;i++)
  {
    int x=rand()%max11;
    printf("%d %d\n",x,(x+rand()%max11));
  }
    return 0;
}
