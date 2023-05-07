using System;

class Solution
{
    public int solution(int n, int[] stations, int w)
    {
        int answer = 0;
        int width = (w * 2 + 1);
        
        // station을 순회하면서 station의 범위에 닿지않은 chunk를 범위로 나눠준다.
        int index = 1;
        foreach(int s in stations)
        {
            int chunkCount = (s - w) - index;
            if(chunkCount > 0)
            {
                answer += chunkCount / width;
                answer += chunkCount % width > 0 ? 1 : 0;
            }

            index = s + w + 1; // 전파 범위가 끝나는 지점으로 밀어준다.
        }
        
        // 루프가 끝난 후에 끝단에 남아있는 청크를 처리한다.
        int ramain = n + 1 - index;
        if(ramain > 0)
        {
            answer += ramain / width;
            answer += ramain % width > 0 ? 1 : 0;
        }
        
        return answer;
    }
}