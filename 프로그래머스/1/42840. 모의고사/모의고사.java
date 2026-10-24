import java.util.*;

class Solution {
    public int[] solution(int[] answers) {
        List<Integer> answer = new ArrayList<>();
        int[][] patterns = {
            {1, 2, 3, 4, 5},
            {2, 1, 2, 3, 2, 4, 2, 5},
            {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
        };
        
        int[] ans_cnt = new int[3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < answers.length; j++) {
                if (answers[j] == patterns[i][j % patterns[i].length])
                    ans_cnt[i]++;
            }
        }
        
        int mx = Arrays.stream(ans_cnt).max().getAsInt();
        
        for (int i = 0; i < ans_cnt.length; i++) {
            if (ans_cnt[i] == mx) answer.add(i + 1);
        }
        
        return answer.stream().mapToInt(Integer::intValue).toArray();

        
    }
}