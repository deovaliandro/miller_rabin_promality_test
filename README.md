# Hanya test miller rabin sederhana

Compiling:

```bash
clang miller_rabin.c -o miller_rabin -lm -O2 -Wall -Wextra -fpie -fPIE -std=c11 -pedantic-errors -ggdb3 -fno-omit-frame-pointer
```

Usage:

```bash
./miller_rabin p t
where p is prime number and t is the number of trials performe (default 1)
```

Testing:

```bas
./miller_rabin 221 20
```