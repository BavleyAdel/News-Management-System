#pragma once
#include <vector>
#include <list>
#include <iostream>
using namespace std;
struct Date {
	int day, month, year;
};
struct Comment {
	string username, commentContent;
};
class News
{
public:
	News();
	static int newsCount;
	string title;
	string description;
	string category;
	Date date;
	list<Comment> comments;
	int rate;
	int spamCount;
	int numOfRatedUsers;
	vector<string> spamUsernames;
};