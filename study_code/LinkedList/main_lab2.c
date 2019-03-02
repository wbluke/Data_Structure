#include <stdio.h>
#include "LinkedList.h"

void ExecuteListOp(List *plist, char *buffer)
{
    char command;
    int new_element;
    int key;
    command = buffer[0];
    
    switch (command) {
        case 'i':
            sscanf(buffer, "%c %d %d", &command, &new_element, &key);
            LInsert(plist, new_element, key);
            break;
        case 'd':
            sscanf(buffer, "%c %d", &command, &key);
            LDelete(plist, key);
            break;
        case 'f':
            sscanf(buffer, "%c %d", &command, &key);
            FindPreviousNode(plist, key);
            break;
        case 'p':
            PrintList(plist);
            break;
        default:
            printf("Wrong instruction.\n");
    }
}

int main(int argc, const char *argv[])
{
    List list;
    char buffer[10];
    
    InitList(&list);
    //printf("%s\n", list.head);
    //printf("%d\n", IsEmpty(&list));
    
    FILE *fp = fopen(argv[1],"r");
    while(1){
        if(fgets(buffer, sizeof(buffer), fp) == NULL) break;
        
        ExecuteListOp(&list, buffer);
    }
    fclose(fp);
    
    return 0;
}
