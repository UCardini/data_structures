#pragma once
#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::ifstream;
using std::getline;
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

	virtual void Play();
	void Details();
};
