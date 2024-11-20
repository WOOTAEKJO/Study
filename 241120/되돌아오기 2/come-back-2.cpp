#include <iostream>
using namespace std;

int Rotate(char c, int dir)
{
    if(c == 'R')
        return (dir + 1) % 4;
    else if(c == 'L')
        return (dir - 1 + 4) % 4;
}

int main() {
    // 여기에 코드를 작성해주세요.

    int iCount(0);

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};

    int dir = 3;

    int point[2] = {};

    string str;

    cin >> str;

    for(auto c : str)
    {
        if(c == 'F')
        {
            point[0] += dx[dir];
            point[1] += dy[dir];
        }else
            dir = Rotate(c,dir);

        iCount++;

        if(point[0] == 0 && point[1] == 0)
            break;
    }

    if(iCount >= str.size())
        cout << -1;
    else   
        cout << iCount;

    return 0;
}