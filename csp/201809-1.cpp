#include <iostream>
using namespace std;
int n;

int main()
{
    cin >> n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            a[i] = (b[i] + b[i + 1]) / 2;
        else if (i == n - 1)
            a[i] = (b[i] + b[i - 1]) / 2;
        else
            a[i] = (b[i - 1] + b[i] + b[i + 1]) / 3;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if (i < n - 1)
            cout << ' ';
    }
    return 0;
}