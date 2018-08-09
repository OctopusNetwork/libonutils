#include <sys/time.h>
#include <stdio.h>

void time_progress(void)
{
    static struct timeval tv, ntv;
    int gap = 0;

    gettimeofday(&ntv, NULL);
    gap = ntv.tv_sec - tv.tv_sec;
    if (4 < gap) {
        gettimeofday(&tv, NULL);
    }
    if (0 == gap) {
        printf("- .\r");
    } else if (1 == gap) {
        printf("\\ ..\r");
    } else if (2 == gap) {
        printf("- ...\r");
    } else if (3 == gap) {
        printf("/ ...\r");
    }
}

unsigned long time_now(void)
{
    static struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}
