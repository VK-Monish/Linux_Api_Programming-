# Linux_Api_Programming-
A collection of programs and examples demonstrating Linux API usage in C, covering essential system calls, file operations, process management, memory handling, and interprocess communication. Ideal for learning and mastering low-level programming on Linux.
# Linux API Programming

This repository contains examples and exercises demonstrating the use of Linux system calls and APIs using C programming. It is intended for students, enthusiasts, and professionals aiming to understand the core of Linux-based system programming.

## 🔍 What You'll Learn

- File and directory operations (`open`, `read`, `write`, `close`, `stat`, etc.)
- Process creation and control (`fork`, `exec`, `wait`, `exit`)
- Inter-process communication (pipes, message queues, shared memory)
- Memory management (`mmap`, `brk`, `malloc`, etc.)
- Signals and signal handling
- Thread programming using `pthreads`
- Error handling and debugging tools

## File I/O and Hardware Access
- `file_io/mouse_reader.c`: Reads raw mouse events from `/dev/input/mice`
- `file_io/battery_status.c`: Reads battery percentage from `/sys/class/...`
- `file_io/keyboard_reader.c`: Reads keyboard input from `/dev/input/eventX`
- `file_io/arg_parser.c`: Demonstrates command-line argument handling in C

## 🛠️ Setup & Compilation

Ensure you have `gcc` installed:

```bash
sudo apt update
sudo apt install build-essential

To compile a sample program:

gcc file_operations/read_write.c -o read_write
./read_write

🤝 Contributions

Feel free to fork this repository, make improvements, or add new examples. Pull requests are welcome!
