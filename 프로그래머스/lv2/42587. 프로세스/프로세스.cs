using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int[] priorities, int location) {
        Queue<int> queue = new Queue<int>();
        int waiting;
        bool is_max = true;
        int cnt=1;
        
        foreach (int priority in priorities)
        {
            queue.Enqueue(priority);
        }
        
        while(queue.Count>0)
        {
            waiting = queue.Dequeue();
            location--;
            
            foreach (int value in queue)
            {
                if (value>waiting)
                {
                    is_max = false;
                    break;
                }
            }
            
            if (!is_max)
            {
                queue.Enqueue(waiting);
                if (location<0)
                {
                    location = queue.Count-1;
                }
            }
            else 
            {
                if (location<0)
                {
                    return cnt;
                }
                cnt++;
            }
            is_max = true;
        }
        return 0;
    }
}