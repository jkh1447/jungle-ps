class Solution {
    int n, answer;
    int[] weak, dist;
    int[] extendedWeak;
    boolean[] visited;
    
    public int solution(int n, int[] weak, int[] dist) {
        this.n = n;
        this.weak = weak;
        this.dist = dist;
        this.answer = dist.length + 1;
        this.visited = new boolean[dist.length];
        
        extendedWeak = new int[weak.length * 2];
        
        for(int i=0; i<weak.length; i++){
            extendedWeak[i] = weak[i];
            extendedWeak[i + weak.length] = weak[i] + n;
        }
        
        
        for(int i=0; i<weak.length; i++){
            dfs(i, 0, 0);
        }
        
        return answer > dist.length ? -1 : answer;
    }
    
    void dfs(int start, int count, int repairedCount) {
        
        if (count >= answer) return;
        
        if (repairedCount >= weak.length) {
            answer = Math.min(answer, count);
            return;
        }
        
        
        for (int i=0; i<dist.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                
                int currentCover = extendedWeak[start] + dist[i];
                int nextRepaired = 0;
                
                while (start + nextRepaired < extendedWeak.length &&
                      extendedWeak[start + nextRepaired] <= currentCover) {
                    nextRepaired++;
                }
                
                dfs(start + nextRepaired, count + 1, repairedCount + nextRepaired);
                
                visited[i] = false;
                
            }
        }
    }
}