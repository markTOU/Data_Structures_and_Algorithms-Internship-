
//最终版本
//本题的逻辑结构：线性表
//本题的存储结构：顺序
//解题思路和算法：由于使用数组，在插入位置利用两个“指针”进行前后搜寻相同的珠子，
//              在搜寻完成后利用两“指针”位置之差从而确定中间有多少珠子，若珠子
//              数目大于3则进行消除，另外对于首次消除后是否还能进行消除，设立
//              一个布尔变量来标志是否还能够进行消除从而达到一直消除到无珠子可消的地步。
//效率:时间复杂度O(mn)、空间复杂度O(n)：
//测试数据： （1）输入：ACCBA       输出：ABCCBA
//                    5                 AABCCBA
//                    1 B               AABBCCBA
//                    0 A               -
//                    2 B               A
//                    4 C
//                    0 A
//
//          （2）输入：                  输出：
//                    4
//                    0 A               A
//                    1 B               AB
//                    0 A               AAB
//                    2 A               B
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char s[20001],temp[20001];
int n;
//string s1;
int  main() {
//  cin.get(s，100);
  scanf("%[^\n]",s);//防止一开始的空字符串
//gets(s);//可能出现一开始便是空串的情况
  scanf("%d",&n );
  for(int x=1;x<=n;x++)
  {int pos,len;
    char c;
    scanf("%d %c",&pos,&c);
    strcpy(temp,s+pos);
    s[pos]=c;
    strcpy(s+pos+1,temp);
//    cout<<s;//测试是否连接准确
    len=strlen(s);
    bool book=1;//是否还存在可消除弹珠的可能性
    int pos1,pos2;//方便计算是否消除
    while(book&&len)
    { char c2=s[pos];
      pos1=pos2=pos;
      while(pos1>0&&s[pos1]==c2)pos1--;
      if(pos1||s[pos1]!=c2)pos1++;
      while(pos2<len&&s[pos2]==c2)pos2++;
      if(pos2-pos1>=3)
      {
        strcpy(temp,s+pos2);
        strcpy(s+pos1,temp);
        len-=(pos2-pos1);
        pos=pos1;
        book=1;
        continue;
      }
      else
    {book=0;
      continue;}
    }
    if(len){
      puts(s);
    }
    else
    puts("-");
  }
    return 0;
}
