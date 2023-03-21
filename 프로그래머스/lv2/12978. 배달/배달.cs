using System;
using System.Collections.Generic;
using System.Linq;

class Solution // 다익스트라.
{
    public int solution(int N, int[,] road, int K)
    {
        // 거리 초기화
        int[,] map = new int[N, N];
        for(int i = 0; i < N; ++i)
        {
            for(int k = 0; k < N; ++k)
                map[i, k] = int.MaxValue;
        }
        for(int i = 0; i < road.GetLength(0); ++i)
        {
            int a = road[i, 0] - 1;
            int b = road[i, 1] - 1;
            int dist = road[i, 2];

            if(dist < map[a, b])
                map[a, b] = map[b, a] = dist;
        }

        // 경로 찾기 전 초기화
        var times = new int[N];
        var visit = new bool[N];
        for(int i = 0; i < N; ++i)
            times[i] = map[0, i];

        times[0] = 0; 
        visit[0] = true; 

        // 경로 찾기. 최초 시작위치에서 한개씩 확정짓기 때문에 시작노드를 제외한 N-1
        for(int repeat = 0; repeat < N - 1; ++repeat)
        {
            int now = -1;
            int min = int.MaxValue;
            // 아직 방문하지 않은 노드 중 최단거리 찾기
            for(int j = 0; j < N; ++j)
            {
                if(visit[j]) continue;
                if(times[j] == int.MaxValue) continue;
                if(times[j] >= min) continue;
                
                min = times[j];
                now = j;
            }

            visit[now] = true;

            for(int k = 0; k < N; ++k)
            {
                if(visit[k]) continue;
                if(map[now, k] == int.MaxValue) continue;

                // 직접 가는거보다 다른경로를 거쳐서 도달하는게 더 빠르면
                if(times[k] > times[now] + map[now, k]) 
                    times[k] = times[now] + map[now, k];
            }
        }

        return times.Count(c => c <= K);
    }
}