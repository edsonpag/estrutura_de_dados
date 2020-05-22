#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
	int id;
	char name[100];
	float gpa;
} Student;

typedef struct _node {
	Student student;
	struct _node *next;
} Node, *List;

void insert_list (List *student_list, Student student) {
	Node *aux;

	aux = (Node *) malloc (sizeof (Node));

	aux->student = student;
	aux->next = *student_list;

	*student_list = aux;
}

Student *search_list (List student_list, int id) {
	Node *aux;

	for (aux = student_list; aux && aux->student.id != id; aux=aux->next);

	if (aux) {
		return &aux->student;
	}

	else {
		return NULL;
	}
}

void create_list (List *student_list) {
	*student_list = NULL;
}

int main () {
	List student_list;
	Student	student, *selected_student;
	int	id = 0;
	FILE *file;

	file = fopen ("./file/List.txt", "r");

	if (!file) {
		printf("Erro ao ler o arquivo\n");
		exit (1);
	}

	create_list (&student_list);

	while(!feof(file)) {
		fscanf (file, "%d %s %f\n", &student.id, student.name, &student.gpa);
		insert_list (&student_list, student);
	}

	fclose (file);

	while(id != -1) {
		printf ("Enter student ID, -1 to finish: ");
		scanf ("%d", &id);

		selected_student = search_list (student_list, id);

		if (!selected_student) {
			printf ("ID #%d not found!\n", id);
		}

		else {
			printf ("%d\t%s\t%0.2f\n", selected_student->id, selected_student->name, selected_student->gpa);
		}
	}

	return 0;
}