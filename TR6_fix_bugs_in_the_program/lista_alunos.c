#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
	int	id;
	char name[100];
	float gpa;
} Student;

typedef struct _node {
	Student	current;
	struct _node *next;
} Node, *List;


void insert_list (List *L, Student k) {
	Node *p;
	p = (Node *) malloc (sizeof (Node));
	p->current = k;
	p->next = *L;

	*L = p;
}


Student *search_list (List student_list, int id) {
	Node *p;

	for (p=student_list; p && p->current.id != id; p=p->next);

	if (p)
		return &p->current;
	else
		return NULL;
}

void create_list (List *L) {
	*L = NULL;
}


int main () {
	List student_list;
	Student student, *found_student;
	int	id;
	FILE *file;


	file = fopen ("./List.txt", "r");
	if (!file) {
		perror ("List");
		exit (1);
	}

	create_list (&student_list);

	while(!feof(file)) {
		fscanf(file, "%d %s %f\n", &student.id, student.name, &student.gpa);
		insert_list(&student_list, student);
	}	

	fclose (file);

	while(id != -1) {
		printf ("Enter student ID, -1 to finish: ");
		scanf ("%d", &id);

		found_student = search_list (student_list, id);

		if (!found_student)
			printf ("ID #%d not found!\n", id);
		else
			printf ("%d\t%s\t%0.2f\n", found_student->id, found_student->name, found_student->gpa);
	}

	exit (0);
}
