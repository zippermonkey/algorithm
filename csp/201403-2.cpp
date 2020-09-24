#include <iostream>

using namespace std;

typedef struct window
{

    int x1, y1, x2, y2;

    int x;

} Window;

int m, n;

int isInwindow(Window &win, int x, int y)

{

    if (x >= win.x1 && x <= win.x2 && y >= win.y1 && y <= win.y2)

        return 1;

    else

        return 0;
}

void MoveWin(Window windows[], int i)

{

    windows[n] = windows[i];

    for (int k = i + 1; k < n; k++)

    {

        windows[k - 1] = windows[k];
    }

    windows[n - 1] = windows[n];
}

int main()

{

    cin >> n >> m;

    Window windows[n + 1];

    // 数组下标为n-1的优先级最大

    // 下标n作为移动的冗余

    for (int i = 0; i < n; i++)

    {

        cin >> windows[i].x1 >> windows[i].y1;

        cin >> windows[i].x2 >> windows[i].y2;

        windows[i].x = i + 1;
    }

    int x, y;

    while (m--)

    {

        cin >> x >> y;

        int inwin = 0;

        for (int i = n - 1; i >= 0; i--)

        {

            if (isInwindow(windows[i], x, y))

            {

                cout << windows[i].x << endl;

                inwin = 1;

                // 将window[i] 移动到最后

                MoveWin(windows, i);

                break;
            }
        }

        if (inwin == 0)

            cout << "IGNORED" << endl;
    }

    return 0;
}