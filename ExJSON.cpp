#include <fstream>
#include <string>
#include <iostream>

int main(){

        std::ifstream in;
        std::ofstream out;

        in.open("NegWords.txt");
        out.open("JSONNeg.txt");

	if(!in.is_open()){
		std::cout << "input file did not open." << std::endl;
	}

	if(!out.is_open()){
                std::cout << "output file did not open." << std::endl;
        }

	std::string line;

    while(!in.eof()){
        getline(in, line);
        std::cout << line << std::endl;
        out << "{word:\"" << line << "\" , rating:}," << std::endl;
        }

        in.close();
        out.close();

	return 0;

}
