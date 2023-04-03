using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public long solution(int[] weights) 
    {
        Array.Sort(weights);
        long answer = 0;
        
        // dictionary에 모든 무게를 넣음
        var dict = weights.GroupBy(g => g).ToDictionary(d => d.Key, d => d.Count());
        var matchWeight = new HashSet<int>();
        for(int i = 0; i < weights.Length; ++i)
        {
            // 조합으로 (2, 3), (2, 4), (3, 4)가 나올 수 있다. 거리가 같은경우는 제외
            int cur = weights[i];
            if(cur % 3 == 0)
            {
                if(dict.TryGetValue(cur * 2 / 3, out int value1))
                    answer += value1;
            }
            
            if(cur % 2 == 0)
            {
                if(dict.TryGetValue(cur / 2, out int value2)) // 원래 2 / 4
                    answer += value2;

                if(cur % 4 == 0)
                {
                    if(dict.TryGetValue(cur * 3 / 4, out int value3))
                        answer += value3;
                }
            }
        }

        // 몸무게가 같은 경우는 그냥 조합 개수 공식으로 구하면 된다. nC2
        long sameWeight = dict.Values.Where(w => w > 1).Sum(s => (long)s * (s - 1) / 2);
        return answer + sameWeight;
    }
}