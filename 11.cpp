//本题的逻辑结构：优先队列
//本题的存储结构：顺序+链式
//解题思路和算法：首先，对于自定义的排序函数进行编写，又因为在此题要求的顺
//              序中均以小号优先，所以我们直接对于存储任务的结构体，进行重载<运算符
//              即可。在完成优先队列的构建后，将题目中提供的所有任务均压入优先队
//              列之中。通过优先队列弹出在队列中的优先级最高的任务。在每次执行任
//              务后将已经执行的任务从队列中弹出，并且使他的优先级乘以2，随后再判
//              断优先级能否构成比2^32大的条件，如果优先级小于2^32，那么就再次将该任
//              务压入优先队列中。直至优先队列中的所有均已执行完毕，或者完成的
//              任务数量已经满足题目要求后，算法结束运行。
//效率:时间复杂度O(n)、空间复杂度O(n)：
//测试数据： （1）输入：3 3
//                    1 hello
//                    2 world
//                    10 test
//               输出：hello
//                     hello
//                    world
//          见输入数据文件test11.in 输出文件tes11.out

#include<bits/stdc++.h>
#include<queue>
using namespace std;
const int SZ = 1<<20;  //快速io
struct fastio{
    char inbuf[SZ];
    char outbuf[SZ];
    fastio(){
        setvbuf(stdin,inbuf,_IOFBF,SZ);
        setvbuf(stdout,outbuf,_IOFBF,SZ);
    }
}io;
struct task{
  int level;
  char s[10];
  bool operator<(const task& x)const
  {
    return ((level>x.level)||(level==x.level&&strcmp(s,x.s)>0));
  }
}task;

priority_queue<struct task> pq;
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
      scanf("%d%s",&task.level,task.s);
      pq.push(task);
    }

    while(!pq.empty()&&m--)
    {
      task=pq.top();
      pq.pop();
      printf("%s\n",task.s );
      task.level*=2;
      if(task.level<4294967296)pq.push(task);
    }

  return 0;
}
