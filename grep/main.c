#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <sys/types.h>


static void do_grep(regex_t *pattern, FILE *fp);
static void do_grep_files(const int argc, char *argv[], regex_t *pattern);

int main(int argc, char *argv[])
{
    regex_t pat;
    int err;

    if(argc < 2) {
        fprintf(stderr, "no pattern\n");
        exit(EXIT_FAILURE);
    }

    err = regcomp(&pat, argv[1], REG_EXTENDED | REG_NOSUB | REG_NEWLINE);
    if(err != 0) {
        char buf[1024];
        regerror(err, &pat, buf, sizeof(buf));
        puts(buf);
        exit(EXIT_FAILURE);
    }

    if(argc == 2) {
        do_grep(&pat, stdin);
    } else {
        do_grep_files(argc, argv, &pat);
    }

    regfree(&pat);
    exit(EXIT_SUCCESS);
}

static void do_grep(regex_t *pattern, FILE *fp)
{
    char buf[4096];
    while(fgets(buf, sizeof(buf), fp)) {
        if(regexec(pattern, buf, 0, NULL, 0) == 0) {
            fputs(buf, stdout);
        }
    }
}

static void do_grep_files(const int argc, char *argv[], regex_t *pattern)
{
    int i;
    for(i = 2; i < argc; i++) {
        FILE *fp;
        fp = fopen(argv[i], "r");
        if(fp < 0) {
            perror(argv[i]);
            exit(EXIT_FAILURE);
        }

        do_grep(pattern, fp);
        fclose(fp);
    }
}
