#include "pch.h"
#include "Header.h"
#include "assert.h"
#include "string.h"
#include <iostream>
using namespace math;
using namespace std;

math::Vecteur3D::Vecteur3D(float x, float y, float z)
{
	this->vect[0] = x;
	this->vect[1] = y;
	this->vect[2] = z;
}

void math::Vecteur3D::print() const
{
	for (int i = 0; i < 3; i++)
	{
		cout << "vect[" << i << "]=" << this->at(i) << endl;
	}

}

float math::Vecteur3D::at(unsigned indice) const
{
	assert(indice>=0 && indice<3);//en mode debbogage
		return this->vect[indice];
	//exception en mode release; lorsque l'utilisation est par l'user
	try
	{
		if (indice < 0 || indice >= 3) throw "rang error";//si la cdt est vrai exception sera affiché et je vais a catch
		return this->vect[indice];
	}
	catch (char* e)
	{
		cout << e << endl;
	}
	
}

bool math::Vecteur3D::operator==(const Vecteur3D& V) const
{
	bool res=true;
	for (int i = 0; i < 3; i++)
	{
		res = res && (this->at(i) == V.at(i));
	}
	return res;
}

bool math::Vecteur3D::operator!=(const Vecteur3D& V) const
{
	bool res = !(*this == V);
	return res;
}

float& math::Vecteur3D::operator[](unsigned indice)
{
	assert(indice >= 0 && indice < 3);//en mode debbogage
	return this->vect[indice];
	//exception en mode release; lorsque l'utilisation est par l'user
	try
	{
		if (indice < 0 || indice >= 3) throw "rang error";//si la cdt est vrai exception sera affiché et je vais a catch
		return this->vect[indice];
	}
	catch (char* e)
	{
		cout << e << endl;
	}
}
float math::Vecteur3D::operator*(const Vecteur3D& V)
{
	float res = 0;
	for (int i = 0; i < 3; i++)
	{
		res = res + (V.vect[i] * this->vect[i]);
	}
	return res;
}
Vecteur3D& math::Vecteur3D::operator^(const Vecteur3D& v)
{
	Vecteur3D* res = new Vecteur3D();
	res->vect[0] = this->vect[1] * v.vect[2] - this->vect[2] * v.vect[1];
	res->vect[1] = this->vect[2] * v.vect[0] - this->vect[0] * v.vect[2];
	res->vect[2] = this->vect[0] * v.vect[1] - this->vect[1] * v.vect[0];

	return *res;
}

double Vecteur3D::norme()
{

	return sqrt(pow(this->vect[0], 2) + pow(this->vect[1], 2) + pow(this->vect[2], 2));
}

//c innacessible lorsque je suis en dehors de l'espace de nommage 
//mais lorsque la methode est declaré comme friend ona le droit d'acceder
/**void display(Vecteur3D& V)
{
	for (int i = 0; i < 3; i++)
	{
		cout << "vect[" << i << "]=" << V.vect[i] << endl;
	}
}**/

void math::display(Vecteur3D& V)
{
	for (int i = 0; i < 3; i++)
	{
		cout << "vect[" << i << "]=" << V.vect[i] << endl;
	}
}
