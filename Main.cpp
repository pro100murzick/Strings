#include <iostream>

using namespace std;

int countWords(char str[]);
int findShortestWordLenth(char str[]);
void getNumOfVolvesAndNotVolves(char str[]);
bool isVolve(char letters);

int main() {
	//char str[] = "I love C++ programming language!";
	char str[] = "Programming languages develop extremely fast";
	cout << str << endl;
	cout << "There are " << countWords(str) << " words in the string.";
	cout << " The shortest word's lenght =  " << findShortestWordLenth(str) << endl;
	getNumOfVolvesAndNotVolves(str);

	char str1[256];
	cin.getline(str1, 256, ',');
	cout << str1;


	return 0;
}

int countWords(char str[])
{
	int counter = 0;
//	int i = 0;
//	while (str[i] != '\0') {
//		if (str[i] == 32) {
//			counter++;
//		}
//		i++;
//	}

	//for (int i = 0; str[i] != '\0'; i++) {
	//	if (str[i] == ' ')
	//		counter++;
	//}
	//counter++;

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 32 )
			counter++;
	}
	counter++;
	return counter;
}

int findShortestWordLenth(char str[])
{
	int min = 10000;
	for (int i = 0; i <= strlen(str); i++) {
		if (str[i] == ' ' ||  str [i] == '\0') {
			int counter = 0;
			for (int j = i - 1; (j >= 0 && str[j] != ' '); j--) {
				counter++;
			}
			if (counter < min)
				min = counter;
		}
	  }
	return min;
}

void getNumOfVolvesAndNotVolves(char str[])
{
	int volves = 0;
	int notVolves = 0;
	for (int i = 0; i < strlen(str); i++) {
		char letter = toupper(str[i]);
		if (isVolve(letter) == true)
			volves++;
		else if (letter >= 65 && letter <= 90)
			notVolves++;
	}
	cout << "Volves = " << volves << endl;
	cout << "Not volves = " << notVolves << endl;
	if (volves > notVolves) {
		cout << "Num of volves is greater" << endl;
	}
	else {
		cout << "Num of not volve is greater" << endl;
	}
}

bool isVolve(char letter)
{
	if (letter == 'A' || letter == 'O' || letter == 'I' || letter == 'J'
		|| letter == 'E' || letter == 'Y' || letter == 'U')
		return true;
	else 
		return false;
}
