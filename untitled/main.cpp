#include <iostream>
#include <ctime>

using namespace std;
int main() {
    while(true) {
        int n;
        cin >> n;
        long double *array = new long double [n];
        clock_t time = clock(); //init time
        array[0]=1;
        array[1]=1;

        for (int i = 2; i<n; i++) {
            array[i]=array[i-1]+array[i-2];
        }
        for(int i=0;i<n;i++){
            cout<<array[i]<<" ";
        }
        time = clock() - time; //diff time
        double ms = double(time) / CLOCKS_PER_SEC *1000;
        cout << "\n ms: " << ms << endl;

    }

}