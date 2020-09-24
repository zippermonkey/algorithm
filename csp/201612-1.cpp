#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int n;
int main()
{
    cin >> n;
    map<int, int> seq;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        seq[a[i]] += 1;
    }
    sort(a,a+n);
    int mid = a[n / 2];
    map<int, int>::iterator iter;
    int Left = 0, Right = 0;
    for (iter = seq.begin(); iter != seq.end(); iter++)
    {
        if (iter->first < mid)
            Left += iter->second;
        else if (iter->first > mid)
            Right += iter->second;
    }
    if (Left == Right)
        cout << mid << endl;
    else
        cout << -1 << endl;
    return 0;
}