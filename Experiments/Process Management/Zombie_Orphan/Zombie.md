**README.md**

**Overview**

This program demonstrates how to create a hierarchy of processes using the `fork()` and `waitpid()` system calls. The program also simulates an orphan process and a zombie process.

**Usage**

To compile the program, run the following command:

```
gcc -o process_hierarchy process_hierarchy.c
```

To run the program, simply type `./process_hierarchy` into a terminal window.

**Output**

The program will output the following messages to the terminal:

```
Process P1 created.
Process P2 created.
Process P4 created.
Process P4 exited.
Process P2 waiting for child processes to terminate.
Process P5 created.
Process P5 exited.
Process P2 waiting for child processes to terminate.
Process P1 waiting for child processes to terminate.
All child processes terminated.
```

After the program terminates, you can use the `ps -eaf` command to verify that process P4 is an orphan process and process P5 is a zombie process.

**Understanding the denotations**

The following table explains the different denotations that can be used in the `ps -eaf` command:

| Denotation | Meaning |
|---|---|
| S | The process is running. |
| S+ | The process is running and has a higher priority than other processes. |
| R | The process is waiting for I/O. |
| D | The process is uninterruptible and waiting for I/O. |
| Z | The process is a zombie process. |
| T | The process is stopped. |

**Orphan process**

An orphan process is a process whose parent process has terminated, but the child process is still running. Orphan processes are denoted by the `Z+` status in the output of the `ps -eaf` command.

In the example program, process P4 is orphaned because it exits without waiting for its parent.

**Zombie process**

A zombie process is a process that has exited, but its parent process has not yet reaped it. Zombie processes are denoted by the `Z` status in the output of the `ps -eaf` command.

In the example program, process P5 is a zombie process because it has exited, but its parent process has not yet reaped it. To reap a zombie process, the parent process must call the `waitpid()` system call. Once the zombie process is reaped, it is removed from the system.

**Additional notes**

* The example program uses the `fork()` system call to create new processes. The `fork()` system call creates a copy of the calling process. The parent process and child process share the same memory space initially, but they have separate PIDs.
* The example program uses the `waitpid()` system call to wait for child processes to terminate. The `waitpid()` system call blocks the calling process until the specified child process terminates.
* The example program simulates an orphan process by exiting without waiting for its parent. This can be done by calling the `exit()` system call.
* The example program simulates a zombie process by exiting without being reaped by its parent. This can be done by calling the `exit()` system call without first calling the `waitpid()` system call.

