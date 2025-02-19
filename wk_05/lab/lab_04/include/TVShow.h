#pragma once
#include "Show.h"
#include "Episode.h"
#include <vector>

using std::vector;


class TVShow : public Show
{
private:
	vector <vector<Episode>> Show_Content;

public:
	TVShow(string, string, vector<vector<Episode>>);

	void Play() override;
	void Details();
};
