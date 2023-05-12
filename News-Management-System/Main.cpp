#include "News.h"
#include "Admin.h"
#include "User.h"
#include <vector>
#include <iostream>
using namespace std;



int main() {

	vector<News> news;
	Admin a;
	a.postNews(news);
	User u1("hazem","123"), u2("bavly","1234");
	u1.addComment(news);
	u1.spamNews(news);
	u1.displayByDate(news);
	u2.displayByDate(news);

	return 0;
}