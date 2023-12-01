#pragma once
#include "point2D.h"
#include "Animation.h"

/// <summary>
/// \class primitive
/// Klasa glowna do tworzenia obiektow.
/// Zawiera ona pola niezbedne do manipulacji ksztaltami oraz ich transformacji
/// </summary>
class primitive
{
protected:
	sf::RenderWindow& window; ///< Adres okna na ktorym obiekt sie znajduje
	int farRight; ///< Granica obiektu z prawej strony
	int farLeft; ///< Granica obiektu z lewej strony
	int farBottom; ///< Granica obiektu od dolu
	int farTop; ///< Granica obiektu od gory
	sf::Sprite texture; ///< Sprite ktory ma byc nalozony na obiekt
	point2D prevPos; ///< Poprzednia pozycja obiektu na ekranie przed zmiana
	point2D point; ///< Obecna pozycja obiektu na ekranie
public:
	bool moving; ///< Czy obiekt sie porusza
	bool selected; ///< Czy obiekt jest wybrany do uzycia
	/// <summary>
	/// Konstruktor glowny obiektow. Inicjalizuje pola, aby byly gotowe do uzycia przez uzytkownika.
	/// </summary>
	/// <param name="window">Adres okna na ktorym ten obiekt ma sie znajdowac</param>
	primitive(sf::RenderWindow& window);
};

/// <summary>
/// \class primitive_rectangle
/// Dziedziczy ona konstrukor oraz pola do obslugi obiektu.
/// Implementuje swoje metody zgodne z ksztaltem obiektu.
/// W tym wypadku jest to prostokat (lub kwadrat). Metody pozwalaja na manipulacje pozycji, obrotu, kolorow oraz wiele wiecej.
/// </summary>
class primitive_rectangle : public primitive{
	sf::RectangleShape rectangle; ///< Obiekt o ksztalcie prostokatu z biblioteki SFML
public:
	/// <summary>
	/// Dziedziczenie konstuktora z klasy glownej \class primitive
	/// </summary>
	using primitive::primitive;
	
	/// <summary>
	/// Funkcja aktualizujaca wartosci graniczne obiektu
	/// </summary>
	void updateEdge();
	
	/// <summary>
	/// Funkcja rysujaca obiekt bez wypelnienia. 
	/// Jezeli byl poprzednio ustawiony jakis kolor, zostaje on nadpisany na kolor przezroczysty, transparentny {0, 0, 0, 0}
	/// </summary>
	/// <param name="color">Kolor dla obrysu</param>
	/// <param name="thickness">Grubosc linii obwodu</param>
	void drawRectangle(sf::Color color, unsigned int thickness);

	/// <summary>
	/// Funkcja rysujaca obiekt z wypelnieniem.
	/// Kolor obwodu oraz wypelnienia jest taki sam.
	/// </summary>
	/// <param name="color">Kolor wypelnienia i obwodu</param>
	/// <param name="thickness">Grubosc linii obwodu</param>
	void drawFilledRectangle(sf::Color color, unsigned int thickness);

	/// <summary>
	/// Funkcja rysujaca obiekt z tekstura.
	/// Kolor wypelnienia nie ma znaczenia.
	/// Grubosc linii jest rowna 0.
	/// </summary>
	/// <param name="texture">Obiekt tekstury ktory ma byc nalozony na ksztalt</param>
	void drawTexturedRectangle(sf::Texture texture);

	/// <summary>
	/// Funkcja podstawowa do rysowania obiektu bez zadnych dodatkowych ustawien.
	/// Uzywana jest glownie do narysowania obiektu animowanego.
	/// </summary>
	void draw();

	/// <summary>
	/// Funkcja ustawiajaca pozycje wektora wedlug przekazanego wektora.
	/// Jezeli x < 0 => 0
	/// Jezeli y < 0 => 0
	/// </summary>
	/// <param name="position">Wektor dwoch wartosci typu float oznaczajacych x, y na ekranie</param>
	void setPosition(sf::Vector2f position);

	/// <summary>
	/// Przeciazenie funkcji setPosition.
	/// Metoda przyjmuje dwa parametry ktore sa uzywane do ustawienia pozycji
	/// </summary>
	/// <param name="x">Wspolrzedna x ekranu, jezeli <0 => 0</param>
	/// <param name="y">Wspolrzedna y ekranu, jezeli <0 => 0</param>
	void setPosition(float x, float y);

	/// <summary>
	/// Przeciazenie funkcji setPosition.
	/// Metoda przyjmuje jeden parametr.
	/// Uzywana jest wtedy, gdy chcemy ustawic obiekt w rownej odleglosci od gornej krawedzi jak i lewej krawedzi.
	/// </summary>
	/// <param name="xy">Wspolrzedna ekranu która jest zarówno x jak i y, jezeli <0 => 0</param>
	void setPosition(float xy);
	
	/// <summary>
	/// Funkcja zwracajaca pozycje obiektu.
	/// </summary>
	/// <returns>Wektor dwoch zmiennych typu float</returns>
	sf::Vector2f getPosition();

	/// <summary>
	/// Funkcja zmieniajaca rozmiar obiektu, wzgledem jego poprzedniego rozmiaru.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="newSize">Wektor dwoch zmiennych typu float oznaczajacych wartosc jaka trzeba dodac do obecnego rozmiaru</param>
	void resize(sf::Vector2f newSize);

	/// <summary>
	/// Przeciazenie funkcji resize.
	/// Funkcja zmieniajaca rozmiar obiektu, wzgledem jego poprzedniego rozmiaru.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="sizeX">Rozmiar dodawany wzgledem szerogosci obiektu</param>
	/// <param name="sizeY">Rozmiar dodawany wzgledem wysokosci obiektu</param>
	void resize(float sizeX, float sizeY);
	
	/// <summary>
	/// Funkcja zmieniajaca rozmiar obiektu, nadpisuje jego poprzednia wartosc.
	/// Metoda ma charakter absolutny.
	/// </summary>
	/// <param name="newSize">Nowy rozmiar ktory zostanie uzyty do nadpisania poprzedniej wartosci</param>
	void setSize(sf::Vector2f newSize);
	
	/// <summary>
	/// Przeciazenie funkcji setSize.
	/// Funkcja zmieniajaca rozmiar obiektu, nadpisuje jego poprzednia wartosc.
	/// Metoda ma charakter absolutny.
	/// </summary>
	/// <param name="sizeX">Nowa wartosc szerokosci obiektu</param>
	/// <param name="sizeY">Nowa wartosc wysokosci obiektu</param>
	void setSize(float sizeX, float sizeY);

	/// <summary>
	/// Funkcja zwracajaca wymiary obiektu.
	/// </summary>
	/// <returns>Wektor dwoch wartosci typu float okreslajacy szerokosc i wysokosc obiektu</returns>
	sf::Vector2f getSize();

	/// <summary>
	/// Funkcja zwracajaca szerokosc obiektu jako int.
	/// </summary>
	/// <returns>Wartosc szerokosci obiektu</returns>
	int getSizeX();

	/// <summary>
	/// Funkcja zwracajaca wysokosc obiektu jako int.
	/// </summary>
	/// <returns>Wartosc wysokosci obiektu</returns>
	int getSizeY();

	/// <summary>
	/// Funckcja przesuwajaca obiekt relatywnie do jego poprzedniej pozycji.
	/// Wyjscie poza ekran jest niemożliwe przy uzyciu tej metody.
	/// Ruch zakonczy sie przy napotkaniu granicy ekranu.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="x">Przesuniecie wzgledem osi X</param>
	/// <param name="y">Przesuniecie wzgledem osi Y</param>
	/// <param name="dt">DeltaTime okreslajacy amplitudę wartości</param>
	void translate(float x, float y, float dt);

	/// <summary>
	/// Przeciazenie funkcji translate.
	/// Funckcja przesuwajaca obiekt relatywnie do jego poprzedniej pozycji.
	/// Wyjscie poza ekran jest niemożliwe przy uzyciu tej metody.
	/// Ruch zakonczy sie przy napotkaniu granicy ekranu.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="translation">Wektor dwoch zmiennych typu float zawierajacy przesuniecie</param>
	/// <param name="dt">DeltaTime okreslajacy amplitudę wartości</param>
	void translate(sf::Vector2f translation, float dt);

	/// <summary>
	/// Przeciazenie funkcji translate.
	/// Funckcja przesuwajaca obiekt relatywnie do jego poprzedniej pozycji.
	/// Wyjscie poza ekran jest niemożliwe przy uzyciu tej metody.
	/// Ruch zakonczy sie przy napotkaniu granicy ekranu.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="xy">Przesuniecie o taka sama wartosc po obu osiach</param>
	/// <param name="dt">DeltaTime okreslajacy amplitudę wartości</param>
	void translate(float xy, float dt);

	/// <summary>
	/// Funkcja obrazajace obiekt wzgledem jego punktu {0,0}.
	/// </summary>
	/// <param name="angle">Kat obrotu</param>
	void rotate(float angle);
	
	/// <summary>
	/// Funkcja zwracajaca obecny kat obrotu od pozycji podstawowej
	/// </summary>
	/// <returns>Kat obrotu w stopniach</returns>
	float getRotation();

	/// <summary>
	/// Funkcja ustawiajaca skale obiektu.
	/// Poprzednia wartosc jest nadpisywana jako nowa.
	/// Metoda ma charakter absolutny.
	/// </summary>
	/// <param name="scale">Wartosc skali do ustawienia</param>
	void setScale(float scale);
	
	/// <summary>
	/// Funkcja ustawiajace skale obiektu, uwzgledniajac poprzedni stan.
	/// Nowa wartosc jest dodawana do poprzedniej.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="scale">Wartosc skali do dodania po obu osiach</param>
	void scale(float scale);

	/// <summary>
	/// Przeciazenie funkcji scale.
	/// Funkcja ustawiajace skale obiektu, uwzgledniajac poprzedni stan.
	/// Nowa wartosc jest dodawana do poprzedniej.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="scaleX">Wartosc skali po osi X</param>
	/// <param name="scaleY">Wartosc skali po osi Y</param>
	void scale(float scaleX, float scaleY);

	/// <summary>
	/// Przeciazenie funkcji scale.
	/// Funkcja ustawiajace skale obiektu, uwzgledniajac poprzedni stan.
	/// Nowa wartosc jest dodawana do poprzedniej.
	/// Przekazywany jest wektor wartosci.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="scale">Wektor dwoch zmiennych typu float zawierajacy skale po obu osiach</param>
	void scale(sf::Vector2f scale);
	
	/// <summary>
	/// Funkcja zwracajaca wartosci skali obiektu
	/// </summary>
	/// <returns>Wektor skali obiektu</returns>
	sf::Vector2f getScale();

	/// <summary>
	/// Funkcja ustawiajaca teksture, ktorej obiekt ma uzywac do nalozenia, a potem do renderowania.
	/// </summary>
	/// <param name="texture">Wskaznik na teksture</param>
	void setTexture(sf::Texture* texture);

	/// <summary>
	/// Funkcja ustawiajaca prostokat, wewnatrz ktorego znajduje sie obraz do wyrysowania na ekranie.
	/// Metoda jest szczegolnie przydatna do animowania
	/// </summary>
	/// <param name="rect">Wektor czterech zmiennych okreslajacych wspolrzedne lewego gornego rogu oraz prawego dolnego rogu obszaru.</param>
	void setTextureRect(sf::IntRect rect);

	/// <summary>
	/// Funkcja ustawiajaca kolor tekstury, ktora ma byc renderowana.
	/// Mozna przekazac takze wektor 4 zmiennych jako {RED, GREEN, BLUE, TRANSPARENCY}: 
	/// {255,0,0,1} = czerwony
	/// {0,255,0,1} = zielony
	/// {0,0,255,1} = niebieski
	/// </summary>
	/// <param name="color">Kolor do ustawienia</param>
	void setColor(sf::Color color);
	
	/// <summary>
	/// Funkcja sprawdzajaca czy klikniecie znajduje sie wewnatrz granic obiektu, efektywnie wybierajac go.
	/// Jezeli klikniecie zostalo wykryte oraz pole <b>selected</b> jest ustawione na false, zostaje ono zmienione na <b>True</b>.
	/// Analogicznie gdy pole <b>selected</b> jest ustawione na true, zostanie zamienione na false, blokujac mozliwosc przemieszczania obiektu.
	/// </summary>
	/// <param name="mousePos">Wektor dwoch zmiennych typu calkowitego pozycji myszy na ekranie</param>
	void isPressed(sf::Vector2i mousePos);
};

/// <summary>
/// Klasa \class primitive_square
/// Dziedziczy ona po glownej klasie \class primitive
/// Jest to zbior metod okreslajacych manipulacje kwadratem.
/// </summary>
class primitive_square : public primitive {
	sf::RectangleShape square; ///< Ksztalt prostokatu jako kwadrat
public:
	/// <summary>
	/// Dziedziczenie konstuktora z klasy glownej \class primitive
	/// </summary>
	using primitive::primitive;

	/// <summary>
	/// Funkcja aktualizujaca wartosci graniczne obiektu
	/// </summary>
	void updateEdge();

	/// <summary>
	/// Funkcja rysujaca obiekt bez wypelnienia. 
	/// Jezeli byl poprzednio ustawiony jakis kolor, 
	/// zostaje on nadpisany na kolor przezroczysty, 
	/// transparentny {0, 0, 0, 0}
	/// </summary>
	/// <param name="color">Kolor dla obrysu</param>
	/// <param name="thickness">Grubosc linii obwodu</param>
	void drawSquare(sf::Color color, unsigned int thickness);

	/// <summary>
	/// Funkcja rysujaca obiekt z wypelnieniem.
	/// Kolor obwodu oraz wypelnienia jest taki sam.
	/// </summary>
	/// <param name="color">Kolor wypelnienia i obwodu</param>
	/// <param name="thickness">Grubosc linii obwodu</param>
	void drawFilledSquare(sf::Color color, unsigned int thickness);

	/// <summary>
	/// Funkcja rysujaca obiekt z tekstura.
	/// Kolor wypelnienia nie ma znaczenia.
	/// Grubosc linii jest rowna 0.
	/// </summary>
	/// <param name="texture">Obiekt tekstury ktory ma byc nalozony na ksztalt</param>
	void drawTexturedSquare(sf::Texture texture);

	/// <summary>
	/// Funkcja podstawowa do rysowania obiektu bez zadnych dodatkowych ustawien.
	/// Uzywana jest glownie do narysowania obiektu animowanego.
	/// </summary>
	void draw();

	/// <summary>
	/// Funkcja ustawiajaca pozycje wektora wedlug przekazanego wektora.
	/// Jezeli x < 0 => 0
	/// Jezeli y < 0 => 0
	/// </summary>
	/// <param name="position">Wektor dwoch wartosci typu float oznaczajacych x, y na ekranie</param>
	void setPosition(sf::Vector2f position);

	/// <summary>
	/// Przeciazenie funkcji setPosition.
	/// Metoda przyjmuje dwa parametry ktore sa uzywane do ustawienia pozycji
	/// </summary>
	/// <param name="x">Wspolrzedna x ekranu, jezeli <0 => 0</param>
	/// <param name="y">Wspolrzedna y ekranu, jezeli <0 => 0</param>
	void setPosition(float x, float y);
	
	/// <summary>
	/// Przeciazenie funkcji setPosition.
	/// Metoda przyjmuje jeden parametr.
	/// Uzywana jest wtedy, gdy chcemy ustawic obiekt w rownej odleglosci od gornej krawedzi jak i lewej krawedzi.
	/// </summary>
	/// <param name="xy">Wspolrzedna ekranu która jest zarówno x jak i y, jezeli <0 => 0</param>
	void setPosition(float xy);

	/// <summary>
	/// Funkcja zwracajaca pozycje obiektu.
	/// </summary>
	/// <returns>Wektor dwoch zmiennych typu float</returns>
	sf::Vector2f getPosition();

	/// <summary>
	/// Funkcja zmieniajaca rozmiar obiektu, wzgledem jego poprzedniego rozmiaru.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="newSize">Wektor dwoch zmiennych typu float oznaczajacych wartosc jaka trzeba dodac do obecnego rozmiaru</param>
	void resize(float newSize);
	
	/// <summary>
	/// Funkcja zmieniajaca rozmiar obiektu, nadpisuje jego poprzednia wartosc.
	/// Metoda ma charakter absolutny.
	/// </summary>
	/// <param name="newSize">Nowy rozmiar ktory zostanie uzyty do nadpisania poprzedniej wartosci</param>
	void setSize(float newSize);

	/// <summary>
	/// Funkcja zwracaja rozmiar kwadratu.
	/// </summary>
	/// <returns>Rozmiar sciany kwadratu</returns>
	float getSize();

	/// <summary>
	/// Funkcja zwracajaca szerokosc obiektu jako int.
	/// </summary>
	/// <returns>Wartosc szerokosci obiektu</returns>
	int getSizeX();

	/// <summary>
	/// Funkcja zwracajaca wysokosc obiektu jako int.
	/// </summary>
	/// <returns>Wartosc wysokosci obiektu</returns>
	int getSizeY();

	/// Funckcja przesuwajaca obiekt relatywnie do jego poprzedniej pozycji.
	/// Wyjscie poza ekran jest niemożliwe przy uzyciu tej metody.
	/// Ruch zakonczy sie przy napotkaniu granicy ekranu.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="x">Przesuniecie wzgledem osi X</param>
	/// <param name="y">Przesuniecie wzgledem osi Y</param>
	/// <param name="dt">DeltaTime okreslajacy amplitudę wartości</param>
	void translate(float x, float y, float dt);

	/// <summary>
	/// Przeciazenie funkcji translate.
	/// Funckcja przesuwajaca obiekt relatywnie do jego poprzedniej pozycji.
	/// Wyjscie poza ekran jest niemożliwe przy uzyciu tej metody.
	/// Ruch zakonczy sie przy napotkaniu granicy ekranu.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="translation">Wektor dwoch zmiennych typu float zawierajacy przesuniecie</param>
	/// <param name="dt">DeltaTime okreslajacy amplitudę wartości</param>
	void translate(sf::Vector2f translation, float dt);

	/// <summary>
	/// Przeciazenie funkcji translate.
	/// Funckcja przesuwajaca obiekt relatywnie do jego poprzedniej pozycji.
	/// Wyjscie poza ekran jest niemożliwe przy uzyciu tej metody.
	/// Ruch zakonczy sie przy napotkaniu granicy ekranu.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="xy">Przesuniecie o taka sama wartosc po obu osiach</param>
	/// <param name="dt">DeltaTime okreslajacy amplitudę wartości</param>
	void translate(float xy, float dt);

	/// <summary>
	/// Funkcja obrazajace obiekt wzgledem jego punktu {0,0}.
	/// </summary>
	/// <param name="angle">Kat obrotu</param>
	/// <param name="dt">DeltaTime okreslajacy amplitudę wartości</param>
	void rotate(float angle, float dt);

	/// <summary>
	/// Funkcja zwracajaca obecny kat obrotu od pozycji podstawowej
	/// </summary>
	/// <returns>Kat obrotu w stopniach</returns>
	float getRotation();

	/// <summary>
	/// Funkcja ustawiajaca skale obiektu.
	/// Poprzednia wartosc jest nadpisywana jako nowa.
	/// Metoda ma charakter absolutny.
	/// </summary>
	/// <param name="scale">Wartosc skali do ustawienia</param>
	void setScale(float scale);

	/// <summary>
	/// Funkcja ustawiajace skale obiektu, uwzgledniajac poprzedni stan.
	/// Nowa wartosc jest dodawana do poprzedniej.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="scale">Wartosc skali do dodania po obu osiach</param>
	void scale(float scale);

	/// <summary>
	/// Przeciazenie funkcji scale.
	/// Funkcja ustawiajace skale obiektu, uwzgledniajac poprzedni stan.
	/// Nowa wartosc jest dodawana do poprzedniej.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="scaleX">Wartosc skali po osi X</param>
	/// <param name="scaleY">Wartosc skali po osi Y</param>
	void scale(float scaleX, float scaleY);

	/// <summary>
	/// Przeciazenie funkcji scale.
	/// Funkcja ustawiajace skale obiektu, uwzgledniajac poprzedni stan.
	/// Nowa wartosc jest dodawana do poprzedniej.
	/// Przekazywany jest wektor wartosci.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="scale">Wektor dwoch zmiennych typu float zawierajacy skale po obu osiach</param>
	void scale(sf::Vector2f scale);

	/// <summary>
	/// Funkcja zwracajaca wartosci skali obiektu
	/// </summary>
	/// <returns>Wektor skali obiektu</returns>
	sf::Vector2f getScale();

	/// <summary>
	/// Funkcja ustawiajaca teksture, ktorej obiekt ma uzywac do nalozenia, a potem do renderowania.
	/// </summary>
	/// <param name="texture">Wskaznik na teksture</param>
	void setTexture(sf::Texture* texture);

	/// <summary>
	/// Funkcja ustawiajaca prostokat, wewnatrz ktorego znajduje sie obraz do wyrysowania na ekranie.
	/// Metoda jest szczegolnie przydatna do animowania
	/// </summary>
	/// <param name="rect">Wektor czterech zmiennych okreslajacych wspolrzedne lewego gornego rogu oraz prawego dolnego rogu obszaru.</param>
	void setTextureRect(sf::IntRect rect);

	/// <summary>
	/// Funkcja ustawiajaca kolor tekstury, ktora ma byc renderowana.
	/// Mozna przekazac takze wektor 4 zmiennych jako {RED, GREEN, BLUE, TRANSPARENCY}: 
	/// {255,0,0,1} = czerwony
	/// {0,255,0,1} = zielony
	/// {0,0,255,1} = niebieski
	/// </summary>
	/// <param name="color">Kolor do ustawienia</param>
	void setColor(sf::Color color);

	/// <summary>
	/// Funkcja sprawdzajaca czy klikniecie znajduje sie wewnatrz granic obiektu, efektywnie wybierajac go.
	/// Jezeli klikniecie zostalo wykryte oraz pole <b>selected</b> jest ustawione na false, zostaje ono zmienione na <b>True</b>.
	/// Analogicznie gdy pole <b>selected</b> jest ustawione na true, zostanie zamienione na false, blokujac mozliwosc przemieszczania obiektu.
	/// </summary>
	/// <param name="mousePos">Wektor dwoch zmiennych typu calkowitego pozycji myszy na ekranie</param>
	void isPressed(sf::Vector2i mousePos);
};

/// <summary>
/// Klasa \class primitive_triangle
/// Zawiera zawiera metody do obslugi i manipulacji trojkatem
/// </summary>
class primitive_triangle : public primitive {
	sf::CircleShape triangle;///<Ksztalt trojkata
public:
	/// <summary>
	/// Dziedziczenie konstuktora z klasy glownej \class primitive
	/// </summary>
	using primitive::primitive;

	/// <summary>
	/// Funkcja aktualizujaca wartosci graniczne obiektu
	/// </summary>
	void updateEdge();
	
	/// <summary>
	/// Funkcja rysujaca obiekt bez wypelnienia. 
	/// Jezeli byl poprzednio ustawiony jakis kolor, zostaje on nadpisany na kolor przezroczysty, transparentny {0, 0, 0, 0}
	/// </summary>
	/// <param name="color">Kolor dla obrysu</param>
	/// <param name="thickness">Grubosc linii obwodu</param>
	/// <param name="radius">Promien trojkata</param>
	void drawTriangle(sf::Color color, unsigned int thickness, unsigned int radius);
	
	/// <summary>
	/// Funkcja rysujaca obiekt z wypelnieniem.
	/// Kolor obwodu oraz wypelnienia jest taki sam.
	/// </summary>
	/// <param name="color">Kolor wypelnienia i obwodu</param>
	/// <param name="thickness">Grubosc linii obwodu</param>
	/// <param name="radius">Promien trojkata</param>
	void drawFIlledTriangle(sf::Color color, unsigned int thickness, unsigned int radius);
	
	/// <summary>
	/// Funkcja rysujaca obiekt z tekstura.
	/// Kolor wypelnienia nie ma znaczenia.
	/// Grubosc linii jest rowna 0.
	/// </summary>
	/// <param name="texture">Obiekt tekstury ktory ma byc nalozony na ksztalt</param>
	void drawTexturedTriangle(sf::Texture texture);
	
	/// <summary>
	/// Funkcja podstawowa do rysowania obiektu bez zadnych dodatkowych ustawien.
	/// Uzywana jest glownie do narysowania obiektu animowanego.
	/// </summary>
	void draw();

	/// <summary>
	/// Funkcja ustawiajaca pozycje wektora wedlug przekazanego wektora.
	/// Jezeli x < 0 => 0
	/// Jezeli y < 0 => 0
	/// </summary>
	/// <param name="position">Wektor dwoch wartosci typu float oznaczajacych x, y na ekranie</param>
	void setPosition(sf::Vector2f position);
	
	/// <summary>
	/// Funkcja zwracajaca pozycje obiektu.
	/// </summary>
	/// <returns>Wektor dwoch zmiennych typu float</returns>
	sf::Vector2f getPosition();

	/// <summary>
	/// Funkcja zmieniajaca szerokosc trojkata.
	/// Jest to wykonywanie na bazie koła.
	/// Rozmiar to inaczej promień.
	/// </summary>
	/// <param name="newSize">Nowy rozmiar dodany do obecnego</param>
	void resize(float newSize);
	
	/// <summary>
	/// Funkcja zmieniajaca szerokosc trojkata.
	/// Jest to wykonywanie na bazie koła.
	/// Rozmiar to inaczej promień.
	/// Rozmiar jest także nadpisywany.
	/// </summary>
	/// <param name="newSize">Nowy rozmiar do nadpisania obecnego</param>
	void setSize(float newSize);
	
	/// <summary>
	/// Funkcja zwracająca promień trojkata.
	/// </summary>
	/// <returns>Promień trojkata</returns>
	float getSize();

	/// <summary>
	/// Funkcja zwracajaca szerokosc obiektu jako int.
	/// </summary>
	/// <returns>Wartosc szerokosci obiektu</returns>
	int getSizeX();

	/// <summary>
	/// Funkcja zwracajaca wysokosc obiektu jako int.
	/// </summary>
	/// <returns>Wartosc wysokosci obiektu</returns>
	int getSizeY();

	/// <summary>
	/// Funckcja przesuwajaca obiekt relatywnie do jego poprzedniej pozycji.
	/// Wyjscie poza ekran jest niemożliwe przy uzyciu tej metody.
	/// Ruch zakonczy sie przy napotkaniu granicy ekranu.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="x">Przesuniecie wzgledem osi X</param>
	/// <param name="y">Przesuniecie wzgledem osi Y</param>
	/// <param name="dt">DeltaTime okreslajacy amplitudę wartości</param>
	void translate(float x, float y, float dt);

	/// <summary>
	/// Przeciazenie funkcji translate.
	/// Funckcja przesuwajaca obiekt relatywnie do jego poprzedniej pozycji.
	/// Wyjscie poza ekran jest niemożliwe przy uzyciu tej metody.
	/// Ruch zakonczy sie przy napotkaniu granicy ekranu.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="translation">Wektor dwoch zmiennych typu float zawierajacy przesuniecie</param>
	/// <param name="dt">DeltaTime okreslajacy amplitudę wartości</param>
	void translate(sf::Vector2f translation, float dt);

	/// <summary>
	/// Przeciazenie funkcji translate.
	/// Funckcja przesuwajaca obiekt relatywnie do jego poprzedniej pozycji.
	/// Wyjscie poza ekran jest niemożliwe przy uzyciu tej metody.
	/// Ruch zakonczy sie przy napotkaniu granicy ekranu.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="xy">Przesuniecie o taka sama wartosc po obu osiach</param>
	/// <param name="dt">DeltaTime okreslajacy amplitudę wartości</param>
	void translate(float xy, float dt);
	/// <summary>
	/// Funkcja obrazajace obiekt wzgledem jego punktu {0,0}.
	/// </summary>
	/// <param name="angle">Kat obrotu</param>
	/// <param name="dt>DeltaTime okreslajacy amplitudę wartości</param>
	void rotate(float angle, float dt);

	/// <summary>
	/// Funkcja ustawiajaca skale obiektu.
	/// Poprzednia wartosc jest nadpisywana jako nowa.
	/// Metoda ma charakter absolutny.
	/// </summary>
	/// <param name="scale">Wartosc skali do ustawienia</param>
	void setScale(float scale);

	/// <summary>
	/// Funkcja ustawiajace skale obiektu, uwzgledniajac poprzedni stan.
	/// Nowa wartosc jest dodawana do poprzedniej.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="scale">Wartosc skali do dodania po obu osiach</param>
	void scale(float scale);

	/// <summary>
	/// Przeciazenie funkcji scale.
	/// Funkcja ustawiajace skale obiektu, uwzgledniajac poprzedni stan.
	/// Nowa wartosc jest dodawana do poprzedniej.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="scaleX">Wartosc skali po osi X</param>
	/// <param name="scaleY">Wartosc skali po osi Y</param>
	void scale(float scaleX, float scaleY);

	/// <summary>
	/// Przeciazenie funkcji scale.
	/// Funkcja ustawiajace skale obiektu, uwzgledniajac poprzedni stan.
	/// Nowa wartosc jest dodawana do poprzedniej.
	/// Przekazywany jest wektor wartosci.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="scale">Wektor dwoch zmiennych typu float zawierajacy skale po obu osiach</param>
	void scale(sf::Vector2f scale);

	/// <summary>
	/// Funkcja zwracajaca wartosci skali obiektu
	/// </summary>
	/// <returns>Wektor skali obiektu</returns>
	sf::Vector2f getScale();

	/// <summary>
	/// Funkcja ustawiajaca teksture, ktorej obiekt ma uzywac do nalozenia, a potem do renderowania.
	/// </summary>
	/// <param name="texture">Wskaznik na teksture</param>
	void setTexture(sf::Texture* texture);

	/// <summary>
	/// Funkcja ustawiajaca prostokat, wewnatrz ktorego znajduje sie obraz do wyrysowania na ekranie.
	/// Metoda jest szczegolnie przydatna do animowania
	/// </summary>
	/// <param name="rect">Wektor czterech zmiennych okreslajacych wspolrzedne lewego gornego rogu oraz prawego dolnego rogu obszaru.</param>
	void setTextureRect(sf::IntRect rect);

	/// <summary>
	/// Funkcja ustawiajaca kolor tekstury, ktora ma byc renderowana.
	/// Mozna przekazac takze wektor 4 zmiennych jako {RED, GREEN, BLUE, TRANSPARENCY}: 
	/// {255,0,0,1} = czerwony
	/// {0,255,0,1} = zielony
	/// {0,0,255,1} = niebieski
	/// </summary>
	/// <param name="color">Kolor do ustawienia</param>
	void setColor(sf::Color color);
};

/// <summary>
/// \class primitive_rectangle
/// Dziedziczy ona konstrukor oraz pola do obslugi obiektu.
/// Implementuje swoje metody zgodne z ksztaltem obiektu.
/// W tym wypadku jest to trojkat Metody pozwalaja na manipulacje pozycji, obrotu, kolorow oraz wiele wiecej.
/// </summary>
class primitive_circle : public primitive {
	sf::CircleShape circle;///< Obiekt o ksztalcie kola
public:
	/// <summary>
	/// Dziedziczenie konstuktora z klasy glownej \class primitive
	/// </summary>
	using primitive::primitive;
	
	/// <summary>
	/// Funkcja aktualizujaca wartosci graniczne obiektu
	/// </summary>
	void updateEdge();
	
	/// <summary>
	/// Funkcja rysujaca obiekt bez wypelnienia. 
	/// Jezeli byl poprzednio ustawiony jakis kolor, zostaje on nadpisany na kolor przezroczysty, transparentny {0, 0, 0, 0}
	/// </summary>
	/// <param name="color">Kolor dla obrysu</param>
	/// <param name="thickness">Grubosc linii obwodu</param>
	/// <param name="radius">Promien kola</param>
	void drawCircle(sf::Color color, unsigned int thickness, unsigned int radius);
	
	/// <summary>
	/// Funkcja rysujaca obiekt z wypelnieniem.
	/// Kolor obwodu oraz wypelnienia jest taki sam.
	/// </summary>
	/// <param name="color">Kolor wypelnienia i obwodu</param>
	/// <param name="thickness">Grubosc linii obwodu</param>
	/// <param name="radius">Promien kola</param>
	void drawFilledCircle(sf::Color color, unsigned int thickness, unsigned int radius);
	
	/// <summary>
	/// Funkcja rysujaca obiekt z tekstura.
	/// Kolor wypelnienia nie ma znaczenia.
	/// Grubosc linii jest rowna 0.
	/// </summary>
	/// <param name="texture">Obiekt tekstury ktory ma byc nalozony na ksztalt</param>
	void drawTexturedCircle(sf::Texture texture);
	
	/// <summary>
	/// Funkcja podstawowa do rysowania obiektu bez zadnych dodatkowych ustawien.
	/// Uzywana jest glownie do narysowania obiektu animowanego.
	/// </summary>
	void draw();

	/// <summary>
/// Funkcja ustawiajaca pozycje wektora wedlug przekazanego wektora.
/// Jezeli x < 0 => 0
/// Jezeli y < 0 => 0
/// </summary>
/// <param name="position">Wektor dwoch wartosci typu float oznaczajacych x, y na ekranie</param>
	void setPosition(sf::Vector2f position);

	/// <summary>
	/// Funkcja zwracajaca pozycje obiektu.
	/// </summary>
	/// <returns>Wektor dwoch zmiennych typu float</returns>
	sf::Vector2f getPosition();

	/// <summary>
	/// Funkcja zmieniajaca szerokosc trojkata.
	/// Jest to wykonywanie na bazie koła.
	/// Rozmiar to inaczej promień.
	/// </summary>
	/// <param name="newSize">Nowy rozmiar dodany do obecnego</param>
	void resize(float newSize);

	/// <summary>
	/// Funkcja zmieniajaca szerokosc trojkata.
	/// Jest to wykonywanie na bazie koła.
	/// Rozmiar to inaczej promień.
	/// Rozmiar jest także nadpisywany.
	/// </summary>
	/// <param name="newSize">Nowy rozmiar do nadpisania obecnego</param>
	void setSize(float newSize);

	/// <summary>
	/// Funkcja zwracająca promień trojkata.
	/// </summary>
	/// <returns>Promień trojkata</returns>
	float getSize();

	/// <summary>
	/// Funkcja zwracajaca szerokosc obiektu jako int.
	/// </summary>
	/// <returns>Wartosc szerokosci obiektu</returns>
	int getSizeX();

	/// <summary>
	/// Funkcja zwracajaca wysokosc obiektu jako int.
	/// </summary>
	/// <returns>Wartosc wysokosci obiektu</returns>
	int getSizeY();

	/// <summary>
	/// Funckcja przesuwajaca obiekt relatywnie do jego poprzedniej pozycji.
	/// Wyjscie poza ekran jest niemożliwe przy uzyciu tej metody.
	/// Ruch zakonczy sie przy napotkaniu granicy ekranu.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="x">Przesuniecie wzgledem osi X</param>
	/// <param name="y">Przesuniecie wzgledem osi Y</param>
	/// <param name="dt">DeltaTime okreslajacy amplitudę wartości</param>
	void translate(float x, float y, float dt);

	/// <summary>
	/// Przeciazenie funkcji translate.
	/// Funckcja przesuwajaca obiekt relatywnie do jego poprzedniej pozycji.
	/// Wyjscie poza ekran jest niemożliwe przy uzyciu tej metody.
	/// Ruch zakonczy sie przy napotkaniu granicy ekranu.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="translation">Wektor dwoch zmiennych typu float zawierajacy przesuniecie</param>
	/// <param name="dt">DeltaTime okreslajacy amplitudę wartości</param>
	void translate(sf::Vector2f translation, float dt);

	/// <summary>
	/// Przeciazenie funkcji translate.
	/// Funckcja przesuwajaca obiekt relatywnie do jego poprzedniej pozycji.
	/// Wyjscie poza ekran jest niemożliwe przy uzyciu tej metody.
	/// Ruch zakonczy sie przy napotkaniu granicy ekranu.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="xy">Przesuniecie o taka sama wartosc po obu osiach</param>
	/// <param name="dt">DeltaTime okreslajacy amplitudę wartości</param>
	void translate(float xy, float dt);
	/// <summary>
	/// Funkcja obrazajace obiekt wzgledem jego punktu {0,0}.
	/// </summary>
	/// <param name="angle">Kat obrotu</param>
	/// <param name="dt>DeltaTime okreslajacy amplitudę wartości</param>
	void rotate(float angle, float dt);

	/// <summary>
	/// Funkcja ustawiajaca skale obiektu.
	/// Poprzednia wartosc jest nadpisywana jako nowa.
	/// Metoda ma charakter absolutny.
	/// </summary>
	/// <param name="scale">Wartosc skali do ustawienia</param>
	void setScale(float scale);

	/// <summary>
	/// Funkcja ustawiajace skale obiektu, uwzgledniajac poprzedni stan.
	/// Nowa wartosc jest dodawana do poprzedniej.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="scale">Wartosc skali do dodania po obu osiach</param>
	void scale(float scale);

	/// <summary>
	/// Przeciazenie funkcji scale.
	/// Funkcja ustawiajace skale obiektu, uwzgledniajac poprzedni stan.
	/// Nowa wartosc jest dodawana do poprzedniej.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="scaleX">Wartosc skali po osi X</param>
	/// <param name="scaleY">Wartosc skali po osi Y</param>
	void scale(float scaleX, float scaleY);

	/// <summary>
	/// Przeciazenie funkcji scale.
	/// Funkcja ustawiajace skale obiektu, uwzgledniajac poprzedni stan.
	/// Nowa wartosc jest dodawana do poprzedniej.
	/// Przekazywany jest wektor wartosci.
	/// Metoda ma charakter addytywny.
	/// </summary>
	/// <param name="scale">Wektor dwoch zmiennych typu float zawierajacy skale po obu osiach</param>
	void scale(sf::Vector2f scale);

	/// <summary>
	/// Funkcja zwracajaca wartosci skali obiektu
	/// </summary>
	/// <returns>Wektor skali obiektu</returns>
	sf::Vector2f getScale();

	/// <summary>
	/// Funkcja ustawiajaca teksture, ktorej obiekt ma uzywac do nalozenia, a potem do renderowania.
	/// </summary>
	/// <param name="texture">Wskaznik na teksture</param>
	void setTexture(sf::Texture* texture);

	/// <summary>
	/// Funkcja ustawiajaca prostokat, wewnatrz ktorego znajduje sie obraz do wyrysowania na ekranie.
	/// Metoda jest szczegolnie przydatna do animowania
	/// </summary>
	/// <param name="rect">Wektor czterech zmiennych okreslajacych wspolrzedne lewego gornego rogu oraz prawego dolnego rogu obszaru.</param>
	void setTextureRect(sf::IntRect rect);

	/// <summary>
	/// Funkcja ustawiajaca kolor tekstury, ktora ma byc renderowana.
	/// Mozna przekazac takze wektor 4 zmiennych jako {RED, GREEN, BLUE, TRANSPARENCY}: 
	/// {255,0,0,1} = czerwony
	/// {0,255,0,1} = zielony
	/// {0,0,255,1} = niebieski
	/// </summary>
	/// <param name="color">Kolor do ustawienia</param>
	void setColor(sf::Color color);
};

/// <summary>
/// Klasa \class primitive_line
/// Tworzy linie na ekranie o podanych wspolrzednych.
/// </summary>
class primitive_line : public primitive {
	sf::Vertex line[2];///<Vertex linii o 2 wspolrzednych
public:
	/// <summary>
	/// Dziedziczenie konstuktora z klasy glownej \class primitive
	/// </summary>
	using primitive::primitive;

	/// <summary>
	/// Tworzenie linii o grubosci 1px pomiedzy dwoma punktami na ekranie
	/// </summary>
	/// <param name="color">Kolor linii</param>
	void drawLine(sf::Color color);

	/// <summary>
	/// Tworzenie linii o grubosci przekazanej do funkcji.
	/// Linia jest przesuwana o 1px w prawo i rysowana kolejny raz
	/// </summary>
	/// <param name="color">Kolor linii</param>
	/// <param name="thickness">Grubosc linii</param>
	void drawThickLine(sf::Color color, unsigned int thickness);

	/// <summary>
	/// Funkcja ustawiająca pozycje linii o podanych wspolrzednych.
	/// Przekazane parametry nadpisuja poprzednia wartosc
	/// </summary>
	/// <param name="point1">Pozycja x,y punktu 1</param>
	/// <param name="point2">Pozycja x,y punktu 2</param>
	void setPosition(sf::Vector2f point1, sf::Vector2f point2);

	/// <summary>
	/// Funkcja przesuwajaca linie wzgledem poprzedniej pozycji
	/// Parametry sa dodawane do poprzedniej pozycji
	/// </summary>
	/// <param name="newPoint1">Wektor przesuniecia</param>
	/// <param name="newPoint2">Wektor przesuniecia</param>
	void translate(sf::Vector2f newPoint1, sf::Vector2f newPoint2);

	/// <summary>
	/// Funkcja obracajaca linie o zadany kat
	/// </summary>
	/// <param name="angle">Kat obrotu</param>
	/// <param name="dt">DeltaTime okreslajacy amplitudę wartości</param>
	void rotate(float angle, float dt);
};

class primitive_convex : public primitive {
	sf::ConvexShape convex;///< Obiekt o ksztalcie wypulkym
public:
	/// <summary>
	/// Dziedziczenie konstuktora z klasy glownej \class primitive
	/// </summary>
	using primitive::primitive;
	
	/// <summary>
	/// Funkcja rysujaca do bufora obiekt.
	/// Podanie punktu gdzies pomiedzy wszystkimi nic nie daje.
	/// Taki punkt zostanie narysowany, jednak ze jest to typ wypukly,
	/// rysowany jest obwod po najdalszych punktach.
	/// </summary>
	/// <param name="color">Kolor obwodu</param>
	/// <param name="thickness">Grubosc obwodu</param>
	void drawConvex(sf::Color color, float thickness);

	/// <summary>
	/// Funkcja rysujaca obiekt wypukly z wypelnieniem.
	/// Podanie punktu gdzies pomiedzy wszystkimi nic nie daje.
	/// Taki punkt zostanie narysowany, jednak ze jest to typ wypukly,
	/// rysowany jest obwod po najdalszych punktach.
	/// </summary>
	/// <param name="color">Kolor obwodu i wypelnienia</param>
	/// <param name="thickness">Grubosc obwodu</param>
	void drawFilledConvex(sf::Color color, float thickness);

	/// <summary>
	/// Ustawienie pozycji punktu o podanym indexie.
	/// </summary>
	/// <param name="index">Indeks punktu</param>
	/// <param name="point">Nowe wspolrzedne punktu</param>
	void setPoint(unsigned int index, sf::Vector2f point);

	/// <summary>
	/// Przeciazenie funkcji setPoint.
	/// Ustawienie pozycji punktu o podanym indexie
	/// </summary>
	/// <param name="index">Indeks punktu</param>
	/// <param name="pointX">Nowa wspolrzedna x</param>
	/// <param name="pointY">Nowa wspolrzedna y</param>
	void setPoint(unsigned int index, float pointX, float pointY);

	/// <summary>
	/// Ustawienie liczby punktow w ksztalcie
	/// Liczba musi byc wieksza od 2.
	/// </summary>
	/// <param name="pointCount">Liczba punktow</param>
	void setPointCount(unsigned int pointCount);

	/// <summary>
	/// Zaladowanie wektora punktow ze wspolrzednymi.
	/// </summary>
	/// <param name="pointPosition">Wektor wektorow o dwoch wspolrzednych typu float</param>
	void setPointPosition(std::vector<sf::Vector2f> pointPosition);

	/// <summary>
	/// Funkcja zwracajaca liczbe punktow obiektu
	/// </summary>
	/// <returns>Liczba punktow</returns>
	int getPointCount();

	/// <summary>
	/// Funkcja zwracajaca punkt z wektora punktow o podanym indeksie
	/// </summary>
	/// <param name="index">Indeks punktu</param>
	/// <returns>Wektor wspolrzednych punktu</returns>
	sf::Vector2f getPoint(unsigned int index);

	/// <summary>
	/// Funkcja zwracajaca wektor wektorow ze wspolrzednymi punktow
	/// </summary>
	/// <returns></returns>
	std::vector<sf::Vector2f> getPointsPosition();

	/// <summary>
	/// Ustawienie pozycji calego ksztaltu.
	/// Pozycja nadpisuje poprzednia.
	/// </summary>
	/// <param name="position">Wektor dwoch zmiennych typu float</param>
	void setPosition(sf::Vector2f position);

	/// <summary>
	/// Ustawienie pozycji calego ksztaltu.
	/// Pozycja nadpisuje poprzednia.
	/// </summary>
	/// <param name="newX">Nowa wspolrzedna x</param>
	/// <param name="newY">Nowa wspolrzedna y</param>
	void setPosition(float newX, float newY);

	/// <summary>
	/// Ustawienie pozycji calego ksztaltu
	/// Pozycja nadpisuje poprzednia
	/// </summary>
	/// <param name="newXY">Nowa wspolrzedna ustawiajaca obie osie jednoczesnie</param>
	void setPosition(float newXY);

	/// <summary>
	/// Pozyskanie pozycji calego obiektu
	/// </summary>
	/// <returns>Wektor dwoch zmiennych typu float</returns>
	sf::Vector2f getPosition();

	/// <summary>
	/// Przesuniecie o podany wektor przesuniecia.
	/// Do obecnej pozycji dodawany jest przekazany wektor.
	/// </summary>
	/// <param name="tranlstaion">Wektor dwoch zmiennych typu float</param>
	/// <param name="dt">DeltaTime okreslajacy amplitudę wartosci</param>
	void translate(sf::Vector2f tranlstaion, float dt);

	/// <summary>
	/// Przesuniecie o podany wektor przesuniecia.
	/// Do obecnej pozycji dodawany jest przekazany wektor.
	/// </summary>
	/// <param name="newX">Wspolrzedna x do dodania</param>
	/// <param name="newY">Wspolrzedna y do dodania</param>
	/// <param name="dt">DeltaTime okreslajacy amplitudę wartosci</param>
	void translate(float newX, float newY, float dt);

	/// <summary>
	/// Obrocenie obiektu o zadany kat w stopniach
	/// </summary>
	/// <param name="angle">Kat obrotu w stopniach</param>
	void rotate(float angle);
	
	/// <summary>
	/// Pozyskanie obecnego katu obrotu w stopniach
	/// </summary>
	/// <returns>Wartosc typu float jako kat w stopniach</returns>
	float getRotation();

	/// <summary>
	/// Ustawienie skali obiektu.
	/// </summary>
	/// <param name="scale">Wektor dwoch zmiennych typu float okreslajacych wartosci skali osi</param>
	void setScale(sf::Vector2f scale);

	/// <summary>
	/// Ustawienie skali typem addytywnym.
	/// Przekazana wartosc jest dodawana do obecnej skali.
	/// </summary>
	/// <param name="scale">Wartosc skali do dodania</param>
	void scale(sf::Vector2f scale);

	/// <summary>
	/// Pozyskanie wartosci skali obiektu.
	/// </summary>
	/// <returns>Wektor dwoch zmiennych typu float jako wektor skali</returns>
	sf::Vector2f getScale();
};