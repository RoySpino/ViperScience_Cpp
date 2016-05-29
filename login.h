#ifndef LOGIN_H
#define LOGIN_H
#include <string>

using namespace std;

class login
{
	private:
		void Sleep(unsigned int);
	public:
		login();
		bool input(int &axisTemp, string &name, int);
		void help(int &t);
                void incrypt(string in, string &out);
	        void decrypt(string &in, string &out);	
		void decryptNoSpace(string &in, string &out);
		void Num_incrypt(int in, char &out);

		void forgoten();
		void NewUser();
		~login();
	
};
#endif
