using System;
using System.Collections.Generic;

class Solution { // 최단거리는 BFS가 유리.
    public int solution(int[,] maps) {
        
        int w = maps.GetLength(0);
        int h = maps.GetLength(1);
        
        var open = new Queue<(int x, int y)>();
        var parents = new Dictionary<(int x, int y), (int x, int y)>(); 
        var dirs = new (int x, int y)[4]{(-1, 0), (1, 0), (0, -1), (0, 1)};
        
        open.Enqueue((0, 0));
        maps[0, 0] = 0;
        bool found = false;
        
        while(open.Count > 0)
        {
            (int x, int y) cur = open.Dequeue();
            if(cur.x == w - 1 && cur.y == h - 1) // 도달!
            {
                found = true;
                break;
            }
            
            foreach((int x, int y) dir in dirs)
            {
                (int x, int y) p = (cur.x + dir.x, cur.y + dir.y);
                
                if(p.x < 0 || p.x >= w || p.y < 0 || p.y >= h)
                    continue;
                
                if(maps[p.x, p.y] != 1)
                    continue;
                
                parents[p] = cur;
                open.Enqueue(p);
                maps[p.x, p.y] = 0;
            }
        }
        
        if(found)
        {
            int length = 0;
            (int x, int y) cur = parents[(w - 1, h - 1)];
            while(!(cur.x == 0 && cur.y == 0))
            {
                cur = parents[cur];
                length++;
            }
            length += 2; // 시작과 끝 더함
            return length;
        }
        else
        {
            return -1;
        }
    }
}