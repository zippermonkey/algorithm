#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    int *si = (int*)malloc(sizeof(int)*n);
    int times[10001] ={0};
    for(int i = 0;i<n;i++)
    {
        scanf("%d",si+i);
        times[*(si+i)]++;
    }
    int max = 0;
    int result = 0;
    for(int i = 1;i<=10000;i++)
    {
        if(times[i]>max)
        {
            max = times[i];
            result = i;
        }
    }
    printf("%d\n",result);
    return 0;
}