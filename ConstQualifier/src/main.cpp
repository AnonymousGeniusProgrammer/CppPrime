#include <iostream>
#include "main.hpp"

int main()
{
//#define _REFERENCE_
#ifdef _REFERENCE_
	extern const int bufSize;
	std::cout << "External variable bufSize: " << bufSize << std::endl;

	int i = 42;
	const int& r1 = i;
	const int& r2 = 42;
	const int& r3 = r1 * 2;
	std::cout << "Const reference of i = 42 is, r1 = " << r1 << std::endl;
	std::cout << "After changing i to ++i = " << ++i << ", r1 = " << r1 << std::endl;
#endif // _REFERENCE_

//#define _POINTER_
#ifdef _POINTER_
	const double pi = 3.14;
	// double* ptr = &pi;			// error: ptr is a plain pointer (non const)
	const double* cptr = &pi;		// ok: &pi return a pointer to a const double variable, and it is
									// used to initiliaze cptr
	// *cptr = 42;					// error: *cptr is not modifyable value

	double dval = 3.14;
	cptr = &dval;					// ok: cptr now pointing to dval, but we can't change dval through
									// cptr

	/*
	 * It is helpful to think of pointers and references to const as pointers or reference that
	 * think they point or refer to const.
	 * 也就是说：声明reference或pointer为const只是限制了我们能对这个reference或pointer进行的操作，但完全
	 * 没有指示，这个underlying variable究竟是不是cosnt
	 */

	int errNumb = 0;
	int* const ptrErr = &errNumb;			// ptrErr will always point to errNumb, address
											// that is sored in ptrErr can not be changed
	*ptrErr = 1;							// errNumb can be changed through dereferenced ptrErr

	double changebale_pi = pi;

	const double* const ptrp = &changebale_pi;		// 1. ptrp is a constant pointer, that can only 
													// point to pi.
													// 2. we can not change value of pi through ptrp

	//*ptrp = 2.72;									// error: ptrp believes it point to a constant

#endif // _POINTER_

//#define _TOP_LEVEL_
#ifdef _TOP_LEVEL_
	/*
	 * top-level const indicates that the pointer as a object is const, address can not be changed
	 * low-level const indicates that the uderlying object of this pointer can't be changed through
	 * this pointer
	 */

	int i = 0;
	int* const p1 = &i;					// top-lvel const, read from right to left
										// the address in p1 can not be changed
	// *p1 = 2;                         // ok

	const int ci = 42;					// only top-level const
	const int* p2 = &ci;				// low-level const, p2 point to a const variable
	// *p2 = 43;						// error
	const int* const p3 = p2;			// copy address in p2 to p3 and this address can not be changed
										// most left one is low-level const
	const int& r = ci;					// low-level const

	/*
	 * Distinction top-level/low-level const, copy operation ignores top-level consts
	 */

	i = ci;								// top-level const is ignored.
	p2 = p3;							// top-level const of p3 is ignored

	/*
	 * when we copy objects, both object must have same low-level const qualifications
	 * or, there must be a conversion between the types of the tow objects. In general, we can
	 * convert a non-const to const but not the other way round
	 */

	// int* p = p3;						// error: low-level const doesn't match

	p2 = &i;							// ok: we can convert int* to const int* 
	// int& r = ci;						// error:  we can't bind int& to const int
	const int& r2 = i;					// ok: we can bind const int& to a plain int


#endif // _TOP_LEVEL_

#define _CONSTEXPR_AND_CONSTANT_EXPRESSION_
#ifdef _CONSTEXPR_AND_CONSTANT_EXPRESSION_
	/*
	 * 1. constant expressions is an expression whose value can't be changed and that can be
	 * evaluated at compile time. e.g. literal, const object that is initilized from a constant expression
	 */
	const int max_files = 20;			// max_file is a constant expression
	const int limit = max_files + 1;	// limit is a constant expression
	int staff_size = 27;				// staff_size is not constant expression, it is initiliazed with
										// constant expression, but it is not a const object
	const int sz = get_size();			// const object initiliazed with non-constant expression
										// is not constant expression, it can be evaluated until runtime

#endif // _CONSTEXPR_AND_CONSTANT_EXPRESSION_


}
