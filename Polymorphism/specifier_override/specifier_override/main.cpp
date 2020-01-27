    struct A {
    // оголошення віртуальних функцій
    virtual int f() { return 1; };
    virtual int f1() { return 1; };
    // віртуальний метод не може бути з сv
    //virtual int f3() const { return 1; };
    //virtual int f3() volatile { return 1; };
    virtual int f4() { return 1; };
    };

    struct B : A {
    // неявний override на cv дозволено
    int f() const volatile { return 1; };
    // явний override на cv заборонено
    //virtual int f1() const override {return 1;};
    int f1() override { return 1; };
    // допускається одночасно override і final
    // у будь-якій послідовності
    //int f4() override final { return 1; };
    int f4() final override { return 1; };
    };

    struct C : B {
    // заборонений override
    //int f() const volatile override {return 1;};
    // дозволений override
    //int f() override { return 1; };
    //int f() { return 1; };
    int f() const volatile { return 1; };
    };
    int main(){}
