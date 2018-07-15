# O método
O método da iteração de ponto fixo é usado para resolver equações na forma f(x) = 0, isto é, achar o zero de f(x). O método é implementado rescrevendo a equação como:

                                                        x = g(x)
onde aqui, x assume o papel de ponto fixo da função g(x), isto é, g(x) = x, enquanto para f(x) continua sendo o zero da função. Assim, com uma aproximação inicial x_0 para x (podendo esta ser obtida através de um gráfico) o método consiste em iterar sucessivamente a função dada sobre x_0, ou seja, x_(n + 1) = f^(n + 1)(x_0) = f^(n)((f(x_0)) sendo cada x_(n) uma nova aproximação do ponto fixo x, neste momento do método (com o avançar das iterações) há duas possibilidades, ou x_(n) converge para o ponto fixo, ou diverge.

# Código do Método do Ponto Fixo

```C
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
```
# Resultados

Como podemos ver nos gráficos há uma convergência para x, onde f(x)= 0, aliás para os dois valores propostos. Uma observação a ser feita é a de que apesar da convergência para as duas aproximações iniciais, o número de iterações para alcançar o erro almejado não foi o mesmo, o que nos leva a crer que há aproximações iniciais que são melhores do que outras quando se trata de economizar nas iterações na execução do programa. 

@thadeupenna
