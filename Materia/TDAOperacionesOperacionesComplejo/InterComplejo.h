//InterComplejo.h


struct Com{

	int real;
	int imaginaria;

};

typedef struct Com Complejo;

Complejo res;

Complejo crear(int real, int imaginaria);
Complejo sumar(Complejo real, Complejo imaginaria );
int real(Complejo OperReal);
int imaginaria(Complejo OperImaginaria);


