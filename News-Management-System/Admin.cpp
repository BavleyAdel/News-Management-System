#include "Admin.h"
#include "News.h"
#include "vector"
#include <string>
#include <iostream>
using namespace std;

Admin::Admin() {}

void Admin::login() {
	string username, password;
	cout << "Enter Username: " << endl;
	cin >> username;
	//if(username)
	cout << "Enter Password: " << endl;
	cin >> password;
}


void Admin::postNews(vector<News>& news) {
	char c;
	do {
		News n;
		cout << "Enter news title" << endl;
		getline(cin >>ws, n.title);
		cout << "Enter news description" << endl;
		getline(cin >>ws, n.description);
		cout << "Enter news category" << endl;
		getline(cin >>ws, n.category);
		cout << "Enter news date (day)" << endl;
		cin >> n.date.day;
		cout << "Enter news date (month)" << endl;
		cin >> n.date.month;
		cout << "Enter news date (year)" << endl;
		cin >> n.date.year;
		//cout << "You have successfully entered one news no. " << n.newsCount << endl;
		news.push_back(n);
		system("cls");
		cout << "Post another one (y/n)?" << endl;
		cin >> c;
	} while (c == 'y' || c == 'Y');
}

int Admin::findNewsIndex(vector<News> news, string title) {
	auto it = news.begin();
	int index = 0;
	while (it != news.end())
	{
		if (it->title == title) {
			return index;
		}
		else {
			index++;
			it++;
		}
	}
	return -1;
}

void Admin::updateNews(vector<News> &news) {
	 cout << "Enter News title to be updated: " << endl;
	 string title;
	 getline(cin >> ws, title); 
	 int i = findNewsIndex(news, title);
	 if (i == -1) {
		 cout << "Not exist.";
	 }
	 else {
		 cout << "Enter the field you would like to change: " << endl;
		 cout << "1- title." << endl
			 << "2- description." << endl
			 << "3- category." << endl
			 << "4- date." << endl;
		 int choice;
		 cin >> choice;
		 switch (choice)

		 {
		 case 1:
			 cout << "Enter news new title: " << endl;
			 getline(cin >> ws, news.at(i).title);
			 break;
		 case 2:
			 cout << "Enter news new description: " << endl;
			 getline(cin >> ws, news.at(i).description);
			 break;
		 case 3:
			 cout << "Enter news new category: " << endl;
			 getline(cin >> ws, news.at(i).category);
			 break;
		 case 4:
			 cout << "Enter news new date: " << endl;
			 cout << "Day: " << endl;
			 cin >> news.at(i).date.day;
			 cout << "Month: " << endl;
			 cin >> news.at(i).date.month;
			 cout << "Year: " << endl;
			 cin >> news.at(i).date.year;
			 break;
		 }
	 }
}

void Admin::removeNews(vector<News>& news) {
	cout << "Enter News title to be removed: " << endl;
	string title;
	getline(cin >> ws, title);
	int i = findNewsIndex(news, title);
	if (i == -1) {
		cout << "Not exist";
	}
	else {
		news.erase(news.begin() + i);
	}
}



void Admin::addCategory() {
	char c;
	do
	{
		cout << "Enter new Category: " << endl;
		string cat;
		getline(cin >> ws, cat);
		categories.insert(cat);
		cout << "you successfully added " << *categories.end() << endl;
		cout << "Do you want to add another category (y/n)? " << endl;
		cin >> c;
	} while (c == 'Y' || c == 'y');
}


void Admin::avgRate(vector<News>news) {
	cout << "Enter News title to show its average rate: " << endl;
	string title;
	getline(cin >> ws, title);
	int i = findNewsIndex(news, title);
	if (i == -1) {
		cout << "Not exist";
	}
	else {
		cout << "average rate: " << news.at(i).rate;
	}
}

