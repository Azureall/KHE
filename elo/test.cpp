#include "elo_words.hpp"

int main() {
	std::ifstream file("words.txt");
	if (!file.is_open()) {
		std::cout << "Unable to open file\n";
		return 1;
	}

	//std::ofstream out("output.txt");
	//if (out.is_open()) {
		//std::cout << "unable to open file (output)\n";
		//return 1; 
	//}


	//initializes vector
	std::string line;
	std::vector<Word>competitor;
	while (std::getline(file, line)) {
		competitor.push_back(line);
	}

	//prompt
	std::cout << "Which word is more 'offensive' to you?\n" << std::endl;
	
	//could be done with iterators
	//calculates scores
	for (size_t i = 0; i < competitor.size(); ++i) {
		for (size_t j = 0; j < competitor.size(); ++j) {

			if (i == j) {
				continue;
			}
			else {
				//prevents an evaluation of word vs itself.. english isn't working
				std::cout << competitor[i].GetWord() << '(' << competitor[i].GetRating() << ')' << "  vs  "
					<< competitor[j].GetWord() << '(' << competitor[j].GetRating() << ')' << std::endl;
				//std::cout << std::endl; 

				updateExpectedRating(competitor[i], competitor[j]);
				//std::cout << "updated expected ratings\n\n";

				int c = 0;
				bool loop = true;
				while (loop) {
					switch (c = _getch()) {
					case KEY_LEFT:
						//std::cout << "left\n" << std::endl; 
						competitor[i].UpdateRating(1);
						competitor[j].UpdateRating(0);
						loop = false; 
						break;

					case KEY_RIGHT:
						//std::cout << "right\n" << std::endl;
						competitor[j].UpdateRating(1);
						competitor[i].UpdateRating(0);
						loop = false; 
						break;

					}

				}
				std::cout << "result:  ";;
				std::cout << competitor[i].GetWord() << '(' << competitor[i].GetRating() << ')' << " "
					<< competitor[j].GetWord() << '(' << competitor[i].GetRating() << ')' << std::endl;
				std::cout << std::endl << std::endl;
			}
		}

	}

	//printing out
	for (size_t i = 0; i < competitor.size(); ++i) {
		std::cout << competitor[i].GetWord() << ": " << competitor[i].GetRating();
		std::cout << std::endl; 
	}
	


	return 0;
}