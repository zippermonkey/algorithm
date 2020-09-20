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
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            scanf("%d", &v);
            SetBit(&panju[i], j, v);
        }
    }
    for(int i = 16;i<=19;i++)
    {
        panju[i] = ~0;
    }
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
    int k = 19;
    for (int i = 19; i >= 3; i--, k--)
    {
        if (panju[i] & fangkuai[3])
            continue;
        if (panju[i - 1] & fangkuai[2])
            continue;
        if (panju[i - 2] & fangkuai[1])
            continue;
        if (panju[i - 3] & fangkuai[0])
            continue;
        else
        {
            break;
        }
    }
    panju[k] |= fangkuai[3];
    panju[k - 1] |= fangkuai[2];
    panju[k - 2] |= fangkuai[1];
    panju[k - 3] |= fangkuai[0];
    OutputResult(panju);
    return 0;
}