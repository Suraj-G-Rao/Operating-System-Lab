# Operating System Lab: Scheduling and System Calls

Welcome to the Operating System Lab repository! This collection features implementations of various system calls and scheduling algorithms, as well as memory management and deadlock avoidance techniques. Each program is designed to demonstrate core concepts in operating systems with comprehensive and robust implementations.

## Contents

### System Calls

- **Fork System Call (`1a_Fork_System_Call`):**
  - Simulates the `fork` system call, demonstrating process creation and management.

- **Wait System Call (`1b_Wait_System_Call`):**
  - Implements the `wait` system call, illustrating process synchronization and management of process termination.

- **Exec System Call (`1c_Exec_System_Call`):**
  - Simulates the `exec` system call, showcasing process execution and replacement.

### Scheduling Algorithms

- **First-Come, First-Served (FCFS) (`2a_First_come_First_Serve`):**
  - Implements the FCFS scheduling algorithm, where processes are executed in the order they arrive.

- **Shortest Job First (SJF) (`2b_Shortest_Job_First`):**
  - Demonstrates the SJF scheduling algorithm, prioritizing processes with the shortest burst time.

- **Priority Scheduling (`3_Priority`):**
  - Implements the Priority Scheduling algorithm, where processes are executed based on their priority levels.

- **Round Robin (RR) (`4_Round_Robin`):**
  - Features the Round Robin scheduling algorithm, providing time-sharing for processes with fixed time slices.

### Synchronization and Memory Management

- **Producer-Consumer Problem (`5_Producer_Consumer`):**
  - Implements a solution to the Producer-Consumer problem, demonstrating synchronization using semaphores.

- **Fixed Partition Memory Management (`6_Fixed_Partition_First_Best_Worst`):**
  - Simulates fixed partition memory allocation using First Fit, Best Fit, and Worst Fit strategies.

- **Variable Partition Memory Management (`6_Variable_Partition_First_Best_Worst_Fit`):**
  - Implements variable partition memory allocation with First Fit, Best Fit, and Worst Fit strategies.

### Page Replacement Algorithms

- **FIFO Page Replacement (`7_FIFO_Page_Replacement`):**
  - Demonstrates the FIFO page replacement algorithm for managing memory pages.

- **LRU Page Replacement (`8_LRU_Page_Replacement`):**
  - Implements the LRU page replacement algorithm, which replaces the least recently used pages.

### Deadlock Management

- **Deadlock Detection (`9_Detect_DeadLock`):**
  - Features a deadlock detection algorithm to identify deadlock situations in process scheduling.

- **Banker's Algorithm for Deadlock Avoidance (`10_Bankers_Algo_DeadLock_Avoidence`):**
  - Implements the Banker's Alg
