#include "elect.h" // class's header file
#include "Resor.h" // Resurce header file
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

resor req;

double const pi = 3.141592653589793238462643383279502884197169399375105820974944;

struct resistor
{
       string color;
       double dval,
              dmult;
       int val,
           mult;
       }res2[10];

// class constructor
elect::elect()
{
	// insert your code here
	res2[0].color = "black";   res2[0].val = 0;   res2[0].mult = 1;
	res2[1].color = "brown";   res2[1].val = 1;   res2[1].mult = 10;
	res2[2].color = "red";     res2[2].val = 2;   res2[2].mult = 100;
	res2[3].color = "orange";  res2[3].val = 3;   res2[3].mult = 1000;
	res2[4].color = "yellow";  res2[4].val = 4;   res2[4].mult = 10000;
	res2[5].color = "green";   res2[5].val = 5;   res2[5].mult = 100000;
	res2[6].color = "blue";    res2[6].val = 6;   res2[6].mult = 1000000;
	res2[7].color = "violet";  res2[7].val = 7;   res2[7].mult = 10000000;
	res2[8].color = "gray";    res2[8].val = 8;   res2[8].mult = 100000000;
	res2[9].color = "white";   res2[9].val = 9;   res2[9].mult = 1000000000;
	
	res2[0].dval = 0;   res2[0].dmult = 1;
	res2[1].dval = 1;   res2[1].dmult = 10;
	res2[2].dval = 2;   res2[2].dmult = 100;
	res2[3].dval = 3;   res2[3].dmult = 1000;
	res2[4].dval = 4;   res2[4].dmult = 10000;
	res2[5].dval = 5;   res2[5].dmult = 100000;
	res2[6].dval = 6;   res2[6].dmult = 1000000;
	res2[7].dval = 7;   res2[7].dmult = 10000000;
	res2[8].dval = 8;   res2[8].dmult = 100000000;
	res2[9].dval = 9;   res2[9].dmult = 1000000000;
}
/////////////////////////////////////////////////////
void elect::clear()
{
     // cout << string(50,'\n');
     system("clear");
     }
///////////////////////////////////////////////////////
void elect::calc()
{
     double ans, num1, num2;
     string mod;
     
     cin >> num1;
     cin >> mod;
     
     
     if(mod == "tan"||mod == "sin"||mod == "cos"||
        mod == "rtan"||mod == "rsin"||mod == "rcos"||
        mod == "arctan"||mod == "arcsin"||mod == "arccos"||
        mod == "log"||mod == "ln"||mod == "log10"||mod == "e"||
        mod == "sqrt")
      {
             if(mod == "tan")
                    {ans = tan(num1 *(pi/180));}
             else if(mod == "cos")
                    {ans = cos(num1 *(pi/180));}
             else if(mod == "sin")
                    {ans = sin(num1 *(pi/180));}
                    
             else if(mod == "arctan")
                    {ans = tan(num1) *(180/pi);}
             else if(mod == "arccos")
                    {ans = cos(num1) *(180/pi);}
             else if(mod == "arcsin")
                    {ans = sin(num1) *(180/pi);}
                    
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
             cin >> num2;
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
/////////////////////////////////////////////////////////////////////
void elect::horse()
{
     long double volt,amp, effic, powf, horse,ans;
         
     string sel, col[3], color[3];
     col[2] = "black";
     
     while(true){
          cout << "\nViper_Electronics_horsePower: ";
          cin >> sel;
          req.IN_History(sel);
	  req.univSelec(sel,sel);

          if(sel == "wattsthree"||sel == "WattsThree"||sel == "WATTSTHREE")
          {
                 cout << "    Enter horsepower of motor:   ";
                 horse = req.VDO();
                 
                 while(true) /// check if powerFactor is valid
                 {
                     cout << "    Enter power factor of motor:       ";
                     powf = req.VDO();
                         if(powf > 1)
                                  powf = powf / 100;
                         if(powf > 1)
                                  cout << "\nInvalid entry: must be within 0% and 100%\n";
                         else
                             break;
                         }
                 
                 while(true) /// check if efficancy is valid
                 {
                     cout << "    Enter motor efficincy:             ";
                     effic = req.VDO();
                         if(effic > 1)
                                  effic = effic / 100;
                         if(effic > 1)
                                  cout << "\nInvalid entry: must be within 0% and 100%\n";
                         else
                             break;
                         }
                 
                 ans = (horse * 746) / (effic * powf * 1.73);
                 
                 cout << "total watts consumed by motor is: " << ans << endl;
                 }
          if(sel == "wattssingle"||sel == "WattsSingle"||sel == "WATTSSINGLE")
          {
                 cout << "    Enter horsepower of motor:   ";
                 horse = req.VDO();
                 cout << "    Enter power factor of motor: ";
                 
                 while(true) /// check if powerFactor is valid
                 {
                     cout << "    Enter power factor of motor:       ";
                     cin >> powf;
                         if(powf > 1)
                                  powf = powf / 100;
                         if(powf > 1)
                                  cout << "\nInvalid entry: must be within 0% and 100%\n";
                         else
                             break;
                         }
                 
                 while(true) /// check if efficancy is valid
                 {
                     cout << "    Enter motor efficincy:             ";
                     effic = req.VDO();
                         if(effic > 1)
                                  effic = effic / 100;
                         if(effic > 1)
                                  cout << "\nInvalid entry: must be within 0% and 100%\n";
                         else
                             break;
                         }
                 
                 ans = (horse * 746) / (effic * powf);
                 
                 cout << "total watts consumed by motor is: " << ans << endl;
                 }
          if(sel == "wattstdc"||sel == "WattsDC"||sel == "WATTSDC")
          {
                 cout << "    Enter horsepower of motor:   ";
                 horse = req.VDO();
                 
                 while(true) /// check if efficancy is valid
                 {
                     cout << "    Enter motor efficincy:             ";
                     effic = req.VDO();
                         if(effic > 1)
                                  effic = effic / 100;
                         if(effic > 1)
                                  cout << "\nInvalid entry: must be within 0% and 100%\n";
                         else
                             break;
                         }
                 
                 ans = (horse * 746) / effic;
                 
                 cout << "total watts consumed by motor is: " << ans << endl;
                 }
          if(sel == "horsethree"||sel == "HorseThree"||sel == "HORSETHREE")
          {
                 cout << "    Enter the volts used by the motor: ";
                 volt = req.VDO();
                 cout << "    Enter the amps used by the motor:  ";
                 amp = req.VDO();
                 
                 while(true) /// check if powerFactor is valid
                 {
                     cout << "    Enter power factor of motor:   ";
                     cin >> powf;
                         if(powf > 1)
                                  powf = powf / 100;
                         if(powf > 1)
                                  cout << "\nInvalid entry: must be within 0% and 100%\n";
                         else
                             break;
                         }
                 
                 while(true) /// check if efficancy is valid
                 {
                     cout << "    Enter motor efficincy:         ";
                     effic = req.VDO();
                         if(effic > 1)
                                  effic = effic / 100;
                         if(effic > 1)
                                  cout << "\nInvalid entry: must be within 0% and 100%\n";
                         else
                             break;   
                         }
                 
                 ans = (volt * amp * powf * effic * 1.73) / 746;
                 
                 cout << "total horsepower preduced by the motor is: " << ans << endl;
                 }
          if(sel == "horsesingle"||sel == "HorseSingle"||sel == "HORSESINGLE")
          {
                 cout << "    Enter the volts used by the motor: ";
                 volt = req.VDO();
                 cout << "    Enter the amps used by the motor:  ";
                 amp = req.VDO();
                 
                 while(true) /// check if powerFactor is valid
                 {
                     cout << "    Enter power factor of motor:       ";
                     cin >> powf;
                         if(powf > 1)
                                  powf = powf / 100;
                         if(powf > 1)
                                  cout << "\nInvalid entry: must be within 0% and 100%\n";
                         else
                             break;
                         }
                 
                 while(true) /// check if efficancy is valid
                 {
                     cout << "    Enter motor efficincy:             ";
                     effic = req.VDO();
                         if(effic > 1)
                                  effic = effic / 100;
                         if(effic > 1)
                                  cout << "\nInvalid entry: must be within 0% and 100%\n";
                         else
                             break;  
                         }
                 
                 ans = (volt * amp * powf * effic) / 746;
                 
                 cout << "total horsepower preduced by the motor is: " << ans << endl;
                 }
          if(sel == "horse"||sel == "Horse"||sel == "HORSE")
          {
                 cout << "    Enter the volts used by the motor: ";
                 volt = req.VDO();
                 cout << "    Enter the amps used by the motor:  ";
                 amp = req.VDO();
                 cout << "    Enter power factor of motor:       ";
                 powf = req.VDO();
                 
                 while(true) /// check if efficancy is valid
                 {
                     cout << "    Enter motor efficincy:             ";
                     effic = req.VDO();
                         if(effic > 1)
                                  effic = effic / 100;
                         if(effic > 1)
                                  cout << "\nInvalid entry: must be within 0% and 100%\n";
                         else
                             break;
                                  
                         }
                 
                 ans = (volt * amp * effic) / 746;
                 
                 cout << "total horsepower preduced by the motor is: " << ans << endl;
                 }
          if(sel == "powfacs"||sel == "PowFacS"||sel == "POWFACS")
          {
                 cout << "    Enter the volts used by the motor: ";
                 volt = req.VDO();
                 cout << "    Enter the amps used by the motor:  ";
                 amp = req.VDO();
                 cout << "    Enter Horsepower of motor:         ";
                 horse = req.VDO();
                
                 while(true) /// check if efficancy is valid
                 {
                     cout << "    Enter motor efficincy:             ";
                     effic = req.VDO();
                         if(effic > 1)
                                  effic = effic / 100;
                         if(effic > 1)
                                  cout << "\nInvalid entry: must be within 0% and 100%\n";
                         else
                             break;
                                  
                         }
                 
                 ans = (horse * 746) / (volt * amp * effic);
                 
                 cout << "total power factor of the motor is: " << ans << endl;
                 }
          if(sel == "powfac3"||sel == "PowFac3"||sel == "POWFAC3")
          {
                 cout << "    Enter the volts used by the motor: ";
                 volt = req.VDO();
                 cout << "    Enter the amps used by the motor:  ";
                 amp = req.VDO();
                 cout << "    Enter Horsepower of motor:         ";
                 horse = req.VDO();
                 
                 while(true) /// check if efficancy is valid
                 {
                     cout << "    Enter motor efficincy:             ";
                     effic = req.VDO();
                         if(effic > 1)
                                  effic = effic / 100;
                         if(effic > 1)
                                  cout << "\nInvalid entry: must be within 0% and 100%\n";
                         else
                             break;
                                  
                         }
                 
                 ans = (horse * 746) / (volt * amp * effic * 1.73);
                 
                 cout << "total power factor of the motor is: " << ans << endl;
                 }
          /////////////////////////////////////////////////////////////////////////
          if(sel == "help"||sel == "Help"||sel == "HELP"||sel == "LS"||sel == "ls")
            {
                   cout << "________________________________________________________\n"
                        << setw(15) << "wattstdc" << setw(40) << "find watts used by dc motor\n"
                        << setw(15) << "wattssingle" << setw(40) << "find watts used by single phase motor\n"
                        << setw(15) << "wattsthree" << setw(40) << "find watts used by three phase motor\n"
                        << setw(15) << "wattstdc" << setw(40) << "find horsepower from a dc motor\n"
                        << setw(15) << "horsesingle" << setw(40) << "find horsepower from a 1 phase motor\n"
                        << setw(15) << "horesthree" << setw(40) << "find horsepower from 3 phase motor\n"
                        << setw(15) << "powfacs" << setw(40) << "find power factor of a 1 phase motor\n"
                        << setw(15) << "powfac3" << setw(40) << "find power factor of a 3 phase motor\n"
                        
                        << setw(15) << "calc" << setw(40) << "simple calculater\n"
                        << setw(15) << "clear" << setw(40) << "Clear screen\n"
                        << setw(15) << "cd"<< setw(40) << "Exit program\n";
                        
                   }
          if(sel == "clear"||sel == "Clear"||sel == "CCLEAR")
                 req.clear();  
          if(sel == "calc"||sel == "Calc"||sel == "CALC")
                 req.calc();
          if(sel == "cd"||sel == "CD")
                 break;
          }
}
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void elect::kilo()
{
     long double volt,amp, effic, powf, horse,ans;
         
     string sel;
     
     while(true){
          cout << "\nViper_Electronics_Kolowatts: ";
          cin >> sel;
          req.IN_History(sel);
	  req.univSelec(sel,sel);

          
          if(sel == "dcwatts"||sel == "DCwatts"||sel == "DCWatts"||sel == "DCWATTS")
          {
                 cout << "    Enter volts:        ";
                 volt = req.VDO();
                 cout << "    Enter amps:         ";
                 amp = req.VDO();
                 
                 ans = (volt * amp) / 1000;
                 cout << "Total killowats within the system is: " << ans;
                 }
          if(sel == "single"||sel == "Single"||sel == "SINGLE")
          {
                 cout << "    Enter volts:        ";
                 volt = req.VDO();
                 cout << "    Enter amps:         ";
                 amp = req.VDO();
                 cout << "    Enter power factor: ";
                 powf = req.VDO();
                 
                 ans = (volt * amp * powf) / 1000;
                 cout << "Total killowats within the system is: " << ans;
                 }
          if(sel == "three"||sel == "Three"||sel == "THREE")
          {
                 cout << "    Enter volts:        ";
                 volt =req.VDO();
                 cout << "    Enter amps:         ";
                 amp = req.VDO();
                 cout << "    Enter power factor: ";
                 powf = req.VDO();
                 
                 ans = (volt * amp * powf * 1.73) / 1000;
                 cout << "Total killowats within the system is: " << ans;
                 }
          /////////////////////////////////////////////////////////////////////////
          if(sel == "dcamp"||sel == "DCAmp"||sel == "DCamp"||sel == "DCAMP")
          {
                 cout << "    Enter volts:        ";
                 volt = req.VDO();
                 cout << "    Enter Killowatts:   ";
                 amp = req.VDO();
                 
                 ans = (amp * 1000) / volt;
                 cout << "Total amps within the system is: " << ans;
                 }
          if(sel == "singamp"||sel == "Singamp"||sel == "SingAmp"||sel == "SINGAMP")
          {
                 cout << "    Enter volts:        ";
                 volt = req.VDO();
                 cout << "    Enter kilowatts:         ";
                 amp = req.VDO();
                 cout << "    Enter power factor: ";
                 powf = req.VDO();
                 
                 ans =  (amp* 1000) / (volt * powf);
                 cout << "Total amps within the system is: " << ans;
                 }
          if(sel == "threeamp"||sel == "threeamp"||sel == "threeamp")
          {
                 cout << "    Enter volts:        ";
                 volt = req.VDO();
                 cout << "    Enter kilowatts:         ";
                 amp = req.VDO();
                 cout << "    Enter power factor: ";
                 powf = req.VDO();
                 
                 ans = (amp * 1000) / (volt * powf * 1.73);
                 cout << "Total amps within the system is: " << ans;
                 }
          //////////////////////////////////////////////////////////////////////
          if(sel == "help"||sel == "Help"||sel == "HELP"||sel == "LS"||sel == "ls")
            {
                   cout << "________________________________________________________\n"
                        << setw(15) << "DCwatts" << setw(40) << "find DC watts\n"
                        << setw(15) << "single" << setw(40) << "find watts from single phase current\n"
                        << setw(15) << "three" << setw(40) << "find watts from three phase current\n"
                        << setw(15) << "DCamp" << setw(40) << "find DC amps from watts\n"
                        << setw(15) << "singamp" << setw(40) << "find amps from single phase current\n"
                        << setw(15) << "threeamp" << setw(40) << "find amps from three phase current\n"
                        
                        << setw(15) << "calc" << setw(40) << "simple calculater\n"
                        << setw(15) << "clear" << setw(40) << "Clear screen\n"
                        << setw(15) << "cd"<< setw(40) << "Exit program\n";
                        
                   }
          if(sel == "clear"||sel == "Clear"||sel == "CCLEAR")
                 req.clear();  
          if(sel == "calc"||sel == "Calc"||sel == "CALC")
                 req.calc();
          if(sel == "cd"||sel == "CD")
                 break;
          }
     }
     ///////////////////////////////////////////////////////////////////////////
void elect::kiloAm()
{
     long double volt,amp, effic, powf, horse,ans;
         
     string sel;
     
     while(true){
          cout << "\nViper_Electronics_Kollovolt-Amp: ";
          cin >> sel;
          req.IN_History(sel);
	  req.univSelec(sel,sel);

          
          if(sel == "single"||sel == "Single"||sel == "SINGLE")
          {
                 cout << "    Enter volts:        ";
                 volt = req.VDO();
                 cout << "    Enter amps:         ";
                 amp = req.VDO();
                 
                 ans = (volt * amp) / 1000;
                 cout << "Total killovolt-amps within the system is: " << ans;
                 }
          if(sel == "three"||sel == "Three"||sel == "THREE")
          {
                 cout << "    Enter volts:        ";
                 volt = req.VDO();
                 cout << "    Enter amps:         ";
                 amp = req.VDO();
                 
                 ans = (volt * amp * 1.73) / 1000;
                 cout << "Total killovolt-amps within the system is: " << ans;
                 }
          //////////////////////////////////////////////////////////////////////
          if(sel == "singamp"||sel == "Singamp"||sel == "SingAmp"||sel == "SINGAMP")
          {
                 cout << "    Enter volts:        ";
                 volt = req.VDO();
                 cout << "    Enter kilowatts:         ";
                 amp = req.VDO();
                 
                 ans =  (amp * 1000) / (volt);
                 cout << "Total amps within the system is: " << ans;
                 }
          if(sel == "threeamp"||sel == "ThreeAmp"||sel == "Threeamp"||sel == "THREEAMP")
          {
                 cout << "    Enter volts:        ";
                 volt = req.VDO();
                 cout << "    Enter kilowatts:         ";
                 amp = req.VDO();
                 
                 ans = (amp * 1000) / (volt * 1.73);
                 cout << "Total amps within the system is: " << ans;
                 }
          //////////////////////////////////////////////////////////////////////
          if(sel == "help"||sel == "Help"||sel == "HELP"||sel == "LS"||sel == "ls")
            {
                   cout << "________________________________________________________\n"
                        << setw(15) << "single" << setw(40) << "find watts from single phase current\n"
                        << setw(15) << "three" << setw(40) << "find watts from three phase current\n"
                        << setw(15) << "singamp" << setw(40) << "find amps from single phase current\n"
                        << setw(15) << "threeamp" << setw(40) << "find amps from three phase current\n"
                        
                        << setw(15) << "calc" << setw(40) << "simple calculater\n"
                        << setw(15) << "clear" << setw(40) << "Clear screen\n"
                        << setw(15) << "cd"<< setw(40) << "Exit program\n";
                        
                   }
          if(sel == "clear"||sel == "Clear"||sel == "CCLEAR")
                 req.clear();  
          if(sel == "calc"||sel == "Calc"||sel == "CALC")
                 req.calc();
          if(sel == "cd"||sel == "CD")
                 break;
          }
     }
////////////////////////////////////////////////////////////////////////////////
void elect::imped()
{
     double volt, amp, res, reac, xl, xc, ans;
     string sel;
     
     while(true){
          cout << "\nViper_Electronics_Impedance: ";
          cin >> sel;
          req.IN_History(sel);
	  req.univSelec(sel,sel);

     
             if(sel == "va"||sel == "Va"||sel == "vA"||sel == "VA") 
             {
                    cout << "    Enter volts: ";
                    volt = req.VDO();
                    cout << "    Enter amps:  ";
                    amp =req.VDO();
                    
                    ans = volt / amp;
                    cout << "total impedance is: " << ans << " ohms" << endl;
                    }
             if(sel == "resrec"||sel =="ResRec"||sel == "resrec")
             {
                    cout << "    Eenter resistance: ";
                    res = req.VDO();
                    cout << "    Enter Reactance:   ";
                    reac = req.VDO();
                    
                    ans = sqrt( pow(res,2) + pow(reac,2) );
                    cout << "Total impedance is: " << ans << " ohms" << endl;
                    }
             if(sel == "resreccap"||sel =="ResRecCap"||sel == "RESRECCAP")
             {
                    cout << "    Eenter resistance:           ";
                    res = req.VDO();
                    cout << "    Enter Inductive Reactance:   ";
                    xl = req.VDO();
                    cout << "    Enter Capacitive Reactance:  ";
                    xc = req.VDO();
                    
                    ans = sqrt(pow(res,2) + pow((xl - xc),2));
                    cout << "Total impedance is: " << ans << " ohms" << endl;
                    }
             if(sel == "help"||sel == "Help"||sel == "HELP"||sel == "LS"||sel == "ls")
             {
                    cout << "________________________________________________________\n"
                         << setw(15) << "va" << setw(40) << "find impedance from volts and amps\n"
                         << setw(15) << "resrec" << setw(40) << "impedance from Resistanc & Reactance\n"
                         << setw(15) << "resreccap" << setw(40) << "impedance from ResistReact&CapacRect\n"
       
                         << setw(15) << "calc" << setw(40) << "simple calculater\n"
                         << setw(15) << "clear" << setw(40) << "Clear screen\n"
                         << setw(15) << "cd"<< setw(40) << "Exit program\n";
                                
                    }
             if(sel == "clear"||sel == "Clear"||sel == "CCLEAR")
                    req.clear();  
             if(sel == "calc"||sel == "Calc"||sel == "CALC")
                    req.calc();
             if(sel == "cd"||sel == "CD")
                    break;
             }
     }
///////////////////////////////////////////////////////////////////////////////
void elect::rescolor()
{
     long double resist,cash1, cash2, cash3, ans2;
     
     int ans1 =0, ans3,
         u = 100000000, v =0,
         r[3], ans;
         
     string sel, col[3], color[3];
     col[2] = "black";
     
     while(true){
          cout << "\nViper_Electronics_ResisterColorCode: ";
          cin >> sel;
          req.IN_History(sel);
	  req.univSelec(sel,sel);

          
          if(sel == "color"||sel == "Color"||sel == "COLOR")
          {
                 cout << "\n    Enter resistance: ";
                 resist = req.VDO();
                 ans2 = u;
                 ans3 = 9;

                  // serch for multiplier multipliers less than 10 /////////////
                  if(resist <100){
                            cash1 = (resist / 10.0);
                            
                            col[2] = res2[0].color;
                            goto assign;
                         }
                  // serch for multipliers /////////////////////////////////////
                 while (ans2 > 0){
                         cash1 = (resist / ans2);
                         
                         if(cash1 > 1||cash1 == 1)
                         {
                              col[2] = res2[ans3 - 2].color;
                              break;
                              }
                         ans3 --;
                         ans2 = (ans2 /10);
                         } 

                 // find first diget ///////////////////////////////////////////
assign:
                 cash2 = (cash1);
                 for(int n=9; n>=0; n--)
                 {
                         if(cash2 >= n &&cash2 <=(n+1))
                         {
                                   col[0] = res2[n].color;
                                   cash3 = (cash1 - n) *11;
                                   break;
                                   }
                         }
                 
                 //  ///////////////////////////////////////////////////////////
                 for(int n=9; n>=0; n--)
                 {

                         if(cash3 >= n &&cash3 <=(n+1))
                         {
                                   col[1] = res2[n].color;
                                   }
                         }
                  
                 cash1 =0;
                 cash2 =0;
                 cash3 =0;
                            
                 cout << "\n      |\n"
                      << " _____|______\n"
                      << "|            |\n"
                      << "|" << setw(10) << col[0] << "  |\n"
                      << "|            |\n"
                      << "|" << setw(10) << col[1] << "  |\n"
                      << "|            |\n"
                      << "|" << setw(10) << col[2] << "  |\n"   
                      << "|____________|\n"
                      << "      |\n"
                      << "      |\n\n";
                 }
          if(sel == "number"||sel == "Number"||sel == "NUMBER")
          {
                 for(int v =0; v <3; v++)
                 {
reenter:
                         cout << "\n    Enter color band : ";
                         cin >> color[v];
	  		 req.univSelec(color[v],color[v]);
                         
                         if(color[v] == "black")
                                     color[v] = "black";
                         else if(color[v] == "brown")
                                     color[v] = "brown";
                         else if(color[v] == "red")
                                     color[v] = "red";
                         else if(color[v] == "orange")
                                     color[v] = "orange";
                         else if(color[v] == "yellow")
                                     color[v] = "yellow";
                         else if(color[v] == "green")
                                     color[v] = "green";
                         else if(color[v] == "blue")
                                     color[v] = "blue";
                         else if(color[v] == "violet")
                                     color[v] = "violet";
                         else if(color[v] == "gray")
                                     color[v] = "gray";
                         else if(color[v] == "white")
                                     color[v] = "white";
                                     
                         else 
                         {
                              cout << "\n\a --INVALID COLOR--\n\n";
                              goto reenter;
                              }
                 }      
                 for(int v=0; v <2; v++){
                     for(int n=9; n >=0; n--)
                             {
                                     if(res2[n].color == color[v])
                                                     r[v] = res2[n].val;
                                                     }
                             }
                     for(int n=9; n >=0; n--)
                             {
                                     if(res2[n].color == color[2])
                                                     r[2] = res2[n].mult;
                                                     }
                 
                 ans = ((r[0] * 10) + r[1]) * r[2];
                 cout << "\n       _____________________\n"
                      << " _____| " << setw(12) <<ans << "        |_____\n"
                      << "      |_____________________|\n";
          }
                    
          if(sel == "help"||sel == "ls")
            {
                   cout << "________________________________________________________\n"
                        << setw(15) << "color" << setw(40) << "find color from resistance\n"
                        << setw(15) << "number" << setw(40) << "find resistance by color\n"
                        << setw(15) << "calc" << setw(40) << "simple calculater\n"
                        << setw(15) << "clear" << setw(40) << "Clear screen\n"
                        << setw(15) << "cd"<< setw(40) << "Exit program\n";
                        
                   }
	   if(sel == "calc")
		   req.calc();
           if(sel =="cd")
                 break;
           if(sel =="clear")
            // cout << string(50,'\n');
                     req.clear();
          }
     }
void elect::oscillators()
{
     string sel;
     double L, C, Hz, ans;
     
     while(true){
          cout << "\nViper_Electronics_Oscillators: ";
          cin >> sel;
          req.IN_History(sel);
	  req.univSelec(sel,sel);

	  if(sel == "freq")
	  {
		  cout << "\n    Enter the inductance(henrys) of the coil: ";
		  cin >> L;
		  cout << "    Enter the capacitance(f) of the capacitor: ";
		  cin >> C;

		  ans = 1.0 / (2.0 * pi * sqrt(L * C));
		  cout << "\nThe frequency of this circut is: " << ans << "Hz";
	  }
	  if(sel == "henry")
	  {
		  cout << "\n    Enter the capacitance(f) of the capacitor: ";
		  cin >> C;
		  cout << "    Enter the frequency(Hz) of the ocilator: ";
		  cin >> Hz;

		  ans = pow(( pow(Hz, -1.0)/ (2 * pi)), 2.0) / C;
		  cout << "\nThe inductance of this circut is: " << ans << " henrys";
	  }
	  if(sel == "cap")
	  {
		  cout << "\n    Enter the inductance(henrys) of the coil: ";
		  cin >> L;
		  cout << "    Enter the frequency(Hz) of the ocilator: ";
		  cin >> Hz;

		  ans = pow(( pow(Hz, -1.0)/ (2 * pi)), 2.0) / L;
		  cout << "\nThe inductance of this circut is: " << ans << " farads";
	  }
	  if(sel == "help" || sel == "ls")
	  {
		  cout << "________________________________________________________\n"
		       << setw(15) << "freq" << setw(40) << "Find frequency of an ocilator citcut\n"
		       << setw(15) << "henry" << setw(40) << "Find inductance of an ocilator circut\n"
		       << setw(15) << "cap" << setw(40) << "Find capacitance of an ocilator circut\n"
                        
                       << setw(15) << "calc" << setw(40) << "simple calculater\n"
                       << setw(15) << "clear" << setw(40) << "Clear screen\n"
                       << setw(15) << "cd"<< setw(40) << "Exit program\n";
                        
                   }
          if(sel == "clear"||sel == "Clear"||sel == "CCLEAR")
                 req.clear();  
          if(sel == "calc"||sel == "Calc"||sel == "CALC")
                 req.calc();
          if(sel == "cd"||sel == "CD")
                 break;
     }
}
/////////////////////////////////////////////////////////////////////////////
void elect::impedan()
{
	string sel;
	double r, l, c, hz, ans;

	while(true){
		cout << "\nViper_Electronics_impedances: ";
		cin >> sel;
		req.IN_History(sel);
		req.univSelec(sel,sel);

		if(sel == "cap")
		{
			cout << "    Enter the capacitance: ";
			c = req.VDO();
			cout << "    Enter the Frequency(hz): ";
			hz = req.VDO();

			ans = 1 / (2 * pi * hz * c);
			cout << "The impedance of the circut is: " << ans << endl;
		}
		if(sel == "henry")
		{
			cout << "    Enter the inductance: ";
			l = req.VDO();
			cout << "    Enter the Frequency(hz): ";
			hz = req.VDO();

			ans = 2 * pi * l * hz;
			cout << "The impedance of the circut is: " << ans << endl;
		}
		if(sel == "help" || sel == "ls")
		{
			cout << "________________________________________________________\n"
			      << setw(15) << "cap" << setw(40) << "Find impedance of a capacitor\n"
			      << setw(15) << "henry" << setw(40) << "Find the impedance of a inductor\n"

			      << setw(15) << "calc" << setw(40) << "simple calculater\n"
			      << setw(15) << "clear" << setw(40) << "Clear screen\n"
			      << setw(15) << "cd"<< setw(40) << "Exit program\n";
                        
		}
		if(sel == "clear"||sel == "Clear"||sel == "CCLEAR")
			req.clear();  
		if(sel == "calc"||sel == "Calc"||sel == "CALC")
			req.calc();
		if(sel == "cd"||sel == "CD")
			break;
	}
}
////////////////////////////////////////////////////////////////////////////////
void elect::npnamp()
{
	double ans, r1, r2, v, ic,ve;
	string sel;

	while(true){
		cout << "\nViper_Electronics_NPN-Amplifiers: ";
		cin >> sel;
		req.IN_History(sel);
		req.univSelec(sel,sel);

		if(sel == "vb"){
			cout << "             r1    <==   r2\n"
			     << "       + ---^^^^------+----^^^^----+\n"
			     << "       |              |            |\n"
			     << "       |   r3     +---+---+  <=    |\n"
			     << "   +-- +--^^^^-+--|n| p |n|--^^^^--+--| Vcc\n"
			     << "   |   |       |  +-------+   r4   |\n"
			     << "   |   +---||--+"
			     << "   |\n"
			     << " ground\n\n";

			cout << "    Enter the value for the first resistor: ";
			r1 = req.VDO();
			cout << "    Enter the value for the second resistor: ";
			r2 = req.VDO();
			cout << "    Enter the voltage of the amp circut: ";
			v = req.VDO();

			ans = (r1 / (r1 * r2)) * v;
			cout << "the voltage entering the base of the transistor is: " << ans << endl;
		}
		if(sel == "henry"){
			cout << "Enter the emiter voltage:   ";
			cin >> ve;
			cout << "Enter the resistance of r3: ";
			cin >> r1;

			ic = ve / r1;

			cout << "emiter current is: " << ic << endl;
		}
		if(sel == "ve"){
			cout << "Enter the voltage entering the base(VB): ";
			cin >> v;

			cout << "the emiter voltage is: " << (v - 0.7) << " mA\n";
		}
		if(sel == "vc"){
			cout << "Enter the volatage from the power suply: ";
			cin >> v;
			cout << "Enter the current from the emiter: ";
			cin >> ic;
			cout << "Enter the resistance of ";

		}
		if(sel == "help" || sel == "ls")
		{
			cout << "________________________________________________________\n"
			      << setw(15) << "henry" << setw(40) << "Find the impedance of a inductor\n"
			      << setw(15) << "vc" << setw(40) << "Find voltage entering the colector\n"
			      << setw(15) << "vb" << setw(40) << "Find voltage entering into the base\n"
			      << setw(15) << "ve" << setw(40) << "Find voltage emited from the base\n"

			      << setw(15) << "calc" << setw(40) << "simple calculater\n"
			      << setw(15) << "clear" << setw(40) << "Clear screen\n"
			      << setw(15) << "cd"<< setw(40) << "Exit program\n";
                        
		}
		if(sel == "clear"||sel == "Clear"||sel == "CCLEAR")
			req.clear();  
		if(sel == "calc"||sel == "Calc"||sel == "CALC")
			req.calc();
		if(sel == "cd"||sel == "CD")
			break;
	}
}
////////////////////////////////////////////////////////////////////////////////
void elect::help()
{
     cout << "________________________________________________________\n";
     cout << setw(15) << "horse" << setw(40) << "Horsepower from AC/DC moters\n"
          << setw(15) << "imped" << setw(40) << "Find impedance\n"
          << setw(15) << "kilo" << setw(40) << "Find killowats\n"
          << setw(15) << "kiloAm" << setw(40) << "Find killovolt amperes\n"
          << setw(15) << "imped" << setw(40) << "Find impedance of a circit\n"
          << setw(15) << "oscillat" << setw(40) << "Oscillator/Resonant circit problems\n"
	  << setw(15) << "impedan" << setw(40) << "Find impedance of componets at dif hz\n"
          
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
elect::~elect()
{
	// insert your code here
}
