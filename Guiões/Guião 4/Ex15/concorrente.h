
typedef struct concorrente no, *pno;

struct concorrente{
	char nome[200];		/* nome do concorrente */
	int id;				/* n.� de aluno: identificador �nico */
	float analise;		/* n�vel de �lcool no sangue */
	pno prox;
};

