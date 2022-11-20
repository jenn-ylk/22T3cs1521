#include <stdio.h>
//#include <stdlib.h>
//#include <errno.h>
//#include <string.h>
//#include <unistd.h>
#include <spawn.h>
#include <sys/types.h>
//#include <sys/stat.h>
#include <sys/wait.h>

// sets up environment variable
extern char **environ;

void spawn_and_wait(char **args) {
    // TODO: set things up to spawn a process, then wait for it to finish
    pid_t pid;
    int status;
    posix_spawn(&pid, args[0], NULL, NULL, args, environ);
    
    waitpid(pid, &status, 0);
}

int main(void) {
    // use whereis to find the locations of commands
    // TODO: call spawn and wait to run the commands
    spawn_and_wait((char *[]){"/bin/date", "+%d-%m-%Y", NULL});
    spawn_and_wait((char *[]){"/bin/date", "+%T", NULL});
    spawn_and_wait((char *[]){"/bin/hostname", "-f", NULL});
    spawn_and_wait((char *[]){"diary", NULL});
    return 0;
}
