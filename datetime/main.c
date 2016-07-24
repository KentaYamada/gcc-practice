#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
    time_t timer;
    struct tm *local;
    //struct tm *utc;

    //現在時刻取得
    timer = time(NULL);

    //ローカルの時刻へ変更
    local = localtime(&timer);

    //時間表示
    printf("%4d/%2d/%2d %2d:%2d:%2d %2d\n",
            local->tm_year + 1900,
            local->tm_mon + 1,
            local->tm_mday,
            local->tm_hour,
            local->tm_min,
            local->tm_sec,
            local->tm_isdst);

    exit(EXIT_SUCCESS);
}
