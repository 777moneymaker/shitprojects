//Created by: Zofia Antoszak & Miłosz Chodkowski
//05.03.2019

/* This program was made for Algorithms and Data Structure lecture.
    Program generates sequence of ints. Then user can choose the sorting method
    and program will sort the array of numbers and also give the time that was necessary
    to sort the array. */

#include <iostream>
#include <cstdlib>
#include <chrono>
#include "Sorts.h"

using std::cout, std::cin, std::endl;

int main(void) {

    while (true) {
        int size;
        cout << endl;
        cout << "Array size: " << endl;
        cin >> size;
        int *randarray = new int[size];
        int *ascarray = new int[size];
        int *descarray = new int[size];
        int *staticarray = new int[size];
        int *adarray = new int[size];


        srand((unsigned) time(NULL));
        cout << "Random array: " << endl;
        for (int i = 0; i < size; i++) {
            randarray[i] = (rand() % 100) + 1;
            cout << randarray[i] << " ";
        }

        cout << "\n\nAscending array: " << endl;
        for (int i = 0; i < size; i++) { //ascending array
            ascarray[i] = (i * size) - 2;
            cout << ascarray[i] << " ";
        }

        cout << "\n\nDescending array: " << endl;
        for (int i = 0; i < size; i++) {
            descarray[i] = (size - i) * 3;
            cout << descarray[i] << " ";
        }

        cout << "\n\nStatic array: " << endl;
        for (int i = 0; i < size; i++) {
            staticarray[i] = size;
            cout << staticarray[i] << " ";
        }
        cout << "\n\nAsc-Desc array: " << endl;
        for (int i = 0; i < size; i++) {
            adarray[i] = (size * 2) + i;
            if (i >= (size / 2)) {
                adarray[i] = (size * 2) - i;
            }
            cout << adarray[i] << " ";
        }

        char choice;
        cout << "\n\nWhich sorting? [1 - Insertion, 2 - Shell, 3 - Selection, 4 - Heap, 5 - Quick, X - Exit() ]" << endl;
        cin >> choice;
        switch (choice) {
            case '1': {
                cout
                        << "\nWhich array?[\"R\" - random, \"A\" - ascending, \"D\" - descending, \"S\" - static, \"X\" - Ascending-descending]"
                        << endl;
                char choice2;
                cin >> choice2;
                if (choice2 == 'R') {
                    auto start = std::chrono::high_resolution_clock::now();
                    insertionSort(randarray, size);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

                    cout << "Time in nanoseconds: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << randarray[i] << " ";
                    }

                } else if (choice2 == 'A') {
                    auto start = std::chrono::high_resolution_clock::now();
                    insertionSort(ascarray, size);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    cout << "Time in nanoseconds: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << ascarray[i] << " ";
                    }
                } else if (choice2 == 'D') {
                    auto start = std::chrono::high_resolution_clock::now();
                    insertionSort(descarray, size);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    cout << "Time in nanoseconds: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << descarray[i] << " ";
                    }
                } else if (choice2 == 'S') {
                    auto start = std::chrono::high_resolution_clock::now();
                    insertionSort(staticarray, size);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    cout << "Time in nanoseconds: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << staticarray[i] << " ";
                    }
                } else if (choice2 == 'X') {
                    auto start = std::chrono::high_resolution_clock::now();
                    insertionSort(adarray, size);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    cout << "Time in nanoseconds: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << adarray[i] << " ";
                    }
                } else {
                    cout << "Error";
                }
                break;
            }
            case '2': {
                cout
                        << "\nWhich array?(\"R\" - random, \"A\" - ascending, \"D\" - descending, \"S\" - static, \"X\" - Ascending-descending"
                        << endl;
                char choice2;
                cin >> choice2;
                if (choice2 == 'R') {
                    auto start = std::chrono::high_resolution_clock::now();
                    shellSort(randarray, size);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    cout << "Time in nanoseconds: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << randarray[i] << " ";
                    }

                } else if (choice2 == 'A') {
                    auto start = std::chrono::high_resolution_clock::now();
                    shellSort(ascarray, size);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    cout << "Time in nanoseconds: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << ascarray[i] << " ";
                    }
                } else if (choice2 == 'D') {
                    auto start = std::chrono::high_resolution_clock::now();
                    shellSort(descarray, size);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    cout << "Time in nanoseconds: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << descarray[i] << " ";
                    }
                } else if (choice2 == 'S') {
                    auto start = std::chrono::high_resolution_clock::now();
                    shellSort(staticarray, size);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    cout << "Time in nanoseconds: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << staticarray[i] << " ";
                    }
                } else if (choice2 == 'X') {
                    auto start = std::chrono::high_resolution_clock::now();
                    shellSort(adarray, size);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    cout << "Time in nanoseconds: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << adarray[i] << " ";
                    }
                } else {
                    cout << "Error";
                }
                break;
            }
            case '3': {
                cout
                        << "\nWhich array?(\"R\" - random, \"A\" - ascending, \"D\" - descending, \"S\" - static, \"X\" - Ascending-descending"
                        << endl;
                char choice2;
                cin >> choice2;
                if (choice2 == 'R') {
                    auto start = std::chrono::high_resolution_clock::now();
                    selectionSort(randarray, size);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    cout << "Time in nanoseconds: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << randarray[i] << " ";
                    }

                } else if (choice2 == 'A') {
                    auto start = std::chrono::high_resolution_clock::now();
                    selectionSort(ascarray, size);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    cout << "Time in nanoseconds: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << ascarray[i] << " ";
                    }
                } else if (choice2 == 'D') {
                    auto start = std::chrono::high_resolution_clock::now();
                    selectionSort(descarray, size);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    cout << "Time in nanoseconds: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << descarray[i] << " ";
                    }
                } else if (choice2 == 'S') {
                    auto start = std::chrono::high_resolution_clock::now();
                    selectionSort(staticarray, size);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    cout << "Time in nanoseconds: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << staticarray[i] << " ";
                    }
                } else if (choice2 == 'X') {
                    auto start = std::chrono::high_resolution_clock::now();
                    selectionSort(adarray, size);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    cout << "Time in nanoseconds: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << adarray[i] << " ";
                    }
                } else {
                    cout << "Error";
                }
                break;
            }
            case '4': {
                cout
                        << "\nWhich array?(\"R\" - random, \"A\" - ascending, \"D\" - descending, \"S\" - static, \"X\" - Ascending-descending"
                        << endl;
                char choice2;
                cin >> choice2;
                if (choice2 == 'R') {
                    auto start = std::chrono::high_resolution_clock::now();
                    heapSort(randarray, size);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    cout << "Time in ns: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << randarray[i] << " ";
                    }

                } else if (choice2 == 'A') {
                    auto start = std::chrono::high_resolution_clock::now();
                    heapSort(ascarray, size);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    cout << "Time in nanoseconds: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << ascarray[i] << " ";
                    }
                } else if (choice2 == 'D') {
                    auto start = std::chrono::high_resolution_clock::now();
                    heapSort(descarray, size);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    cout << "Time in nanoseconds: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << descarray[i] << " ";
                    }
                } else if (choice2 == 'S') {
                    auto start = std::chrono::high_resolution_clock::now();
                    heapSort(staticarray, size);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    cout << "Time in nanoseconds: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << staticarray[i] << " ";
                    }
                } else if (choice2 == 'X') {
                    auto start = std::chrono::high_resolution_clock::now();
                    heapSort(adarray, size);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    cout << "Time in nanoseconds: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << adarray[i] << " ";
                    }
                } else {
                    cout << "Error";
                }
                break;
            }
            case '5': {
                cout
                        << "\nWhich array?(\"R\" - random, \"A\" - ascending, \"D\" - descending, \"S\" - static, \"X\" - Ascending-descending"
                        << endl;
                char choice2;
                cin >> choice2;
                if (choice2 == 'R') {
                    auto start = std::chrono::high_resolution_clock::now();
                    quickSort(randarray, 0, size - 1);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

                    cout << "Time in nanoseconds: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << randarray[i] << " ";
                    }

                } else if (choice2 == 'A') {
                    auto start = std::chrono::high_resolution_clock::now();
                    quickSort(ascarray, 0, size - 1);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    cout << "Time in ns: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << ascarray[i] << " ";
                    }
                } else if (choice2 == 'D') {
                    auto start = std::chrono::high_resolution_clock::now();
                    quickSort(descarray, 0, size - 1);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    cout << "Time in ns: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << descarray[i] << " ";
                    }
                } else if (choice2 == 'S') {
                    auto start = std::chrono::high_resolution_clock::now();
                    quickSort(staticarray, 0, size - 1);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    cout << "Time in ns: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << staticarray[i] << " ";
                    }
                } else if (choice2 == 'X') {
                    auto start = std::chrono::high_resolution_clock::now();
                    quickSort(adarray, 0, size - 1);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    cout << "Time in ns: " << ns << endl;
                    cout << "After sorting: " << endl;
                    for (int i = 0; i < size; i++) {
                        cout << adarray[i] << " ";
                    }
                } else {
                    cout << "Error";
                }
                break;
            }
            case 'X':{
                exit(0);
            }
            default: {
                cout << "Error" << endl;
                break;
            }
        }

    }
}
