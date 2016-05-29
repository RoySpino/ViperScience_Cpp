#include "Resor.h"
#include "login.h"
#include "convert.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

const double pi = 3.141592653589793238462643383279502884197169399375105820974944;

login lo;
convert Convert;

//=======================================
struct Uhistory
{
	int index;
	//string HIST[500];
	vector<string> HIST;
}hi;
//=======================================

resor::resor()
{
	clearControl =0;
	hi.index = 0;
	//
}
//////////////////////////////////////////////////////////////
void resor::clearCON(int i)
{
	clearControl =i;
}
// ///////////////////////////////////////////////////////////
void resor::histOUT()
{
	his(hi.HIST, hi.index);
}
void resor::his(vector<string> h,int ind)
{
     for(int i =0; i < ind; i ++)
             cout << setw(3)<< (i+1) << " " << h[i] << endl;
             }
/////////////////////////////////////////////////////////////
void resor::rec(string name)
{    
     string fi,write, infile,
            filepromt,prompt, HIDEN=".";
     
     std::string filename; //personal record file

     fi = name;
     cout << "<"<< fi << "> " << "personal records             ~ to exit";
     
     HIDEN.append(fi);
     filename = HIDEN;

     ofstream record(filename.c_str(), ios::app);
     
     if(! record) // check if file is there
     {
          cout << "\n      --- Error No file or directory---\n";
          }
     filepromt = "(Type your notes here)";

     lo.incrypt(filepromt, filepromt);
     record << filepromt << endl;
     
////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

         ifstream read(filename.c_str());
         cout << "\n____________________________________________________________\n"; 
         while(! read.eof())
         {
                 getline(read, write);
                 lo.decrypt(write, write);
                 cout << write << endl;
                 //infile.erase();
                 }
         
         ofstream input(filename.c_str(), ios::app);
         while(true)
         {
                 //infile.erase();
                 getline(cin, write);
                 if(write =="~")
                          break;
                 lo.incrypt(write,write);
                 input << '\t'<< write << endl;
                 }
     }
////////////////////////////////////////////////////////////////
void resor::clear()
{
	if(clearControl == 1)
		system("cls");
	else
     		system("clear");
     }
void resor::univSelec(string raw, string &modif)
{
	for(int i=0; i< raw.size(); i++)
		modif[i] = tolower(raw[i]);
}
////////////////////////////////////////////////////////////
void resor::IN_History(string i)
{
	HISTORY(hi.index, hi.HIST, i);
}
void resor::HISTORY(int &ind ,vector<string> &sh, string input)
{
	sh.push_back(input);
	ind++;
}
////////////////////////////////////////////////////////////
void resor::handl(string &check)
{
	if(check.empty())
	{
		cout << ">>> ";
		cin.get();
		getline(cin,check);
	}
	else
	{ 
		check = check;
	}
}
////////////////////////////////////////////////////////////
void resor::valid_INT(string raw, int &mod)
{
	double cash;
VALstart:

	cash = strtod(raw.data(), NULL);
	mod =(int) cash;	

	if(mod == '\0')  // ///////////// ifno numbers are found
	{
		cout << "\t<please enter a valid INTIGER value>\n>>> ";
		cin >> raw;
		goto VALstart;
	}
}
/////////////////////////////////////////////////////////////
int resor::V_INT(string raw)
{
	int mod;
	double cash;
VALstart:

	cash = strtod(raw.data(), NULL);
	mod =(int) cash;

	if(mod == '\0')  // ///////////// ifno numbers are found
	{
		cout << "\t<please enter a valid INTIGER value>\n>>> ";
		cin >> raw;
		goto VALstart;
	}
	return mod;
}
///////////////////////////////////////////////////////////
double resor::VDO()
{
	string replace;
	double out;
	int setDefalt=0;
	
	cin >> replace;

	for(int i=0; i< replace.size(); i++)
		if((replace[i] < '0' or replace[i] > '9') and replace[i] != '.'and replace[i] != '-')
			if(replace[i] == 'e' and (replace[i+1] == '-' or (replace[i+1] >= '0' and replace[i+1] <= '9')))
				replace[i] = 'e';
			else
				replace[i] = ' ';

	for(int i=0; i< replace.size(); i++){
		if(replace[i] == ' ')
			setDefalt++;
		if(setDefalt == replace.size())
			return 0;
	}
	out = strtod(replace.data(), NULL);

	return out;
}
////////////////////////////////////////////////////////
int resor::VInt()
{
	string replace;
	int out;
	int setDefalt=0;
	
	cin >> replace;

	for(int i=0; i< replace.size(); i++)
		if((replace[i] < '0' or replace[i] > '9') and replace[i] != '.'and replace[i] != '-')
			if(replace[i] == 'e' and (replace[i+1] == '-' or (replace[i+1] >= '0' and replace[i+1] <= '9')))
				replace[i] = 'e';
			else
				replace[i] = ' ';

	for(int i=0; i< replace.size(); i++){
		if(replace[i] == ' ')
			setDefalt++;
		if(setDefalt == replace.size())
			return 0;
	}
	out = int(strtod(replace.data(), NULL));

	return out;
}
////////////////////////////////////////////////////////
void resor::V_DO(string raw, double &out)
{
validate:

	out = strtod(raw.data(), NULL);
	
	if(out == 0)
	{
		cout << "\t<please enter a valid NUMBER value>\n>>> ";
		cin >> raw;
		goto validate;
	}

}
////////////////////////////////////////////////////////////////

double resor::valid_DOU(string raw)
{
	char temp[15];
	double mod;
	int decCount =0;
	string cash;

	for(int i=0, u=0; i<raw.size(); i++){
		if((raw[i] >='0' &&raw[i] <='9')||raw[0] =='-'||raw[i]=='.'){
			if(raw[i] == '.')
				decCount++;
			if(decCount >1)
				continue;
			else{
				temp[u++] = raw[i];
				temp[u] = '\0';
			}
		}
	}
	cash.assign(temp);

	mod = strtod(cash.data(), NULL);

	return mod;
}
///////////////////////////////////////////////////////////////////////
bool resor::VDO_break(string raw, double &mod)
{
	double cash;
 
	mod = strtod(raw.data(), NULL);
	
	if(mod == '\0')
	{
		cout << "\tinvalid expression\n";
		return false;
	}

	return true;
}
///////////////////////////////////////////////////////////////////////
string resor::getChar(string in)
{
	char intoString[50];
	string out;

	// check value: if there is a character it will be overwiten
	intoString[0] = '0';

	for(int i=0, u=0; i< in.size(); i++){
		if((in[i] < '0'|| in[i]> '9') && in[i] !='\0'){
			intoString[u++] = in[i];
			intoString[u+1] = '\0';
		}
	}

	// check if any characters are within the intoString array
	if(intoString[0] == '0')
		return "0";
	else
		out.assign(intoString);

	return out;
}
///////////////////////////////////////////////////////////////////////
void resor::calc()
{
     bool test, test2;
     double ans, num1, num2;
     string mod, n1, n2;

     cin >> n1; 
     test = VDO_break(n1, num1);
     if(test == false)
	     return;
     
     cin >> mod;
     
     if(mod == "tan"||mod == "sin"||mod == "cos"||
        mod == "rtan"||mod == "rsin"||mod == "rcos"||
        mod == "arctan"||mod == "arcsin"||mod == "arccos"||
        mod == "log"||mod == "ln"||mod == "log10"||mod == "e"||
        mod =="sqrt")
      {
             if(mod == "tan")
                    {ans = tan(num1 *(pi/180));}
             else if(mod == "cos")
                    {ans = cos(num1 *(pi/180));}
             else if(mod == "sin")
                    {ans = sin(num1 *(pi/180));}
                    
             else if(mod == "arctan")
                    {ans = atan(num1) *(180/pi);}
             else if(mod == "arccos")
                    {ans = acos(num1) *(180/pi);}
             else if(mod == "arcsin")
                    {ans = asin(num1) *(180/pi);}
                    
             else if(mod == "rtan")
                    {ans = tan(num1);}
             else if(mod == "rcos")
                    {ans = cos(num1);}
             else if(mod == "rsin")
                    {ans = sin(num1);}
                    
             else if(mod == "log")
                    {ans = log(num1 )/ log(10);}
             else if(mod == "ln")
                    {ans = log(num1);}
             else if(mod == "log10")
                    {ans = pow(10,num1);}
             else if(mod == "e")
                    {ans = pow(2.718281828,num1);}
             else if(mod == "sqrt")
                    {ans = sqrt(num1);}
             }
      if(mod == "-"||mod == "+"||mod == "/"||mod == "*")
      {
	     cin >> n2; ////////////////////check for empty strings 
	     test2 = VDO_break(n2, num2);
	     if(test2 == false)
		     return;

             if(mod == "+")
                    {ans = num1 + num2;}
             else if(mod == "-")
                  {ans = num1 - num2;}
             else if(mod == "*")
                  {ans = num1 * num2;}
	     else if(mod == "/")
                  {ans = num1 / num2;}
             else
                 return;
             }
          
     cout << "\n" << ans << endl;
     }
//==============================================================================
string resor::cd()
{
	return home;
}
string resor::cd(string changeDirectory)
{
	cin >> changeDirectory;

	IN_History(changeDirectory);
     	univSelec(changeDirectory,changeDirectory); // Universal Selector
     
     	if(changeDirectory == "chem")
     	{
            	changeDirectory = "Chem";
            	return changeDirectory ;
        }
     	if(changeDirectory == "math")
     	{
            	changeDirectory = "Math";
            	return changeDirectory ;
        }
     	if(changeDirectory == "elect")
     	{
            	changeDirectory = "Elect";
            	return changeDirectory ;
     	}
     	if(changeDirectory == "conv")
     	{
            	changeDirectory = "Conv";
            	return changeDirectory ;
     	}
     	if(changeDirectory == "phys")
     	{
            	changeDirectory = "Phys";
            	return changeDirectory ;
     	}
     	if(changeDirectory == "astro")
     	{
            	changeDirectory = "Astro";
            	return changeDirectory ;
     	}
     	if(changeDirectory == "econ")
     	{
            	changeDirectory = "Econ";
            	return changeDirectory ;
     	}
     	if(changeDirectory  == "help")
     	{
          	cout << "________________________________________________________\n"
                     << setw(15) << "astro" << setw(40) << "Change to Astronomy directory\n"
                     << setw(15) << "econ"  << setw(40) << "Change to Economics directory\n"
                     << setw(15) << "elect" << setw(40) << "Change to Electronics directory\n"
                     << setw(15) << "chem"  << setw(40) << "Change to Chemestry directory\n"
                     << setw(15) << "conv"  << setw(40) << "Change to Conversion directory\n"
                     << setw(15) << "math"  << setw(40) << "Change to Math directory\n"
                     << setw(15) << "phys" << setw(40) << "Change to Physics directory\n";
     	}
	return home;
}
string resor::mod(string changeDirectory)
{
	int ind;
	IN_History(changeDirectory);
     	univSelec(changeDirectory,changeDirectory); // Universal Selector
     
     	if(changeDirectory == "chem")
     	{
            	changeDirectory = "Chem";
            	return changeDirectory;
        }
     	if(changeDirectory == "math")
     	{
            	changeDirectory = "Math";
            	return changeDirectory;
        }
     	if(changeDirectory == "elect")
     	{
            	changeDirectory = "Elect";
            	return changeDirectory;
     	}
     	if(changeDirectory == "conv")
     	{
            	changeDirectory = "Conv";
            	return changeDirectory;
     	}
     	if(changeDirectory == "phys")
     	{
            	changeDirectory = "Phys";
            	return changeDirectory;
     	}
     	if(changeDirectory == "astro")
     	{
            	changeDirectory = "Astro";
            	return changeDirectory;
     	}
     	else if( changeDirectory == "help")
     	{
          	cout << "________________________________________________________\n"
                     << setw(15) << "astro" << setw(40) << "Change to Astronomy directory\n"
                     << setw(15) << "elect" << setw(40) << "Change to Electronics directory\n"
                     << setw(15) << "chem" << setw(40) << "Change to Chemestry directory\n"
                     << setw(15) << "conv" << setw(40) << "Change to Conversion directory\n"
                     << setw(15) << "math" << setw(40) << "Change to Math directory\n"
                     << setw(15) << "phys" << setw(40) << "Change to Physics directory\n";
     	}
}
//============================================
void resor::sortString(string *in, int lim)
{
	for(int i=0; i<lim; i++)
		for(int u=i+1; u<lim; u++)
			if(in[u] < in[i])
				swap(in[i],in[u]);
}
//============================================
void resor::sortVector(vector<double> &in, int lim){
	for(int i=0; i<lim; i++)
		for(int u =0; u<lim; u++)
			if(in[u] < in[i])
				swap(in[i],in[u]);
}
/////////////////////////////////////////////////
void resor::convertMenu(){
	Convert.menu(); 
}
/////////////////////////////////////////////////
void resor::setNoSpace(string in, string &out){
	string cp="";

	for(int i=0; i<in.size(); i++)
		if(in[i] != ' ')
			cp.push_back(in[i]);
	out = cp;
	return ;
}
int resor::redFrac(double in){
	for(int d=1; d<512; d++)
		for(int n=0; n<d; n++){
			if(round((n*1.0)/(d*1.0)) == round(in))
				return d;
		}
	return 1;
}
double resor::round(double in){
	char *str;
	sprintf((str =new char), "%.4g", in);
	return strtod(str,NULL);
}
resor::~resor()
{
	//
}
