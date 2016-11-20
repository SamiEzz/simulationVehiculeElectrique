#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Types_project.h"
#include "SP_Outils_Simulation.h"



float SP_SOURCE(float sp_E,float sp_W,float sp_Tactu){
    if (sp_W==0){
        return sp_E;
    }
    else{
        return sp_E*sin(sp_W*sp_Tactu);
    }

}

float SP_ANA(ST_PARAM_SYSTEM varSystem,float sp_Tactu){
    float unsurto = -varSystem.R/varSystem.L;
    if (varSystem.W!=0){
//        return varSystem.E/(varSystem.R*)+(varSystem.L*varSystem.W).^2)*(varSystem.L*varSystem.W*(exp(sp_Tactu*unsurto)-cos(varSystem.W*sp_Tactu)+varSystem.R*sin(varSystem.W*sp_Tactu) ));
        return (varSystem.E/(varSystem.R*varSystem.R+varSystem.L*varSystem.L*varSystem.W*varSystem.W))*(varSystem.L*varSystem.W*(exp(-sp_Tactu*varSystem.R/varSystem.L)-cos(varSystem.W*sp_Tactu))+varSystem.R*sin(varSystem.W*sp_Tactu));
    }

    else{
        return varSystem.E/varSystem.R*(1-1/exp(sp_Tactu*unsurto));
    }

}
float SP_IEULEUR(ST_PARAM_SYSTEM sp_varSystem,ST_PARAM_SIMU sp_varSimu,float sp_Tactu,ST_POINT sp_varPoints){
        return sp_varPoints.i_euler+sp_varSimu.pas*SP_EQDIFF_I(sp_varPoints.i_euler,sp_varSystem,sp_Tactu);
}
float SP_EQDIFF_I(float sp_i,ST_PARAM_SYSTEM sp_varSystem,float sp_Tactu){
    float SE;
    SE=SP_SOURCE(sp_varSystem.E,sp_varSystem.W,sp_Tactu);
    return (SE-sp_varSystem.R*sp_i)/sp_varSystem.L;
}

float SP_RK2(ST_PARAM_SYSTEM sp_varSystem,ST_PARAM_SIMU sp_varSimu,float sp_Tactu,float point){
    float a;    // irk2(k+1/2)
    float b;    // E(k+1/2)
    float c;    // di/dt pour t=k+1/2
    a=point+sp_varSimu.pas/2*SP_EQDIFF_I(point,sp_varSystem,sp_Tactu);
    b=SP_SOURCE(sp_varSystem.E,sp_varSystem.W,sp_Tactu+sp_varSimu.pas/2);
    c=(b-sp_varSystem.R*a)/sp_varSystem.L;
    return point+sp_varSimu.pas*c;

}
