// SchedulingSelector.cpp

#include "Process.h"
#include "SchedulingAlgorithms.cpp"

SchedulingResult selectBestAlgorithm(std::vector<Process> processes) {
    std::vector<SchedulingResult> results;

    results.push_back(fcfs(processes));
    results.push_back(sjfNonPreemptive(processes));
    results.push_back(preemptiveSJF(processes));
    results.push_back(srtf(processes));
    results.push_back(roundRobin(processes, 2)); // Example time quantum
    results.push_back(priorityScheduling(processes));
    results.push_back(prioritySchedulingPreemptive(processes));

    // Example criteria: select algorithm with the lowest average waiting time
    auto bestResult = std::min_element(results.begin(), results.end(), [](const SchedulingResult& a, const SchedulingResult& b) {
        return a.avgWaitingTime < b.avgWaitingTime;
    });

    return *bestResult;
}

std::vector<SchedulingResult> compareAlgorithms(std::vector<Process> processes) {
    std::vector<SchedulingResult> results;

    results.push_back(fcfs(processes));
    results.push_back(sjfNonPreemptive(processes));
    results.push_back(preemptiveSJF(processes));
    results.push_back(srtf(processes));
    results.push_back(roundRobin(processes, 2)); // Example time quantum
    results.push_back(priorityScheduling(processes));
    results.push_back(prioritySchedulingPreemptive(processes));

    return results;
}
