
# CPU Scheduler using Qt

## Project Description

This project involves implementing a CPU scheduler that uses various scheduling algorithms, such as First Come, First Serve (FCFS), Shortest Job First (SJF), Shortest Remaining Time First (SRTF), Round Robin (RR), Priority Scheduling (Preemptive), and Priority Scheduling (Non-Preemptive). The scheduler simulates the execution of processes and calculates performance metrics, such as average waiting time and average turnaround time. Additionally, the project includes a graphical user interface (GUI) developed using the Qt framework, allowing users to interact with the scheduler.
## How to Run the Project

### Dependencies

- Qt framework (version 6 or later)
- C++ compiler

### Installation Steps

1. **Clone the Repository: **
   ```bash
   git clone https://github.com/yourusername/cpu-scheduler-qt 
   ```

2. **Build the Project: **
   - Open Qt Creator and select "Open Project."
   - Navigate to the project directory and open the `cpu-scheduler-qt. Pro` file.
   - Configure the project for your development environment.
   - Build the project by clicking on the build button in Qt Creator.

3. **Run the Application: **
   - Once the project is successfully built, run the executable file generated by the build process.

## Internal Working of the Project

### Classes and Data Structures

- **Process Class: ** Represents a process with attributes such as process ID, arrival time, burst time, remaining time, priority, start time, finish time, waiting time, and turnaround time.
- **SchedulingResult Struct: ** Contains a vector of Process objects representing the scheduled processes and the calculated average waiting time and average turnaround time.

### Algorithms Implementation
Please find the revised text below:

- FCFS: Processes are executed in the order they arrive.
- SJF: The process with the shortest burst time is executed next.
- SRTF: Similar to SJF, the process with the shortest remaining time is executed.
- RR: Processes are executed in a circular manner with a fixed time quantum.
- Priority Scheduling (Preemptive): Processes with the highest priority are executed first, and a new process can preempt a currently executing process if it has a higher priority.
- Priority Scheduling (Non-Preemptive): Similar to preemptive priority scheduling, a new process cannot preempt a currently executing process.

### GUI Implementation

- **MainWindow Class: ** Implements the application's main window with buttons for adding processes, selecting scheduling algorithms, and displaying the scheduling results.
- **ProcessTable Widget: ** Displays the list of processes with their attributes.
- **OutputText Widget: ** Displays the output, including the scheduling results and performance metrics.
- **ComparisonChart Widget: ** Displays a chart comparing the performance of different scheduling algorithms.

## Learning Takeaways
- Proficiency in using the Qt framework for GUI development.
- Understanding CPU scheduling algorithms and their implementation.
- Experience with C++ programming, data structures, and algorithms in real-world applications.

## Resources/References

- [Qt Documentation](https://doc.qt.io/qt-6/index.html)
- [GeeksforGeeks - CPU Scheduling](https://www.geeksforgeeks.org/cpu-scheduling-in-operating-systems/)
- [Introduction to scheduling algorithms]( https://www.youtube.com/playlist?list=PLBlnK6fEyqRitWSE_AyyySWfhRgyA-rHk/)
- [Basic scheduling terminology](https://ravipatel1309.github.io/CPUScheduler/docs.html/)