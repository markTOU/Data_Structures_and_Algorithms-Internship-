//本题的逻辑结构：线性表
//本题的存储结构：顺序
//解题思路和算法：首先将A字符串重复得AA字符串，如果B能够由A字符串经过循环移位获得
//              那么B一定是AA字符串的子串，也就是只需要经过KMP或者strstr函数查询
//               B是否为子串即可。
//效率:时间复杂度O(n+n)、空间复杂度O(n)：
//测试数据： （1）输入：4
//                    AACD CDAA
//                    ABCDEFG EFGABCD
//                    ABCD ACBD
//                    ABCDEFEG ABCDEE
//               输出：YES
//                    YES
//                    NO
//                    NO
//          见输入数据文件test5.in 输出文件test5.out,防止B字符串比A字符串长但是是AA字符串子串的情况
//#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char s1[200001],s2[100001];
int nex[200001];
const int SZ = 1<<20;  //快速io
struct fastio{
    char inbuf[SZ];
    char outbuf[SZ];
    fastio(){
        setvbuf(stdin,inbuf,_IOFBF,SZ);
        setvbuf(stdout,outbuf,_IOFBF,SZ);
    }
}io;
inline void do_next(int l1,int l2)
{
  int t1=0,t2=-1;
  nex[0]=-1;
  while (t1<l2)
  {
    if (t2==-1||s2[t1]==s2[t2]) {

      nex[++t1]=++t2;
    }
    else
      t2=nex[t2];
  }
}
inline bool KMP(int l1,int l2)
{
  int t1=0,t2=0;
  while (t1<l1) {
    if (t2==-1||s1[t1]==s2[t2]) {
      t1++;t2++;

    } else {
      t2=nex[t2];

    }

    if (t2==l2) {
      return true;

    } else {
      return false;

    }
  }

}
int main(int argc, char const *argv[]) {
  int n,l1,l2;
  scanf("%d\n",&n );
  for (int i = 1; i <=n; i++) {
  scanf("%s %s",s1,s2);
    l1=strlen(s1);
    l2=strlen(s2);
    if(l2!=l1)
    {
      puts("NO");
      continue;
    }
    for(int j=0;j<l1;j++)
      s1[j+l1]=s1[j];
    l1=strlen(s1);
  //    cout<<s1;

  /*  do_next(l1,l2);*/
    if(strstr(s1,s2))
      puts("YES");
    else
      puts("NO");//未开启io加速的前提下速度太慢
  }
  return 0;
}
//使用strstr可以通过评测但是时间相较于直接使用kmp会略慢
//***************下方为学习io加速所使用的程序，非本人编写**********
//直接使用io加速
/*#include "cstdio"
#include "cstring"

using namespace std;
const int maxn = 2e5 + 100;

char s[maxn], t[maxn];
const int SZ = 1<<20;  //快速io
struct fastio{
    char inbuf[SZ];
    char outbuf[SZ];
    fastio(){
        setvbuf(stdin,inbuf,_IOFBF,SZ);
        setvbuf(stdout,outbuf,_IOFBF,SZ);
    }
}io;
int main() {
    while (scanf("%s %s", s, t) != EOF) {
        if (strlen(s) != strlen(t)) {
            printf("NO\n");
            continue;
        }
        int len = strlen(s);
        for (int i = len; i < len * 2; i++) {
            s[i] = s[i - len];
        }
        s[len * 2] = '\0';
        if (strstr(s, t) != NULL)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
*/
