#include <stdio.h>
#define END -1 

typedef enum {false, true} bool;


bool search(const int* array, int num_to_find) {
    bool found = false;
    int i = 0;

    while(!found && array[i] != END) {
        if (array[i] == num_to_find) {        
            found = true;
        }
        else {
            ++i;
        }
    }
    return found;
}

int main() {

    int no_read = 1,
        num,
        num_to_search,
        i,
        array[50];

    bool found;

    FILE* inpf = fopen("numbers.txt", "r");
    for (i = 0; no_read == 1; ++i)  {
        no_read = fscanf(inpf, "%d", &num);
        if (no_read == 1) {
            array[i] = num; 
        }
        else {
            array[i] = END;
        }
    }
    fclose(inpf);
 
    while (1) {
        printf("Enter number to search for or -1 to quit: ");
        scanf("%d", &num_to_search);
        if (num_to_search == -1) {
            break;
        }
        found = search(array, num_to_search);
        printf("%d was found? %s\n", num_to_search, (found? "yes" : "no"));
    }
    return(0);
}
    




