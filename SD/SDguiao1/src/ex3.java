import java.lang.Thread;
import java.util.concurrent.locks.ReentrantLock;

class ConcurrentBank {

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

    //Reentrant lock
    private ReentrantLock lock = new ReentrantLock();

    // Account balance
    public int balance() {
        lock.lock();
        try {
            return savings.balance();
        } finally {
            lock.unlock();
        }
    }

    // Deposit
    boolean deposit(int value) {
        lock.lock();
        try {
            return savings.deposit(value);
        } finally {
            lock.unlock();
        }
    }
}

class ConcurrentDepositer implements Runnable {
    private ConcurrentBank b;

    ConcurrentDepositer (ConcurrentBank b) {this.b = b;}

    public void run() {
        for (int j = 0; j<1000; j++) {
            b.deposit(100);
        }
    }
}

public class ex3 {
    public static void main(String args[]) {
        final int N = 10;
        final int I = 1000;
        final int V = 100;
        ConcurrentBank b = new ConcurrentBank();
        Thread threads[] = new Thread[N];


        for (int i = 0; i < N; i++) {
            threads[i] = new Thread(new ConcurrentDepositer(b));
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

