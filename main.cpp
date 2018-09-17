 
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
#include "RGB.h"
//";<; ;/
using namespace std;
using namespace fractal;

int main() {
    

    FractalCreator fractalCreator(800,600);
    
    fractalCreator.addRange(0.0, RGB(255,0,0));//for pixels with 0 to 300 iterations
    fractalCreator.addRange(0.3, RGB(255,0,0));//for pixels with 300 to 500 iterations
    fractalCreator.addRange(0.5, RGB(255,255,0));
    fractalCreator.addRange(1.0, RGB(255,255,255));
    
    fractalCreator.addZoom(Zoom(295,202,0.1));
    fractalCreator.addZoom(Zoom(312,304,0.1));
    fractalCreator.run("test.bmp");
    cout<<"Finished"<<endl;
    return 0;
}

