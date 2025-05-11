#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int ans[SIZE] = {0};
int n;
int r = 1, k = 1;

bool comp(pair<int, int> p1, pair<int, int> p2) {
    return p1.first > p2.first;
}

vector<pair<int, int>> v;

int main() {
    FAST_IO
    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back({tmp, i});
    }

    sort(v.begin(), v.end(), comp);

    ans[v[0].second] = 1;

    for (int i = 1; i < n; i++) {
        if (v[i].first != v[i-1].first) {
            r += k;
            k = 0;
        }

        ans[v[i].second] = r;
        k++;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
}