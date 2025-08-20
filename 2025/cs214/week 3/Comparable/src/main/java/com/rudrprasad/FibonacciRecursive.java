package com.rudrprasad;

public class FibonacciRecursive {
    public long compute(int n) {
        if (n <= 1) return n;
        // counter
        return compute(n - 1) + compute(n - 2);
    }
}
