#ifndef IMOVEL_VELHO_H
#define IMOVEL_VELHO_H

#include "Imovel.h"

class ImovelVelho : public Imovel {
public:
  ImovelVelho(string="", double=0, double=800);

  void setDiscount(double);
  double getDiscount() const;

  double getPrice() const;

private:
  double discount;
};

#endif