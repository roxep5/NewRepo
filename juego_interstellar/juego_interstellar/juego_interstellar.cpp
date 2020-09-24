//#include<iostream>
//#include<Windows.h>
//#include<conio.h>
#include "funciones.h"
#include "Nave.h"
#include "Asteroide.h"
#include "Disparo.h"
#include<list>
#include <ctime>
#include "Asteroide_m.h"
#include "Asteroide_G.h"
#include "AgujeroNegro.h"
using namespace std;
int main()
{
menu:
   
    //listaASCII();
    int puntos = 0;
    system("cls");
    dibuja_titulo(3, 4);
    ocultarCursor();
    //creamos objeto de la nave endurance
    Nave endurance(60, 30,9,3);
    
    endurance.dibujar();
    dibujar_limites();
 
    gotoxy(45, 20); cout << "1. Jugar";
    gotoxy(45, 22); cout << "2. Salir";
    int sleep33 = 0;
    PlaySound(TEXT("sonidos/musica.wav"), NULL, SND_ASYNC);
    while (1) {
        
        
        if (_kbhit()) {
            char opcion = _getch();
            switch (opcion)
            {
            case('1')://jugar
                gotoxy(45, 20); cout << "        ";
                gotoxy(45, 22); cout << "        ";
                goto jugar;
                break;
            case('2'):
                exit(0);
                break;
            
                
            }
            //PlaySound(TEXT("sonidos/musica.wav"), NULL, SND_LOOP);
        }
    }
jugar:
    system("cls");
    endurance.dibujar();
    dibujar_limites();
    //creamos lista de asteroides pequeños
    list<Asteroide*> l_ast;
    list<Asteroide*>::iterator it_ast;
    //creamos lista de asteroides medianos
    list<Asteroide_m*> l_astm;
    list<Asteroide_m*>::iterator it_astm;
    //creamos lista de asteroides medianos
    list<Asteroide_G*> l_astg;
    list<Asteroide_G*>::iterator it_astg;
    //creamos lista de disparos
    list<Disparo*> l_Disp;
    list<Disparo*>::iterator it;



    endurance.dibujar_salud();
    bool game_over = false;
    bool ganaste = false;
    clock_t t0, t1,t2,t3,t0a,t0b;
    t0 = clock();
    t2 = clock();
    int contador = 0,
        sleep_5=0,
        sleep_10=0;
    int tiempo_astm=0;
    int tiempo_astg=0;
    int tiempo = 0;
    int vidaG = 4;
    t0a = clock();
    bool crearagujero = true;
    AgujeroNegro agujeroNegro;
    endurance.aleatorizar();
    int sleep_50 = 0;
    int cuentaatras = 30;
    while (!game_over&&ganaste==false) {
        t0b = clock();
        t1 = clock();
        t3 = clock();
        
        tiempo=(int)(t0b-t0a)/CLOCKS_PER_SEC;
        gotoxy(4, 2); cout << "Puntos " << puntos;
        if (tiempo < 120) {
            gotoxy(20, 2); cout << "Tiempo " << tiempo;
        }
        if (tiempo < 120) {
            float tiempo0, tiempo1 = 0.1;

            tiempo0 = (float)(t1 - t0) / CLOCKS_PER_SEC;
            //creacion de asteroides pequeños(añadir asteroides a la lista cada 5 segundos)
            if (tiempo0 > 5 && contador != 10) {
                l_ast.push_back(new Asteroide(rand() % 92 + 4, 4, 1));

                t0 = clock();
                contador++;
                tiempo_astm++;
                tiempo_astg++;
            }
            //creacion de asteroides medianos(añadir asteroides a la lista cada 10 segundos)
            if (tiempo_astm == 2 && l_astm.size() < 5) {
                l_astm.push_back(new Asteroide_m(rand() % 88 + 4, 4, 2));
                tiempo_astm = 0;
            }
            //float tiempo0, tiempo1 = 0.1;
            
            if (tiempo_astg == 4 && l_astg.size() < 3) {
                l_astg.push_back(new Asteroide_G(rand() % 84 + 4, 4, 4));
                tiempo_astg=0;
                t0 = clock();
               // contador++;
                //tiempo_astm++;
            }
        }
        else if (!l_ast.empty()) {
            //borramos la imagen del asteroide pequeño y el objeto
            for (it_ast = l_ast.begin(); it_ast != l_ast.end(); it_ast++) {
                (*it_ast)->borrar();//borrar imagen
                delete(*it_ast);//borrar objeto
            }
            for (it_astm = l_astm.begin(); it_astm != l_astm.end(); it_astm++) {
                (*it_astm)->borrar();//borrar imagen
                delete(*it_astm);//borrar objeto
            }
            for (it_astg = l_astg.begin(); it_astg != l_astg.end(); it_astg++) {
                (*it_astg)->borrar();//borrar imagen
                delete(*it_astg);//borrar objeto
            }
            //borramos los elementos de la lista
            while (!l_ast.empty())l_ast.pop_front();
            while (!l_astm.empty())l_astm.pop_front();
            while (!l_astg.empty())l_astg.pop_front();
            //dibuja_agujeronegro(40, 5);
        }
        if (tiempo > 120&&crearagujero) {
            agujeroNegro.setCoordenadas(40, 5);
            PlaySound(TEXT("sonidos/musica_agujeronegro.wav"), NULL, SND_ASYNC);
            agujeroNegro.dibujar();
            crearagujero = false;

       
        }
        else if (crearagujero == false&&sleep_5==5) {
            agujeroNegro.mover();
            sleep_5 = 0;
            int tiempo30 = (int)(t3 - t2) / CLOCKS_PER_SEC;
            gotoxy(40, 2); cout << "Cuenta atras " << cuentaatras;
            //creacion de asteroides pequeños(añadir asteroides a la lista cada 5 segundos)
            //if (tiempo30 <=1 && cuentaatras > 0) {
           if (tiempo<164&&sleep33>34) {

               sleep33 = 0;
                t2 = clock();
                cuentaatras--;

            }
           
            else if(cuentaatras==0)
            {
                game_over = true;
            }
        }
        if (GetAsyncKeyState(VK_SPACE) < 0) {    //GetKeyState:devuelve estado de tecla
                                            //si devuelve 1 => pulsada(0000 0001)
                                            //si devuelve 0 => no pulsada
                                            //-127:(0111 1111)
                                            //-128:(1000 0000)
            PlaySound(TEXT("sonidos/disparo.wav"), NULL, SND_ASYNC);
            l_Disp.push_back(new Disparo(endurance.getX() + 3, endurance.getY() - 1));
        }
        /*if (_kbhit()) {
            char tecla = _getch();
            if (tecla == SPACE_BAR && endurance.getY() > 4) {
                //CREAR DISPARO
               
                PlaySound(TEXT("sonidos/disparo.wav"), NULL, SND_ASYNC);
                    l_Disp.push_back(new Disparo(endurance.getX() + 3, endurance.getY() - 1));
                    
                
            }
        }*/
        //recorremos la lista de disparos desde el inicio al final
        for (it = l_Disp.begin(); it != l_Disp.end(); it++) {
            (*it)->mover();
            sleep33=0;
            if ((*it)->fuera())//si el disparo esta fuera
            {
                (*it)->borrar();//borrado visual
                delete(*it);//borro objeto
                l_Disp.erase(it);
                break;
            }
        }
        //mover asteroides pequeños y comprobar colision
        for (it_ast = l_ast.begin(); it_ast != l_ast.end(); it_ast++) {
            (*it_ast)->mover();
            
            (*it_ast)->colision(endurance);
        }  
        if (sleep_5 == 6) {
            sleep_5 = 0;
            //mover asteroides medianos y comprobar colision
            for (it_astm = l_astm.begin(); it_astm != l_astm.end(); it_astm++) {
                (*it_astm)->mover();
                (*it_astm)->colision(endurance);
            }
        }if (sleep_10 == 11) {
            sleep_10 = 0;
            //mover asteroides medianos y comprobar colision
            for (it_astg = l_astg.begin(); it_astg != l_astg.end(); it_astg++) {
                (*it_astg)->mover();
                (*it_astg)->colision(endurance);
            }
        }
        //comprobar colision entre disparos y asteroides pequeños
        for (it = l_Disp.begin(); it != l_Disp.end(); it++) {
       for (it_ast = l_ast.begin(); it_ast != l_ast.end(); it_ast++) {
            
                //si sus coordenadas son "coincidentes"
                if ((*it)->getX() == (*it_ast)->getX() && 
                    (
                        (*it)->getY() == (*it_ast)->getY() ||
                        (*it)->getY() + 1 == (*it_ast)->getY() ||
                        (*it)->getY() - 1 == (*it_ast)->getY()
                    )
                ){
                    (*it)->borrar();//borro disparo
                    (*it)->eliminar();//elimino disparo enviandolor al margen superior 
                    (*it_ast)->borrar();///elimino asteroide
                    (*it_ast)->eliminar();
                    PlaySound(TEXT("sonidos/explosion_asteroide_p.wav"), NULL, SND_ASYNC);
                    cout << ".";
                    puntos += 5;
                }
            }
      /* if (
           endurance.getY() + 4 == agujeroNegro.getY() + 5 &&
           endurance.getX() + 5 == agujeroNegro.getX()+11 
           )
       {
           dibuja_win(20,30);
       }*/
       
       for (it_astm = l_astm.begin(); it_astm != l_astm.end(); it_astm++) {
            
                //si sus coordenadas son "coincidentes"
                if (
                    
                    (
                        ((*it)->getX() >= (*it_astm)->getX()) && 
                        ((*it)->getX() < (*it_astm)->getX()+4)
                    )&&
                    (
                        ((*it)->getY() >= (*it_astm)->getY()) &&
                        ((*it)->getY() < (*it_astm)->getY() + 4)
                    )

                     )

                    

                   {
                    if ((*it_astm)->getDureza() == 1) {
                         (*it_astm)->setDureza(2);
                        
                        (*it_astm)->borrar();///elimino asteroide
                        (*it_astm)->eliminar();
                        cout << "...";
                        puntos += 10;

                    }
                    else {
                        (*it_astm)->setDureza(1);
                        (*it)->borrar();//borro disparo
                        (*it)->eliminar();//elimino disparo enviandolor al margen superior 
                    }
                }
            }
       for (it_astg = l_astg.begin(); it_astg != l_astg.end(); it_astg++) {

                    //si sus coordenadas son "coincidentes"
                    if (

                        (
                            ((*it)->getX() >= (*it_astg)->getX()) &&
                            ((*it)->getX() < (*it_astg)->getX() + 9)
                            ) &&
                        (
                            ((*it)->getY() >= (*it_astg)->getY()) &&
                            ((*it)->getY() < (*it_astg)->getY() + 4)
                            )

                        )



                    {
                        if ((*it_astg)->getDureza() == 1) {
                            (*it_astg)->setDureza(4);

                            (*it_astg)->borrar();///elimino asteroide
                            (*it_astg)->eliminar();
                            cout << ".........";
                            puntos += 20;
                          //delete(*it_astg);
                            vidaG = 4;
                        }
                        else {
                            vidaG--;
                            (*it_astg)->setDureza(vidaG);
                            (*it)->borrar();//borro disparo
                            (*it)->eliminar();//elimino disparo enviandolor al margen superior 
                        }
                    }
                }

        }
          
        if (crearagujero) {
            endurance.mover();
        }
        else if (crearagujero == false) {
            if (sleep_50 == 50) {
                endurance.aleatorizar();
                sleep_50 = 0;
            }
            endurance.moverfinal();
            sleep_50++;
        }
        
        //if()


        //comprobar game over
        if (endurance.getVidas() < 0) {
            game_over = true;
        }
        Sleep(30);
        sleep_5++;
        sleep_10++;
        sleep33++;
        ganaste=agujeroNegro.ganar(endurance);
    }
    Sleep(2000);
    gotoxy(46, 19); cout << "         ";
    game_over = false;
 
    while (!_kbhit());
    goto menu;

}


