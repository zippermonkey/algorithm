#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef struct site
{
    int x1, y1;
    int x2, y2;
} Site;
int n;
int gezi[101][101];
int main()
{
    cin >> n;
    Site site[n];
    for (int i = 0; i < n; i++)
    {
        cin >> site[i].x1 >> site[i].y1 >> site[i].x2 >> site[i].y2;
        for (int j = site[i].x1; j < site[i].x2; j++)
        {
            for (int k = site[i].y1; k < site[i].y2;k++)
            {
                gezi[j][k]++;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
            if (gezi[i][j] != 0)
                cnt++;
    }
    cout << cnt<<endl;
    return 0;
}