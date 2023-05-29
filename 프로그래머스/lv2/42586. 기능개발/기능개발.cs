using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        List<int> temp = new List<int>();
        Queue<int> pool = new Queue<int>();
        
        for (int i=0; i<speeds.Length; i++)
        {
            pool.Enqueue(i);
        }
        
        while (pool.Count>0)
        {
            int cnt = 0;
            foreach( int work in pool )
            {
                progresses[work] += speeds[work];
            }
            while (pool.Count>0 && progresses[pool.Peek()]>=100)
            {
                pool.Dequeue();
                cnt++;
            }
            if (cnt>0)
            {
                temp.Add(cnt);
            }
        }
        
        int[] answer = temp.ToArray();
        
        return answer;
    }
}