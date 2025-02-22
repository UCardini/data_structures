#pragma once
#include "Show.h"


class Movie : public Show
{
private:
	string AgeRating;

public:
	Movie(string, string, string);

	void setAgeRating(string);

	string getAgeRating();

	void Play() override;
};
