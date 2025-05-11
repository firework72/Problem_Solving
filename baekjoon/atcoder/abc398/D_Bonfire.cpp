#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

set<pair<int, int>> s;
string str;
int n;
int x, y;
int fx = 0, fy = 0;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, -1, 0, 1};

int convert(char c) {
    if (c == 'N') return 0;
    if (c == 'E') return 1;
    if (c == 'S') return 2;
    if (c == 'W') return 3;
}

int main() {
    FAST_IO
    cin >> n >> y >> x;
    cin >> str;
    s.insert({0, 0});
    for (int i = 0; i < n; i++) {
        int d = convert(str[i]);
        fx += dx[d];
        fy += dy[d];
        s.insert({fx, fy});
        x += dx[d];
        y += dy[d];

        if (s.find({x, y}) != s.end()) {
            cout << "1";
        }
        else {
            cout << "0";
        }
    }
}