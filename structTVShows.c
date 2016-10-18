#include <stdlib.h>
#include <stdio.h>

typedef struct TV_Program // define structure for TV_Program
{
    char programName[20];
    char weekday; // M, T, W, R, F
    int minutes;  //Running time
    struct TV_Program *next;
} Show; // define typedef for Show

void printList(Show *h)
{
    Show *curr = h; // move current position to top of the list
    int i = 1;
    while (curr != NULL) // while not at end of list
    {   
        printf("TV SHOW %i INFORMATION:\n", i);
        printf("Program Name: %s\n", curr->programName);
        printf("Day of the week: %c\n", curr->weekday);
        printf("Running time: %i\n", curr->minutes);
        curr = curr->next; // move to next node
        i++;
        printf("\n");
    }
}

void addNode(Show **head)
{
    Show *ptr = (Show *)malloc(sizeof(Show)); // allocate space for new node
    printf("Enter the name of the TV program:\n");
    scanf("%s", ptr->programName);
    printf("Enter the day of the week the show is on:\n");
    scanf(" %c", &ptr->weekday);
    printf("Enter the running time in minutes:\n");
    scanf("%i", &ptr->minutes);
    ptr->next = *head; // add new node to front of list
    *head = ptr; // adjust header to point to new node
}

int main()
{
    Show *head = NULL; // intialize head pointer
    for (int i = 1; i < 6; i++) // add 5 nodes
    {
        printf("TV SHOW NUMBER %i:\n", i);
        addNode(&head);
        printf("\n");
    }
    printList(head);
    free(head); // free allocated memory
    return 0;
}
