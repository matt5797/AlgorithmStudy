using System;

public class Solution {
    public int[] solution(int[] arr, int k) {
        for (int i=0; i<arr.Length; i++)
        {
            arr[i] = (k%2==0)? arr[i]+k: arr[i]*k;
        }
        
        return arr;
    }
}