#ifndef DATA_H_
#define DATA_H_
#include <cstring>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include "VectorMap.h"
#include "DistanceType.h"
using namespace std;

class Data {
    /// @brief distance type by int.
    VectorMap vec;
    string disName;
    int k;
    DistanceType disType;

public:
    Data();
    Data(string fname, string disNum, int k, DistanceType disType);
    string getDisName();
    int getk();
    void setK(int newK);
    void setDisName(string newDisName);
    void setDisType(DistanceType newDisType);
    VectorMap getVectorMap();


};
#endif