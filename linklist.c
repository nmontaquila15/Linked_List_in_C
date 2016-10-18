#include <stdlib.h>
#include <stdio.h>

struct TV_Program
{
    char programName[20];
    char weekday; // M, T, W, R, F
    int minutes;  //Running time
    struct TV_Program *next;
};

typedef struct TV_Program Show;

void printNode(Show *x)
{
    printf("Program Name: %s\n", x.programName);
    printf("Day of the week: %c\n", x.weekday);
    printf("Running time: %i\n", x.minutes);
}

void addNode(Show **head)
{
    Show *ptr = malloc(Show);
    printf("Enter the name of the TV program:\n");
    scanf("%s", ptr->programName);
    printf("Enter the day of the week the show is on:\n");
    scanf("%c", ptr->weekday);
    printf("Enter the running time in minutes:\n");
    scanf("%i", ptr->minutes);
    ptr->next = *head;
    *head = ptr;
}

int main()
{
    Show *head = NULL;
    int i;
    for (i = 0; i < 5; i++)
    {
        addNode(&head);
    }
    printNode(ptr);
    free ptr;
    return 0;
}