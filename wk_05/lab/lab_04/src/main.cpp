#include <iostream>
#include "Show.h"
#include "TVShow.h"
#include "Movie.h"


int DisplayOptions();
Show CreateShow();
TVShow CreateTVShow();
Movie CreateMovie();


int main()
{
	return 0;
}


int DisplayOptions()
{
	string input;
	cout << "What kind of object would you like to create?" << endl
		<< "Press 1 for an instance of Show." << endl
		<< "Press 2 for an instance of Movie." << endl
		<< "Press 3 for an instance of TV Show." << endl
		<< "Press 4 for an instance of Movie declared as Show" << endl
		<< "Press 5 for an instance of TV Show declared as a Show" << endl;
	cin >> input;

	return stoi(input);
}


Show CreateShow()
{
	return { "Breaking Bad", "Description" };
}


TVShow CreateTVShow()
{
	vector<vector<Episode>> show;

	// Season 1
	show.push_back({
		{1, "Pilot - Chemistry teacher Walter White partners with a former student to make meth."},
		{2, "Cat's in the Bag - Walt and Jesse clean up the mess after their first cook."},
		{3, "...And the Bag's in the River - Walt makes a tough decision about a captive."},
		{4, "Cancer Man - Walt reveals his diagnosis to his family."},
		{5, "Gray Matter - Walt is offered financial help but refuses."},
		{6, "Crazy Handful of Nothin' - Walt creates his Heisenberg persona."},
		{7, "A No-Rough-Stuff-Type Deal - Jesse and Walt expand their operation."}
		});

	// Season 2
	show.push_back({
		{1, "Seven Thirty-Seven - Walt and Jesse deal with Tuco's instability."},
		{2, "Grilled - Tuco kidnaps Walt and Jesse."},
		{3, "Bit by a Dead Bee - Walt returns home after his disappearance."},
		{4, "Down - Jesse struggles with his parents."},
		{5, "Breakage - Jesse expands the business with his friends."},
		{6, "Peekaboo - Jesse finds a neglected child during a drug retrieval."},
		{7, "Negro y Azul - The blue meth gains notoriety."},
		{8, "Better Call Saul - The duo hires lawyer Saul Goodman."},
		{9, "4 Days Out - Walt and Jesse get stranded in the desert."},
		{10, "Over - Walt tries to assert control over his life."},
		{11, "Mandala - Jane introduces Jesse to heroin."},
		{12, "Phoenix - Walt misses his daughter’s birth."},
		{13, "ABQ - A tragic event unfolds due to Jane’s death."}
		});

	return { "Breaking Bad", "Descritpion", show };
}


Movie CreateMovie()
{
	return { "Star Wars", "Description", "PG-13" };
}