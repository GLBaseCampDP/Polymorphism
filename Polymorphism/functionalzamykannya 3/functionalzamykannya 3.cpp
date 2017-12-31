// functionalzamykannya 3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <String>

struct Popup {
	Popup(int x1, int y1, int x2, int y2)
	{/* збереження координат*/}
	virtual ~Popup() {/*відновлення перекривання*/}
};

struct PopupWin	{
	PopupWin() : pop(1, 2, 10, 40) { }
	Popup pop;
	void Out(char* mes) {
		//побудова вмісту вікна
		//відображення вікна
	}
	~PopupWin() {/* знищення вмісту вікна*/ }
};
	
void main()	{
	PopupWin pw;
	pw.Out("Error");
}
