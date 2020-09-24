#include <iostream>
using namespace std;
int n;
int main()
{
    cin >>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (abs(a[i + 1] - a[i]) > max)
            max = abs(a[i + 1] - a[i]);
    }
    cout << max<<endl;

    return 0;
}