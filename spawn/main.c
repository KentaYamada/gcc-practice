#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
    if(argc != 3) {
        fprintf(stderr, "Usage: %s <command> <arg>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid_t pid;
    pid = fork();
    if(pid < 0) {
        fprintf(stderr, "fork(2) failed\n");
        exit(EXIT_FAILURE);
    } else if(pid == 0) {
        execl(argv[1], argv[1], argv[2], NULL);
        //execlが呼び出しから戻ってきたら失敗
        perror(argv[1]);
        exit(99);
    } else { 
        int status;
        waitpid(pid, &status, 0);
        printf("child (PID=%d) finished; ", pid);
        if(WIFEXITED(status)) {
            printf("exit status=%d\n", WEXITSTATUS(status));
        } else if(WIFSIGNALED(status)) {
            printf("signal, sig=%d\n", WTERMSIG(status));
        } else {
            printf("abnomal exit\n");
        }

        exit(EXIT_SUCCESS);
    }
}
