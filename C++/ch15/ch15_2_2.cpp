
//ch15_2_2

#include <iostream.h>

class Animal;

void SetValue(Animal&, int);
void SetValue(Animal&, int, int);

class Animal{
public:
  void Set(int v);
  void Set(int v, int w);
  void display();
protected:
  int itsWeight;
  int itsAge;
};

void Animal::Set(int v)
{ 
	itsWeight = v; 
}
void Animal::Set(int v, int w)
{ 
	itsWeight=v; itsAge=w; 
}
void Animal::display()
{
	cout << "weight = " << itsWeight << "\tage = " << itsAge << endl;
}

void SetValue(Animal& ta, int tw)
{ 
	ta.Set(tw);
}
void SetValue(Animal& ta, int tw, int tn)
{ 
	ta.Set(tw,tn); 
}

void main()
{
  Animal peppy;
  SetValue(peppy, 5);
  peppy.display();
  SetValue(peppy,7,9);
  peppy.display();
}
