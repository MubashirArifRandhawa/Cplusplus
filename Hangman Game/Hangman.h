#include<fstream>
#include <cstdlib> 
#include <ctime> 
#include<iostream>
#include<string.h>
#define NUM 100
using namespace std;
class Hangman{
	char guess_word[NUM];
	string name;
	int password;
	int count;
	
	public:
		char selected_word[NUM];
		Hangman(){
			strcpy(guess_word,"House");	
			count = 0;
			name = "Admin";
			password = 0000;
		}
		Hangman(char _guess_word[100]){
			strcpy(guess_word,_guess_word);
		}
		void getData(){
		cin.get();
		cout<<"Enter the word : ";
		cin.getline(guess_word,99);
		saveWord(guess_word);	
		}
		void EnterNewWordInComputerVSPlayer(){
			string _name="";
			int _pass = 0;
			int choice;
			cout<<"\t\t\tVERIFICATION\t\t\t\n\n";
			cout<<"Enter the Username : ";
			cin>>_name;
			cout<<"Enter Password : ";
			cin>>_pass;
			if( name == _name && password == _pass){
				cout<<"\t\t\tWELCOME BACK\t\t\t\n";
				cout<<"Please Select From Below.\n";
				cout<<"1.See All Words Saved In File\n";
				cout<<"2.Enter New Word\n";
				cin>>choice;
				switch(choice){
					case(1):{
						readAllRecords();		
						break;
					}
					case(2):{
						getData();
						break;
					}
					default:{
						cout<<"Invalid selection...";
						break;
					}
				}
			}
			else{
				cout<<"Username or Password Is Invalid.";
				cout<<endl;
			}
		}
		void saveWordToGuess(){
			cout<<"Enter the word that you want your friend to guess : ";
			cin.get(selected_word,100);
			cin.get();
		}
		void showData(){
			cout<<guess_word<<endl;
		}
		void setWord(){
			strcpy(selected_word,guess_word);
		}
		void saveWord(char guess_word[100]);
		void readAllRecords();
		void set_random_word(int count);
		void countAllWordSaved();
		
		~Hangman(){
			strcpy(guess_word,"null");	
			count = 0;
		}
};
	void Hangman::saveWord(char guess_word[100]){
		ofstream fout;
		fout.open("file1.txt",ios::app | ios::binary);
		fout.write((char*)this,sizeof(*this));
		fout.close();
		cout<<"Word has been saved "<<endl;
	}	
	void Hangman::readAllRecords(){
		ifstream fin;
		
		fin.open("file1.txt",ios::in|ios::binary);
		if(!fin){
			cout<<"\nFile Not Found...\n"<<endl;
		}
		else{
			int count = 0;
			fin.read((char*)this,sizeof(*this));
			while(!fin.eof()){
				showData();
				count++;	
				fin.read((char*)this,sizeof(*this));
			}
			fin.close();
		}
	}
	void Hangman::countAllWordSaved(){
			ifstream fin;
		fin.open("file1.txt",ios::in|ios::binary);
		if(!fin){
			cout<<"\nFile Not Found...\n"<<endl;
		}
		else{
			int count = 0;
			fin.read((char*)this,sizeof(*this));
			while(!fin.eof()){
				count++;	
				fin.read((char*)this,sizeof(*this));
			}
			set_random_word(count);
			fin.close();
		}
	}
	void Hangman::set_random_word(int count){
		unsigned seed = time(0);
   	    srand(seed);
		int num = (rand() % count );
		int counts = 0;
		ifstream fin;
		fin.open("file1.txt",ios::in|ios::binary);
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof()){
			if(counts == num){	
				setWord();
				break;	
			}
			else{
				counts++;
				fin.read((char*)this,sizeof(*this));
				continue;
			}
		}
		fin.close();
	}
