 
/* 
 * File:   main.cpp
 * Author: Dwivedi
 *
 * Created on 16 September, 2018, 5:52 PM
 */

//#include <cstdlib>
//#include <math.h>
//#include <cstdint>
#include<iostream>

#include "FractalCreator.h"
//";<; ;/
using namespace std;
using namespace fractal;

int main() {
    
//    int const m_width = 800;
//    int const m_height = 600;
    int height = 600;
    FractalCreator fractalCreator(800,600);
    fractalCreator.addZoom(Zoom(295,height-202,0.1));
    fractalCreator.addZoom(Zoom(312,height-304,1.0));
    fractalCreator.calculateIterations();
    fractalCreator.calculateTotalIterations();
    fractalCreator.drawFractal();

    fractalCreator.writeBitmap("test.bmp");
    cout<<"Finished"<<endl;
    return 0;
}

