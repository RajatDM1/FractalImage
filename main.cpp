 
/* 
 * File:   main.cpp
 * Author: Dwivedi
 *
 * Created on 16 September, 2018, 5:52 PM
 */

#include <cstdlib>
#include <math.h>
#include <cstdint>
#include<iostream>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
//";<; ;/
using namespace std;
using namespace fractal;

int main() {
    
    int const WIDTH = 800;
    int const HEIGHT = 600;
    ZoomList zoomList(WIDTH,HEIGHT);
    zoomList.add(zoom(WIDTH/2,HEIGHT/2,4.0/WIDTH));
    Bitmap bitmap(WIDTH, HEIGHT);
    double min = 999999;
    double max = -999999;
//    bitmap.setPixel(WIDTH/2,HEIGHT/2,255,255,255);
    unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});
    unique_ptr<int[]> frac(new int[WIDTH*HEIGHT]{0});
    for(int y=0;y<HEIGHT;y++)
    {
        for(int x=0;x<WIDTH;x++)
        {
//            bitmap.setPixel(x,y, 255,255,255);
            double xfractal = (x-WIDTH/2-200)*(2.0/HEIGHT);//as values of xfractal should be between -1 to 1
            double yfractal = (y-HEIGHT/2)*(2.0/HEIGHT);
            
            int iterations = Mandelbrot::getIterations(xfractal,yfractal);
            frac[y*WIDTH+x] = iterations;
            if(iterations!= Mandelbrot::MAX_ITERATIONS)
                histogram[iterations]++;
//            uint8_t color = (uint8_t)(256*(double)iterations/Mandelbrot::MAX_ITERATIONS);
//            color = color*color*color;
//            bitmap.setPixel(x,y,0,color,0);
//            if(color < min ) min = color;
//            if(color > max) max = color;
        }
    }
    int total = 0;
    for(int i=0;i<Mandelbrot::MAX_ITERATIONS;i++)
    {
        total +=histogram[i];
    }
    for(int y=0;y<HEIGHT;y++)
    {
        for(int x=0;x<WIDTH;x++)
        {
             int iterations = frac[y*WIDTH+x];
             uint8_t red = 0;
             uint8_t green = 0;
             uint8_t blue = 0;
             if(iterations!=Mandelbrot::MAX_ITERATIONS)
             {
                  uint8_t color = (uint8_t)(256*(double)iterations/Mandelbrot::MAX_ITERATIONS);
                    double hue = 0.0;
                    for(int i = 0;i < iterations;i++)
                    {
                        hue+=((double)histogram[i])/total;
                    }
                    green = pow(255,hue);
             }
             
            bitmap.setPixel(x,y,red,green,blue);
//            if(color < min ) min = color;
//            if(color > max) max = color;
        }
    }
    
    cout<<min<<","<<max<<endl;
    bitmap.write("test.bmp");
    cout<<"Finished"<<endl;
    return 0;
}

