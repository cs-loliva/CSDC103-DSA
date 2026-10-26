#include <iostream>
using namespace std;

void selecctionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j ++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
//code snippet from lecture

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - 1; j ++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

//code snippet from lecture


//so chic for a helper print fxn to be here purr

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (i > 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    
    int n;
    cin >> n;
    
    int ogArr[100];
    int bubbleArr[100];
    int selectionArr[100];
    
    for (int i = 0; i < n; i++) {
        cin >> ogArr[i];
        bubbleArr[i] = ogArr[i];
        selectionArr[i] = ogArr[i];
    }

    bubbleSort(bubbleArr, n);
    selecctionSort(selectionArr, n);
    
    cout << "Bubble Sort: ";
    printArr(bubbleArr, n);
    
    cout << "Selection Sort: ";
    printArr(selectionArr, n);
    return 0;
}