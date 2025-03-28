///NAME : Mariam Turk
/// ID: 1211115
/// sec :1
/// Instructor : Ahmad Abusnaina

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define SIZE  63
#include <stddef.h>
typedef struct NODE
{
    char string[31];
    struct NODE * NEXT;
    struct NODE * PREV;
};

struct NODE *array[SIZE];

/// functions of this project
struct NODE* createNode(char string[31]);
struct NODE * createlist();
void printList(struct NODE * node);
void Insert_At_End( char * str,struct NODE * node);
struct NODE* makeEmpty(struct NODE* L);
int maxString (struct NODE *head );
void addSpace (struct NODE * head);
void ASCII();
void Delete_Node(struct NODE* head);
void DeleteList(struct NODE* L);
void Radix_Sort(struct NODE* head);
void print_radix_list(struct NODE * node);
void print ();
void load_From_File(struct NODE* head, const char* filename);
void saveToFile(struct NODE* head, const char* filename);



// Function to load strings from a file and insert into the linked list
void loadFromFile(struct NODE* head, const char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    char buffer[31];

    // Read strings from the file and insert into the linked list
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        // Remove newline character if present
        size_t len = strlen(buffer);
        if (buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
        }

        // Insert the string into the linked list
        Insert_At_End(buffer, head);
    }

    fclose(file);
}



// function to create new node
struct NODE* createNode(char string[31])
{
    struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
    //put the string in the node
    strcpy(newNode->string, string);
    newNode->NEXT = NULL;
    return newNode;
}



/*to create a new double linked list*/
 struct NODE * createlist()
 {
   struct NODE * l= (struct NODE *)malloc(sizeof(struct NODE));
   //in case the list is empty
   if(l==NULL)
   {
       printf("\n Out of memory \n");
       return NULL;
   }
    l->NEXT=NULL;
    l->PREV=NULL;
    return l;
  }



// function to print the list of string
void printList(struct NODE * node)
{

    struct NODE * N = node;
    while (N != NULL)
    {
        printf("%s\n",N ->string);
        N = N ->NEXT;
    }
}



// function to insert at end of linked list
void Insert_At_End( char * str,struct NODE * node)
{

    struct NODE *NEWNODE = (struct NODE*)malloc(sizeof(struct NODE));
    strcpy(NEWNODE-> string, str);
    NEWNODE -> NEXT = NULL;
    //in case the list is empty
    if(node == NULL)
    {
        NEWNODE -> PREV = NULL;
    }
    // start to insert from the end of the list (in case the list is not empty)
    struct NODE * LASTNODE = node;
    while(LASTNODE -> NEXT != NULL)
    {
        LASTNODE = LASTNODE -> NEXT;
    }
    LASTNODE -> NEXT = NEWNODE;
    NEWNODE -> PREV = LASTNODE;
}



struct NODE* makeEmpty(struct NODE* L)
{
    L = (struct NODE*) malloc (sizeof(struct NODE)); //I reserved place at the memory for the full node which have pointer and data in, so i used malloc
    //to make sure that malloc won't point to void data, we use casting as struct data type
    if (L==NULL) printf("OutOfMemo!!\n");//to make sure we won't have null pointer exception
    L->PREV = NULL;
    //we created the head, which is at the beggining don't point to ant thing just NULL
    L->NEXT = NULL;
    //return the head
    return L;
}L;// return L ( points to the newly created node



//function to know the maximum string
int maxString (struct NODE *head )
{
    // to save the first string in maxStr
    int maxStr = strlen(head ->string);
    // to check all the node in the linked list
    struct NODE* node = head -> NEXT;
    // loop to know the max length of strings in the linked list
    while(node != NULL)
    {
        int str = strlen(node  -> string);
        if (str > maxStr)
        {
            maxStr=str;
        }
        node =node -> NEXT;
    }
    // return the number of char in the max string
    return maxStr;
}



// function to add spaces in the short strings
void addSpace (struct NODE * head)
{
    // to know the max length of string
    int max = maxString(head);
    struct NODE * node = head ->NEXT;
    while (node != NULL)
    {
        // to the number of char in each node
        int num_str = strlen(node->string);
        // sub the size of strings with the max string
        int num = max - num_str;
        // for loop to add spaces to strings
        for(int i = 0 ; i<num ; i++)
        {
            strncat(node->string," ", sizeof(node->string) - strlen(node->string) - 1);
        }
        node = node -> NEXT;
    }
}



// function to put the ASCII(lower case) code in the array of linked list
void ASCII()
{

    int ascii = 64 ;
    int ascii2 = 96;
    int ascii3 =  -1 ;

    array[0] = (struct NODE*)malloc (sizeof(struct NODE));
    strcpy(array[0]-> string, "");
    array [0]-> NEXT = NULL;
    printf("%s\n",array[0] ->string);
    for (int m = 1; m<=10 ; m++)
    {
        array[m] = (struct NODE*)malloc (sizeof(struct NODE));
        ascii3 +=1;
        itoa(ascii3,array[m] -> string, 10);


        array[m]->NEXT = NULL ;
       //printf("%s", array[m] ->string);
    }

    for (int i = 10 ; i < 37; i++)
    {
        array[i] = (struct NODE*)malloc (sizeof(struct NODE));
        ascii +=1;
        strcpy( array[i] -> string, &ascii);

        array[i]->NEXT = NULL ;
        //printf("%s", array[i] ->string);

    }

    for (int j = 'a' ; j < 'z' ; j++)
    {
        array[j] = (struct NODE*)malloc (sizeof(struct NODE));
        ascii2+=1;
        strcpy( array[j] -> string, &ascii2);

        array[j]->NEXT = NULL ;

        //printf("%s", array[j] ->string);
    }

}



// function to delete a node (specific place)from linked list
void Delete_Node(struct NODE* head)
{

    char deleteW[31];
    printf("Enter the word to delete: ");
    scanf("%s", &deleteW);
    int x = maxString(head);
    int num = x - strlen(deleteW);

    for (int i = 0; i < num; i++)
    {
        strncat(deleteW, " ", sizeof(deleteW) - strlen(deleteW) - 1);
    }

    struct NODE* temp = head->NEXT;
    struct NODE* current_node = NULL;

    // linked list is empty
    if (temp == NULL)
    {
        printf("Error: The linked list is empty.\n");
        return;
    }

    // if the pos is the head of the list
    if (strcasecmp(temp->string, deleteW) == 0)
    {
        head->NEXT = temp->NEXT;
        if (temp->NEXT != NULL)
        {
            temp->NEXT->PREV = NULL;
        }
        free(temp);
        printf("Word deleted!\n");
        return;
    }

    // if the pos is not the head
    while (temp != NULL)
    {
        if (strcasecmp(temp->string, deleteW) == 0)
        {
            current_node->NEXT = temp->NEXT;
            if (temp->NEXT != NULL)
            {
                temp->NEXT->PREV = current_node;
            }
            free(temp);
            printf("Word deleted!\n");
            return;
        }
        current_node = temp;
        temp = temp->NEXT;
    }

    printf("Word not found!\n");
}



//delete all the nodes in a linked list
void DeleteList(struct NODE* L)
{
     // current is initialized with the address of the head node (L)
    struct NODE* current = L;
    struct NODE* nextN;
    //continues as long as current is not NULL
    while (current != NULL)
    {
        //assigned the value of the Next pointer of the current node
        nextN = current->NEXT;
        // frees the memory allocated for the current node
        free(current);
        //updated to point to the next node
        current = nextN;
    }

    // Reset head pointers
    L->NEXT = NULL;
    L->PREV = NULL;
}



// function to radix the strings in the linked list
void Radix_Sort(struct NODE* head)
{

    // Find the max string in the list
    int Max = maxString(head);

    // Add spaces to make all the strings the same length
   addSpace(head);


    // Create an array of linked lists
    struct NODE* Array[63];

    // Initialize each element of the array ( empty linked list for each Position )
    for (int x = 0; x < 63; x++)
    {
        Array[x] = makeEmpty(NULL);
    }

    // Radix Sort from right to left (string )
    for (int i = Max - 1; i >= 0; i--)   // P is the Position
    {

        // distribute nodes into the array
        struct NODE* c = head ->NEXT;
        // loop to put the ascii code for space , numbers(0-9) , upper case , lower case
        while (c != NULL)
        {

            int index;

            //  the current character
            char currentC = c->string[i];
            //space
            if (currentC == ' ')
            {
                index = 0;
            }
            // numbers
            else if ('0' <= currentC && currentC <= '9')
            {
                index = currentC - '0' + 1;
            }
             // uppercase
            else if ('A' <= currentC && currentC <= 'Z')
            {

                index = currentC - 'A' + 11;
            }
             // lowercase
            else if ('a' <= currentC && currentC <= 'z')
            {

                index = currentC - 'a' + 37;
            }

            Insert_At_End(c->string, Array[index]);
            c = c->NEXT;
        }
        // Make a new list and combine the array's nodes back into the first list.
        struct NODE* newL = makeEmpty(NULL);

        for (int i = 0; i < 63; i++)
        {
            struct NODE* c = Array[i] ->NEXT;
            while (c != NULL)
            {

                // Insert the current node into the new list
                Insert_At_End(c->string, newL);

                // Free the memory of the current
                struct NODE* Temp = c->NEXT;
                free(c);
                c = Temp;
            }

            // For the following , reset the array index to an empty list.
            Array[i]->NEXT = NULL;
        }

        // the original list's point to the new list
       head->NEXT = newL->NEXT;
    }

    // Delete the remaining nodes in each array index
    for (int i = 0; i < 63; i++)
    {
        DeleteList(Array[i]);
    }
}



//function to print the sorted string
void print_radix_list(struct NODE * node)
{

    struct NODE * n = node ;
    while(n!=NULL)
    {
        printf("%s\n",n);
        n=n ->NEXT;
    }
}



//function to print the list of the proj
void print ()
{
    printf("\n");
    printf("1. Load the strings from the file.\n");
    printf("2. Print the strings before sorting.\n");
    printf("3. Sort the strings.\n");
    printf("4. Print the sorted strings.\n");
    printf("5. Add a new word to the list of sorted strings (and sort it).\n");
    printf("6. Delete a word from the sorted strings.\n");
    printf("7. Save to output file.\n");
    printf("8. Exit.\n");
}



// Function to load strings from a file and insert into the linked list
void load_From_File(struct NODE* head, const char* filename)
{

    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    char buffer[31];

    // Read strings from the file and insert into the linked list
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        //the first letter is number
        if(!isdigit(buffer[0])){


        // Remove newline character if present
        size_t len = strlen(buffer);
        if (buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
        }

        // Insert the string into the linked list
        Insert_At_End(buffer, head);
    }
    }

    fclose(file);
}



// Function to save sorted strings to an output file
void saveToFile(struct NODE* head, const char* filename)
{

    FILE* file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error: Could not open file %s for writing\n", filename);
        return;
    }

    struct NODE* current = head->NEXT;

    while (current != NULL)
    {
        fprintf(file, "%s\n", current->string);
        current = current->NEXT;
    }

    fclose(file);
}



int main()
{
    struct NODE *list = createlist(); // Create an empty linked list

    int choice;
 char filename[100];
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\||| program to make radix sort to strings |||     \n");
    printf("\n");
    printf("\n");
    printf("\n");
    do
    {
        print(); // Print the menu
 printf("\n");
        printf("----------------------------------------------------------------------------------------------------------------------\n");
        printf("\n");
        printf("Please Enter your choice (from 1 to 8 ) \n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            {

                load_From_File(list, "input.txt");
                printf("\n");
                printf("Strings loaded successfully!\n");
                printf("\n");
            }
            break;

        case 2:
            printf("\n");
            printf("Strings before sorting:\n");
            printf("\n");
            printList(list->NEXT); // Print the unsorted list
            break;

        case 3:
            Radix_Sort(list); // Sort the strings using Radix Sort
            printf("\n");
            printf("Strings sorted successfully!\n");
            printf("\n");
            break;

        case 4:
            printf("\n");
            printf("Sorted strings:\n");
            printf("\n");
            print_radix_list(list->NEXT); // Print the sorted list
            break;

        case 5:
            {
                char newWord[31];
                printf("\n");
                printf("Enter a new word to add to the sorted list: ");
                scanf("%s", newWord);
                Insert_At_End(newWord, list);
                Radix_Sort(list);
                printf("\n");
                printf("Word added and list sorted successfully!\n");
                printf("\n");
            }
            break;

        case 6:
            Delete_Node(list); // Delete a word from the sorted strings
            break;

        case 7:
            // Save to output file


                saveToFile(list, "output.txt");
                printf("\n");
                printf("Sorted strings saved successfully in the file  \n", filename);
break;
        case 8:
            printf("\n");
            printf("Exiting the program. Goodbye!\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 8);

    // Clean up and free memory
    DeleteList(list);

    return 0;
}




