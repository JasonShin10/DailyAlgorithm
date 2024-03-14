#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int arr[104][104] = {};
bool visited[104][104] = {};
vector<pair<int, char>> dir;
vector<pair<int, int>> aPos;
// 오른쪽, 아래, 왼쪽, 위
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, K;
  cin >> N >> K;
  for (int i = 0; i < K; i++) {
    int x;
    int y;
    cin >> x >> y;
    aPos.push_back({x - 1, y - 1});
  }

  for (int i = 0; i < K; i++) {

    int x = aPos[i].first;
    int y = aPos[i].second;
    arr[x][y] = 2;
  }

  int L;
  cin >> L;
  for (int i = 0; i < L; i++) {
    int x;
    char c;
    cin >> x >> c;
    dir.push_back({x, c});
  }
  int cnt = 0;
  int d = 0;
  int x = 0;
  int y = 0;
  bool isFinal = 0;
  deque<pair<int, int>> spos;
  visited[0][0] = true;
  spos.push_back({0, 0});
  for (int i = 0; i < dir.size(); i++) {
    int t = dir[i].first;
    while (1) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      if (nx >= 0 && nx < N && ny >= 0 && ny < N && visited[nx][ny] == false) {
        if (arr[nx][ny] == 2) {
          visited[nx][ny] = true;
          arr[nx][ny] = 0;
          spos.push_back({nx, ny});
        }
        else {
          visited[nx][ny] = true;
          if (spos.size()) {
            spos.push_back({nx, ny});
            int tx = spos.front().first;
            int ty = spos.front().second;
            spos.pop_front();
            visited[tx][ty] = false;
          }
          else {
            visited[x][y] = false;
          }
        }
        x = nx;
        y = ny;
      }
      else {
        cnt++;
        cout << cnt;
        return 0;
      }

      cnt++;
      if (cnt >= t && isFinal ==false) {
        if (dir[i].second == 'D') {
          d++;
          if (d >= 4) {
            d = 0;
          }
        }
        else {
          d--;
          if (d < 0) {
            d = 3;
          }
        }
        if (i == dir.size() - 1) {
          isFinal = true;
          continue;
        }
        break;
      }
    }
  }
  cout << cnt;
}
