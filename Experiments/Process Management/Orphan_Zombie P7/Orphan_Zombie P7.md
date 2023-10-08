## Explanation


## The code creates a process hierarchy with multiple child processes using the fork() system call.

## It starts with the main process (Parent).

## The main process creates P2, which in turn creates P4 as an orphan process (P4 doesn't wait for its child).

## P2 then creates P5, which in turn creates P6. P6 is a child of P5.

## P3 is created by the main process.

## P3 creates P7 as a zombie process (P7 never terminates, so P3 becomes a zombie when waiting for it).

## Finally, the main process waits for P2 and P3 to terminate and prints "All child processes terminated."

## This code demonstrates process creation, parent-child relationships, orphan processes (P4), zombie processes (P3), and waiting for child processes to terminate.