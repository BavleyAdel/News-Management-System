#pragma once
#include "News.h"
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
using namespace std;
class Admin
{
	unordered_map<string, string> admins;
	set<string> categories;
public:
	Admin();
	void login();
	void postNews(vector<News>&);
	void updateNews(vector<News>&);
	void removeNews(vector<News>&);
	int findNewsIndex(vector<News>,string);
	void avgRate(vector<News>);
	void addCategory();
};