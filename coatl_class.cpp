// Class automatically generated by Dev-C++ New Class wizard

#include "coatl.h" // class's header file
#include "astro.h"
#include "chem.h"
#include "math.h"
#include "viper.h"
#include "elect.h"
#include "econ.h"
#include "Resor.h"
#include "convert.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

resor Qre;

// serch engin control
const int physEnd = 22,
          chemEnd = 34,
          mathEnd = 47,
          elecEnd = 32;
int dirEnd[4] = {22,34,47,32};

// class constructor
coatl::coatl()
{
	bool notDir=true;
	string fromf, prgmName, rootName;
	KEY = new basisRing();
	KEY->root = NULL;
	KEY->next = KEY;
	KEY->before = KEY;

	ringEnd = KEY;
	

	ifstream read(".coatlData.txt");
	if(read){
		while(!read.eof()){
			// read line form file 
			getline(read, fromf);
			// check to see if its not a remark
			if(fromf.find("rem") == string::npos){
				if(fromf[0] == '^'){
					// add new binary Tree 'ROOT'
					newRingEl();
					fromf = fromf.erase(0,1);
					rootName = fromf;
					notDir = false;
				}
				if(fromf[0] == '~'){
					// add node for program name
					fromf = fromf.erase(0,1);
					prgmName = fromf;
					notDir = true;
				}
				// create node with root name, program name and relation
				if(notDir == true)
					newHydraEl(rootName, fromf, prgmName);
			}
		}
		read.close();
	}
}
void coatl::newRingEl()
{
	basisRing *temp = new basisRing();
	temp->root = NULL;

	// add new ring element
	temp->next = KEY;
	temp->before = KEY->before;
	KEY->before->next = temp;
	KEY->before = temp;

	// set ring end variable to new element
	ringEnd = temp;
}
void coatl::newHydraEl( string directory, string relat, string name)
{
	// set the root of new binary tree to the ending ring element
	basisRing *ring = ringEnd;

	// make a new root node for a binary tree if no node exist
	if(ring->root == NULL){
		ring->root = new hydra();

		// set data within Hydra
		ring->root->related = relat;
		ring->root->prgName = name;
		ring->root->dir = directory;

	}else{
		// make new nodes if a root node exits
		hydra *trav = ring->root, *end;
		hydra *temp = new hydra();
		
		//setup node members
		temp->related = relat;
		temp->prgName = name;
		temp->dir = directory;

		// travers the tree to find the end
		while(trav != NULL)
			if(trav->related >relat){
				end = trav;
				trav = trav->right;
			}else{
				end = trav;
				trav = trav->left;
			}

		// assign temp to point to the tree
		temp->before = end;
		// assigh the tree to point to temp
		if(end->related > relat)
			end->right = temp;
		else
			end->left = temp;
	}
}
bool coatl::Find(string in)
{
	basisRing *kRoot = KEY->next;
	bool foundObject = false;
	foundSize=0;
	hydra *findNode;

	while(kRoot->root != NULL){
		findNode = kRoot->root;
		// travers the tree to find the node contaning 'in'
		while(findNode != NULL)
			if(findNode->related == in){
				// return the element if found
				cout << setw(19) << findNode->prgName << setw(20) << findNode->related << setw(21) << findNode->dir << endl;
				//found[foundSize++] = *findNode;
				foundSize++;
				hydraList.add(*findNode);
				foundObject = true;
				
				// continue to find other matching relations
				findNode = findNode->left;
			}else{
				// travel the tree
				if(findNode->related < in)
					findNode = findNode->left;
				else
					findNode = findNode->right;
			}
		// if nothing is found go to the next tree
		kRoot= kRoot->next;
	}
	return foundObject;
}
void coatl::search(string input)
{
	viper vip;
	chem ch;
	math mat;
	
	int i=0,  v=0, x=0,sear, excape =0;
	string find, in, cash;
	
	hydraList.erase();
	Qre.univSelec(input,input);

	cout << "\n__________________________________________________________________"
	     << "\n       Command Name|              About|             Location\n"
	     << "------------------------------------------------------------------\n";
	if(Find(input)){	
		cout << endl;

	///////////////////////////////////////////////////////////////////////////
		cout << "  _________________________________________________________________\n"
		     << " / Do you want run a program (y/n) ";
	
		cin >> find;
		Qre.univSelec(find,find);

		if(find == "yes"||find == "y"){
			cout << "/  Please enter the Command Name: ";
			cin >> find;
			Qre.IN_History(find);
			Qre.univSelec(find,find);
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  GOTO FUNCTION
			/*
			for(int u=0; u<= foundSize; u++){
				if(found[u].prgName == find);{
					goto_class(found[u].dir, find);
					break;
				}
			}
			*/
			for(int u=0; u< foundSize; u++){
				if(hydraList[u].prgName == find){
					cash = hydraList[u].dir;
					Qre.univSelec(cash,cash);
					goto_class(cash, find);
					break;
				}
			}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
              
			cout << endl;
			return;
		}else{
			cout << endl;
			return;
		}
	}
}
//===================================================================================
int binarySearch(string *list, string key, int lim)
{
	int index, begin =0, end =(lim-1);

	while(end >=begin)
	{
		int middile = (begin + end) / 2;
		if(key < list[middile])
			end = middile -1;
		else if(key == list[middile])
			return middile;
		else
			begin = middile +1;
	}
	return -1;
}
//===================================================================================
string coatl::removeSpace(string in)
{
	string out;
	char arr[20];

	for(int i=0,u=0; i<in.size(); i++)
		if(in[i] != ' '){
			arr[u++] = in[i];
			arr[u+1] = '\0';
		}

	out.assign(arr);
	return out;
}
//===================================================================================
void coatl::goto_class(string m, string input)
{
	viper vip;
	chem ch;
	math mat;
	elect el;
	Astro astro;
	econ econo;
	convert ccon;

	if(m == "phys")
	{
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
	}
	if(m == "chem")
	{
		if(input == "autotitrator")
			ch.titrate();
		if(input == "boyllaw")
			ch.boyllaw();
		if(input == "calc")
			ch.calc();
		if(input == "charlaw")
			ch.charlaw();
		if(input == "clear")
			system("clear");
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
		if(input == "stoich")
			ch.stoichiometry();
		if(input == "oxystate")
			ch.oxidationState();
		if(input == "solutions")
			ch.solutions();

	}
	if(m == "math")
	{
		if(input == "dot")
			mat.dotprod();
		if(input == "cros")
			mat.cross();
		if(input == "magnetud")
			mat.magnetud();
		if(input == "sin")
			mat.sine();
		if(input == "plane")
			mat.calcplane();
		if(input == "tan")
			mat.tang();
		if(input == "cos")
			mat.coss();
		if(input == "shapes")
			mat.shape();
		if(input == "shadow")
			mat.shadow();
		if(input == "sandev")
			mat.sanDev();
		if(input == "exp")
			mat.groth();
		if(input == "rando")
			mat.rando();
		if(input == "prob")
			mat.prob();
		if(input == "dataa")
			mat.dataAnal();
		if(input == "matrx")
			mat.MatrixCalc();
		if(input == "calc")
		{
			cout << "\nTYPE YOUR EXPRESSION : ";
			Qre.calc();
		}
	}
	if(m == "elect")
	{
		if(input == "horse")
			el.horse();
		if(input == "kilo")
			el.kilo();
		if(input == "kiloam")
			el.kiloAm();
		if(input == "imped")
			el.imped();
		if(input == "resist")
			el.rescolor();
		if(input == "impedan")
			el.impedan();
	}
	if(m == "astro")
	{
		if(input == "doppler")
			astro.doppler();
		if(input == "rocket")
			astro.rocket();
	}
	if(m == "econ"){
		if(input == "inflat")
			econo.infl();
		if(input == "gdp")
			econo.gdp();
		if(input == "consume")
			econo.consume();
	}
	if(m == "conv"){
		if(input == "energy")
			ccon.energy();
		if(input == "meters")
			ccon.meters();
		if(input == "milkl")
			ccon.milklm();
		if(input == "presure")
			ccon.presure();
		if(input == "temp")
			ccon.temp();
	}
}
// class destructor
coatl::~coatl()
{
	// insert your code here
	basisRing *ringTraverse = KEY->next,
		  *killRing;
	hydra *killHydra = NULL;
	
	while(ringTraverse->root != NULL){
		// get root tree node
		killHydra = ringTraverse->root;
		
		// delete tree (burn Hydra)
		deleteHydraTree(killHydra);

		// goto the next ring element
		killRing = ringTraverse;
		ringTraverse = ringTraverse->next;
		delete killRing;
	}
	delete KEY;
}
