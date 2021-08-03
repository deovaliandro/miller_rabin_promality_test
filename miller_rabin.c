#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>

static const char *app = NULL;

int miller_rabin(int p, int k) {
    int n = p, n_1, a = 0, d, s;
    n_1 = p - 1;
    d = rand() % n;
    s = rand() % n;

    if (d % 2 == 0) {
        d--;
    }
    
    for (int i=0; i < k; i++) {
        a = rand() % n_1;
        for (int r = 0; r < s-1; r++) {
            int x = (int) pow(a, (pow(2, r) * d)) % n;
            if (x == 1 || x == n_1) {
                printf("True\n");
                exit(1);
            }
        }
    }

    printf("false\n");

    return 0;
}

int is_prime(char *argv[], int k)
{
    int p, t = 0;
    p = atoll(argv[1]);
    
    if (k == -1) {
        t = atoll(argv[2]);
    } else {
        t = 1;
    }

    if (p <= 3) {
        printf("True\n");
        exit(1);
    }

    if (p % 2 == 0 || p % 3 == 0) {
        printf("False\n");
        exit(1);
    }

    miller_rabin(p, t);
    
    return 0;
}

void print_help(void)
{
    printf("Usage:\n");
    printf("    %s p t\n", app);
    printf("    where p is prime number and t is the number of trials performe (default 1)\n");
}

int main(int argc, char *argv[])
{
    app = argv[0];

    if(argc < 2){
        print_help();
        return EINVAL;
    }

    if (argc == 3) {
        is_prime(argv, -1);
    } else if (argc == 2) {
        is_prime(argv, 2);
    }

    return 0;
}
