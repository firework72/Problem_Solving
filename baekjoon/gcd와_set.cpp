#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 5005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int n;
int has[SIZE] = {0};
int visited[SIZE] = {0};
vector<int> divisor[SIZE];

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    return (b == 0) ? a : gcd(b, a % b);
}

int ans = 0;

int main() {
    FAST_IO
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        has[tmp]++;
    }

    for (int i = 1; i <= 5000; i++) {
        if (has[i] == 0) continue;
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                divisor[j].push_back(i);
                if (i != j) {
                    divisor[i / j].push_back(i);
                }
            }
        }
    }

    for (int i = 1; i <= 5000; i++) {
        if (divisor[i].empty()) continue;
        int sum = 0;
        int mx = -1;
        
        for (int j : divisor[i]) {
            visited[j] = 1;
            sum += has[j];
            mx = max(mx, j);
        }

        int GCD = 0;

        for (int j = 1; j <= 5000; j++) {
            if (has[j] == 0 || visited[j]) continue;
            GCD = gcd(GCD, j);
            if (GCD == 1) break;
        }

        if (GCD == 0 && sum >= 2) {
            ans = max(ans, mx + i);
        }

        ans = max(ans, GCD + i);


        for (int j : divisor[i]) {
            visited[j] = 0;
        }
    }

    cout << ans;
}