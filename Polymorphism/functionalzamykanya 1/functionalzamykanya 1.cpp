// functionalzamykanya 1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

struct Popup {
public:
	Popup(int x1, int y1, int x2, int y2) {/* збереження координат*/}
		virtual void Out() = 0;
		virtual ~Popup() {/*відновлення перекривання*/}
};
struct PopupWin : public Popup	{
	PopupWin() : Popup(1, 10, 20, 30)
 	{/*побудова вмісту вікна*/}
    void Out()	{/* вивід*/ }
	~PopupWin(){/* знищення вмісту вікна*/}
};
void main()  {
	PopupWin w;
	w.Out();
}
