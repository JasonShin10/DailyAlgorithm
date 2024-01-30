#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int arr[101][101] = {};
int ansArr[101][101] = {};
bool visited[101][101] = {};
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

queue<pair<int, int>> mq;

void BFS() {
    while (!mq.empty()) {
        int x = mq.front().first;
        int y = mq.front().second;
        mq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[nx][ny] == 1 && !visited[nx][ny]) {
                mq.push({ nx,ny });
                ansArr[nx][ny] = ansArr[x][y] + 1;
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++) {
            arr[i][j] = line[j] - '0'; 
        }
    }

    mq.push({ 0,0 });
    visited[0][0] = true;
    ansArr[0][0] = 1;
    BFS();

    cout << ansArr[N - 1][M - 1] << endl;

    return 0;
}
