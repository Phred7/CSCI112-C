#include <stdio.h>
#include <math.h>

void output_corners(double x[], double y[], int actSize); //f(x) declaration
double polygon_area(double x[], double y[], int actSize); //f(x) declaration

/**
*this f(x) fills an x and y array with the x,y coords of a polygon from a file
*this f(x) returns the real length of the array
*/
int get_corners(FILE *file, double x[], double y[], int length){
	int i;

	for(i = 0; i < length; i++){ 
		fscanf(file, "%lf\n %lf", &x[i], &y[i]);
		if(((x[0] == x[i]) && (y[0] == y[i])) && ((i < length) && (i != 0))){ //this if statement is used to determine if the declared length of the arrays is longer than the file itself
			//printf("i: %d: init length is: %d\n", i, length); //used for debugging and testing if the actual length is calculated
			length = i + 1;
			//printf("i: %d: length is now the real size: %d\n", i, length); //used for debugging and testing if the actual length is calculated
		}
	}
	output_corners(x, y, length); //f(x) call
	polygon_area(x, y, length); //f(x) call
	return length;
}

/**
* this f(x) prints the values of the x,y coords within the x and y arrays
*/
void output_corners(double x[], double y[], int actSize){
	int j;
	printf("  x\t  y\n-------------\n");
	for(j = 0; j < actSize; j++){
		printf(" %1.1lf\t %1.1lf\n", x[j], y[j]);
	}
	printf("-------------\n");
}

/**
* this f(x) calculates the area of the polygon defined by the x and y arrays
* this f(x) returns the area as type double
*/
double polygon_area(double x[], double y[], int actSize){
	double area;
	int k;
		
	for(k = 0; k < (actSize - 2); k++){
		area += ((x[k+1] + x[k]) * (y[k+1] - y[k]));
	}
	area = area * 0.5;
	area = fabs(area);
	
	printf("The file defined a polygon whose area is %1.1lf square units.\n", area);
		
	return area;
}

/**
* this f(x) defines the txt file to be used to calculate the area of a polygon, 
* calls the f(x) to begin running the f(x)'s in the correct order, 
* closes the file when finished
* this f(x) returns 0
*/
int main(int argc, char* arcv[]){
	int size = 255;
	double x[size], y[size];
	
	FILE *file;
	file = fopen("/public/csci112sp19/lab4/x_y_polygon.txt", "r"); //opens file from defined server directory
	
	get_corners(file, x, y, size); //f(x) call
	fclose(file); //closes the file
	return 0;
}