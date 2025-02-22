#include <iostream>
#include <stdio.h>
#include <cstring>
#include <fstream>
#include <string>
#include "hangmangraphics.h"
#include <vector>
//#include <sqlite3.h>
//class for interfacing with database
//constructor creates database if it dosen't already exist
//main has initial program logic to write words to database,
//if selected class object is created and method for writing to database is created
//                   *under construction*
/*
class sqlclass{
	public:
		sqlite3* db;
		char* errMsg;
		int rc;
		sqlclass(){
			errMsg = nullptr;
			rc = sqlite3_open("hangmanWords.db", &db);
			if(rc) {
				cerr << "Error opening hangmanWords.db\n";
			}
				const char* createTableSQL = R"(
					CREATE TABLE IF NOT EXISTS words (
					id INTEGER PRIMARY KEY AUTOINCREMENT,
					name TEXT NOT NULL,
					last INTEGER
				);
			);
		}

};
*/
class vWclass{
	public:
		bool win;
		vector<char> guessword;
		vector<char> finalword;
		vector<char> temparray;
		char activeGuess;
		int wlen;

		vWclass(){
			guessword = {'a', 'm', 'o', 'e', 'b', 'a'};
			finalword = {'_', '_', '_', '_', '_', '_'};
			wlen = guessword.size();
			win = false;
			}
		void temping(string linput){
			temparray = vector<char>(linput.begin(), linput.end()); 
			activeGuess = temparray[0];
			guess(temparray);
		}

		void guess(vector<char> temparray){
			if(temparray == guessword){
				win = true;
			} else {
				 for(int i = 0; i < wlen; i++){
        			        if(guessword[i] == activeGuess){
						finalword[i] = activeGuess;
					}
				}
				if(finalword == guessword){
					win = true;
				}
			}
	}
};


int main(){
	vWclass vW;
	std::cout << "Welcome to Hangman, the word length is: " << vW.wlen << "\n";
	std::cout << "You have " << (vW.wlen * 2) << " guesses, good luck! ;3\n";
	for(int i = 0; i < (vW.wlen * 2); i++){
		std::string input;
		std::cout << "guess: ";
		getline(cin, input);
		vW.temping(input);
		std::string output(vW.finalword.begin(), vW.finalword.end());
		std::cout << output << "\n";
		if(vW.win == true){
			break;
		} else {
//get graphics from file
			int x = (vW.wlen * 2) - i - 1;
			draw(i);
			if(x > 0){
				std::cout << "he has " << x << " tries left\n";
			}else if(x == 0){
				std::cout << "he dieded 3:\n";
			}
		}
	}
	if(vW.win == true){
		std::cout << "Good Job! You won!\n";
		#if defined(_WIN32)
		system("PAUSE");
		return 0;
		#else
			return 0;
		#endif
	} else {
		std::cout << "Better Luck next time\n" << "The word was: ";
		for(int i =0; i < vW.wlen; i++){
			std::cout << vW.guessword[i];
		}
		std::cout << "\n";
		#if defined(_WIN32)
			system("PAUSE");
			return 0;
		#else
			return 0;
		#endif
	}
}





