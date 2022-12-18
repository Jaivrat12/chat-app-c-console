#include "stdio.h"
#include "string.h"
#include "../project.h"

char checker1[] = {'0', '1'};
char checker2[] = {'a', 'b'};
int i = 0, j = 0;

void listenChat() {

    int line = 0;
    char c[100], data[2][100];

    FILE *fptr;

    if((fptr = fopen("../Chats/chat2.txt", "r")) == NULL) {

        printf("Failed to open the chat file... Retrying\n");
        fclose(fptr);
    }

    while(fgets(c, 100, fptr) != NULL) {

        strcpy(data[line++], c);
    }

    fclose(fptr);

    if(data[0][0] == checker1[i]) {

        i = (i == 1) ? 0 : 1;

        setColor(PINK);
        printf("User 1> ");
        setColor(CYAN);
        printf("%s\n", data[1]);
    }
    if(data[0][0] == checker2[j]) {

        j = (j == 1) ? 0 : 1;

        setColor(YELLOW);
        printf("You> ");
        setColor(GREEN);
        printf("%s\n", data[1]);
    }
}

void connectChat() {

    while(1) {

        listenChat();
    }
}

int main() {

	SetConsoleTitle("USER 2 - RECEIVER");

    FILE *fp;
    fp = fopen("../Chats/chat2.txt", "w");
    fprintf(fp, "");
    fclose(fp);

    gotoxy(40, 0);
    printf("USER 2");
    gotoxy(38, 2);
    printf("[RECEIVER]\n\n");

    while(1) {

        connectChat();
        setColor(RED);
        printf("\n\nConnection Lost!!!...\n");
        setColor(GREEN);
        printf("You were Reconnected...\n\n");
    }
}
