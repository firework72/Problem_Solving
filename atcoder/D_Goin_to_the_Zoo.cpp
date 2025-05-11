#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 15
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int n, m;
ll ans = 1e18+9;

ll c[SIZE] = {0};
int visitCnt[SIZE] = {0};
vector<int> animal[105];

int myPow(int x, int y) {
    int ret = 1;
    for (int i = 0; i < y; i++) {
        ret *= x;
    }
    return ret;
}

int main() {
    FAST_IO
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }


    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        while (k--) {
            int tmp;
            cin >> tmp;
            tmp--;
            animal[i].push_back(tmp);
        }
    }

    for (int i = 0; i < myPow(3, n); i++) {
        ll curCost = 0;
        for (int j = 0; j < n; j++) {
            visitCnt[j] = i % myPow(3, j + 1) / myPow(3, j);
            curCost += c[j] * visitCnt[j];
        }
        
        bool flag = true;

        for (int j = 0; j < m; j++) {
            int tmp = 0;
            for (int k : animal[j]) {
                tmp += visitCnt[k];
            }
            if (tmp < 2) {
                flag = false;
            }
        } 

        if (flag) {
            ans = min(ans, curCost);
        }
    }

    cout << ans;
}