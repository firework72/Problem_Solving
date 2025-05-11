#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 7000000
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int isNotPrime[SIZE] = {0};
vector<ll> prime;
ll prefix_sum[400005] = {0};

void makePrime() {
    for (int i = 2; i * i < SIZE; i++) {
        if (isNotPrime[i]) continue;
        for (int j = i * 2; j < SIZE; j += i) {
            isNotPrime[j] = 1;
        }
    }

    for (int i = 2; i < SIZE; i++) {
        if (isNotPrime[i] == 0) {
            prime.push_back(i);
        }
    }
}

void solve() {
    int n;
    ll sum = 0;
    cin >> n;
    vector<ll> v(n+3, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    sort(v.begin() + 1, v.begin() + n + 1);

    for (int i = n; i >= 2; i--) {
        ll flag = prefix_sum[i];
        if (sum >= flag) {
            cout << n - i << '\n';
            return;
        }

        sum -= v[n-i+1];
        
    }

    cout << n - 1 << '\n';
}

int main() {
    FAST_IO
    makePrime();
    for (int i = 1; i < 400005; i++) {
        prefix_sum[i] = prefix_sum[i-1] + prime[i-1];
    }
    int t;
    cin >> t;
    while (t--) solve();
}