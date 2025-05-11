#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int isNotPrime[SIZE] = {0};

void makePrime() {
    for (int i = 2; i * i <= 200000; i++) {
        if (isNotPrime[i]) continue;
        for (int j = i * 2; j <= 200000; j += i) {
            isNotPrime[j] = 1;
        }
    }

    
}

void solve() {
    int cur = 0;
    for (int i = 2; i <= 200000; i++) {
        if (isNotPrime[(i + 2) / 2] == 0) cur++;
        if (cur < i / 3 - 1) {
            cout << i << ' ';   
            cout << "false";
            return;
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