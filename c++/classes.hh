#include <iostream>
#include <string>


class replace_link
{
  public:
    //Constructeurs
    replace_link();
    replace_link(std::string name,std::string firstname);
    //Affichage
    void m_afficher(void);

    //Destructuer
    ~replace_link();
  private:
    std::string a_name;
    std::string a_firstname;
};


class replace_me
{
  public:
    // Constructeurs
    replace_me();   //Par défaut
    replace_me(int a,char b,float c,double d,bool e,std::string a_name,std::string a_firstname);    //Pour la surcharge
    //Accesseur
    char m_getChar(void);
    //Afficheur
    void m_afficher(void);
    //Différentes méthodes:


    //Destructeur
    ~replace_me();

  private:
    int a_var_1;
    char a_var_2;
    float a_var_3;
    double a_var_4;
    bool a_var_5;
    replace_link c_instance;
};
