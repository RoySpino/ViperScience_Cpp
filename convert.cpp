#include "convert.h"
#include "Resor.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

resor rconvert;

convert::convert()
{
}
double convert::ctof(double n){
	return (n * 1.8) + 32.0;
}
double convert::ctok(double n){
	return n +273;
}
double convert::ctor(double n){
	return (n + 273.0) * (9/5.0);
}
double convert::ftoc(double n){
	return ((n- 32)* 5.0) / 9.0;
}
double convert::ftok(double n){
	return ftoc(n) + 273;
}
double convert::ftor(double n){
	return n + 459.67;
}
double convert::ktoc(double n){
	return n-273;
}
double convert::ktof(double n){
	return ktoc(n) *1.8 + 32;
}
double convert::ktor(double n){
	return n * (9/5,0);
}
double convert::rtoc(double n){
	return (n - 491.76) * (9.0/5,0);
}
double convert::rtof(double n){
	return n - 491.67;
}
double convert::rtok(double n){
	return n * (5,0/9,0);
}
double convert::toMPH(){
	double speed;
	string input;
	getline(cin, input);

	if(input[0] =='\0' or (input[0] <'0' or input[0]>'9') or input.size() <1)
		getline(cin, input);

	rconvert.univSelec(input, input);
	rconvert.setNoSpace(input, input);

	if(input.find("kph") < input.size() and input.find("mph") > 0){
		speed = rconvert.valid_DOU(input);
		return speed *  0.621371;
	}
	if(input.find("km/h") < input.size() and input.find("km/h") > 0){
		speed = rconvert.valid_DOU(input);
		return speed *  0.621371;
	}
	if(input.find("m/s") < input.size() and input.find("m/s") > 0){
		speed = rconvert.valid_DOU(input);
		return speed * 2.23694; 
	}
	if(input.find("ft/s") < input.size() and input.find("m/s") > 0){
		speed = rconvert.valid_DOU(input);
		return speed *0.681818; 
	}
	cout << "<<ATENTION: No unit or unrecognized symbol given.>>\n"
	     << "<<        : unit is in __MILES PER HOUR__        >>";
	return rconvert.valid_DOU(input);
}
double convert::mphConv(){
	double speed;
	string input;
	getline(cin, input);

	if(input[0] =='\0' or (input[0] <'0' or input[0]>'9') or input.size() <1)
		getline(cin, input);

	rconvert.univSelec(input, input);
	rconvert.setNoSpace(input, input);

	if(input.find("kph") < input.size() and input.find("mph") > 0){
		speed = rconvert.valid_DOU(input);
		return speed *  1.60934;
	}
	if(input.find("m/s") < input.size() and input.find("m/s") > 0){
		speed = rconvert.valid_DOU(input);
		return speed *0.44703; 
	}
	if(input.find("ft/s") < input.size() and input.find("m/s") > 0){
		speed = rconvert.valid_DOU(input);
		return speed /3600; 
	}
	cout << "<<ATENTION: No unit or unrecognized symbol given.>>\n"
	     << "<<        : unit is in __MILES PER HOUR__        >>";
	return rconvert.valid_DOU(input);
}
double convert::klmConv(){
	double speed;
	string input;
	getline(cin, input);

	if(input[0] =='\0' or (input[0] <'0' or input[0]>'9') or input.size() <1)
		getline(cin, input);

	rconvert.univSelec(input, input);
	rconvert.setNoSpace(input, input);

	if(input.find("mph") < input.size() and input.find("mph") > 0){
		speed = rconvert.valid_DOU(input);
		return 0.621371192*speed;
	}
	if(input.find("m/s") < input.size() and input.find("m/s") > 0){
		speed = rconvert.valid_DOU(input);
		return speed/(3600); 
	}
	if(input.find("ft/s") < input.size() and input.find("m/s") > 0){
		speed = rconvert.valid_DOU(input);
		return 0.084666667*speed; 
	}
	cout << "<<ATENTION: No unit or unrecognized symbol given.>>\n"
	     << "<<        : unit is in __KILOMETERS PER HOUR__   >>";
	return rconvert.valid_DOU(input);
}
void convert::menu(){
	string input;

	while(true){
		cout << "\nViper_Conversion: ";
		cin >> input;
		
		rconvert.IN_History(input);
		rconvert.univSelec(input, input);

		if(input == "energy")
			energy();
		if(input == "meters")
			meters();
		if(input == "milkl")
			milklm();
		if(input == "presure")
			presure();
		if(input == "temp")
			temp();
		if(input == "help")
			help();
		if(input == "cd")
			break;
		if(input == "calc")
			rconvert.calc();
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void convert::help()
{
			cout << "________________________________________________________\n" 
			     << setw(15) << "energy" << setw(40) << "Convert jules and calories\n"
			     << setw(15) << "meters"<< setw(40) << "Convert metters to feet\n"
			     << setw(15) << "milkl" << setw(40) << "Convert miles to kilometers\n"
			     << setw(15) << "presure" << setw(40) << "Convert presure units\n"
			     << setw(15) << "temp" << setw(40) << "Convert temprature units (k,c,f,r)\n"
                  	     << setw(15) << "calc" << setw(40) << "simple calculater\n"
			     << setw(15) << "clear" << setw(40) << "Clear screen\n"
			     << setw(15) << "cd"<< setw(40) << "Return to parant directory\n";
}
//////////////////////////////////////////////////////////////////////////////////////////////
void convert::meters()
{
     string sel;
     double ft, m;
     while(true){
           cout << "\nViper_Conversion_Meter: ";
           cin >> sel;
	 rconvert.IN_History(sel);
	 rconvert.univSelec(sel,sel);

           
           if(sel == "mtof")
           {
                  cout << "\n    Enter the number of meters: ";
                  m = rconvert.VDO();
                  
                  ft = m / 0.3048;
                  cout << " ________________________________\n"
                       << "|     Feet " << ft << endl << endl;
                  }
           if(sel == "ftom")
           {
                  cout << "\n    Enter the number of feet: ";
                  ft = rconvert.VDO();
                  
                  m = ft / 3.281;
                  cout << " ________________________________\n"
                       << "|     Meters " << m << endl << endl;
                  }
           if(sel == "mtoin")
           {
                  cout << "\n    Enter the number of Meters: ";
                  m = rconvert.VDO();
                  
                  ft = m / 39.37;
                  cout << " ________________________________\n"
                       << "|     inches " << ft << endl<< endl;
                  }
           if(sel == "help"||sel == "Help"||sel == "HELP"||sel == "ls"||sel == "LS")
           {
             cout << "________________________________________________________\n" 
                  << setw(15) << "mtof"<< setw(40) << "Convert metters to feet\n"
                  << setw(15) << "ftom" << setw(40) << "Convert feet to metters\n"
                  << setw(15) << "mtoin" << setw(40) << "Convert metters to inches\n"
                  << setw(15) << "calc" << setw(40) << "simple calculater\n"
                  << setw(15) << "clear" << setw(40) << "Clear screen\n"
                  << setw(15) << "cd"<< setw(40) << "Exit program\n";
                  }
           if(sel =="cd"||sel =="CD")
                 break;
	   if(sel == "calc")
		 rconvert.calc();

           if(sel =="clear"||sel =="Clear"||sel =="CLEAR")
                 rconvert.clear();// cout << string(50,'\n');
           }
     }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void convert::milklm()
{
     string sel;
     double m, k;
     while (true){
           cout << "\nViper_Converersion_Distance: ";
           cin >> sel;
	 rconvert.IN_History(sel);
	 rconvert.univSelec(sel,sel);

           
           if(sel == "ktom"||sel == "KtoM"||sel == "KTOM")
           {
                  cout << "\n    Enter kilometer distance: ";
                  k = rconvert.VDO();
                  
                  m = k *  0.621371192;
                  cout << "the mile distance is: " << m << endl;
                  }
           if(sel == "mtok"||sel == "MtoK"||sel == "MTOK")
           {
                  cout << "\n    Enter mile distance: ";
                  m = rconvert.VDO();
                  
                  k = m * 1.609344;
                  cout << "the kilometer distance is: " << m << endl;
                  }
           if(sel == "help"||sel == "Help"||sel == "HELP"||sel == "ls"||sel == "LS")
           {
             cout << "________________________________________________________\n" 
                  << setw(15) << "ktom"<< setw(40) << "Convert metters to feet\n"
                  << setw(15) << "mtok" << setw(40) << "Convert feet to metters\n"
                  << setw(15) << "calc" << setw(40) << "simple calculater\n"
                  << setw(15) << "clear" << setw(40) << "Clear screen\n"
                  << setw(15) << "cd"<< setw(40) << "Exit program\n";
                  }
           if(sel =="cd"||sel =="CD")
                 break;
	   if(sel == "calc")
		 rconvert.calc();

           if(sel =="clear"||sel =="Clear"||sel =="CLEAR")
                 rconvert.clear();// cout << string(50,'\n');
           }
     }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void convert::energy()
{
     string sel;
     double m, k;
     while (true){
           cout << "\nViper_Conversion_Energy: ";
           cin >> sel;
	 rconvert.IN_History(sel);
	 rconvert.univSelec(sel,sel);

           
     if(sel == "ctoj"||sel == "CToJ"||sel == "CTOJ")
     {
            cout << "    Enter total calories: ";
            k = rconvert.VDO();
            
            m = k * 4.186;
            cout << "total number of juels is " << m <<endl;
            }
     if(sel == "jtoc"||sel == "JToC"||sel == "JTOC")
     {
            cout << "    Enter total joules: ";
            k = rconvert.VDO();
            
            m = k / 4.186;
            cout << "total number of calories is " << m <<endl;
            }
     if(sel == "help"||sel == "Help"||sel == "HELP"||sel == "ls"||sel == "LS")
           {
             cout << "________________________________________________________\n" 
                  << setw(15) << "ctoj"<< setw(40) << "Convert calories to joules\n"
                  << setw(15) << "jtoc" << setw(40) << "Convert joules to calories\n"
                  << setw(15) << "calc" << setw(40) << "simple calculater\n"
                  << setw(15) << "clear" << setw(40) << "Clear screen\n"
                  << setw(15) << "cd"<< setw(40) << "Exit program\n";
                  }
           if(sel =="cd"||sel =="CD")
                 break;
	   if(sel == "calc")
		 rconvert.calc();

           if(sel =="clear"||sel =="Clear"||sel =="CLEAR")
                 rconvert.clear();// cout << string(50,'\n');
           }
     }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void convert::temp()
{
     double k, c, f, r;
     string eleSymb[20], sel;
     
     while (true){
     cout << "\nViper_Conversion_Temp: ";
     cin >> sel;
	 rconvert.IN_History(sel);
	 rconvert.univSelec(sel,sel);

     
     if(sel == "far"||sel == "Far"||sel == "FAR")
     {
            cout << "\n    Enter Fahrenheit degree: ";
            f = rconvert.VDO();

            c = ((f - 32) * 5) / 9;
            k = c + 273;
	    r = f + 459.67;
            
	    cout << " kelvin     " << k << endl
                 << " Fahrenheit " << f << endl
                 << " Celsius    " << c << endl
                 << " Rankine    " << r << endl;
            }
     if(sel == "cel"||sel == "Cel"||sel == "CEL")
     {
            cout << "\n    Enter Celsius degree: ";
            c = rconvert.VDO();

            f = (c * 1.8) + 32;
            k = c + 273;
	    r = (c + 273.15) * (9/5);

            cout << " kelvin     " << k << endl
                 << " Fahrenheit " << f << endl
                 << " Celsius    " << c << endl
                 << " Rankine    " << r << endl;
                 }
     if(sel == "kel"||sel == "Kel"||sel == "KEL")
     {
            cout << "\n    Enter Kelvin degree: ";
            k = rconvert.VDO();

            c = k - 273;
            f = (c * 1.8) + 32;
	    r = k * (9/5);

            cout << " kelvin     " << k << endl
                 << " Fahrenheit " << f << endl
                 << " Celsius    " << c << endl
                 << " Rankine    " << r << endl;
            }
     if(sel == "rankine")
     {
	     cout << "\n    Enter Rankine degree: ";
	     r = rconvert.VDO();

	     c = (r - 491.76) * (5/9);
	     f = r - 491.67;
	     k = r * (5/9);
            
	     cout << " kelvin     " << k << endl
                  << " Fahrenheit " << f << endl
                  << " Celsius    " << c << endl
                  << " Rankine    " << r << endl;
     }
     if(sel == "help"||sel == "Help"||sel == "HELP"||sel == "ls"||sel == "LS")
           {
             cout << "________________________________________________________\n" 
                  << setw(15) << "cel"<< setw(40) << "Convert Fahrenheit to C and K\n"
                  << setw(15) << "far" << setw(40) << "Convert Celsius to F and K\n"
                  << setw(15) << "kel" << setw(40) << "Convert Kelvin to C and F\n"
                  << setw(15) << "calc" << setw(40) << "simple calculater\n"
                  << setw(15) << "clear" << setw(40) << "Clear screen\n"
                  << setw(15) << "cd"<< setw(40) << "Exit program\n";
                  }
           if(sel =="cd"||sel =="CD")
                 break;
	   if(sel == "calc")
		 rconvert.calc();

           if(sel =="clear"||sel =="Clear"||sel =="CLEAR")
                 rconvert.clear();// cout << string(50,'\n');
           }
     }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void convert::presure()
{
     double k, c, f, an, atm, torr;
     string sel, ans;
     while (true){
             cout << "\nViper_Chem_Pressure-Converter: ";
             cin >> sel;
	 rconvert.IN_History(sel);
	 rconvert.univSelec(sel,sel);

                   
           if(sel == "sea")
           {
                  cout << "    Is the fluid exposed in the air: ";
                  cin >> ans;

                  if(ans == "yes"||ans == "Yes"||ans == "YES")
                  {
                         cout << "    Enter atmospheric temp in pascals: ";
                         c = rconvert.VDO();
                         }
                  cout << "    Enter debth of water:              ";
                  k = rconvert.VDO();
                  cout << "    Enter gravity acceleration:        ";
                  f = rconvert.VDO();
                  
                  an = c + (k * f * 1000);
                  atm = an / 101325;
                  torr = atm * 760;
                  cout << "the presure at " << k << " is " << an << endl
                       << " ____________________________________________________\n"
                       << "|  atm          " << atm << " atm"<< endl
                       << "|  torr         " << torr << " torr"<< endl
                       << "|  mmHg         " << torr << " mmHg" << endl; 
                  }
           if(sel == "help"||sel == "Help"||sel == "HELP"||sel == "ls"||sel == "LS")
           {
             cout << "________________________________________________________\n"
                  << setw(15) << "sea" << setw(40) << "find and convert pressures at sea debths\n"
                  << setw(15) << "clear" << setw(40) << "Clear screen\n"
                  << setw(15) << "calc" << setw(40) << "simple calculater\n"
                  << setw(15) << "cd"<< setw(40) << "Exit program\n";
                  }
           if(sel =="cd"||sel =="CD")
                 break;
	   if(sel == "calc")
		 rconvert.calc();

           if(sel =="clear"||sel =="Clear"||sel =="CLEAR")
                 rconvert.clear();// cout << string(50,'\n');
           }
     }
void convert::windChil(){
     double k, c, f, r, mph, klm, ans;
     string sel;
     while (true){
             cout << "\nViper_Convert_WindCill: ";
             cin >> sel;
	 rconvert.IN_History(sel);
	 rconvert.univSelec(sel,sel);

                   
           if(sel == "oldc"){
		   cout << "    Enter the Celceus temprature: ";
		   c = rconvert.VDO();
		   cout << "    Enter the wind speed mph: ";
		   mph = toMPH();

		   f = ctof(c);

		   ans =  0.08 * (3.71 * sqrt(mph) + 581 - 0.25 *mph) * (f - 91.4) + 91.4;
		   cout << "new ambeant temprature is: " << ans << "C\n";
	   }
	   if(sel == "newc"){
		   cout << "    Enter the Celceus temprature: ";
		   c = rconvert.VDO();
		   cout << "    Enter the wind speed mph: ";
		   mph = toMPH();

		   f = ctof(c);

		   ans = 35.74 + 0.6215*f -35.75 * pow(mph, 0.16) + 0.4275* f * pow(mph, 0.16);
		   cout << "new ambeant temprature is: " << ans << "C\n";
	   }
	   if(sel == "oldf"){
		   cout << "    Enter the Celceus temprature: ";
		   f = rconvert.VDO();
		   cout << "    Enter the wind speed mph: ";
		   mph = toMPH();


		   ans =  0.08 * (3.71 * sqrt(mph) + 581 - 0.25 *mph) * (f - 91.4) + 91.4;
		   cout << "new ambeant temprature is: " << ans << "C\n";
	   }
	   if(sel == "newf"){
		   cout << "    Enter the Celceus temprature: ";
		   c = rconvert.VDO();
		   cout << "    Enter the wind speed mph: ";
		   mph = toMPH();

		   f = ctof(c);

		   ans = 35.74 + 0.6215*f -35.75 * pow(mph, 0.16) + 0.4275* f * pow(mph, 0.16);
		   cout << "new ambeant temprature is: " << ans << "C\n";
	   }
	   if(sel == "oldk"){
		   cout << "    Enter the kelvin temprature: ";
		   k = rconvert.VDO();
		   cout << "    Enter the wind speed (include units): ";
		   mph = toMPH();

		   f = ktof(k);

		   //ans = 35.74 + 0.6215*f -35.75 * pow(mph, 0.16) + 0.4275* f * pow(mph, 0.16);
		   ans =  0.08 * (3.71 * sqrt(mph) + 581 - 0.25 *mph) * (f - 91.4) + 91.4;
		   cout << "new ambeant temprature is: " << ans << "C\n";
	   }
	   if(sel == "newk"){
		   cout << "    Enter the kelvin temprature: ";
		   k = rconvert.VDO();
		   cout << "    Enter the wind speed mph: ";
		   mph = toMPH();

		   f = ktof(k);

		   ans = 35.74 + 0.6215*f -35.75 * pow(mph, 0.16) + 0.4275* f * pow(mph, 0.16);
		   cout << "new ambeant temprature is: " << ans << "C\n";
	   }
	   if(sel == "oldr"){
		   cout << "    Enter the kelvin temprature: ";
		   r = rconvert.VDO();
		   cout << "    Enter the wind speed mph: ";
		   mph = toMPH();

		   f = rtof(k);

		   ans =  0.08 * (3.71 * sqrt(mph) + 581 - 0.25 *mph) * (f - 91.4) + 91.4;
		   cout << "new ambeant temprature is: " << ans << "C\n";
	   }
	   if(sel == "newr"){
		   cout << "    Enter the kelvin temprature: ";
		   r = rconvert.VDO();
		   cout << "    Enter the wind speed mph: ";
		   mph = toMPH();

		   f = rtof(k);

		   ans = 35.74 + 0.6215*f -35.75 * pow(mph, 0.16) + 0.4275* f * pow(mph, 0.16);
		   cout << "new ambeant temprature is: " << ans << "C\n";
	   }
           if(sel == "help"||sel == "Help"||sel == "HELP"||sel == "ls"||sel == "LS"){
             cout << "________________________________________________________\n"
                  << setw(15) << "newC" << setw(40) << "Find C wind chill with new index\n"
                  << setw(15) << "oldC" << setw(40) << "Find C widn chill with old index\n"
                  << setw(15) << "newF" << setw(40) << "Find F wind chill with new index\n"
                  << setw(15) << "oldF" << setw(40) << "Find F widn chill with old index\n"
                  << setw(15) << "newK" << setw(40) << "Find K wind chill with new index\n"
                  << setw(15) << "oldK" << setw(40) << "Find K widn chill with old index\n"
                  << setw(15) << "newR" << setw(40) << "Find R wind chill with new index\n"
                  << setw(15) << "oldR" << setw(40) << "Find R widn chill with old index\n"
                  << setw(15) << "clear" << setw(40) << "Clear screen\n"
                  << setw(15) << "calc" << setw(40) << "simple calculater\n"
                  << setw(15) << "cd"<< setw(40) << "Exit program\n";
                  }
           if(sel =="cd"||sel =="CD")
                 break;
	   if(sel == "calc")
		 rconvert.calc();

           if(sel =="clear"||sel =="Clear"||sel =="CLEAR")
                 rconvert.clear();// cout << string(50,'\n');
           }

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
convert::~convert(){
}
