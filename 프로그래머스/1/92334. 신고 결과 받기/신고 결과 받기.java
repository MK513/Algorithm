import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        
        Set<String> reportSet = new HashSet<>(Arrays.asList(report));
        
        Map<String, Set<String>> reportedUsers = new HashMap<>();
        Map<String, Integer> reportedCount = new HashMap<>();
        
        for (String r : reportSet) {
            String[] parts = r.split(" ");
            String reporter = parts[0];
            String reported = parts[1];
            
            reportedUsers.putIfAbsent(reporter, new HashSet<>());
            reportedUsers.get(reporter).add(reported);
            reportedCount.put(reported, reportedCount.getOrDefault(reported, 0) + 1);
        }
        
        List<Integer> answer = new ArrayList<>();
        
        for (String id : id_list) {
            int cnt = 0;
            Set<String> reporteds = reportedUsers.getOrDefault(id, new HashSet<>());
            
            for (String r : reporteds) {
                if (reportedCount.get(r) >= k) cnt++;
            }
            
            answer.add(cnt);
        }
        
        return answer.stream().mapToInt(i->i).toArray();
    }
}