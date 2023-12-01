#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

/// <summary>
/// Klasa przechowujaca dane o wsplorzednych wzgledem ekranu.
/// </summary>
class point2D
{
private:
	sf::Vector2f point; ///< Wektor typu float, ktory przechowuje dwie wartosci, w tym wypadku x, y na ekranie.
public:

	/// <summary>
	/// Konstruktor pusty klasy.
	/// Ustawia zmienna <b>point</b> na {0,0} 
	/// </summary>
	point2D();

	/// <summary>
	/// Konstruktor glowny klasy. 
	/// Ustawia wspolrzedne wektora <b>point</b> na zadane mu wartosci.
	/// </summary>
	/// <param name="position">Wektor dwoch wartosci typu float oznaczajacych x, y na ekranie</param>
	point2D(sf::Vector2f position);
	
	/// <summary>
	/// Konstruktor przeciazeniowy klasy.
	/// Ustawia wspolrzedne wektora <b>point</b na zadane mu wartosci.
	/// Do jego wywolania nie trzeba wektora, wystarcza dwie wartosci float.
	/// </summary>
	/// <param name="x">Wspolrzedna x ekranu, jezeli <0 => 0</param>
	/// <param name="y">Wspolrzedna y ekranu, jezeli <0 => 0</param>
	point2D(float x, float y);

	/// <summary>
	/// Funkcja zwracajaca wspolrzedna x wzgledem ekranu przypisana do <b>point</b>
	/// </summary>
	/// <returns>Wspolrzedna x obiektu</returns>
	float getX();

	/// <summary>
	/// Funkcja zwracajaca wspolrzedna y wzgledem ekranu przypisana do <b>point</b>
	/// </summary>
	/// <returns>Wspolrzedna y obiektu</returns>
	float getY();

	/// <summary>
	/// Funkcja zwracajaca pelna pozycje obiektu na ekranie
	/// </summary>
	/// <returns>Wektor dwoch wartosci typu float oznaczajacych x, y na ekranie</returns>
	sf::Vector2f getPosition();

	/// <summary>
	/// Funkcja ustawiajaca pozycje wektora wedlug przekazanego wektora.
	/// Jezeli x < 0 => 0
	/// Jezeli y < 0 => 0
	/// </summary>
	/// <param name="position">Wektor dwoch wartosci typu float oznaczajacych x, y na ekranie</param>
	void setPosition(sf::Vector2f position);

	/// <summary>
	/// Funkcja ustawiajaca pozycje x wedlug przekazanej wartosci/
	/// </summary>
	/// <param name="x">Wspolrzedna x obiektu</param>
	void setX(float x);

	/// <summary>
	/// Funkcja ustawiajaca pozycje y wedlug przekazanej wartosci/
	/// </summary>
	/// <param name="x">Wspolrzedna y obiektu</param>
	void setY(float y);

};

