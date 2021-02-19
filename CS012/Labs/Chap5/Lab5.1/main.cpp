//include any standard libraries needed
#include <iostream>
#include <fstream>

using namespace std;

//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize);

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index);


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize);


const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
    ifstream fin;
    double n;
    int index;
    fin.open(argv[1]);
    if (argc < 1) {
        return 1;
    }
   // verify file name provided on command line
    if (!fin.is_open()) {
        return 1;
    }
   // open file and verify it opened

   // Declare an array of doubles of size ARR_CAP.
    double arr[ARR_CAP];
    
    int size = 0;
    while (fin >> n) {
        arr[size] = n;
        size++;
    }
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.

    
   // Call the mean function passing it this array and output the 
    cout << "mean: " << mean(arr, size) << endl;
   // value returned.
    
   // Ask the user for the index (0 to size - 1) of the value they want to remove.
    cout << "Enter index of value to be removed (0 to " << size-1 << "):" << endl;
    cin >> index;
	
   // Call the display function to output the array.
    cout << "Before removing value: ";
    display(arr, size);

   
   // Call the remove function to remove the value at the index
   // provided by the user.
    remove(arr, size, index);
  
    
   // Call the display function again to output the array
   // with the value removed.
    cout << "After removing value: ";
    display(arr, size);

   
   // Call the mean function again to get the new mean
    cout << "mean: " << mean(arr, size) << endl;
   
	return 0;
}

double mean(const double array[], int arraySize) {
    double m, sum;
    m = 0;
    sum = 0;
    for (int i = 0; i < arraySize; i++)
        sum += array[i];
    m = sum/arraySize;
    return m;  
}

void remove(double array[], int &arraySize, int index) {
    if ((index < 0) || (index > arraySize)) {
        return;
    }
    else {
        for (int i = index; i < arraySize-1; i++) {
            array[i] = array[i+1];
        }
        arraySize--;
    }
}

void display(const double array[], int arraySize) {
    for (int i = 0; i < arraySize-1; i++) {
            cout << array[i] << ", ";
    }
    cout << array[arraySize-1] << endl;
}