import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        
        String[] arr = Arrays.stream(numbers)
                            .mapToObj(String::valueOf)
                            .toArray(String[]::new);
        
        Arrays.sort(arr, (a, b) -> (b + a).compareTo(a + b));
        
        StringBuilder sb = new StringBuilder();
        
        for (String s : arr) {
            sb.append(s);
        }
        
        
        if (arr[0].equals("0")) return "0";
        
        return sb.toString();
    }
}