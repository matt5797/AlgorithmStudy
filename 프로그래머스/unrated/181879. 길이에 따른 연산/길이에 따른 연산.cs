using System;
using System.Linq;

public class Solution {
    public int solution(int[] num_list) {
        int answer = 0;
        if (num_list.Length>=11)
            Array.ForEach(num_list, i=>answer+=i);
        else
        {
            answer=1;
            Array.ForEach(num_list, i=>answer*=i);
        }
        
        return answer;
    }
}