//本题的逻辑结构：DFS搜索递归（栈）
//本题的存储结构：顺序+链式
//解题思路和算法：通过深度优先搜素不断的寻找，哪个传染源拥有最长的传染链。
//              通过对于输入数据不同的感染者进行DFS搜索，返回以该感染者
//              为源头的最长的传染链的人数。如果该人数大于现有最长传染链
//              的人数，那么将最长传染链的长度进行更新，并且最长传染链的
//              源头也随之进行更新。并且在DFS搜索过程中对于传染链进行记录，
//              最终分别输出最长传染链的长度和最长传染链传染的人员序列。
//效率:时间复杂度O(n^2)、空间复杂度O(n)：
//测试数据： （1）输入：10
//                    0
//                    3 3 4 7
//                    2 1 9
//                    1 6
//                    1 5
//                     0
//                    0
//                    0
//                    2 6 0
//                    1 8
//               输出：4
//                    2 1 3 6
//          数据较难构建所以未构建数据文件
#include<bits/stdc++.h>
using namespace std;

vector<int> v[100010];

int step[10010];
int n[10010];//对于某个元素其能够传染的最长传染序列
int ans=0;
int dfs(int begin)
{
  if(v[begin].size()==0)
        return 1;

    int num=0;
    for(int i=0;i<v[begin].size();i++)
    {
        if(step[v[begin][i]]>num)
         {
            num=step[v[begin][i]]+1;
            n[begin]=v[begin][i];
        }
        else
        {
            int temp=dfs(v[begin][i])+1;
            if(temp>num)
            {
                num=temp;
                n[begin]=v[begin][i];
            }
        }
    }
    step[begin]=num;
    return num;
}
int main()
{
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int num;
        cin>>num;
        for(int j=0;j<num;j++)
        {
            int temp;
            cin>>temp;
            v[i].push_back(temp);
        }
    }
    int b=0;
    for(int i=0;i<m;i++)
    { int temp;
       temp=dfs(i);
        if(temp>ans)
        {
            b=i;//起始点
            ans=temp;
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<ans-1;i++)
    {
        cout<<b<<" ";
        b=n[b];
    }
    cout<<b;
}
