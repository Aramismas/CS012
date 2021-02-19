#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   
   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];
   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];
   
   // Create input stream and open input csv file.
   ifstream fin;
   ofstream ofin;
   vector<int> numbers;
   // Verify file opened correctly.
   fin.open(inputFile);
   if (!fin.is_open()) {
       cout << "Error opening " << inputFile << endl;
       return 1;
   }
   // Output error message and return 1 if file stream did not open correctly.
   int n;
   char c;
   // Read in integers from input file to vector.
   while (fin >> n) {
       fin >> c;
       numbers.push_back(n);
   }
   fin.close();
   // Close input stream.
   
   // Get integer average of all values read in.
   int sum = 0;
   int size = numbers.size();
   int average;
   for (int i = 0; i < size; i++) {
       sum += numbers.at(i);
   }
   average = sum/size;
   // Convert each value within vector to be the difference between the original value and the average.
   for (int i = 0; i < size; i++) {
       numbers.at(i) = numbers.at(i) - average;
   }
   
   // Create output stream and open/create output csv file.
   ofin.open(outputFile);

   // Verify file opened or was created correctly.
   if (!ofin.is_open()) {
       cout << "Error opening " << outputFile << endl;
       return 1;
   }
   // Output error message and return 1 if file stream did not open correctly.
   
   // Write converted values into ouptut csv file, each integer separated by a comma.
   for (int i = 0; i < size - 1; i++){
       ofin << numbers.at(i) << ", ";
   }
   ofin << numbers.at(size - 1);
   // Close output stream.
   ofin.close();
   
   return 0;
}