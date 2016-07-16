#include <stdio.h>
#include <stdlib.h>


static void do_head(FILE *fp, long lines);
static void do_head_files(int argc, char *argv[], long lines);


int main(int argc, char *argv[])
{
    long lines;
    if(argc < 2) {
        fprintf(stderr, "Usage: %s n[file1 file2...fileN]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    lines = atoll(argv[1]);
    if(argc == 2) {
        do_head(stdin, lines);
    } else {
        do_head_files(argc, argv, lines);
    }

    exit(EXIT_SUCCESS);
}

static void do_head(FILE *fp, long lines)
{
    long i;
    for(i = lines; i > 0; i--) {
        int c;
        while((c = getc(fp)) != EOF) {
            if(putchar(c) < 0) {
                exit(EXIT_FAILURE);
            }
            if(c == '\n') {
                break;
            }
        }
    }
}

static void do_head_files(int argc, char *argv[], long lines)
{
    int i;
    for(i = 2; i < argc; i++) {
        FILE *fp;
        fp = fopen(argv[i], "r");
        if(fp  < 0) {
            perror(argv[i]);
            exit(EXIT_FAILURE);
        }

        do_head(fp,lines);
        fclose(fp);
    }
}
