#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int  SolucaoPontoFixo(double *x_0, double precisao){	
	double x, diff;
	int num_iteracoes = 0;
	FILE *fp = fopen("solucao.txt", "w");
	
	do{
		fprintf(fp, "%d %.12lf\n", num_iteracoes, *x_0);
			
		x = cos(*x_0);
		diff = fabs(x-*x_0);
		*x_0 = x;
		
		num_iteracoes++;
	} while(diff > precisao);
	
	fclose(fp);
	return(num_iteracoes);
}

int main(int argc, char **argv) //main foi dada como modelo a ser seguido pelo professor
{	double x, x0, dx, prec;

	x0 = atof(argv[1]);
	prec = atof(argv[2]);
	
	printf("\nRaiz = %.10g em %d iterações\n", x0, SolucaoPontoFixo(&x0, prec));
	
	return(0);	
}