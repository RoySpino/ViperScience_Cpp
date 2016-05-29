// Class automatically generated by Dev-C++ New Class wizard

#ifndef RESOR_H
#define RESOR_H
#include "convert.h"
#include <string>
#include <vector>

using namespace std;
/*
 * No description
 */
class resor
{
	private:
		string home;
		int clearControl;
	public:
		// class constructor
		resor();
		void clear();
		void rec(string name);
		void his(vector<string> h,int ind);
		void calc();
		void univSelec(string,string &modif);
		void IN_History(string);
		void HISTORY(int &ind,vector<string> &sh,string);
		void histOUT();
		void sortDouble(double*, double*, int);
		void sortInt(int*, int*, int);
		void sortString(string*, int);
		void sortVector(vector<double>&in, int lim);
		void setNoSpace(string, string&);

		// change directory overloading
		string cd();
		string cd(string);
		string mod(string);
		string getChar(string);
		
		void valid_INT(string, int &mod);
		void handl(string &check); 
		void V_DO(string raw, double &out);
		void convertMenu();
		double VDO();
		int VInt();
		int redFrac(double);
		double round(double);
		bool VDO_break(string,double &mod);

		int V_INT(string);
		double valid_DOU(string raw);
		void clearCON(int);
		
		// mutatorFunction
		void getHome(string ho)
		{
			home = ho;
		}
		// class destructor
		~resor();
};

#endif // RESOR_H