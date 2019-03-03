#include <iostream>
#include <ctime>

using namespace std;

int insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i]; int j = i-1;
        while(key<arr[j] && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main(){
  int arr[]={-24,234452,123,23,2,0,-23,-45634};
  int n = sizeof(arr)/sizeof(arr[0]); //num of elements

  clock_t time = clock(); //init time
  insertionSort(arr,n);
    time = clock() - time; //diff time
    double ms = double(time)/CLOCKS_PER_SEC * 1000;
  cout<<"Time: "<<ms<<endl;
  cout<<"Insertion sort: ";
  for(int i=0;i<n;i++) // printing array
    cout<<arr[i]<<" ";




  return 0;
}
