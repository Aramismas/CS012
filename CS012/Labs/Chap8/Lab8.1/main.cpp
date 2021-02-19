#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);


int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here
void flipString(string &s) {
    string flip;
    if (s.length() <= 0) {
        return;
    }
    else {
        char f = s.at(s.length()-1);
        flip = s.substr(0,s.length()-1);
        flipString(flip);
        s = f + flip;
    }
}
