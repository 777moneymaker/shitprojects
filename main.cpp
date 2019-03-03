#include <iostream>
#include <chrono>

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
    }
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

int main(){

    int size;
    cout<< "Array size: " << endl; cin >> size;
    int *randarray= new int[size];
    int *ascarray= new int[size];
    int *descarray= new int[size];
    int *staticarray= new int[size];
    int *adarray = new int[size];



    srand((unsigned)time(NULL));
    cout<<"Random array: ";
    for(int i=0; i<size; i++){
        randarray[i] = (rand()%100)+1;
        cout << randarray[i] <<" ";
        }

    cout<<"\n\nAscending array: "<<endl;
    for(int i=0;i<size;i++){ //ascending array
      ascarray[i] = (i*size)- 2;
      cout<<ascarray[i]<<" ";
    }

    cout<<"\n\nDescending array: "<<endl;
    for(int i=0;i<size;i++){
      descarray[i]= (size-i)*3 ;
      cout<<descarray[i]<<" ";
    }

    cout<<"\n\nStatic array: "<<endl;
    for(int i=0;i<size;i++){
      staticarray[i]=size;
      cout<<staticarray[i]<<" ";
    }
    cout<<"\n\n Asc-Desc array: "<<endl;
    for(int i=0;i<size;i++){
      adarray[i]=(size*2)+i;
      if(i>=(size/2)){
          adarray[i]=(size*2)-i;
      }
      cout<<adarray[i]<<" ";
    }

    char choice; cout<<"\n\nWhich sorting? ( 1- Insertion, 2 - Shell, 3 - Selection, 4 - Heap, 5 - Quick)"<<endl;
    cin>>choice;
    switch(choice){
        case '1':{
            cout<<"\nWhich array?(\"R\" - random, \"A\" - ascending, \"D\" - descending, \"S\" - static, \"X\" - Ascending-descending"<<endl;
            char choice2;
            cin>>choice2;
            if(choice2== 'R'){
                auto start = std::chrono::high_resolution_clock::now();
                insertionSort(randarray,size);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

                cout<<"Time in nanoseconds: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<randarray[i]<<" ";
                }

            }
            else if(choice2== 'A'){
                auto start = std::chrono::high_resolution_clock::now();
                insertionSort(ascarray,size);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                cout<<"Time in nanoseconds: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<ascarray[i]<<" ";
                }
            }
            else if(choice2=='D'){
                auto start = std::chrono::high_resolution_clock::now();
                insertionSort(descarray,size);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                cout<<"Time in nanoseconds: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<descarray[i]<<" ";
                }
            }
            else if(choice2=='S'){
                auto start = std::chrono::high_resolution_clock::now();
                insertionSort(staticarray,size);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                cout<<"Time in nanoseconds: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<staticarray[i]<<" ";
                }
            }
            else if(choice2=='X'){
                auto start = std::chrono::high_resolution_clock::now();
                insertionSort(adarray,size);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                cout<<"Time in nanoseconds: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<adarray[i]<<" ";
                }
            }
            else{
                cout<<"Error";
            }
            break;
        }
        case '2':{
            cout<<"\nWhich array?(\"R\" - random, \"A\" - ascending, \"D\" - descending, \"S\" - static, \"X\" - Ascending-descending"<<endl;
            char choice2;
            cin>>choice2;
            if(choice2== 'R'){
                auto start = std::chrono::high_resolution_clock::now();
                shellSort(randarray,size);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                cout<<"Time in nanoseconds: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<randarray[i]<<" ";
                }

            }
            else if(choice2== 'A'){
                auto start = std::chrono::high_resolution_clock::now();
                shellSort(ascarray,size);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                cout<<"Time in nanoseconds: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<ascarray[i]<<" ";
                }
            }
            else if(choice2=='D'){
                auto start = std::chrono::high_resolution_clock::now();
                shellSort(descarray,size);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                cout<<"Time in nanoseconds: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<descarray[i]<<" ";
                }
            }
            else if(choice2=='S'){
                auto start = std::chrono::high_resolution_clock::now();
                shellSort(staticarray,size);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                cout<<"Time in nanoseconds: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<staticarray[i]<<" ";
                }
            }
            else if(choice2=='X'){
                auto start = std::chrono::high_resolution_clock::now();
                shellSort(adarray,size);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                cout<<"Time in nanoseconds: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<adarray[i]<<" ";
                }
            }
            else{
                cout<<"Error";
            }
            break;
        }
        case '3':{
            cout<<"\nWhich array?(\"R\" - random, \"A\" - ascending, \"D\" - descending, \"S\" - static, \"X\" - Ascending-descending"<<endl;
            char choice2;
            cin>>choice2;
            if(choice2== 'R'){
                auto start = std::chrono::high_resolution_clock::now();
                selectionSort(randarray,size);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                cout<<"Time in nanoseconds: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<randarray[i]<<" ";
                }

            }
            else if(choice2== 'A'){
                auto start = std::chrono::high_resolution_clock::now();
                selectionSort(ascarray,size);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                cout<<"Time in nanoseconds: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<ascarray[i]<<" ";
                }
            }
            else if(choice2=='D'){
                auto start = std::chrono::high_resolution_clock::now();
                selectionSort(descarray,size);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                cout<<"Time in nanoseconds: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<descarray[i]<<" ";
                }
            }
            else if(choice2=='S'){
                auto start = std::chrono::high_resolution_clock::now();
                selectionSort(staticarray,size);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                cout<<"Time in nanoseconds: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<staticarray[i]<<" ";
                }
            }
            else if(choice2=='X'){
                auto start = std::chrono::high_resolution_clock::now();
                selectionSort(adarray,size);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                cout<<"Time in nanoseconds: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<adarray[i]<<" ";
                }
            }
            else{
                cout<<"Error";
            }
            break;
        }
        case '4':{
            cout<<"\nWhich array?(\"R\" - random, \"A\" - ascending, \"D\" - descending, \"S\" - static, \"X\" - Ascending-descending"<<endl;
            char choice2;
            cin>>choice2;
            if(choice2== 'R'){
                auto start = std::chrono::high_resolution_clock::now();
                heapSort(randarray,size);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                cout<<"Time in ns: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<randarray[i]<<" ";
                }

            }
            else if(choice2== 'A'){
                auto start = std::chrono::high_resolution_clock::now();
                heapSort(ascarray,size);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                cout<<"Time in nanoseconds: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<ascarray[i]<<" ";
                }
            }
            else if(choice2=='D'){
                auto start = std::chrono::high_resolution_clock::now();
                heapSort(descarray,size);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                cout<<"Time in nanoseconds: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<descarray[i]<<" ";
                }
            }
            else if(choice2=='S'){
                auto start = std::chrono::high_resolution_clock::now();
                heapSort(staticarray,size);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                cout<<"Time in nanoseconds: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<staticarray[i]<<" ";
                }
            }
            else if(choice2=='X'){
                auto start = std::chrono::high_resolution_clock::now();
                heapSort(adarray,size);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                cout<<"Time in nanoseconds: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<adarray[i]<<" ";
                }
            }
            else{
                cout<<"Error";
            }
            break;
        }
        case '5':{
            cout<<"\nWhich array?(\"R\" - random, \"A\" - ascending, \"D\" - descending, \"S\" - static, \"X\" - Ascending-descending"<<endl;
            char choice2;
            cin>>choice2;
            if(choice2== 'R'){
                auto start = std::chrono::high_resolution_clock::now();
                quickSort(randarray,0,size-1);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

                cout<<"Time in nanoseconds: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<randarray[i]<<" ";
                }

            }
            else if(choice2== 'A'){
                auto start = std::chrono::high_resolution_clock::now();
                quickSort(ascarray,0,size-1);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                cout<<"Time in ns: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<ascarray[i]<<" ";
                }
            }
            else if(choice2=='D'){
                auto start = std::chrono::high_resolution_clock::now();
                quickSort(descarray,0,size-1);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                cout<<"Time in ns: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<descarray[i]<<" ";
                }
            }
            else if(choice2=='S'){
                auto start = std::chrono::high_resolution_clock::now();
                quickSort(staticarray,0,size-1);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                cout<<"Time in ns: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<staticarray[i]<<" ";
                }
            }
            else if(choice2=='X'){
                auto start = std::chrono::high_resolution_clock::now();
                quickSort(adarray,0,size-1);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;

                long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                cout<<"Time in ns: "<<ns<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<adarray[i]<<" ";
                }
            }
            else{
                cout<<"Error";
            }
            break;
        }

    }

    return 0;

}
