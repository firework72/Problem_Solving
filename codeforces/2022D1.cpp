#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

void solve() {
    int n;
    cin >> n;
    int start = 1;
    int end = n;
    while (end - start > 1) {
        int mid = (start + end) / 2;
        vector<int> v;
        v.push_back(0);
        for (int i = start; i <= mid; i++) {
            int a = i;
            int b = i + 1;
            if (b > mid) b = start;
            cout << "? " << a << ' ' << b << endl;
            int res;
            cin >> res;
            if (res == 0) {
                v.push_back(!v.back());
            }
            else {
                v.push_back(v.back());
            }
        }

        // 탐색한 범위 내에 임포스터가 있음.
        if (v[0] != v.back()) {
            end = mid;
        }
        else {
            start = mid + 1;
        }
    }

    if (start == end) {
        cout << "! " << start << endl;
    }
    else {
        if (start == 1) {
            cout << "? 2 3" << endl;
            int res1;
            cin >> res1;
            cout << "? 3 2" << endl;
            int res2;
            cin >> res2;
            if (res1 == res2) {
                cout << "! 1" << endl;
            } 
            else {
                cout << "! 2" << endl;
            }
        }
        else {
            cout << "? " << start - 1 << ' ' << start << endl;
            int res1;
            cin >> res1;
            cout << "? " << start << ' ' << start - 1 << endl;
            int res2;
            cin >> res2;
            if (res1 == res2) {
                cout << "! " << end << endl;
            } 
            else {
                cout << "! " << start << endl;
            }
        }
    }
}

int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}