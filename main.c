#include <stdio.h>
#include <stdlib.h>
#include "Types_project.h"
#include "SP_Homme_Machine.h"
#include "SP_Outils_Simulation.h"
#include <math.h>
void SP_SAVE_POINTS(float*);


int main()
{
    ST_POINT varPoints;
    ST_PARAM_SIMU varSimu;
    ST_PARAM_SYSTEM varSystem;
    SP_INIT_SIMU(&varSimu);
    SP_INIT_SYSTEME(&varSystem);
    varPoints.Tactu=0;
    varPoints.i_euler=0;
    varPoints.i_rk2=0;
    float tab_save[NB_COURBES_TOTAL+1];
    while (varPoints.Tactu<varSimu.tfinal){
        varPoints.Tactu=varPoints.Tactu+varSimu.pas;
        tab_save[0]=varPoints.Tactu;
        varPoints.i_ana=SP_ANA(varSystem,varPoints.Tactu+varSimu.pas);
        tab_save[1]=varPoints.i_ana;
        varPoints.i_euler=SP_IEULEUR(varSystem,varSimu,varPoints.Tactu,varPoints);
        tab_save[2]=varPoints.i_euler;
        varPoints.i_rk2=SP_RK2(varSystem,varSimu,varPoints.Tactu,varPoints.i_rk2);
        tab_save[3]=varPoints.i_rk2;
    }
    SP_SAVE_POINTS(tab_save);
    return 0;
}

void SP_SAVE_POINTS(float tab[]){
    FILE *sp_fichier;
    int nb;
    nb=NB_COURBES_TOTAL;
    sp_fichier = fopen("resultat simulation.txt", "wt");
    fprintf(sp_fichier, "Le temps actuel : %f\t\n",tab[0]);
    fprintf(sp_fichier, "Les NB_COURBES_TOTAL que souhaite sauvegarder l'utilisateur pour le %f : \t\n",tab[0]);
    switch(nb){
        case 3:
            fprintf(sp_fichier,"Les NB_COURBES_TOTAL que souhaite  %f\t ,%f\t ,%f\t, %f\n",tab[0],tab[1],tab[2],tab[3]);
        break;
        case 2:
            fprintf(sp_fichier,"Les NB_COURBES_TOTAL que souhaite  %f ,%f ,%f\n",tab[0],tab[1],tab[2]);
        break;
        case 1:
            fprintf(sp_fichier,"Les NB_COURBES_TOTAL que souhaite  %f ,%f ,\n",tab[0],tab[1]);
        break;
    }
    fclose(sp_fichier);
}


