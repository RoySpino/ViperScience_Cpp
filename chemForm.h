#ifndef FORMULA_H
#define FORMULA_H
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

class formula
{
	private:
		char *compound;
		string *element,*ionArr, *Split;
		string temp;
		int fSize, numberOfAtoms,
		    ionLim;
		double MOL;

		struct Ions{
			string ionName;
			int ionCharge;
			int metalCharge;
		};
		struct periodicTable{
			string name;
			double w;
		};
		periodicTable pt[119];
		Ions ions[65];

		//-------------------------------
		void setIonArr(){
			int lim=0, tmp;
			string f;

			// count the number of ions
			f.assign(compound);
			for(int i=0; i<61; i++){
				tmp = f.find(ions[i].ionName);
				if(tmp>=0 and tmp <f.size())
					lim++;
				// reset temp
				tmp=-1;
			}

			// make new ion array
			ionArr = new string[lim];
			ionLim = lim;
			
			// load ion array
			for(int i=0, index=0; i<61; i++){
				tmp = f.find(ions[i].ionName);
				if(tmp>=0 and tmp <f.size())
					ionArr[index++] = ions[i].ionName;
			}
		}

	public:
		// defalt constrctor
		formula(const char in[] = "H")
		{
			if(pt[0].name != "H")
				tableFiller();

			MOL = 0;
			fSize = 0;
			int s = strlen(in) +1;
			compound = new char[s];
			strcpy(compound, in);

			temp.assign(compound);

			MOL = doMolMas(temp);

			// count number of elements
			for(int i=0; i< s; i++)
				if(compound[i] >= 'A' and compound[i] <= 'Z')
					fSize++;

			element = new string[fSize];
			do_BREAK_formula(temp, fSize);
			numberOfAtoms = doEleCount(temp);
			ionArr = NULL;
			ionLim = 0;
		}
		////////////////////////////////////////////////////////////////////////////////////////////
		// copy constructer
		formula(const formula &c)
		{
			if(pt[0].name != "H")
				tableFiller();

			strcpy(this->compound, c.compound);
			memcpy(this->element, c.element, c.fSize);
			this->temp = c.temp;
			this->fSize = c.fSize;
			this->numberOfAtoms = c.numberOfAtoms;
			this->MOL = c.MOL;
			ionArr = NULL;
			ionLim = 0;
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		void remove(int posit, int u)
		{
			char *temp;
			int newSize = strlen(compound) - u;
			temp = new char[newSize];

			for(int i=0; i< posit; i++)
				temp[i] = compound[i];
			for(int i=posit; i< newSize; i++)
				temp[i] = compound[i+u];

			delete [] compound;

			compound = new char[newSize];
			for(int i=0; i<newSize; i++)
				compound[i] = temp[i];

			delete [] temp;
		}
		/////////////////////////////////////////////////////////////////////////////////////
		// assighnment operator
		const formula &operator =(formula &right){
			// checks for self assighnemt
			if(&right == this)
				return *this;
			// if not the same then assighn right 
			// componets to this class
			else{
				numberOfAtoms = right.count();
				delete [] this->element;
				delete [] this->compound;
				this->element = new string[right.fSize];
				this->compound = new char[ strlen(right.compound)];
				// assigne rights elements to this
				// element array
				for(int i=0; i<right.fSize; i++)
					this->element[i] = right.element[i];

				for(int i=0; i<right.fSize; i++)
					this->compound[i] = right.compound[i];

				this->fSize = right.fSize;
				return *this;
			}
		}
		const formula &operator =(string &right){
			MOL = 0;
			fSize = 0;
			int s = right.size() +1;

			// delete the array if it is filled
			if(compound != NULL)
				delete [] compound;

			compound = new char[s];
			strcpy(compound, right.data());

			temp.assign(compound);
			MOL = doMolMas(temp);

			// count number of elements
			for(int i=0; i< s; i++)
				if(compound[i] >= 'A' and compound[i] <= 'Z')
					fSize++;

			element = new string[fSize];
			do_BREAK_formula(temp, fSize);
			numberOfAtoms = doEleCount(temp);

			return *this;
		}
		//////////////////////////////////////////////////////////////////////////////////////////
		bool operator ==(const formula &sec)
		{
			bool pass;
			((this->temp == sec.temp) ? pass = true: pass = false);
			return pass;
		}
		bool operator !=(const formula &sec)
		{
			bool pass;
			((this->temp != sec.temp) ? pass = true: pass = false);
			return pass;
		}
		bool operator ==(const char a[])
		{
			bool pass;
			((strcmp(this->compound, a) == 1) ? pass = true: pass = false);
			return pass;
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////
		bool operator >(const formula &sec)
		{
			bool pass;
			((this->temp > sec.temp) ? pass = true: pass = false);
			return pass;
		}
		bool operator <(const formula &sec)
		{
			bool pass;
			((this->temp < sec.temp) ? pass = true: pass = false);
			return pass;
		}
		bool operator >(const char a[])
		{
			bool pass;
			((strcmp(compound, a) > 1) ? pass = true: pass = false);
			return pass;
		}
		bool operator <(const char a[])
		{
			bool pass;
			((strcmp(compound, a) < 1) ? pass = true: pass = false);
			return pass;
		}
		//////////////////////////////////////////////////////////////////////////////////////////
		// returns the number of elements in compound
		int size()
		{
			return fSize;
		}
		/////////////////////////////////////////////////////////////////////////////////////////
		// reterns a c++ string of formula
		string str()
		{
			return temp;
		}
		//////////////////////////////////////////////////////////////////////////////////////////
		string *list()
		{
			return element;
		}
		//////////////////////////////////////////////////////////////////////////////////////////
		// get values through []
		string &operator [](const int &i)
		{
			int index;
			((i < 0) ? index = 0: ((i > fSize) ? index =fSize-1: index =i));

			return element[index];
		}
		// output the contence of formula
		friend ostream &operator <<(ostream &out, const formula &F)
		{
			out << F.compound;

			return out;
		}
		///////////////////////////////////////////////////////////////////////////////////////////
		void *do_BREAK_formula(string raw, int h)
		{
			string f ="*******";
			char *mult;
			double cash =0, tx =0, stow;
			int index =0, K=0;


			element = new string[h];
			//cout << "\nEnter the molecular formula: ";
			//getline(cin, formula);
			f = raw;


			// fills string with *
			for(int i=0; i<raw.size(); i++)
				f[i] = '*';


			// brakes down formula
			for(int i=0; i<raw.size(); i++)
			{
				mult = new char[ raw.size() ];
				for(i; i<raw.size(); i++)
				{
					mult[i] = raw[i];
					f[i] = raw[i];


					if(raw[i] >='0'&&raw[i] <='9')
					{
						f[i] = '*';
					}
					if(raw[i+1] >='A'&&raw[i+1] <='Z'||raw[i+1] =='\0')
					{
						// Element isolater
						for(int v=0; v<raw.size(); v++)
						{
							if(f[index] != '*')
								index ++;
							else
								f.erase(index,1);
						}
						element[K] = f;

						K++;


						index = 0; // Resets index for next elemtnt

						f = raw;	
						for(int w=0; w<raw.size(); w++)
						{
							f[w] = '*';
							mult[w] = 0;
						}
						break;
					}
				}
			}
			delete [] mult;
		}
		///////////////////////////////////////////////////////////////////////////////////////
		string *chop(){
			doChopFormula(temp,numberOfAtoms);
			return Split;
		}
		void *doChopFormula(string raw, int h)
		{
			string f ="";
			double cash =0, tx =0, stow;
			int index =0, K=0;

			Split = new string[h];
			//f = raw;

			// brakes down formula
			for(int i=0; i<raw.size(); i++)
			{
				f.push_back(raw[i] );

				if(raw[i+1] >='A'&&raw[i+1] <='Z'||raw[i+1] =='\0')
				{
					// Element isolater
					Split[K] = f;

					K++;

					f=""; // Resets index for next elemtnt
				}
			}
		}
		//////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////
		double mol()
		{
			return MOL;
		}
		///////////////////////////////////////////////////////////////////////////////////////
		int count()
		{
			return numberOfAtoms;
		}
		////////////////////////////////////////////////////////////////////////////////////////
		friend istream &operator >>(istream &s, formula &h)
		{
			s >> h.temp;
			int newSize = h.temp.size() +1;

			h.compound = new char[newSize];
			strcpy(h.compound, h.temp.data());


			h.fSize =0;
			// count number of elements
			for(int i=0; i< strlen(h.compound)+1; i++)
				if(h.compound[i] >= 'A' and h.compound[i] <= 'Z')
					h.fSize++;

			if(&(h.element[0]) != 0)
				delete [] h.element;
			h.element = new string[h.fSize];
			h.do_BREAK_formula(h.temp, h.fSize);
			h.MOL = h.doMolMas(h.temp);
			h.numberOfAtoms = h.doEleCount(h.temp);

			return s;
		}
		//////////////////////////////////////////////////////////////////////////////////////
		int doIonCount(string ion){
			int ionCount=0, locAt, skip;
			string tmp, dig="";

			// find ion in the compound
			tmp.assign(compound);
			locAt = tmp.find(ion);
			skip = ion.size()+1;

			// count the ion if found
			if(locAt >0 and locAt<tmp.size()){
				if(tmp[locAt+skip] >='0' and tmp[locAt+skip] <= '9')
					dig.push_back(tmp[locAt+skip]);
				else
					return 1;
				if(tmp[locAt+skip+1] >='0' and tmp[locAt+skip+1] <= '9'){
					dig.push_back(tmp[locAt+skip+1]);
				}
				ionCount = int(strtod(dig.data(), NULL));
				dig ="";
				return ionCount;
			}
			return 0;
		}
		double sumIonCharge(){
			double charge=0;
			setIonArr();

			for(int i=0; i<ionLim; i++)
				for(int u=0; u<61; u++)
					if(ionArr[i] == ions[u].ionName)
						charge += ions[u].ionCharge;
			return charge;
		}
		int getIonC(int ind){
			for(int i=0; i<ionLim; i++){
				for(int u=0; u<61; u++)
					if(ionArr[i]==ions[u].ionName)
						return ions[u].ionCharge;
			}
		}
		int doEleCount(string raw)
		{
			string f ="*******",
			       split;
			char *mult;
			double cash =0, tx =0, stow,
			       Complex =0, numComplex;
			int index =0;

			f = raw;

			//////////////////////////////////////////////////////////
			// count complex compounds
			if(raw.find('(') >=0 && raw.find('(') <= raw.size()){
				split = splitForm(raw, numComplex);
				Complex = doEleCount(split);
				Complex *= numComplex;

				int loc1 = raw.find('('),
				    loc2 = raw.find(')');
				if(loc2 == 0)
					raw.erase(loc1, loc2);
			}
			///////////////////////////////////////////////////////////	
			f = raw;

			mult = new char[ raw.size() ];
			// fills string with *
			for(int i=0; i<raw.size(); i++)
			{
				f[i] = '*';
				mult[i] = ' ';
			}

			// brakes down formula
			for(int i=0; i<raw.size(); i++)
			{
				for(i; i<raw.size(); i++)
				{
					mult[i] = raw[i];
					f[i] = raw[i];

					if(raw[i] >='0'&&raw[i] <='9')
					{
						f[i] = '*';
					}
					if(raw[i+1] >='A'&&raw[i+1] <='Z'||raw[i+1] =='\0')
					{
						// Element isolater
						for(int v=0; v<raw.size(); v++)
						{
							if(f[index] != '*')
								index ++;
							else
								f.erase(index,1);
						}

						index = 0; // Resets index for next elemtnt


						for(int d=0; d< raw.size(); d++)
						{
							if(mult[d] >='0'&&mult[d] <='9')
								d++;
							else
								mult[d] = ' ';
						}
						
						// insted of geting elements mass use 1 to count element symbol
						stow = 1; 
						
						// tx is now used to count group of symbols ex 'O3' tx = 3
						tx = strtod(mult, NULL);
						if(tx == 0)
							tx = 1;

						cash += stow * tx; // Count all elements


						f = raw;	
						for(int i=0; i<raw.size(); i++)
							f[i] = '*';
						for(int i=0; i<raw.size(); i++)
							mult[i] = ' ';

						break;
					}
				}
			}
			delete [] mult;
			return int(cash + Complex);
		}
		///////////////////////////////////////////////////////////////////////////////////////////
		double doMolMas(string raw)
		{
			string f ="*******",
			       split;
			char *mult;
			double cash =0, tx =0, stow,
			       Complex =0, numComplex;
			int index =0;

			/////////////////////////////////////////////////////////
			// calculate complex compounds
			if(raw.find('(') >=0 && raw.find('(') <= raw.size()){
				split = splitForm(raw, numComplex);
				Complex = doMolMas(split);
				Complex *= numComplex;

				int loc1 = raw.find('('),
				    loc2 = raw.find(')');
				if(loc2 >= 0&& loc2 <= raw.size())
					raw.erase(loc1, loc2);
			}
			f = raw;
			/////////////////////////////////////////////////////////

			mult = new char[ raw.size() ];
			// fills string with *
			for(int i=0; i<raw.size(); i++)
			{
				f[i] = '*';
				mult[i] = ' ';
			}

			// brakes down formula
			for(int i=0; i<raw.size(); i++)
			{
				for(i; i<raw.size(); i++)
				{
					mult[i] = raw[i];
					f[i] = raw[i];

					if(raw[i] >='0'&&raw[i] <='9')
					{
						f[i] = '*';
					}
					if(raw[i+1] >='A'&&raw[i+1] <='Z'||raw[i+1] =='\0')
					{
						// Element isolater
						for(int v=0; v<raw.size(); v++)
						{
							if(f[index] != '*')
								index ++;
							else
								f.erase(index,1);
						}

						index = 0; // Resets index for next elemtnt


						for(int d=0; d< raw.size(); d++)
						{
							if(mult[d] >='0'&&mult[d] <='9')
								d++;
							else
								mult[d] = ' ';
						}

						stow = check(f); // checks element to pt

						tx = strtod(mult, NULL); 
						if(tx == 0)
							tx = 1;

						cash += stow * tx;


						f = raw;	
						for(int i=0; i<raw.size(); i++)
							f[i] = '*';
						for(int i=0; i<raw.size(); i++)
							mult[i] = ' ';

						break;
					}
				}
			}
			delete [] mult;
			return cash + Complex;
		}
		string splitForm(string in, double &mult)
		{
			char *inParen;
			char multArr[2];
			int count=0;
			string split;

			inParen = new char[in.size()+5];

			// count the open perenthasies
			for(int i=0; i <in.size(); i++)
				if(in[i] == '(')
					count++;

			// isolate the formula within the perenthesies
			for(int i=0; i <in.size(); i++)
			{
				if(in[i] == '(')
					for(int u=0; u <in.size(); u++)
					{
						if(in[u+i+1] == ')')
							count--;
						if(inParen[u] != in[u+i+1])
							inParen[u] = '\0';
						if(count ==0)
							break;
						else
							inParen[u] = in[u+i+1];
					}
				if(count == 0)
					break;
			}

			// get the number of the complex molocules
			if(in[in.find(')')+1] >='0' and in[in.find(')')+1] <='9'){
				multArr[0] = in[in.find(')') + 1];
				if(in[in.find(')')+2] >= '0' and in[in.find(')')+2] <='9')
					multArr[1] = in[in.find(')') +2];
			}

			if(multArr[0] == '\0')
				multArr[0] ='1';
			// convert multArr from a string to a number
			mult = strtod(multArr, NULL);

			split.assign(inParen);

			delete [] inParen;
			return split;
		}
		///////////////////////////////////////////////////////////////////////////////////////
		double check(string c)// checks puriotic table and retrives atomic weight
		{
			double out =1; 

			for(int i=0; i <118; i++)
				if(c == pt[i].name)
					out = pt[i].w;

			return out;
		}
		///////////////////////////////////////////////////////////////////////////////////////
		void tableFiller()
		{
			pt[0].name = "H" ;   pt[0].w = 1.008 ;
			pt[1].name = "He";   pt[1].w = 4.003 ;
			pt[2].name = "li";   pt[2].w = 6.941 ;
			pt[3].name = "Be";   pt[3].w = 9.012 ;
			pt[4].name = "B" ;   pt[4].w = 10.81 ;
			pt[5].name = "C";    pt[5].w = 12.01 ;
			pt[6].name = "N";    pt[6].w = 14.01 ;
			pt[7].name = "O";    pt[7].w = 16 ;
			pt[8].name = "F" ;   pt[8].w = 19 ;
			pt[9].name = "Ne";   pt[9].w = 20.18 ;

			pt[10].name = "Na";  pt[10].w = 22.99 ;
			pt[11].name = "Mg";  pt[11].w = 24.31;
			pt[12].name = "Al" ; pt[12].w = 26.98 ;
			pt[13].name = "Si";  pt[13].w = 28.09;
			pt[14].name = "P";   pt[14].w = 30.97;
			pt[15].name = "S";   pt[15].w = 32.07;
			pt[16].name = "Cl" ; pt[16].w = 35.05 ;
			pt[17].name = "Ar";  pt[17].w = 39.95;
			pt[18].name = "K";   pt[18].w = 39.10;
			pt[19].name = "Ca";  pt[19].w = 40.08 ;

			pt[20].name = "Sc" ; pt[20].w = 44.96 ;
			pt[21].name = "Ti";  pt[21].w = 47.88 ;
			pt[22].name = "V";   pt[22].w =  50.94;
			pt[23].name = "Cr";  pt[23].w = 52 ;
			pt[24].name = "Mn";  pt[24].w = 54.94;
			pt[25].name = "Fe";  pt[25].w = 55.85 ;
			pt[26].name = "Co" ; pt[26].w = 58.93 ;
			pt[27].name = "Ni";  pt[27].w = 58.69;
			pt[28].name = "Cu";  pt[28].w =  63.55;
			pt[29].name = "Zn";  pt[29].w = 65.38;

			pt[30].name = "Ga";  pt[30].w = 69.72;
			pt[31].name = "Ge" ; pt[31].w = 72.59;
			pt[32].name = "As";  pt[32].w = 74.92;
			pt[33].name = "Se";  pt[33].w = 78.96;
			pt[34].name = "Br";  pt[34].w = 79.90;
			pt[35].name = "Kr";  pt[35].w = 83.80;
			pt[36].name = "Rb";  pt[36].w = 85.47;
			pt[37].name = "Sr" ; pt[37].w = 87.62;
			pt[38].name = "Y";   pt[38].w = 88.91;
			pt[39].name = "Zr";  pt[39].w = 91.22;

			pt[40].name = "Nb";  pt[40].w = 92.91;
			pt[41].name = "Mo" ; pt[41].w = 95.94;
			pt[42].name = "Te";  pt[42].w = 98;
			pt[43].name = "Ru";  pt[43].w = 101.1;
			pt[44].name = "Rh";  pt[44].w = 102.9;
			pt[45].name = "Pd";  pt[45].w = 106.4;
			pt[46].name = "Ag";  pt[46].w = 107.9;
			pt[47].name = "Cd" ; pt[47].w = 112.4;
			pt[48].name = "In";  pt[48].w = 114.8;
			pt[49].name = "Sn";  pt[49].w = 118.7;

			pt[50].name = "Sb";  pt[50].w = 121.8;
			pt[51].name = "Te" ; pt[51].w = 127.6;
			pt[52].name = "I";   pt[52].w = 126.9;
			pt[53].name = "Xe";  pt[53].w = 131.3;
			pt[54].name = "Cs";  pt[54].w = 132.9;
			pt[55].name = "Ba";  pt[55].w = 137.3;
			pt[56].name = "La";  pt[56].w = 138.9;
			pt[57].name = "Ce" ; pt[57].w = 140.1;
			pt[58].name = "Pr";  pt[58].w = 140.9;
			pt[59].name = "Nd";  pt[59].w = 144.2;

			pt[60].name = "Pm";  pt[60].w = 145;
			pt[61].name = "Sm" ; pt[61].w = 150.4;
			pt[62].name = "Eu";  pt[62].w = 152.0;
			pt[63].name = "Gd";  pt[63].w = 157.3;
			pt[64].name = "Tb";  pt[64].w = 158.9;
			pt[65].name = "Dy";  pt[65].w = 162.9;
			pt[66].name = "Ho";  pt[66].w = 164.9;
			pt[67].name = "Er" ; pt[67].w = 167.3;
			pt[68].name = "Tm";  pt[68].w = 168.9;
			pt[69].name = "Yb";  pt[69].w = 173.0;

			pt[70].name = "Lu";  pt[70].w = 175.0;
			pt[71].name = "Hf" ; pt[71].w = 178.5;
			pt[72].name = "Ta";  pt[72].w = 180.9;
			pt[73].name = "W";   pt[73].w = 183.9;
			pt[74].name = "Re";  pt[74].w = 186.2;
			pt[75].name = "Os";  pt[75].w = 190.2;
			pt[76].name = "Ir";  pt[76].w = 192.2;
			pt[77].name = "Pt" ; pt[77].w = 195.1;
			pt[78].name = "Au";  pt[78].w = 197.0;
			pt[79].name = "Hg";  pt[79].w = 200.6;

			pt[80].name = "Tl";  pt[80].w = 204.4;
			pt[81].name = "Pb" ; pt[81].w = 207.2;
			pt[82].name = "Bi";  pt[82].w = 209.0;
			pt[83].name = "Po";  pt[83].w = 209;
			pt[84].name = "At";  pt[84].w = 210;
			pt[85].name = "Rn";  pt[85].w = 222;
			pt[86].name = "Fr";  pt[86].w = 223;
			pt[87].name = "Ra" ; pt[87].w = 226;
			pt[88].name = "Ac";  pt[88].w = 227;
			pt[89].name = "Th";  pt[89].w = 232.0;

			pt[90].name = "Pa";  pt[99].w = 231;
			pt[91].name = "U" ;  pt[91].w = 238.0;
			pt[92].name = "Np";  pt[92].w = 237;
			pt[93].name = "Pu";  pt[93].w = 244;
			pt[94].name = "Am";  pt[94].w = 243;
			pt[95].name = "Cm";  pt[95].w = 247;
			pt[96].name = "Bk";  pt[96].w = 247;
			pt[97].name = "Cf" ; pt[97].w = 251;
			pt[98].name = "Es";  pt[98].w = 252;
			pt[99].name = "Fm";  pt[99].w = 257;

			pt[100].name = "Md";  pt[100].w = 258;
			pt[101].name = "No" ; pt[101].w = 259;
			pt[102].name = "Lr";  pt[102].w = 260;
			pt[103].name = "Rf";  pt[103].w = 261;
			pt[104].name = "Db";  pt[104].w = 262;
			pt[105].name = "Sg";  pt[105].w = 263;
			pt[106].name = "Bh";  pt[106].w = 264;
			pt[107].name = "Hs";  pt[107].w = 265;
			pt[108].name = "Mt";  pt[108].w = 268;
			pt[109].name = "Ds";  pt[109].w = 271;

			pt[110].name = "Rg";  pt[110].w = 272;
			pt[111].name = "Cn" ; pt[111].w = 285;
			pt[112].name = "Uut"; pt[112].w = 286;
			pt[113].name = "Fl";  pt[113].w = 289;
			pt[114].name = "Uup"; pt[114].w = 288;
			pt[115].name = "Lv";  pt[115].w = 293;
			pt[116].name = "Uus"; pt[116].w = 294;
			pt[117].name = "Uuo"; pt[117].w = 294;
			pt[118].name = "Uud"; pt[118].w = 295;

			ions[0].ionName = "Li"; ions[0].ionCharge = 1; ions[0].metalCharge = 1;
			ions[1].ionName = "Na"; ions[1].ionCharge = 1; ions[1].metalCharge = 1;
			ions[2].ionName = "K";  ions[2].ionCharge = 1; ions[2].metalCharge = 1;
			ions[3].ionName = "Rb"; ions[3].ionCharge = 1; ions[3].metalCharge = 1;
			ions[4].ionName = "Cs"; ions[4].ionCharge = 1; ions[4].metalCharge = 1;
			ions[5].ionName = "Fr"; ions[5].ionCharge = 1; ions[5].metalCharge = 1;
			ions[6].ionName = "Be"; ions[6].ionCharge = 2; ions[6].metalCharge = 2;
			ions[7].ionName = "Mg"; ions[7].ionCharge = 2; ions[7].metalCharge = 2;
			ions[8].ionName = "Ca"; ions[8].ionCharge = 2; ions[8].metalCharge = 2;
			ions[9].ionName = "Sr"; ions[9].ionCharge = 2; ions[9].metalCharge = 2;

			ions[10].ionName = "Ba";ions[10].ionCharge = 2; ions[10].metalCharge = 2;
			ions[11].ionName = "Ra";ions[11].ionCharge = 2; ions[11].metalCharge = 2;
			ions[12].ionName = "B"; ions[12].ionCharge = 3; ions[12].metalCharge = 3;
			ions[13].ionName = "Al";ions[13].ionCharge = 3; ions[13].metalCharge = 3;
			ions[14].ionName = "Ga";ions[14].ionCharge = 3; ions[14].metalCharge = 3;
			ions[15].ionName = "Ln";ions[15].ionCharge = 3; ions[15].metalCharge = 3;
			ions[16].ionName = "Ti";ions[16].ionCharge = 3; ions[16].metalCharge = 3;
			ions[17].ionName = "Uut";ions[17].ionCharge= 3; ions[17].metalCharge = 3;
			ions[18].ionName = "Ag";ions[18].ionCharge = 1; ions[18].metalCharge = 1;
			ions[19].ionName = "Zn";ions[19].ionCharge = 2; ions[19].metalCharge = 2;

			ions[20].ionName = "NH4";ions[20].ionCharge = 1;  ions[20].metalCharge = 1;
			ions[21].ionName = "ClO4";ions[21].ionCharge = -1; ions[21].metalCharge = -1;
			ions[22].ionName = "ClO3";ions[22].ionCharge = -1; ions[22].metalCharge = -1;
			ions[23].ionName = "C2H3O2";ions[23].ionCharge = -1; ions[23].metalCharge = -1;
			ions[24].ionName = "SO4";ions[24].ionCharge = -2; ions[24].metalCharge = -2;
			ions[25].ionName = "CO3";ions[25].ionCharge = -2; ions[25].metalCharge = -2;
			ions[26].ionName = "PO4";ions[26].ionCharge = -3; ions[26].metalCharge = -3;
			ions[27].ionName = "CrO4";ions[27].ionCharge = -2; ions[27].metalCharge = -2;
			ions[28].ionName = "AsO4";ions[28].ionCharge = -3; ions[28].metalCharge = -3;
			ions[29].ionName = "OH";ions[29].ionCharge = -1; ions[29].metalCharge = -1;

			ions[30].ionName = "NO3";ions[30].ionCharge = -1; ions[30].metalCharge = -1;
			ions[31].ionName = "C2O4";ions[31].ionCharge = -2; ions[31].metalCharge = -2;
			ions[32].ionName = "SO3";ions[32].ionCharge = -2; ions[32].metalCharge = -2;
			ions[33].ionName = "PO4";ions[33].ionCharge = -3; ions[33].metalCharge = -3;
			ions[34].ionName = "ClO2"; ions[34].ionCharge = -1; ions[34].metalCharge = -1;
			ions[35].ionName = "ClO";ions[35].ionCharge = -1; ions[35].metalCharge = -1;
			ions[36].ionName = "CN";ions[36].ionCharge = -1; ions[36].metalCharge = -1;
			ions[37].ionName = "NO2";ions[37].ionCharge = -1; ions[37].metalCharge = -1;
			ions[38].ionName = "Cr2O7";ions[38].ionCharge = -2; ions[38].metalCharge = -2;
			ions[39].ionName = "CrO4"; ions[39].ionCharge = -2; ions[39].metalCharge = -2;

			ions[40].ionName = "MnO4"; ;ions[40].ionCharge = -1;ions[40].metalCharge = -1;
			ions[41].ionName = "NCS";ions[41].ionCharge = -1; ions[41].metalCharge = -1;
			ions[42].ionName = "H"; ions[42].ionCharge = 1;  ions[42].metalCharge = 1;
			ions[43].ionName = "F"; ions[43].ionCharge = -1; ions[43].metalCharge = -1;
			ions[44].ionName = "Cl"; ions[44].ionCharge = -1; ions[44].metalCharge = -1;
			ions[45].ionName = "Br"; ions[45].ionCharge = -1; ions[45].metalCharge = -1;
			ions[46].ionName = "I";  ions[46].ionCharge = -1; ions[46].metalCharge = -1;
			ions[47].ionName = "At"; ions[47].ionCharge = -1; ions[47].metalCharge = -1;
			ions[48].ionName = "Uus";ions[48].ionCharge = -1; ions[48].metalCharge = -1;
			ions[49].ionName = "O";  ions[49].ionCharge = -2; ions[49].metalCharge = -2;

			ions[50].ionName = "S";ions[50].ionCharge = -2; ions[50].metalCharge = -2;
			ions[51].ionName = "Se";ions[51].ionCharge = -2; ions[51].metalCharge = -2;
			ions[52].ionName = "Te";ions[52].ionCharge = -2; ions[52].metalCharge = -2;
			ions[53].ionName = "Po";ions[53].ionCharge = -2; ions[53].metalCharge = -2;
			ions[54].ionName = "Lv";ions[54].ionCharge = -2; ions[54].metalCharge = -2;
			ions[55].ionName = "N";ions[55].ionCharge = -3; ions[55].metalCharge = -3;
			ions[56].ionName = "P";ions[56].ionCharge = -3; ions[56].metalCharge = -3;
			ions[57].ionName = "As"; ions[57].ionCharge = -3; ions[57].metalCharge = -3;
			ions[58].ionName = "Sb"; ions[58].ionCharge = -3; ions[58].metalCharge = -3;
			ions[59].ionName = "Bi"; ions[59].ionCharge = -3; ions[59].metalCharge = -3;

			ions[60].ionName = "Uup"; ions[60].ionCharge = -3; ions[60].metalCharge = -3;
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////
		~formula()
		{
			delete [] element;
			delete [] compound;
			if(ionArr != NULL)
				delete [] ionArr;
		}
};
#endif
/*

   friend istream &operator >>(istream &s, formula &h)
   {
   s >> h.compound;
   return s;
   }*/
