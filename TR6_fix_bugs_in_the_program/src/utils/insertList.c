void insertList (List *L, Student k);

void insertList (List *L, Student k) {
	Node *p;
	p = (Node *) malloc (sizeof (Node));
	p->current = k;
	p->next = *L;

	*L = p;
}