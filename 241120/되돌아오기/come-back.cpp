#include <iostream>
using namespace std;

int direct(char c)
{
    if(c == 'E')
        return 0;
    else if(c == 'S')
        return 1;
    else if(c == 'W')
        return 2;
    else if(c == 'N')
        return 3;
    return 0;
}

int main() {
    // 여기에 코드를 작성해주세요.

    int n(0),count(0);
    cin >> n;

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};

    int point[2] = {};

    while(n > 0)
    {   
        int temp(0);
        char c;
        cin >> c >> temp;

        for(int i = 0; i<temp;i++)
        {
            point[0] += dx[direct(c)];
            point[1] += dy[direct(c)];

            count++;

            if(point[0] == 0 && point[1] == 0)
            {
                n = 0;
                break;
            }
        }

        n--;
    }

    if(n == 0)
        cout << -1;
    else
        cout << count;

    return 0;
}