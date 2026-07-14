import java.util.*;
class Solution {
    Map<Long, Long> p = new HashMap<>();
    
    long find(Long x) {
        Long next = p.get(x);
        if (next != null) {
            long root = find(next);
            p.put(x, root);
            return root;
        }
        return x;
    }
    
    public boolean union(long u, long v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;

        p.put(v, u);
        return true;
    }
    
    public long[] solution(long k, long[] room_number) {
        long[] answer = new long[room_number.length];

        for (int i = 0; i < room_number.length; i++) {
            long next = find(room_number[i]);
            union(next + 1, next);
            answer[i] = next;
        }

        return answer;
    }
}