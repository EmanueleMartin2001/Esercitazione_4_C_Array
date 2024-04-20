#pragma once

#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"

using namespace std;

bool DataRetrieve(const string& filename,double &S, size_t &n, double* &w, double* &r){

    ifstream file;
    file.open(filename);

    if (file.fail())
    {
        cerr << "file did not open successfully" << endl;
        return false;
    }

    //retrieve S,n
    string line;
    char separator = ';';
    while (getline(file,line)){
        if (line[0] == 'S'){
            istringstream ss(line);
            getline(ss,line,separator);
            getline(ss,line,separator);
            S = stod(line); //could be decimal (stod for changing type into a double)
        }
        if (line[0] == 'n'){
            istringstream ss2(line);
            getline(ss2,line,separator);
            getline(ss2,line,separator);
            n = stoul(line); //change the type of n in an unsigned int
        }
        if (line[0] == 'w'){
            break;
        }
    }

    //retrieve the 2 arrays which contain w and r
    w = new double[n]; //creates a dynamic array and the pointer point to its start
    r = new double[n];
    int index = 0;
    while (getline(file,line)){
        istringstream ss(line);

        getline(ss,line,separator);
        w[index] = stod(line);

        getline(ss,line,separator);
        r[index] = stod(line);

        index++;
    }

    return true;
}

double RateOfReturn(const size_t& n, const double* const &w, const double* const &r){
    double ror = 0;
    for (int i; i < n; i++){
        ror += w[i]*r[i];
    }
    return ror;
}

bool DataOutput (const string& filename,double &S, size_t &n,
                const double* const &w, const double* const &r, const double &ror){
    ofstream ofstr; //output stream utilizzato per scrivere dati in uscita
    ofstr.open(filename);
    if (!ofstr.is_open()) //check if the file has been opened  successfully
    {
        cerr << "file could not be opened" << endl;
        return false;
    }
    ofstr << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
    ofstr << "w = [ ";
    for (int i=0; i < n; i++){
        ofstr << defaultfloat << w[i] << " ";
    }
    ofstr << "]" << endl;
    ofstr << "r = [ ";
    for (int i=0; i < n; i++){
        ofstr << defaultfloat << r[i] << " ";
    }
    ofstr << "]" << endl;
    ofstr << "Rate of return of the portfolio: " << setprecision(4) <<ror << endl;
    ofstr << "V: " << fixed << setprecision(2) << (ror+1)*S << endl;
    return true;

}

