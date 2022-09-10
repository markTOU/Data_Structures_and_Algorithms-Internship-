#include<cstdio>
#include<ctime>//必写
#include<cstdlib>//必写
#include<iostream>
using namespace std;
int max11=0;
int main()
{
  freopen("test3.data","w",stdout);
	srand(time(NULL));//必写
        int maxn=4000001,n;
    n=(rand()*rand())%maxn;
	printf("%d\n",n);
  for(int i=1;i<=n;i++)
    { int x=(rand()*rand())%100000001,y=(rand()*rand())%100000001;
      printf("%d %d\n",x,y);
    }

    return 0;
}
