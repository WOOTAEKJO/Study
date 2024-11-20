#include <iostream>
#include <vector>
using namespace std;

bool InRange(int x, int y, int n)
{
    return (0<= x && x < n && 0 <= y && y < n);
}

int main() {
    // 여기에 코드를 작성해주세요.

    int n(0),m(0);
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    cin >> n >> m;

    vector<vector<int>> array(n);

    for(auto& nums : array)
        nums.resize(n);

    while(m--)
    {
        int point[2] = {};
        cin >> point[0] >> point[1];

        array[point[0]-1][point[1]-1] = 1;

        int iCount(0);

        for(int k = 0; k<4;k++)
        {
            if(InRange(point[0]-1 + dx[k],point[1]-1+dy[k],n) && array[point[0]-1 + dx[k]][point[1]-1+dy[k]] == 1)
                iCount++;

        }

        if(iCount == 3)
            cout <<1;
        else
            cout << 0;
        cout << endl;
    }

    return 0;
}