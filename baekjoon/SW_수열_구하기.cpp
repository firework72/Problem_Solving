#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int n;

int main() {
    FAST_IO
    cin >> n;
    for (int i = 0; i < n / 2; i++) {
        cout << i+1 << ' ' << n-i << ' ';
    }

    if (n % 2 == 1) {
        cout << n / 2 + 1;
    }
}