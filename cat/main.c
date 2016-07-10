#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//マクロ定義
#define BUFFER_SIZE 2048


//関数プロトタイプ宣言
static void do_cat(const char *path);
static void die(const char *path);


//エントリポイント
int main(int argc, char *argv[])
{
    int i;

    //check command line argument
    if(argc < 2) {
        fprintf(stderr, "%s: file not exist.\n", argv[0]);
        exit(1);
    }

    for(i = 1; i < argc; i++) {
        do_cat(argv[i]);
    }

    exit(0);
}

//
// cat実行
// arguments
// path string: ファイルパス(読み取り専用)
//
static void do_cat(const char *path)
{
    unsigned char buf[BUFFER_SIZE];
    int fd;
    int n;

    fd = open(path, O_RDONLY);
    if(fd < 0) {
        die(path);
    }

    while(1) {
        n = read(fd, buf, sizeof(buf));
        if(n < 0) {
            die(path);
        } else if(n == 0) {
            break;
        }
        if(write(STDOUT_FILENO, buf, n) < 0) { 
            die(path);
        }
    }

    if(close(fd) < 0) {
        die(path);
    }
}

static void die(const char *path)
{
    perror(path);
    exit(1);
}
