using System;

public class Solution {
    public int solution(int[] num_list) {
        int i = 0;
        for(i=0; i<num_list.Length; i++)
            if (num_list[i]<0)
                break;
        
        if (i==num_list.Length) return -1;
        return i;
    }
}