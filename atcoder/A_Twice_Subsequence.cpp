#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int n, m;
vector<int> a, b;
vector<int> t, u;

int main() {
    FAST_IO
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
    }


    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[pos]) {
            pos++;
            t.push_back(i);
            if (pos == m) {
                break;
            }
        }
    }

    if (pos != m){
        cout << "No";
        return 0;
    }
    
    pos = m - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == b[pos]) {
            pos--;
            u.push_back(i);
            if (pos == -1) {
                break;
            }
        }
    }

    sort(u.begin(), u.end());
    if (t == u) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }
}