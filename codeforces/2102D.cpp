#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int segTree[SIZE * 4] = {0};

void makeSeg(int node, int start, int end) {
    if (start == end) {
        segTree[node] = 0;
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

int query(int node, int start, int end, int left, int right) {
    if (start > right || end < left) {
        return 0;
    }
    if (left <= start && end <= right) {
        return segTree[node];
    }

    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a, b;
    ll inv_cnt_a = 0, inv_cnt_b = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (i % 2 == 0) {
            a.push_back(tmp);
        }
        else {
            b.push_back(tmp);
        }
    }

    makeSeg(1, 1, n);
    for (int i = 0; i < a.size(); i++) {
        inv_cnt_a += query(1, 1, n, a[i], n);
        updateSeg(1, a[i], 1, 1, n);
    }

    makeSeg(1, 1, n);
    for (int i = 0; i < b.size(); i++) {
        inv_cnt_b += query(1, 1, n, b[i], n);
        updateSeg(1, b[i], 1, 1, n);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (abs(inv_cnt_a - inv_cnt_b) % 2 == 1) {
        if (n % 2 == 0) {
            swap(b[b.size() - 2], b[b.size() - 1]);
        }
        else {
            swap(a[a.size() - 2], a[a.size() - 1]);
        }
    }

    //cout << inv_cnt_a << ' ' << inv_cnt_b << '\n';

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            cout << a[i/2] << ' ';
        }
        else {
            cout << b[i/2] << ' ';
        }
    }

    cout << '\n';
}

int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}