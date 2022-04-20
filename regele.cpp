#include <bits/stdc++.h>
using namespace std;

ifstream in("regele.in");
ofstream out("regele.out");
// ifstream in("input.txt");
// ofstream out("output.txt");
#define cin in
#define cout out

const int maxn = 2e3 + 2;
const int inf = 2e9;

vector<int> v(maxn);
vector<vector<int>> dp(maxn, vector<int>(maxn, -inf));

int main() {

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    dp[1][1] = v[2] - v[1];
    dp[2][1] = max(dp[1][1], v[3] - v[1]);
    dp[2][2] = v[3] - v[1];
    for (int i = 3; i <= n; ++i) {
        int sum1 = v[i] - v[i - 1];
        int sum2 = 0;
        if (i + 1 <= n)sum1 += v[i + 1] - v[i], sum2 += v[i + 1] - v[i];
        dp[i][1] = max(dp[i - 1][1], sum1);
        for (int j = 2; j <= i; ++j) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + sum2);
            dp[i][j] = max(dp[i][j], dp[i - 2][j - 1] + sum1);
        }
    }
    
    
    int questions;
    cin >> questions;
    while (questions--) {
        int value;
        cin >> value;
        int low = 1, high = n;
        int answer = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (dp[n][mid] <= value) {
                answer = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        cout << answer << '\n';
    }


    return 0;
}