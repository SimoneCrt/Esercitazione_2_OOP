#include <iostream>

//Faccio la dichiarazione della classe template
template <typename T>
class complex_number {
private: //creo parte reale e immaginaria
    T real;
	T imag;
public:
    //Costruttore di default(primo punto esercizio)
	complex_number() : real(0),imag(0) {}
	
	//costruttore user-defined(secondo punto esercizio)
	complex_number(T r,T i) : real(r), imag(i) {}
	
	//metodo per ottenere il coniugato
	complex_number coniugato() const {
		return complex_number(real,-imag);
	}
	
	//Metodo per ottenere la parte reale
	T parte_reale() const {
		return real;
	}
	
	//Metodo per ottenere la parte immaginaria
	T parte_immaginaria() const {
		return imag;
	}
	
	
	// Overload dell'operatore << come membro della classe per stampare il numero complesso
    std::ostream& operator<<(std::ostream& os) {
        if (imag >= 0)
            os << real << "+" << imag << "i";
        else
            os << real << imag << "i";  // Gestisce il caso in cui la parte immaginaria è negativa
        return os;
    }
	
	//Overload dell'operatore +=
	complex_number<T> operator+=(const complex_number<T>&other) {
		real = real + other.real;
		imag = imag + other.imag;
		return complex_number<T>(real,imag);
	}
	
	//Overload dell'operatore + per sommare due numeri complessi
	complex_number<T> operator+(const complex_number<T>&other) const {
		return complex_number<T>(real+ other.real, imag + other.imag);
	}
	
	// Funzione per sommare un valore di tipo T ad un numero complesso
    complex_number<T> operator+(T scalar) const {
        return complex_number<T>(real + scalar, imag);
    }
	
	 // Overload dell'operatore *= per moltiplicare due numeri complessi
    complex_number<T> operator*=(const complex_number<T>& other) {
        T real_part = real * other.real - imag * other.imag;  // Parte reale del risultato
        T imag_part = real * other.imag + imag * other.real;  // Parte immaginaria del risultato
        return complex_number<T>(real_part, imag_part);  // Restituisce il risultato dell'operazione
    }
	
	// Overload dell'operatore * per moltiplicare due numeri complessi
    complex_number<T> operator*(const complex_number<T>& other) const {
        T real_part = real * other.real - imag * other.imag;  // Parte reale del risultato
        T imag_part = real * other.imag + imag * other.real;  // Parte immaginaria del risultato
        return complex_number<T>(real_part, imag_part);
    }
	
	
	
};

// Funzione per moltiplicare un valore di tipo T con un numero complesso
    template <typename T>
    complex_number<T> operator*(T scalar, const complex_number<T>& complex) {
        return complex_number<T>(complex.parte_reale() * scalar, complex.parte_immaginaria() * scalar);
}
	
	
	
	
	
int main()
{   //alcuni esempi
	complex_number<double> a(1.0,2.0);
	complex_number<double> b(1.0,-2.0);
	
	// Stampa il numero complesso a usando l'operatore <<
    std::cout << "a: ";
    a.operator<<(std::cout);  // Stampa 1 + 2i
    std::cout << std::endl;
	
	//Stampo il coniugato di a
	std::cout << "Il coniugato di a è: ";
	a.coniugato().operator<<(std::cout);
	std::cout << std::endl;
	
	//Stampa b
	std::cout << "b: ";
	b.operator<<(std::cout);  //Stampa 1-2i
	std::cout << std::endl;
	
	//ora verifico che gli operatori + e * implementati soddisfano i requisiti di
	//commutatività quando l'operazione è svolta tra un numero complesso e un T.
	complex_number<double> c = a + 2.0;
    std::cout << "a + 2: ";
    c.operator<<(std::cout);  // Stampa 3 + 2i
    std::cout << std::endl;
	
	complex_number<double> d = 3.0 * a;
    std::cout << "3 * a: ";
    d.operator<<(std::cout);  // Stampa 3+6i
    std::cout << std::endl;
	
	return 0;
    
}
