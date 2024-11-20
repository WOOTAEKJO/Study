#include <iostream>
#include <vector>
using namespace std;

bool InRange(int x, int y, int n)
{
    return (0 <= x && x < n && 0 <= y && y < n);
}

int main() {
    // 여기에 코드를 작성해주세요.

    int n(0);
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    int dir = 2;

    cin >> n;

    vector<vector<int>> array(n);

    int point[2] = {n-1,n-1};

    for(auto& nums : array)
        nums.resize(n);

    array[point[0]][point[1]] = n * n;

    for(int i = (n*n) - 1; i > 0;i--)
    {
        if(!InRange(point[0] + dx[dir],point[1] + dy[dir],n) ||
            array[point[0] + dx[dir]][point[1] + dy[dir]] != 0)
            dir = (dir + 1) % 4;

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