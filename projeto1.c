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

    //selecao da qtd de elementos a serem ordenados
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
        result = algoritmoEscolhido(alg, qtd); //chama a funcao que realiza a ordenacao e calcula tempo de acordo com algoritmo e qtd de elementos escolhido

    }
    else{
        printf("Valor invalido!");
    }

    system("pause");
    return 0;

}

//Funcao que exibe relatorio com o resultado do tempo de ordenacao do algoritmo escolhido
void printRelatorio(int qtd, float tmp_medio[]) {
  printf("\t\t----------------- RELATORIO DE TEMPO DE ORDENACAO -------------------\n");
  printf("\t\t|Quantidade de elementos ordenados: %d                             |\n", qtd);
  printf("\t\t|Tempo medio de ordenacao de vetores aleatorios: %f            |\n", tmp_medio[0]);
  printf("\t\t|Tempo de ordenacao de vetores crescentes: %f                  |\n", tmp_medio[1]);
  printf("\t\t|Tempo medio de ordenacao de vetores decrescentes: %f          |\n", tmp_medio[2]);
  printf("\t\t---------------------------------------------------------------------\n");

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
        printf("Aguarde enquanto o relatorio eh gerado...");
        printf("\n\nAlgoritmo escolhido: BeadSort\n");

        //ordenacao sera repetida 10 vezes
        for(i = 0; i < 10; i++){
            //alocacao dinamica do vetor
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            srand(time(NULL));
            //preenche vetores com elementos aleatorios
            for (j = 0; j < qtd; j++){
                /* gerando valores aleatórios entre zero e 10000 */
                v[j] = rand() % 10000;
            }
            bead_sort(v, qtd); //chama funcao do beadsort e passa o vetor dinamico e a quantidade de elementos a serem ordenados

            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            //calcula tempo em segundos
            deltaT = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            soma += deltaT; //faz a somatoria dos segundos de cada ordenacao para calcular media
            free(v); //libera memoria do vetor

        }
        tmp_medio[0] = soma / 10; //calcula tempo medio ordenacao

           /*Tempo de execucao de vetor em ordem crescente*/
            v = malloc (qtd * sizeof(int)); //aloca vetor dinamicamente
            gettimeofday(&tempo_antes, NULL); //coleta tempo de inicio
            //Preenche o vetor ordenado de forma crescente
            for(int i = 0; i < qtd; i++){
                v[i] = i;
            }
            bead_sort(v, qtd); //chama funcao beadsort para ordenar vetores em ordem crescente
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[1] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v); //libera memoria do vetor

            /* Tempo de execução do vetor em ordem decrescente*/
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            //preenche o vetor de forma decrescente
            for(int i = 0; i < qtd; i++){
                v[i] = qtd - i;
            }
            bead_sort(v, qtd); //chama a funcao para ordenar os vetores que estao em ordem decrescente
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[2] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v); //libera memoria do vetor

            printRelatorio(qtd, tmp_medio); //chama funcao de exibicao de relatorio do tempo de execucao

        break;
    case 2:
        printf("Aguarde enquanto o relatorio eh gerado...");
        printf("\n\nAlgoritmo escolhido: Bubblesort\n");

        //ordenacao sera repetida 10 vezes
        for(i = 0; i < 10; i++){
            //alocacao dinamica do vetor
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            srand(time(NULL));
            //preenche vetores com elementos aleatorios
            for (j = 0; j < qtd; j++){
                /* gerando valores aleatórios entre zero e 10000 */
                v[j] = rand() % 10000;
            }
            bubble_sort(v, qtd); //chama funcao do bubblesort e passa o vetor dinamico e a quantidade de elementos a serem ordenados
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            deltaT = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v); //libera memoria do vetor
            soma += deltaT;
        }
        tmp_medio[0] = soma / 10; //calcula tempo medio ordenacao

         /*Tempo de execucao de vetor em ordem crescente*/
            v = malloc (qtd * sizeof(int)); //aloca vetor dinamicamente
            gettimeofday(&tempo_antes, NULL); //coleta tempo de inicio
            //Preenche o vetor ordenado de forma crescente
            for(int i = 0; i < qtd; i++){
                v[i] = i;
            }
            bubble_sort(v, qtd); //chama funcao bublesort para ordenar vetores em ordem crescente
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[1] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v); //libera memoria do vetor


            /* Tempo de execução do vetor em ordem decrescente*/
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            //preenche o vetor de forma decrescente
            for(int i = 0; i < qtd; i++){
                v[i] = qtd - i;
            }
            bubble_sort(v, qtd); //chama funcao do bubblesort
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[2] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v); //libera memoria do vetor


            printRelatorio(qtd, tmp_medio); //chama funcao de exibicao de relatorio do tempo de execucao
        break;
    case 3:
        printf("Aguarde enquanto o relatorio eh gerado...");
        printf("\n\nAlgoritmo escolhido: CountingSort\n");

        //ordenacao sera repetida 10 vezes
        for(i = 0; i < 10; i++){
            //faz alocacao dinamica do vetor
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            srand(time(NULL));
            //preenche vetores com elementos aleatorios
            for (j = 0; j < qtd; j++){
                /* gerando valores aleatorios entre zero e 10000 */
                v[j] = rand() % 10000;
            }
            countingSort(v, qtd); //chama funcao do coutingsort e passa o vetor dinamico e a quantidade de elementos a serem ordenados
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            deltaT = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            soma += deltaT;
            free(v); //libera memoria do vetor


       }
        tmp_medio[0] = soma / 10; //calcula tempo medio de ordenacao


            /*Tempo de execucao de vetor em ordem crescente*/

            //alocacao dinamica do vetor
            v = malloc (qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo de inicio
            //Preenche o vetor ordenado de forma crescente
            for(int i = 0; i < qtd; i++){
                v[i] = i;
            }
            countingSort(v, qtd); //chama funcao do coutingSort
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[1] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v); //libera memoria do vetor

            /* Tempo de execução do vetor em ordem decrescente*/
            //faz alocacao dinamica do vetor
            v = (int *) malloc(qtd * sizeof(int));
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            //percorre o vetor de forma decrescente
            for(int i = 0; i < qtd; i++){
                v[i] = qtd - i;
            }
            countingSort(v, qtd); //chama funcao do coutingSort
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[2] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v); //libera memoria do vetor

            printRelatorio(qtd, tmp_medio); //chama funcao de exibicao de relatorio do tempo de execucao

        break;
    case 4:
        printf("Aguarde enquanto o relatorio eh gerado...");
        printf("Algoritmo escolhido: HeapSort\n");

        //ordenacao sera repetida 10 vezes
        for(i = 0; i < 10; i++){
            v = (int *) malloc(qtd * sizeof(int)); //faz alocacao dinamica do vetor
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            srand(time(NULL));
            //preenche vetores com elementos aleatorios
            for (j = 0; j < qtd; j++){
                /* gerando valores aleatórios entre zero e 10000 */
                v[j] = rand() % 10000;
            }
            HeapSort(v, qtd); //chama funcao do heapsort e passa o vetor dinamico e a quantidade de elementos a serem ordenados
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            deltaT = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            soma += deltaT;
            free(v); //libera memoria do vetor

        }
        tmp_medio[0] = soma / 10; //calcula tempo medio de ordencao

           /*Tempo de execucao de vetor em ordem crescente*/
            v = malloc (qtd * sizeof(int)); //faz alocacao dinamica do vetor

            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            //Preenche o vetor ordenado de forma crescente
            for(int i = 0; i < qtd; i++){
                v[i] = i;
            }
            HeapSort(v, qtd); //chama funcao do heapsort
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[1] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v); //libera memoria do vetor

            /* Tempo de execução do vetor em ordem decrescente*/
            v = (int *) malloc(qtd * sizeof(int)); //faz alocacao dinamica do vetor
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio

            //Preenche o vetor de forma decrescente
            for(int i = 0; i < qtd; i++){
                v[i] = qtd - i;
            }
            HeapSort(v, qtd); //chama funcao do heapsort
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[2] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v); //libera memoria do vetor

            printRelatorio(qtd, tmp_medio); //chama funcao de exibicao de relatorio do tempo de execucao
        break;
    case 5:
        printf("Aguarde enquanto o relatorio eh gerado...");
        printf("\n\nAlgoritmo escolhido: InsertionSort\n");

        //ordenacao sera repetida 10 vezes
        for(i = 0; i < 10; i++){
            v = (int *) malloc(qtd * sizeof(int)); //faz alocacao dinamica do vetor
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            srand(time(NULL));
            //preenche vetores com elementos aleatorios
            for (j = 0; j < qtd; j++){
                /* gerando valores aleatórios entre zero e 10000 */
                v[j] = rand() % 10000;
            }
            Insertion_Sort(v, qtd); //chama funcao do insertioSort e passa o vetor dinamico e a quantidade de elementos a serem ordenados
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            deltaT = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            soma += deltaT;
            free(v); //libera memoria do vetor

        }
        tmp_medio[0] = soma / 10; //calcula tempo medio de ordencao

            /*Tempo de execucao de vetor em ordem crescente*/
            v = malloc (qtd * sizeof(int)); //faz alocacao dinamica do vetor

            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            //Preenche o vetor ordenado de forma crescente
            for(int i = 0; i < qtd; i++){
                v[i] = i;
            }
            Insertion_Sort(v, qtd); //chama funcao do insertioSort
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[1] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v); //libera memoria do vetor

            /* Tempo de execução do vetor em ordem decrescente*/
            v = (int *) malloc(qtd * sizeof(int)); //faz alocacao dinamica do vetor
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            //Preenche o vetor de forma decrescente
            for(int i = 0; i < qtd; i++){
                v[i] = qtd - i;
            }
            Insertion_Sort(v, qtd); //chama funcao do insertioSort
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[2] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v); //libera memoria do vetor

            printRelatorio(qtd, tmp_medio); //chama funcao de exibicao de relatorio do tempo de execucao
        break;
    case 6:
        printf("Aguarde enquanto o relatorio eh gerado...");
        printf("\n\nAlgoritmo escolhido: MergeSort\n");

        //ordenacao sera repetida 10 vezes
        for(i = 0; i < 10; i++){
            v = (int *) malloc(qtd * sizeof(int)); //faz alocacao dinamica do vetor
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            srand(time(NULL));
            //preenche vetores com elementos aleatorios
            for (j = 0; j < qtd; j++){
                /* gerando valores aleatórios entre zero e 10000 */
                v[j] = rand() % 10000;
            }
            mergeSort(v, 0, qtd - 1); //chama funcao do mergeSort e passa o vetor dinamico e a quantidade de elementos a serem ordenados
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            deltaT = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            soma += deltaT;
            free(v); //libera memoria do vetor

        }
        tmp_medio[0] = soma / 10; //calcula tempo medio de ordenacao

           /*Tempo de execucao de vetor em ordem crescente*/
            v = malloc (qtd * sizeof(int)); //faz alocacao dinamica do vetor

            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            //Preenche o vetor ordenado de forma crescente
            for(int i = 0; i < qtd; i++){
                v[i] = i;
            }
            mergeSort(v, 0, qtd - 1); //chama funcao do mergeSort
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[1] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v); //libera memoria do vetor

            /* Tempo de execução do vetor em ordem decrescente*/
            v = (int *) malloc(qtd * sizeof(int)); //faz alocacao dinamica do vetor
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            //Preenche o vetor de forma decrescente
            for(int i = 0; i < qtd; i++){
                v[i] = qtd - i;
            }
            mergeSort(v, 0, qtd - 1); //chama funcao do mergeSort
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[2] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v); //libera memoria do vetor

            printRelatorio(qtd, tmp_medio); //chama funcao de exibicao de relatorio do tempo de execucao
        break;
    case 7:
        printf("Aguarde enquanto o relatorio eh gerado...");
        printf("\n\nAlgoritmo escolhido: RadixSort\n");

        //ordenacao sera repetida 10 vezes
        for(i = 0; i < 10; i++){
            v = (int *) malloc(qtd * sizeof(int)); //faz alocacao dinamica do vetor
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            srand(time(NULL));
            //preenche vetores com elementos aleatorios
            for (j = 0; j < qtd; j++){
                /* gerando valores aleatórios entre zero e 10000 */
                v[j] = rand() % 10000;
            }
            radixsort(v, qtd); //chama funcao do radixsort e passa o vetor dinamico e a quantidade de elementos a serem ordenados
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            deltaT = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            soma += deltaT;
            free(v); //libera memoria do vetor

        }
        tmp_medio[0] = soma / 10; //calcula tempo medio de ordencao

        /*Tempo de execucao de vetor em ordem crescente*/
        /*aqui nao funciona
            v = malloc (qtd * sizeof(int)); //faz alocacao dinamica do vetor

            gettimeofday(&tempo_antes, NULL); //coleta tempo de inicio
            //Preenche o vetor ordenado de forma crescente
            for(int i = 0; i < qtd; i++){
                v[i] = i;
            }
            radixsort(v, qtd); //chama funcao do radixsort
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[1] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v); //libera memoria do vetor */

            /* Tempo de execução do vetor em ordem decrescente*/
            v = (int *) malloc(qtd * sizeof(int)); //faz alocacao dinamica do vetor
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            //Preenche o vetor de forma decrescente
            for(int i = 0; i < qtd; i++){
                v[i] = qtd - i;
            }
            radixsort(v, qtd); //chama funcao do radixsort
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[2] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v); //libera memoria do vetor

            printRelatorio(qtd, tmp_medio); //chama funcao de exibicao de relatorio do tempo de execucao

        break;
    case 8:
        printf("Aguarde enquanto o relatorio eh gerado...");
        printf("\n\nAlgoritmo escolhido: SelectionSort\n");

        //ordenacao sera repetida 10 vezes
        for(i = 0; i < 10; i++){
            v = (int *) malloc(qtd * sizeof(int)); //alocacao dinamica do vetor
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            srand(time(NULL));
            //preenche os vetores com valores aleatorios
            for (j = 0; j < qtd; j++){
                /* gerando valores aleatórios entre zero e 10000 */
                v[j] = rand() % 10000;
            }
            selectionSort(v, qtd); //chama funcao do selectionSort e passa o vetor dinamico e a quantidade de elementos a serem ordenados

            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            deltaT = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            soma += deltaT;
            free(v); //libera memoria do vetor

        }
        tmp_medio[0] = soma / 10; //calcula tempo medio de ordenacao dos vetores aleatorios

            /*Tempo de execucao de vetor em ordem crescente*/
            v = malloc (qtd * sizeof(int)); //alocacao dinamica do vetor

            gettimeofday(&tempo_antes, NULL); //coleta tempo de inicio
            //Preenche o vetor ordenado de forma crescente
            for(int i = 0; i < qtd; i++){
                v[i] = i;
            }
            selectionSort(v, qtd); //chama funcao do selectionSort
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[1] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v); //libera memoria do vetor

            /* Tempo de execução do vetor em ordem decrescente*/
            v = (int *) malloc(qtd * sizeof(int)); //alocacao dinamica do vetor
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio

            //preenche o vetor de forma decrescente
            for(int i = 0; i < qtd; i++){
                v[i] = qtd - i;
            }
            selectionSort(v, qtd); //chama funcao do selectionSort
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[2] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v); //libera memoria do vetor

            printRelatorio(qtd, tmp_medio); //chama funcao de exibicao de relatorio do tempo de execucao


        break;
    case 9:
        printf("Aguarde enquanto o relatorio eh gerado...");
        printf("\n\nAlgoritmo escolhido: ShellSort\n");

        //ordenacao sera repetida 10 vezes
        for(i = 0; i < 10; i++){
            v = (int *) malloc(qtd * sizeof(int)); //alocacao dinamica do vetor
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            srand(time(NULL));
            //preenche os vetores com valores aleatorios
            for (j = 0; j < qtd; j++){
                /* gerando valores aleatórios entre zero e 10000 */
                v[j] = rand() % 10000;
            }
            shellSort(v, qtd); //chama funcao do shellSort e passa o vetor dinamico e a quantidade de elementos a serem ordenados
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            deltaT = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            soma += deltaT;
            free(v); //libera memoria do vetor

        }
        tmp_medio[0] = soma / 10; //calcula tempo medio de ordenacao

           /*Tempo de execucao de vetor em ordem crescente*/
            v = malloc (qtd * sizeof(int)); //aloca vetor dinamicamente

            gettimeofday(&tempo_antes, NULL); //coleta tempo de inicio
             //Preenche o vetor ordenado de forma crescente
            for(int i = 0; i < qtd; i++){
                v[i] = i;
            }
            shellSort(v, qtd); //chama funcao do shellSort
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[1] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v); //libera memoria do vetor

            /* Tempo de execução do vetor em ordem decrescente*/
            v = (int *) malloc(qtd * sizeof(int)); //aloca vetor dinamicamente
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio

            //Preenche o vetor de forma decrescente
            for(int i = 0; i < qtd; i++){
                v[i] = qtd - i;
            }
            shellSort(v, qtd); //chama funcao do shellSort
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[2] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v); //libera memoria do vetor

            printRelatorio(qtd, tmp_medio); //chama funcao de exibicao de relatorio do tempo de execucao

        break;
    case 10:
        printf("Aguarde enquanto o relatorio eh gerado...");
        printf("\n\nAlgoritmo escolhido: TimSort\n");

        //ordenacao sera repetida 10 vezes
        for(i = 0; i < 10; i++){
            v = (int *) malloc(qtd * sizeof(int)); //aloca vetor dinamicamente
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            srand(time(NULL));
            //preenche os vetores com valores aleatorios
            for (j = 0; j < qtd; j++){
                /* gerando valores aleatórios entre zero e 10000 */
                v[j] = rand() % 10000;
            }
            timSort(v, qtd); //chama funcao do timSort e passa o vetor dinamico e a quantidade de elementos a serem ordenados
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            deltaT = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            soma += deltaT;
            free(v); //libera memoria do vetor

        }
        tmp_medio[0] = soma / 10; //calcula tempo medio de ordenacao

            /*Tempo de execucao de vetor em ordem crescente*/
            v = malloc (qtd * sizeof(int)); //aloca vetor dinamicamente

            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            //Preenche o vetor ordenado de forma crescente
            for(int i = 0; i < qtd; i++){
                v[i] = i;
            }
            timSort(v, qtd); //chama a funcao timSort
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[1] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v); //libera memoria do vetor

            /* Tempo de execução do vetor em ordem decrescente*/
            v = (int *) malloc(qtd * sizeof(int)); //aloca vetor dinamicamente
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            //Preenche o vetor de forma decrescente
            for(int i = 0; i < qtd; i++){
                v[i] = qtd - i;
            }
            timSort(v, qtd); //chama a funcao timSort
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[2] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v); //libera memoria do vetor

            printRelatorio(qtd, tmp_medio); //chama funcao de exibicao de relatorio do tempo de execucao
        break;
    case 11:
        printf("Aguarde enquanto o relatorio eh gerado...");
        printf("\n\nAlgoritmo escolhido: QuickSort\n");

        //ordenacao sera repetida 10 vezes
        for(i = 0; i < 10; i++){
            v = (int *) malloc(qtd * sizeof(int)); //aloca vetor dinamicamente
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            srand(time(NULL));
            //Preenche os vetores com valores aleatorios
            for (j = 0; j < qtd; j++){
                /* gerando valores aleatórios entre zero e 10000 */
                v[j] = rand() % 10000;
            }
            quick_sort(v, 0, qtd - 1); //chama funcao do quick_sort e passa o vetor dinamico e a quantidade de elementos a serem ordenados
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            deltaT = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            soma += deltaT;
            free(v); //libera memoria do vetor

        }
        tmp_medio[0] = soma / 10; //calcula tempo medio de ordenacao


           /*Tempo de execucao de vetor em ordem crescente*/
            v = malloc (qtd * sizeof(int)); //vetor alocado dinamicamente

            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio
            //Preenche o vetor ordenado de forma crescente
            for(int i = 0; i < qtd; i++){
                v[i] = i;
            }
            quick_sort(v, 0, qtd - 1); //chama a funcao quick_sort
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[1] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v); //libera memoria do vetor

            /* Tempo de execução do vetor em ordem decrescente*/
            v = (int *) malloc(qtd * sizeof(int)); //aloca vetor dinamicamente
            gettimeofday(&tempo_antes, NULL); //coleta tempo no inicio

            //Preenche vetor de forma decrescente
            for(int i = 0; i < qtd; i++){
                v[i] = qtd - i;
            }
            quick_sort(v, 0, qtd - 1); //chama a funcao quick_sort
            gettimeofday(&tempo_depois, NULL); //coleta tempo no final
            tmp_medio[2] = (tempo_depois.tv_sec + tempo_depois.tv_sec/1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_sec/1000000.0);
            free(v); //libera memoria do vetor

            printRelatorio(qtd, tmp_medio); //chama funcao de exibicao de relatorio do tempo de execucao

        break;

    }


}

/*Inicio da funcao bead_sort*/
void bead_sort(int *a, int qtd){
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
/* Fim da funcao bead_sort*/

/*Inicio da funcao bubble_sort*/
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
/*Fim da funcao bubble_sort*/


/*Inicio da funcao countingSort */
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
/*Fim da funcao countingSort */

/*Inicio da funcao HeapSort */
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
/*Fim da funcao HeapSort */

/*Inicio da funcao Insertion_Sort */
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

/*Fim da funcao Insertion_Sort */

/*Inicio da funcao mergeSort */
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
/*Fim da funcao mergeSort */

/*Inicio da funcao radixsort */
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
/*Fim da funcao radixsort */



/*Inicio da funcao selectionSort */
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
/*Fim da funcao selectionSort */

/*Inicio da funcao shellSort */
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
/*Fim da funcao shellSort */

/*Inicio da funcao timSort */
const int run = 32;

int minimum(int a, int b){
    if(a<b)
        return a;
    else
        return b;
}

void insertionSort(int v[], int beg, int end){
    int temp, i, j;
    for (i = beg + 1; i <= end; i++){
        temp = v[i];
        j = i - 1;
        while (v[j] > temp && j >= beg){
                v[j+1] = v[j];
                j--;
        }
        v[j+1] = temp;
    }
}

void merge_tim(int v[], int left, int mid, int right){
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

        while (i < len1 && j < len2) {
            if (beg[i] <= end[j]) {
                v[k] = beg[i];
                i++;
            } else {
                v[k] = end[j];
                j++;
            }
            k++;
        }
        while (i < len1) {
            v[k] = beg[i];
            k++;
            i++;
        }

        while (j < len2) {
            v[k] = end[j];
            k++;
            j++;
        }
    }

void timSort(int v[], int qtd) {

    int i,size,beg,mid,end;

    for (i = 0; i < qtd; i+=run)
        insertionSort(v, i, minimum((i+31), (qtd-1)));

    for (size = run; size < qtd; size = 2*size) {
        for (beg = 0; beg < qtd; beg += 2*size) {
            mid = beg + size - 1;
            end = minimum((beg + 2*size - 1), (qtd-1));

            merge_tim(v, beg, mid, end);
        }
    }
}
/*Fim da funcao timSort */


/*Fim da funcao quick_sort */
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


void quick_sort(int *v, int ini, int fim){

    int pivo;

    //utiliza recursividade para ordenar as particoes
    if(ini < fim) {
        pivo = particiona(v, ini, fim); //chama a funcao que separa os dados em 2 particoes
        quick_sort(v, ini, pivo - 1);
        quick_sort(v, pivo + 1, fim);
    }

}
/*Fim da funcao quick_sort */
