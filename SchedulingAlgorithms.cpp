// SchedulingAlgorithms.cpp

#include "Process.h"
#include <queue>
#include <vector>
#include <algorithm>
#include <string> // Include string header for algorithm name

// Define constants for algorithm names
const std::string FCFS_ALGORITHM = "First-Come, First-Served";
const std::string SJF_NON_PREEMPTIVE_ALGORITHM = "Shortest Job First (Non-Preemptive)";
const std::string PREEMPTIVE_SJF_ALGORITHM = "Shortest Job First (Preemptive)";
const std::string SRTF_ALGORITHM = "Shortest Remaining Time First (SRTF)";
const std::string ROUND_ROBIN_ALGORITHM = "Round Robin";
const std::string PRIORITY_NON_PREEMPTIVE_ALGORITHM = "Priority Scheduling (Non-Preemptive)";
const std::string PRIORITY_PREEMPTIVE_ALGORITHM = "Priority Scheduling (Preemptive)";
// Comparison functions
bool compareArrival(const Process &a, const Process &b) {
    return a.arrival < b.arrival;
}
bool compareBurst(const Process &a, const Process &b) {
    return a.burst < b.burst;
}

bool comparePriority(const Process &a, const Process &b) {
    return a.priority > b.priority;
}

bool comparePriority2(const Process &a, const Process &b) {
    return a.priority < b.priority;
}

bool compareRemaining(const Process &a, const Process &b) {
    return a.remaining < b.remaining;
}

// Function to calculate average waiting and turnaround times
void calculateTimes(std::vector<Process>& processes, SchedulingResult& result) {
    double totalWaitingTime = 0;
    double totalTurnaroundTime = 0;

    for (auto& process : processes) {
        process.turnaround = process.finish - process.arrival;
        process.waiting = process.turnaround - process.burst;
        totalWaitingTime += process.waiting;
        totalTurnaroundTime += process.turnaround;
    }

    result.avgWaitingTime = totalWaitingTime / processes.size();
    result.avgTurnaroundTime = totalTurnaroundTime / processes.size();
}

// FCFS Scheduling
SchedulingResult fcfs(std::vector<Process> processes) {
    SchedulingResult result;
    std::sort(processes.begin(), processes.end(), compareArrival);

    int currentTime = 0;
    for (auto &p : processes) {
        if (currentTime < p.arrival) {
            currentTime = p.arrival;
        }
        p.start = currentTime;
        currentTime += p.burst;
        p.finish = currentTime;
        p.turnaround = p.finish - p.arrival;
        p.waiting = p.turnaround - p.burst;
        result.processes.push_back(p);
    }

    calculateTimes(result.processes, result);
    result.algorithm  = FCFS_ALGORITHM;
    return result;
}

// Shortest Job First (Non-Preemptive)
SchedulingResult sjfNonPreemptive(std::vector<Process> processes) {
    SchedulingResult result;
    std::sort(processes.begin(), processes.end(), compareArrival);

    int time = 0;
    std::vector<Process> readyQueue;

    for (size_t i = 0; i < processes.size(); ) {
        while (i < processes.size() && processes[i].arrival <= time) {
            readyQueue.push_back(processes[i]);
            ++i;
        }

        if (!readyQueue.empty()) {
            std::sort(readyQueue.begin(), readyQueue.end(), compareBurst);
            auto& process = readyQueue.front();
            process.start = time;
            time += process.burst;
            process.finish = time;
            result.processes.push_back(process);
            readyQueue.erase(readyQueue.begin());
        } else {
            time = processes[i].arrival;
        }
    }

    calculateTimes(result.processes, result);
    result.algorithm  = SJF_NON_PREEMPTIVE_ALGORITHM;
    return result;
}

// Shortest Job First (Preemptive)
SchedulingResult preemptiveSJF(std::vector<Process> processes) {
    SchedulingResult result;
    std::sort(processes.begin(), processes.end(), compareArrival);

    int time = 0;
    std::priority_queue<Process, std::vector<Process>, decltype(&compareRemaining)> readyQueue(compareRemaining);

    for (size_t i = 0; i < processes.size() || !readyQueue.empty(); ) {
        while (i < processes.size() && processes[i].arrival <= time) {
            readyQueue.push(processes[i]);
            ++i;
        }

        if (!readyQueue.empty()) {
            auto process = readyQueue.top();
            readyQueue.pop();
            if (process.start == -1) process.start = time;
            time += 1;
            process.remaining -= 1;
            if (process.remaining == 0) {
                process.finish = time;
                result.processes.push_back(process);
            } else {
                readyQueue.push(process);
            }
        } else {
            time = processes[i].arrival;
        }
    }

    calculateTimes(result.processes, result);
    result.algorithm  = PREEMPTIVE_SJF_ALGORITHM;
    return result;
}

// Shortest Remaining Time First (SRTF)
SchedulingResult srtf(std::vector<Process> processes) {
    return preemptiveSJF(processes);
}

// Round Robin
SchedulingResult roundRobin(std::vector<Process> processes, int timeQuantum) {
    SchedulingResult result;
    std::sort(processes.begin(), processes.end(), compareArrival);

    int time = 0;
    std::queue<Process> readyQueue;

    size_t i = 0;
    while (i < processes.size() || !readyQueue.empty()) {
        while (i < processes.size() && processes[i].arrival <= time) {
            readyQueue.push(processes[i]);
            ++i;
        }

        if (!readyQueue.empty()) {
            auto process = readyQueue.front();
            readyQueue.pop();
            if (process.start == -1) process.start = time;

            int execTime = std::min(timeQuantum, process.remaining);
            time += execTime;
            process.remaining -= execTime;

            if (process.remaining == 0) {
                process.finish = time;
                result.processes.push_back(process);
            } else {
                readyQueue.push(process);
            }
        } else {
            time = processes[i].arrival;
        }
    }

    calculateTimes(result.processes, result);
    result.algorithm  = ROUND_ROBIN_ALGORITHM;
    return result;
}
// Priority Scheduling (Non-Preemptive)
SchedulingResult priorityScheduling(std::vector<Process> processes) {
    SchedulingResult result;
    std::sort(processes.begin(), processes.end(), compareArrival);

    int currentTime = 0;
    std::vector<Process> completedProcesses;

    while (!processes.empty()) {
        auto it = std::min_element(processes.begin(), processes.end(), comparePriority);
        if (currentTime < it->arrival) {
            currentTime = it->arrival;
        }
        it->start = currentTime;
        currentTime += it->burst;
        it->finish = currentTime;
        it->turnaround = it->finish - it->arrival;
        it->waiting = it->turnaround - it->burst;
        completedProcesses.push_back(*it);
        processes.erase(it);
    }

    result.processes = completedProcesses;
    calculateTimes(result.processes, result);
    result.algorithm  = PRIORITY_NON_PREEMPTIVE_ALGORITHM;
    return result;
}



// Priority Scheduling (Preemptive)
SchedulingResult prioritySchedulingPreemptive(std::vector<Process> processes) {
    SchedulingResult result;
    std::sort(processes.begin(), processes.end(), compareArrival);

    int currentTime = 0;
    std::priority_queue<Process, std::vector<Process>, decltype(&comparePriority)> readyQueue(comparePriority);

    for (size_t i = 0; i < processes.size() || !readyQueue.empty(); ) {
        while (i < processes.size() && processes[i].arrival <= currentTime) {
            readyQueue.push(processes[i]);
            ++i;
        }

        if (!readyQueue.empty()) {
            auto process = readyQueue.top();
            readyQueue.pop();
            if (process.start == -1) {
                process.start = currentTime;
            }
            currentTime++;
            process.remaining--;

            if (process.remaining == 0) {
                process.finish = currentTime;
                result.processes.push_back(process);
            } else {
                readyQueue.push(process);
            }
        } else {
            currentTime = processes[i].arrival;
        }
    }

    calculateTimes(result.processes, result);
    result.algorithm  = PRIORITY_PREEMPTIVE_ALGORITHM;
    return result;
}

