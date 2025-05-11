#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int cnt[SIZE] = {0};
vector<int> v;
int n, m;
int ans = 0;

int main() {
    FAST_IO
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        cnt[tmp]++;
    }    

    do {
        bool flag = true;
        for (int i = 1; i <= m; i++) {
            if (cnt[i] == 0) flag = false;
        }
        if (flag == false) {
            break;
        }

        cnt[v.back()]--;
        v.pop_back();
        ans++;
    } while (1);
    cout << ans;
}