#include "header.hh"
//replace_me
///Constructeurs
replace_me::replace_me() : a_var_1(0),a_var_2('\0'),a_var_3(0.0),a_var_4(0.0),a_var_5(0),c_instance()
{}
replace_me::replace_me(int a,char b,float c,double d,bool e,string a_name,string a_firstname) : a_var_1(a),a_var_2(b),a_var_3(c),a_var_4(d),a_var_5(e),c_instance(a_name,a_firstname)
{}
///Destructeurs
replace_me::~replace_me()
{}
///Méthodes
char replace_me::m_getChar(void)
{
  return a_var_2;
}

void replace_me::m_afficher(void)
{
  std::cout << "Dans la struture on a actuellement : "<<a_var_1<<" et "<<a_var_2<<" et "<< a_var_3 <<" et "<< a_var_4 <<" et "<< a_var_5 << std::endl;
  c_instance.m_afficher();
}

//replace_link
///Constructeurs
replace_link::replace_link() : a_name("Lama"),a_firstname("Chameau")
{}
replace_link::replace_link(string name,string firstname) : a_name(name),a_firstname(firstname)
{}
///Destructeurs
replace_link::~replace_link()
{}
///Méthodes
void replace_link::m_afficher(void)
{
  std::cout << "\nEt dans la sous-structure on a : "<<a_name<<" et "<<a_firstname<<std::endl;
}
