#include<iostream>
#include "Checker.h"
#include <unistd.h>
using namespace std;
int main(){
	Checker newGame;
	int choice;
	char YesOrNo;
	
	cout<<"---------------------------------------------------Hangman Game------------------------------------------------------"<<endl;
	cout<<"Select from following "<<endl;
	cout<<"1.Group Details"<<endl;
	cout<<"2.CPU vs Player"<<endl;
	cout<<"3.Player vs Player"<<endl;
	cout<<"4.Admin Panel"<<endl;
	cout<<"5.Instruction"<<endl;
	cout<<"6.Exit"<<endl;
	cin>>choice;
	switch(choice){
		case(1):{
			cout<<"--------------------------------------------------MY GROUP DETAILS--------------------------------------------------"<<endl;
			cout<<"\t\t\t\tNAME : NAME"<<endl;
			cout<<"\t\t\t\tROLL NUMBER : ROLL"<<endl;
			cout<<"\t\t\t\tDEGREE : DEGREE"<<endl;
			cout<<"\t\t\t\tSUBJECT : SUBJECT"<<endl;
			cout<<"\t\t\t\tPROJECT : GAME"<<endl;
			cout<<endl<<endl;
			cout<<"Do you want to go back ( Type Y or N )? ";
			cin>>YesOrNo;
			if(YesOrNo == 'Y' || YesOrNo == 'y'){
				system ("CLS");
				main();
			}
			else{
				cout<<"We hope you Enjoyed the game ....";
				sleep(3);
				exit(0);
			}		
			break;
		}
		case(2):{
			newGame.ComputerVsPlayerGame();
			cout<<"Do you want to go back ( Type Y or N )? ";
			cin>>YesOrNo;
			if(YesOrNo == 'Y' || YesOrNo == 'y'){
				system ("CLS");
				main();
			}
			else{
				cout<<"We hope you Enjoyed the game ....";
				sleep(3);
				exit(0);
			}		
			break;
		}
		case(3):{
			newGame.PlayerVsPlayerGame();
			cout<<"Do you want to go back ( Type Y or N )? ";
			cin>>YesOrNo;
			if(YesOrNo == 'Y' || YesOrNo == 'y'){
				system ("CLS");
				main();
			}
			else{
				cout<<"We hope you Enjoyed the game ....";
				sleep(3);
				exit(0);
			}
			break;
		}
		case(4):{
			Hangman admin;
			admin.EnterNewWordInComputerVSPlayer();
			cout<<"Do you want to go back ( Type Y or N )? ";
			cin>>YesOrNo;
			if(YesOrNo == 'Y' || YesOrNo == 'y'){
				system ("CLS");
				main();
			}
			else{
				cout<<"We hope you Enjoyed the game ....";
				sleep(3);
				exit(0);
			}
			break;
		}
		case(5):{
			int choice;
			char back;
			cout<<"Select from following : "<<endl;
			cout<<"1.PLAYER VS CPU"<<endl;
			cout<<"2.PLAYER VS PLAYER"<<endl;
			cin>>choice;
			switch(choice){
				case(1):{
					cout<<"1.Random word will be selected from File."<<endl;
					cout<<"2.User will guess one alphabet at a time."<<endl;
					cout<<"3.User has 5 tries"<<endl;
					cout<<"4.On each failed guess man part will appear and if man is drawn completely user looses"<<endl;
					cout<<endl<<endl;
					cout<<"Do you wanna go back ? (Y or N)";
					cin>>back;
					if(back == 'Y' || back == 'y'){
						cout<<"Going Back....";
						sleep(3);
						system("CLS");
						main();
					}
					else{
						exit(0);
					}
					break;
				}
				case(2):{
					cout<<"1.First User will store his word."<<endl;
					cout<<"2.Second User will guess one alphabet at a time."<<endl;
					cout<<"3.User has 5 tries"<<endl;
					cout<<"4.On each failed guess man part will appear and if man is drawn completely user looses"<<endl;
					cout<<endl<<endl;
					cout<<"Do you wanna go back ? (Y or N)";
					cin>>back;
					if(back == 'Y' || back == 'y'){
						cout<<"Going Back....";
						sleep(3);
						system("CLS");
						main();
					}
					else{
						exit(0);
					}
					break;
				}
			}
			break;
		}
		case(6):{
			cout<<"We Hope You Enjoyed This Game\n\n";
			sleep(3);
			exit(0);
			break;
		}
		default:{
			cout<<"Under Construction"<<endl;
			break;
		}
	}
	return 0;
}

