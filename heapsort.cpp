#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n)
{
   
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    
    for(int i = n-1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main()
{
    int n;
    clock_t start, end;
    double cpu_time;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    
    srand(time(0));
    for(int i = 0; i < n; i++)
        arr[i] = rand() % 1000;

    cout << "\nGenerated Numbers:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

  
    start = clock();

    heapSort(arr, n);

   
    end = clock();

    cout << "\n\nSorted Numbers:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecution Time: " << cpu_time << " seconds\n";

    return 0;
}