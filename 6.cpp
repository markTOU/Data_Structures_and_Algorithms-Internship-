//本题的逻辑结构：线性表
//本题的存储结构：链式
//解题思路和算法：先将所有入度为0的结点压入栈中并记录已经访问，
//							并且修改邻接点的入度（入度-1），对于栈中每一个入度为0的结点，
//							我们都访问其邻接点并记录，并且利用动态规划的思路，不断的更新
//							到每个入度为0的顶点的邻居的最大路径长度，并额外添加了语句以更新
//							到每个邻居的最大路径长度和记录图的最大路径长度。在更新入度后，若邻
//							接点的入度为0，则压入堆栈并及时记录，直到栈空为止
//效率:时间复杂度O(n)、空间复杂度O(n)：
//测试数据： （1）输入：4 3
//										1 4
//										2 4
//										4 3
//               输出：3
//          见输入数据文件test6.in 输出文件test6.out
#include<stdio.h>
#include<iostream>
using namespace std;
//边的数量太多只能用邻接表存储
struct ENode{
	int dest;//vsub//destination
	ENode *next;//下条边succ
};
struct VNode{
	int in,len;//入度以及最大路径
	ENode *fstEdge;
};
VNode V[1000001];ENode *t;
int s[1000001],top=0,maxlen=0;
int n,m;
void TopSort(){
	for(int k=1;k<=n;k++)if(!V[k].in)s[++top]=k;
	while(top){
		int v=s[top--];
		for(ENode *p=V[v].fstEdge;p;p=p->next){
		//策略：动态规划-不断的更新到每个入度为0的顶点的邻居的最大路径长度
//相对于拓扑排序，额外添加了下述2句以更新到每个邻居的最大路径长度和记录图的最大路径长度
			V[p->dest].len=max(V[v].len+1,V[p->dest].len);
			maxlen=max(V[p->dest].len,maxlen);
			if(!(--V[p->dest].in))s[++top]=p->dest;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	int x1,x2;
	for(int k=0;k<m;k++){
		scanf("%d%d",&x1,&x2);
		t=new ENode;t->dest=x2;V[x2].in++;
		t->next=V[x1].fstEdge;V[x1].fstEdge=t;
	}
	TopSort();
	cout<<maxlen+1;
	return 0;
}
