#ifndef TYPES_PROJECT_H_INCLUDED
#define TYPES_PROJECT_H_INCLUDED
typedef struct{
    float pas;
    float tfinal;
} ST_PARAM_SIMU;
typedef struct{
    float R;
    float L;
    float E;
    float W;
} ST_PARAM_SYSTEM;
typedef struct{
    float Tactu;
    float i_ana;
    float i_euler;
    float i_rk2;
    float V_alim;
} ST_POINT;
#endif
#define NB_COURBES_TOTAL 3
