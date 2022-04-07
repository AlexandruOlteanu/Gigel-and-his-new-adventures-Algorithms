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
vector<vector<int>> dp(2, vector<int>(40000, 0));
vector<vector<int>> divisors(100002);
vector<int> a(maxn);


void preprocess(int x) {
    for (int i = 1; i <= x; ++i) {
        for (int j = i; j <= x; j += i) {
            divisors[j].push_back(i);
        }
    }
    c[1] = 0;
    for (int i = 1; i <= x; ++i) {
        for (auto u : divisors[i]) {
            if (i + u <= x) {
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

    int n, k;
    cin >> n >> k;
    int sum = 0;
    int maxi = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        maxi = max(maxi, a[i]);
    }
    preprocess(maxi);
    for (int i = 1; i <= n; ++i) {
        cost[i] = c[a[i]];
        sum += cost[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    if (k >= sum) {
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += p[i];
        }
        cout << ans << '\n';
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i % 2][j] = dp[1 - i % 2][j];
            if (j >= cost[i]) {
                dp[i % 2][j] = max(dp[i % 2][j], dp[1 - i % 2][j - cost[i]] + p[i]);
            }
        }
    }

    cout << dp[n % 2][k] << '\n';

    return 0;
}