#pragma once
#include "Show.h"
#include "Episode.h"
#include <vector>

using std::vector;


class TVShow : protected Show
{
protected:
	vector <vector<Episode>> Show_Content = { {{1, "Summary"}}};

public:
	void Play() override;

	using Show::Details;

	void Details();
};
