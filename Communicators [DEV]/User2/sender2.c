#include "stdio.h"
#include "string.h"
#include "../project.h"

int main() {

	SetConsoleTitle("USER 2 - SENDER");

    char checker1[] = {'0', '1'};
    char checker2[] = {'a', 'b'};
    int i = 0, j = 0;

    gotoxy(40, 0);
    printf("USER 2");
    gotoxy(39, 2);
    printf("[SENDER]\n\n");

    while(1) {

        char message[100];

        printf("> ");
        fgets(message, 100, stdin);

        FILE *fptr;
        fptr = fopen("../Chats/chat1.txt", "w");

        fprintf(fptr, "%c\n", checker1[i]);
        fprintf(fptr, "%s\n", message);

        fclose(fptr);

        fptr = fopen("../Chats/chat2.txt", "w");

        fprintf(fptr, "%c\n", checker2[j]);
        fprintf(fptr, "%s\n", message);

        fclose(fptr);

        j = i = (i == 1) ? 0 : 1;

        printf("\n");
    }
}
