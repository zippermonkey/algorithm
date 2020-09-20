#include <stdio.h>
int panju[19];
int fangkuai[4];
int n;
int backup[4];
void SetBit(int *a, int i, int v)
{
    if (v)
        *a |= (1 << i);
    else
        *a &= ~(1 << i);
}
int GetBit(int a, int i)
{
    return (a >> i) & 1;
}
void OutputResult(int result[])
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int s = GetBit(result[i], j);
            printf("%d", s);
            if (j < 9)
                printf(" ");
        }
        printf("\n");
    }
}
int main()
{
    int v;
    // 读取数据
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            scanf("%d", &v);
            SetBit(&panju[i], j, v);
        }
    }
    // 添加下面四行全1
    for (int i = 15; i < 19; i++)
    {
        panju[i] = ~0;
    }
    // 读取掉落的方块
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &v);
            SetBit(&fangkuai[i], j, v);
        }
    }

    scanf("%d", &n);
    // 将 fangkuai 移位  左 n-1位
    for (int i = 0; i < 4; i++)
    {
        fangkuai[i] <<= (n - 1);
    }

    int k = 0;    // 记录当前匹配的盘局的第一行 也比配方块的第一行  从0到14
    int flag = 1; // 表示在当前位置可行
    for (k = 0; k <= 14; k++)
    {
        if ((fangkuai[0] & panju[k]))
            // 不通过
            flag = 0;
        if (fangkuai[1] & panju[k + 1])
            flag = 0;
        if (fangkuai[2] & panju[k + 2])
            flag = 0;
        if (fangkuai[3] & panju[k + 3])
            flag = 0;

        if (flag == 0)
            break;
    }
    k = k - 1;
    panju[k] |= fangkuai[0];
    panju[k + 1] |= fangkuai[1];
    panju[k + 2] |= fangkuai[2];
    panju[k + 3] |= fangkuai[3];
    OutputResult(panju);
    return 0;
}