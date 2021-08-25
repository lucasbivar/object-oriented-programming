#ifndef IMOVEL_NOVO_H
#define IMOVEL_NOVO_H

#include "Imovel.h"

class ImovelNovo : public Imovel {
public:
  ImovelNovo(string="", double=0, double=500);

  void setAdditionalFee(double);
  double getAdditionalFee() const;

  double getPrice() const;

private:
  double additionalFee;
};

#endif