#include <iostream>
#include <vector>
#include <chrono>
using namespace std::chrono;
using namespace std;


// -- SET 1 -- \\
//
//
//problem 1
//
// int arraySum(int A[], int n) {
//     int sum = 0;
//     for (int i = 0; i < n; i++) {
//         sum += A[i];
//     }
//     return sum;
// }
//
//
// int main() {
//
//     int n;
//     cout << "Enter n: " << endl;
//     cin >> n;
//     int* A = new int[n];
//
//     for (int i = 0; i < n; i++) {
//         A[i] = rand() % 100;
//     }
//
//
//     auto start = high_resolution_clock::now();
//
//     int result = arraySum(A, n);
//
//     auto stop = high_resolution_clock::now();
//     auto duration = duration_cast<microseconds>(stop - start);
//     cout << "Time taken: " << duration.count() << " microseconds" << endl;
//
//     delete[] A;
//
//     return 0;
// }



//problem 2
//
// int linearSearch(int A[], int n, int key) {
//     for (int i = 0; i < n; i++) {
//         if (A[i] == key) return i;
//     }
//     return -1;
// }
//
// int main() {
//
//     int n;
//     cout << "Enter n: " << endl;
//     cin >> n;
//
//     int* A = new int[n];
//     for (int i = 0; i < n; i++) {
//         A[i] = i;
//     }
//
//
//     auto start = high_resolution_clock::now();
//
//     linearSearch(A, n, A[0]);
//
//     auto finish = high_resolution_clock::now();
//     auto duration = duration_cast<microseconds>(finish - start);
//     cout << "Best case time taken: " << duration.count() << " microseconds" << endl;
//
//     start = high_resolution_clock::now();
//
//     linearSearch(A, n, A[n/2]);
//
//     finish = high_resolution_clock::now();
//     duration = duration_cast<microseconds>(finish - start);
//     cout << "Average case time taken: " << duration.count() << " microseconds" << endl;
//
//     start = high_resolution_clock::now();
//
//     linearSearch(A, n, -999999999);
//
//     finish = high_resolution_clock::now();
//     duration = duration_cast<microseconds>(finish - start);
//     cout << "Worst case time taken: " << duration.count() << " microseconds" << endl;
//
//     delete [] A;
//     return 0;
// }



//problem 3
//
// void bubbleSort(int A[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n - 1 - i; j++) {
//             if (A[j] > A[j + 1]) {
//                 int temp = A[j];
//                 A[j] = A[j + 1];
//                 A[j + 1] = temp;
//             }
//         }
//     }
// }
//
// int main() {
//
//     int n;
//     cout << "Enter n: ";
//     cin >> n;
//
//     int* A = new int[n];
//     for (int i = 0; i < n; i++) {
//         A[i] = rand() % 100;
//     }
//
//     auto start = high_resolution_clock::now();
//
//     bubbleSort(A, n);
//
//     auto finish = high_resolution_clock::now();
//     auto duration = duration_cast<microseconds>(finish - start);
//     cout << "Time taken: " << duration.count() << " microseconds" << endl;
//
//     delete[] A;
//     return 0;
// }



//problem 4
//
// int main() {
//     const int CAP = 100000;
//     int n;
//     cout << "Enter number of elements: ";
//     cin >> n;
//
//     int A[CAP];
//     int* B = new int[n];
//
//     auto startA = chrono::high_resolution_clock::now();
//
//     for (int i = 0; i < n; i++) {
//         A[i] = i;
//     }
//
//     auto endA = chrono::high_resolution_clock::now();
//
//     auto startB = chrono::high_resolution_clock::now();
//
//     for (int i = 0; i < n; i++) {
//         B[i] = i;
//     }
//
//     auto endB = chrono::high_resolution_clock::now();
//
//     auto timeA = chrono::duration_cast<chrono::microseconds>(endA - startA).count();
//
//     auto timeB = chrono::duration_cast<chrono::microseconds>(endB - startB).count();
//
//     cout << "Static array bytes: " << sizeof(A) << endl;
//     cout << "Dynamic array bytes: " << n * sizeof(int) << endl;
//
//     cout << "Static fill time: " << timeA << " microseconds" << endl;
//     cout << "Dynamic fill time: " << timeB << " microseconds" << endl;
//
//     delete[] B;
//
//     return 0;
// }



//problem 5
//
int main() {
    int n;
    cout << "Enter n: " << endl;
    cin >> n;

    vector<int> v;
    int capacityJumps = 0;

    auto start1 = chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        v.push_back(rand());

        if (v.size() == 1 ||
            (v.size() & (v.size() - 1)) == 0) {
            cout << "Size: " << v.size()
                 << ", Capacity: " << v.capacity() << endl;
            capacityJumps++;
            }
    }
    cout << "Capacity Jumps: " << capacityJumps << endl;

    auto end1 = chrono::high_resolution_clock::now();


    vector<int> w;
    w.reserve(n);

    auto start2 = chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        w.push_back(rand());
    }

    auto end2 = chrono::high_resolution_clock::now();

    auto time1 = chrono::duration_cast<chrono::microseconds>(
        end1 - start1).count();

    auto time2 = chrono::duration_cast<chrono::microseconds>(
        end2 - start2).count();

    cout << "\nWithout reserve: " << time1 << " microseconds" << endl;
    cout << "With reserve:    " << time2 << " microseconds" << endl;

    return 0;
}
