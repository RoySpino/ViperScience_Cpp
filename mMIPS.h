#ifndef MMIPS_H
#define MMIPS_H
#include <string>
#include "matrix.h"
#include "vipLl.h"

class mMIPS{
	private:
		matrix *t0,*t1,*t2,*t3,*t4,*t5,*t6,*t7,*t8,*t9,
		       *s0,*s1,*s2,*s3,*s4,*s5,*s6,*s7,*s8,*s9,
		       *a0,*a1,*a2,
		       *v0,*v1;
		matrix *zero, *one, *dest, *sor1, *sor2;
		vipLl <string>list;
		double num;
	public:
		mMIPS();
		int input(string);
		void print(matrix*&);
		void li(matrix*&, string);
		void table();
		matrix *getMat(string);
		matrix* getZero(matrix*);
		matrix* getOne(matrix*);
		void lar();
		void helpMIPS();

		void add(matrix*&, matrix*&, matrix*&);
		void sub(matrix*&, matrix*&, matrix*&);
		void mul(matrix*&, matrix*&, matrix*&);
		void aug(matrix*&, matrix*&, matrix*&);

		void addi(matrix*&, matrix*&, double);
		void subi(matrix*&, matrix*&, double);
		void muli(matrix*&, matrix*&, double);

		void move(matrix*&, matrix*&);

		void Pow(matrix*&, matrix*&, double);
		void cof(matrix*&, matrix*&);
		void inv(matrix*&, matrix*&);
		void det(matrix*&, matrix*&);
		void tran(matrix*&, matrix*&);
		void Null(matrix*&, matrix*&);
		void coll(matrix*&, matrix*&);
		void rref(matrix*&, matrix*&);
		void ref(matrix*&, matrix*&);

		~mMIPS();
};

#endif
