#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int n;
vector<pair<ll, ll>> v;

int main() {
    FAST_IO
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    cout << fixed;
    cout.precision(12);
    cout << hypotl(v[0].first - v[n-1].first, v[0].second - v[n-1].second);
}