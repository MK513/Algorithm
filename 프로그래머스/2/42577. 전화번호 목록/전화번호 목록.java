import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        
        Set<String> set = new HashSet<>(Arrays.asList(phone_book));
        
        for (String pnum : phone_book) {
            for (int i = 1; i < pnum.length(); i++) {
                if (set.contains(pnum.substring(0, i))) {
                    return false;
                }
            }
        
        }
        return true;
    }
}