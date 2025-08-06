package com.rudrprasad;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) {
        PriorityQueue<Student> studentPQ = new PriorityQueue<>();

        Student s;
        //filling PQ
        for (int i = 1; i < 10; i++) {
            int heads = (int)(Math.random() * 2);
            String addr = heads == 0 ? "Mr. " : "Ms. ";

            s = new Student(i, addr + Integer.toString(i),i%4);
            studentPQ.add(s);
        }

        System.out.println("The list of students (not in any particular order):");
        System.out.println(studentPQ);

        System.out.println("The winner is: " + studentPQ.remove());

        //dequeue (NOT needed)
        while (!studentPQ.isEmpty()) {
            System.out.println(studentPQ.remove());
        }

    }
}
