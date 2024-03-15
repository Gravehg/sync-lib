# synchronization-library
A basic implementation of a synchronization library for the C programming language.

## Table of contents
-[Pre-requisites](#pre-requisites)

-[Installation](#installation)

-[Usage](#usage)

-[Examples](#examples)

## Pre-requisites
- Linux Operating System - In conformance with POSIX.
- GCC compiler installed in your distro.
- Make tool installed in your distro.

## Installation

First, just so things are easier, there is a Makefile with a lot of commands

### Local library

If you just want the local object library file, it is named **synclib.o**, to compile it run the commands:

- make clearlib

- make synclib.o

Great! Now you have the object file, to use it, you will still need the **synclib.h** file to be in the same folder as your 
project file and include it at the top using double quotes.
Then you can compile your program as follows:

- gcc -o yourprogram yourprogram.c synclib.o

Neat, right?

### The DLL way

On the other hand, if you want the DLL, named **libsynclib.so**, run the commands:

- make cleardll

- make lybsynclib.so

Now that you have the file, you will still need the **synclib.h** file to be in the same folder as your 
project file and include it at the top using double quotes.

Then you can compile your program as follows:

- gcc -o test test.c -L. -lsynclib

If the compilation throws an error signaling that it cannot find the library, you can do the following:

- First: Issue the command ld --verbose | grep SEARCH_DIR | tr -s ' ;' \\012 , in your terminal

The paths where the linker searches for the library will appear there, choose one of them, like /usr/lib

- Second: In the folder that has the libsinclib.so file, issue the following command: sudo cp libsynclib.so /usr/lib

**Note**: For this you need to issue your superuser password

- Third: Try compiling your program again 


## Usage
The **semaphore** synchronization primitve allows for the synchronization of threads on crytical
sections of the code, it allows threads to **acquire** and **release** a resource.

Use semaphore_init(semaphore *sem, int initial_value) to initialize a semaphore.

Use semaphore_acquire(semaphore *sem) to wait.

Use semaphore_release(semaphore *sem) to notify.

Use semaphore_destroy(semaphore *sem) to destroy the semaphore.

An example usage for semaphores is included in the **testsemaphore.c** file

The **barrier** synchronization primitive allows threads to synchronize at an specific point
and continue their execution **once** every thread reaches a certain point.  

Use barrier_init(barrier *b, int count) to initialize a barrier.

Use barrier_wait(barrier *b) to synchronize threads at an specifi point.

Use barrier_destroy(barrier *b) to destroy the barrier.

An example usage for barriers is included in the **testbarriersync.c** file

All the structures are defined in the **synclib.h** file if you want to check their contents.


## Examples

### Running the test file for the semaphore
Try running it by issuing **./testsemaphore** on your terminal

![alt text](image.png)

### Running the test file for barrier

Try running it by issuing **./testbarrier** on your terminal

![alt text](image-1.png)

There are also tests with the DLL way, but you first need to follow the steps in [The DLL way](#the-dll-way)
If you follow the instructions you can issue the commands to test it:

- make testbarrierDLL
- make testsemaphoreDLL
- ./testsemaphoredll
- ./testbarrierdll

If you want to clear all tests:

- make clearalltests

If you want to re-compile all tests:

- make compilealltests