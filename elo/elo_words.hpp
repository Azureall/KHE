#ifndef ELLO_WORDS_HPP
#define ELLO_WORDS_HPP

#include <iostream>
#include <fstream>
#include <cmath>
#include <string> 
#include <vector>
#include <conio.h>

//#define KEY_UP 72 //up could be used for backing up
					//incase an incorrect rating was made
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77



class Word{
public:
	Word();
	Word(std::string);
	void SetWord(std::string);
	void SetRating(double);
	//void SetWordAndRating(std::string, int);
	double GetRating() const;
	void SetExpectedRating(double);
	double GetExpectedRating() const;
	void UpdateRating(bool);
	std::string GetWord() const;
		

private:
	std::string word; 
	double rating; 
	double expected_rating; 
};

void updateExpectedRating(Word a, Word b);


#endif // !ELLO_WORDS_HPP
