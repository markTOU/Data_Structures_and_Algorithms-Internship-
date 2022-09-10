
 //本题的逻辑结构：数组（哈希表）
 //本题的存储结构：顺序
 //解题思路和算法：从原始状态开始通过三种操作的反向给出一切可以达到的状态，
 //               通过BFS打表进行搜索。首先编写三种操作对应的程序，
 //               由于题目可以进行类似的打表操作，所以在程序最开始直接利用目标结果
 //               反向搜索能够到达的状态，由于三种状态时可逆的，
 //               所以如果能够从目标状态搜索到输入状态那么则一定可以从输入状态
 //               经过若干次修改后到达目标状态。通过map状态数组记录从目标状态转变
 //               为起始状态的步数，最终经过康托展开直接从map数组中输出最终结果即可
//                记录每个状态的访问标记和需要达到的最小步数，假设步数为-1即为未访问过。
 //对于逆康托要保存康托的结果，大大提高效率然后利用康托展开的数值作为哈希值。
 //效率:时间复杂度O(m)、空间复杂度O(n)：
 //测试数据： （1）输入：2
//                     1 2 3 4 5 6 7 8
//                      8 6 3 5 4 2 7 1
 //               输出：0
 //										2
 //          见输入数据文件test10.in 输出文件test10.out
 #include<iostream>
 #include<cstring>
 #include<cstdio>
 using namespace std;
 char ss[10]="12348765";
 #define MAXN 40321
 int sys[MAXN];    //状态图
 int fac[8] = { 1,1,2,6,24,120,720,5040};//阶乘打表
 struct Board{
     int fa;        //上一状态
     int value;    //Hash值
     char s[9];
     void Cont()
     {
         int num = 0;
         for (int i = 0; i < 8; i++)
         {
             int tmp = 0;
             for (int j = i + 1; j < 8; j++)
             {
                 if (this->s[j] < this->s[i]) tmp++;
             }
             num += tmp*fac[7 - i];
         }
         this->value = num;
     }
 }m[2*MAXN],t;


 void chushihua(char s[9])
 {
     int r = 0;
     int w = 1;
     strcpy(m[0].s, s);
     m[0].Cont();
     while (r < w) {
         if (sys[m[r].value])
         {
             r++;
             continue;
         }
         sys[m[r].value] = sys[m[m[r].fa].value] + 1;
         /*由于是反向搜索，因此将逆向操作即可*/
         // 交换行
         for (int i = 0; i < 8; i++)
             m[w].s[(i + 4) % 8] = m[r].s[i];
         m[w].Cont();
         if (!sys[m[w].value]) {
             m[w].fa = r;
             w++;
         }
         // 循环左移
         for (int i = 0; i < 4; i++)
             m[w].s[(i + 3) % 4] = m[r].s[i];
         for (int i = 4; i < 8; i++)
             m[w].s[(i + 3) % 4 + 4] = m[r].s[i];
         m[w].Cont();
         if (!sys[m[w].value]) {
             m[w].fa = r;
             w++;
         }
         // 中心逆旋转
         strcpy(m[w].s, m[r].s);
         m[w].s[5] = m[r].s[1]; m[w].s[1] = m[r].s[2];
         m[w].s[2] = m[r].s[6]; m[w].s[6] = m[r].s[5];
         m[w].Cont();
         if (!sys[m[w].value]) {
             m[w].fa = r;
             w++;
         }
         r++;
     }
 }
 int main()
 {

     chushihua(ss);//初始化
     int n;
     scanf("%d", &n);
     for(int k=1;k<=n;k++)
     {
         int temp;
         for (int i = 0; i < 4; i++)
         {
             scanf("%d", &temp);
             t.s[i] = temp+'0';
         }
         for (int i = 4; i < 8; i++)
         {
             scanf("%d", &temp);
             t.s[(8 - i) + 3] = temp + '0';
         }
         t.Cont();//康托展开
         printf("%d\n", sys[t.value] - 1);
     }
     return 0;
 }
//*************下程序为网络参考程序用于学习借鉴***********
/*#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

static const int MAX = 40321;

static const int factorial[8] = {1, 1, 2, 6, 24, 120, 720, 5040};

struct stateInfo
{
    bool valid = false;
    int A[8];
    int step = -1;
};

static stateInfo data[MAX];

struct Queue
{
    int data[MAX];
    int front = 0, end = 0;
    int pop()
    {
        int temp = front;
        front = (front + 1) % MAX;
        return data[temp];
    }
    void push(int i)
    {
        data[end] = i;
        end = (end + 1) % MAX;
        return;
    }
    bool empty() { return front == end; }
};

template <typename T>
void print(T A[], int n)
{
    for (int i = 0; i != n; ++i)
        cout << A[i] << ' ';
    putchar('\n');
    return;
}

void check_enq(int w, int v, Queue &Q)
{
    if (data[w].step == -1)
    {
        data[w].step = data[v].step + 1;
        Q.push(w);
    }
    return;
}

int contor(int A[], int n)
{
    int res = 0;
    for (int i = 0; i != n; ++i)
    {
        int smaller = 0;
        for (int j = i + 1; j != n; ++j)
        {
            if (A[j] < A[i]) ++smaller;
        }
        res += smaller * factorial[n-i-1];
    }
    return res;
}

void re_contor(int stateNo, int n)
{
    int temp;
    bool used[n];
    memset(used, false, sizeof(used));
    int tempStateNo = stateNo;
    for (int i = 0; i != n - 1; ++i)
    {
        temp = tempStateNo / factorial[n-i-1];
        int rank = 0;
        for (int j = 1; j != n + 1; ++j)
        {
            if (!used[j-1])
                ++rank;
            if (rank == temp + 1)
            {
                data[stateNo].A[i] = j;
                used[j-1] = true;
                break;
            }
        }
        tempStateNo %= factorial[n-i-1];
    }
    for (int i = 0; i != n; ++i)
    {
        if (!used[i])
        {
            data[stateNo].A[n-1] = i + 1;
            break;
        }
    }
    data[stateNo].valid = true;
    return;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    return;
}

// 上下互换
int op1(int A_o[])
{
    int A[8];
    memcpy(A, A_o, sizeof(A));
    swap(A[0], A[7]);
    swap(A[1], A[6]);
    swap(A[2], A[5]);
    swap(A[3], A[4]);
    int res = contor(A, 8);
    memcpy(data[res].A, A, sizeof(A));
    data[res].valid = true;
    return res;
}

// 循环左移
int op2(int A_o[])
{
    int A[8];
    memcpy(A, A_o, sizeof(A));
    int temp1 = A[0], temp2 = A[7];
    A[0] = A[1];
    A[1] = A[2];
    A[2] = A[3];
    A[7] = A[6];
    A[6] = A[5];
    A[5] = A[4];
    A[3] = temp1;
    A[4] = temp2;
    int res = contor(A, 8);
    memcpy(data[res].A, A, sizeof(A));
    data[res].valid = true;
    return res;
}

// 逆时针旋转
int op3(int A_o[])
{
    int A[8];
    memcpy(A, A_o, sizeof(A));
    int temp = A[1];
    A[1] = A[2];
    A[2] = A[5];
    A[5] = A[6];
    A[6] = temp;
    int res = contor(A, 8);
    memcpy(data[res].A, A, sizeof(A));
    data[res].valid = true;
    return res;
}

void BFS()
{
    Queue Q;
    Q.push(0);
    data[0].step = 0;
    while (!Q.empty())
    {
        int v = Q.pop();
        if (!data[v].valid) re_contor(v, 8);
        // printf("reached stateNo = %d: ", v);
        // print(data[v].A, 8);
        int w1 = op1(data[v].A), w2 = op2(data[v].A), w3 = op3(data[v].A);
        check_enq(w1, v, Q);
        check_enq(w2, v, Q);
        check_enq(w3, v, Q);
    }
    return;
}

int main(int argc, char const *argv[])
{
    BFS();
    int N;
    scanf("%d", &N);
    for (int i = 0; i != N; ++i)
    {
        int A[8];
        for (int j = 0; j != 8; ++j) scanf("%d", &A[j]);
        int stateNo = contor(A, 8);
        // printf("stateNo = %d for A: \n", stateNo);
        // print(A, 8);
        printf("%d\n", data[stateNo].step);
    }
    return 0;
}*/
