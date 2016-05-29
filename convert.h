#ifndef CONVERT_H
#define CONVERT_H

class convert
{
	private:
		double ctof(double);
		double ctok(double);
		double ctor(double);
		double ftoc(double);
		double ftok(double);
		double ftor(double);
		double ktoc(double);
		double ktof(double);
		double ktor(double);
		double rtoc(double);
		double rtof(double);
		double rtok(double);
		double klmConv();
		double mphConv();
		double toMPH();
	public:
		convert();
		void meters();
		void milklm();
		void energy();
		void temp();
		void presure();
		void windChil();
		void menu();
		void help();
	
		~convert();
};

#endif
