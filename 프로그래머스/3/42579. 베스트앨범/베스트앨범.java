import java.util.*;

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        
        Map<String, List<int[]>> map = new HashMap<>();
        Map<String, Integer> totalPlay = new HashMap<>();
        
        for (int i = 0; i < genres.length; i++) {
            map.putIfAbsent(genres[i], new ArrayList<>());
            map.get(genres[i]).add(new int[]{plays[i], i});
            
            totalPlay.merge(genres[i], plays[i], Integer::sum);
        }
        
        List<String> genreOrder = new ArrayList<>(totalPlay.keySet());
        genreOrder.sort((a, b) -> Integer.compare(totalPlay.get(b), totalPlay.get(a)));
        
        for (Map.Entry<String, List<int[]>> entry : map.entrySet()) {
            List<int[]> lists = entry.getValue();
            
            lists.sort((a, b) -> {
                if (a[0] == b[0]) {
                    return Integer.compare(a[1], b[1]); 
                }
                return Integer.compare(b[0], a[0]);
            });
        }
        
        List<Integer> answer = new ArrayList<>();
        for (String genre : genreOrder) {
            List<int[]> lists = map.get(genre);
            answer.add(lists.get(0)[1]);
            
            if (lists.size() >= 2)
                answer.add(lists.get(1)[1]);            
        }
        
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}