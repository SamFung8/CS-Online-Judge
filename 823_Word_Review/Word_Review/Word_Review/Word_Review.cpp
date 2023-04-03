#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	
    int testWord = 0, essayWord = 0;

    while (cin >> testWord) {
        unordered_map<int, string> mapWordLocation;
        vector<int> wordLocation;
        vector<string> wordName;
        unordered_map<string, int> mapWordCount;

        for (int i = 0; i < testWord; i++) {
            string tem;
            cin >> tem;
            mapWordCount[tem] = 0;
        }

        int count = 0;
        cin >> essayWord;
        for (int i = 0; i < essayWord; i++) {
            string tem;
            cin >> tem;
            if (mapWordCount.find(tem) != mapWordCount.end()) {
                if (mapWordCount[tem] == 0) {
                    count++;
                }
                mapWordCount[tem]++;
                mapWordLocation[i + 1] = tem;
                wordLocation.push_back(i + 1);
                wordName.push_back(tem);
            }
        }




        int totalCount = 0, totalLength = 0;
        if (count == 0)
            totalCount = 0;
        else if (count == 1)
            totalCount = 1;
        else {
            int start = wordLocation[0], end = 0, currentLength = 0, currentCount = 0;
            unordered_map<string, int> mapWord;
            bool del = false;
            int delLength = 0;

            for (int i = 0; i < wordName.size(); i++) {

                if (!(mapWord.find(wordName[i]) != mapWord.end()) || mapWord[wordName[i]] == 0) {
                    currentCount++;
                    mapWord[wordName[i]] = 1;
                    if (currentCount == count) {
                        end = wordLocation[i];
                        currentLength = end - start + 1;
                        if ((currentLength <= totalLength || totalLength == 0) && (currentCount == count)) {
                            totalLength = currentLength;
                            totalCount = currentCount;
                        }
                        del = true;
                    }
                }
                else {
                    mapWord[wordName[i]]++;
                }

                while (del) {
                    mapWord[wordName[delLength]]--;
                    if (mapWord[wordName[delLength]] == 0) {
                        del = false;
                        currentCount--;
                        delLength++;
                        break;
                    }
                    else {
                        delLength++;
                        start = wordLocation[delLength];
                        end = wordLocation[i];
                        currentLength = end - start + 1;
                        if ((currentLength <= totalLength || totalLength == 0) && (currentCount == count)) {
                            totalLength = currentLength;
                            totalCount = currentCount;
                        }
                    }
                }
            }
        }


        cout << count;
        cout << "\n";
        cout << totalLength;
        cout << "\n";



    }

    return 0;
}