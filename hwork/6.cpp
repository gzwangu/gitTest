#include <iostream>
using namespace std;
 
#define N 16

void buildTable(int a[][N + 1], int n){ //N为队伍个数
    int i, j, t, temp;
    // 前4个格子已经填好，所以不必循环到t==2。
    // 迭代处理，依次处理2^2, …, 2^k个选手比赛日程
    for (t = N; t >= 4; t = t / 2){ 
        temp = n;                     
        n = n * 2;
        //填左下角元素
        for (i = temp + 1; i <= n; i++)
            for (j = 1; j <= temp; j++)
                a[i][j] = a[i - temp][j] + temp;
        //填右上角元素
        for (i = 1; i <= temp; i++)
            for (j = temp + 1; j <= n; j++)
                a[i][j] = a[i + temp][(j + temp) % n];
        //填右下角元素
        for (i = temp + 1; i <= n; i++)
            for (j = temp + 1; j <= n; j++)
                a[i][j] = a[i - temp][j - temp];
    }
}
 
int main()
{
    cout << N << "名运动员比赛日程安排表" << endl << endl;
    int n, i, j, a[N + 1][N + 1] = {0}; // n=2^k(k≥1)个选手参加比赛，二维数组a表示日程安排，数组下标从1开始
    n = 2;                              //先将左上角四个数写出来
    a[1][1] = 1;
    a[1][2] = 2;
    a[2][1] = 2;
    a[2][2] = 1;
    buildTable(a, n);
    cout << "选手" << "\t";
    for (i = 1; i <= N - 1; i++)
    {
        cout << "第" << i << "天" << "\t";
    }
    cout << endl;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }

    return 0;
}