#include <stdio.h>
#include "class.h"

int main() {
    class_t classes[50];

    // read in the text class file and put classes in array
    int size = ReadTxtClasses(classes);

    // write array to a binary file
    WriteBinClasses(classes, size);

    // Now read the binary file and print out the classes
    ReadPrintBinClasses();
    return(0);
}
