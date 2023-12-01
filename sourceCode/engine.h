#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
/// <summary>
/// \class engine
/// Klasa glowna. Obsluga okna graficznego
/// </summary>
class engine
{
private:
	sf::VideoMode videoMode; ///< Instrukcje okreslajace jakie parametry ma przyjac okno programu
	bool paused = false;///<  Zmienna okreslajaca czy okno jest obecnie zatrzymane
	//inicjalizacja

	/// <summary>
	/// Funkcja inizjalizujaca okno programu
	/// </summary>
	void init();

	/// <summary>
	/// Funkcja tworzaca okno programu.
	/// </summary>
	/// <param name="height">Wysokosc okna</param>
	/// <param name="width">Szerokosc okna</param>
	/// <param name="fullscreen">Czy okno ma byc pelnoekranowe</param>
	/// <param name="title">Tytul okna pojawiacy sie na pasku glownym okna</param>
	void initWindow(float height, float width, bool fullscreen, std::string title);

public:
	sf::RenderWindow* window; ///< Wskaznik na okno programu
	sf::Event event; ///< Obiekt zawierajacy wszystkie wykonywane interakcje z programem
	//(de)konstruktor

	/// <summary>
	/// Konstruktor klasy. Przyjmuje dane do utworzenia okna
	/// </summary>
	/// <param name="height">Wysokosc okna</param>
	/// <param name="width">Szerokosc okna</param>
	/// <param name="fullscreen">Czy okno ma byc pelnoekranowe</param>
	/// <param name="title">Tytul okna pojawiacy sie na pasku glownym okna</param>
	engine(float height, float width, bool fullscreen, std::string title);

	/// <summary>
	/// Dekonstrukor programu
	/// </summary>
	virtual ~engine();


	//obsluga
	
	/// <summary>
	/// Funkcja okreslajaca stan okna programu
	/// </summary>
	/// <returns>(True | 1) Jezeli okno jest otwarte, w przeciwnym wypadku (False | 0)</returns>
	const bool gameRunning();

	/// <summary>
	/// Wypelnienie ekranu kolorem, aby pozbyc sie poprzednio wygenerowanych obietkow
	/// </summary>
	/// <param name="color">Kolor wypelnienia ekranu</param>
	void clearToColor(sf::Color color);
	/// <summary>
	/// Wyniesienie na ekran wszystkich wczesniej odnotowanych obiektow i ksztaltow
	/// </summary>
	void render();
	/// <summary>
	/// Ustawienie czestotliwosci odswiezania programu
	/// </summary>
	/// <param name="framerate">Liczba klatek na sekunde</param>
	void setFramerate(unsigned int framerate);
	/// <summary>
	/// Sprawdzenie czy okno jest zapauzowane
	/// </summary>
	/// <returns>(True | 1) Jezeli pause == (True | 1), w przeciwnym wypadku (False | 0)</returns>
	bool enginePaused();
	/// <summary>
	/// Zatrzymanie wykonywania programu
	/// </summary>
	void pause();
};


