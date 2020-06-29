#include <iostream>
#include <typeinfo>

using namespace std;

class Receiver {
public:
    void Action() {
        cout << "Reciever::Action..." << endl;
    }

    void Undo() {
        cout << "Reciever::Undo..." << endl;
    }
};

template <typename receiverInterface>
class ConcreteCommand {
public:
    ConcreteCommand(receiverInterface rev) {
        _rev = rev;
    }

    void Excute() {
        _rev.Action();
    }

private:
    receiverInterface _rev;
};

template <typename receiverInterface>
class UndoCommand {
public:
    UndoCommand(receiverInterface rev) {
        _rev = rev;
    }  

    void Excute() {
        _rev.Undo();
    }

private:
    receiverInterface _rev;
};

template <class commandInterface>
class Invoker {
public:

    void Invoke(commandInterface& Tfunc) {
        Tfunc.Excute();
    }

};

using ACTION_COMMAND = ConcreteCommand<Receiver>;
using UNDO_COMMAND   = UndoCommand<Receiver>;

int main() {

    Receiver _receiver;
    Invoker<ACTION_COMMAND> invaction;
    ACTION_COMMAND cmdaction(_receiver);
    invaction.Invoke(cmdaction);

    Invoker<UNDO_COMMAND> invundo;  
    UNDO_COMMAND cmdundo(_receiver);
    invundo.Invoke(cmdundo);

    return 0;
}

