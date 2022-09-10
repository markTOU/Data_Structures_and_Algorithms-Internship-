#include<cstdio>
#include<ctime>//必写
#include<cstdlib>//必写
#include<iostream>
using namespace std;
int max11=0;
int main()
{
  freopen("test4.data","w",stdout);
	srand(time(NULL));//必写
        int maxn=1600001,n,m;
    n=(rand()*rand())%maxn;
    m=(rand()*rand())%n;
	printf("%d %d\n",n,m);
  for(int i=1;i<=n;i++)
    { int x=(rand()*rand())%5/100000001,y=(rand()*rand())%100000001;
      printf("%d %d\n",x,y);
    }

    return 0;
}
