#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

void maxHeap(int array[], int i, int n)
{
    int j, aux;
    aux = array[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && array[j+1] > array[j])
            j = j + 1;
        if (aux > array[j])
            break;
        else if (aux <= array[j])
        {
            array[j / 2] = array[j];
            j = 2 * j;
        }
    }
    array[j/2] = aux;
    return;
}
void heapMax(int array[],int tamanho)
{
    int i;
    for(i = tamanho/2; i >= 1; i--)
    {
        maxHeap(array,i,tamanho);
    }
}

int main() {

    char arquivo[30]; 
    cout << "Digite o nome do arquivo para o teste: " << endl;
    cin >> arquivo;

    int array[100000]; 
    int tamanho = 0; 

    ifstream myReadFile;
    myReadFile.open(arquivo);
    char output[1000];
    if (myReadFile.is_open()) 
    {
        while (!myReadFile.eof()) 
        {
            myReadFile >> output;
            array[tamanho] = atoi(output);
            tamanho++;
        }
    }
    
    myReadFile.close();  

    heapMax(array, tamanho);

    for(int x=0; x<=(tamanho-1); x++)
    {
        cout << array[x] << endl;
    }
}