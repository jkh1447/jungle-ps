import java.util.*;

class Solution {
    
    int ts = 0;
    Boolean done  = false;
    ArrayList<String> answer;
    ArrayList<Boolean> vis;
    
    void dfs(String[][] t, int cnt, ArrayList<String> path, String cur){
        if (done) return;
        
        if (ts == cnt) {
            answer = path;
            done = true;
            return;
        }
        
        for (int i=0; i<t.length; i++){
            if (!vis.get(i) && t[i][0].equals(cur)) {
                
                vis.set(i, true);
                path.add(t[i][1]);
                
                dfs(t, cnt+1, path, t[i][1]);
                if (done) return;
                vis.set(i, false);
                path.remove(path.size()-1);
                
                
            }
            
            
        }
    }
    
    
    public ArrayList<String> solution(String[][] tickets) {

        
        Arrays.sort(tickets, (o1, o2) -> {
            if (o1[0].equals(o2[0])) {
                return o1[1].compareTo(o2[1]);
            }
            return o1[0].compareTo(o2[0]);
        });
        ts = tickets.length;
        
        vis = new ArrayList<>(Collections.nCopies(ts, false));
        
        ArrayList<String> path = new ArrayList<>();
        path.add("ICN");
        dfs(tickets, 0, path, "ICN");
        
        return answer;
    }
}