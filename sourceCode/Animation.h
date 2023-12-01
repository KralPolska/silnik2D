#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/// <summary>
/// \class Animation
/// Klasa Animation zawiera wszystkie niezbędne metody oraz pola,
/// które sa uzywane przy animowaniu ze spritesheet.
/// </summary>
class Animation
{
private:
	sf::Vector2u frameCount; ///< Wektor liczb nieujemnych, okreslajacy ile jest klatek animacji
	sf::Vector2u framePosition; ///< Wektor pozycji obecnej klatki animacji
	float refreshRate; ///< Liczba zmiennoprzecinkowa nadajaca interwal odswiezania animacji, 1.0f = 1sec
	float totalTime; ///< Liczba zmiennoprzecinkowa zliczajaca ile czasu uplynelo od rozpoczecia animacji

public:
	sf::IntRect uvRect; ///< Obiekt typu IntRect okreslajacy wspolrzedne obecnej klatki animacji
	
	/// <summary>
	///	Konstruktor klasy tworzacy obiekt animacji
	/// </summary>
	/// <param name="texture">Wskaznik do tekstury ktora chcemy animowac</param>
	/// <param name="frameCount">Wektor liczb nieujemnych zawierajacy dane, ile jest klatek do obslugi</param>
	/// <param name="refreshRate">Liczba okreslajaca czas pomiedzy zmiana klatki na nastepna</param>
	Animation(sf::Texture* texture, sf::Vector2u frameCount, float refreshRate);
	
	/// <summary>
	/// Funkcja wywolywana na koniec kazdej iteracji petli glownej.
	/// Zaktualizowanie danych obslugujacych animacje.
	/// </summary>
	/// <param name="dt">DeltaTime (dt) to czas jaki uplynal od poprzedniej iteracji petli, jest dodawany do czasu wykonywania animacji</param>
	/// <param name="state">Stan lub inaczej kolumna z ktorej chcemy pobierac kolejne klatki</param>
	void update(float dt, unsigned int state);

	/// <summary>
	/// Funkcja majaca na celu zmienic okres czestotliwosci odswiezania klatek
	/// </summary>
	/// <param name="newRefreshRate">Liczba zmiennoprzecinkowa przedstawiajaca nowy czas okresu czestotliwosci odswiezania klatek</param>
	void setRefreshRate(float newRefreshRate);
};

