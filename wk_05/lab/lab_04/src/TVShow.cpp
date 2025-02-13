#include "TVShow.h"



void TVShow::Play()
{
	int season = 0;
	int episode = 0;

	cout << "Enter Season number: ";
	cin >> season;

	cout << "Enter Episode number: ";
	cin >> episode;

	Episode* episode_ptr;

	episode_ptr = &Show_Content[season - 1][episode - 1];

	cout << episode_ptr->Summary;
}


void TVShow::Details()
{
	cout << "Title: " << Title << endl
		<< "Seasons: " << Show_Content.size() << endl
		<< "Description:" << endl << Description << endl;
}
