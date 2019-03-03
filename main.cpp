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

    srand((unsigned)time(0));
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
                clock_t time = clock(); //init time

                insertionSort(randarray,size);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC*1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<randarray[i]<<" ";
                }

            }
            else if(choice2== 'A'){
                clock_t time = clock(); //init time

                insertionSort(ascarray,size);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC * 1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<ascarray[i]<<" ";
                }
            }
            else if(choice2=='D'){
                clock_t time = clock(); //init time

                insertionSort(descarray,size);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC * 1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<descarray[i]<<" ";
                }
            }
            else if(choice2=='S'){
                clock_t time = clock(); //init time

                insertionSort(staticarray,size);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC * 1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<staticarray[i]<<" ";
                }
            }
            else if(choice2=='X'){
                clock_t time = clock(); //init time

                insertionSort(adarray,size);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC * 1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
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
                clock_t time = clock(); //init time

                shellSort(randarray,size);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC*1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<randarray[i]<<" ";
                }

            }
            else if(choice2== 'A'){
                clock_t time = clock(); //init time

                shellSort(ascarray,size);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC * 1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<ascarray[i]<<" ";
                }
            }
            else if(choice2=='D'){
                clock_t time = clock(); //init time

                shellSort(descarray,size);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC * 1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<descarray[i]<<" ";
                }
            }
            else if(choice2=='S'){
                clock_t time = clock(); //init time

                shellSort(staticarray,size);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC * 1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<staticarray[i]<<" ";
                }
            }
            else if(choice2=='X'){
                clock_t time = clock(); //init time

                shellSort(adarray,size);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC * 1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
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
                clock_t time = clock(); //init time

                selectionSort(randarray,size);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC*1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<randarray[i]<<" ";
                }

            }
            else if(choice2== 'A'){
                clock_t time = clock(); //init time

                selectionSort(ascarray,size);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC * 1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<ascarray[i]<<" ";
                }
            }
            else if(choice2=='D'){
                clock_t time = clock(); //init time

                selectionSort(descarray,size);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC * 1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<descarray[i]<<" ";
                }
            }
            else if(choice2=='S'){
                clock_t time = clock(); //init time

                selectionSort(staticarray,size);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC * 1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<staticarray[i]<<" ";
                }
            }
            else if(choice2=='X'){
                clock_t time = clock(); //init time

                selectionSort(adarray,size);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC * 1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
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
                clock_t time = clock(); //init time

                heapSort(randarray,size);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC*1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<randarray[i]<<" ";
                }

            }
            else if(choice2== 'A'){
                clock_t time = clock(); //init time

                insertionSort(ascarray,size);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC * 1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<ascarray[i]<<" ";
                }
            }
            else if(choice2=='D'){
                clock_t time = clock(); //init time

                heapSort(descarray,size);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC * 1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<descarray[i]<<" ";
                }
            }
            else if(choice2=='S'){
                clock_t time = clock(); //init time

                heapSort(staticarray,size);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC * 1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<staticarray[i]<<" ";
                }
            }
            else if(choice2=='X'){
                clock_t time = clock(); //init time

                heapSort(adarray,size);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC * 1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
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
                clock_t time = clock(); //init time

                quickSort(randarray,0,size-1);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC*1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<randarray[i]<<" ";
                }

            }
            else if(choice2== 'A'){
                clock_t time = clock(); //init time

                quickSort(ascarray,0,size-1);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC * 1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<ascarray[i]<<" ";
                }
            }
            else if(choice2=='D'){
                clock_t time = clock(); //init time

                quickSort(descarray,0,size-1);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC * 1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<descarray[i]<<" ";
                }
            }
            else if(choice2=='S'){
                clock_t time = clock(); //init time

                quickSort(staticarray,0,size-1);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC * 1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
                cout<<"After sorting: "<<endl;
                for(int i=0;i<size;i++){
                    cout<<staticarray[i]<<" ";
                }
            }
            else if(choice2=='X'){
                clock_t time = clock(); //init time

                quickSort(adarray,0,size-1);

                time = clock() - time; //diff time
                double ms = double(time)/CLOCKS_PER_SEC * 1000; // final time
                cout<<"Time in ms: "<<ms<<endl;
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
