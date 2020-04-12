struct Popup {
 Popup(int x1, int y1, int x2, int y2) 			{/* збереження координат*/}
 virtual ~Popup() 						{/*відновлення перекривання*/}
};
struct PopupWin{
 PopupWin() : pop(1, 2, 10, 40) { }
 Popup pop;
 void Out(char* mes)					 	{/*побудова вмісту вікна і відображення вікна*/ }
~PopupWin() 							{/* знищення вмісту вікна*/ }
};


int main(){
 PopupWin pw;
 pw.Out("Error");
}
