#include <iostream>
#include <semaphore>
#include <vector>
#include <fstream>
#include <thread>

using namespace std;

std::counting_semaphore<1> file_semaphore(1);  // Semaphore to control file access

void filewrite(int threadID)
{
    // Acquire semaphore to ensure only one thread writes to the file at a time
    file_semaphore.acquire();

    ofstream file("output2.txt", ios::app);
    if (file.is_open())
    {
        file << threadID << endl;  // Writing thread ID to file
        file.close();
    }
    else
    {
        cout << "Error opening file" << endl;
    }

    // Release semaphore after writing to the file
    file_semaphore.release();
}

int main()
{
    thread threads[10];

    // Launch 10 threads to write to the file
    for (int i = 0; i < 10; i++)
    {
        threads[i] = thread(filewrite, i + 1);  // Correct function name here
    }

    // Wait for all threads to finish
    for (int i = 0; i < 10; i++)
    {
        threads[i].join();
    }

    return 0;
}
