#include <stdio.h>
#include <stdlib.h>
#include "Types_project.h"
#include "SP_Homme_Machine.h"


void SP_AFFICHE_PARAM(ST_PARAM_SIMU varSimu,ST_PARAM_SYSTEM varSystem){
    printf("Valeurs des paramétres de simulation\n");
    printf("1. RESISTANCE_R= %.0f ohm\n",  varSystem.R);
    printf("2. INDUCTANCE_L= %.1e Henri\n", varSystem.L);
    printf("3. TENSION_E= %.0f Volt\n", varSystem.E);
    printf("4. PULSATION_PULS= %.2f rad/s\n", varSystem.W);
    printf("5. TEMPS FINAL_TFINAL= %.1e secondes\n", varSimu.tfinal);
    printf("6. PAS DE CALCUL_PAS= %.1e\n", varSimu.pas);
}

int SP_MESSAGERIE(int sp_varMessage){
    switch (sp_varMessage){
            case 0:
                printf("Bienvenue\n");
                break;
            case 1:
                printf("Modification paramètres en cours\n");
                break;
            case 2 :
                printf("Modification paramètres OK\n");
                break;
            case 3 :
                printf("Initialisation param system OK\n");
                break;
            case 4 :
                printf("Initialisation param simulation OK\n");
                break;
            case 5 :
                printf("Simulation en cours\n");
                break;
            case 6 :
                printf("Fin de la simulation\n");
                break;
            case 7 :
                printf("Au revoir\n");
                break;
            default :
                printf("Erreur messagerie: message inconnu\n");
    }
    return 0;
}


void SP_INIT_SIMU(ST_PARAM_SIMU* pt_varSimu){
    pt_varSimu->tfinal=2;
    pt_varSimu->pas=1e-3;
}

void SP_INIT_SYSTEME(ST_PARAM_SYSTEM* pt_varSystem){
    pt_varSystem->R=1.2;
    pt_varSystem->L=2e-3;
    pt_varSystem->E=48;
    pt_varSystem->W=5;
}

void  SP_MODIF_PARAM( ST_PARAM_SIMU varSimu,ST_PARAM_SYSTEM varSystem){
    int choix=1;
    float c;
    float d;
    SP_MESSAGERIE(0);
    SP_MESSAGERIE(1);
    while (choix!=0){
        SP_AFFICHE_PARAM(varSimu,varSystem);
        while (choix!=0){
                printf("Choisir le paramètre à modifier, [0] pour sortir\n");
                scanf("%i",&choix);
                if (choix<7){
                    switch (choix){
                        case 1:
                            printf("Modification de la résistance\n");
                            varSystem.R=SP_SAISIE_PARAM(0,100,"R",1);
                            SP_AFFICHE_PARAM(varSimu,varSystem);
                            break;
                        case 2:
                            printf("Modification de l'inductance\n");
                            varSystem.L=SP_SAISIE_PARAM(0,100,"L",1);
                            SP_AFFICHE_PARAM(varSimu,varSystem);
                            break;
                        case 3 :
                            printf("Modification de la tension\n");
                            varSystem.E=SP_SAISIE_PARAM(0,100,"E",1);
                            SP_AFFICHE_PARAM(varSimu,varSystem);
                            break;
                        case 4 :
                            printf("Modification de la pulsation\n");
                            varSystem.W=SP_SAISIE_PARAM(0,100,"W",1);
                            SP_AFFICHE_PARAM(varSimu,varSystem);
                            break;

                        case 5 :
                            printf("Modification du temps final\n");

                            c=SP_SAISIE_PARAM(0,100,"tfinal",1);
                            if(c<varSimu.pas){
                                printf("le temps final ne peut pas etre inferieur au pas\n");
                            }
                            else{
                                 varSimu.tfinal=c;
                            }


                            SP_AFFICHE_PARAM(varSimu,varSystem);
                            break;
                        case 6:
                            printf("Modification du pas de calcul\n");

                            d=SP_SAISIE_PARAM(0,100,"pas",1);
                            if(d>varSimu.tfinal){
                                printf("le pas ne peut pas etre superieur au temps final\n");
                            }
                            else{
                                 varSimu.pas=d;
                            }
                            SP_AFFICHE_PARAM(varSimu,varSystem);
                            break;
                     }
                }
                else {
                        printf("Entrez une valeur entre 0 et 6\n");


            }
        }

    }
}


float SP_SAISIE_PARAM(float sp_valeur_min,float sp_valeur_max,char* sp_nom_param,int sp_test){
    if(sp_test==1 || sp_test == 0){
        int saisie=0;
        int execution=0;
        float val_param;
        while (saisie==0){
            if (execution!=0){
                printf("Bornes non respectées\n le parametre doit etre compris entre: %.2e et %.2e\n",sp_valeur_min ,sp_valeur_max);
            }
            printf("Entrez valeur du paramètre: %s\n",sp_nom_param);
            scanf("%f",&val_param);
            execution+=1;
            if (sp_test==1){
                if (val_param>sp_valeur_min && val_param<sp_valeur_max){
                    saisie=1;
                    return val_param;
                }
            }
            else {
                if (val_param>=sp_valeur_min && val_param<=sp_valeur_max){
                    saisie=1;
                    return val_param;
                }
            }
        }
    }
    else{
        printf("Veuillez entrez une valeur (1: < ou 0: <=) dans le 4ième paramètre de la fonction\n");
    }
}

void SP_FICH_CONTEXTE(ST_PARAM_SIMU sp_varSimu,ST_PARAM_SYSTEM sp_varSystem,char* sp_nom_fichier){
        FILE *sp_fichier;
        sp_fichier = fopen(sp_nom_fichier, "wt");
            fprintf(sp_fichier, "%% ======= Parametres de Simulation=====\n");
            fprintf(sp_fichier, "%% pas = %.1e s\n", sp_varSimu.pas );
            fprintf(sp_fichier, "%% T_final = %.1e s\n", sp_varSimu.tfinal);
            fprintf(sp_fichier, "%% ======= Parametres du systeme=====\n");
            fprintf(sp_fichier, "%% R = %.1e ohm\n", sp_varSystem.R );
            fprintf(sp_fichier, "%% L = %.1e Henri\n", sp_varSystem.L );
            fprintf(sp_fichier, "%% E = %.1e Volt\n", sp_varSystem.E );
            fprintf(sp_fichier, "%% w = %.1e rad/s\n", sp_varSystem.W );
            fclose(sp_fichier);
}









