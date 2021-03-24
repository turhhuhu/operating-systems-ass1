#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/syscall.h"

int main(int argc, char* argv[])
{
    int f_pid = getpid();
    trace(1 << SYS_fork | 1 << SYS_kill, f_pid);

    int pid;
    pid = fork();
    if(pid == 0){
        fprintf(2, "in child process\n");
    }
    else{
        fprintf(2, "in father process with pid: %d\n", f_pid);
        kill(pid);
        wait(0);
    }

    exit(0);
}