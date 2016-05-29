#include "econ.h"
#include "vipLl.h"
#include "Resor.h"
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

resor resorEcon;

econ::econ(){
}
void econ::infl(){
	string sel;
	int blim, plim, lim;
	double base;
	double *data, *basket, 
	       *per, *out;

	while(true){
		cout << "\nViper_Econ_Inflation: ";
		cin >> sel;
		resorEcon.IN_History(sel);
		resorEcon.univSelec(sel,sel);


		if(sel == "infrat"){
getbsk:
			cout << "    Enter the number of items in the basket: ";
			blim = resorEcon.VInt();
			try{ basket = new double[blim];}catch(bad_alloc){
				cout <<"unable to make set try a smaller number\n"; goto getbsk; }

getdps:
			cout << "    Enter the number of periods in the series: ";
			lim = resorEcon.VInt();
			plim = lim;
			plim *= blim;
			try{ data = new double[plim]; 
				per = new double[lim];
				out = new double[lim];}catch(bad_alloc){
					cout <<"unable to make set try a smaller number\n"; goto getdps; }

				for(int i=0; i< blim; i++){
					cout << "      item" << (i+1) << " ";
					cin >> basket[i];
				}
				for(int i=0, sere=0; i< (blim*lim); i++){
					sere += ( ((i%blim)==0)? 1: 0);
					cout << (((i%blim)==0)?"\n\n":"");
					cout << "    ser_" << sere << ": ";
					cin >> data[i];
				}

				for(int i=0, index=0; i<(blim*lim); i++){
					index += (((i%blim)==0)? 1: 0);
					per[index-1] += basket[(i%blim)] * data[i];
				}

				base = per[0];
				for(int i=0; i<lim; i++){
					per[i] = 100*(per[i]/ base);
				}
				for(int i=1; i<lim; i++)
					out[i] = ((per[i] - per[i-1]) / per[i-1]) * 100;

				cout << "\n______________________\n";
				for(int i=1; i<lim; i++)
					cout << "    period"<< i+1 <<": " << out[i] << "%" << endl;

				delete [] data;
				delete [] basket;
		}
		if(sel == "help" or sel == "ls"){
			cout << "________________________________________________________\n"
				<< setw(15) << "infrat" << setw(40) << "Calcualt inflation rates\n"
				//<< setw(15) << "" << setw(40) << "\n"
				<< setw(15) << "calc" << setw(40) << "Scientific calculater\n"
				<< setw(15) << "clear" << setw(40) << "Clear screen\n"
				<< setw(15) << "cd" << setw(40) << "Exit program\n";
		}
		if(sel == "calc")
			resorEcon.calc();
		if(sel == "clear")
			resorEcon.clear();
		if(sel == "cd")
			break;
	}
}
void econ::gdp(){
	string sel;
	int blim, plim, lim;
	double idel, real, nom, ans,
	       nom1, idel1;

	while(true){
		cout << "\nViper_Econ_GDP: ";
		cin >> sel;
		resorEcon.IN_History(sel);
		resorEcon.univSelec(sel,sel);

		if(sel == "ngdb"){
			cout << "    Enter the implicit GDP delator: ";
			idel = resorEcon.VDO();

			cout << "    Enter the real GDP delator: ";
			real = resorEcon.VDO();

			nom = 100 * (idel/real);
			cout << "The nominal GDP is: " << nom << endl;
		}
		if(sel == "rgdb"){
			cout << "    Enter the implicit GDP delator: ";
			idel = resorEcon.VDO();

			cout << "    Enter the nominal GDP delator: ";
			nom = resorEcon.VDO();

			real = 100 * (nom/idel);
			cout << "The real GDP groth is: " << real << endl;
		}
		if(sel == "rgrth"){
			cout << "    Enter nominal GDP of the curent year: ";
			nom = resorEcon.VDO();
			cout << "    Enter real gdp of the preveous year: ";
			real = resorEcon.VDO();

			idel = ((nom - real) /real) * 100;
			cout << "the real GDP groth is: "<< idel << "%\n";
		}
		if(sel == "infl"){
			cout << "    Enter inplicit GDP delator: ";
			nom = resorEcon.VDO();
			cout << "    Enter implicit GDP of the second year: ";
			idel = resorEcon.VDO();

			ans = 100 * ((nom - idel)/ idel);
			cout << "The overal inflation of the two yers is: "<< ans << endl;
		}
		if(sel == "all"){
			cout << "    Enter first nominal GDP: ";
			nom = resorEcon.VDO();
			cout << "    Enter second nominal GDP: ";
			nom1 = resorEcon.VDO();
			cout << "    Enter first nominal GDP: ";
			idel = resorEcon.VDO();
			cout << "    Enter second nominal GDP: ";
			idel1 = resorEcon.VDO();

			real = (nom/idel)*100;
			ans = (((nom1/idel1)*100) - real) / ((nom1/idel1)*100) * 100;

			cout << "Real GDP period 1: " << real << endl
				<< "Real GDP Period 2: " << ((nom1/idel1)*100) << endl
				<< "Real GDP groth:    " << real << endl
				<< "Overal inflation:  " << (((nom1 - nom)/nom)*100) << endl;
		}
		if(sel == "help" or sel == "ls"){
			cout << "________________________________________________________\n"
				<< setw(15) << "ngdp" << setw(40) << "Calculate nominal gdp\n"
				<< setw(15) << "rgdp" << setw(40) << "Calcualte real gdp\n"
				<< setw(15) << "rgrth" << setw(40) << "Calcualte real gdp groth\n"
				<< setw(15) << "infl" << setw(40) << "Calcualte real gdp groth\n"
				<< setw(15) << "all" << setw(40) << "Calcualte all GDP data\n"
				<< setw(15) << "calc" << setw(40) << "Scientific calculater\n"
				<< setw(15) << "clear" << setw(40) << "Clear screen\n"
				<< setw(15) << "cd" << setw(40) << "Exit program\n";
		}
		if(sel == "calc")
			resorEcon.calc();
		if(sel == "clear")
			resorEcon.clear();
		if(sel == "cd")
			break;
	}
}
void econ::consume(){
	string sel, lex;
	int x;
	double a, mpc, eqlib, psh, 
	       delta=-1, tmp;
	vipLl <double>Y;
	vipLl <double>T;
	vipLl <double>C;
	vipLl <double>Yd;
	vipLl <double>I;
	vipLl <double>G;
	vipLl <double>AE;
	vipLl <string>eq;
	vipLl <double>deq;

	Y.add(-1.0);
	while(true){
		cout << "\nViper_Econ_Consumption: ";
		cin >> sel;
		resorEcon.IN_History(sel);
		resorEcon.univSelec(sel,sel);

		if(sel == "caeq"){
			cout << "    Enter all Agrigate income values('~' to end input):\n";
			Y.erase();
			while(true){
				cout << "     >>> ";
				cin >>lex;
				if(lex =="~")
					break;
				psh = strtod(lex.data(), NULL);
				Y.push(psh);
			}

			cout << "    Enter the government tax: ";
			psh = resorEcon.VDO();

			for(int i=0; i<Y.size(); i++)
				T.push(psh);
			for(int i=0; i<Y.size(); i++){
				Yd.push((Y[i]-T[i]));
			}

			cout << "    Enter the autonomous consumption: ";
			a = resorEcon.VDO();
			cout << "    Enter the Marginal prpencity to consume(MPC): ";
			mpc = resorEcon.VDO();

			for(int i=0; i<Y.size(); i++)
				C.push(a + (mpc*Yd[i]));

			cout << "    Enter the planed investement: ";
			psh = resorEcon.VDO();
			for(int i=0; i<Y.size(); i++)
				I.push(psh);
			cout << "    Enter the government spending: ";
			psh = resorEcon.VDO();
			for(int i=0; i<Y.size(); i++)
				G.push(psh);

			for(int i=0; i<Y.size(); i++)
				AE.push(I[i] + G[i] + C[i]);
			for(int i=0; i<Y.size(); i++){
				deq.push( Y[i]-AE[i] );
				eq.push( (deq[i] == 0)?"yes":"no" );
			}
			eqlib = ((-1*mpc) *T[0] +a +I[0] +G[0]) / (1-mpc);
			delta = (delta == -1)? eqlib: delta;

			// print table
			printf("\n%8s%8s%8s%8s%8s%8s%8s%8s%8s\n","ag.in","tax","Yd","C","I","G","AE","Y-AE","eq");
			cout << "________________________________________________________________________\n";
			for(int i=0; i<Y.size(); i++)
				printf("%8g%8g%8g%8g%8g%8g%8g%8g%8s\n", Y[i], T[i], Yd[i], C[i], I[i],
						                       G[i], AE[i],deq[i],eq[i].data());
		}
		if(sel == "cha"){
			if(Y[0] != -1){
				cout << "    Enter the autonomous consumption: ";
				a = resorEcon.VDO();

			}else
				cout << " <<ERROR: must run 'caeq' or 'daeq' command first>>";
		}
		if(sel == "chgs"){
			if(Y[0] != -1){
				G.erase();
				cout << "    Enter the government spending: ";
				psh = resorEcon.VDO();
				for(int i=0; i<Y.size(); i++)
					G.push(psh);

			}else
				cout << " <<ERROR: must run 'caeq' or 'daeq' command first>>";
		}
		if(sel == "chin"){
			if(Y[0] != -1){
				I.erase();
				cout << "    Enter the planed investement: ";
				psh = resorEcon.VDO();
				for(int i=0; i<Y.size(); i++)
					I.push(psh);
			}else
				cout << " <<ERROR: must run 'caeq' or 'daeq' command first>>";
		}
		if(sel == "chmpc"){
			if(Y[0] != -1){
				cout << "    Enter the Marginal prpencity to consume(MPC): ";
				mpc = resorEcon.VDO();
			}else
				cout << " <<ERROR: must run 'caeq' or 'daeq' command first>>";
		}
		if(sel == "chtx"){
			if(Y[0] != -1){
				T.erase();
				cout << "    Enter the government tax: ";
				psh = resorEcon.VDO();

				for(int i=0; i<Y.size(); i++)
					T.push(psh);
			}else
				cout << " <<ERROR: must run 'caeq' or 'daeq' command first>>";
		}
		if(sel == "txmlt"){
			if(Y[0] != -1){
				cout << "the tax multiplyer is: " << ((-1* mpc)/ (1-mpc)) << endl;
			}else
				cout << " <<ERROR: must run 'caeq' or 'daeq' command first>>";
		}
		if(sel == "mps"){
			if(Y[0] != -1){
				cout << "the tax multiplyer is: " << ((1-mpc)) << endl;
			}else
				cout << " <<ERROR: must run 'caeq' or 'daeq' command first>>";
		}
		if(sel == "delta"){
			if(delta != -1){
				cout << "The diffrence between inical Y to current Y is: "
					<< eqlib -delta<< endl;
			}else
				cout << " <<ERROR: must run 'caeq' or 'daeq' command first>>";
		}
		if(sel == "print"){
			if(Y[0] != -1){
				Yd.erase();
				C.erase();
				AE.erase();
				deq.erase();
				eq.erase();
				for(int i=0; i<Y.size(); i++)
					Yd.push(Y[i]-T[i]);
				for(int i=0; i<Y.size(); i++)
					C.push(a + (mpc*Yd[i]));
				for(int i=0; i<Y.size(); i++)
					AE.push(C[i]+ I[i]+G[i]);
				for(int i=0; i<Y.size(); i++){
					deq.push(Y[i] - AE[i]);
					eq.push( (deq[i] == 0)?"yes":"no" );
				}
				delta = (delta == -1)? eqlib: delta;
				printf("\n%8s%8s%8s%8s%8s%8s%8s%8s%8s\n","ag.in","tax","Yd","C","I","G","AE","Y-AE","eq");
				cout << "________________________________________________________________________\n";
				for(int i=0; i<Y.size(); i++){
					printf("%8g%8g%8g%8g%8g%8g%8g%8g%8s\n", Y[i], T[i], Yd[i], C[i], I[i],
							G[i], AE[i],deq[i],eq[i].data());
				}
			}else
				cout << " <<ERROR: must run 'caeq' or 'daeq' command first>>";
		}
		if(sel == "eqal"){
			if(Y[0] != -1){
				eqlib = ((-1*mpc) *T[0] +a +I[0] +G[0]) / (1-mpc);
				cout << "    At the equivilance point Y is: " << eqlib << endl;
			}else
				cout << " <<ERROR: must run 'caeq' or 'daeq' command first>>";
		}
		if(sel == "sneqp"){
			delta = eqlib;
			cout << "    New base equivalence point is: " << delta << endl;
		}
		if(sel == "save"){
			tmp = a + mpc*(eqlib - T[0]);
			tmp = (eqlib - T[0]) - tmp;
			cout << "    savings at equilibrium: " << tmp << endl;
		}
		if(sel == "fcon"){
			if(Y[0] != -1){
				tmp = a + mpc*(eqlib - T[0]);
				cout << "    Consumption at equlibrium: " << tmp << endl;
			}
		}
		if(sel == "smult"){
			if(Y[0] == -1){
				cout << "    Enter the mpc: ";
				cin >> mpc;
			}
			tmp = 1 / (1-mpc);
			cout << "    The savings multiplier is: " << tmp << endl;
		}
		if(sel == "help" or sel == "ls"){
			cout << "________________________________________________________\n"
				<< setw(15) << "delta" << setw(40) << "Find the diff in Ag. income\n"
				<< setw(15) << "caeq" << setw(40) << "Calculate all consum data\n"
				<< setw(15) << "cha" << setw(40) << "Change atonomus consumption rate\n"
				<< setw(15) << "chgs" << setw(40) << "Change gov. spending rate\n"
				<< setw(15) << "chin" << setw(40) << "Change investment rate\n"
				<< setw(15) << "chmpc" << setw(40) << "Change the MPC\n"
				<< setw(15) << "chtx" << setw(40) << "Change tax rate\n"
				<< setw(15) << "eqal" << setw(40) << "calculate equivilance point\n"
				<< setw(15) << "fcon" << setw(40) << "Find consumption at equlibrium\n"
				<< setw(15) << "mps" << setw(40) <<"Find the marginal propencety to save\n"
				<< setw(15) << "print" << setw(40) << "Reprint consumption table\n"
				<< setw(15) << "save" << setw(40) << "Find savings at equilibrium\n"
				<< setw(15) << "sneqp" << setw(40) << "Set new equivilance point\n"
				<< setw(15) << "smult" << setw(40) << "Find spending multiplier\n"
				<< setw(15) << "txmlt" << setw(40) << "Find Tax Multiplyer\n"
				<< setw(15) << "calc" << setw(40) << "Scientific calculater\n"
				<< setw(15) << "clear" << setw(40) << "Clear screen\n"
				<< setw(15) << "cd" << setw(40) << "Exit program\n";
		}
		if(sel == "calc")
			resorEcon.calc();
		if(sel == "clear")
			resorEcon.clear();
		if(sel == "cd")
			break;
	}
}
void econ::help(){
	cout << "________________________________________________________\n"
		<< setw(15) << "consume" << setw(40) << "Consumption function analisis\n"
		<< setw(15) << "gdp" << setw(40) << "GDP calculations\n"
		<< setw(15) << "infl" << setw(40) << "Inflationary statustucs\n"

		<< setw(15) << "calc" << " " << setw(40) << "simple calculater\n"
		<< setw(15) << "cd" << " " << setw(40) << "return to phisics menue\n"
		<< setw(15) << "coatl" << setw(40) << "search for program\n"
		<< setw(15) << "chmod" << " " << setw(40) << "Change subject phisics/chem/trig\n"
		<< setw(15) << "clear" << " " << setw(40) << "Clear screen\n"
		<< setw(15) << "history" << " " << setw(40) << "show most keystrokes\n"
		<< setw(15) << "rec" << setw(40) << "record your notes and observations\n"
		<< setw(15) << "search" << setw(40) << "search for program\n"
		<< setw(15) << "exit" << " " << setw(40) << "Exit program\n";

}
econ::~econ(){
}
