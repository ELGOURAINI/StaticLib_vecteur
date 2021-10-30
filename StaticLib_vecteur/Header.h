#pragma once

namespace math
{
	class Vecteur3D
	{
	private:
		float vect[3];

	public:
		Vecteur3D(float x = 0.0, float y = 0.0, float z = 0.0);
		Vecteur3D(const Vecteur3D&)=delete;//je veux plus travailler avec passage par valeur donc je peux pas travailler avec le constructeur de recompiage et l'operateur = par default don je cree moi meme ces deuc et je les suppriment
		Vecteur3D& operator=(Vecteur3D& V) = delete; 
		void print() const;
		float at(unsigned indice) const;
		bool operator==(const Vecteur3D& V) const;
		bool operator!=(const Vecteur3D& V) const;
		float& operator[](unsigned indice) ;
		friend void display(Vecteur3D& V);
		
	};

};

