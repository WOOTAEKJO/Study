#include <iostream>
#include <vector>
using namespace std;

bool InRange(int x, int y, int n)
{
    return (0 <= x && x < n && 0 <= y && y < n);
}

int main() {
    // 여기에 코드를 작성해주세요.

    int n(0),k(0),iCount(0);

    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    int dir = 0;

    cin >> n;

    vector<vector<char>> array(n);

    for(auto& chs : array)
    {
        for(int i = 0; i < n;i++)
        {
            char c;
            cin >> c;
            chs.push_back(c);
        }
    }

    cin >> k;

    int point[2] = {};

    for(int i = 1; i<k;i++)
    {
        if(InRange(point[0] + dx[dir],point[1] + dy[dir],n))
        {
            point[0] += dx[dir];
            point[1] += dy[dir];
        }else
            dir = (dir + 1) % 4;
    }

    int light_dir = (dir + 1) % 4;

    while(1)
    {
        if(array[point[0]][point[1]] == '\\')
        {
            if(light_dir == 0 || light_dir == 2)
                light_dir = (light_dir + 1) % 4;
            else
                light_dir = (light_dir - 1 + 4) % 4;  
        }
        else{
            if(light_dir == 0 || light_dir == 2)
                light_dir = (light_dir - 1 + 4) % 4;
            else
                light_dir = (light_dir + 1) % 4;
        }

        iCount++;

        if(!InRange(point[0] + dx[light_dir],point[1] + dy[light_dir],n))
            break;
        
        point[0] += dx[light_dir];
        point[1] += dy[light_dir];
    }

    cout << iCount;

    return 0;
}