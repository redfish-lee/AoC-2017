#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

vector<char> input;
const char* filename = "input";

void readInput(const char* filename){
    // read file and store into input array
    ifstream infs;
    infs.open(filename);

    char tmp;
    while(infs >> tmp) {
        input.push_back(tmp);
    }
    infs.close();
}

// Part I : find next
int traverseArray1() {
    // For circular
    input.push_back(input[0]);

    int sum = 0;
    for(int i = 0; i < input.size() - 1; ++i) {
        if (input[i] == input[i+1]) {
            sum += input[i] - '0';
        }
    }
    return sum;
}

// Part II : find next offset (offset = total / 2)
int traverseArray2() {
    int sum = 0;
    int offset = input.size()/2;
    for(int i = 0; i < offset; ++i) {
        if (input[i] == input[i + offset]) {
            sum += input[i] - '0';
        }
    }
    // for circular
    return sum * 2;
}

int main(int argc, char** argv) {
    readInput(filename);
    int ret1 = traverseArray1();
    int ret2 = traverseArray2();
    cout << "Captcha 1 : " << ret1 << endl;
    cout << "Captcha 2 : " << ret2 << endl;
    return 0;
}
