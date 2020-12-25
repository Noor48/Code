#include <iostream>
using namespace std;

class BasicCar
{
public:
    void start()
    {
        cout << "Car Started" << endl;
    }
};

class AdvanceCar : public BasicCar
{
public:
    void playMusic()
    {
        cout << "Music playing " << endl;
    }
};

int main()
{
    AdvanceCar a;
    BasicCar *p = &a;
    a.start();
    a.playMusic();
    p->start();
    //p->playMusic();

    return 0;
}