using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] num_list) {
        Array.Sort(num_list);
        return num_list.Skip(5).ToArray();
    }
}