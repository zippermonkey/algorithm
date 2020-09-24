#include <iostream>
using namespace std;
int a[2000][2000];
int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[j][i];
            if (j < m - 1)
                cout << ' ';
        }
        cout << endl;
    }
    return 0;
}