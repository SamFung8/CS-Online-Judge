#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include<set>
#include <vector>
using namespace std;

void print(const std::string& item)
{
	std::cout << item << std::endl;
}
int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	
	vector<string> book;
	string line;

	while (getline(cin, line))
	{
		transform(line.begin(), line.end(), line.begin(), ::tolower);
		for (int i = 0; i < line.length(); i++) {
			if (!isalpha(line[i])) {
				line[i] = ' ';
			}

		}
		istringstream ss(line);
		string word;
		while (ss >> word) {
			book.push_back(word);

		}
	}

	sort(book.begin(), book.end());

	string repeatWord = "";
	for (int i = 0; i < book.size(); i++) {
		if (repeatWord != book[i]) {
			repeatWord = book[i];
			cout << book[i];
			cout << "\n";
		}
	}
}
