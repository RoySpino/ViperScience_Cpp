// Class automatically generated by Dev-C++ New Class wizard

#ifndef CHEM_H
#define CHEM_H
#include <string>

using namespace std;

/*
 * No description
 */
class chem
{
	private:

	public:
		// class constructor
		chem();
		void boyllaw();
		void charlaw();
		void elecplat();
		void ph();
		void milklm();
		void idelgas();
		void titrate();
		void precEntry();
		void stoichiometry();
		void solutions();
		void eqlprsur();
		void frzpoint();
		void bondEnrgy();
		void oxidationState();
		void balance();
		void hgl();

		void convert(string sel,string lab);
		void temp();
		void meters();
		void energy();
		void presure();
		double atmPas(double);
		double atmBar(double);
		double atmPsi(double);
		double pasAtm(double);
		double pasBar(double);
		double pasPsi(double);
		double psiAtm(double);
		double psiBar(double);
		double psiPas(double);
		double barAtm(double);
		double barPsi(double);
		double barPas(double);

		double farCel(double);
		double farKel(double);
		double farRac(double);
		double celFar(double);
		double celKel(double);
		double celRac(double);
		double kelCel(double);
		double kelFar(double);
		double kelRac(double);
		double racCel(double);
		double racKel(double);
		double racFar(double);

		void calc();
		void help();
		void clear();
		bool knownIonExcluder(string);
		double check(string);
		double do_MOL_mas(string);  // get moler mass
		double do_ELE_count(string);// count elemts in a formula
		double do_SYM_count(string);// count the simbols in the formula
		double *do_ELE_weigh(string);// calculate weight of each element group
		string *do_BREAK_formula(string,int); // reaturn the symboles in the formula
		// splits formulas that are in parentesies
		string splitForm(string in, double &mult);
		bool soluble(string, int&);

		// class destructor
		~chem();
};

#endif // CHEM_H