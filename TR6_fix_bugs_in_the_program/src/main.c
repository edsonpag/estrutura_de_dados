#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./structs/Student.c"
#include "./structs/Node.c"

#include "./utils/createList.c"
#include "./utils/insertList.c"
#include "./utils/readFile.c"


Student *search_list (List student_list, int id) {
	Node *p;

	for (p=student_list; p && p->current.id != id; p=p->next);

	if (p)
		return &p->current;
	else
		return NULL;
}




int main () {
	List student_list;
	Student *found_student;
	int	id;


	readFile(&student_list);

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