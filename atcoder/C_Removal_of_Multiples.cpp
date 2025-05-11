#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 3000005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int q;
set<int> s;
int segTree[SIZE * 4] = {0};
int flag[SIZE] = {0};

void makeSeg(int node, int start, int end) {
    if (start == end) {
        segTree[node] = 1;
        return;
    }

    int mid = (start + end) / 2;
    makeSeg(node * 2, start, mid);
    makeSeg(node * 2 + 1, mid + 1, end);
    segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}

void updateSeg(int node, int target, int val, int start, int end) {
    if (start > target || end < target) {
        return;
    }

    if (start == end) {
        segTree[node] = val;
        return;
    }

    int mid = (start + end) / 2;
    updateSeg(node * 2, target, val, start, mid);
    updateSeg(node * 2 + 1, target, val, mid + 1, end);
    segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}

int query(int node, int target, int start, int end, int left, int right) {
    if (left > target || right < target) {
        return 0;
    }

    if (start == end) {
        return start;
    }

    int mid = (start + end) / 2;
    int res1 = query(node * 2, target, start, mid, left, right - segTree[node * 2 + 1]);
    int res2 = query(node * 2 + 1, target, mid + 1, end, left + segTree[node * 2], right);
    return max(res1, res2);
}

int main() {
    FAST_IO
    for (int i = 1; i < SIZE; i++) {
        flag[i] = 1;
    }
    makeSeg(1, 1, 3000000);
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (s.find(a) == s.end()) {
            s.insert(a);
            for (int i = a; i < SIZE; i += a) {
                if (flag[i] == 1) {
                    flag[i] = 0;
                    updateSeg(1, i, 0, 1, 3000000);
                }
            }
        }
        cout << query(1, b, 1, 3000000, 1, segTree[1]) << '\n';
    }
}