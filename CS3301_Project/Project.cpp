// project CS3301
// DON'T CHANGE THIS FILE NAME AND THE CODE PROVIDED !!!
//continue writing your codes into this file
//compile it and test it with test.input.csv

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

std::vector<int> read_input(const std::string &path){
	std::vector<int> arr;
    std::ifstream ifs;
    ifs.open(path,std::ios::in);
    if (!ifs.is_open())
    {
        std::cout << "read fail." << std::endl;
        
    }
    std::string line;
    while(std::getline(ifs,line))
    {
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<int> parsedRow;
        while(std::getline(lineStream,cell,','))
        {
            auto i = std::atoi(cell.c_str());
            arr.push_back(i);
        }

    }
	return arr;
}

std::vector<int> longest_alternative_seq(std::vector<int> &arr){
	std::vector<int> longest_altseq;
	// IMPLEMENT YOUR CODES HERE 
    
    longest_altseq.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++) {
        int front = longest_altseq[longest_altseq.size() - 1];
        int back;
        if (i + 1 < arr.size()) {
            back = arr[i + 1];
        }
        else {
            back = front;
        }
        if ((front - arr[i] != 0) && (arr[i] - back != 0)) {
            if (signbit(float(front - arr[i])) != signbit(float(arr[i] - back))) {
                longest_altseq.push_back(arr[i]);
            }
        }
    }
	
	return longest_altseq;
}

int main(int args, char* argv[]) {
	std::vector<int> arr = read_input(argv[1]);
	std::vector<int> output_arr = longest_alternative_seq(arr);
	for(int i = 0; i < output_arr.size(); i++) {
		std::cout<<output_arr[i];
		if(i== output_arr.size()-1) break;
		std::cout<<",";
	}
	std::cout<<"\n";
    return 0;
}