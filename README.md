<h1 align="center">Schools_Projects</h1>

<p align="center">
  <img alt="Github top language" src="https://img.shields.io/github/languages/top/mkati42/Schools_Projects?color=56BEB8">
  <img alt="Github language count" src="https://img.shields.io/github/languages/count/mkati42/Schools_Projects?color=56BEB8">
  <img alt="Repository size" src="https://img.shields.io/github/repo-size/mkati42/Schools_Projects?color=56BEB8">
  <img alt="License" src="https://img.shields.io/github/license/mkati42/Schools_Projects?color=56BEB8">
</p>

<p align="center">
  <a href="#dart-about">About</a> &#xa0; | &#xa0; 
  <a href="#sparkles-features">Features</a> &#xa0; | &#xa0;
  <a href="#rocket-technologies">Technologies</a> &#xa0; | &#xa0;
  <a href="#white_check_mark-requirements">Requirements</a> &#xa0; | &#xa0;
  <a href="#checkered_flag-starting">Starting</a> &#xa0; | &#xa0;
  <a href="#books-projects">Projects</a> &#xa0; | &#xa0;
  <a href="#memo-license">License</a> &#xa0; | &#xa0;
  <a href="https://github.com/mkati42" target="_blank">Author</a>
</p>

<br>

## :dart: About ##

This repository contains a collection of school projects developed during my journey at Ecole 42. Each subfolder represents a different project, focusing on various aspects of programming, from C language basics to advanced concurrency, system programming, and game development.

## :sparkles: Features ##

:heavy_check_mark: Implementation of standard C library functions (libft);  
:heavy_check_mark: Custom implementation of printf (ft_printf);  
:heavy_check_mark: Reading lines from files efficiently (get_next_line);  
:heavy_check_mark: Signal-based client-server communication (mini_talk);  
:heavy_check_mark: Stack-based number sorting with limited operations (push_swap);  
:heavy_check_mark: 2D game using MLX (so_long);  
:heavy_check_mark: Shell interpreter with pipes and redirections (minishell);  
:heavy_check_mark: Philosophers problem with thread synchronization (philo);

## :rocket: Technologies ##

These projects were built using:

- C (ISO C90 Standard)
- Makefiles
- POSIX System Calls
- UNIX Signals
- Pthreads
- MiniLibX (for graphical interface in `so_long`)

## :white_check_mark: Requirements ##

Before starting, make sure you have the following installed:

- [GCC](https://gcc.gnu.org/)
- [Make](https://www.gnu.org/software/make/)
- [X11 libraries](https://www.x.org/) (for MiniLibX)
- [Valgrind](https://valgrind.org/) (for memory debugging)

## :checkered_flag: Starting ##

```bash
# Clone this project
$ git clone https://github.com/mkati42/Schools_Projects.git

# Access
$ cd Schools_Projects

# Navigate into each project to read specific README files and build instructions
$ cd libft && make
$ cd ../ft_printf && make
# etc.

:books: Project Details
<details> <summary><strong>📘 libft</strong> - Implementation of standard C library functions</summary> <p> This project is a custom implementation of the standard C library functions such as `memcpy`, `strlen`, `strcpy`, etc. It is the foundational project for many others at 42. </p> </details> <details> <summary><strong>🖨️ ft_printf</strong> - Custom printf function</summary> <p> This project reimplements the standard C `printf` function, supporting formatted output with flags, width, precision, and different specifiers. </p> </details> <details> <summary><strong>📄 get_next_line</strong> - Efficient file reading line-by-line</summary> <p> Reads input from a file descriptor line by line. It handles buffering and memory efficiently, a good introduction to file handling and dynamic memory. </p> </details> <details> <summary><strong>🔔 mini_talk</strong> - Signal-based client-server communication</summary> <p> A minimalist messaging system using UNIX signals (`SIGUSR1`, `SIGUSR2`) to send characters between processes, forming the basis of inter-process communication. </p> </details> <details> <summary><strong>🔢 push_swap</strong> - Number sorting using stack operations</summary> <p> Sorting numbers using a limited set of stack operations. Emphasizes algorithm optimization, data structures, and efficient sorting with fewest moves. </p> </details> <details> <summary><strong>🕹️ so_long</strong> - 2D game with MLX</summary> <p> A simple 2D tile-based game using MiniLibX. The player collects items and reaches an exit while navigating through a map. Emphasizes graphical output and basic game loops. </p> </details> <details> <summary><strong>💻 minishell</strong> - Bash-like shell implementation</summary> <p> Builds a mini shell that supports commands, pipes, redirections, environment variables, and more. One of the most comprehensive projects at 42. </p> </details> <details> <summary><strong>🍝 philo</strong> - Philosophers problem (threads and mutex)</summary> <p> Classic concurrency problem solved using threads and mutexes. Demonstrates thread synchronization, starvation avoidance, and race condition management. </p> </details>