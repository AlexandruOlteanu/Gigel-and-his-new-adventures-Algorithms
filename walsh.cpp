#include <bits/stdc++.h>
using namespace std;

ifstream in("walsh.in");
ofstream out("walsh.out");
#define cin in
#define cout out

bool check(int x, int y, int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) {
        return 0;
    }
    if (x <= x1 + (x2 - x1) / 2) {
        if (y <= y1 + (y2 - y1) / 2) {
            return check(x, y, x1, y1, x1 + (x2 - x1) / 2, y1 + (y2 - y1) / 2);
        }
        else {
            return check(x, y, x1, y1 + (y2 - y1 + 1) / 2, x1 + (x2 - x1) / 2, y2);
        }
    }
    else {
        if (y <= y1 + (y2 - y1) / 2) {
            return check(x, y, x1 + (x2 - x1 + 1) / 2, y1, x2, y1 + (y2 - y1) / 2);
        }
        else {
            return !check(x, y, x1 + (x2 - x1 + 1) / 2, y1 + (y2 - y1 + 1) / 2, x2, y2);
        }
    }
}

int main() {

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        int x, y;
        cin >> x >> y;
        cout << check(x, y, 1, 1, n, n) << '\n';
    }


    return 0;
}