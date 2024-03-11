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

int arr[1004][1004] = {};
int sum[1004][1004] = {};

vector<pair<int, int>> airPos = {};
queue<pair<int, int>> q;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int R, C, T;

void airfresherOn()
{
  int first = airPos[0].first;
  int second = airPos[1].first;

  int dx1[] = {0, -1, 0, 1};
  int dy1[] = {1, 0, -1, 0};

  int x = first;
  int y = 0;
  int prev = 0;
  int idx = 0;

  while (1)
  {
    int nx = x + dx1[idx], ny = y + dy1[idx];

    if (nx < 0 || nx >= R || ny < 0 || ny >= C)
    {
      idx++;
      continue;
    }
    if (nx == first && ny == 0)
    {
      break;
    }
    int cur = arr[nx][ny];
    arr[nx][ny] = prev;
    prev = cur;
    x = nx;
    y = ny;
  }

  int dx2[] = {0, 1, 0, -1};
  int dy2[] = {1, 0, -1, 0};

  x = second;
  y = 0;
  prev = 0;
  idx = 0;

  while (1)
  {
    int nx = x + dx2[idx], ny = y + dy2[idx];

    if (nx < 0 || nx >= R || ny < 0 || ny >= C)
    {
      idx++;
      continue;
    }

    if (nx == second && ny == 0)
    {
      break;
    }
    int cur = arr[nx][ny];
    arr[nx][ny] = prev;
    prev = cur;
    x = nx;
    y = ny;
  }
  return;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> R >> C >> T;

  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      cin >> arr[i][j];
      if (arr[i][j] == -1)
      {
        airPos.push_back({i, j});
      }
    }
  }

  while (T--)
  {
    for (int i = 0; i < R; i++)
    {
      for (int j = 0; j < C; j++)
      {
        if (arr[i][j] > 0)
        {
          int x = i;
          int y = j;
          int m = 0;
          for (int i = 0; i < 4; i++)
          {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < R && ny >= 0 && ny < C && arr[nx][ny] != -1)
            {
              sum[nx][ny] += arr[x][y] / 5;
              m += arr[x][y] / 5;
            }
          }
          arr[x][y] -= m;
        }
      }
    }

    for (int i = 0; i < R; i++)
    {
      for (int j = 0; j < C; j++)
      {
        arr[i][j] += sum[i][j];
      }
    }
    fill(&sum[0][0], &sum[0][0] + 1004 * 1004, 0);

    airfresherOn();
  }

  int sum = 0;
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      if (arr[i][j] != -1)
      {
        sum += arr[i][j];
      }
    }
  }
  cout << sum;
}
