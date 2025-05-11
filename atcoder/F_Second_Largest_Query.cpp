#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

struct Node {
    int mx1;
    int mx2;
    int cnt1;
    int cnt2;
};

Node segTree[SIZE * 4] = {0};
int a[SIZE] = {0};

int n, q;

void makeSeg(int node, int start, int end) {
    if (start == end) {
        segTree[node] = {a[start], -1, 1, 0};
        return;
    }

    int mid = (start + end) / 2;
    makeSeg(node * 2, start, mid);
    makeSeg(node * 2 + 1, mid + 1, end);
    map<int, int> m;
    vector<pair<int, int>> tmp;
    m[segTree[node * 2].mx1] += segTree[node * 2].cnt1;
    m[segTree[node * 2].mx2] += segTree[node * 2].cnt2;
    m[segTree[node * 2 + 1].mx1] += segTree[node * 2 + 1].cnt1;
    m[segTree[node * 2 + 1].mx2] += segTree[node * 2 + 1].cnt2;

    for (auto i : m) {
        tmp.push_back(i);
    }

    segTree[node] = {tmp[tmp.size() - 1].first, tmp[tmp.size() - 2].first, tmp[tmp.size() - 1].second, tmp[tmp.size() - 2].second};
}

void updateSeg(int node, int target, int val, int start, int end) {
    if (start > target || end < target) {
        return;
    }

    if (start == end) {
        segTree[node] = {val, -1, 1, 0};
        return;
    }

    int mid = (start + end) / 2;
    updateSeg(node * 2, target, val, start, mid);
    updateSeg(node * 2 + 1, target, val, mid + 1, end);

    map<int, int> m;
    vector<pair<int, int>> tmp;
    m[segTree[node * 2].mx1] += segTree[node * 2].cnt1;
    m[segTree[node * 2].mx2] += segTree[node * 2].cnt2;
    m[segTree[node * 2 + 1].mx1] += segTree[node * 2 + 1].cnt1;
    m[segTree[node * 2 + 1].mx2] += segTree[node * 2 + 1].cnt2;

    for (auto i : m) {
        tmp.push_back(i);
    }

    segTree[node] = {tmp[tmp.size() - 1].first, tmp[tmp.size() - 2].first, tmp[tmp.size() - 1].second, tmp[tmp.size() - 2].second};
}

Node query(int node, int start, int end, int left, int right) {
    if (start > right || end < left) {
        return {-1, -1, 0, 0};
    }

    if (left <= start && end <= right) {
        return segTree[node];
    }

    int mid = (start + end) / 2;
    
    Node res1 = query(node * 2, start, mid, left, right);
    Node res2 = query(node * 2 + 1, mid + 1, end, left, right);

    map<int, int> m;
    vector<pair<int, int>> tmp;
    m[res1.mx1] += res1.cnt1;
    m[res1.mx2] += res1.cnt2;
    m[res2.mx1] += res2.cnt1;
    m[res2.mx2] += res2.cnt2;

    for (auto i : m) {
        tmp.push_back(i);
    }

    return {tmp[tmp.size() - 1].first, tmp[tmp.size() - 2].first, tmp[tmp.size() - 1].second, tmp[tmp.size() - 2].second};
}

int main() {
    FAST_IO
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    makeSeg(1, 1, n);

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            updateSeg(1, a, b, 1, n);
        }
        else {
            cout << query(1, 1, n, a, b).cnt2 << '\n';
        }
    }
}