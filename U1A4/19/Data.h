#ifndef DATA_H
#define DATA_H

class Data{
public:
  Data(int novoDia, int novoMes, int novoAno);

  void setDia(int novoDia);
  int getDia();

  void setMes(int novoMes);
  int getMes();

  void setAno(int novoAno);
  int getAno();

  void mostrarData();

private:
  int dia, mes, ano;
};

#endif