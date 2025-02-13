#include "Movie.h"

void Movie::setAgeRating( string age_rating ) { AgeRating = age_rating; }

string Movie::getAgeRating() { return AgeRating; }

void Movie::Play() { cout << "Age Rating: " << AgeRating << endl; }
