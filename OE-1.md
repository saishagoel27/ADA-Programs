 **EXPERIMENT 1: Job Scheduling with Deadlines (Greedy Approach)**

Aim: Implement Job Scheduling Problem with Deadlines using Greedy Method to maximize profit.

Theory:
The Job Scheduling Problem involves selecting jobs to maximize total profit, where each job has:

A deadline (by when it must finish)
A profit (reward for completing it)

Each job takes 1 unit of time. We use a Greedy approach: sort jobs by profit (highest first), then schedule each job as late as possible before its deadline.
Real-world Applications:

Project management (completing high-priority tasks)
CPU task scheduling
Meeting/event planning
Production scheduling in factories

Time Complexity:
Best, Average, Worst Case: O(n²) where n = number of jobs


Algorithm:

1. Read number of jobs n
2. For each job, input: job ID, deadline, profit
3. Sort all jobs in descending order of profit (highest profit first)
4. Create a time slots array slots[] initialized to -1 (empty slots)
5. For each job in sorted order:
Find a free slot from min(deadline-1, n-1) down to 0
If free slot found, assign job to that slot
Add profit to total
6. Print scheduled jobs and total profit

Graph: Time Complexity Analysis of Job Scheduling (Greedy Approach)

Observation:
The graph shows the relationship between the number of jobs (n) and 
the time taken to schedule them using the Greedy algorithm. 

As the number of jobs increases from 10 to 1000, the execution time 
increases from approximately 1500 microseconds to 12000 microseconds.

The curve demonstrates O(n²) time complexity behavior, which matches 
the theoretical analysis of the Job Scheduling algorithm that uses 
sorting (O(n log n)) followed by slot finding (O(n²)).

Conclusion:
The algorithm performs efficiently for practical job scheduling 
scenarios with reasonable input sizes.

