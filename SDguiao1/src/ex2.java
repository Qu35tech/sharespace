import java.lang.Thread;
import java.util.concurrent.locks.ReentrantLock;

class Bank {

    private static class Account {
        private int balance;
        Account(int balance) { this.balance = balance; }
        int balance() { return balance; }
        boolean deposit(int value) {
            balance += value;
            return true;
        }
    }

    // Our single account, for now
    private Account savings = new Account(0);

    // Account balance
    public int balance() {
        return savings.balance();
    }

    // Deposit
    boolean deposit(int value) {
        return savings.deposit(value);
    }
}

class Depositer implements Runnable {
    private Bank b;

    Depositer (Bank b) {this.b = b;}

    public void run() {
        for (int j = 0; j<1000; j++) {
            b.deposit(100);
        }
    }
}

public class ex2 {
    public static void main(String args[]) {
        final int N = 10;
        final int I = 1000;
        final int V = 100;
        Bank b = new Bank();
        Thread threads[] = new Thread[N];


        for (int i = 0; i < N; i++) {
            threads[i] = new Thread(new Depositer(b));
        }

        for (int i = 0; i < N; i++) {
            threads[i].start();
        }

        for (int i = 0; i < N; i++) {
            try {
                threads[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        System.out.println(b.balance());
    }
}
