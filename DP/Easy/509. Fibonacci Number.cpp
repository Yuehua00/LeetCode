// Problem : https://leetcode.com/problems/fibonacci-number/description/
// Fibonacci

class Solution {
public:
    int arr[30+5];
    int fib(int n) {
        if(arr[n]) return arr[n];
        if(n == 0) return arr[0] = 0;
        if(n == 1) return arr[1] = 1;
        
        return arr[n] = fib(n-1) + fib(n-2);
    }
};
