class ThreadTest extends Thread {
	Thread t;
	String name;

	ThreadTest(String thread_name) {
		name = thread_name;
		t = new Thread(this, name);
		System.out.println("Child Thread : " + this);
		t.start();
	}

	public void run() {
		try {
			for (int i = 5; i >= 1; i--) {
				System.out.println("Child Thread: " + i);
				Thread.sleep(500);
			}
		} catch (InterruptedException e) {
			System.out.println("Child Thread Interrupted " + e);
		}
		System.out.println("Child Thread Executed");
	}
}


public class multithread {
	public static void main(String[] args) {
		new ThreadTest("thread 1");
		new ThreadTest("thread 2");
		new ThreadTest("thread 3");
		try {
			for (int i = 5; i > 0; i--) {
				System.out.println("Main Thread: " + i);
				Thread.sleep(1000);
			}
		} catch (InterruptedException e) {
			System.out.println("Main Thread Interrupted " + e);
		}
		System.out.println("Main Thread Executed");
	}
}
