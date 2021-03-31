#include <stdio.h>
void swtch(struct context **old, struct context *new);
// Svae current register context in old
// and then load register context from new.
.globl swtch

// the registers  xv6 will save and restore
// to stop and subsequently restart a process

struct context {
	int eip;
	int esp;
	int ebx;
	int ecx;
	int dex;
	int esi;
	int edi;
	int ebp;
};

// the different states a process can be in
enum proc_state { UNUSED, EMBRYO, SLEEPING,
		  RUNNABLE, RUNNING, ZOMBIE };

// the information xv6 tracks about each process
// including its register context and state
struct proc {
	char *mem;		// Start of process memory
	uint sz;		// Size of process memory
	char *kstack;		// Bottom of kernel satck
				// for this process
	enum proc_state state;	// Processs state
	int pid;		// Parent state
	struct proc *parent;	// Parent process
	void *chan;		// If !zero, sleeping
	int killed;		// If !zero, has been killed
	struct file *ofile[NOFILE]; // Open files
	struct inode *cwd;	// Cureent directory
	struct context context;	// Switch here to run process
	struct trapframe *tf;	// Trap frame for the
				// current interrup
};

	// Save old registers
	swtch:
	movl 4(%esp), %eax	// put old ptr into eax
	popl 0(%eax)		// save the old IP
	movl %esp, 4(%eax)	// and stack
	movl %ebx, 8(%eax)	// and other registers
	movl %ecx, 12(%eax)
	movl %edx, 16(%eax)
	movl %esi, 20(%eax)
	movl %edi, 24($eax)
	movl %ebp, 28($eax)

	# Load new registers
	movl 4(%esp), %eax	// put new ptr into eax	
	movl 28(%eax), %ebp	
	movl 24(%eax), %edi
	movl 20(%eax), %esi
	movl 16(%eax), %edx
	movl 12(%eax), %ecx
	movl 8(%eax), %ebx
	movl 4(%eax), %esp	// stack is switched here
	pushl 0(%eax)		// eturn addr pu inplace
	ret			// finally return into new ctxt


	
