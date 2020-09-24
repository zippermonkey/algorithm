#include <iostream>
#include <algorithm>
using namespace std;
int n;

int main()
{
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i + 1] - a[i] == 1)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}