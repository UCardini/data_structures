#include "Movie.h"


Movie::Movie(string title, string description, string rating) : Show(title, description)
{
	AgeRating = rating;
}


void Movie::setAgeRating(string age_rating)
{
	AgeRating = age_rating;
}


string Movie::getAgeRating()
{
	return AgeRating;
}


void Movie::Play()
{
	cout << "Age Rating: " << AgeRating;
}
