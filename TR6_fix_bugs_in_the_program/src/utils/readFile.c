void readFile();

void readFile(List *student_list) {
    Student student;
	FILE *file;

    printf("Lendo o arquivo...\n");

    file = fopen ("../archives/List.txt", "r");
	if (!file) {
		perror ("List");
		exit (1);
	}

	*student_list = NULL;

	while(!feof(file)) {
		fscanf(file, "%d %s %f\n", &student.id, student.name, &student.gpa);
		insertList(student_list, student);
	}	

	fclose (file);
}



