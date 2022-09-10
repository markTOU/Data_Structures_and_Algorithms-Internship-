/*
若遍历过程中第一个点无邻接点，那么可能会直接退出，不进行后续判断
如果是一块一块的该如何处理？

*/
//本题的逻辑结构：队列
//本题的存储结构：顺序
//解题思路和算法：利用STL中的Queue，代替BFS中传统的队列，在选取点
//              进行入队操作后对于该点进行染色操作，观察是否能够进行正常的染
//              色过程，如果染色成功则继续下一步，直到完成整个地图的遍历或者
//              是中途退出，从而得到最终的结果。
//效率:时间复杂度O(n^2)、空间复杂度O(n^2)：
//测试数据： （1）输入：4 3
//										1 2
//										1 3
//										2 4
//               输出：1
//            (2)输入：5 3//此数据存在孤立点，可能会有部分程序遇见孤立点直接退出
//                    2 3
//                    3 4
//                    2 4
//              输出：-1
//          见输入数据文件test7.in 输出文件test7.out
//#include <bits/stdc++.h>
#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;
const int Maxs=10001;
int ma[Maxs][Maxs]={};
int a[Maxs]={};
queue <int> q;
bool check(int n)
{
  for(int i=2;i<=n;i++)
  {if(a[i]==0){
    q.push(i);return true;
  }}
  return false;
}
bool BFS(int n)
{
  q.push(1);
  int v;
  do {
    /* code */

  while(!q.empty())
  {
    v=q.front();
    q.pop();
    a[v]=1;
    for(int i=1;i<=n;i++)
    {
      if(ma[v][i]&&a[v]!=a[i])
      {
        if (a[i]!=3-a[v]) {
          a[i]=3-a[v];
          q.push(i);
        } else {
          return false;
        }
      }
    }
      }
  } while(check(n));
  return true;
}
int main(int argc, char const *argv[]) {
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++)
  {int x1,x2;
    scanf("%d%d",&x1,&x2 );
    ma[x1][x2]=ma[x2][x1]=1;
}
  if (BFS(n)) {
    puts("1");
  } else {
    puts("-1");
  }
  return 0;
}

//*******下方为网上寻找的对拍程序非本人所作**************
/*
#include<iostream>
#include<cstring>
#include<cstdio>
//请勿搬抄，尤其中国石油大学的学生，一定要自己实现，避免查重，加油，有不理解的地方可以与我交流
using namespace std;
#define MAX 10010
int n, m;        //小镇数-相距20Km内小镇对数
int queue[MAX],head,tail;    //模拟队列-队首-队尾
int cover;    //Broadcast放置数量


struct Node
{
    int num;
    Node *next;
    Node()
    {
        next = NULL;
    }
    Node(int n, Node *k) :num(n), next(k) {}
};

struct Town
{
    int state;
    Node *t;
    Town()
    {
        state = 0;
        t = NULL;
    }
    void insert(int num);
} town[MAX];

void Town::insert(int num)
{
    if (this->t == NULL)
        this->t = new Node(num,NULL);
    else
        this->t = new Node(num,this->t);
}

bool BFS(int x)
{
    queue[tail++] = x;
    town[x].state = 1;
    cover++;
    while (head < tail)
    {
        Town cur = town[queue[head]];
        Node *tmp = cur.t;
        while (tmp != NULL)
        {
            if (!town[tmp->num].state)
            {
                town[tmp->num].state = -cur.state;
                cover++;
                queue[tail++] = tmp->num;
            }
            else if (town[tmp->num].state == cur.state)
                return false;
            tmp = tmp->next;
        }
        head++;
    }
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        town[x].insert(y);
        town[y].insert(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (town[i].state==0)
        {
            if (BFS(i) == false)
            {
                printf("-1\n");
                return 0;
            }
            if (cover == n)
            {
                printf("1\n");
                return 0;
            }
        }
    }
    return 0;
}
*/
