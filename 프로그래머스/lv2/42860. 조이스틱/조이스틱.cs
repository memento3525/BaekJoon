using System;
using System.Linq;

public class Solution {
    public int solution(string name) 
    {
        int answer = int.MaxValue;
        bool[] visited = name.Select(s => s == 'A').ToArray(); // A 는 방문안해도 됨
        DFS(name, visited, 0, 0, ref answer);
        
        return answer;
    }
    
    private void DFS(string name, bool[] visited, int cur, int count, ref int answer)
    {
        if(!visited[cur]) // A 면 이미 visited이니 무시한다.
        {
            // n 위치의 알파벳을 위나 아래로 옮기는 것 중 빠른 쪽으로 맞춘다.
            int up = name[cur] - 'A'; // ▲ - 다음 알파벳
            int down = 'Z' - 'A' - up + 1; // ▼ - 이전 알파벳 (A에서 아래쪽으로 이동하면 Z로)
            count += Math.Min(up, down);

            visited[cur] = true;
        }
        
        if(visited.Count(c => !c) == 0)
        {
            if(count < answer)
                answer = count;
            
            return;
        }
        
        // ◀ - 커서를 왼쪽으로 이동
        int left = cur;
        int leftCount = 0;
        while (visited[left])
        {
            ++leftCount;
            left = left > 0 ? left - 1 : (left + name.Length - 1) % name.Length;
        }

        // ▶ - 커서를 오른쪽으로 이동
        int right = cur;
        int rightCount = 0;
        while (visited[right])
        {
            ++rightCount;
            right = right < name.Length - 1 ? right + 1 : (right + 1) % name.Length;
        }

        DFS(name, visited, left, count + leftCount, ref answer);
        visited[left] = false;
        
        DFS(name, visited, right, count + rightCount, ref answer);
        visited[right] = false;
    }
}