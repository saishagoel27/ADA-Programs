#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool compareJobs(Job a, Job b) {
    return a.profit > b.profit;
}

void jobScheduling(Job jobs[], int n) {
    // Sort jobs by profit (descending)
    sort(jobs, jobs + n, compareJobs);
    
    cout << "\nJobs after sorting by profit:\n";
    cout << "ID\tDeadline\tProfit\n";
    for (int i = 0; i < n; i++) {
        cout << jobs[i].id << "\t" << jobs[i].deadline << "\t\t" << jobs[i].profit << "\n";
    }
    
    // Find maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }
    
    // Create slots array
    int slots[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        slots[i] = -1;  // -1 means empty slot
    }
    
    int totalProfit = 0;
    int jobCount = 0;
    
    // Schedule jobs
    for (int i = 0; i < n; i++) {
        // Find free slot from deadline-1 to 0
        for (int j = min(maxDeadline, jobs[i].deadline) - 1; j >= 0; j--) {
            if (slots[j] == -1) {  // If slot is free
                slots[j] = i;
                totalProfit += jobs[i].profit;
                jobCount++;
                break;
            }
        }
    }
    
    // Print results
    cout << "\n--- Scheduled Jobs ---\n";
    cout << "Time Slot\tJob ID\tProfit\n";
    for (int i = 0; i < maxDeadline; i++) {
        if (slots[i] != -1) {
            cout << (i + 1) << "\t\t" << jobs[slots[i]].id 
                 << "\t" << jobs[slots[i]].profit << "\n";
        }
    }
    
    cout << "\nTotal Jobs Scheduled: " << jobCount << "\n";
    cout << "Maximum Total Profit: " << totalProfit << "\n";
}

int main() {
    srand(time(0));  // Seed for random number generation
    
    int counter = 5;  // Run 5 times
    
    cout << "========================================\n";
    cout << "   JOB SCHEDULING WITH DEADLINES\n";
    cout << "========================================\n";
    
    while (counter > 0) {
        int n;
        cout << "\n\n>>> RUN " << (6 - counter) << " <<<\n";
        cout << "Enter number of jobs: ";
        cin >> n;
        
        Job jobs[n];
        
        // Generate random jobs
        cout << "\nGenerated Jobs:\n";
        cout << "ID\tDeadline\tProfit\n";
        for (int i = 0; i < n; i++) {
            jobs[i].id = 'A' + i;
            jobs[i].deadline = (rand() % n) + 1;  // Random deadline between 1 and n
            jobs[i].profit = (rand() % 100) + 1;  // Random profit between 1 and 100
            cout << jobs[i].id << "\t" << jobs[i].deadline 
                 << "\t\t" << jobs[i].profit << "\n";
        }
        
        // ⏱️ START TIMING
        auto start = high_resolution_clock::now();
        
        jobScheduling(jobs, n);
        
        auto stop = high_resolution_clock::now();
        // ⏱️ STOP TIMING
        
        auto duration = duration_cast<microseconds>(stop - start);
        
        cout << "\n⏱️ TIME TAKEN: " << duration.count() << " microseconds\n";
        cout << "========================================\n";
        
        counter--;
    }
    
    cout << "\nALL RUNS COMPLETED!\n";
    cout << "Now use the time data to create your graph.\n";
    
    return 0;
}
