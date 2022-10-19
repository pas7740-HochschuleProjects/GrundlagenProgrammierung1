#include <stdio.h>

int main() {
    char meldung1[] = "Hello1";
    char meldung2[] = {'H','e','l','l','o','2','\0'};
    // Das Zeichen '\0' ist wichtig!
    char meldung3[] = "Hello3";

    printf("%s", meldung1);
    printf("%s", meldung2);
    printf("%s", meldung3);
    printf("\n");
    return 0;
}

