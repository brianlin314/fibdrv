#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define FIB_DEV "/dev/fibonacci"

int main()
{
    char write_buf[] = "testing writing";
    int offset = 100; /* TODO: try test something bigger than the limit */

    int fd = open(FIB_DEV, O_RDWR);
    if (fd < 0) {
        perror("Failed to open character device");
        exit(1);
    }

    for (int i = 0; i <= offset; i++) {
        long long t1, t2, t3, t4;
        lseek(fd, i, SEEK_SET);
        /*iterative*/
        t1 = write(fd, write_buf, 1);
        /*fast_doubling_recursive*/
        t2 = write(fd, write_buf, 2);
        /*fast_doubling_iterative*/
        t3 = write(fd, write_buf, 3);
        /*fast_doubling_iterative_clz*/
        t4 = write(fd, write_buf, 4);

        printf("%lld %lld %lld %lld\n", t1, t2, t3, t4);
    }

    close(fd);
    return 0;
}