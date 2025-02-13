#pragma once
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;


class Show
{
protected:
	string Title;
	string Description;

public:
	Show();
	Show(string, string);

	void setTitle(string);
	void setDescription(string);

	string getTitle();
	string getDescription();

	virtual void Play() = 0;
	void Details();
};
