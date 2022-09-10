//本题的逻辑结构：栈
//本题的存储结构：顺序
//解题思路和算法：在每一次完成进栈动作后需要对比栈顶元素是否与目标出栈序列的元素相等，
//              如果相等则进行出栈操作，将该车从栈S中弹出，并继续检查栈顶的第一辆车与
//              出栈序列的第一辆车是否相同，直到栈空或者二者不同位置；如果不相等的话，
//              则将继续进行进栈操作，直至所有车辆均已入栈或者S端中转盲道已经溢出，
//              则表示无法完成目标序列的中转工作。
//效率:时间复杂度O(n)、空间复杂度O(n)：
//测试数据： （1）输入：5 2
//                    1 2 3 5 4
//               输出：push
//                    pop
//                    push
//                    pop
//                    push
//                    pop
//                    push
//                    push
//                    pop
//                    pop
//          见输入数据文件test4.in 输出文件test4.out
#include<bits/stdc++.h>
using namespace std;
stack <int> s1;
int n,m,a[1600001],d[3200001],key=0,ss=1,lo=0;

int main()
{
  //cout<<1;
  scanf("%d%d",&n,&m);

  for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
  int j=1,k=1;//j序号，k初始序列
  for (int i=1;i<=2*n;i++)
  { if (s1.size()>m)
    {
      lo=1;
      break;
    }
    if(a[j]>=k)
    {
      s1.push(k++);
      d[i]=1;
    }
    else
    {
    if(s1.top()==a[j]){
    d[i]=0;
    s1.pop();
    j++;
    }
    else {
      lo=1;
      break;
    }

}
}
  if (lo) cout<<"No";
  else for(int i=1;i<=2*n;i++)
  {
    if (d[i]) {puts("push");  }
    else puts("pop");
  }
  return 0;
}
