#include<iostream>
#include <algorithm>
#include <map>
using namespace std;
int n;
int main()
{
    cin >> n;
    map<int ,int > a;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        a[x] +=1;
        cout << a[x];
        if(i<n-1) cout<<' ';
    }
    return 0;
}