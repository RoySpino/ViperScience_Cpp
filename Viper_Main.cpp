#include "viper.h"
#include "chem.h"
#include "coatl.h"
#include "convert.h"
#include "math.h"
#include "astro.h"
#include "elect.h"
#include "login.h"
#include "econ.h"
#include "Resor.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void mod(string &mod);
void LOGIN(bool &, int &, int);

int chem1(int&, int&, string&);
int Conv(int&, int&, string&);
int math1(int&, int&, string&);
int electron(int&, int&, string&);
int phys(int&, int&, string&);
int astro(int&, int&, string&);
int econo(int&, int&, string&);
string viper_rc(int&, int&);

resor re; // RESORCE OBJECT
viper vip;
chem ch;
convert con;
coatl co;
math mat;
elect el;
econ Econ;
Astro Ast;

string record;
string HANDLER;
string trash;
string HOME;

int main()
{
	string input, mode;
    	int ex=0,ind, tempAcces,loginCONTROL,
	    clearControl =0;
    	bool t;
  
	// call viper rc document costomizing
        mode = viper_rc(loginCONTROL, clearControl);
	re.clearCON( clearControl );
	HOME = mode;
	re.getHome(HOME);

	while(true)
	{
		LOGIN(t, tempAcces, loginCONTROL);
		if(t == false)
			return EXIT_SUCCESS;
    		
		while(true)  
		{
			if(mode == "Phys")
				ex = phys(tempAcces, ind, mode);
			if(mode == "Chem")
				ex = chem1(tempAcces, ind, mode);
			if(mode == "Math")
				ex = math1(tempAcces, ind, mode);
			if(mode == "Elect")
				ex = electron(tempAcces, ind, mode);
			if(mode == "Astro")
				ex = astro(tempAcces, ind, mode);
			if(mode == "Econ")
				ex = econo(tempAcces, ind, mode);
			if(mode == "conv")
				ex = Conv(tempAcces, ind, mode);
			if(ex == 1)
				break;
		}
		if(loginCONTROL == 1)
			return EXIT_SUCCESS;
	}
	return 0;
}
//===================================================================================
void LOGIN(bool &t, int &tempAcces, int lc)
{
    	while( true)  // login ////////////////////////////////////////////////////
    	{
           	login lo;
           	t = lo.input(tempAcces,record, lc);
        
           	if(t == true)
           	{
                	cout << "\n                     welcome  to" << 
				"\n                   Viper  Science\n";
			if(tempAcces ==5)
                		cin.get();
			else
			{
				cin.get();
                		cin.get();
			}
                	break;
                }
           	else
               		return;
	}
}
int phys(int &tempAcces, int &ind, string &mode)
{
	string input;
	while(true)
    	{
          	cout << "\nViper_Physics: ";
         
          	cin >> input;
          	//ind = h.index ++;
          	re.IN_History(input); // input into HISTORY
  
          	re.univSelec(input,input); // Universal Selector

// selection ///////////////////////////////////////////////////////////////////    
          
          	if(input == "consaccel")
                   	vip.consaccel();
          	if(input == "springenergy")
                   	vip.spring();
          	if(input == "keneticenergy")
                   	vip.kenenergy();
          	if(input == "consenergy")
                   vip.consenergy();
          	if(input == "projetmot")
                   vip.projectile();
          	if(input == "resist")
                   vip.resistor();
          	if(input == "tor")
                   vip.torque();
          	if(input == "grav")
                   vip.grav();
          	if(input == "momentum")         
                   vip.momentum();
          	if(input == "convert")
          	{
                    string  lab = "Physics";
                    ch.convert(input,lab);
                    }
          	if(input == "cent")         
          	         vip.cent();
          	if(input == "thermexp")
          	         vip.thermexp();
          	if(input == "heatcap")
          	         vip.heatcap();
          	if(input == "graven")
          	         vip.graven();
          	if(input == "adiabetic")
          	         vip.adiabetic();
          	if(input == "calo")
                   	vip.calo();
          	if(input == "elefield")
                   vip.elecField();
          	if(input == "magnet")
                   vip.magnet();
          	if(input == "componet")
                   vip.componet();
          	if(input == "ior")
                   vip.ior();
          	if(input == "lens")
                   vip.lens();
          	if(input == "light")
                   vip.light();
          	if(input == "wave")
                   vip.wave();
                   
// Utility /////////////////////////////////////////////////////////////////////
          	if(input == "clear")
                   re.clear();
          	if(input == "calc")
                   re.calc();
          	if(input == "cd")
		{
			mode = re.cd();
			return 2;
		}
          	if(input == "help"||input == "ls")
                   vip.help();
          	if(input == "chmod")
          	{
                   	if(tempAcces == 2) // teperary acces
                   	{
                          	cout << "\n\a          ---Temporary axcess--- \n" << 
					"  user is not allowed to change directories\n" << 
					"          User request is denied\n";
                          	input.erase();
                          	cin >> trash;
                        }
                   	else
			{
                   		mode = re.cd(mode);
                        	return 2;
                   	}
		}
          	if(input == "coatl"||input == "find"||input == "search")
          	{
                   	if(tempAcces == 2) // teperary acces
                   	{
			   cout << "\n\a          ---Temporary Access--- \n" << 
				" User is not allowed to use Coatl Search Engine\n" << 
				"          User request is denied \n";
                          	input.erase();
                          	cin >> trash;
                   	}
                   	else
		   	{
			   	re.handl(HANDLER);
		       	   	re.IN_History(HANDLER);
                           	co.search(HANDLER); 
		           	HANDLER = "\0";
		   	}
          	}
          	if(input == "rec")
          	{
                   	if(tempAcces != 2)
                   		re.rec(record);
                }
          	if(input == "history")
                   	re.histOUT();
          	if(input == "exit")
                   	{ re.clear();
                   	return 1;}
	}
}
int econo(int&tempAcces, int &ind, string& mode){
	string input;

	while(true){
           	cout << "\nViper_Econ: ";
           	cin >> input;
           	re.IN_History(input); // Input into HISTORY
	   	re.univSelec(input,input); // Universal Selector

		if(input == "infl")
			Econ.infl();
		if(input == "gdp")
			Econ.gdp();
		if(input == "consume")
			Econ.consume();


          	if(input == "help"||input == "ls")
			Econ.help();
          	if(input == "chmod")
          	{
                   	if(tempAcces == 2) // teperary acces
                   	{
                          	cout << "\n\a          ---Temporary axcess--- \n" << 
					"  user is not allowed to change directories\n" << 
					"          User request is denied\n";
                          	input.erase();
                          	cin >> trash;
                        }
                   	else
			{
                   		mode = re.cd(mode);
                        	return 2;
                   	}
		}
          	if(input == "coatl"||input == "find"||input == "search")
          	{
                   	if(tempAcces == 2) // teperary acces
                   	{
			   cout << "\n\a          ---Temporary Access--- \n" << 
				" User is not allowed to use Coatl Search Engine\n" << 
				"          User request is denied \n";
                          	input.erase();
                          	cin >> trash;
                   	}
                   	else
		   	{
			   	re.handl(HANDLER);
		       	   	re.IN_History(HANDLER);
                           	co.search(HANDLER); 
		           	HANDLER = "\0";
		   	}
          	}
          	if(input == "rec")
          	{
                   	if(tempAcces != 2)
                   		re.rec(record);
                }
          	if(input == "history")
                   	re.histOUT();
          	if(input == "exit")
                   	{ re.clear();
                   	return 1;}
	        if(input == "clear")
			re.clear();
          	if(input == "calc")
			re.calc();
          	if(input == "cd")
		{
			mode = re.cd();
			return 2;
		}
	}
}
int Conv(int&tempAcces, int &ind, string& mode){
	string input;

	while(true){
		cout << "\nViper_Conversion: ";
		cin >> input;
		
		re.IN_History(input);
		re.univSelec(input, input);

		if(input == "energy")
			con.energy();
		if(input == "meters")
			con.meters();
		if(input == "milkl")
			con.milklm();
		if(input == "presure")
			con.presure();
		if(input == "temp")
			con.temp();

          	if(input == "help"||input == "ls")
			con.help();
          	if(input == "chmod"){
                   	if(tempAcces == 2) // teperary acces
                   	{
                          	cout << "\n\a          ---Temporary axcess--- \n" << 
					"  user is not allowed to change directories\n" << 
					"          User request is denied\n";
                          	input.erase();
                          	cin >> trash;
                        }
                   	else
			{
                   		mode = re.cd(mode);
                        	return 2;
                   	}
		}
          	if(input == "coatl"||input == "find"||input == "search"){
                   	if(tempAcces == 2) // teperary acces
			{
			   cout << "\n\a          ---Temporary Access--- \n" << 
				" User is not allowed to use Coatl Search Engine\n" << 
				"          User request is denied \n";
                          	input.erase();
                          	cin >> trash;
                   	}else{
			   	re.handl(HANDLER);
		       	   	re.IN_History(HANDLER);
                           	co.search(HANDLER); 
		           	HANDLER = "\0";
		   	}
          	}
          	if(input == "rec"){
                   	if(tempAcces != 2)
                   		re.rec(record);
                }
          	if(input == "history")
                   	re.histOUT();
          	if(input == "exit")
                   	{ re.clear();
                   	return 1;}
	        if(input == "clear")
			re.clear();
          	if(input == "calc")
			re.calc();
          	if(input == "cd"){
			mode = re.cd();
			return 2;
		}
	}
}
int astro(int &tempAcces, int &ind, string& mode)
{
	string input;
     
     	while (true){
           	cout << "\nViper_Astronomy: ";
           	cin >> input;
           	re.IN_History(input); // Input into HISTORY
	    
	   	re.univSelec(input,input); // Universal Selector
		if(input == "doppler")
			Ast.doppler();
		if(input == "lum")
			Ast.lumin();


	        if(input == "clear")
			re.clear();
          	if(input == "calc")
			re.calc();
          	if(input == "cd")
		{
			mode = re.cd();
			return 2;
		}
          	if(input == "help"||input == "ls")
			Ast.help();
          	if(input == "chmod")
          	{
                   	if(tempAcces == 2) // teperary acces
                   	{
                          	cout << "\n\a          ---Temporary axcess--- \n" << 
					"  user is not allowed to change directories\n" << 
					"          User request is denied\n";
                          	input.erase();
                          	cin >> trash;
                        }
                   	else
			{
                   		mode = re.cd(mode);
                        	return 2;
                   	}
		}
          	if(input == "coatl"||input == "find"||input == "search")
          	{
                   	if(tempAcces == 2) // teperary acces
                   	{
			   cout << "\n\a          ---Temporary Access--- \n" << 
				" User is not allowed to use Coatl Search Engine\n" << 
				"          User request is denied \n";
                          	input.erase();
                          	cin >> trash;
                   	}
                   	else
		   	{
			   	re.handl(HANDLER);
		       	   	re.IN_History(HANDLER);
                           	co.search(HANDLER); 
		           	HANDLER = "\0";
		   	}
          	}
          	if(input == "rec")
          	{
                   	if(tempAcces != 2)
                   		re.rec(record);
                }
          	if(input == "history")
                   	re.histOUT();
          	if(input == "exit")
                   	{ re.clear();
                   	return 1;}
	}
}
int chem1(int &tempAcces, int &ind, string &mode)
{
	string input;
     
     	while (true){
           	cout << "\nViper_Chem: ";
           	cin >> input;
           	re.IN_History(input); // Input into HISTORY
	    
	   	re.univSelec(input,input); // Universal Selector
          
           	if(input == "autotitrator")
                    	ch.titrate();
           	if(input == "boyllaw")
                   	ch.boyllaw();
           	if(input == "calc")
                   	ch.calc();
           	if(input == "charlaw")
                   	ch.charlaw();
           	if(input == "help"|| input == "ls")
                   	ch.help();
           	if(input == "elecplat")
                   	ch.elecplat();
           	if(input == "idelgas")
                   	ch.idelgas();
           	if(input == "ph")
                   	ch.ph();
           	if(input == "eqlib")
                    	ch.eqlprsur();
           	if(input == "frzpoint")
                    	ch.frzpoint();
           	if(input == "convert")
           	{
                    	string  lab = "Chem";
                    	ch.convert(input,lab);
                }
           	if(input == "stoich")
                   	ch.stoichiometry();
           	if(input == "oxystate")
                   	ch.oxidationState();
           	if(input == "solutions")
                   	ch.solutions();
           	if(input == "bal")
			ch.balance();
           	if(input == "henry")
			ch.hgl();
           
           
           
           	if(input == "clear")
                   	re.clear();
           	if(input == "rec")
                   	re.rec(record);
           	if(input == "cd")
		{
                   	mode = re.cd();
			return 0;
		}
           	if(input == "history")
                   	re.histOUT();
           	if(input == "exit")
           	{
                   	re.clear();
                   	return 1;
                }
           	if(input == "chmod")
          	{
                   	if(tempAcces == 2) // teperary acces
                   	{
                          	cout << "\n\a          ---Temporary axcess--- \n" << 
					"  user is not allowed to change directories\n" << 
					"          User request is denied\n";
                          	input.erase();
                          	cin >> trash;
                        }
                   	else
		   	{	       
                   		mode = re.cd(mode);
                        	return 2;
                   	}
                }
          	if(input == "coatl"||input == "find"||input == "search")
	  	{
			if(tempAcces == 2)
			{
                          	cout << "\n\a            ---Temporary axcess--- \n" << 
					"  user is not allowed to use Coatl Search Engine\n" << 
					"             User request is denied\n";
                          	input.erase();
				cin >> trash;
			}
			else
			{

		   		re.handl(HANDLER);
		   		re.IN_History(HANDLER);
                   		co.search(HANDLER);
		   
		   		HANDLER = "\0";
			}
	  	}
	}
}
int math1(int &tempAcces, int &ind, string &mode)
{
	string input;

     	while (true)
	{
             	cout << "\nViper_Math: ";
              
             	cin >> input;
             	re.IN_History(input); // Input into HISTORY
	     	re.univSelec(input,input); // Universal Selector

           	if(input == "dot"|| input == "Dot"|| input == "DOT")
                   	mat.dotprod();
           	if(input == "cros"|| input == "Cros"|| input == "CROS")
                   	mat.cross();
           	if(input == "magnetud"|| input == "Magnetud"|| input == "MAGNETUDE")
                   	mat.magnetud();
           	if(input == "sin"|| input == "Sin"|| input == "SIN")
                   	mat.sine();
           	if(input == "plane"|| input == "Plane"|| input == "PLANE")
                   	mat.calcplane();
           	if(input == "tan"|| input == "Tan"|| input == "TAN")
                   	mat.tang();
           	if(input == "cos"|| input == "Cos"|| input == "COS")
                   	mat.coss();
           	if(input == "shapes"||input == "Shapes"||input == "SHAPES")
                   	 mat.shape();
           	if(input == "shadow"||input == "Shadow"||input == "SHADOW")
                   	 mat.shadow();
           	if(input == "sandev"||input == "sanDev"||input == "STANDEV")
                   	 mat.sanDev();
           	if(input == "exp"||input == "Exp"||input == "EXP")
                   	 mat.groth();
           	if(input == "rando"||input == "Rando" ||input == "RANDO")
                   	 mat.rando();
           	if(input == "prob")
                   	 mat.prob();
		if(input == "dataa")
			mat.dataAnal();
		if(input == "matrx")
			mat.MatrixCalc();
                    
                    
           	if(input == "rec"|| input == "Rec"|| input == "REC")
                   	re.rec(record);
           	if(input == "cd"|| input == "CD")
		{
			mode = re.cd();
                   	return 2;
                }
           	if(input == "clear"|| input == "CLEAR"|| input == "Clear")
                   	re.clear();
           	if(input == "calc"|| input == "CALC"|| input == "Calc")
                   	re.calc();
           	if(input == "help"|| input == "Help"|| input == "HELP"||input == "Ls"||input == "ls"|| input == "LS")
                   	mat.help();
           	if(input == "history"|| input == "History"|| input == "HISTORY")
                   	re.histOUT();
           	if(input == "exit"|| input == "Exit"|| input == "EXIT")
           	{
                   	re.clear();
                   	return 1;
                }
           	if(input == "chmod"|| input == "chMod"|| input == "CHMOD")
          	{
                   	if(tempAcces == 2) // teperary acces
                   	{
                          	cout << "\n\a          ---Temporary axcess--- \n" << 
					"  user is not allowed to change directories\n" << 
					"          User request is denied\n";
                          	input.erase();
				cin >> trash;
                        }
                   	else
		   	{	       
                   		mode = re.cd(mode);
                        	return 2;
			}
                }
          	if(input == "coatl"|| input == "find"|| input == "search")
             	{
			if(tempAcces == 2)
			{
                          	cout << "\n\a            ---Temporary axcess--- \n" << 
					"  user is not allowed to use Coatl Search Engine\n" << 
					"             User request is denied\n";
                          	input.erase();
                          	cin >> trash;
			}
			else
			{
		   		re.handl(HANDLER); 
		   		re.IN_History(HANDLER);
                   		co.search(HANDLER); 
		   		HANDLER = "\0";
			}
        	}
	}
}
int electron(int &tempAcces, int &ind, string &mode)
{
	string input;

     	while (true)
	{
           	cout << "\nViper_Electronics: ";
              
              	cin >> input;
              	re.IN_History(input);// Input into HISTOURY
	        
	      	re.univSelec(input,input); // Universal Selector

              	if(input == "horse"|| input == "Horse"|| input == "HORSE")
                   	el.horse();
              	if(input == "kilo"|| input == "Kilo"|| input == "KILO")
                   	el.kilo();
              	if(input == "kiloam"|| input == "KiloAm"|| input == "Kiloam"|| input == "KILOAM")
                   	el.kiloAm();
              	if(input == "imped"|| input == "Imped"|| input == "IMPED")
                   	el.imped();
                   
              	if(input == "resist"|| input == "Resist"|| input == "RESIST")
                   	el.rescolor();
		if(input == "oscillat")
			el.oscillators();
              	////////////////////////////////////////////////////////////////////
              	////////////////////////////////////////////////////////////////////
              	if(input == "rec"|| input == "Rec"|| input == "REC")
                   	re.rec(record);
              	if(input == "cd"|| input == "CD")
		{
			mode = re.cd();
                       	return 2;
                }
               	if(input == "clear"|| input == "CLEAR"|| input == "Clear")
                       	re.clear();
               	if(input == "calc"|| input == "CALC"|| input == "Calc")
                       	re.calc();
               	if(input == "help"|| input == "Help"|| input == "HELP"||input == "Ls"||input == "ls"|| input == "LS")
                       	el.help();
               	if(input == "history"|| input == "History"|| input == "HISTORY")
                   	re.histOUT();
               	if(input == "exit"|| input == "Exit"|| input == "EXIT")
               	{
                       	re.clear();
                       	return 1;
                       }
               	if(input == "chmod"|| input == "chMod"|| input == "CHMOD")
              	{
                   	if(tempAcces == 2) // teperary acces
                   	{
                          	cout << "\n\a          ---Temporary axcess--- \n" << 
					"  user is not allowed to change directories\n" << 
					"          User request is denied\n";
                          	input.erase();
				cin >> trash;
                        }
                   	else
		   	{	       
                   		mode = re.cd(mode);
                        	return 2;
			}
              	}
              	if(input == "coatl"|| input == "find"|| input == "search")
              	{
			if(tempAcces == 2)
			{
                          	cout << "\n\a            ---Temporary axcess--- \n" << 
					"  user is not allowed to use Coatl Search Engine\n" << 
					"             User request is denied\n";
                          	input.erase();
                          	cin >> trash;
			}
			else
			{
		       		re.handl(HANDLER);	 
		       		re.IN_History(HANDLER);
                       		co.search(HANDLER); 
		       		HANDLER = "\0";
			}
		}
	}
}
//######################################################################
string viper_rc(int &lpas, int &clearC)
{
	string rc, rcGET;


	ifstream VIPERRC(".viperrc");
	if(! VIPERRC)
	{
		lpas = 5;
		return "Phys";
	}

	// get clear comand for windows
	ifstream viperRcWindows(".viperrc");
	while(! viperRcWindows.eof())
	{
		getline(viperRcWindows, rcGET);

		if(rcGET == "windows" || rcGET == "Windows"||
		   rcGET == "win" || rcGET == "Win")
			clearC = 1;
	}

	// check for login
	while(! VIPERRC.eof())
	{
		getline(VIPERRC, rcGET);

		if(rcGET == "login=no"|| rcGET == "login=n")
			lpas = 1;

	}

	// get a HOME diriectory
	ifstream VIPER_return(".viperrc");
	while(! VIPER_return.eof())
	{
		getline(VIPER_return, rcGET);

		if(rcGET == "physics"|| rcGET == "phys")
			return "Phys";
		else
		{
		 	if(rcGET == "chemistry" || rcGET == "chem")
				return "Chem";
			else
			{
				if(rcGET == "math" || rcGET == "math")
					return "Math";
				else
				{
					if(rcGET == "electronics" || rcGET == "elect")
						return "electron";
					else
						return "Phys";
				}
			}
		}
	}
}
