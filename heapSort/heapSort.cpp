#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2;  
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
 
        heapify(arr, i, 0);
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

    heapSort(array, tamanho);

    for(int x=0; x<=(tamanho-1); x++)
    {
        cout << array[x] << endl;
    }
}