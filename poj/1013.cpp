#include <iostream>
#include <cstring>
bool isFake(char c, bool light);
char Left[3][7];
char Right[3][7];
char result[3][7];
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 3; i++)
        {
            cin >> Left[i] >> Right[i] >> result[i];
        }
        for (char c = 'A'; c <= 'L'; c++)
        {
            if (isFake(c, true))
            {
                cout << c << " is the counterfeit coin and it is light." << endl;
                break;
            }
            else if (isFake(c, false))
            {
                cout << c << " is the counterfeit coin and it is heavy." << endl;
                break;
            }
        }
    }
    return 0;
}

bool isFake(char c, bool light)
{
    char *pLeft, *pRight;
    for (int i = 0; i < 3; i++)
    {
        if (light)
        {
            pLeft = Left[i];
            pRight = Right[i];
        }
        else
        {
            pLeft = Right[i];
            pRight = Left[i];
        }
        switch (result[i][0])
        {
        case 'e':
            if (strchr(pLeft, c) || strchr(pRight, c))
                return false;
            break;
        case 'u':
            if (strchr(pRight, c) == NULL)
                return false;
            break;
        case 'd':
            if (strchr(pLeft, c) == NULL)
                return false;
            break;
        }
    }
    return true;
}
