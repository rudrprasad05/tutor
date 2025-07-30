import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class CallCenter {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Queue<String> callQueue = new LinkedList<>();
        String input;

        System.out.println("📞 ANZ Call Centre Simulation Started...");

        while (true) {
            // Display menu options
            System.out.println("\nSelect an option:");
            System.out.println("1. New Call");
            System.out.println("2. Serve Call");
            System.out.println("3. View Queue");
            System.out.println("4. Caller Hang Up");
            System.out.println("5. Exit");

            System.out.print("Your choice: ");
            input = scanner.nextLine();

            switch (input) {
                case "1":
                    System.out.print("Enter Caller Name: ");
                    String caller = scanner.nextLine();
                    callQueue.offer(caller);
                    System.out.println("📞 " + caller + " added to the queue.");
                    break;

                case "2":
                    if (!callQueue.isEmpty()) {
                        System.out.println("🎧 Now serving: " + callQueue.poll());
                    } else {
                        System.out.println("⚠️  No callers in the queue.");
                    }
                    break;

                case "3":
                    if (callQueue.isEmpty()) {
                        System.out.println("📭 Queue is currently empty.");
                    } else {
                        System.out.println("📋 Current Queue: " + callQueue);
                    }
                    break;

                case "4":
                    System.out.print("Enter Caller Name to remove: ");
                    String nameToRemove = scanner.nextLine();
                    if (callQueue.remove(nameToRemove)) {
                        System.out.println("☎️ " + nameToRemove + " has hung up and was removed from the queue.");
                    } else {
                        System.out.println("❌ Caller not found in the queue.");
                    }
                    break;

                case "5":
                    System.out.println("✅ Simulation ended. Goodbye!");
                    scanner.close();
                    return;

                default:
                    System.out.println("⚠️ Invalid option. Please try again.");
            }
        }
    }
}