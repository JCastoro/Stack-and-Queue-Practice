

#include <iostream>
#include <fstream>
#include <iostream>
#include <list>
#include <stack>

using namespace std;

//bool symbolBalanceCheck(ifstream& inFile);
bool symbolBalanceCheckString(ifstream& inFile);



int main()
{
	ifstream file;
	file.open("test.txt");

	if (symbolBalanceCheckString(file)) {
		cout << "symbols are balanced";
	}
	else {
		cout << "symbols are not balanced";
	}

	/*if (symbolBalanceCheck(file)) {
		cout << "all good here dude";
	}
	else {
		cout << "symbols are not balanced";
	}*/

	file.close();
}


//bool symbolBalanceCheck(ifstream& inFile) {
//	//read in the first word and make sure its "begin"
//	string firstWord;
//	inFile >> firstWord;
//
//	if (firstWord != "begin") {
//		return false;
//	}
//	else {
//
//
//		//have a stack that reads in every character of the file, if its {} () [] it will add it to the stack
//		stack<char> charStack;
//
//		char currChar;
//		while (inFile >> currChar) {
//			if (currChar == '{' ||
//				currChar == '(' ||
//				currChar == '[') {
//
//				charStack.push(currChar);
//			}
//			else {}
//
//			if (currChar == '}') {
//				//char tempCurr = currChar;
//
//				if (charStack.top() == '{') {
//					charStack.pop();
//				}
//				else {
//					return false;
//				}
//
//			}
//			else {}
//			if (currChar == ')') {
//				//char tempCurr = currChar;
//
//				if (charStack.top() == '(') {
//					charStack.pop();
//				}
//				else {
//					cout << "here";
//					return false;
//				}
//
//			}
//			else {}
//
//			if (currChar == ']') {
//				//char tempCurr = currChar;
//
//				if (charStack.top() == '[') {
//					charStack.pop();
//				}
//				else {
//					return false;
//				}
//
//			}
//			else {}
//
//		}
//
//		//move the file reading pointer back 3 characters and make sure last word is "end"
//		inFile.seekg(-5);
//		cout << "here";
//		string lastWord;
//		inFile >> lastWord;
//		cout << lastWord;
//		if (lastWord != "end")
//			return false;
//
//		if (charStack.empty())
//			return true;
//
//		else
//			return false;
//	}
//	}

bool symbolBalanceCheckString(ifstream& inFile) {
	//read in the first word and make sure its "begin"
	string currWord;

	//have a stack that reads in every character of the file, if its {} () [] it will add it to the stack
	stack<char> charStack;
	bool endOfWord=false;

	while (endOfWord == false || inFile >> currWord ) {//need to handle case where word has ((  text  ))
		endOfWord = true;
		if (currWord.find("begin") != string::npos)
			charStack.push('*');

		if (currWord.find("(") != string::npos) {
			charStack.push('(');
			endOfWord = false;
			currWord=currWord.substr(currWord.find("(") + 1, currWord.length());//starts the word from the next char
		}

		else if (currWord.find("{") != string::npos) {
			charStack.push('{');
			endOfWord = false;
			currWord = currWord.substr(currWord.find("{") + 1, currWord.length());//starts the word from the next char
		}
		else if (currWord.find("[") != string::npos) {
			charStack.push('[');
			endOfWord = false;
			currWord = currWord.substr(currWord.find("[") + 1, currWord.length());//starts the word from the next char
		}
		



		//checking for closed

		else if (currWord.find(")") != string::npos) {
			//char tempCurr = currChar;

			if (charStack.top() == '(') {
				charStack.pop();
				endOfWord = false;
				currWord = currWord.substr(currWord.find(")") + 1, currWord.length());//starts the word from the next char
			}
			else
				return false;

		}
		else if (currWord.find("}") != string::npos) {
			if (charStack.top() == '{') {
				charStack.pop();
				endOfWord = false;
				currWord = currWord.substr(currWord.find("}") + 1, currWord.length());//starts the word from the next char
			}
			else
				return false;

		}
		else if (currWord.find("]") != string::npos) {
			if (charStack.top() == '[') {
				charStack.pop();
				endOfWord = false;
				currWord = currWord.substr(currWord.find("]") + 1, currWord.length());//starts the word from the next char
			}
			else
				return false;

		}
		else {
			endOfWord = true;
		}


		if (currWord.find("end") != string::npos) {
			if (charStack.top() == '*') {
				charStack.pop();
				endOfWord = true;//might not need
			}
			else
				return false;

		}
	}

	
	if (charStack.empty())
		return true;
	else
		return false;

}
