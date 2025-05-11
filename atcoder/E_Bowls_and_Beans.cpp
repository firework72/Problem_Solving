#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int n;

int c[SIZE] = {0};
int a[SIZE] = {0};
int mn[SIZE] = {0};
int dist[SIZE] = {0};

int ans = 0;

int main() {
    FAST_IO
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> c[i];
    }

    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        mn[i] = max(0, i - c[i]);
    }

    for (int i = 1; i < n; i++) {
        int tmp = INF;
        for (int j = mn[i]; j < i; j++) {
            tmp = min(tmp, dist[j]);
        }
        dist[i] = tmp + 1;
    }

    for (int i = n - 1; i >= 1; i--) {

        if (a[i] == 0) continue;

        int target = INF;
        int tmp_mn = INF;
        
        for (int j = mn[i]; j < i; j++) {
            if (a[j] != 0 && dist[j] < tmp_mn) {
                tmp_mn = dist[j];
                target = j;
            }
        }

        if (target != INF) {
            a[target] += a[i];
            a[i] = 0;
            ans++;
            continue;
        }

        target = INF;
        tmp_mn = INF;

        for (int j = mn[i]; j < i; j++) {
            if (mn[j] < tmp_mn) {
                tmp_mn = mn[j];
                target = j;
            }
        }

        a[target] += a[i];
        a[i] = 0;
        ans++;
    }

    cout << ans;
}