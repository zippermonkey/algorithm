#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    int count = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if ((value[i] - value[i - 1]) * ((value[i] - value[i + 1])) > 0)
            count++;
    }
    cout << count << endl;
    return 0;
}