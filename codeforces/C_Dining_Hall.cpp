#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ord;

    for (int i = 1; i <= 500000; i++) {
        if (i % 3 == 0) continue;
        if (i % 3 == 1) {
            int x = 1;
            int y = i;
            do {
                ord.push_back({x, y});
                x += 3;
                y -= 3;
            } while (y > 0);
        }
        else if (i % 3 == 2) {
            int x = 1;
            int y = i;
            do {
                if (x % 3 == 0) {

                }
                if (x % 3 == 1) {
                    ord.push_back({x, y});
                }
                else if (x % 3 == 2) {
                    if (y - 2 > 0) {
                        ord.push_back({x, y - 2});
                    }
                    ord.push_back({x, y});
                }
                x++;
                y--;
            } while (y > 0);
        }

        if (ord.size() > 10 * n) break;
    }


    vector<int> visited(ord.size(), 0);

    int l = 0, r = 0;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == 0) {
            while (visited[l] != 0 || !(ord[l].first % 3 == 1 && ord[l].second % 3 == 1) ) l++;
            cout << ord[l].first << ' ' << ord[l].second << '\n';
            visited[l] = 1;
        }
        else {
            while (visited[r] != 0) r++;
            cout << ord[r].first << ' ' << ord[r].second << '\n';
            visited[r] = 1;
        }
    }
}

int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}