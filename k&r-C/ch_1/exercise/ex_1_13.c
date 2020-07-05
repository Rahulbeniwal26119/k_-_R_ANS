#include <stdio.h>
int main() {
    int c;
    int ns = 0;
    while ((c= getchar()) != EOF) {
        if (c == '\n') {
            putchar('\n');
            continue;
        }
        if (c == ' ')
            ns = ns;
        else {
            ++ns;
            for (; ns > 0; --ns)
                putchar('*');
        }
    }
}

