#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(string);

int main() {
   string filename;
   ifstream fin;
   cout << "Enter the name of the input file: " << endl;
   cin >> filename;
   fin.open(filename);
   if (!fin.is_open()){
       cout << "Error opening " << filename << endl;
       return 1;
   }
   cout << endl;
   cout << "Sum: " << fileSum(filename) << endl;
   return 0;
}

// Place fileSum implementation here
int fileSum(string filename) {
    ifstream fin;
    int n;
    int sum = 0;
    fin.open(filename);
    while (fin >> n) {
        sum += n;
    }
    fin.close();
    return sum;
    
}