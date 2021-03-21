#include <iostream>
#include "Hangman.h"
class Checker{
	Hangman a,temp_string;
	int tries,flag;
	bool returnValue;
	int returnStatus;
	char guessAlphabet,lower,upper;
public:
	Checker(){
		tries = 0;
		flag = 0;
		returnValue = false;
		returnStatus = 0;
		guessAlphabet = '-';
		lower = '-';
		upper = '-';	
	}
	void ComputerVsPlayerGame(){
	a.countAllWordSaved();	
	int i = 0;
	strcpy(temp_string.selected_word,a.selected_word);
	while(i < strlen(temp_string.selected_word)){
		temp_string.selected_word[i] = '-';
		i++;
	}
    cout<<"The word is : "<<temp_string.selected_word<<endl;
    while(tries < 5){
    	convertToUpperCase(a.selected_word);
    	convertToUpperCase(temp_string.selected_word);
    	if(strcmp(a.selected_word,temp_string.selected_word) == 0){
    		cout<<"\n\nCongratulations......You Guessed the word right...."<<endl;
    		cout<<"You Guessed : "<<temp_string.selected_word<<endl;
    		cout<<"Word : "<<a.selected_word<<endl;
    		break;
		}
    	else
			{
    		flag = 0;

			cout<<"Enter the guess : ";
    		cin>>guessAlphabet;
    		if (guessAlphabet==toupper(guessAlphabet))
			{
    			upper = guessAlphabet;
    			lower = guessAlphabet + 32;
			}
			else if(guessAlphabet==tolower(guessAlphabet))
			{
				lower = guessAlphabet;
    			upper = guessAlphabet - 32;
			}
    		for(int i = 0; i < strlen(a.selected_word) ; i++){
				if(a.selected_word[i] == lower || a.selected_word[i] == upper )
				{
    				temp_string.selected_word[i] = guessAlphabet;
    				flag = 1;
				}
				else
				{
					continue;
				}
			}	
			if(flag == 1){
				cout<<"Nice!!!!"<<endl;
				cout<<"Correct Guess : "<<temp_string.selected_word<<endl;
				continue;
			}
			else{
				cout<<"OOPS :( Guess Word Is Wrong...."<<endl;
				tries++;
				cout<<"Tries Left : "<<5 - tries<<endl;
				cout<<"\n\n\n";
				shapes(tries);
				cout<<endl<<endl;
				if(tries == 5){
					cout<<"You Lost.....The Word was : "<<a.selected_word<<endl;
				}
			}
		}
	}
}
void PlayerVsPlayerGame(){	
	cin.get();
	a.saveWordToGuess();	
	int i = 0;
	strcpy(temp_string.selected_word,a.selected_word);
	while(i < strlen(temp_string.selected_word)){
		temp_string.selected_word[i] = '-';
		i++;
	}
    cout<<"The word is : "<<temp_string.selected_word<<endl;
    while(tries < 5){
    	convertToUpperCase(a.selected_word);
    	convertToUpperCase(temp_string.selected_word);
    	if(strcmp(a.selected_word,temp_string.selected_word) == 0){
    		cout<<"\n\nCongratulations......You Guessed the word right...."<<endl;
    		cout<<"You Guessed : "<<temp_string.selected_word<<endl;
    		cout<<"Word : "<<a.selected_word<<endl;
    		break;
		}
    	else
			{
    		flag = 0;
			cout<<"Enter the guess : ";
    		cin>>guessAlphabet;
    		if (guessAlphabet==toupper(guessAlphabet))
			{
    			upper = guessAlphabet;
    			lower = guessAlphabet + 32;
			}
			else if(guessAlphabet==tolower(guessAlphabet))
			{
				lower = guessAlphabet;
    			upper = guessAlphabet - 32;
			}
			for(int i = 0; i < strlen(a.selected_word) ; i++){
				if(a.selected_word[i] == lower || a.selected_word[i] == upper)
				{
    				temp_string.selected_word[i] = guessAlphabet;
    				flag = 1;
				}
				else
				{
					continue;
				}
			}	
			if(flag == 1){
				cout<<"Nice!!!!"<<endl;
				cout<<"Correct Guess : "<<temp_string.selected_word<<endl;
				continue;
			}
			else{
				cout<<"OOPS :( Guess Word Is Wrong..."<<endl;
				tries++;
				cout<<"Tries Left : "<<5 - tries<<endl;
				cout<<"\n\n\n";
				shapes(tries);
				cout<<endl<<endl;
				if(tries == 5){
					cout<<"You Lost.....The Word was : "<<a.selected_word<<endl;
				}
			}
		}
	}
}
void convertToUpperCase(char s[100]){
	for(int i=0;i<=strlen(s);i++) { 
      /* Here we are performing a check so that only lowercase 
       * characters gets converted into uppercase. 
       * ASCII value of a to z(lowercase chars) ranges from 97 to 122 
       */ 
      if(s[i]>=97 && s[i]<=122)
      {
		s[i]=s[i]-32;
      }
      else{
      	continue;
	  }
   	}
}
void shapes(int tries){
	if(tries == 1){
		cout<<"\t\t0 \t\t"<<endl;
		cout<<"\t\t| \t\t"<<endl;
		cout<<"\t\t| \t\t"<<endl;
	}
	else if(tries == 2){
		cout<<"\t\t  0 \t\t"<<endl;
		cout<<"\t 	 /| \t\t"<<endl;
		cout<<"\t\t  | \t\t"<<endl;
	}
	else if(tries == 3){
		cout<<"\t\t  0 \t\t"<<endl;
		cout<<"\t 	 /|\\ \t\t"<<endl;
		cout<<"\t\t  | \t\t"<<endl;
	}
	else if(tries == 4){
		cout<<"\t\t  0 \t\t"<<endl;
		cout<<"\t 	 /|\\ \t\t"<<endl;
		cout<<"\t\t  | \t\t"<<endl;
		cout<<"\t\t / \t\t"<<endl;
	}
	else if(tries == 5){
		cout<<"\t\t  0 \t\t"<<endl;
		cout<<"\t 	 /|\\ \t\t"<<endl;
		cout<<"\t\t  | \t\t"<<endl;
		cout<<"\t\t / \\\t\t"<<endl;
	}
  }
};
