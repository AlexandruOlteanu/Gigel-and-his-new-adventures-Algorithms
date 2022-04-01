#include <bits/stdc++.h>
using namespace std;

ifstream in("prinel.in");
ofstream out("prinel.out");
// ifstream in("input.txt");
// ofstream out("output.txt");
#define cin in
#define cout out

const int maxn = 1e3 + 2;
const int inf = 2e9;

vector<int> c(100002, inf), cost(maxn), p(maxn);
vector<vector<int>> dp(maxn, vector<int>(40000, 0));
vector<vector<int>> divisors(100002);


void preprocess() {
    for (int i = 1; i <= 1e5; ++i) {
        for (int j = i; j <= 1e5; j += i) {
            divisors[j].push_back(i);
        }
    }
    c[1] = 0;
    for (int i = 1; i <= 1e5; ++i) {
        for (auto u : divisors[i]) {
            if (i + u <= 1e5) {
                c[i + u] = min(c[i + u], c[i] + 1);
            }
        }
    }
    return;
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    preprocess();
    int n, k;
    cin >> n >> k;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        int x;cin >> x;
        cost[i] = c[x];
        sum += cost[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    k = min(k, sum);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= cost[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + p[i]);
            }
        }
    }
    cout << dp[n][k] << '\n';

    return 0;
}