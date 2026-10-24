import java.util.*;

class Solution {
    
    public boolean possible(long limit_time, int n, int[] times) {
        long cnt = 0;
        for (int t : times) {
            cnt += limit_time / t;
            if (cnt >= n) return true;
        }
        
        return false;
    }
    
    public long solution(int n, int[] times) {
        long answer = 0;
        int maxT = Arrays.stream(times).max().getAsInt();
        long l = 1, r = (long) maxT * n, mid;
        
        while (l <= r) {
            mid = (r + l) / 2;
            
            if (possible(mid, n, times)) {
                answer = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        
        return answer;
    }
}