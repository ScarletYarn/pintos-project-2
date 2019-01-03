#ifndef USERPROG_SYSCALL_H
#define USERPROG_SYSCALL_H

#include "lib/user/syscall.h"
#define NOT_LOAD 0
#define LOADED 1
#define LOAD_FAIL 2


void syscall_init (void);

pid_t sys_exit(int status);
static int sys_write(int fd, const void *buffer, unsigned length);
static void sys_halt(void);
static int sys_create(const char *file, unsigned initial_size);
static int sys_open(const char *file);
static int sys_close(int fd);
static int sys_read(int fd, void *buffer, unsigned size);
static int sys_exec(const char *cmd);
static int sys_wait(int pid);
static int sys_filesize(int fd);
static int sys_tell(int fd);
static int sys_seek(int fd, unsigned pos);
static int sys_remove(const char *file);


/* new process forked by syscall exec. */
struct process 
{
	struct thread *t;
	pid_t pid;
	struct list_elem elem;
	bool loaded;
};

struct process* init_process(tid_t tid);

#endif /* userprog/syscall.h */
