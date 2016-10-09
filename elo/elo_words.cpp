//10/9/2016
//currently works incorrectly
//isn't a quite a "real elo rating system" 
#include "elo_words.hpp"

Word::Word() {
	word = ""; 
	rating = 1000.0;
	expected_rating = .5;
}


Word::Word(std::string input) {
	word = input;
	rating = 1000.0;
	expected_rating = .5;
}

void Word::SetRating(double input) {
	rating = input; 
}

void Word::SetWord(std::string input) {
	word = input; 
}

double Word::GetRating()const{
	return rating;
}

void Word::SetExpectedRating(double rating) {
	expected_rating = rating;
}

//gets executed after every match
void updateExpectedRating(Word a, Word b) {
	//double a_old_rating = a.GetRating(); 
	//setting a's rating
	double new_rating_raw = 1.0 / (1 + (std::pow(10, ((b.GetRating() - a.GetRating()))/400.0)));
	//int new_rating = std::round(new_rating_raw); 
	a.SetExpectedRating(new_rating_raw);
	
	//setting b's rating
	//new_rating_raw = 1 / (1.0 + (std::pow(10, ((a_old_rating - b.GetRating())) / 400.0)));
	//new_rating = std::round(new_rating_raw);
	b.SetExpectedRating(1-a.GetExpectedRating());
}


void Word::UpdateRating(bool result) {//change to double result for ties
	double q = 32.0 * (result - GetExpectedRating());
	double new_rating = rating + q;
	// rounded_rating = std::round(new_rating);
	SetRating(new_rating);
}

std::string Word::GetWord()const{
	return word; 
}

double Word::GetExpectedRating()const{
	return expected_rating;
}