#include <iostream>
#include <stdlib.h>
#include "Show.h"
#include "TVShow.h"
#include "Movie.h"


int DisplayOptions();
Show CreateShow();
TVShow CreateTVShow();
Movie CreateMovie();
Show* CreateMovie_Show();
Show* CreateTVShow_Show();


int main()
{
	bool running = true;
	while (running)
	{
		int option = DisplayOptions();

		if (option == 1)
		{
			Show show = CreateShow();
			show.Details();
			show.Play();
		}
		else if (option == 2)
		{
			Movie movie = CreateMovie();
			movie.Details();
			movie.Play();
		}
		else if (option == 3)
		{
			TVShow tvshow = CreateTVShow();
			tvshow.Details();
			tvshow.Play();
		}
		else if (option == 4)
		{
			Show* movie_show = CreateMovie_Show();
			movie_show->Details();
			movie_show->Play();
		}
		else if (option == 5)
		{
			Show* tvshow_show = CreateTVShow_Show();
			tvshow_show->Details();
			tvshow_show->Play();
		}

		string choice;
		cout << endl;
		cout << "Continue (y/n?): ";
		cin >> choice;

		system("cls");
		if (choice == "y") { running = true; }
		else { running = false; }
	}

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
		<< "Press 5 for an instance of TV Show declared as a Show" << endl
		<< "Choice: ";
	cin >> input;
	cout << endl;

	return stoi(input);
}

/*
A.I Used to generate descriptions, episodes, and titles for inputs.

By providing chatGPT with our data structures it created full functions
to intitialize our objects with information
*/
Show CreateShow()
{
	return {
		"Breaking Bad",
		"Breaking Bad is a gripping crime drama about a high school chemistry teacher, Walter White,\n"
		"who turns to cooking meth after being diagnosed with cancer. As he descends into the criminal\n"
		"underworld, he transforms into the ruthless drug kingpin, Heisenberg, leading to deadly consequences.\n"
	};
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

	return {
		"Breaking Bad",
		"Breaking Bad is a gripping crime drama about a high school chemistry teacher, Walter White,\n"
		"who turns to cooking meth after being diagnosed with cancer. As he descends into the criminal\n"
		"underworld, he transforms into the ruthless drug kingpin, Heisenberg, leading to deadly consequences.\n",
		show
	};
}

Movie CreateMovie()
{
	return { "Inception",
		"A mind - bending thriller where a skilled thief enters people's dreams to steal secrets\n"
		"but is tasked with planting an idea instead, blurring the lines between reality and illusion.\n",
		"PG- 13"
	};
}

Show* CreateMovie_Show()
{
	Show* s = new Movie("Interstellar",
		"A group of astronauts travels through a wormhole in search of a new home for humanity,\n"
		"facing the unknown depths of space and time.\n",
		"PG-13"
	);
	return s;
}

Show* CreateTVShow_Show()
{
	vector<vector<Episode>> show;

	// Season 1
	show.push_back({
		{ 1, "A young boy vanishes, leading his friends to encounter a girl with strange powers." },
		{ 2, "The boys hide Eleven while investigating their friend's disappearance." },
		{ 3, "Nancy investigates a friend’s disappearance, while the boys learn more about Eleven." },
		{ 4, "The boys seek help from their teacher as Hopper digs into Hawkins Lab." },
		{ 5, "Nancy and Jonathan form an alliance while Eleven recalls painful memories." },
		{ 6, "Hopper and Joyce uncover truths while the boys experiment with Eleven’s powers." },
		{ 7, "The group prepares for a showdown as danger escalates in Hawkins." },
		{ 8, "The Demogorgon strikes as Eleven and her friends make a final stand." }
		});

	// Season 2
	show.push_back({
		{1, "Will experiences disturbing visions as a new threat looms over Hawkins."},
		{2, "Nancy and Jonathan take action while Eleven learns about her past."},
		{3, "Dustin discovers a mysterious creature as Will’s episodes worsen."},
		{4, "Hopper tries to keep Eleven hidden, but she longs for answers."},
		{5, "Tensions rise as Will’s connection to the Shadow Monster deepens."},
		{6, "Eleven embarks on a journey to find others like her."},
		{7, "As Hawkins falls into chaos, the group fights to save their town."},
		{8, "The Mind Flayer makes its move as the town prepares for battle."},
		{9, "The battle for Hawkins reaches its climax as friends unite against the darkness."}
		});

	Show* s = new TVShow("Stranger Things",
		"A group of kids in a small town uncovers secret government experiments and a parallel dimension\n"
		"while searching for their missing friend.\n",
		show
	);

	return s;
}