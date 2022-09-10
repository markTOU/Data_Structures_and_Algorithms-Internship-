//本题的逻辑结构：哈希表
//本题的存储结构：链式
//解题思路和算法：通过深度优先搜素不断的寻找，哪个传染源拥有最长的传染链。
//              通过对于输入数据不同的感染者进行DFS搜索，返回以该感染者
//              为源头的最长的传染链的人数。如果该人数大于现有最长传染链
//              的人数，那么将最长传染链的长度进行更新，并且最长传染链的
//              源头也随之进行更新。并且在DFS搜索过程中对于传染链进行记录，
//              最终分别输出最长传染链的长度和最长传染链传染的人员序列。
//效率:时间复杂度O(n)、空间复杂度O(n)：
//测试数据： （1）输入：10
//										brioche
//										camembert
//										cappelletti
//										savarin
//										cheddar
//										cappelletti
//										tortellni
//										croissant
//										brioche
//										mapotoufu
//               输出：cappelletti
//										brioche
//          见输入数据文件test11.in 输出文件test11.out
#include<bits/stdc++.h>
using namespace std;
struct tong {
	char* m;
	bool re;
	tong* next;
}b[600010];
char s[41];
void push(int addr, char* s) {
	tong* t = new tong;
	t->m = s; t->re = false;
	t->next = b[addr].next;
	b[addr].next = t;
}
int Hash(char* s) {
	int sum = 0, l = strlen(s);
	for (int i = 0; i<l; i++)
		sum += (i + 1)*(s[i] - 'a'+1);
	return sum%600010;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%s", s);
		int address = Hash(s);
		tong* p = b[address].next;
		while (p)
	{	if (!strcmp(p->m, s)) {
			if (!p->re) {
				p->re = 1;
				puts(s);
			}break;
		}
		else p = p->next;
	}
		if (!p)push(address, s);
	}
	return 0;
}
//*********下方程序为（参考资料）网上搜索所得用于对拍，非本人所写**********
/*#include<cstdio>
#include<cstring>
using namespace std;
struct Slot {//每个桶对应的槽位，存储冲突，即映射到同一地址且不重复的字符串（实则字符指针）
	char* data;//数据项，存储字符指针
	bool repeat;//标志，判别字符串是否重复
	Slot* next;//后继
}buckets[600010];//桶数组（散列表）
char name[600010][41];//字符二维数组（必须开头定义），存储输入字符串，注意二维长度为40+1个结束符=41
void Insert(int addr, char* s) {//在相应地址中插入冲突的字符串（实则字符指针）
	Slot* t = new Slot;
	t->data = s; t->repeat = false;//初始化当前字符串从未重复
	t->next = buckets[addr].next;//链表头插法
	buckets[addr].next = t;
}
int Hash(char* s) {//散列码转换（字符串转数字）
	int sum = 0, l = strlen(s);
	for (int i = 0; i<l; i++)//求和
		sum += (i + 1)*(s[i] - 'a'+1);
	return sum%600010;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%s", name[i]);
		int address = Hash(name[i]);//获得映射到的地址
		Slot* p = buckets[address].next;//从当前桶的第1个槽位开始
		while (p)//遍历所有槽位（冲突的单元）
		if (!strcmp(p->data, name[i])) {//若当前槽位的字符串重复
			if (!p->repeat) {//检查当前槽位的字符串是否重复
				p->repeat = true;//若未重复，则标志为已重复过
				puts(name[i]);//输出重复字符串
			}break;//若重复过，则忽略，无论是否重复过，皆终止遍历
		}
		else p = p->next;
		if (!p)Insert(address, name[i]);//若当前槽位空，则进行插入
	}
	return 0;
}*/
