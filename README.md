# Operating System Lab: Scheduling and System Calls

<div align="center">

![OS Lab](https://img.shields.io/badge/OS-Lab-blue?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C-green?style=for-the-badge)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-lightgrey?style=for-the-badge)

</div>

Welcome to the Operating System Lab repository! This comprehensive collection features implementations of various system calls, scheduling algorithms, memory management techniques, and deadlock avoidance strategies. Each program is designed to demonstrate core operating system concepts with robust and well-documented implementations.

## 📋 Table of Contents

- [System Calls](#system-calls)
- [Scheduling Algorithms](#scheduling-algorithms)
- [Synchronization and Memory Management](#synchronization-and-memory-management)
- [Page Replacement Algorithms](#page-replacement-algorithms)
- [Deadlock Management](#deadlock-management)
- [How to Use](#how-to-use)
- [Contributing](#contributing)

---

## 🔄 System Calls

### 🍴 Fork System Call (`1a_Fork_System_Call`)
- **Purpose:** Simulates the `fork` system call
- **Features:** Demonstrates process creation and management
- **Key Concepts:** Process duplication, parent-child relationships

### ⏳ Wait System Call (`1b_Wait_System_Call`)
- **Purpose:** Implements the `wait` system call
- **Features:** Illustrates process synchronization and termination management
- **Key Concepts:** Process states, zombie processes, parent-child synchronization

### 🚀 Exec System Call (`1c_Exec_System_Call`)
- **Purpose:** Simulates the `exec` system call
- **Features:** Showcases process execution and replacement
- **Key Concepts:** Process image replacement, program loading

## ⚡ Scheduling Algorithms

### 📊 First-Come, First-Served (FCFS) (`2a_First_come_First_Serve`)
- **Algorithm:** Non-preemptive scheduling
- **Features:** Processes executed in arrival order
- **Metrics:** Calculates completion time, turnaround time, waiting time

### 🎯 Shortest Job First (SJF) (`2b_Shortest_Job_First`)
- **Algorithm:** Non-preemptive, optimal for minimum waiting time
- **Features:** Prioritizes processes with shortest burst time
- **Advantage:** Minimizes average waiting time

### 🏆 Priority Scheduling (`3_Priority`)
- **Algorithm:** Priority-based execution
- **Features:** Processes executed based on priority levels
- **Considerations:** Handles priority inversion scenarios

### ⭕ Round Robin (RR) (`4_Round_Robin`)
- **Algorithm:** Preemptive time-sharing
- **Features:** Fixed time slices for fair CPU allocation
- **Metrics:** Generates Gantt charts and calculates all scheduling metrics

## 🔗 Synchronization and Memory Management

### 🏭 Producer-Consumer Problem (`5_Producer_Consumer`)
- **Problem:** Classic synchronization challenge
- **Solution:** Semaphore-based implementation
- **Concepts:** Mutual exclusion, buffer management

### 📦 Fixed Partition Memory Management (`6_Fixed_Partition_First_Best_Worst`)
- **Strategy:** Fixed-size memory partitions
- **Algorithms:** First Fit, Best Fit, Worst Fit
- **Features:** Memory allocation and deallocation simulation

### 🔄 Variable Partition Memory Management (`6_Variable_Partition_First_Best_Worst_Fit`)
- **Strategy:** Dynamic memory partitioning
- **Algorithms:** First Fit, Best Fit, Worst Fit
- **Advantages:** Efficient memory utilization, fragmentation handling

## 📄 Page Replacement Algorithms

### 📋 FIFO Page Replacement (`7_FIFO_Page_Replacement`)
- **Algorithm:** First-In, First-Out replacement
- **Features:** Simple and easy to implement
- **Use Case:** Basic page replacement strategy

### 🕒 LRU Page Replacement (`8_LRU_Page_Replacement`)
- **Algorithm:** Least Recently Used replacement
- **Features:** Replaces least recently accessed pages
- **Advantage:** Better performance than FIFO

## 🔒 Deadlock Management

### 🔍 Deadlock Detection (`9_Detect_DeadLock`)
- **Purpose:** Identifies deadlock situations
- **Algorithm:** Resource allocation graph analysis
- **Features:** Detects circular wait conditions

### 🏦 Banker's Algorithm (`10_Bankers_Algo_DeadLock_Avoidence`)
- **Purpose:** Deadlock avoidance strategy
- **Algorithm:** Resource allocation with safety checks
- **Features:** Safe state verification and resource request handling

---

## 🛠️ How to Use

### Prerequisites
- C compiler (GCC or any ANSI C compatible compiler)
- Terminal/Command Prompt
- Basic understanding of operating system concepts

### Compilation
```bash
# Compile any program
gcc program_name.c -o program_name

# Example for Round Robin
gcc 4_Round_Robin.c -o round_robin
```

### Execution
```bash
# Run the compiled program
./program_name

# Example
./round_robin
```

### Input Format
Most programs accept input through the command line or interactive prompts. Follow the on-screen instructions for each specific algorithm.

---

## 📊 Output Features

### Scheduling Algorithms
- **Gantt Chart:** Visual representation of process execution
- **Performance Metrics:** 
  - Completion Time (CT)
  - Turnaround Time (TAT)
  - Waiting Time (WT)
  - Response Time (RT)

### Memory Management
- **Memory Layout:** Visual representation of memory allocation
- **Fragmentation Analysis:** Internal and external fragmentation metrics
- **Allocation Statistics:** Memory utilization efficiency

---

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes, please open an issue first to discuss what you would like to change.

### Guidelines
- Follow consistent coding style
- Add appropriate comments
- Include input/output examples
- Update documentation as needed

---

## 📝 License

This project is for educational purposes as part of Operating Systems laboratory assignments.

---

<div align="center">

**🎓 Educational Repository for Operating System Concepts**

Made with ❤️ for OS Students

</div>
