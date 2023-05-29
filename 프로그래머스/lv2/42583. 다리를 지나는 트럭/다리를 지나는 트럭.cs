using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        Queue<int> truck_queue = new Queue<int>();
        Queue<int> road_weight = new Queue<int>();
        Queue<int> road_time = new Queue<int>();
        int total_weight = 0;
        int truck_weight;
        int time = 0;
        int out_time;
        
        foreach (int truck in truck_weights)
        {
            truck_queue.Enqueue(truck);
        }
        
        while(truck_queue.Count > 0 || road_weight.Count > 0)
        {
            time += 1;
            
            if (road_time.Count > 0 && road_time.Peek()<=time)
            {
                road_time.Dequeue();
                total_weight -= road_weight.Dequeue();
            }
            
            if (truck_queue.Count>0 && total_weight + truck_queue.Peek() <= weight)
            {
                truck_weight = truck_queue.Dequeue();
                total_weight += truck_weight;
                road_weight.Enqueue(truck_weight);
                road_time.Enqueue(time + bridge_length);
            }
        }
        
        int answer = time;
        return answer;
    }
}