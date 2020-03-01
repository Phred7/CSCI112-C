typedef enum {false, true} Bool;

typedef struct {
	int ipA;
	int ipB;
	int ipC;
	int ipD;
	char name[25];
} address_t;

int main(void);
void parseLine(address_t ip[], char line[], int i);
void readFile();
void compare(FILE *out, address_t ip[], int length);
void printAddresses(FILE *out, address_t ip[], int length);