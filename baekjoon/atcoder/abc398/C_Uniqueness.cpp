#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

map<int, int> m;
vector<int> v;
int n;
int ans = -1;
int mx = -1;

int main() {
    FAST_IO
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        m[tmp]++;
    }

    for (int i = 0; i < n; i++) {
        if (m[v[i]] == 1) {
            if (v[i] > mx) {
                ans = i + 1;
                mx = v[i];
            }
        }
    }

    cout << ans;
}