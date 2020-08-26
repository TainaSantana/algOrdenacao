#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    int alg, qtd, result;

    //menu de seleção de algoritmos
    printf("###########################################################################\n");
    printf("#                       Algoritmos de ordenação                           #\n");
    printf("# Escolha um valor de 1 a 11                                              #\n");
    printf("# 1 - BeadSort                                                            #\n");
    printf("# 2 - BubbleSort                                                          #\n");
    printf("# 3 - CountingSort                                                        #\n");
    printf("# 4 - HeapSort                                                            #\n");
    printf("# 5 - InsertionSort                                                       #\n");
    printf("# 6 - MergeSort                                                           #\n");
    printf("# 7 - RadixSort                                                           #\n");
    printf("# 8 - SelectionSort                                                       #\n");
    printf("# 9 - ShellSort                                                           #\n");
    printf("# 10 - TimSort                                                            #\n");
    printf("# 11 - QuickSort                                                          #\n");
    printf("# Pressione 0 (zero) para sair                                            #\n");
    printf("###########################################################################\n");

    printf("\nInforme o número correspondente ao algoritmo a ser analisado: ");
    scanf("%d", &alg);

    if(alg >= 1 && alg <= 11){
        system("cls");
        printf("Escolha a quantidade de elementos a serem ordenados\n");
        printf("1 - 1000 elementos \n");
        printf("2 - 5000 elementos \n");
        printf("3 - 10000 elementos\n");
        printf("4 - 20000 elementos\n");
        printf("5 - 50000 elementos\n");
        printf("6 - 100000 elementos\n");

        printf("Informe um número de 1 a 6 correspondente a quantidade de elementos: \n");
        scanf("%d", &qtd);
        switch(qtd){
        case 1:
            qtd = 25;
            break;
        case 2:
            qtd = 5000;
            break;
        case 3:
            qtd = 10000;
            break;
        case 4:
            qtd = 20000;
            break;
        case 5:
            qtd = 50000;
            break;
        case 6:
            qtd = 100000;
            break;
        default:
            printf("Selecionou valor invalido");
            break;
        }
        result = algoritmoEscolhido(alg, qtd);
        //printf("\nChamada da funcao: %d", result);

    }
    else{
        printf("Valor incorreto");
    }

}

//funcao que recebe o algoritmo de ordenacao e a quantidade de elementos
int algoritmoEscolhido(int alg, int qtd){

    int i, j, *v;

    switch(alg){
    case 1:
        printf("Algoritmo: BeadSort\n"); //alterar ordem depois
       //for(i = 0; i < 2; i++){
            v = (int *) malloc(qtd * sizeof(int));
            for (j = 0; j < qtd; j++){
                //v = malloc(qtd * sizeof(int));
                /* gerando valores aleatórios entre zero e 1000 */
                v[j] = rand() % 1000;
                printf("%d = %d\n", j, v[j]);
            }
            bead_sort(v, qtd);
            printf("Vetor ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
    }
        //}


        break;
    case 2:
        printf("Algoritmo escolhido: Bubblesort");
        //for(i = 0; i < 2; i++){
            v = (int *) malloc(qtd * sizeof(int));
            for (j = 0; j < qtd; j++){
                //v = malloc(qtd * sizeof(int));
                /* gerando valores aleatórios entre zero e 1000 */
                v[j] = rand() % 1000;
                printf("%d = %d\n", j, v[j]);
            }
            bubble_sort(v, qtd);
            printf("Vetor ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
    }
        //}
        break;
    case 3:
        printf("Algoritmo escolhido: CountingSort");
        break;
    case 4:
        printf("Algoritmo escolhido: HeapSort");
        //for(i = 0; i < 2; i++){
            v = (int *) malloc(qtd * sizeof(int));
            for (j = 0; j < qtd; j++){
                //v = malloc(qtd * sizeof(int));
                /* gerando valores aleatórios entre zero e 1000 */
                v[j] = rand() % 1000;
                printf("%d = %d\n", j, v[j]);
            }
            HeapSort(v, qtd);
            printf("Vetor ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
    }
        //}
        break;
    case 5:
        printf("Algoritmo escolhido: InsertionSort");
        break;
    case 6:
        printf("Algoritmo escolhido: MergeSort\n");
        //for(i = 0; i < 2; i++){
            v = (int *) malloc(qtd * sizeof(int));
            for (j = 0; j < qtd; j++){
                //v = malloc(qtd * sizeof(int));
                /* gerando valores aleatórios entre zero e 1000 */
                v[j] = rand() % 1000;
                printf("%d = %d\n", j, v[j]);
            }
            mergeSort(v, 0, qtd - 1);
            printf("Vetor ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            }
        //}
        break;
    case 7:
        printf("Algoritmo escolhido: RadixSort");
        break;
    case 8:
        printf("Algoritmo: SelectionSort");
        break;
    case 9:
        printf("Algoritmo: ShellSort");
        break;
    case 10:
        printf("Algoritmo: TimSort");
        break;
    case 11:
        printf("Algoritmo: QuickSort");
        //for(i = 0; i < 2; i++){
            v = (int *) malloc(qtd * sizeof(int));
            for (j = 0; j < qtd; j++){
                //v = malloc(qtd * sizeof(int));
                /* gerando valores aleatórios entre zero e 1000 */
                v[j] = rand() % 1000;
                printf("%d = %d\n", j, v[j]);
            }
            quick_sort(v, 0, qtd - 1);
            printf("Vetor ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            }
        //}

        break;

    }


}

void bead_sort(int *a, int qtd)
{
    //SUM = SOMA DA COLUNA
	int i, j, max, sum;
	unsigned char *beads;
//S�O COMO PONTOS DE CORDENADA EM UM PLANO CARTESIANO
#	define BEAD(i, j) beads[i * max + j]

    //COLOCA O MAIOR VALOR DO VETOR DENTRO DA VARIAVEL MAX
	for (i = 1, max = a[0]; i < qtd; i++)
		if (a[i] > max) max = a[i];
    //ALOCA MEMORIA
	beads = calloc(1, max * qtd);

	/* mark the beads */
	//MARCA EM TODOS FEIJ�ES VERDADEIRO
	//USA O i COMO LINHA E O j COMO COLUNA
	for (i = 0; i < qtd; i++)
		for (j = 0; j < a[i]; j++)
            //AQUI ELE TA COLOCANDO QUE NESSA POSI��O TEMOS UM FEIJ�O, POR ISSO VERADEIRO
			BEAD(i, j) = 1;
    //AQUI ELE VAI POR COLUNA CONTANDO OS FEIJ�ES CONSIDERANDO QUE ESSE SORT CONTA AS COLUNAS DO ABACO PARA SABER O VALOR DOS NUMEROS
    //N�O AS LINHAS COMO FARIAMOS NO USO NORMAL DO ABACO
	for (j = 0; j < max; j++) {
		/* count how many beads are on each post */
		//AQUI DEPOIS DE SOMAR FEIJ�O POR FEIJ�O DA COLUNA ELE ATRIBUI O FALSE PARA AQUELA POSI��O, JA QUE JA FOI UTILIZADA
		for (sum = i = 0; i < qtd; i++) {
			sum += BEAD(i, j);
			BEAD(i, j) = 0;
		}
		/* mark bottom sum beads */
		//AQUI ELE VAI SUBTRAIR A SOMA DO NUMERO DE COLUNAS E INICIA O FOR A PARTIR DISSO ASSIM ELE FAZ COM QUE OS FEIJ�ES ANDEM PARA A ESQUERDA AT� ENCONTRAR UM EMPECILHO, OU SEJA, OUTRO FEIJ�O
		for (i = qtd - sum; i < qtd; i++) BEAD(i, j) = 1;
	}
    //VAI RODAR TORNANDO OS FEIJ�ES N�MEROS
	for (i = 0; i < qtd; i++) {
		for (j = 0; j < max && BEAD(i, j); j++);
		a[i] = j;
	}
	//free(beads);
}

void bubble_sort(int *v, int qtd)
{

	int i, continua, aux, fim = qtd;

    do {
        continua = 0;
        for(i = 0; i < fim; i++){
            if(v[i] > v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua = i;

            }
        }
        fim--;
    } while(continua != 0);


}

void HeapSort(int *v, int qtd){
    int i, aux;

    for(i=(qtd-1)/2; i>=0; i--){
        CriandoHeap(v, i, qtd-1);
    }

    for(i=(qtd-1); i>0; i--){
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        CriandoHeap(v, 0, i-1);
    }
}

void CriandoHeap(int *v, int ini, int fim){
    int filho = 2*ini + 1, aux = v[ini], i;

    while(filho <= fim){

        if(filho < fim){
            if(v[filho] < v[filho + 1]){
                filho += 1;
            }
        }

        if(v[filho] > aux){
            v[ini] = v[filho];
            ini = filho;
            filho = ini*2 + 1;
        }else{
            filho = fim + 1;
        }

    }

    v[ini] = aux;
}

void merge(int *v, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = v[l + i];
	for (j = 0; j < n2; j++)
		R[j] = v[m + 1+ j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			v[k] = L[i];
			i++;
		}
		else
		{
			v[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		v[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		v[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int *v, int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l+(r-l)/2;

		// Sort first and second halves
		mergeSort(v, l, m);
		mergeSort(v, m+1, r);

		merge(v, l, m, r);
	}
}


//funcao do quicksort, particiona e retorna o indice do pivo
int particiona(int *v, int ini, int fim) {
    int esq, dir, pivo, aux;

    esq = ini; //esquerda é o inicio
    dir = fim; //direita eh o final
    pivo = v[ini]; //pivo recebe o inicio do vetor

    while(esq < dir) {
        while(esq <= fim && v[esq] <= pivo) { //avanca posicao da esquerda até achar um elemento que n seja menor que o pivo
            esq++;
        }
        while(dir >= 0 && v[dir] > pivo) { //recua posicao da direita enquanto os elementos forem menor que o pivo
            dir--;
        }
        //se a esquerda for maior que a direita faz a troca dps elementos
        if(esq < dir) {
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }
    v[ini] = v[dir]; //inicio recebe o ultimo valor da direita
    v[dir] = pivo; //posicao da direita se torna o pivo
    return dir;


}

// funcao do quick sort
void quick_sort(int *v, int ini, int fim){

    int pivo;

    //utiliza recursividade para ordenar as particoes
    if(ini < fim) {
        pivo = particiona(v, ini, fim); //chama a funcao que separa os dados em 2 particoes
        quick_sort(v, ini, pivo - 1);
        quick_sort(v, pivo + 1, fim);
    }

}
