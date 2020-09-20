#include <stdio.h>
#include <string.h>
int isFake(char c, int light);
char left[3][7];
char right[3][7];
char result[3][7];

int main()
{

    int t;
    scanf("%d", &t);
    while (t--)
    {
        for (int i = 0; i < 3; i++)
        {
            scanf("%s %s %s", left[i], right[i], result[i]);
        }
        for (char c = 'A'; c <= 'L'; c++)
        {
            if (isFake(c, 1))
            {

                printf("%c is the counterfeit coin and it is light.\n",c);
                break;
            }
            else if (isFake(c, 0))
            {
                printf("%c is the counterfeit coin and it is heavy.\n",c);
                break;
            }
        }
    }
    return 0;
}
int isFake(char c, int light)
{
    char *pLeft, *pRight;
    for (int i = 0; i < 3; i++)
    {
        if (light)
        {
            pLeft = left[i];
            pRight = right[i];
        }
        else
        {
            pLeft = right[i];
            pRight = left[i];
        }
        switch (result[i][0])
        {
        case 'e':
            if (strchr(pLeft, c) || strchr(pRight, c))
                return 0;
            break;
        case 'u':
            if (strchr(pRight, c) == NULL)
                return 0;
            break;
        case 'd':
            if (strchr(pLeft, c) == NULL)
                return 0;
            break;
        }
    }
    return 1;
}
