#include <bits/stdc++.h>
using namespace std;

ifstream in("statistics.in");
ofstream out("statistics.out");
#define cin in
#define cout out


const int alphabet_len = 30;

vector<int> v[alphabet_len];
int have_letters[alphabet_len];

int main() {

    int n;
    cin >> n;
    for (int tt = 1; tt <= n; ++tt) {
        string s;
        cin >> s;
        int sz = s.size();
        for (int j = 0; j < 26; ++j) {
            have_letters[j] = 0;
        }
        for (char c : s) {
            ++have_letters[c - 'a'];
        } 
        for (int i = 0; i < 26; ++i) {
            v[i].push_back(2 * have_letters[i] - sz);
        }
    }
    for (int i = 0; i < 26; ++i) {
        sort(v[i].rbegin(), v[i].rend());
    }
    int cnt = 0;
    char letter;
    for (int i = 0; i < 26; ++i) {
        int ans = 0;
        int sum = 0;
        for (int j = 0; j < v[i].size(); ++j) {
            sum += v[i][j];
            if (sum <= 0) {
                break;
            }
            ++ans;
        }
        cnt = max(cnt, ans);
    }
    if (cnt == 0)cnt = -1;
    cout << cnt << '\n';


    return 0;
}