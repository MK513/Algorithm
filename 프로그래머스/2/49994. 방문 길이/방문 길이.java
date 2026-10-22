import java.util.HashMap;

class Solution {
    public int solution(String dirs) {
        int answer = 0;
        
        boolean[][][] visited = new boolean[20][20][4];
        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, 1, 0, -1};
        HashMap<Character, Integer> dirMap = new HashMap<>();
        dirMap.put('D', 0);
        dirMap.put('L', 1);
        dirMap.put('U', 2);
        dirMap.put('R', 3);
        
        int cx = 5, cy = 5;
        for (int i = 0; i < dirs.length(); i++) {
            char c = dirs.charAt(i);
            
            int d = dirMap.get(c);
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            
            if (nx < 0 || ny < 0 || nx > 10 || ny > 10) continue;
            
            if (!visited[cx][cy][d]) answer++;
            
            visited[cx][cy][d] = true;
            visited[nx][ny][(d + 2) % 4] = true;
            
            cx = nx;
            cy = ny;
        }
        
        return answer;
    }
}