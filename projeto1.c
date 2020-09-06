#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
#include<sys/time.h>

int main(){

    (LC_ALL, "Portuguese");

    int alg, qtd, result;

    //menu de seleção de algoritmos
    printf("###########################################################################\n");
    printf("#                       Algoritmos de ordenacao                           #\n");
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
    printf("###########################################################################\n");

    //armazena o valor correspondente ao algoritmo escolhido pelo usuario
    printf("\nInforme o numero correspondente ao algoritmo a ser analisado: ");
    scanf("%d", &alg);

    //se o valor estiver entre 1 e 11 (incluindo ambos os valores), o usuario seleciona a qtd de elementos
    if(alg >= 1 && alg <= 11){
        system("cls");
        printf("Escolha a quantidade de elementos a serem ordenados\n");
        printf("1 - 1000 elementos \n");
        printf("2 - 5000 elementos \n");
        printf("3 - 10000 elementos\n");
        printf("4 - 20000 elementos\n");
        printf("5 - 50000 elementos\n");
        printf("6 - 100000 elementos\n");

        printf("Informe um numero de 1 a 6 correspondente a quantidade de elementos: \n");
        scanf("%d", &qtd);
        switch(qtd){
        case 1:
            qtd = 1000;
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
            printf("Valor invalido!");
            break;
        }
        result = algoritmoEscolhido(alg, qtd);
        //printf("\nChamada da funcao: %d", result);

    }
    else{
        printf("Valor invalido!");
    }

    system("pause");
    return 0;

}


void printRelatorio(int qtd, float tmp_medio[]) {
  printf("Quantidade de elementos ordenados: %d\n", qtd);
  printf("Tempo medio de ordenacao de vetores aleatorios: %f\n", tmp_medio[0]);
  printf("Tempo de ordenacao de vetores crescentes: %f\n", tmp_medio[1]);
  printf("Tempo medio de ordenacao de vetores decrescentes: %f\n", tmp_medio[2]);

}

//funcao que recebe o algoritmo de ordenacao e a quantidade de elementos
int algoritmoEscolhido(int alg, int qtd){

    int i, j, *v;
    struct timeval tempo_antes, tempo_depois;
    double deltaT, soma = 0;
    float *tmp_medio;

    tmp_medio = malloc(3 * sizeof(float));

    switch(alg){
    case 1:

    printf("Algoritmo: BeadSort\n");

        for(i = 0; i < 10; i++){
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            srand(time(NULL));
            for (j = 0; j < qtd; j++){
                /* gerando valores aleatórios entre zero e 1000 */
                v[j] = rand() % 1000;
                //printf("%d = %d\n", j, v[j]);
            }
            bead_sort(v, qtd);

            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            deltaT = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            //free(v);
            soma += deltaT;


            /*printf("Vetor ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            }*/
             free(v);

            /*printf("\nTempo de execução usando gettime: %f segundos \n", deltaT);
            printf("\nSomatoria do tempo: %f\n", soma);
            printf("\nTempo medio: %f\n", tmp_medio[0]);*/


        }
        tmp_medio[0] = soma / 10;

        /*Tempo de execucao de vetor em ordem crescente*/
            v = malloc (qtd * sizeof(int));
            //Percorre o vetor de forma ordenada
            gettimeofday(&tempo_antes, NULL);
            for(int i = 0; i < qtd; i++){
                v[i] = i;
                //printf("%d ", v[i]);
            }
            bead_sort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[1] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            //printf("\nTempo de execução dos vetores ordenados %f: \n", tmp_medio[1]);
            free(v);

            /* Tempo de execução do vetor em ordem decrescente*/
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            for(int i = 0; i < qtd; i++){
                v[i] = qtd - i;
                //printf("%d ", v[i]);
            }
            bead_sort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[2] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v);

            /*printf("Vetor decrescente ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            }*/
            //printf("\nTempo de execução dos vetores ordenados %f: \n", tmp_medio[2]);
            printRelatorio(qtd, tmp_medio);

        break;
    case 2:
        printf("Algoritmo escolhido: Bubblesort\n");
        for(i = 0; i < 10; i++){
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            srand(time(NULL));
            for (j = 0; j < qtd; j++){
                /* gerando valores aleatórios entre zero e 1000 */
                v[j] = rand() % 1000;
                //printf("%d = %d\n", j, v[j]);
            }
            bubble_sort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            deltaT = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            //free(v);
            soma += deltaT;
            tmp_medio[0] = soma / 10;

            /*printf("Vetor ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            }*/
            free(v);

           /* printf("\nTempo de execução usando gettime: %f segundos \n", deltaT);
            printf("\nSomatoria do tempo: %f\n", soma);
            printf("\nTempo medio: %f\n", tmp_medio[0]);*/
        }

        /*Tempo de execucao de vetor em ordem crescente*/
            v = malloc (qtd * sizeof(int));
            //Percorre o vetor de forma ordenada
            gettimeofday(&tempo_antes, NULL);
            for(int i = 0; i < qtd; i++){
                v[i] = i;
                //printf("%d ", v[i]);
            }
            bubble_sort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[1] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            //printf("\nTempo de execução dos vetores ordenados %f: \n", tmp_medio[1]);
            free(v);

            /* Tempo de execução do vetor em ordem decrescente*/
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            printf("\nVetor decrescente calc2\n");
            for(int i = 0; i < qtd; i++){
                v[i] = qtd - i;
                //printf("%d ", v[i]);
            }
            bubble_sort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[2] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            //free(v);

            /*printf("Vetor decrescente ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            }*/
            //printf("\nTempo de execução dos vetores ordenados %f: \n", tmp_medio[2]);

            printRelatorio(qtd, tmp_medio);
        break;
    case 3:
        printf("Algoritmo escolhido: CountingSort\n");
        for(i = 0; i < 10; i++){
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            srand(time(NULL));
            for (j = 0; j < qtd; j++){
                /* gerando valores aleatórios entre zero e 1000 */
                v[j] = rand() % 10000;
                //printf("%d = %d\n", j, v[j]);
            }
            countingSort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            deltaT = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            soma += deltaT;



            /*printf("Vetor ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            }*/

            free(v);

            //printf("\nTempo de execução usando gettime: %f segundos \n", deltaT);


       }
        tmp_medio[0] = soma / 10;
        //printf("\n1. Tempo medio: %f\n", tmp_medio[0]);
        //printf("\nSomatoria do tempo: %f\n", soma);



        /*Tempo de execucao de vetor em ordem crescente*/
            v = malloc (qtd * sizeof(int));
            //Percorre o vetor de forma ordenada
            gettimeofday(&tempo_antes, NULL);
            for(int i = 0; i < qtd; i++){
                v[i] = i;
                //printf("%d ", v[i]);
            }
            countingSort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[1] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            //printf("\n1. Tempo de execução dos vetores ordenados %f: \n", tmp_medio[1]);
            free(v);

            /* Tempo de execução do vetor em ordem decrescente*/
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            for(int i = 0; i < qtd; i++){
                v[i] = qtd - i;
                //printf("%d ", v[i]);
            }
            countingSort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[2] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v);

            /*printf("Vetor decrescente ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            }*/

            printRelatorio(qtd, tmp_medio);


        break;
    case 4:
        printf("Algoritmo escolhido: HeapSort\n");
        for(i = 0; i < 10; i++){
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            srand(time(NULL));
            for (j = 0; j < qtd; j++){
                /* gerando valores aleatórios entre zero e 1000 */
                v[j] = rand() % 1000;
                //printf("%d = %d\n", j, v[j]);
            }
            HeapSort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            deltaT = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            soma += deltaT;


            /*printf("Vetor ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            }*/
            free(v);

            //printf("\nTempo de execução usando gettime: %f segundos \n", deltaT);
            //printf("\nSomatoria do tempo: %f\n", soma);

        }
        tmp_medio[0] = soma / 10;
        //printf("\nTempo medio: %f\n", tmp_medio[0]);

        /*Tempo de execucao de vetor em ordem crescente*/
            v = malloc (qtd * sizeof(int));
            //Percorre o vetor de forma ordenada
            gettimeofday(&tempo_antes, NULL);
            for(int i = 0; i < qtd; i++){
                v[i] = i;
                //printf("%d ", v[i]);
            }
            HeapSort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[1] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            //printf("\nTempo de execução dos vetores ordenados %f: \n", tmp_medio[1]);
            free(v);

            /* Tempo de execução do vetor em ordem decrescente*/
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio

            for(int i = 0; i < qtd; i++){
                v[i] = qtd - i;
                //printf("%d ", v[i]);
            }
            HeapSort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[2] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            //free(v);

            /*printf("Vetor decrescente ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            }*/
            //printf("\nTempo de execução dos vetores decrescentes %f: \n\n", tmp_medio[2]);
            printRelatorio(qtd, tmp_medio);
        break;
    case 5:
        printf("Algoritmo escolhido: InsertionSort\n");
        for(i = 0; i < 10; i++){
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            srand(time(NULL));
            for (j = 0; j < qtd; j++){
                /* gerando valores aleatórios entre zero e 1000 */
                v[j] = rand() % 1000;
                //printf("%d = %d\n", j, v[j]);
            }
            Insertion_Sort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            deltaT = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            soma += deltaT;


            /*printf("Vetor ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            */
            free(v);

            //printf("\nTempo de execução usando gettime: %f segundos \n", deltaT);
            //printf("\nSomatoria do tempo: %f\n", soma);

        }
        tmp_medio[0] = soma / 10;
        //printf("\nTempo medio: %f\n", tmp_medio[0]);

        /*Tempo de execucao de vetor em ordem crescente*/
            v = malloc (qtd * sizeof(int));
            //Percorre o vetor de forma ordenada
            gettimeofday(&tempo_antes, NULL);
            for(int i = 0; i < qtd; i++){
                v[i] = i;
                //printf("%d ", v[i]);
            }
            Insertion_Sort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[1] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            //printf("\nTempo de execução dos vetores ordenados %f: \n", tmp_medio[1]);
            free(v);

            /* Tempo de execução do vetor em ordem decrescente*/
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            for(int i = 0; i < qtd; i++){
                v[i] = qtd - i;
                //printf("%d ", v[i]);
            }
            Insertion_Sort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[2] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);


            /*printf("Vetor decrescente ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            }*/
            free(v);
            //printf("\nTempo de execução dos vetores decrescentes %f: \n", tmp_medio[2]);

            printRelatorio(qtd, tmp_medio);
        break;
    case 6:
        printf("Algoritmo escolhido: MergeSort\n");

        for(i = 0; i < 10; i++){
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            srand(time(NULL));
            for (j = 0; j < qtd; j++){
                /* gerando valores aleatórios entre zero e 1000 */
                v[j] = rand() % 1000;
                //printf("%d = %d\n", j, v[j]);
            }
            mergeSort(v, 0, qtd - 1);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            deltaT = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            soma += deltaT;

            /*printf("Vetor ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            }*/
            free(v);

            //printf("\nTempo de execução usando gettime: %f segundos \n", deltaT);
            //printf("\nSomatoria do tempo: %f\n", soma);

        }
        tmp_medio[0] = soma / 10;
        //printf("\nTempo medio: %f\n", tmp_medio[0]);

        /*Tempo de execucao de vetor em ordem crescente*/
            v = malloc (qtd * sizeof(int));
            //Percorre o vetor de forma ordenada
            gettimeofday(&tempo_antes, NULL);
            for(int i = 0; i < qtd; i++){
                v[i] = i;
                //printf("%d ", v[i]);
            }
            mergeSort(v, 0, qtd - 1);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[1] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            //printf("\nTempo de execução dos vetores ordenados %f: \n", tmp_medio[1]);
            free(v);

            /* Tempo de execução do vetor em ordem decrescente*/
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            for(int i = 0; i < qtd; i++){
                v[i] = qtd - i;
                //printf("%d ", v[i]);
            }
            mergeSort(v, 0, qtd - 1);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[2] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v);

            /*printf("Vetor decrescente ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            }*/
            //printf("\nTempo de execução dos vetores ordenados %f: \n", tmp_medio[2]);

            printRelatorio(qtd, tmp_medio);
        break;
    case 7:
        printf("Algoritmo escolhido: RadixSort\n");
        for(i = 0; i < 10; i++){
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            srand(time(NULL));
            for (j = 0; j < qtd; j++){
                /* gerando valores aleatórios entre zero e 1000 */
                v[j] = rand() % 1000;
                //printf("%d = %d\n", j, v[j]);
            }
            radixsort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            deltaT = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            soma += deltaT;

            /*printf("Vetor ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            }*/
            free(v);

            //printf("\nTempo de execução usando gettime: %f segundos \n", deltaT);
            //printf("\nSomatoria do tempo: %f\n", soma);

        }
        tmp_medio[0] = soma / 10;
        //printf("\nTempo medio: %f\n", tmp_medio[0]);

        /*Tempo de execucao de vetor em ordem crescente*/
        /*aqui nao funciona
            v = malloc (qtd * sizeof(int));
            //Percorre o vetor de forma ordenada
            gettimeofday(&tempo_antes, NULL);
            for(int i = 0; i < qtd; i++){
                v[i] = i;
                printf("%d ", v[i]);
            }
            radixsort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[1] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            printf("\nTempo de execução dos vetores ordenados %f: \n", tmp_medio[1]);
            free(v);*/

            /* Tempo de execução do vetor em ordem decrescente*/
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            for(int i = 0; i < qtd; i++){
                v[i] = qtd - i;
                //printf("%d ", v[i]);
            }
            radixsort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[2] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            //free(v);

            /*printf("Vetor decrescente ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            }*/
            free(v);
            //printf("\nTempo de execução dos vetores decrescentes %f: \n", tmp_medio[2]);

            printRelatorio(qtd, tmp_medio);

        break;
    case 8:
        printf("Algoritmo: SelectionSort\n");
        for(i = 0; i < 10; i++){
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            srand(time(NULL));
            for (j = 0; j < qtd; j++){
                /* gerando valores aleatórios entre zero e 1000 */
                v[j] = rand() % 1000;
                //printf("%d = %d\n", j, v[j]);
            }
            selectionSort(v, qtd);

            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            deltaT = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            soma += deltaT;


            /*printf("Vetor ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            }*/
            free(v);

            //printf("\nTempo de execução usando gettime: %f segundos \n", deltaT);
            //printf("\nSomatoria do tempo: %f\n", soma);

        }
        tmp_medio[0] = soma / 10;
        //printf("\nTempo medio: %f\n", tmp_medio[0]);

        /*Tempo de execucao de vetor em ordem crescente*/
            v = malloc (qtd * sizeof(int));
            //Percorre o vetor de forma ordenada
            gettimeofday(&tempo_antes, NULL);
            for(int i = 0; i < qtd; i++){
                v[i] = i;
                //printf("%d ", v[i]);
            }
            selectionSort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[1] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            //printf("\nTempo de execução dos vetores ordenados %f: \n", tmp_medio[1]);
            free(v);

            /* Tempo de execução do vetor em ordem decrescente*/
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio

            for(int i = 0; i < qtd; i++){
                v[i] = qtd - i;
                //printf("%d ", v[i]);
            }
            selectionSort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[2] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            //free(v);

            /*printf("Vetor decrescente ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            }*/
            //printf("\nTempo de execução dos vetores ordenados %f: \n", tmp_medio[2]);

            printRelatorio(qtd, tmp_medio);


        break;
    case 9:
        printf("Algoritmo: ShellSort\n");
        for(i = 0; i < 10; i++){
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            srand(time(NULL));
            for (j = 0; j < qtd; j++){
                /* gerando valores aleatórios entre zero e 1000 */
                v[j] = rand() % 1000;
                //printf("%d = %d\n", j, v[j]);
            }
            shellSort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            deltaT = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            soma += deltaT;


            /*printf("Vetor ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            }*/
            free(v);

            //printf("\nTempo de execução usando gettime: %f segundos \n", deltaT);
            //printf("\nSomatoria do tempo: %f\n", soma);


        }
        tmp_medio[0] = soma / 10;
         //printf("\nTempo medio: %f\n", tmp_medio[0]);

        /*Tempo de execucao de vetor em ordem crescente*/
            v = malloc (qtd * sizeof(int));
            //Percorre o vetor de forma ordenada
            gettimeofday(&tempo_antes, NULL);
            for(int i = 0; i < qtd; i++){
                v[i] = i;
                //printf("%d ", v[i]);
            }
            shellSort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[1] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            //printf("\nTempo de execução dos vetores ordenados %f: \n", tmp_medio[1]);
            free(v);

            /* Tempo de execução do vetor em ordem decrescente*/
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio

            /*for(int i = 0; i < qtd; i++){
                v[i] = qtd - i;
                printf("%d ", v[i]);
            }*/
            shellSort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[2] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            //free(v);

            /*printf("Vetor decrescente ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            }*/
            //printf("\nTempo de execução dos vetores decrescentes %f: \n", tmp_medio[2]);

            printRelatorio(qtd, tmp_medio);

        break;
    case 10:
        printf("Algoritmo: TimSort\n");
        for(i = 0; i < 10; i++){
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            srand(time(NULL));
            for (j = 0; j < qtd; j++){
                /* gerando valores aleatórios entre zero e 1000 */
                v[j] = rand() % 1000;
                //printf("%d = %d\n", j, v[j]);
            }
            timSort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            deltaT = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            soma += deltaT;


            /*printf("Vetor ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            }*/
            free(v);

            //printf("\nTempo de execução usando gettime: %f segundos \n", deltaT);
            //printf("\nSomatoria do tempo: %f\n", soma);

        }
        tmp_medio[0] = soma / 10;
        //printf("\nTempo medio: %f\n", tmp_medio[0]);

        /*Tempo de execucao de vetor em ordem crescente*/
            v = malloc (qtd * sizeof(int));
            //Percorre o vetor de forma ordenada
            gettimeofday(&tempo_antes, NULL);
            for(int i = 0; i < qtd; i++){
                v[i] = i;
                //printf("%d ", v[i]);
            }
            timSort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[1] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            //printf("\nTempo de execução dos vetores ordenados %f: \n", tmp_medio[1]);
            free(v);

            /* Tempo de execução do vetor em ordem decrescente*/
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio

            for(int i = 0; i < qtd; i++){
                v[i] = qtd - i;
                //printf("%d ", v[i]);
            }
            timSort(v, qtd);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[2] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            //free(v);

            /*printf("Vetor decrescente ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            }*/
            //printf("\nTempo de execução dos vetores decrescentes %f: \n", tmp_medio[2]);

            printRelatorio(qtd, tmp_medio);
        break;
    case 11:
        printf("Algoritmo: QuickSort\n");
        for(i = 0; i < 10; i++){
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            srand(time(NULL));
            for (j = 0; j < qtd; j++){
                //v = malloc(qtd * sizeof(int));
                /* gerando valores aleatórios entre zero e 1000 */
                v[j] = rand() % 1000;
                //printf("%d = %d\n", j, v[j]);
            }
            quick_sort(v, 0, qtd - 1);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            deltaT = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            soma += deltaT;


            /*printf("Vetor ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            }*/
            free(v);

            //printf("\nTempo de execução usando gettime: %f segundos \n", deltaT);
            //printf("\nSomatoria do tempo: %f\n", soma);

        }
        tmp_medio[0] = soma / 10;
        //printf("\nTempo medio: %f\n", tmp_medio[0]);


        /*Tempo de execucao de vetor em ordem crescente*/
            v = malloc (qtd * sizeof(int));
            //Percorre o vetor de forma ordenada
            gettimeofday(&tempo_antes, NULL);
            for(int i = 0; i < qtd; i++){
                v[i] = i;
                //printf("%d ", v[i]);
            }
            quick_sort(v, 0, qtd - 1);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[1] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            //printf("\nTempo de execução dos vetores ordenados %f: \n", tmp_medio[1]);
            free(v);

            /* Tempo de execução do vetor em ordem decrescente*/
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio

            for(int i = 0; i < qtd; i++){
                v[i] = qtd - i;
                //printf("%d ", v[i]);
            }
            quick_sort(v, 0, qtd - 1);
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[2] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v);

           /* printf("Vetor decrescente ordenado\n");
            for(int i = 0; i < qtd; i++){
                printf("%d ", v[i]);
            }
            printf("\nTempo de execução dos vetores decrescentes %f: \n", tmp_medio[2]);*/

            printRelatorio(qtd, tmp_medio);

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

void countingSort(int *v, int size) {
  int output[100000];

  // Find the largest element of the array
  int max = v[0];
  for (int i = 1; i < size; i++) {
    if (v[i] > max)
      max = v[i];
  }

  // The size of count must be at least (max+1) but
  // we cannot declare it as int count(max+1) in C as
  // it does not support dynamic memory allocation.
  // So, its size is provided statically.
  int count[100000];

  // Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < size; i++) {
    count[v[i]]++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = size - 1; i >= 0; i--) {
    output[count[v[i]] - 1] = v[i];
    count[v[i]]--;
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++) {
    v[i] = output[i];
  }
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

//Funcao insertion sort
void Insertion_Sort(int *v, int n) {
    int i, j, aux;

    for(i = 1; i < n; i++){
        aux = v[i];
        for(j = i; (j > 0) && (aux < v[j-1]); j--){
            v[j] = v[j-1];
        }
        v[j] = aux;
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


// Function to get the largest element from an array
int getMax(int v[], int n) {
  int max = v[0];
  for (int i = 1; i < n; i++)
    if (v[i] > max)
      max = v[i];
  return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countSort(int v[], int size, int place) {
  int output[size + 1];
  int max = (v[0] / place) % 10;

  for (int i = 1; i < size; i++) {
    if (((v[i] / place) % 10) > max)
      max = v[i];
  }
  int count[max + 1];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(v[i] / place) % 10]++;

  // Calculate cummulative count
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(v[i] / place) % 10] - 1] = v[i];
    count[(v[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    v[i] = output[i];
}

// Main function to implement radix sort
void radixsort(int *v, int size) {
  // Get maximum element
  int max = getMax(v, size);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countSort(v, size, place);
}




//funcao selection sort
void selectionSort(int *v, int n) {
    int i, j, menor, troca;

    for(i = 0; i < n - 1; i++){
        menor = i;
        for(j = i + 1; j < n; j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        if(i != menor){
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}
//algoritmo ShellSort
void shellSort(int *v, int size) {
    int i , j , value;

    int h = 1;
    while(h < size) {
        h = 3*h+1;
    }
    while (h > 0) {
        for(i = h; i < size; i++) {
            value = v[i];
            j = i;
            while (j > h-1 && value <= v[j - h]) {
                v[j] = v [j - h];
                j = j - h;
            }
            v [j] = value;
        }
        h = h/3;
    }
}

//Escopo da funcao timsort
const int run = 32;

    int minimum(int a, int b)
    {
        if(a<b)
        return a;
        else
        return b;
}

    void insertionSort(int v[], int beg, int end)
    {
        int temp, i, j;
        for (i = beg + 1; i <= end; i++)
        {
            temp = v[i];
            j = i - 1;
            while (v[j] > temp && j >= beg)
            {
                v[j+1] = v[j];
                j--;
            }
            v[j+1] = temp;
        }
    }

void merge_tim(int v[], int left, int mid, int right)
    {
        int len1 = mid - left + 1, len2 = right - mid;
        int beg[len1], end[len2];
        int i,j,k;
        for (i = 0; i < len1; i++)
            beg[i] = v[left + i];
        for (i = 0; i < len2; i++)
            end[i] = v[mid + 1 + i];

        i = 0;
        j = 0;
        k = left;

        while (i < len1 && j < len2)
        {
            if (beg[i] <= end[j])
            {
                v[k] = beg[i];
                i++;
            }
            else
            {
                v[k] = end[j];
                j++;
            }
            k++;
        }
        while (i < len1)
        {
            v[k] = beg[i];
            k++;
            i++;
        }

        while (j < len2)
        {
            v[k] = end[j];
            k++;
            j++;
        }
    }
//funcao timSort
void timSort(int v[], int qtd) {
                int i,size,beg,mid,end;
                for (i = 0; i < qtd; i+=run)
                    insertionSort(v, i, minimum((i+31), (qtd-1)));
                for (size = run; size < qtd; size = 2*size)
                {
                    for (beg = 0; beg < qtd; beg += 2*size)
                    {
                        mid = beg + size - 1;
                        end = minimum((beg + 2*size - 1), (qtd-1));

                        merge_tim(v, beg, mid, end);
                    }
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
