class Solution {
    public long solution(int[] sequence) {
        int n = sequence.length;
        long maxSum = Long.MIN_VALUE;
        
        long[] pulse1 = new long[n];
        long[] pulse2 = new long[n];
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                pulse1[i] = sequence[i];   // (+, -, +, -, ...)
                pulse2[i] = -sequence[i];  // (-, +, -, +, ...)
            } else {
                pulse1[i] = -sequence[i];
                pulse2[i] = sequence[i];
            }
        }
        
        // 카데인 알고리즘 적용
        maxSum = Math.max(maxSubarraySum(pulse1), maxSubarraySum(pulse2));
        
        return maxSum;
    }
    
    private long maxSubarraySum(long[] arr) {
        long maxSum = arr[0];
        long currentSum = arr[0];
        
        for (int i = 1; i < arr.length; i++) {
            currentSum = Math.max(arr[i], currentSum + arr[i]);
            maxSum = Math.max(maxSum, currentSum);
        }
        
        return maxSum;
    }
}
