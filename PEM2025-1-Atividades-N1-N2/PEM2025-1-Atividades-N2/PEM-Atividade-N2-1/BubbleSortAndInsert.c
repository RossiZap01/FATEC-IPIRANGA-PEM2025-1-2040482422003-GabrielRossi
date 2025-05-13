#include <stdio.h>

//Função para BubbleSort.
void BubbleSort(int *numero,int *count){
    
    for(int i = 0 ; i < *count ; i++){
        for(int j = 0 ; j < *count - i - 1 ; j++){
            //verifica se o numero atual é maior que o proximo numero.
            if(numero[j] > numero[j+1]){
                int aux = numero[j];
                numero[j] = numero[j + 1];
                numero[j + 1] = aux;
            }
        }
    }
}

void insertion(int *numero, int count) {
    for (int i = 1; i < count; i++) {
        int chave = numero[i];
        int j = i - 1;

        // Move os elementos maiores que a chave para frente
        while (j >= 0 && numero[j] > chave) {
            numero[j + 1] = numero[j];
            j--;
        }

        // Insere a chave na posição correta
        numero[j + 1] = chave;
    }
}


int main(){
    
    //pede para o usuario definir o numero de casos que quer organizar.
    int casos;
    puts("Quantos numeros deseja organizar?");
    scanf("%d",&casos);
    
    //cria duas variaveis , uma para ser organizada em BubbleSort e outra em Insertion.
    int organizarbbsort[casos];
    int organizarinsertion[casos];
    int input;
    
    //pede os numeros para serem organizados.
    for(int i = 0;i < casos; i++ ){
        puts("Digite um numero");
        scanf("%d",&input);
        organizarbbsort[i] = input;
        organizarinsertion[i] = input;
    }


    //chamada a Função BubbleSort.
    BubbleSort(organizarbbsort,&casos);
    
    //Printa a variavel organizarbbsort já organizada
    puts("seus numeros organizados por BubbleSort:");
    for(int i = 0 ; i < casos ; i++){
        printf("%d \n",organizarbbsort[i]);
    }
    
    //chamada a Função Insertion.
    insertion(organizarinsertion, casos);
    
    //Printa a variavel organizarinsertion já organizada
    puts("seus numeros organizados por Insertion:");
    for(int i = 0 ; i < casos ; i++){
        printf("%d \n",organizarinsertion[i]);
    }
    
    


    return 0;
}
