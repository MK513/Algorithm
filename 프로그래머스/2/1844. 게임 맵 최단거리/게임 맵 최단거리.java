import java.util.*;

class Solution {
    
    int N, M;
    int[][] Maps;
    boolean[][] visited;
    int[] dx = {-1, 0, 1, 0};
    int[] dy = {0, 1, 0, -1};
    
    public boolean is_possible(int x, int y) {
        if (x < 0 || y < 0 || x >= N || y >= M) return false;
        if (visited[x][y]) return false;
        if (Maps[x][y] == 0) return false;
        return true;
    }
    
    public int solution(int[][] maps) {
        Maps = maps;
        
        N = maps.length;
        M = maps[0].length;
        
        Deque<int[]> q = new ArrayDeque<>();
        visited = new boolean[N][M];
        q.offer(new int[]{0, 0, 1});
        visited[0][0] = true;
        
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            
            for (int i = 0; i < 4; i++) {
                int nx = cur[0] + dx[i];
                int ny = cur[1] + dy[i];
                
                if (is_possible(nx, ny)) {
                    
                    if (nx == N - 1 && ny == M - 1) {
                        return cur[2] + 1;
                    }

                    visited[nx][ny] = true;
                    q.offer(new int[]{nx, ny, cur[2] + 1});
                }
            }
        }
        
        return -1;
    }
}