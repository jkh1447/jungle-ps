import java.util.*;

class Solution {
    public int[] solution(String s) {
        int[] answer = {};
        
        int zero = 0;
        int time = 0;
        
        StringBuilder sb = new StringBuilder();
        
        while(!s.equals("1")) {
            sb.setLength(0);
            
            for(int i=0; i<s.length(); i++){
                if (s.charAt(i) == '0') {
                    zero++;
                }
                else {
                    sb.append('1');
                }
            }
            
            int c = sb.length();
            
            s = Integer.toBinaryString(c);
            time++;
        }

        return new int[]{time, zero};
    }
}