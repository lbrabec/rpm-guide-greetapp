#include <stdio.h>
#include <greetlib.h>

int main(int argc, char *argv[]) {
    const char *name = (argc > 1) ? argv[1] : "User";
    printf("%s\n", greet(name));
    return 0;
}

