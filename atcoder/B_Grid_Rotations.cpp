#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int h, w;

int q;

int dir = 1;

int r, c;

vector<int> res_r, res_c;

int main() {
    FAST_IO
    cin >> h >> w;
    vector<string> v(h+2, "");
    for (int i = 0; i < h; i++) {
        cin >> v[i];
    }

    r = 0, c = 0;

    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (i % 2 == 0) {
            r = (r + a) % h;
            c = (c + b) % w;
        }
        else {
            r -= a, c -= b;
            if (r < 0) r += h;
            if (c < 0) c += w;
        }

        dir *= -1;
    }

    if (dir == 1) {
        for (int i = r; i < r + h; i++) {
            res_r.push_back(i % h);
        }
        for (int i = c; i < c + w; i++) {
            res_c.push_back(i % w);
        }
    }
    else {
        for (int i = r + h; i > r; i--) {
            res_r.push_back(i % h);
        }
        for (int i = c + w; i > c; i--) {
            res_c.push_back(i % w);
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << v[res_r[i]][res_c[j]];
        }
        cout << '\n';
    }
}