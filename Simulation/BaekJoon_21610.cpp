#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[54][54];
// 왼, 왼위, 위, 오른위, 오른, 오른아래, 아래, 윈아래
int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
bool visited[54][54] = {};
queue<pair<int, int>> q;
queue<pair<int, int>> moveq;
queue<pair<int, int>> magicq;
void moveCloud()
{
    // 모든 구림이 d방향으로 n칸 이동한다.
    while (!moveq.empty())
    {
        int d = moveq.front().first - 1;
        int n = moveq.front().second;

        moveq.pop();
        // 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;

            q.pop();
            int nx = x + n * dx[d];
            int ny = y + n * dy[d];
            nx = (nx + N) % N;
            ny = (ny + N) % N;
            if (nx < 0) nx += N;
            if (ny < 0) ny += N;
            if (nx == 0) nx = N;
            if (ny == 0) ny = N;
            arr[nx][ny] += 1;
            magicq.push({ nx,ny });
            visited[nx][ny] = true;
        }

        // 물복사 버그 마법
        while (!magicq.empty())
        {
            int x = magicq.front().first;
            int y = magicq.front().second;
            magicq.pop();
            for (int i = 1; i < 8; i += 2)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx > 0 && nx <= N && ny > 0 && ny <= N)
                {
                    if (arr[nx][ny] > 0)
                    {
                        arr[x][y] += 1;

                    }
                }
            }
        }
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (arr[i][j] >= 2 && visited[i][j] == false)
                {
                    q.push({ i,j });
                    arr[i][j] -= 2;
                }

                if (visited[i][j] == true)
                {
                    visited[i][j] = false;
                }
            }
        }
    }

}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < M; i++)
    {
        int x;
        int y;
        cin >> x >> y;
        moveq.push({ x,y });
    }
    q.push({ N,1 });
    q.push({ N,2 });
    q.push({ N - 1,1 });
    q.push({ N - 1,2 });
    moveCloud();
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            sum += arr[i][j];
            //cout << arr[i][j] << " ";
        }
        //cout << "\n";
    }
    cout << sum;
    return 0;
}
