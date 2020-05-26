typedef struct _student {
    int id;
	char name[100];
	float gpa;
} Student;

typedef struct _node {
	Student student;
	struct _node *next;
	struct _node *prev;
} Node, *List;
