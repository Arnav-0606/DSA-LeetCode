class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int sx, sy;
        int totalKeys = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    sx = i;
                    sy = j;
                }
                else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    totalKeys++;
                }
            }
        }

        int finalMask = (1 << totalKeys) - 1;

        vector<vector<vector<bool>>> vis(
            m,
            vector<vector<bool>>(n, vector<bool>(1 << totalKeys, false))
        );

        queue<tuple<int,int,int>> q;
        q.push({sx, sy, 0});
        vis[sx][sy][0] = true;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        int steps = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [x, y, mask] = q.front();
                q.pop();

                if (mask == finalMask)
                    return steps;

                for (int d = 0; d < 4; d++) {

                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;

                    char ch = grid[nx][ny];

                    if (ch == '#')
                        continue;

                    int newMask = mask;
                    if (ch >= 'a' && ch <= 'f')
                        newMask |= (1 << (ch - 'a'));
                    if (ch >= 'A' && ch <= 'F') {
                        if (!(newMask & (1 << (ch - 'A'))))
                            continue;
                    }
                    if (!vis[nx][ny][newMask]) {
                        vis[nx][ny][newMask] = true;
                        q.push({nx, ny, newMask});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};