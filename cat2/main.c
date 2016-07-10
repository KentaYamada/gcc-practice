//
// 標準ライブラリ利用版catコマンドプログラム
//
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    int i;

    if(argc < 2) {
        fprintf(stderr, "file not exitst.");
    }

    for(i = 1; i < argc; i++) {
        FILE *fp;
        int buf;

        fp = fopen(argv[i], "r");
        if(fp < 0) {
            fprintf(stderr, "file read failed.");
            perror(argv[i]);
            exit(EXIT_FAILURE);
        }
        while((buf = fgetc(fp)) != EOF) {
            if(putchar(buf) < 0) {
                exit(EXIT_FAILURE);
            }
        }
        fclose(fp);
    }

    exit(EXIT_SUCCESS);
}
