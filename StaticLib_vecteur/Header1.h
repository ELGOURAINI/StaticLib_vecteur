#pragma once
#include "assert.h"
#include "string.h"
#include <iostream>
using namespace std;
namespace math
{
	template <class T>
	class Vecteur3D
	{
	private:
		T vect[3];

	public:
		Vecteur3D(T x = 0.0, T y = 0.0, T z = 0.0);
		Vecteur3D(const Vecteur3D<T>&) = delete;//je veux plus travailler avec passage par valeur donc je peux pas travailler avec le constructeur de recompiage et l'operateur = par default don je cree moi meme ces deuc et je les suppriment
		Vecteur3D<T>& operator=(Vecteur3D<T>& V) = delete;
		void print() const;
		T at(unsigned indice) const;
		bool operator==(const Vecteur3D<T>& V) const;
		bool operator!=(const Vecteur3D<T>& V) const;
		T& operator[](unsigned indice);
		T operator*(const Vecteur3D<T>& V);
		Vecteur3D<T>& operator^(const Vecteur3D<T>& V);
		double norme();
		void display(Vecteur3D<T>& V);

	};

	template<class T>
	 Vecteur3D<T>::Vecteur3D(T x, T y, T z)
	{
		this->vect[0] = x;
		this->vect[1] = y;
		this->vect[2] = z;
	}

	 template<class T>
	 void Vecteur3D<T>::print() const
	 {
		 for (int i = 0; i < 3; i++)
		 {
			 cout << "vect[" << i << "]=" << this->at(i) << endl;
		 }
	 }

	 template<class T>
	 T Vecteur3D<T>::at(unsigned indice) const
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
		return T();
	}

	 template<class T>
	 bool Vecteur3D<T>::operator==(const Vecteur3D<T>& V) const
	 {
		 bool res = true;
		 for (int i = 0; i < 3; i++)
		 {
			 res = res && (this->at(i) == V.at(i));
		 }
		 return res;
	 }

	 template<class T>
	 bool Vecteur3D<T>::operator!=(const Vecteur3D<T>& V) const
	 {
		 bool res = !(*this == V);
		 return res;
	 }

	template<class T>
	 T& Vecteur3D<T>::operator[](unsigned indice)
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

	template<class T>
	 T Vecteur3D<T>::operator*(const Vecteur3D<T>& V)
	{
		float res = 0;
			for (int i = 0; i < 3; i++)
			{
				res = res + (V.vect[i] * this->vect[i]);
			}
		return res;
	}

	 template<class T>
	 Vecteur3D<T>& Vecteur3D<T>::operator^(const Vecteur3D<T>& v)
	 {
		 Vecteur3D<T>* res = new Vecteur3D<T>();
		 res->vect[0] = this->vect[1] * v.vect[2] - this->vect[2] * v.vect[1];
		 res->vect[1] = this->vect[2] * v.vect[0] - this->vect[0] * v.vect[2];
		 res->vect[2] = this->vect[0] * v.vect[1] - this->vect[1] * v.vect[0];

		 return *res;
	 }

	 template<class T>
	 double Vecteur3D<T>::norme()
	 {
		 return sqrt(pow(this->vect[0], 2) + pow(this->vect[1], 2) + pow(this->vect[2], 2));
	 }

	 template<class T>
	 void Vecteur3D<T>::display(Vecteur3D<T> & V)
	 {
		 for (int i = 0; i < 3; i++)
		 {
			 cout << "vect[" << i << "]=" << V.vect[i] << endl;
		 }
	 }
};


