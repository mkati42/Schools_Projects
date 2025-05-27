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
