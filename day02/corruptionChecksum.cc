#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

#define SUPPOSEDNOTREACHED  -1
using namespace std;

const char* filename = "input";

int getDiff(const char* line) {
    char* total = strdup(line);

    char* pch;
    pch = strtok(total, " \t\n");
    int max = atoi(pch);
    int min = atoi(pch);

    while (pch != NULL) {
        int tmp = atoi(pch);
        if (tmp > max) max = tmp;
        if (tmp < min) min = tmp;
        pch = strtok (NULL, " \t\n");
    }
    return max-min;
}

int getQuot(const char* line) {
    char* total = strdup(line);
    vector<int> items;

    char* pch;
    pch = strtok(total, " \t\n");
    while (pch != NULL) {
        items.push_back(atoi(pch));
        pch = strtok (NULL, " \t\n");
    }
    
    for(int i = 0; i < items.size(); ++i) { 
        for(int j = i+1; j < items.size(); ++j) {
            if (items[i] % items[j] == 0) return items[i] / items[j];
            if (items[j] % items[i] == 0) return items[j] / items[i];
        }
    }
    return SUPPOSEDNOTREACHED;
}

int sumCalc(const char* filename, int part){
    // read file and store into input array
    ifstream infs;
    infs.open(filename);

    int sum = 0;
    string line;
    if (part == 1) {
        while(getline(infs, line)) sum += getDiff(line.c_str());
    }
    else if (part == 2) {
        while(getline(infs, line)) sum += getQuot(line.c_str());
    }
    else cerr << "Unknown part" << endl;
    
    infs.close();
    return sum;
}

int main(int argc, char** argv) {
    int ret1 = sumCalc(filename, 1);
    int ret2 = sumCalc(filename, 2);
    return 0;
}
