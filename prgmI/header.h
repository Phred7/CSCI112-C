typedef enum {false, true} Bool;

typedef struct {
	char number[80];
	char name[80];
	char days[80];
	char time[80];
	int year;
} classes_t;   

void parseLine(classes_t cls[], char read[], int i);
void getClasses();
void sort(FILE *out, classes_t cls[], char* type, int length);
int printOptions();
int printOptionsDay();
int printOptionsYear();
void printClass(FILE *out, classes_t cls[], int index);
void printDayType(FILE *out, char* type);
void printNumber(FILE *out);
void printTime(FILE *out);
void printLevel(FILE *out, int year);
void promptUser(classes_t cls[], int length);