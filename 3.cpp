//直接结构体一级快速排序可能会TLE
//快速排序+归并排序
//下方为快速排序加暴力搜寻
//本题的逻辑结构：线性表
//本题的存储结构：顺序
//解题思路和算法：对于该题目首先对灯塔的横坐标进行排序，排序后利用归并排序完成对于，
//                Y坐标的排序，同时利用归并排序分治的思想，在排序的过程中进行答案
//              的计算工作。
//效率:时间复杂度O(logn)、空间复杂度O(n)：
//测试数据： （1）输入：3               输出:1
//                    2 2
//                    4 3
//                    5 1
//          （2）输入：5            输出：9
//                    3 4
//                    1 3
//                    2 4
//                    12 8
//                    9  13
//          (3)见输入数据文件test3.in 输出文件test3.out
//#include<bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include<iostream>
//#include<algorithm>
using namespace std;
struct light{
  int x,y;
}a[5000000];
bool cmp(light v,light c)
{
  return v.x<c.x;
}
int cmp1(const void *a,const void *b)
{
  struct light *c=(light *)a;
  struct light *d=(light *)b;
  return c->x-d->x;
}
int main() {
  int n,ans=0;
  scanf("%d",&n );
  for (int i=1;i<=n;i++)
  scanf("%d%d",&a[i].x,&a[i].y );   /* code */
  qsort(a+1,n,sizeof(light),cmp1);
//  sort(a+1,a+n+1,cmp);
  for(int i=1;i<n;i++)
    for(int j=i+1;j<=n;j++)
  {
    if(a[i].y<=a[j].y)
    {
      ans++;
    }
  }
  cout<<ans;
  return 0;
}
//下方为快速排序+归并排序
/*//#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
//#include<algorithm>
using namespace std;
struct light{
  int x,y;
}a[4000001],tmp1[4000001];
int b[4000001],count=0;
int tmp[4000001];
long long  ans;
bool cmp(light v,light c)
{
  return v.x<c.x;
}
int cmp1(const void *a,const void *b)
{
  struct light *c=(light *)a;
  struct light *d=(light *)b;
  if(c->x!=d->x)return c->x-d->x;
  else
    return c->y-d->y;
}
void merge(int l,int r,int mid)
{
  int x1=0,x2=l,x3=mid+1;

  while (x2<=mid&&x3<=r) {
    if (b[x2]<b[x3]) {
      tmp[x1++]=b[x2++];
      ans+=r-x3+1;
      }
    else
      tmp[x1++]=b[x3++];
  }
  while(x2<=mid){
      tmp[x1++]=b[x2++];
  }
  while(x3<=r){
    tmp[x1++]=b[x3++];}
    for(int i=0;i<r-l+1;i++)
    {
      b[i+l]=tmp[i];
    }


    return;
}
void mergesort(int l,int r)//guibingpaixu
{
  int mid=(l+r)>>2;
  if (l<r) {
    mergesort(l,mid);
    mergesort(mid+1,r);
    merge(l,r,mid);
  }
  return;
}
void mmerge(int l,int r,int mid)
{
  int x1=0,x2=l,x3=mid+1;

  while (x2<=mid&&x3<=r) {
    if (a[x2].x<a[x3].x||(a[x2].x==a[x3].x&&a[x2].y<a[x3].y)) {
      tmp1[x1++]=a[x2++];
      //ans+=r-mid-(x3-mid-1);
      }
    else
      tmp1[x1++]=a[x3++];
  }
  while(x2<=mid){
      tmp1[x1++]=a[x2++];
  }
  while(x3<=r){
    tmp1[x1++]=a[x3++];}

    for(int i=0;i<r-l+1;i++)
    {
      a[i+l]=tmp1[i];
    }


    }
void mmergesort(int l,int r)//guibingpaixu
{
  int mid=(l+r)/2;
  if (l<r) {
    mergesort(l,mid);
    mergesort(mid+1,r);
    merge(l,r,mid);
  }
  return;
}
int main() {
  int n;
  scanf("%d",&n );
  for (int i=0;i<n;i++)
  scanf("%d%d",&a[i].x,&a[i].y );
  //qsort(a,n,sizeof(light),cmp1);
  mmergesort(0,n-1);
//  sort(a+1,a+n+1,cmp);//THUOJ禁用stl和万能库
  for(int i=0;i<n;i++)
    b[i]=a[i].y;
  mergesort(0,n-1);
  cout<<ans;

  return 0;
}*/
