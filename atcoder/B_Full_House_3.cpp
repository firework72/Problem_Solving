#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

vector<int> v;
int cnt[15] = {0};

int main() {
    FAST_IO
    for (int i = 0; i < 7; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        cnt[tmp]++;
    }

    for (int i = 1; i <= 13; i++) {
        for (int j = 1; j <= 13; j++) {
            if (i == j) continue;
            if (cnt[i] >= 3 && cnt[j] >= 2) {
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";

}