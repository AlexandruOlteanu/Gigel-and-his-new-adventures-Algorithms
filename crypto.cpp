#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const mod=1000000007LL;
ll mypowr(ll a,ll b, ll mod1) {ll res=1;if(b<0)b=0;a%=mod1; assert(b>=0);
for(;b;b>>=1){if(b&1)res=res*a%mod1;a=a*a%mod1;}return res;}

ifstream in("crypto.in");
ofstream out("crypto.out");
// ifstream in("input.txt");
// ofstream out("output.txt");
#define cin in
#define cout out

vector<vector<ll>> dp(11, vector<ll>(11, 0)), dp1(11, vector<ll>(11, 0));
set<int> st;


int main() {

    int n, l;
    string k, s;
    cin >> n >> l >> k >> s;
    int sz = s.size();
    s = "#" + s;
    k = "#" + k;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += (k[i] == '?');
        dp1[1][0] = dp1[1][1] = 0;
        if (k[i] == '?') {
            dp1[1][1] = 1;
        }
        if (k[i] == s[1]) {
            dp1[1][0] = 1;
        }
        for (int j = 2; j <= sz; ++j) {
            for (int t = 0; t <= j; ++t) {
                dp1[j][t] = 0;
                if (k[i] == '?' && t > 0) {
                    dp1[j][t] = dp[j - 1][t - 1];
                }          
                if (k[i] == s[j]) {
                    dp1[j][t] = dp[j - 1][t];
                }
            }
        }
        for (int j = 1; j <= sz; ++j) {
            for (int t = 0; t <= j; ++t) {
                dp[j][t] += dp1[j][t];
                dp[j][t] %= mod;       
            }
        } 
    }
    int cnt = 0;
    for (int i = 1; i <= sz; ++i) {
        if (!st.count(s[i])) {
            ++cnt;
            st.insert(s[i]);
        }
    }
    ll ans = 0;
    for (int i = 0; i <= sz; ++i) {
        ans += dp[sz][i] * mypowr(cnt, sum - i, mod) % mod;
        ans %= mod;
    }
    cout << ans << '\n';

    return 0;
}