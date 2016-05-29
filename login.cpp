#include "login.h"
#include "Resor.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

resor Lre;

login::login()
{
	//
}
bool login::input(int &axisTemp, string &name, int lc)
{
	string pass, passcheck, ans, ans2,
	       rpass, getname;
	char cpass[50];
	int pch[10], temp, r, size, INTname, sname; 
	axisTemp = 0;

	ifstream mypas(".MyPass.txt");
	if(!mypas){
		cout << "unable to find login data\n";
		axisTemp = 2;
	}

	if(lc == 1) //viperrc login control
	{
		axisTemp = 5;
		return true;
	}

	// login start
	while(pass != "logout"){

		cout << "Login: ";
		cin >> pass;

		if(pass == "help"|| pass == "Help"|| pass == "HELP")
		{
			help(axisTemp);
			if(axisTemp == 2)
				return true;
		}
		else if(pass == "logout"||pass == "Logout"||pass == "LOGOUT"||
				pass == "exit"||pass == "Exit"||pass == "EXIT")
			return false;
		else{
			////////////////////////////////////////////////////////////////////////

			// pass.erase();
			ifstream mypasch(".MyPass.txt");
			while(! mypasch.eof())
			{	       
				getline(mypasch, passcheck);

				// password isolator //////////////////////////
				size = passcheck.size();
				sname = size - 11;
				decryptNoSpace(passcheck,passcheck);
				if(size < 10|| passcheck == "")
					break;

				// get name
				getname = passcheck;
				name = getname.erase(sname, size);


				size = size - 10;
				// gets password
				passcheck.erase(0, size);
				if(pass == passcheck)
				{

					system("clear");
					mypasch.close();
					mypas.close();
					return true;
				}
				//passcheck.erase();
			}
		}
	}
}
void login::Sleep(unsigned int m){
	clock_t goal = m + clock();
	while(goal > clock());
}
////////////////////////////////////////////////////////////////////////
void login::help(int &t)
{
	char temINCR;
	string pass, passcheck, ans, ans2,
	       rpass, getname, name,
	       prompt1 = "Are you a first time user of the network: ";
	int pch[10], temp, r, size, INTname, sname;

	cout << "Are you a first time user of the network: ";
	cin >> ans;
	if(ans == "y"|| ans == "Y"|| ans == "yes"|| ans == "Yes"|| ans == "YES")
	{
		cout << "Do you want a password issued to you: ";
		cin >> ans2;

		if(ans2 == "y"|| ans2 == "Y"|| ans2 == "yes"|| ans2 == "Yes"|| ans2 == "YES")
		{
			ofstream intopas(".MyPass.txt", ios::app);
			cout << "Your full name: ";
			cin.get();
			getline(cin, name);

			incrypt(name,name); // incrypt your name /////////////////////////////////////////

			cout << "\nYour new password is: ";
			// Password Generator Program ////////////////////////////////////////
			// //////////////////////////////////////////////////////////////////
			srand(time(NULL));
			for(int i=0; i < 10; i++)
				pch[i] = i;

			for(int i=0; i < 10; i++)
			{
				r = (rand() % 9) + 1;
				temp = pch[i];
				pch[i] = pch [r];
				pch[r] = temp;
			}

			intopas << name << "|";

			for(int i=0; i < 10; i++) //////////////INCRYPTER////INCRYPTER////INCRYPTOR///////
			{
				Num_incrypt(pch[i],temINCR);
				intopas << temINCR;
			}
			intopas << endl;
			////////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////
			for(int i=0; i < 10; i++)
				cout << pch[i];
			cout << " make a note of it\n";
			cout << "Please re-enter your password now.\n\n";
			return;
		}
		else
		{
			system("clear");
			cout << "\t\tTemparary Access Given";
			//system("clear");

			t = 2;
			return;
		}
	}
	//////////////////////////////////////////////////////////////////////////////////
	// serch for existing passwords /////////////////////////////////////////////////
	// /////////////////////////////////////////////////////////////////////////////
	else
	{
		cout << "What is your name: ";
		cin.get();
		getline(cin, name);
		incrypt(name,name);

		ifstream mypas(".MyPass.txt");
		while(! mypas.eof())
		{
			getline(mypas, passcheck);

			//decrypt(passcheck,passcheck); // decryption //////////////////////////////////////////

			size = passcheck.size();
			INTname = size - 11;
			if(INTname < 0)
				break;

			rpass = passcheck;
			// serch names //////////////////////////
			passcheck.erase(INTname, size);

			// checks names to file ////////////////
			if(name == passcheck)
			{
				rpass = rpass.erase(0, (INTname + 1));
				decrypt(rpass,rpass);
				decrypt(passcheck,passcheck);

				cout << "\nThe password for " << passcheck << " is " << rpass << endl;
				cout << "Please re-enter your password now\n\n";
				break;	
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////
// incryption ////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////
void login::Num_incrypt(int in, char &out)
{
	if(in == 1)
		out = 'X';
	if(in == 2)
		out = 'Q';
	if(in == 3)
		out = 'W';
	if(in == 4)
		out = 'D';
	if(in == 5)
		out = 'V';
	if(in == 6)
		out = 'N';
	if(in == 7)
		out = 'J';
	if(in == 8)
		out = 'K';
	if(in == 9)
		out = 'S';
	if(in == 0)
		out = 'H';
}
void login::decryptNoSpace(string &in,string &out)
{
	char cypher[37] = {'#','!','@','&','^','%','&','O','}','U','"','>',
		'<','/',',','.','?',':','[','\\','-','_','+','=','A',
		'B','X','Q','W','D','V','N','J','K','S','H','E'},
	     alphab[37] = {'a','b','c','d','e','f','g','h','i','j','k','l',
		     'm','n','o','p','q','r','s','t','u','v','w','x',
		     'y','z','1','2','3','4','5','6','7','8','9','0','_'};

	for(int i=0; i< in.size(); i++)
	{
		for(int u=0; u<37; u++)
		{
			if(in[i] == cypher[u])
				out[i] = alphab[u];
		}
	}
}
void login::incrypt(string in,string &out)
{
	char cypher[37] = {'#','!','@','&','^','%','&','O','}','U','"','>',
		'<','/',',','.','?',':','[','\\','-','_','+','=','A',
		'B','X','Q','W','D','V','N','J','K','S','H','E'},
	     alphab[37] = {'a','b','c','d','e','f','g','h','i','j','k','l',
		     'm','n','o','p','q','r','s','t','u','v','w','x',
		     'y','z','1','2','3','4','5','6','7','8','9','0',' '};
	Lre.univSelec(in,in);

	for(int i=0; i< in.size(); i++)
	{
		for(int u=0; u<37; u++)
		{
			if(in[i] == alphab[u])
				out[i] = cypher[u];
		}
	}
}
void login::decrypt(string &in,string &out)
{	
	char cypher[37] = {'#','!','@','&','^','%','&','O','}','U','"','>',
		'<','/',',','.','?',':','[','\\','-','_','+','=','A',
		'B','X','Q','W','D','V','N','J','K','S','H','E'},
	     alphab[37] = {'a','b','c','d','e','f','g','h','i','j','k','l',
		     'm','n','o','p','q','r','s','t','u','v','w','x',
		     'y','z','1','2','3','4','5','6','7','8','9','0',' '};

	for(int i=0; i< in.size(); i++)
	{
		for(int u=0; u<37; u++)
		{
			if(in[i] == cypher[u])
				out[i] = alphab[u];
		}
	}
}
login::~login()
{
	//
}
