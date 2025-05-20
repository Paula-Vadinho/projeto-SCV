#include <stdio.h>
#include <stdlib.h>
#define Nnome 49

struct produto
{
    char nome [Nnome];
    int codigo; 
	int Qestoque;
    float Pvenda;
	int Cvenda;
	float Vtotal;
}
int main()
{
	printf("\n\t\t\t Bem vindo a loja de Informatica");
	printf("digite o produto");
	

	system("pause");
	return 0;
}
