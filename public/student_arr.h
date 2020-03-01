// structure to define a student
// notice the way the elements of the structure are declared (, ;)
typedef struct {

	char* name;  // name of student

	int id,      // id number
	    cur_class_nos[5], // classes student is currently taking
	    credits; // number of credits student has

	char year;   // use 'f', 's', 'j', 'r' (senior)

} student_t;  // to make a user defined type stand out, use _t in type name
