#include <iostream>

using namespace std;

int insertionSort(int tab[], int n){
  int curr; //current element
  int j;
  for(int i=1;i<n;i++){
    curr = tab[i]; //chosen numbere to compare with other elements
    j=i-1; //index of compared element
    while(j>=0 && tab[j]>curr){
      tab[j+1] = tab[j];
      --j;
    }
    curr=tab[j];
  }

}

int main(){
  int arr[]={2,4,5,8,12,156,23,423,1,0};
  int n = sizeof(arr)/sizeof(arr[0]); //num of elements

  insertionSort(arr,n);

  for(int i=0;i<n;i++) // printing array
    cout<<arr[i]<<" ";
  return 0;
}
