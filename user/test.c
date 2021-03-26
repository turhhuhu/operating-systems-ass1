#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/syscall.h"
#include "kernel/perf.h"
int main(int argc, char* argv[])
{
    int f_pid = getpid();

    int pid;
    pid = fork();
    if(pid == 0){
        for (int i = 0; i < 100; i++)
        {
            fprintf(2, "in child process\n");
        }
        sleep(5);
    }
    else{
        fprintf(2, "in father process with pid: %d\n", f_pid);
        struct perf perfomance;
        wait_stat(0, &perfomance);
        fprintf(2, "ttime, ctime, rettime, ruttime, stime: %d, %d, %d, %d, %d\n ", perfomance.ttime, perfomance.ctime, perfomance.retime, perfomance.rutime, perfomance.stime);
    }

    exit(0);
}