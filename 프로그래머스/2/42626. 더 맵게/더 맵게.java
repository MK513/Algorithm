import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for (int i : scoville) {
            pq.offer(i);
        }
        
        while (true) {
            int f = pq.poll();
            
            if (f >= K) return answer;
            if (pq.isEmpty()) break;
            int s = pq.poll();
            
            int new_food = f + (s * 2);
            
            pq.offer(new_food);
            answer++;
        }
        
        return -1;
    }
}