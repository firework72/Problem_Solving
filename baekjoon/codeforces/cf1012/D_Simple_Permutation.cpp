#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int isNotPrime[SIZE] = {0};
vector<int> prime;

void makePrime() {
    for (int i = 2; i * i <= 200000; i++) {
        if (isNotPrime[i]) continue;
        for (int j = i * 2; j <= 200000; j += i) {
            isNotPrime[j] = 1;
        }
    }

    for (int i = 2; i <= 200000; i++) {
        prime.push_back(i);
    }
}

void solve() {
    int cnt = 0;
    int len = 1;
    ll val = 1;
    int prev_prime = 1;
    for (int i = 2; i <= 100005; i++) {
        if (isNotPrime[i]) continue;
        int cur = i * 2 - 1;
        for (int j = cur; j > prev_prime * 2 - 1; j--) {
            len++;
            if (isNotPrime[val / len] == 0) cnt++;
            cout << cnt << ' ' << len / 3 - 1 << '\n';
        }
    }
    cout << "true";
}

int main() {
    FAST_IO
    makePrime();
    int t;
    cin >> t;
    while (t--) solve();
}