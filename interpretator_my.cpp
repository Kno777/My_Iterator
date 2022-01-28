#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <ostream>

// C++ //                      // Wrestling My Lezu //
// int //                      // melnica // 
// double //                   // suplex //
// bool //                     // bool //
// string //                   // gorg //
// cout //                     // tushe //
// while //                    // glori //
// if //                       // chelenge //

// c++ //                        // Wrestler //
// int x;//                      // melnica x: //
// double db; //                 // suplex sp: //
// string str; //                // gorg g: //
// cout << x; //                 // tushe <<< g: //
// while() //                    // glori() //
// if() //                       // chelenge() //

// Knereq angleren grvac Hayeren bareri hamar // (:

struct my_lezu
{
    std::string name;
    char type;
    unsigned short index; 
    bool arjeq;
};


std::vector <std::string> str_var; //string_value

std::vector <int> int_var; //int_value

std::vector <double> doub_var; //double_value

std::vector <bool> bool_var; //bool_value

std::vector <my_lezu> my_lezu_var; //variable_name

std::vector <std::string> code;
std::vector <std::string> tokens;
std::vector <std::string> glori;
std::string token;
std::string kode;

int ind_ex = 0;

void stexcel(std::vector <std::string>& tokens); // stexcel

void matem(std::vector <std::string>& tokens); // matematikakkan gorcoxutyunner

void unboxing(std::vector <std::string>& tokens);

void arjeqavorum(std::vector <std::string>& tokens);

void tpel(std::vector <std::string>& tokens);

void payman(std::vector <std::string>& tokens); // paymani stugum

void vortex_es(std::string& kode); // what is this bro

void hishoxutyun();

int main()
{
    std::string path = "iterpretator.txt";
    std::ifstream fin;
    fin.open(path);
    if(fin.is_open())
    {
        while(!fin.eof())
        {
            std::string tox;
            std::getline(fin,tox);
            std::string tmp;
            for(int i = 0; i <= tox.length(); ++i)
            {
                if(tox[i] != '\0')
                {
                    tmp += tox[i];
                }
                else
                {
                    code.push_back(tmp); 
                    tmp = "";
                }
            }
        }
    }
    else
    {
        std::cout << "Error: file chi bacvel" << std::endl;
    }

    for(int i = 0; i < code.size(); ++i)
    {
        std::string durs = "";
        bool tmp = false;
        for(int j = 0; j < code[i].size(); ++j)
        {
            if(code[i][j] != ' ' && code[i][j] != ' ') tmp = true;
            if(tmp) durs += code[i][j];
        }
        code[i] = durs;
    }

    for(int i = 0; i < code.size(); ++i)
    {
        std::cout << code[i] << std::endl;
    }


    for( ; ind_ex < code.size(); ++ind_ex)
    {
        vortex_es(code[ind_ex]);
    }
}

void stexcel(std::vector <std::string>& tokens)
{
    for(int i = 0, jisht = 0; i < tokens.size(); ++i,jisht++)
    {
        my_lezu M_L;
        M_L.type = tokens[0][0];
        i++;
        if(jisht > 0)
        {
            M_L.name = tokens[i-1];
        }
        else
        {
            M_L.name = tokens[i];
        }
        i++;

        if(tokens[i] == "=")
        {
            i++;
        }
        else if(tokens[i] == "&" && tokens[i] == ":")
        {
            M_L.arjeq = false;
            my_lezu_var.push_back(M_L);
            continue;
        }
        M_L.arjeq = true;

        if(tokens[0] == "melnica")
        {
            int tmp = std::stoi(tokens[i]);
            M_L.index = int_var.size();
            int_var.push_back(tmp);
        }
        else if(tokens[0] == "gorg")
        {
            std::string tmp = tokens[i];
            M_L.index = str_var.size();
            str_var.push_back(tmp);
        }
        else if(tokens[0] == "suplex")
        {
            double tmp = std::stod(tokens[i]);
            M_L.index = doub_var.size();
            doub_var.push_back(tmp);
        }
        else if(tokens[0] == "bool")
        {
            bool tmp;
            if(tokens[i] == "real")
            {
                tmp = true;
            }
            else if(tokens[i] == "fack")
            {
                tmp = false;
            }
            M_L.index = bool_var.size();
            bool_var.push_back(tmp);
        }
        i++;
        my_lezu_var.push_back(M_L);
    }
}

void matem(std::vector <std::string>& tokens)
{
    for(int i = 0; i < tokens.size(); ++i)
    {
        if(tokens[i] == "*" || tokens[i] == "/")
        {
            char simbol = tokens[i][0];
            double db[3];
            db[0] = std::stod(tokens[i-1]);
            db[1] = std::stod(tokens[i+1]);
            tokens.erase(tokens.begin()+ (i-1));
            tokens.erase(tokens.begin() + (i));
            if(simbol == '*')
            {
                db[2] = db[0] * db[1];
            }
            else
            {
                db[2] = db[0] / db[1];
            }
            i--;
            tokens[i] = std::to_string(db[2]);
        }
    }

    for(int i = 0; i < tokens.size(); ++i)
    {
        if(tokens[i] == "+" || tokens[i] == "-")
        {
            char simbol = tokens[i][0];
            double db[3];
            db[0] = std::stod(tokens[i-1]);
            db[1] = std::stod(tokens[i+1]);
            tokens.erase(tokens.begin()+ (i-1));
            tokens.erase(tokens.begin() + (i));
            if(simbol == '+')
            {
                db[2] = db[0] + db[1];
            }
            else
            {
                db[2] = db[0] - db[1];
            }
            i--;
            tokens[i] = std::to_string(db[2]);
        }
    }
}

void unboxing(std::vector <std::string>& tokens)
{
    for(int j = 1; j < tokens.size(); ++j)
    {
        for(int i = 0; i < my_lezu_var.size(); ++i)
        {
            if(tokens[j] == my_lezu_var[i].name)
            {
                if(my_lezu_var[i].type == 'm')
                {
                    tokens[j] = std::to_string(int_var[my_lezu_var[i].index]);
                }
            }
            else if(my_lezu_var[i].type == 's')
            {
                tokens[j] = std::to_string(doub_var[my_lezu_var[i].index]);
            }
            else if(my_lezu_var[i].type == 'b')
            {
                tokens[j] = std::to_string(bool_var[my_lezu_var[i].index]);
            }
            else if(my_lezu_var[i].type == 'g')
            {
                tokens[j] = str_var[my_lezu_var[i].index];
            }
        }
    }
}


void arjeqavorum(std::vector <std::string>& tokens)
{
    int j = 0;
    for(int i = 0; i < my_lezu_var.size(); ++i) if(my_lezu_var[i].name == tokens[0]) j = i;
    if(my_lezu_var[j].arjeq == 0)
    {
        if(my_lezu_var[j].type == 'm')
        {
            my_lezu_var[j].index = int_var.size();
            int tmp = std::stoi(tokens[2]);
            int_var.push_back(tmp);
        }
        else if(my_lezu_var[j].type == 'b')
        {
            my_lezu_var[j].index = bool_var.size();
            bool tmp;
            if(tokens[2] == "real") tmp = true;
            else if(tokens[2] == "fack") tmp = false;
            bool_var.push_back(tmp);
        }
        else if(my_lezu_var[j].type == 's')
        {
            my_lezu_var[j].index = doub_var.size();
            double tmp = std::stod(tokens[2]);
            doub_var.push_back(tmp);
        }
        else if(my_lezu_var[j].type == 'g')
        {
            my_lezu_var[j].index = str_var.size();
            std::string tmp = tokens[2];
            str_var.push_back(tmp);
        }
        my_lezu_var[j].arjeq = true;
    }
    else
    {
        if(my_lezu_var[j].type == 'm')
        {
            int_var[my_lezu_var[j].index] = std::stoi(tokens[2]);
        }
        else if(my_lezu_var[j].type == 's')
        {
            doub_var[my_lezu_var[j].index] = std::stod(tokens[2]);
        }
        else if(my_lezu_var[j].type == 'g')
        {
            str_var[my_lezu_var[j].index] = tokens[2];
        }
        else if(my_lezu_var[j].type == 'b')
        {
            if(tokens[2] == "real")
            {
                bool_var[my_lezu_var[j].index] = 1;
            }
            else if(tokens[2] == "fack")
            {
                bool_var[my_lezu_var[j].index] = 0;
            }
        }
    }
}

void hishoxutyun()
{
    for(int i = 0; i < my_lezu_var.size(); ++i)
    {
        std::cout << "Name: " << my_lezu_var[i].name << " Type: " << my_lezu_var[i].type << " Arjeq: " << my_lezu_var[i].arjeq;
        if(my_lezu_var[i].arjeq == 1)
        {
            std::cout << "Value: " ;
            if(my_lezu_var[i].type == 'm') 
            {
                std::cout << int_var[my_lezu_var[i].index] << std::endl;
            }
            else if(my_lezu_var[i].type == 's')
            {
                std::cout << doub_var[my_lezu_var[i].index] << std::endl;
            }
            else if(my_lezu_var[i].type == 'b')
            {
                std::cout << bool_var[my_lezu_var[i].index] << std::endl;
            }
            else if(my_lezu_var[i].type == 'g')
            {
                std::cout << str_var[my_lezu_var[i].index] << std::endl;
            }
        }
        else
        {
            std::cout << "Raven" << std::endl;
        }
    }
}

void tpel(std::vector <std::string>& tokens)
{
    int i = 0;
    if(tokens[i] == "tushe")i++;
    else if (tokens[i] == "<<<" || tokens[i] == "<<<") { unboxing(tokens); matem(tokens); }
    else
    {
        i++;
        for( ; i < tokens.size()-1; ++i) std::cout << tokens[i] << " ";
    }
    i += 2;
    for( ; i < tokens.size() - 1; ++i) std::cout << token[i] << " ";
    //std::cout << std::endl; 
}

void payman(std::vector <std::string>& tokens)
{
    for(int i = 0; i < tokens.size(); ++i)
    {
        if(tokens[i] == ">" || tokens[i] == ">=" || tokens[i] == "<" || tokens[i] == "<=" || tokens[i] == "==" || tokens[i] == "!=")
        {
            std::string wre = tokens[i];
            double db[3];
            db[0] = std::stod(tokens[i-1]);
            db[1] = std::stod(tokens[i+1]);
            tokens.erase(tokens.begin() + (i-1));
            tokens.erase(tokens.begin() + (i));
            if(wre == ">") db[2] = db[0] > db[1];
            else if(wre == ">=") db[2] = db[0] >= db[1];
            else if(wre == "<") db[2] = db[0] < db[1];
            else if(wre == "<=") db[2] = db[0] <= db[1];
            else if(wre == "==") db[2] = db[0] == db[1];
            else if(wre == "!=") db[2] = db[0] != db[1];
            i--;
            tokens[i] = std::to_string(db[2]);
        }
    }

    for(int i = 0; i < tokens.size(); ++i)
    {
        if(tokens[i] == "&&" || tokens[i] == "||")
        {
            char wre = tokens[i][0];
            double db[3];
            db[0] = std::stod(tokens[i-1]);
            db[1] = std::stod(tokens[i+1]);
            tokens.erase(tokens.begin() + (i-1));
            tokens.erase(tokens.begin() + (i));
            if(wre == '&') db[2] = db[0] && db[1];
            else if(wre == '|') db[2] = db[0] || db[1];
            i--;
            tokens[i] = std::to_string(db[2]);
        }
        
    }
}


void vortex_es(std::string& kode)
{
    for(int i = 0; i <= kode.length(); ++i)
    {
        if(kode[i] != ' ' && kode[i] != '\0') token += kode[i];
        else 
        {
            tokens.push_back(token);
            token = "";
        }
        if(tokens[0] == "melnica" || tokens[0] == "suplex" || tokens[0] == "bool" || tokens[0] == "gorg")
        {
            unboxing(tokens);
            matem(tokens);
            stexcel(tokens);
        }
        else if(tokens[0] == "tushe")
        {
            tpel(tokens);
        }
        else if(tokens[0] == "chelenge")
        {
            int begin = ind_ex, finish = ind_ex + 1, count = 0;
            bool tmp = true;
            for( ; tmp ; finish++)
            {
                if(code[finish] == "payqarir")
                {
                    count++;
                }
                else if(code[finish] == "handznvecir")
                {
                    count--;
                }
                if(count == 0) tmp = false;
            }
            finish--;
            ind_ex++;
            unboxing(tokens);
            matem(tokens);
            payman(tokens);

            if ( std::stoi(tokens[2]) == 1)
		    {
			for (; ind_ex < finish; ind_ex++)
			    {
				tokens.clear();
				kode = "";
				vortex_es(code[ind_ex]);
			    }
		    }
            ind_ex = finish;
        }
        else if(tokens[0] == "glori")
        {
            int begin = ind_ex, finish = ind_ex + 1, count = 0;
		    bool tmp = true;
            for( ; tmp ; finish++)
            {
                if(code[finish] == "payqarir")
                {
                    count++;
                }
                else if(code[finish] == "handznvecir")
                {
                    count--;
                }
                if(count == 0) tmp = false;
            }
            finish--;
            for( ; begin <= finish; begin++)
            {
                glori.push_back(code[begin]);
            }
            begin = ind_ex;
            tmp = false;
            unboxing(tokens);
		    matem(tokens);
		    payman(tokens);
            if(std::stoi(tokens[2]) == 1) tmp = true;
            while(tmp)
            {
                for(int j = ind_ex; j < finish; ++j)
                {
                    tokens.clear();
                    kode = "";
                    vortex_es(code[j]);
                }

                tokens.clear();
                kode = "";
                for (int i = begin, j = 0; i < finish; i++, j++)
			    {
				    code[i] = glori[j];
			    }
                kode = code[ind_ex];
                for(int i = 0; i <= kode.size(); ++i)
                {
                    if(kode[i] != ' ' && kode[i] != '\0') token += kode[i];
                    else {tokens.push_back(token); token = "";}
                }
                unboxing(tokens);
			    matem(tokens);
			    payman(tokens);

                if (std::stoi(tokens[2]) == 1) tmp = true;
			    else tmp = false;
            }
            ind_ex = finish;
        }
        else if(tokens[0] == "hishoxutyun")
        {
            hishoxutyun();
        }
        else
        {
            bool tmp = false;
            for(int i = 0; i < my_lezu_var.size(); ++i)
            {
                if(tokens[i] == my_lezu_var[i].name)
                    tmp = true;
            }
            if(tmp == true)
            {
                unboxing(tokens);
			    matem(tokens);
			    arjeqavorum(tokens);
            }
        }
        tokens.clear();
        kode = "";
    }
}