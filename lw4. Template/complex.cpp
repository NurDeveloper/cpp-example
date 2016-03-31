//Определение класса для работы с комплексными числами

#include "complex.h"

Complex::Complex(){
	Re=0;
	Im=0;}

Complex::Complex(float re){
	Re=re;
	Im=0;}

Complex::Complex(float re,float im){
	Re=re;
	Im=im;}

Complex Complex::operator+ (const Complex& cmlx){
	Complex res;
	res.Re=Re+cmlx.Re;
	res.Im=Im+cmlx.Im;
	return res;}

Complex Complex::operator- (const Complex& cmlx){
	Complex res;
	res.Re=Re-cmlx.Re;
	res.Im=Im-cmlx.Im;
	return res;}

Complex Complex::operator* (const Complex& cmlx){
	Complex res;
	res.Re=Re*cmlx.Re-Im*cmlx.Im;
	res.Im=Re*cmlx.Im+Im*cmlx.Re;
	return res;}

bool Complex::operator== (const Complex& cmlx){
	return ((Re==cmlx.Re) && (Im==cmlx.Im));}

bool Complex::operator!= (const Complex& cmlx){
	return !((Re==cmlx.Re) && (Im==cmlx.Im));}

ostream&  operator<< (ostream& out, const Complex& cmlx){
	out<<'('<<cmlx.Re<<", "<<cmlx.Im<<')';
	return out;}