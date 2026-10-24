import java.util.*;

class Solution {
    public String solution(String new_id) {
        String answer = "";
        
        StringBuilder sb = new StringBuilder();
        
        // 1 ~ 3 처리
        for (char c : new_id.toCharArray()) {
            
            c = Character.toLowerCase(c);
            if (Character.isLetter(c) || Character.isDigit(c) || c == '-' || c == '_' || c == '.') {
                if (c == '.' && sb.length() > 0 && sb.charAt(sb.length() - 1) == '.') continue;
                sb.append(c);
            }
        }
        
        // 4
        if (sb.length() > 0 && sb.charAt(0) == '.') sb.deleteCharAt(0);
        if (sb.length() > 0 && sb.charAt(sb.length() - 1) == '.') sb.deleteCharAt(sb.length() - 1);

        // 5
        if (sb.isEmpty()) {
            sb.append('a');
        }
        
        // 6
        if (sb.length() >= 16) {
            sb.setLength(15);
            if (sb.charAt(sb.length() - 1) == '.') sb.deleteCharAt(sb.length() - 1);
        }
        
        // 7
        while (sb.length() <= 2) {
            sb.append(sb.charAt(sb.length() - 1));
        }
        
        return sb.toString();
    }
}