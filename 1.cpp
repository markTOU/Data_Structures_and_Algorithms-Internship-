//最终版本
//直接寻找或者利用前缀和时间复杂度会超标，
//所以直接利用二分查找缩减算法的时间复杂度
//本题的逻辑结构：线性表
//本题的存储结构：顺序
//解题思路和算法：对于该题目首先对数组进行排序，排序后通过二分查找，
//                查找出闭区间的两个端点在数组中对应的下标序号
//               再利用序号相减得到最终结果所对应的值。
//效率:时间复杂度O(mlogn)、空间复杂度O(n)：
//测试数据： （1）输入：5 2               输出:0
//                    1 3 7 9 11             3
//                    4 6
//                    7 12
//          （2）输入：5 2           输出：5
//                    7 3 9 1 10         3
//                    1 10
//                    5 12
//          (3)见输入数据文件test1.in 输出文件test1.out
#include <cstdio>
#include <cstdlib>
#include<iostream>
#include<algorithm>//THUoj无法使用
using namespace std;
int n,m,a[500010];
int cmp(const void *a, const void *b)
{
 return *(int*)a - *(int*)b;
}
//不存在则返回小于该值的最后一个元素的pos
int binarysearch(int v[], int const& e, int lo, int hi) {
 while (lo < hi) {
   int mi = (lo + hi) >> 1;
   (e < v[mi]) ? hi = mi : lo = mi + 1;
 }
 return --lo;//返回所搜索值的前一个pos，因为已经超过一个位置
}

int main()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)
  {
    scanf("%d",&a[i]);
  }
//  sort(a+1,a+n+1);
   qsort(a+1,n, sizeof(int), cmp);
  int a1,b1;
  for(int i=1;i<=m;i++)
  {
    scanf("%d%d",&a1,&b1);
    int s = binarysearch(a, a1, 1, n+1);
    int e = binarysearch(a, b1, max(s,1), n+1);
    if (s >= 1 && a[s] == a1)
      s--;
    printf("%d\n", e - s);
    }

  return 0;
}

/*
int k=1;
if (a[1]==0)
{  b[0]=1;  k=2;
  for(int i=1;i<=max1;i++)
  {
    if (i==a[k]){
      b[i]=b[i-1]+1;
      k++;
    }
    else b[i]=b[i-1];
  }
}
else {
for(int i=1;i<=max1;i++)
{
  if (i==a[k]){
    b[i]=b[i-1]+1;
    k++;
  }
  else b[i]=b[i-1];
}
}*///前缀和内容由于并未显著优化，所以最终并未使用该方法
