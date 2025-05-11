#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 1000005
#define INF 987654321
#define MOD 1000000000
#define FLAG 10000

ll a[SIZE] = {0};
ll prefix_sum[SIZE] = {0};
int n, k;

int main() {
    FAST_IO
    cin >> n >> k;
    for (int i = 1; i <= n + 1; i++) {
        if (k < i) {
            ll cur = prefix_sum[i-1] - prefix_sum[i-k-1];
            if (cur < 0) cur += MOD;
            a[i] = cur;
        }
        else {
            a[i] = 1;
        }
        prefix_sum[i] = prefix_sum[i-1] + a[i];
        prefix_sum[i] %= MOD;
    }

    cout << a[n + 1];
}