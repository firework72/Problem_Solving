#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

void solve() {
    int n, k;
    cin >> n >> k;

    int start = 1;
    int end = n;

    vector<ll> prefix_sum_a(2 * n + 5, 0), prefix_sum_b(2 * n + 5, 0);
    vector<ll> a(n+3, 0), b(n+3, 0);

    vector<int> mn_round(n+3, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= 2 * n + 2; i++) {
        prefix_sum_a[i] += prefix_sum_a[i-1] + a[(i - 1) % n + 1];
        prefix_sum_b[i] += prefix_sum_b[i-1] + b[(i - 1) % n + 1];
    }

    
    while (start <= end) {
        int mid = (start + end) / 2;
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            ll cur = a[i];
            cur -= min(a[i], b[i]);
            ll mi = (prefix_sum_b[i + mid - 1] - prefix_sum_b[i]) - min(prefix_sum_a[i + mid - 1] - prefix_sum_a[i], prefix_sum_b[i + mid - 1] - prefix_sum_b[i]);
            cur -= mi;
            sum += max(0ll, cur);
        }

        if (sum == 0) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    int l = 1, r = 0;
    ll sum = 0;
    ll remain = 0;

    while (l <= n) {
        r++;
        sum += max(0ll, b[r] - remain);
        if (sum >= a[l]) {
            mn_round[l] = r - l;
            l++;
        }

        if ()
    }

    cout << start << '\n';
}


int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}