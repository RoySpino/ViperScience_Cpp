#include "astro.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cmath>
#include <string>
#include "Resor.h"

using namespace std;
double const pi = 3.141592653589793238462643383279502884197169399375105820974944;

resor rq;

Astro::Astro()
{
}
void Astro::rocket()
{
	string sel, speed, unit;
	double F, mdot, ve, pe, po, ae,
	       totalTemp, pt, mach, velocity,
	       ans, t, m, heatCapRatio;
	while(true)
	{
		cout << "\nViper_Astronomy_Rocket: ";
		rq.IN_History(sel);
		rq.univSelec(sel,sel);

		if(sel == "gasflo")
		{
			cout << "    Enter the temprature(k) of the gas:      ";
			cin >> t;
			cout << "    Enter the molecular mass of the gas:     ";
			cin >> m;
			cout << "    Enter the ratio of specific heats:       ";
			cin >> heatCapRatio;
			cout << "    Enter the pressure of the exaust gass:   ";
			cin >> pe;
			cout << "    Enter the presure outside of the rocket: ";

			ae = 1 - pow((pe/po),((heatCapRatio-1)/heatCapRatio));
			ans = sqrt(((t * 8.3144621)/m) * ((2 * heatCapRatio)/ (heatCapRatio -1)) * ae);

			cout << "Exit velocity of the gas is: " << ans << endl;;
		}
		if(sel == "mach")
		{
			cout << "    Enter the speed of the object (include units): ";
			cin >> speed;
			unit = rq.getChar(speed);
			if(unit == "m/s")
				ans = velocity / 340.29;
			if(unit == "ft/s")
				ans = velocity / 1126;
			if(unit == "km/h"|| unit == "kmh")
				ans = velocity / 1236;
			if(unit == "mil/h"||unit == "mph")
				ans = velocity / 768;
			else{
				ans = velocity / 340.29;
				unit = "m/s";
			}

			cout << "The object is travaling at mach: " << velocity << unit<< endl; 
		}
		if(sel == "masflow")
		{
			cout << "";

			//mdot = ((ae * pt)/sqrt(totalTemp)) * sqrt(specHeat / 8.3144621) * mach
		}
		if(sel == "specimp")
		{
			cout << "    Enter  precure surounding the rocket:        ";
			po = rq.VDO();
			cout << "    Enter the precure produced by the rocket:    ";
			pe = rq.VDO();
			cout << "    Enter the exost exit velocity of the rocket: ";
			ve = rq.VDO();
			cout << "    Enter the area of the rocket engein:         ";
			ae = rq.VDO();
			cout << "    Enter the mass flwo rate of the rocket:      ";
			mdot = rq.VDO();


			F = (mdot * ve) + (pe - po) * ae;
			cout << "Total thrust from rocket is: " << F << endl;
		}
		if(sel == "escpspd"){
			cout << "    Enter the mass of the planet/object: ";
			po = rq.VDO();
			cout << "    Enter the mass of the rocket: ";
			ve = rq.VDO();

			ve = sqrt((2* pow(6.67, -11.0)* po)/ (ve));
			cout << "escape velocity is: " << ve << " m/s\n";
		}
		if(sel == "planfesc"){
			cout << "    Enter the mass of the rocket: ";
			po = rq.VDO();
			cout << "    Enter the escape velocity of the rocket: ";
			ve = rq.VDO();

			ve = (pow(ve, 2.0) * po) / (2 * pow(6.67, -11.0));
			cout << "the mass of the planet/object is: " << ve << "kg\n";
		}
		if(sel == "rockmas"){
			cout << "    Enter the mass of the planet/object: ";
			po = rq.VDO();
			cout << "    Enter the escape velocity: ";
			ve = rq.VDO();

			ve = 1 / (pow(ve, 2.0) / (2*pow(6.67,-11.0)*po) );
			cout << "the mass of the rocket is: " << ve << "kg\n";
		}
		if(sel == "help" || sel == "ls")
		{
			cout << "________________________________________________________\n"
			     << setw(15) << "gasflow" << setw(40) << "Calculate Mach number\n"
			     << setw(15) << "escpspd" << setw(40) << "Calculate escape speed\n"
			     << setw(15) << "mach" << setw(40) << "Calculate Mach number\n"
			     << setw(15) << "masflow" << setw(40) << "Mass flow rate of a rocket\n"
			     << setw(15) << "planfesc" << setw(40) << "find mass of object from escape speed\n"
			     << setw(15) << "sqecimp" << setw(40) << "Specific impuls of a rocket\n"
			     
			     << setw(15) << "calc" << setw(40) << "simple calculater\n"
			     << setw(15) << "clear" << setw(40) << "Clear screen\n"
			     << setw(15) << "cd"<< setw(40) << "Exit program\n";
		}
        	if(sel == "clear"||sel == "Clear"||sel == "CCLEAR")
        		rq.clear();  
        	if(sel == "calc"||sel == "Calc"||sel == "CALC")
        		rq.calc();
        	if(sel == "cd"||sel == "CD")
        		break;
	}
}
void Astro::doppler()
{
	double Dshift, waveLength,
	       velocity;
	string sel;
	
	while(true)
	{
		cout << "\nViper_Astronomy_Doppler: ";
		cin >> sel;
		rq.IN_History(sel);
		rq.univSelec(sel,sel);


		if(sel == "speed")
		{
			cout << "    Enter the amount of light shift: ";
			Dshift = rq.VDO();
			cout << "    Enter the wavelenght of the spectra: ";
			waveLength = rq.VDO();

			velocity = (Dshift / waveLength) * 299800000;
			cout << "the object is moving at: " << velocity << " m/s\n";
		}
		if(sel == "freq")
		{
			cout << "    Enter the speed of the object: ";
			velocity = rq.VDO();
			cout << "    Enter the emited wavelengh of object: ";
			Dshift  = rq.VDO();

			waveLength = (velocity / 299800000) * Dshift;
			cout << "the Starting wavelength is: " << waveLength;
		}

		if(sel == "help" || sel == "ls")
		{
			cout << "________________________________________________________\n"
			     << setw(15) << "freq" << setw(40) << "Find origanal frequency of the object\n"
			     << setw(15) << "speed" << setw(40) << "Find speed of the object\n"
			     
			     << setw(15) << "calc" << setw(40) << "simple calculater\n"
			     << setw(15) << "clear" << setw(40) << "Clear screen\n"
			     << setw(15) << "cd"<< setw(40) << "Exit program\n";
                   }
        	if(sel == "clear"||sel == "Clear"||sel == "CCLEAR")
        		rq.clear();  
        	if(sel == "calc"||sel == "Calc"||sel == "CALC")
        		rq.calc();
        	if(sel == "cd"||sel == "CD")
        		break;
	}
}
void Astro::lumin(){
	double dis, ans, lum, brit;
	string sel;
	
	while(true)
	{
		cout << "\nViper_Astronomy_Luminosity: ";
		cin >> sel;
		rq.IN_History(sel);
		rq.univSelec(sel,sel);

		if(sel == "lum"){
			cout << "    Enter the distance to the object(meters): ";
			dis = rq.VDO();
			cout << "    Enter the brightnes(wats/meters): ";
			brit = rq.VDO();

			ans = 4.0* pi * pow(dis, 2) * brit;
			cout << "The luminosity of the object is: "<< ans << endl;
		}
		if(sel == "bri"){
			cout << "    Enter the luminosity: ";
			lum = rq.VDO();
			cout << "    Enter the distance to the object(meters): ";
			dis = rq.VDO();

			ans = lum / (4 * pi* pow(dis, 2));
			cout << "the brigtness in (W/m^2) is: " << ans << endl;
		}
		if(sel == "dis"){
			cout << "    Enter the luminosity: ";
			lum = rq.VDO();
			cout << "    Enter the brightnes(wats/meters): ";
			brit = rq.VDO();

			ans = sqrt( lum / (4 * pi * brit));
			cout << "The distance to the bject is:\n";
				if(ans < 1)
					printf("\t%8gcm\n",(ans*100));
				if(ans > 1000 and ans < 3.0856e16)
					printf("\t%8gm\n%8gklm\n",ans,(ans/100));
				if(ans > 3.0856e16 and ans <9.4605e15)
					printf("\t%8gm\n%8gklm\n%8gpc\n", ans, (ans/1000), (ans/3.0856e16));
				if(ans >9.4605e15)
					printf("\t%8gm\n%8gklm\n%8gpc\n%8gly\n",ans,(ans/1000),(ans/3.0856e16)
							                      ,(ans/9.4605e15));
		}
		if(sel == "help" || sel == "ls"){
			cout << "________________________________________________________\n"
			     << setw(15) << "bright" << setw(40) << "Find brightness og an object\n"
			     << setw(15) << "dis" << setw(40) << "Find distance to object\n"
			     << setw(15) << "lum" << setw(40) << "luminocity of the object\n"
			     
			     << setw(15) << "calc" << setw(40) << "simple calculater\n"
			     << setw(15) << "clear" << setw(40) << "Clear screen\n"
			     << setw(15) << "cd"<< setw(40) << "Exit program\n";
                   }
        	if(sel == "clear"||sel == "Clear"||sel == "CCLEAR")
        		rq.clear();  
        	if(sel == "calc"||sel == "Calc"||sel == "CALC")
        		rq.calc();
        	if(sel == "cd"||sel == "CD")
        		break;
	}

}
void Astro::help()
{
     cout << "________________________________________________________\n"
          << setw(15) << "doppler" << setw(40) << "Calculate dopler shift\n"
          << setw(15) << "rocket" << setw(40) << "Tercofskies rocket equation\n"
          
          << setw(15) << "calc" << setw(40) << "simple calculater\n"
          << setw(15) << "cd" << setw(40) << "return to phisics menue\n"
          << setw(15) << "coatl" << setw(40) << "search for program\n"
          << setw(15) << "chmod" << setw(40) << "Change subject phisics/chem/trig\n"
          << setw(15) << "clear" << setw(40) << "Clear screen\n"
          << setw(15) << "history" << setw(40) << "show most keystrokes\n"
          << setw(15) << "rec" << setw(40) << "record your notes and observations\n"
          << setw(15) << "search" << setw(40) << "search for program\n"
          << setw(15) << "exit"<< setw(40) << "Exit program\n";
     }
// class destructor
Astro::~Astro()
{
}
