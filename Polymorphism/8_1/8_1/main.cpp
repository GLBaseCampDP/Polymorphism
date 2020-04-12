struct B;
struct O {};


struct A {
// оголошення віртуальних функцій
virtual A* GetA() { return this; };
virtual B* GetB() { return nullptr; };
virtual const  int GetInt() { return 1; };
};


struct B: A {
// обидва правильні override
//A* GetA() { return this; };
B* GetA() { return this; };
// не коваріантні типи повернення
//O* GetA() { return this; };
//const B* GetA() { return this; };


// не коваріантний тип повернення
//A* GetB() { return this; };
// правильний override
B* GetB() { return this; };


// правильний override
const int GetInt() { return 1; };
// не коваріантний тип повернення
//int GetInt() { return 1; };
// не коваріантний тип повернення
//char GetInt() { return 1; };
// не коваріантний тип повернення
//const char GetInt() { return 1; };
};


int main() { return 0; }

