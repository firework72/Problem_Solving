#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 1005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

char field[SIZE][SIZE] = {0};
int dist[SIZE][SIZE] = {0};
int visitCell = 0;

int dr[8] = {1, 0, -1, 0, 2, 0, -2, 0};
int dc[8] = {0, 1, 0, -1, 0, 2, 0, -2};

queue<pair<int, int>> q;
queue<pair<int, int>> visited;
queue<pair<int, int>> tmp_q;

int h, w;
int a, b, c, d;

int main() {
    FAST_IO
    cin >> h >> w;

    for (int i = 1; i <= h; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= w; j++) {
            field[i][j] = s[j-1];
            dist[i][j] = INF;
        } 
    }

    cin >> a >> b >> c >> d;
    q.push({a, b});
    dist[a][b] = 0;
    visited.push({a, b});
    visitCell++;

    while (dist[c][d] == INF) {
        while (!q.empty()) {
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();
    
            for (int i = 0; i < 4; i++) {
                int nr = cr + dr[i];
                int nc = cc + dc[i];
                if (nr < 1 || nr > h || nc < 1 || nc > w) continue;
                if (dist[nr][nc] != INF) continue;
                if (field[nr][nc] == '#') continue;
    
                dist[nr][nc] = dist[cr][cc];
                visited.push({nr, nc});
                q.push({nr, nc});
                visitCell++;
            }
        }

        while (!visited.empty()) {
            int cr = visited.front().first;
            int cc = visited.front().second;
            visited.pop();
    
            for (int i = 0; i < 8; i++) {
                int nr = cr + dr[i];
                int nc = cc + dc[i];
                if (nr < 1 || nr > h || nc < 1 || nc > w) continue;
                if (dist[nr][nc] != INF) continue;
    
                dist[nr][nc] = dist[cr][cc] + 1;
                tmp_q.push({nr, nc});
                visitCell++;
            }
        }

        while (!tmp_q.empty()) {
            visited.push(tmp_q.front());
            q.push(tmp_q.front());
            tmp_q.pop();
        }
    }

    cout << dist[c][d];
}