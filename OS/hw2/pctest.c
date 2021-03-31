#include <sys/type.h>
#include <dirent.h>


void main() {
//#1. two soultion, set file read and compile target and solution program
	DIR *dirPtr = opendir("./Tests");
	execv
		

//#2. execute target and solution program with each input file in tests
//# one by one.
//# addtion utilize a multicore CPU


//#2-1. for each test input, pctest must create on process and run them correctly
//# **when running program on a new process, pctest must not allow the process to #open new file (I/O block)


//#3. pctest determines that target fails for a given test input
//#3-1. False Detector
/*
1. target crash (runtime/fatal error) occurs
2. target returns a error code at termination
3. target does not terminate within a certain amount of execution time
4. the text printed to the standard output is not identical to that of solution.
*/


//#pctest must kill a program if time limit
//#

//#4. Command-line interface
//# $ pctest -i <testdir> -t <timeout> <solution> <target>
//# main(argc, args)
///# -i input, -t timeout option navigator

	return;
}
