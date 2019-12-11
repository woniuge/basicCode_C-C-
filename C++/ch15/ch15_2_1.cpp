//ch15_2_1

#include <iostream.h>

//class Animal;

//void SetValue(Animal&, int);
//void SetValue(Animal&, int, int);

class Animal{
public:
 // friend void SetValue(Animal&, int);
  void SetValue(Animal&, int);
  void SetValue(Animal&, int, int);

protected:
  int itsWeight;
  int itsAge;
};

void Animal::SetValue(Animal& ta, int tw)
{
  ta.itsWeight =tw;
}

void Animal::SetValue(Animal& ta, int tw, int tn)
{
  ta.itsWeight =tw;      //�ǳ�Ա��������Ա���ܷ������˽������
  ta.itsAge =tn;         //�ǳ�Ա��������Ա���ܷ������˽������
}

int main()
{
  Animal peppy;
  peppy.SetValue(peppy, 5);
  peppy.SetValue(peppy,7,9);
}
