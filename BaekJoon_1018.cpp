#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
char board[50][50];

int countRepaints(int x, int y) {
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // (i+j)의 합이 짝수인 경우와 홀수인 경우를 나누어 계산
            if ((i + j) % 2 == 0) {
                if (board[x + i][y + j] != 'W') cnt1++;
                if (board[x + i][y + j] != 'B') cnt2++;
            } else {
                if (board[x + i][y + j] != 'B') cnt1++;
                if (board[x + i][y + j] != 'W') cnt2++;
            }
        }
    }
    // 두 가지 경우 중 더 작은 값을 반환
    return min(cnt1, cnt2);
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    int minRepaint = 1e9;
    for (int i = 0; i + 7 < N; i++) {
        for (int j = 0; j + 7 < M; j++) {
            minRepaint = min(minRepaint, countRepaints(i, j));
        }
    }

    cout << minRepaint;
    return 0;
}
