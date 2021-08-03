#ifndef RETANGULO_H
#define RETANGULO_H

class Retangulo{
public:
  Retangulo(double = 1.0, double = 1.0);

  void setAltura(double);
  void setLargura(double);

  double getAltura();
  double getLargura();

  double perimetro();
  double area();

private:
  double altura, largura;
};

#endif