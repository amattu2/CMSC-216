typedef struct {
  char *name;
  unsigned int id;
  float shoe_size;
} Student;

Student *new_student(const char name[], unsigned int id, float shoe_size);
unsigned int has_id(const Student *const student, unsigned int id);
unsigned int has_name(const Student *const student, const char name[]);
unsigned int get_id(const Student *const student);
float get_shoe_size(const Student *const student);
void change_shoe_size(Student *const student, float new_shoe_size);
void change_name(Student *const student, const char new_name[]);
void copy_student(Student *const student1, const Student *const student2);
