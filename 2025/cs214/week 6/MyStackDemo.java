import java.util.Arrays;

class MyStack<T> implements Cloneable {
    private Object[] elements;
    private int top;
    private int capacity;

    // Constructor
    public MyStack(int capacity) {
        this.capacity = capacity;
        elements = new Object[capacity];
        top = -1;
    }

    // Push element
    public void push(T item) {
        if (top == capacity - 1) {
            throw new RuntimeException("Stack Overflow!");
        }
        elements[++top] = item;
    }

    // Pop element
    @SuppressWarnings("unchecked")
    public T pop() {
        if (isEmpty()) {
            throw new RuntimeException("Stack Underflow!");
        }
        return (T) elements[top--];
    }

    // Peek
    @SuppressWarnings("unchecked")
    public T peek() {
        if (isEmpty()) {
            throw new RuntimeException("Stack is empty!");
        }
        return (T) elements[top];
    }

    // Empty check
    public boolean isEmpty() {
        return top == -1;
    }

    // Size
    public int size() {
        return top + 1;
    }

    // Display
    public void display() {
        if (isEmpty()) {
            System.out.println("Stack is empty.");
        } else {
            System.out.print("Stack contents: ");
            for (int i = 0; i <= top; i++) {
                System.out.print(elements[i] + " ");
            }
            System.out.println();
        }
    }

    // ✅ Clone method
    @Override
    public MyStack<T> clone() {
        try {
            MyStack<T> copy = (MyStack<T>) super.clone();
            copy.elements = Arrays.copyOf(this.elements, this.capacity);
            return copy;
        } catch (CloneNotSupportedException e) {
            throw new AssertionError();
        }
    }
}

public class MyStackDemo {
    public static void main(String[] args) {
        // Q1: Stack of Integers
        MyStack<Integer> intStack = new MyStack<>(10);
        intStack.push(11);
        intStack.push(25);
        intStack.push(89);
        System.out.println("Integer Stack:");
        intStack.display();

        // Q2: Stack of Strings
        MyStack<String> stringStack = new MyStack<>(10);
        stringStack.push("I");
        stringStack.push("Love");
        stringStack.push("Java");
        System.out.println("\nString Stack:");
        stringStack.display();

        // Q3: Clone the stack
        MyStack<String> clonedStack = stringStack.clone();
        System.out.println("\nCloned String Stack:");
        clonedStack.display();

        // Prove clone works independently
        clonedStack.pop(); // remove "Java" from clone
        System.out.println("\nAfter popping from cloned stack:");
        System.out.print("Original Stack -> ");
        stringStack.display();
        System.out.print("Cloned Stack -> ");
        clonedStack.display();
    }
}
