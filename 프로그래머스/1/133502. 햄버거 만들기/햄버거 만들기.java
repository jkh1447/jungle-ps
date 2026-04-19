import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[] ingredient) {
        int answer = 0;
        
        ArrayList<Integer> list = new ArrayList<>();
        
        for(int i=0; i<ingredient.length; i++){
            int cur = ingredient[i];            
            list.add(cur);
            int size = list.size();
            if (size >= 4) {
                if (list.get(size-1) == 1 &&
               list.get(size-2) == 3 &&
               list.get(size-3) == 2 &&
               list.get(size-4) == 1) {
                
                for(int j=0; j<4; j++) {
                    list.remove(list.size() - 1);
                   
                }
                     answer++;   
            }
            }
            
        }
        
        return answer;
    }
}