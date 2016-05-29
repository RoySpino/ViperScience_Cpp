// Class automatically generated by Dev-C++ New Class wizard

#ifndef COATL_H
#define COATL_H
#include "vipLl.h"
#include <string>

using namespace std;
/*
 * No description
 */
class coatl
{
	private:
		int ringSize, hydraSize, foundSize;
		struct hydra{
			public:
				hydra *left, *right, *before;
				string prgName, related, dir;
				// CONSTRUCTOR
				hydra(){
					left = right = before = NULL;
				}
		};
		struct basisRing{
			public:
				basisRing *next, *before;
				hydra *root;
				// CONSTRUCTOR
				basisRing(){
					next = before = NULL;
				}
		};
		void deleteHydraTree(hydra *killNode){
			if(killNode == NULL)
				return;
			deleteHydraTree(killNode->left);
			deleteHydraTree(killNode->right);

			delete killNode;
		}
		basisRing *KEY, *ringEnd;
		vipLl <hydra>hydraList;
		hydra found[20];
		hydra ht;
	public:
		// class constructor
		coatl();


		bool Find(string);
		void search(string);
		void goto_class(string m,string input);
		void newHydraEl( string name, string relat, string directory);
		void newRingEl();
		string removeSpace(string);
		int binarySearch(string*, string, int);
		// class destructor
		~coatl();
};

#endif // COATL_H