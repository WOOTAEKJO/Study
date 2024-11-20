#include <iostream>
#include <vector>
using namespace std;

bool InRange(int x, int y, int n)
{ 
    return (0 <= x && x < n && 0 <= y && y < n);
}

int Rotate(char c,int dir)
{
    if(c=='R')
        return (dir + 1) %4;
    else
        return (dir - 1 + 4) % 4;
}

int main() {
    // 여기에 코드를 작성해주세요.

    int n(0), t(0), sum(0);
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    int dir = 3;

    cin >> n >> t;

    vector<vector<int>> array(n);
    string str;

    cin >> str;

    for(auto& nums : array)
    {
        int i = n;
        while(i--)
        {
            int temp(0);
            cin >> temp;
            nums.push_back(temp);
        }
    }

    int point[2] = {n/2,n/2};
    sum += array[point[0]][point[1]];

    for(auto ch : str)
    {
        if((ch == 'F'))
        {   
            if(!InRange(point[0] + dx[dir],point[1] + dy[dir],n))
                continue;

            point[0] += dx[dir];
            point[1] += dy[dir];

            sum += array[point[0]][point[1]];
            
        }else
            dir = Rotate(ch,dir);

        
    }
    
    cout << sum;

    return 0;
}