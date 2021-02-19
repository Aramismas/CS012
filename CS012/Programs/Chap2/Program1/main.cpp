#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

int main (int argc, char *argv[]) {
    string fileName;
    vector<double> angles;
    vector<double> coef;
    double flightAngle;
    string response;
    fileName = argv[1];
    readData(fileName, angles, coef);
    if (!isOrdered(angles)) {
        reorder(angles, coef);
    }
    cout << "Enter a flight angle" << endl;
    cin >> flightAngle;
    cout << "The corresponding coefficient of lift is " << interpolation(flightAngle, angles, coef) << endl;
    cout << "Would you like to enter another angle?" << endl;
    cin >> response;
    while (response != "No") {
        cout << "Enter a flight angle" << endl;
        cin >> flightAngle;
        cout << "The corresponding coefficient of lift is " << interpolation(flightAngle, angles, coef) << endl;
        cout << "Would you like to enter another angle?" << endl;
        cin >> response;
    }
    return 0;
}

void readData(const string &fileName, vector<double> &angles, vector<double> &coef) {
    ifstream fin;
    double a;
    double c;
    fin.open(fileName);
    if (!fin.is_open()){
        cout << "Error opening " << fileName << endl;
        exit(1);
    }
    while (fin >> a >> c) {
        angles.push_back(a);
        coef.push_back(c);
    }
    fin.close();
}

double interpolation(double b, const vector<double> &angles, const vector<double> &coef) {
    int size = angles.size();
    double ang;
    double ac;
    double co;
    double cc;
    if ((b < angles.at(0)) || (b > angles.at(size-1)) ) {
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        if (abs(b-(angles.at(i))) < 0.0001){
            return coef.at(i);
        }
    }
    for (int i = 0; i < size-1; i++) {
        if ((b > angles.at(i)) && (b < angles.at(i+1)) ) {
            ang = angles.at(i); 
            ac = coef.at(i); 
            co = angles.at(i+1);
            cc = coef.at(i+1); 
        }
    }
    return (ac + ((b - ang)/(co - ang))*(cc - ac));
}


bool isOrdered(const vector<double> &angles) {
    int size = angles.size();
    for (int i = 0; i < size-1; i++) {
            if (angles.at(i+1) < angles.at(i)){
                return false;
            }
    }
    return true;
}

void reorder(vector<double> &angles, vector<double> &coef) {
    double minValue;
    double otherValue;
    int size = angles.size();
    for (int i = 0; i < size-1; i++) {
        minValue = angles.at(i);
        otherValue = coef.at(i+1);
        for (int j = i+1; j < size; j++) {
            if (minValue > angles.at(j)) {
                minValue = angles.at(j);
                otherValue = coef.at(j);
                angles.at(j) = angles.at(i); 
                coef.at(j) = coef.at(i); 
                angles.at(i) = minValue;
                coef.at(i) = otherValue;
            }
        }
    }
}