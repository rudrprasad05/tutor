// MultiThreadDemo.java
class Task1 implements Runnable {
    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println("Task1 - Count: " + i);
            try {
                Thread.sleep(500); // Pause for half a second
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("Task1 finished!");
    }
}

class Task2 implements Runnable {
    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println("Task2 - Count: " + i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("Task2 finished!");
    }
}

public class MultiThreadDemo {
    public static void main(String[] args) {
        // Create runnable objects
        Task1 t1 = new Task1();
        Task2 t2 = new Task2();

        // Create Thread objects and pass the tasks
        Thread thread1 = new Thread(t1);
        Thread thread2 = new Thread(t2);

        // Start both threads
        thread1.start();
        thread2.start();

        // Main thread work
        for (int i = 1; i <= 5; i++) {
            System.out.println("Main Thread - Count: " + i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("Main thread finished!");
    }
}
