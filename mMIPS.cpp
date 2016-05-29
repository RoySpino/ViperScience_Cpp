#include "mMIPS.h"
#include <string>
#include <iostream>
#include "matrix.h"
#include "vipLl.h"
#include <cstdlib>

using namespace std;

mMIPS::mMIPS(){
	t0 =t1 =t2 =t3 =t4 = NULL;
	t5 =t6 =t7 =t8 =t9 = NULL;

	s0 =s1 =s2 =s3 =s4 = NULL;
	s5 =s6 =s7 =s8 =s9 = NULL;

	v0 =v1 = NULL;
	a0 =a1 = a2 = NULL;

	zero = one = NULL;
}
int mMIPS::input(string in){
	int lim=0;
	bool itaMatrix=false;
	string word="", lel;
	list.erase();

	for(int i=0; i<in.size(); i++){
		if(in[i] == '[')
			itaMatrix = true;
		if(in[i] == ']')
			itaMatrix = false;

		if(itaMatrix == false){
			if((i !=0 and in[i]== ' ')or in[i]==',' or in[i+1] == '\0'or in[i]=='#'){
				if(in[i+1] == '\0') 
					word.push_back(in[i]);
				if(word != "")
				list.add(word);
				word = "";
				if(in[i] == '#')
					break;
			}
			else
				word.push_back(in[i]);
		}
		else
			word.push_back(in[i]);
	}

	lim = list.size();

	return lim;
}
void mMIPS::table(){
	string sel, ag1, ag2, ag3, ag4;
	int arcnt;

	while(true){
		getline(cin, sel);
		arcnt = input(sel);

		// utility or system comands ///////////////////////////////////
		if(sel == "exit")
			break;
		if(sel == "clc" or sel == "cls" or sel == "clear"){
			system("clear");
			continue;
		}
		if(sel == "lar"){
			lar();
			continue;
		}
		if(sel == "help"){
			helpMIPS();
			continue;
		}

		// get the command /////////////////////////////////////////////
		if(arcnt >=2)
			sel = list.deque();
		else
			continue;
		

		// if there is an error of somesort ////////////////////////////
		if(list.size() == 0){
			cout << "<<ERROR: invalid command or variable >>\n\n";
			continue;
		}

		// get the destination
		ag1 = list.deque();
		dest = getMat( ag1 );
		if(dest == NULL){
			cout << "<<ERROR: invalid command or variable >>\n\n";
			continue;
		}

		// single matrix operations ////////////////////////////////////
		if(sel == "li"){
			ag2 = list.deque();
			li(dest, ag2 );
			continue;
		}
		if(sel == "print"){
			print(dest);
			continue;
		}
		if(sel == "det"){
			det(dest, dest);
			continue;
		}

		// two matrix operatoins ///////////////////////////////////////
		if(arcnt == 3){
			matrix tmp;
			// get a source
			ag3 = list.deque();
			sor1 = getMat( ag3 );
			if(ag3 == "zero")
				sor1 = getZero(&tmp);
			if(ag3 == "one")
				sor1 = getOne(&tmp);
			if(sor1 == NULL){
				cout << "<<ERROR: invalid command or variable >>\n\n";
				continue;
			}
			if(sel == "move")
				move(dest, sor1);
			if(sel == "cof")
				cof(dest, sor1);
			if(sel == "rref")
				rref(dest, sor1);
			if(sel == "ref")
				ref(dest, sor1);
			if(sel == "coll")
				coll(dest, sor1);
			if(sel == "null")
				Null(dest, sor1);
			if(sel == "tran")
				tran(dest, sor1);
			if(sel == "inv")
				inv(dest, sor1);
		}
		// three matrix opertations ////////////////////////////////////
		if(arcnt == 4){
			num =0;
			ag3 = list.deque();
			ag4 = list.deque();
			sor1 = getMat( ag3 );
			sor2 = getMat( ag4 );

			if(ag3 == "zero")
				sor1 = getZero(sor2);
			if(ag3 == "one")
				sor1 = getOne(sor2);
			if(ag4 == "zero")
				sor2 = getZero(sor1);
			if(ag4 == "one")
				sor2 = getOne(sor1);
			if(sor1 == NULL){
				cout << "<<ERROR: invalid command or variable >>\n\n";
				continue;
			}
			if(sor2 == NULL){
				num = strtod(ag4.data(), NULL);
			}
			if(sel == "pow"){
				Pow(dest, sor1, num);
				continue;
			}
			if(sel == "addi"){
				addi(dest, sor1, num);
				continue;
			}
			if(sel == "subi"){
				subi(dest, sor1, num);
				continue;
			}
			if(sel == "muli"or sel=="multi"){
				muli(dest, sor1, num);
				continue;
			}
			if(sor1 == NULL or sor2 == NULL){
				cout << "<<ERROR: invalid command or variable >>\n\n";
				continue;
			}
			if(sel == "add")
				add(dest, sor1, sor2);
			if(sel == "sub")
				sub(dest, sor1, sor2);
			if(sel == "mul"or sel == "mult")
				mul(dest, sor1, sor2);
			if(sel == "aug")
				aug(dest, sor1, sor2);
		}

	}
}
void mMIPS::lar(){
	cout << endl;
	cout << "t0 " <<((t0 == NULL)?"_":"#")<< "    s0 " <<((s0 == NULL)?"_":"#")<<"    v0 "<<((v0 ==NULL)?"_\n":"#\n")
	     << "t1 " <<((t1 == NULL)?"_":"#")<< "    s1 " <<((s1 == NULL)?"_":"#")<<"    v1 "<<((v1 ==NULL)?"_\n":"#\n")
	     << "t2 " <<((t2 == NULL)?"_":"#")<< "    s2 " <<((s2 == NULL)?"_":"#")<< "\n"
	     << "t3 " <<((t3 == NULL)?"_":"#")<< "    s3 " <<((s3 == NULL)?"_":"#")<< "\n"  
	     << "t4 " <<((t4 == NULL)?"_":"#")<< "    s4 " <<((s4 == NULL)?"_":"#")<<"    a0 "<<((a0 ==NULL)?"_\n":"#\n")
	     << "t5 " <<((t5 == NULL)?"_":"#")<< "    s5 " <<((s5 == NULL)?"_":"#")<<"    a1 "<<((a1 ==NULL)?"_\n":"#\n")
	     << "t6 " <<((t6 == NULL)?"_":"#")<< "    s6 " <<((s6 == NULL)?"_":"#")<<"    a2 "<<((a2 ==NULL)?"_\n":"#\n")
	     << "t7 " <<((t7 == NULL)?"_":"#")<< "    s7 " <<((s7 == NULL)?"_":"#")<< "\n" 
	     << "t8 " <<((t8 == NULL)?"_":"#")<< "    s8 " <<((s8 == NULL)?"_":"#")<< "\n"
	     << "t9 " <<((t9 == NULL)?"_":"#")<< "    s9 " <<((s9 == NULL)?"_":"#")<< "\n\n"; 


}
matrix* mMIPS::getOne(matrix* size){
	if(one != NULL)
		delete one;

	one = new matrix;
	*one = *size;

	for(int i=0; i<one->getRow(); i++)
		for(int u=0; u<one->getCol(); u++)
			one->load(i, u, ((i==u)?1:0) );
	return one;
}
matrix* mMIPS::getZero(matrix* size){
	if(zero != NULL)
		delete zero;

	zero = new matrix;
	*zero = *size;

	for(int i=0; i<zero->getRow(); i++)
		for(int u=0; u<zero->getCol(); u++)
			zero->load(i, u, 0);
	return zero;
}
matrix* mMIPS::getMat(string raw){
	matrix *l;

	if(raw == "one"){
		if(one != NULL)
			return one;
		one = new matrix(1,1);
		return one;
	}
	if(raw == "zero"){
		if(zero != NULL)
			return zero;
		zero = new matrix(1,1);
		return zero;
	}
	if(raw == "t0"){
		if(t0 != NULL)
			return t0;
		t0 = new matrix(1,1);
		return t0;
	}
	if(raw == "t1"){
		if(t1 != NULL)
			return t1;
		t1 = new matrix(1,1);
		return t1;
	}
	if(raw == "t2"){
		if(t2 != NULL)
			return t2;
		t2 = new matrix(1,1);
		return t2;
	}
	if(raw == "t3"){
		if(t3 != NULL)
			return t3;
		t3 = new matrix(1,1);
		return t3;
	}
	if(raw == "t4"){
		if(t4 != NULL)
			return t4;
		t4 = new matrix(1,1);
		return t4;
	}
	if(raw == "t5"){
		if(t5 != NULL)
			return t5;
		t5 = new matrix(1,1);
		return t5;
	}
	if(raw == "t6"){
		if(t6 != NULL)
			return t6;
		t6 = new matrix(1,1);
		return t6;
	}
	if(raw == "t7"){
		if(t7 != NULL)
			return t7;
		t7 = new matrix(1,1);
		return t7;
	}
	if(raw == "t8"){
		if(t8 != NULL)
			return t8;
		t8 = new matrix(1,1);
		return t8;
	}
	if(raw == "t9"){
		if(t9 != NULL)
			return t9;
		t9 = new matrix(1,1);
		return t9;
	}



	if(raw == "s0"){
		if(s0 != NULL)
			return s0;
		s0 = new matrix(1,1);
		return s0;
	}
	if(raw == "s1"){
		if(s1 != NULL)
			return s1;
		s1 = new matrix(1,1);
		return s1;
	}
	if(raw == "s2"){
		if(s2 != NULL)
			return s2;
		s2 = new matrix(1,1);
		return s2;
	}
	if(raw == "s3"){
		if(s3 != NULL)
			return s3;
		s3 = new matrix(1,1);
		return s3;
	}
	if(raw == "s4"){
		if(s4 != NULL)
			return s4;
		s4 = new matrix(1,1);
		return s4;
	}
	if(raw == "s5"){
		if(s5 != NULL)
			return s5;
		s5 = new matrix(1,1);
		return s5;
	}
	if(raw == "s6"){
		if(s6 != NULL)
			return s6;
		s6 = new matrix(1,1);
		return s6;
	}
	if(raw == "s7"){
		if(s7 != NULL)
			return s7;
		s7 = new matrix(1,1);
		return s7;
	}
	if(raw == "s8"){
		if(s8 != NULL)
			return s8;
		s8 = new matrix(1,1);
		return s8;
	}
	if(raw == "s9"){
		if(s9 != NULL)
			return s9;
		s9 = new matrix(1,1);
		return s9;
	}





	if(raw == "a0"){
		if(a0 != NULL)
			return a0;
		a0 = new matrix(1,1);
		return a0;
	}
	if(raw == "a1"){
		if(a1 != NULL)
			return a1;
		a1 = new matrix(1,1);
		return a1;
	}
	if(raw == "a2"){
		if(a2 != NULL)
			return a2;
		a2 = new matrix(1,1);
		return a2;
	}



	if(raw == "v0"){
		if(v0 != NULL)
			return v0;
		v0 = new matrix(1,1);
		return v0;
	}
	if(raw == "v1"){
		if(v1 != NULL)
			return v1;
		v1 = new matrix(1,1);
		return v1;
	}

	return NULL;
}
void mMIPS::li(matrix *&d, string s){
	bool newRow = false;
	string word="", lel;
	double n;
	double *l;
	int i=0, lim;
	vipLl <double> el;

	// overwrite the existing matrix ////////////////////////////////////////////////////////
	if(d !=NULL)
		delete d;
	d = new matrix(1,1);

	// erase square brackets ////////////////////////////////////////////////////////////////
	for(i=0; i<s.size(); i++){
		if(s[i] =='[' or s[i]==']')
			s = s.erase(i,1);
	}

	// parse the input string and make the matrix from it //////////////////////////////////
	for(i=0; i<s.size(); i++){

		for(i; i<s.size(); i++){
			if((i !=0 and s[i]== ' ')or s[i]==',' or s[i+1] == '\0'or s[i]==';'){
				if(s[i+1] == '\0') 
					word.push_back(s[i]);
				if(word.size() != 0){// ignore double ',' 'spaces'
					n = strtod(word.data(),NULL);

					el.add(n);
					word = "";
				}
				if(s[i] == ';')
					break;
			}
			else
				word.push_back(s[i]);
		}


		lim = el.size();
		l = new double[lim];
		for(int v=0; v<lim; v++){
			l[v] = el.deque();
		}


		if(lim != d->getCol())
			d->setCol(lim);

		// load matrix values ////////////////////////
		if(d->getRow() == 1 and newRow == false){
			for(int v=0; v<lim; v++)
				d->load(0,v,l[v]);
			newRow = true;
		}else
			dest->loadRow(l);
		//////////////////////////////////////////////
		delete []l;
	}
}
void mMIPS::print(matrix*& pt){
	cout << *pt << endl;
}

void mMIPS::add(matrix*& d, matrix*& s1, matrix*& s2){
	*d = *s1 + *s2;
}
void mMIPS::sub(matrix*& d, matrix*& s1, matrix*& s2){
	*d = *s1 - *s2;
}
void mMIPS::aug(matrix*& d, matrix*& s1, matrix*& s2){
	*d = *s1;
	d->aug( *s2 );
}
void mMIPS::mul(matrix*& d, matrix*& s1, matrix*& s2){
	if(s1->getCol() == s2->getRow())
		*d = *s1 * *s2;
	else
		cout << "\t<<ERROR: dimension mis-match>>\n";
}

void mMIPS::cof(matrix*& d, matrix*& s1){
	*d = s1->cof();
}
void mMIPS::addi(matrix*& d, matrix*& s1, double n){
	*d = *s1 + n;
}
void mMIPS::subi(matrix*& d, matrix*& s1, double n){
	*d = *s1 - n;
}
void mMIPS::muli(matrix*& d, matrix*& s1, double n){
	*d = *s1 * n;
}

void mMIPS::move(matrix*& d, matrix*& s1){
	*d = *s1;
}

void mMIPS::Pow(matrix*& d, matrix*& s1, double n){
	*d = pow(*s1, int(n));
}
void mMIPS::inv(matrix *&d, matrix *&s1){
	*d = s1->invert();
}
void mMIPS::det(matrix*& d, matrix*& s1){
	cout << "\t" << s1->det() << endl;
}
void mMIPS::tran(matrix*& d, matrix*& s1){
	*d = s1->tran();
}
void mMIPS::Null(matrix*& d, matrix*& s1){
	*d = s1->null();
}
void mMIPS::coll(matrix*& d, matrix*& s1){
	*d = s1->col();
}
void mMIPS::rref(matrix*& d, matrix*& s1){
	*d = s1->rref();
}
void mMIPS::ref(matrix*& d, matrix*& s1){
	*d = s1->ref();
}
void mMIPS::helpMIPS(){
	string sub;
	cout << "Enter a command name:\n>> ";
	cin >> sub;
	cout << endl;
  

	if(sub == "print"){
		cout << "\tShow the matrix contained in a variable/register\n"
		     << "\t(matrix A)\n"
		     << "\tEX)\n"
		     << "\t\tprint  (matrix A)\n";
		return;
	}
	if(sub == "cof"){
		cout << "\tGets the cofactor of the matrix and sores it in another matrix\n"
		     << "\tresult = (matrix A)\n"
		     << "\tEX)\n"
		     << "\t\tcof  (result)  (matrix A)\n";
		return;
	}
	if(sub == "pow"){
		cout << "\trais the matrix to an intager power then sores the result in another matrix\n"
		     << "\tresult = (matrix A)^ (number)\n"
		     << "\tEX)\n"
		     << "\t\tpow  (result)  (matrix A)  (INTAGER number)\n";
		return;
	}
	if(sub == "null"){
		cout << "\tGets the null space of the matrix and sores it in another matrix\n"
		     << "\tresult = (matrix A)\n"
		     << "\tEX)\n"
		     << "\t\tnull  (result)  (matrix A)\n";
		return;
	}
	if(sub == "coll"){
		cout << "\tGets the basis of the colum space and sores it in another matrix\n"
		     << "\tresult = (matrix A)\n"
		     << "\tEX)\n"
		     << "\t\tcoll  (result)  (matrix A)\n";
		return;
	}
	if(sub == "mul"){
		cout << "\tMultiplies two matricies together and sores the result in another matrix\n"
		     << "\tresult = (matrix A) * (matrix B)\n"
		     << "\tEX)\n"
		     << "\t\tmul  (result)  (matrix A)  (matrix B)\n";
		return;
	}
	if(sub == "muli"){
		cout << "\tMultiplies a matrix and a number then sores the result in another matrix\n"
		     << "\tresult = (matrix A) * (number)\n"
		     << "\tEX)\n"
		     << "\t\tmuli  (result)  (matrix A)  (number)\n";
		return;
	}
	if(sub == "add"){
		cout << "\tAdds two matricies together and sores the result in another matrix\n"
		     << "\tresult = (matrix A) + (matrix B)\n"
		     << "\tEX)\n"
		     << "\t\tadd  (result)  (matrix A)  (matrix B)\n";
		return;
	}
	if(sub == "addi"){
		cout << "\tAdds a matrix and a number then sores the result in another matrix\n"
		     << "\tresult = (matrix A) + (number)\n"
		     << "\tEX)\n"
		     << "\t\taddi  (result)  (matrix A)  (number)\n";
		return;
	}
	if(sub == "sub"){
		cout << "\tSubtracts two matricies together and sores the result in another matrix\n"
		     << "\tresult = (matrix A) - (matrix B)\n"
		     << "\tEX)\n"
		     << "\t\tsub  (result)  (matrix A)  (matrix B)\n";
		return;
	}
	if(sub == "subi"){
		cout << "\tsubtracts a matrix and a number then sores the result in another matrix\n"
		     << "\tresult = (matrix A) - (number)\n"
		     << "\tEX)\n"
		     << "\t\tsubi  (result)  (matrix A)  (number)\n";
		return;
	}
	if(sub == "rref"){
		cout << "\tTakes the rref of a matrix then saves the result in another matrix\n"
		     << "\tresult = rref( matrix A )"
		     << "\tEX)\n"
		     << "\t\trref  (result)  (matrix A)\n";
		return;
	}
	if(sub == "ref"){
		cout << "\tTakes the ref of a matrix then saves the result in another matrix\n"
		     << "\tresult = ref( matrix A )"
		     << "\tEX)\n"
		     << "\t\tref  (result)  (matrix A)\n";
		return;
	}
	if(sub == "tran"){
		cout << "\tTakes the transpose of a matrix then saves the result in another matrix\n"
		     << "\tresult = transpose ( matrix A )\n"
		     << "\tEX)\n"
		     << "\t\ttran  (result)  (matrix A)\n";
		return;
	}
	if(sub == "inv"){
		cout << "\tTakes the inverse of a matrix then saves the result in another matrix\n"
		     << "\tresult = ( matrix A ) ^-1\n"
		     << "\tEX)\n"
		     << "\t\tinv  (result)  (matrix A)\n";
		return;
	}
	if(sub == "det"){
		cout << "\tTakes the determinat of a matrix then outputs the result on screen\n"
		     << "\tresult = det ( matrix A )\n"
		     << "\tEX)\n"
		     << "\t\tdet  (matrix A)\n";
		return;
	}
	if(sub == "li"){
		cout << "\tTakes a string of numbers and saves it to a matrix\n"
		     << "\tresult = [a,b,c;d,e,f;g,h,i]\n"
		     << "\tEX)\n"
		     << "\t\tli (matrix A) [a,b,c;d,e,f;g,h,i]\n";
		return;
	}
	if(sub == "move"){
		cout << "\tmakes a copy of the matrix and saves it to another matrix\n"
		     << "\tresult = [a,b,c;d,e,f;g,h,i]\n"
		     << "\tEX)\n"
		     << "\t\tmove  (dstination)   (matrix A)";
		return;
	}
}

	mMIPS::~mMIPS(){
		if(t0 != NULL)
			delete t0;
		if(t1 != NULL)
			delete t1;
		if(t2 != NULL)
			delete t2;
		if(t3 != NULL)
			delete t3;
		if(t4 != NULL)
			delete t4;
		if(t5 != NULL)
			delete t5;
		if(t6 != NULL)
			delete t6;
		if(t7 != NULL)
			delete t7;
		if(t8 != NULL)
			delete t8;
		if(t9 != NULL)
			delete t9;

		if(s0 != NULL)
			delete s0;
		if(s1 != NULL)
			delete s1;
		if(s2 != NULL)
			delete s2;
		if(s3 != NULL)
			delete s3;
		if(s4 != NULL)
			delete s4;
		if(s5 != NULL)
			delete s5;
		if(s6 != NULL)
			delete s6;
		if(s7 != NULL)
			delete s7;
		if(s8 != NULL)
			delete s8;
		if(s9 != NULL)
			delete s9;

		if(a0 != NULL)
			delete a0;
		if(a1 != NULL)
			delete a1;
		if(a2 != NULL)
			delete a2;

		if(v0 != NULL)
			delete v0;
		if(v1 != NULL)
			delete v1;

		if(zero != NULL)
			delete zero;
		if(one != NULL)
			delete one;
	}
