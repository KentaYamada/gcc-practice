#include <stdio.h>
#include <stdlib.h>


static void do_head(FILE *fp, long lines);


int main(int argc, char *argv[])
{
    //argument check
    if(argc != 2) {
        fprintf(stderr, "Usage: %s n\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    do_head(stdin, atol(argv[1]));

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
