import java.util.*;

class Solution {
    
    class Node implements Comparable<Node> {
        int x, y, dir, w;
        
        public Node(int x, int y, int dir, int w) {
            this.x = x;
            this.y = y;
            this.dir = dir;
            this.w = w;
        }
        
        @Override
        public int compareTo(Node o) {
            return Integer.compare(this.w, o.w);
        }
    }
    
    int[] dx = {1, 0, -1, 0};
    int[] dy = {0, 1, 0, -1};
    int INF = (int)1e9;
    
    public int solution(int[][] board) {
        int n = board.length;
        
        int[][][] dist = new int[n][n][4];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                Arrays.fill(dist[i][j], INF);
            }
        }
        dist[0][0][0] = 0;
        
        PriorityQueue<Node> pq = new PriorityQueue<Node>();
        pq.add(new Node(0, 0, 0, 0));
        
        while(!pq.isEmpty()) {
            Node cur = pq.poll();
            if (dist[cur.x][cur.y][cur.dir] != cur.w) continue;

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (board[nx][ny] == 1) continue;

                if ((cur.x == 0 && cur.y == 0) || dir == cur.dir) {
                    if (dist[nx][ny][dir] > dist[cur.x][cur.y][cur.dir] + 100) {
                        dist[nx][ny][dir] = dist[cur.x][cur.y][cur.dir] + 100;
                        pq.add(new Node(nx, ny, dir, dist[nx][ny][dir]));
                    }
                } 

                else {
                    if (dist[nx][ny][dir] > dist[cur.x][cur.y][cur.dir] + 500 + 100) {
                        dist[nx][ny][dir] = dist[cur.x][cur.y][cur.dir] + 500 + 100;
                        pq.add(new Node(nx, ny, dir, dist[nx][ny][dir]));
                    }
                }
            }
        }
        
        int answer = INF;
        for (int i = 0; i < 4; i++) {
            answer = Math.min(answer, dist[n - 1][n - 1][i]);
        }
        
        return answer;
    }
}