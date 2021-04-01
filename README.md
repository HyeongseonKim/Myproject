# Contraction About program

## pctest program: C program, with one source file, no dependency.

### purpose: to assist an instructor of C programming courses in evaluating programming homework submissions of the students.

	1. with each of given test inputs, pctest runs both
    - target program	(student's submission)
    - solution program	(correct program offered by instructor)
	2. compares target and solution results
	- to determine whether the target program resturns correct result or a failure.

### How?
	- find proper system library fuctions for different purposes of process control
	- use them properly in construction pctest.

#### Inputs
	- two source code files
		- target(.c)
		- solution(.c)
		- two progs aim to solve the same problem.
		- but target may or may not have errors
	- set of program inputs Tests.
		- consists of 1~10 files
		- each of one is an input of target and solution

#### Outputs
	- display the summary of the test results via standard Output
		- whether the compliation was succeeded or not
		- the number of the correct test executions and the number of fialed test executions
		- the maximum and the minimum time of a single test execution


## 2. Running test

  - pctest launches target and solution with each input file in Tests one by one.
  - Tests input file each
  * -> target
  * -> solution
  * to better utilize a multicore CPU
  - for each test input,
  - pctest must create one process
  * -> target
  * -> soultion
  - and run them concurrently

#### condition:
  ⁃	pctest must kill a process running target if its execution exceeds a predefined time limt, because it may run indefnitely.
  * such a test execution should be recognized as a failed one.
  ⁃	when running target on a new process, pctest must disallow the  process to open new file (I/O block)
 
## 3. Checkinng Test

  - pctest determines that target fails for a given test input (False Detector)
  - if the corresponding test execution falls into one of the following case.
    - a crash (runtime/fatal error) occurs
    - returns an error code at termination
    - does not terminate within a certain amount of execution time
    (for example, time over)
    - the text printed to the standard output is not identical to that of solution
  - In addition to the functionality checking, (Timer)
  - pctest also measures the test execution time to maintain the following three values
    - the maximum execution time of a single test run in milliseconds
    - the minimum execution time of a single test run in miliseconds
    - the sum of the execution time of all test runs in miliseconds


## 4. Command-line interface

  ## $ pctest -i <testdir> -t <timeout> <solution> <target>
  
  - <testdir> : a user gives a path to directory where the test input files are stored.
  * all files under <testdir> will be recognized as input files

  - <timeout> :
	* specifies the time limit of a program execution in seconds.
	* time limit should be an integer bet 1 and 10

  - <solution>, <target> :
	* give a filename of the source code of the correct version
	* filename of the source code of a student’s program under test respectively.
  * pctest should exit if it recieves an invalid command line argument.

 
## 5. Implementation

### requirments, assumption, useful info on implementing pctest

### 5.1 Constraints, assumptions, and requirments
	- Use system functions for creating, executing, and killing processes
	- not allowed to execute a shell like bash from pctest,
	- pipe and dup2: to construct an unnamed pipe for transferring data between a parent process with a child process
	- func kill : must be used for a parent process to terminate a child process
	- pctest must properly handle them so that it works reliably even with an invalid input
 
## 6. Useful information
	- opendir
	: the list of the names in a files in a certain directory can be obtained by calling
	- clock_gettime
		: For querying the current time in miliseoconds -> / not use gettimeofday
	- setrlimit
		: change the limits of various resource uses of the current process,
		including the maximum num of file descriptors that process opens.
	*	setrlimit can decrease the limit of a resource us from the current value but cannot increase it.
  * if a process is to execute exec, it requires a new file descriptor to open the target binary file to load the content to mem.
