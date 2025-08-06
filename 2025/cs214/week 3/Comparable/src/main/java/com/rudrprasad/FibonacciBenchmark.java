package com.rudrprasad;

public class FibonacciBenchmark {
    public static void main(String[] args) {
        int[] testValuesIterative = {5, 10, 15, 20, 30, 40, 50, 100, 500, 1000};
        int[] testValuesRecursive = {5, 10, 15, 20, 30, 40}; // Avoid large n

        FibonacciIterative fibIter = new FibonacciIterative();
        FibonacciRecursive fibRec = new FibonacciRecursive();

        System.out.println("== Iterative Fibonacci Timing ==");
        for (int n : testValuesIterative) {
            long start = System.nanoTime();
            long result = fibIter.compute(n);
            long end = System.nanoTime();
            System.out.printf("n = %d, result = %d, time = %d ns%n", n, result, (end - start));
        }

        System.out.println("\n== Recursive Fibonacci Timing ==");
        for (int n : testValuesRecursive) {
            long start = System.nanoTime();
            long result = fibRec.compute(n);
            long end = System.nanoTime();
            System.out.printf("n = %d, result = %d, time = %d ns%n", n, result, (end - start));
        }
    }
}
