#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert_list (List *student_list, Student student);
Student *search_list (List student_list, int id);
void create_list (List *student_list);
List read_file();
void findById();




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

List read_file() {
	List student_list;
	Student	student;
	
	FILE *file;

	printf("Lendo o arquivo...\n");
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

	return student_list;
}

void findById() {
	Student *selected_student;
	int id = 0;

	List student_list = read_file();

	while(id != -1) {
		printf ("Digite o ID do estudante, -1 para voltar ao menu: ");
		scanf ("%d", &id);

		selected_student = search_list (student_list, id);

		!selected_student ? printf("Estudante não encontrado\n") : printf("%d\t%s\t%0.2f\n", selected_student->id, selected_student->name, selected_student->gpa);
	}
}