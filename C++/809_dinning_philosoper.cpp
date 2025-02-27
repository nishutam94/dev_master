#include <iostream>
#include <thread>
#include <mutex>

#define N 5
#define LEFT(i) ((i + N - 1) % N)
#define RIGHT(i) ((i + 1) % N)
#define THINKING 0
#define HUNGRY 1
#define EATING 2

using namespace std;

int status[N];         // Array to track philosopher status
mutex spoon[N];        // Mutex for each fork
mutex mtx;          // Mutex for shared mtx

void thinking(int i) {
    status[i] = THINKING;
    cout << "Philosopher " << i << " is thinking.\n";
    this_thread::sleep_for(chrono::milliseconds(500)); // Simulate thinking
}

void Test(int i) {
    if (status[i] == HUNGRY && status[LEFT(i)] != EATING && status[RIGHT(i)] != EATING) {
        status[i] = EATING;
        cout << "Philosopher " << i << " is eating.\n";
        spoon[i].unlock(); // Allow philosopher to eat
    }
}

void takefork(int i) {
    mtx.lock();
    status[i] = HUNGRY;
    cout << "Philosopher " << i << " is hungry.\n";
    Test(i);
    mtx.unlock();
    spoon[i].lock(); // Wait until forks are available
}

void putfork(int i) {
    mtx.lock();
    status[i] = THINKING;
    cout << "Philosopher " << i << " finished eating and put down forks.\n";
    Test(LEFT(i));  // Check if left neighbor can eat
    Test(RIGHT(i)); // Check if right neighbor can eat
    mtx.unlock();
}

void dining_phil(int i) {
    while (true) {
        thinking(i);
        takefork(i);
        this_thread::sleep_for(chrono::milliseconds(1000)); // Simulate eating
        putfork(i);
    }
}

int main() {
    thread philosophers[N];

    for (int i = 0; i < N; i++) {
        spoon[i].lock(); // Initially, forks are unavailable
        philosophers[i] = thread(dining_phil, i);
    }

    for (int i = 0; i < N; i++) {
        philosophers[i].join();
    }

    return 0;
}
