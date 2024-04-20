#pragma once

#include "iostream"
#include "fstream"
#include "sstream"
using namespace std;

bool DataRetrieve(const string& filename,double &S, size_t &n, double* &w, double* &r);

double RateOfReturn(const size_t& n, const double* const &w, const double* const &r);

bool DataOutput(const string& filename,double &S, size_t &n,
                const double* const &w, const double* const &r, const double &ror);
