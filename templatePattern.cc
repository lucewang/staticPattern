#include <iostream>
using namespace std;

template<typename concreteclass>
class AbstractClass {
public:
    virtual void TemplateMethod() {
        static_cast<concreteclass&>(*this).PrimitiveOperation1();
        static_cast<concreteclass&>(*this).PrimitiveOperation2();        
    }

    virtual ~AbstractClass() { }
protected:
    virtual void PrimitiveOperation1() = 0;
    virtual void PrimitiveOperation2() = 0;
    AbstractClass() { }
};

class ConcreteClass1 :public AbstractClass<ConcreteClass1> {
public:
    void PrimitiveOperation1() {
        cout << "ConcreteClass1::PrimitiveOperation1" << endl;
    }

    void PrimitiveOperation2() {
        cout << "ConcreteClass1::PrimitiveOperation2" << endl;
    }
};

class ConcreteClass2 :public AbstractClass<ConcreteClass2> {
public:
    void PrimitiveOperation1() {
        cout << "ConcreteClass2::PrimitiveOperation1" << endl;
    }

    void PrimitiveOperation2() {
        cout << "ConcreteClass2::PrimitiveOperation2" << endl;
    }
};



int main() {
    AbstractClass<ConcreteClass1> *p1 = new ConcreteClass1();
    AbstractClass<ConcreteClass2> *p2 = new ConcreteClass2();
    p1->TemplateMethod();
    p2->TemplateMethod();

    delete p1;
    delete p2;

    return 0;
}

