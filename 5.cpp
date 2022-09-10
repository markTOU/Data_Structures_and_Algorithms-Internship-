//本题的逻辑结构：树
//本题的存储结构：顺序
//解题思路和算法：在递归过程中最重要的就是确定左右子树的序列，
//              如果对于某个序列的左子树根节点的序号等于右子树根节点的序号，
//              那么其子树一定为单独元素，可以返回，否则的话，利用后续节点的
//              二叉树后序序列寻找到先序序列的第一个节点，从而再不断地递归查
//              询直到找到最终的节点。
//效率:时间复杂度O(n)、空间复杂度O(n)：
//测试数据： （1）输入：5
//                    1 2 4 5 3
//                    4 5 2 3 1
//               输出：4 2 5 1 3
//难以构造数据，所以使用THUoj进行评测
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int pre[4000001];//先序
int post[4000001];//中序
int in[4000001];//后续

void rebuild(int pre_l, int pre_r, int post_l, int post_r){
  //避免多次使用链表构建麻烦，使用数组模拟不必建树
    if(pre_r == pre_l )
          return;
    int i=post_l, j=0;
    for(; post[i] != pre[pre_l +1]; )
    {
      ++i;++j;
    };

    in[i+1] = pre[pre_l];
    int k=post_r;
    for(; k > i + 1; --k)
        post[k] = post[k-1];
    if(k != post_r)
        post[k] = 0;

    rebuild(pre_l+1, pre_l+1+j, post_l, i);
    rebuild(pre_l+1+j+1, pre_r, i+2, post_r);

    return;
}
int main(){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &pre[i]);
        for(int i = 0; i < n; ++i)
            scanf("%d", &post[i]);
        rebuild(0, n-1, 0, n-1);
        for(int i = 0; i < n; ++i){
            in[i] += post[i];
            printf("%d ", in[i]);
        }
        return 0;
}
