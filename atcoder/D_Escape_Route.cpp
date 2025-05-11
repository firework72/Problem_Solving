#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 1005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int h, w;
char field[SIZE][SIZE] = {0};
int dist[SIZE][SIZE] = {0};

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
char res_char[4] = {'v', '>', '^', '<'};

queue<pair<int, int>> q;

int main() {
    FAST_IO
    cin >> h >> w;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            dist[i][j] = INF;
        }
    }
    for (int i = 1; i <= h; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= w; j++) {
            field[i][j] = s[j-1];
            if (field[i][j] == 'E') {
                q.push({i, j});
                dist[i][j] = 0;
            }
            
        }
    }

    

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 1 || nr > h || nc < 1 || nc > w) continue;
            if (dist[nr][nc] != INF) continue;
            if (field[nr][nc] != '.') continue;

            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (field[i][j] == '.') {
                int mn = INF;
                for (int k = 0; k < 4; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if (dist[nr][nc] < mn) {
                        mn = dist[nr][nc];
                        field[i][j] = res_char[k];
                    }
                }
            }
            
            cout << field[i][j];
        }
        cout << '\n';
    }
}