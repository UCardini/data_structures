#include "Movie.h"


void Movie::setAgeRating(string rating)
{
	AgeRating = rating;
}


string Movie::getAgeRating()
{
	return AgeRating;
}


void Movie::Play()
{
	cout << "Age Rating: " << AgeRating << endl;
}
