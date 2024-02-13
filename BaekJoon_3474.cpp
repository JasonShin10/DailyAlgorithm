#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <math.h>
#include <cstring> 

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int cnt = 0;

        for (long long i = 5; n / i >= 1; i *= 5) {
            cnt += n / i;
        }
        cout << cnt << '\n';
    }
    return 0;

}
