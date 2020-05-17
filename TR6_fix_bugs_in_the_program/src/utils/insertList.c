void insertList (List *student_list, Student student);

void insertList (List *student_list, Student student) {
	Node *aux;

	aux = (Node *) malloc (sizeof (Node));
	aux->current = student;
	aux->next = *student_list;

	*student_list = aux;
}