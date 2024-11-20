#include <iostream>
#include <vector>
using namespace std;

bool InRange(int x, int y, int n, int m)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}

int main() {
    // 여기에 코드를 작성해주세요.

    int n(0),m(0);

    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    int dir = 1;

    int point[2] = {};

    cin >> n >> m;

    vector<vector<int>> array(n);

    for(auto& nums : array)
        nums.resize(m);

    array[0][0] = 1;

    for(int i = 2;i<=(n * m);i++)
    {
        if(!InRange(point[0] + dx[dir],point[1] + dy[dir],n,m) || 
        array[point[0] + dx[dir]][point[1] + dy[dir]] != 0)
            dir = (dir - 1 + 4) % 4;

        point[0] += dx[dir];
        point[1] += dy[dir];

        array[point[0]][point[1]] = i;
    }

    for(auto nums : array)
    {
        for(auto num : nums)
            cout << num << " ";

        cout << endl;
    }

    return 0;
}