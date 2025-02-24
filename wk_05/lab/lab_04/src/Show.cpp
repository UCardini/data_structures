#include "Show.h"


Show::Show()
{
	Title = "";
	Description = "";
}


Show::Show(string title, string description)
{
	Title = title;
	Description = description;
}


void Show::setTitle(string title)
{
	Title = title;
}


void Show::setDescription(string description)
{
	Description = description;
}


string Show::getTitle()
{
	return Title;
}


string Show::getDescription()
{
	return Description;
}


void Show::Play()
{
	cout << "Playing: " << Title << endl;
}


void Show::Details()
{
	cout << "Title: " << Title << endl;
	cout << "Description:" << endl << Description << endl;
}