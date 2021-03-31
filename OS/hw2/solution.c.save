#include <unistd.h>
// read(), write(), close(), dup(), dup2(), getcwd(), chdir(const char* pathname), fchdir()
#include <stdlib.h>
// exit(): calls exit handlers registered by process flush stdio buffers
#include <stdio.h>
// perrorr(), remove(), rename()
#include <error.h>
// EREPM 1 (Operation not permitted), ENOENT 2 (No such file or directory), ESRCH 3 (No such process
/* simple error handling
fd = open(pathname, flags, mode);
if (fd == -1) {
	perror("open");
	exit(EXIT_FAILURE);
}
*/
#include <string.h>
//  strerror(int errnum), strsignal(int sig), execve
#include <sys/types.h>
// 
#include <sys/wait.h>
// pause(): to wait for a siganl, wait(), waitip(): waits for a child process to change state
/* 
pid == -1: any child of caller
pid > 0: child whose PID equals pid
pid == 0: any child in same process group as caller
*/
/*
for ( ; ; ) {

