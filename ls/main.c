#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>


static void do_ls(const char *path);

int main(int argc, char *argv[])
{
    if(argc < 2) {
        fprintf(stderr, "%s no arguments\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int i;
    for(i = 1; i < argc; i++) {
        do_ls(argv[i]);
    }

    exit(EXIT_SUCCESS);
}

static void do_ls(const char *path)
{
    DIR *dp;
    struct dirent *ent;

    dp = opendir(path);
    if(!dp) {
        perror(path);
        exit(EXIT_FAILURE);
    }

    while((ent = readdir(dp)) != NULL) {
        printf("%s\n", ent->d_name);
    }

    closedir(dp);
}
