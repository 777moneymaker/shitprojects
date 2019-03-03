#include <iostream>
#include <ctime>

class complexNumber{
    public:
        int re,im;
        complexNumber add(complexNumber X);
};

complexNumber complexNumber::add(complexNumber X){
    X.re+=re;
    X.im+=im;
    return X;
};

int main(){
    clock_t time = clock();

    complexNumber A,B,C;
    A.im = 4;
    A.re = 4;
    B = A;
    C=B.add(A);
    time = clock() - time;

    double ms = time / CLOCKS_PER_SEC * 1000;
    std::cout<<C.im<<" "<<C.re<<std::endl;
    std::cout<<"Time: "<<ms;

    return 0;
}