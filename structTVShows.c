#include <stdlib.h>
#include <stdio.h>

typedef struct TV_Program
{
    char programName[20];
    char weekday; // M, T, W, R, F
    int minutes;  //Running time
    struct TV_Program *next;
} Show;

void printList(Show *h)
{
    Show *curr = h;
    int i = 1;
    while (curr != NULL)
    {   
        printf("TV SHOW %i INFORMATION:\n", i);
        printf("Program Name: %s\n", curr->programName);
        printf("Day of the week: %c\n", curr->weekday);
        printf("Running time: %i\n", curr->minutes);
        curr = curr->next;
        i++;
        printf("\n");
    }
}

void addNode(Show **head)
{
    Show *ptr = (Show *)malloc(sizeof(Show));
    printf("Enter the name of the TV program:\n");
    scanf("%s", ptr->programName);
    printf("Enter the day of the week the show is on:\n");
    scanf(" %c", &ptr->weekday);
    printf("Enter the running time in minutes:\n");
    scanf("%i", &ptr->minutes);
    ptr->next = *head;
    *head = ptr;
}

int main()
{
    Show *head = NULL;
    for (int i = 1; i < 6; i++)
    {
        printf("TV SHOW NUMBER %i:\n", i);
        addNode(&head);
        printf("\n");
    }
    printList(head);
    free(head);
    return 0;
}
