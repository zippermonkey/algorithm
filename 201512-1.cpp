#include<iostream>
using namespace std;
int main()
{
    char n[11];
    cin>>n;
    int c = 0;
    int result = 0;
    c = n[0];
    int i = 0;
    while(c)
    {
        result+= c-'0';
        c = n[++i];
    }
    cout << result<<endl;;
    return 0;
}