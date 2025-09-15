#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<string> slices;

int main() {
	int linecount=0,total_weight=0;
	string line;
	ifstream list_slice("lista.txt");
while (getline(list_slice,line)){
	++linecount;
	if (!line.empty()) {size_t dot_pos = line.find('.');
        if (dot_pos != string::npos) {
            string name = line.substr(0, dot_pos);
            int weight = stoi(line.substr(dot_pos + 1));
            total_weight += weight;
            for (int i = 0; i < weight; i++) {
                slices.push_back(name);
            }
        }
	}
}
    mt19937 gen(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<> distrib(0, total_weight - 1);

    int rnd = distrib(gen);
	cout<<rnd<<endl;
	cout<<slices[rnd]<<endl;
	system("pause");
  list_slice.close();
  return 0;
}
