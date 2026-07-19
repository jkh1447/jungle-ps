import java.util.*;

class Solution {

    ArrayList<Integer> adj = new ArrayList<>(Collections.nCopies(101, -1));
    ArrayList<Integer> vis = new ArrayList<>(Collections.nCopies(101, 0));
    
    public int solution(int[] cards) {
        for(int i=0; i<cards.length; i++) {
            adj.set(i+1, cards[i]);
        }
        ArrayList<Integer> counts = new ArrayList<>();
        for(int i=1; i<=cards.length; i++) {
            int cnt = 0;
            int cur = i;
            while(vis.get(cur) != 1) {
                vis.set(cur, 1);
                cur = adj.get(cur);
                cnt++;
            }
            counts.add(cnt);
        }
        
        counts.sort(Comparator.reverseOrder());
        
        return counts.size() == 1 ? 0 : counts.get(0) * counts.get(1);
    }
}