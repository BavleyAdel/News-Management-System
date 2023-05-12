#include "User.h"
#include "News.h"
#include "Admin.h"
#include <iterator>
#include <iostream>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

int News::newsCount = 0;


User::User()
{
	username = "";
	password = "";
}
User::User(string inputUserName, string inputPassword)
{
	username = inputUserName;
	password = inputPassword;
}

int User::findNewsIndex(vector<News> news, string title) {
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

void User::addComment(vector<News>& news)
{
    char c;
    do 
    {
        cout << "Enter News title to add comment: " << endl;
        string title;
        getline(cin >> ws, title);
        int i = findNewsIndex(news, title);
        if (i == -1) {
            cout << "Not exist";
        }
        else 
        {    
            Comment comment;
            cout << "\nEnter Your Comment\n";
            getline(cin >> ws, comment.commentContent);
            comment.username = username;
            news.at(i).comments.push_back(comment);
        }
        system("cls");
        cout << "Add another Comment (y/n)? " << endl;
        cin >> c;
    } while (c == 'Y' || c == 'y');
}

void User::displayAllComments(vector<News> news)
{
    char c;
    do
    {
        cout << "Enter News title to display its comments: " << endl;
        string title;
        getline(cin >> ws, title);
        int i = findNewsIndex(news, title);
        if (i == -1) {
            cout << "Not exist";
        }
        else
        {
            auto it = news.at(i).comments.begin();
            for (; it != news.at(i).comments.end(); it++)
            {
                cout << it->username << endl;
                cout << it->commentContent << endl << endl;
                cout << "-----------------------------------------------------------" << endl;
            }
        }
        system("cls");
        cout << "Add another Comment (y/n)? " << endl;
        cin >> c;
    } while (c == 'Y' || c == 'y');
}

void User::displayByDate(vector<News> allNews)
{
    //system("cls");
    for (int i = 0; i < allNews.size(); i++)
    {
        for (int j = i; j < allNews.size(); j++)
        {
            if (allNews.at(i).date.year < allNews.at(j).date.year)
                swap(allNews.at(i), allNews.at(j));
            else if (allNews.at(i).date.year == allNews.at(j).date.year && allNews.at(i).date.month < allNews.at(j).date.month)
                swap(allNews.at(i), allNews.at(j));
            else if (allNews.at(i).date.year == allNews.at(j).date.year && allNews.at(i).date.month == allNews.at(j).date.month && allNews.at(i).date.day < allNews.at(j).date.day)
                swap(allNews.at(i), allNews.at(j));
        }
    }
    for (int i = 0; i < allNews.size(); i++)
    {
        if (allNews.at(i).spamUsernames.size() == 0 && (allNews.at(i).rate == 0 || allNews.at(i).rate > 2 ))
        {
            cout << allNews.at(i).title << endl;
            cout << allNews.at(i).description << endl;
            cout << "Number of spam reports: " << allNews.at(i).spamCount << endl;
        }
        else
        {
            for (int j = 0; j < allNews.at(i).spamUsernames.size(); j++)
            {
                if ((allNews.at(i).rate > 2 || allNews.at(i).rate == 0) && allNews.at(i).spamUsernames.at(j) != username)
                {
                    cout << allNews.at(i).title << endl;
                    cout << allNews.at(i).description << endl;
                    cout << "Number of spam reports: " << allNews.at(i).spamCount<<endl;
                    cout << "-----------------------------------------------------------" << endl;
                }
                /*else 
                {
                    cout << "Spamed news" << endl;
                }*/
            }
        }

    }
}

void User::rateNews(vector<News>& news) {
    char c;
    do
    {
        cout << "Enter News title to be rated: " << endl;
        string title;
        getline(cin >> ws, title);
        int i = findNewsIndex(news, title);
        if (i == -1) {
            cout << "Not exist";
        }
        else {
            cout << "Enter rate (1-5): " << endl;
            cin >> news.at(i).rate;
            if (news.at(i).rate < 1)
                news.at(i).rate = 1;
            else if (news.at(i).rate > 5)
                news.at(i).rate = 5;
            cout << "you have successfully rated this news." << endl;
        }
        system("cls");
        cout << "Do you want to Continue (y/n)? " << endl;
        cin >> c;

    } while (c == 'y' || c == 'Y');
}


void User::displayByRate(vector<News> allNews)
{
    for (int i = 0; i < allNews.size(); i++)
    {
        for (int j = i; j < allNews.size(); j++)
        {
            if (allNews.at(i).rate < allNews.at(j).rate)
                swap(allNews.at(i), allNews.at(j));
        }
    }
    for (int i = 0; i < allNews.size(); i++)
    {
        if (allNews.at(i).spamUsernames.size() == 0 && allNews.at(i).rate > 2)
        {
            cout << allNews.at(i).title << endl;
            cout << allNews.at(i).description << endl;
            cout << "Number of spam reports: " << allNews.at(i).spamCount << endl;
        }
        else
        {
            for (int j = 0; j < allNews.at(i).spamUsernames.size(); j++)
            {
                if (allNews.at(i).rate > 2 && allNews.at(i).spamUsernames.at(j) != username)
                {
                    cout << allNews.at(i).title << endl;
                    cout << allNews.at(i).description << endl;
                    cout << "Number of spam reports: " << allNews.at(i).spamCount << endl;
                    cout << "-----------------------------------------------------------" << endl;
                }
            }
        }
    }
}

void User::spamNews(vector<News>& news)
{
    cout << "Enter News title to be reported as spam: " << endl;
    string title;
    getline(cin >> ws, title);
    int i = findNewsIndex(news, title);
    if (i == -1) {
        cout << "Not exist";
    }
    else {
        news.at(i).spamCount++;
        news.at(i).spamUsernames.push_back(username);
        cout << "you have successfully reported this news as spam." << endl;

    }
}