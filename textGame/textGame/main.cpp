//
//  main.cpp
//  textGame
//
//  Created by Luciano Picozzi on 07/11/14.
//  Copyright (c) 2014 Luciano Picozzi. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
	string prize; //store the prize that you can win
	int number; //store the number you have in mind
	int answer; //store the answer of participant

	//rules of the game
	cout << "Welcome to numberguess!" << endl << endl << "Try to guess the number under 10 and you may win a awesome prize!"  << endl <<  "======================================================"<< endl << endl <<"** The gamemaster will nou enter a secret number and prize **" << endl << endl << endl << endl << "Enter the secret number: ";
	
	cin >> number; //decide the secret number
	cout << "Enter the prize: ";
	cin >> prize; //decide the prize
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl <<endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl; //some spaces so the 'guesser' cant see the secret number ;)
	
	cout << "Guess the secret number and you may win some " << prize << "." << endl << endl << "your guess: ";//sentence for the second player to read.
    cin >> answer; //get answer

	
	
    if(answer == number)
        {cout << endl << "You've earned your " << prize << " my friend! The answer was " << answer << endl;}
    else
        {cout << endl << "No "<< prize <<" for you.... It was " << number << endl << endl;}//win or loose is decided here

	
	return 0;//the fun must end here
}
