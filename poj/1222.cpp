#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char originLight[5];
char Lights[5];
char result[5];

void SetBit(char &c, int j, int s)
{
    if (s)
        c |= (1 << j);
    else
        c &= ~(1 << j);
}
void FlipBit(char &c, int j)
{
    // 反转c的第j位
    c ^= (1 << j);
}
int GetBit(int c, int i)
{
    return (c >> i) & 1;
}
void OutputResult(int t, char result[])
{
    cout << "PUZZLE #" << t << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            int s = GetBit(result[i], j);
            cout << s;
            if (j < 5)
                cout << ' ';
        }
        cout << endl;
    }
}
int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        // 读取数据
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 6; ++j)
            {
                int s;
                cin >> s;
                SetBit(originLight[i], j, s);
            }
        }
        // 读取完成
        // 枚举第一行的所用状态 使用k表示
        for (int k = 0; k < 64; k++)
        {
            int Switch = k;
            // 制作副本
            memcpy(Lights, originLight, sizeof(Lights));
            for (int i = 0; i < 5; ++i)
            {
                result[i] = Switch;
                for (int j = 0; j < 6; ++j)
                {
                    if (GetBit(Switch, j))
                    {
                        if (j > 0)
                            FlipBit(Lights[i], j - 1);
                        FlipBit(Lights[i], j);
                        if (j < 5)
                            FlipBit(Lights[i], j + 1);
                    }
                }
                if (i < 4)
                    Lights[i + 1] ^= Switch;
                Switch = Lights[i];
            }
            if (Lights[4] == 0)
            {
                OutputResult(t, result);
                break;
            }
        }
    }
    return 0;
}