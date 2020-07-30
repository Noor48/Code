#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Enemy 
{
    public:
    virtual void attack()
    {
        cout << "Enemy!" << endl;
    }
};

class Ninja: public Enemy
{
    void attack()
    {
        cout << "Ninja!" << endl;
    }
};

class Monster: public Enemy
{
    public:
    void attack()
    {
        cout << "Monster!" << endl;
    }
};

int main()
{
    Ninja n;
    Monster m;
    Enemy e;

    Enemy *e1 = &n;
    Enemy *e2 = &m;
    Enemy *e3 = &e;
    
    e1->attack();
    e2->attack();
    e3->attack();
     
     return 0;
}