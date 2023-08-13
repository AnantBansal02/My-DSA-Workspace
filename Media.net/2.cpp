#include<bits/stdc++.h>
using namespace std;
int helper(const vector<string> &a) {
    const int m = a.size(), n = a[0].length();
    vector<int> last(n);
    int r = 0;
    for (int i = 0; i < m; ++i) {
        vector<int> now(n);
        for (int j = n - 1, t = 0; j >= 0; --j) {
            now[j] = (t = a[i][j] == '0' ? (t + 1) : 0);
        }
        for (int j = 0, t = 0; j < n; ++j) {
            if (a[i][j] == '1') {
                t = 0;
                continue;
            }
            now[j] = (min(now[j], ++t) << 1) - 1;
            if (last[j] == 0) {
                last[j] = -1;
            }
            now[j] = min(last[j] + 2, now[j]);
            r += now[j] >> 1;
        }
        last = now;
    }
    return r;
}

int solution(const vector<string> &a) {
    auto b = a;
    reverse(b.begin(), b.end());
    return helper(a) + helper(b);
}

int main() {
    cout << solution({"11111", "01010", "11011"}) << endl;
    cout << solution({"1111", "1011", "0001"}) << endl;
    return 0;
}