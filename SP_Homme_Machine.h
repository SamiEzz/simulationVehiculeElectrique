#include <stdio.h>
#include <stdlib.h>
#include "Types_project.h"
#ifndef TYPES_PROJECT_H_INCLUDED
#define TYPES_PROJECT_H_INCLUDED

#endif

void SP_INIT_SIMU(ST_PARAM_SIMU*);
void SP_INIT_SYSTEME(ST_PARAM_SYSTEM*);
int SP_MESSAGERIE(int);
void SP_AFFICHE_PARAM(ST_PARAM_SIMU ,ST_PARAM_SYSTEM);
void SP_MODIF_PARAM( ST_PARAM_SIMU ,ST_PARAM_SYSTEM);
float SP_SAISIE_PARAM(float,float,char*,int);
void SP_FICH_CONTEXTE(ST_PARAM_SIMU,ST_PARAM_SYSTEM,char*);
