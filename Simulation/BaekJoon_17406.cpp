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

int arr[54][54] = {};
int temp[54][54] = {};

bool visited[54][54] = {};
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int N, M, K;
struct S {
  int r;
  int c;
  int s;
};

vector<S> v;

bool selected[6] = {};
vector<int> ans;
vector<S> cv;

void Rotate(int lx, int ly, int rx, int ry)
{
  int d = 0;
  int pre, cur;
  pre = temp[lx][ly];
  int nx = lx;
  int ny = ly;
  while (1) {
    if (nx + dx[d] >= lx && nx + dx[d] < rx && ny + dy[d] >= ly &&
        ny + dy[d] < ry) {
      nx += dx[d];
      ny += dy[d];
      cur = temp[nx][ny];
      temp[nx][ny] = pre;
      pre = cur;
      visited[nx][ny] = true;
    }
    else {
      d++;
      if (d >= 4) {
        if (visited[lx + 1][ly + 1] == false) {
          Rotate(lx + 1, ly + 1, rx - 1, ry - 1);
          return;
        }
        else {
          return;
        }
      }
    }
  }
}
void Permute()
{
  if (cv.size() == K) {
    memcpy(temp, arr, sizeof(int) * 54 *54);
    for (int i = 0; i < K; i++) {
      int lx = cv[i].r - cv[i].s - 1;
      int ly = cv[i].c - cv[i].s - 1;
      int rx = cv[i].r + cv[i].s;
      int ry = cv[i].c + cv[i].s;
      Rotate(lx, ly, rx, ry);
      fill(&visited[0][0], &visited[0][0] + 54 * 54, false);
    }
    int mn = 1e9;
    for (int i = 0; i < N; i++) {
      int sum = 0;
      for (int j = 0; j < M; j++) {
        sum += temp[i][j];
      }
      if (mn > sum) {
        mn = sum;
      }
    }
    ans.push_back(mn);
    return;
  }

  for (int i = 0; i < K; i++) {
    if (!selected[i]) {
      selected[i] = true;
      cv.push_back(v[i]);
    Permute();
    cv.pop_back();
    selected[i] = false;
    }
  }
  return;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M >> K;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < K; i++) {
    S ss;
    cin >> ss.r >> ss.c >> ss.s;
    v.push_back(ss);
  }
  Permute();

  int mn = 1e9;
  for (int i = 0; i < ans.size(); i++) {
    if (ans[i] < mn) {
      mn = ans[i];
    }
  }

  cout << mn;
}
