#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a = 0, b = 0, c = 0, d = 0;
    int i = 1;
    while (n != 0)
    {
        if (i % 7 == 0 || contain7(i)) // 7的倍数
        {
            if (i % 4 == 1)
                a++;
            else if (i % 4 == 2)
                b++;
            else if (i % 4 == 3)
                c++;
            else if (i % 4 == 0)
                d++;
        }
        else
        {
            n--;
        }
        i++;
    }
    printf("%d\n%d\n%d\n%d\n", a, b, c, d);
    return 0;
}
int contain7(int x)
{
    int digit = x % 10;
    if (digit == 7)
        return 1;
    x = x / 10;
    digit = x % 10;
    if (digit == 7)
        return 1;
    x = x / 10;
    digit = x % 10;
    if (digit == 7)
        return 1;
    return 0;
}