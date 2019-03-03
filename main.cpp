#include <iostream>
#include <ctime>

using namespace std;

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i]; int j = i-1;
        while(key<arr[j] && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void shellSort(int arr[], int n){
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int n){
    int i, j, min;

    for (i = 0; i < n-1; i++){

        min = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(&arr[min], &arr[i]);
    }
}

//heapify and heapsort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;


    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
//heapify and heapsort

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

int main(){
    int size;
    cout<< "Array size: " << endl;
    cin >> size;
    int *array = new int[size];
    srand((unsigned)time(0));

    cout<<"Random array: ";

    for(int i=0; i<size; i++){
        array[i] = (rand()%100)+1;
        cout << array[i] <<" ";
        }


  clock_t time = clock(); //init time
  insertionSort(array,size);
  time = clock() - time; //diff time

  double ms = double(time)/CLOCKS_PER_SEC * 1000;

  cout<<"\nInsertion sort time: "<<ms<<endl;
  cout<<"After insertion sort array: ";
  for(int i=0;i<size;i++) // printing array
    cout<<array[i]<<" ";




  return 0;
}
