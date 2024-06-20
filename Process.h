#ifndef PROCESS_H
#define PROCESS_H

#include <vector>

struct Process {
    int pid;        // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time
    int remaining;  // Remaining burst time
    int priority;   // Priority
    int start = -1; // Start time
    int finish = -1;// Finish time
    int waiting = 0;// Waiting time
    int turnaround = 0; // Turnaround time
    int completion = 0; // Completion time

    Process(int p, int a, int b, int pr = 0)
        : pid(p), arrival(a), burst(b), remaining(b), priority(pr) {}
};

#include <string> // Include this header for std::string

struct SchedulingResult {
    std::vector<Process> processes; // Vector of processes with scheduling details
    double avgWaitingTime; // Average waiting time of all processes
    double avgTurnaroundTime; // Average turnaround time of all processes
    std::string algorithm; // Identifier for the scheduling algorithm used
};


#endif // PROCESS_H


