#pragma once
#include "News.h"
#include "Admin.h"
#include <vector>
#include <list> 
#include <string>
using namespace std;
class User
{
public:
	string username;
	string password;
	User();
	User(string inputUserName, string inputPassword);
	int findNewsIndex(vector<News>, string);
	void addComment(vector<News>&);
	void rateNews(vector<News>&);
	void spamNews(vector<News>&);
	void displayAllComments(vector<News>);
	void displayNews(vector<News>);
	void displayByDate(vector<News>);
	void displayByCategory(vector<News>,Admin);
	void displayByRate(vector<News>);
	
};

