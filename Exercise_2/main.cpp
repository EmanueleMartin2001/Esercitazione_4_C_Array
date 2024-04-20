#include "Utils.hpp"

/* Data Retrieve import data from data.csv
 * RateofReturn calculates the rate of return :()
 * DataOutput write in the file result.txt
 */

using namespace std;
int main()
{
    string infile =  "data.csv";
    double S = 0;
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;
    DataRetrieve(infile,S,n,w,r);
    double ror = RateOfReturn(n,w,r);

    string outFile = "result.txt";
    DataOutput(outFile,S,n,w,r, ror);
    delete[] w; //memory release
    delete[] r;
    return 0;
}


