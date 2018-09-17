
#include "FractalCreator.h"
#include "RGB.h"
#include<iostream>
using namespace std;

namespace fractal{
    
void FractalCreator::addRange(double rangeEnd, const RGB& rgb)
{
    m_ranges.push_back(rangeEnd*Mandelbrot::MAX_ITERATIONS);
    m_colors.push_back(rgb); 
    
    if(m_bGotFirstRange)
    {
        m_rangeTotals.push_back(0);
    }
    m_bGotFirstRange = true;
    
}
void FractalCreator::addZoom(const Zoom& zoom)
{
  m_zoomList.add(zoom);   
}
    void FractalCreator::run(string name) {
//         FractalCreator fractalCreator(800,600);
    addZoom(Zoom(295,m_height-202,0.1));
    addZoom(Zoom(312,m_height-304,1.0));
    calculateIterations();
    calculateTotalIterations();
    calculateRangeTotals();
    drawFractal();
    writeBitmap("test.bmp");
    }
FractalCreator::FractalCreator(int width, int height):
            m_width(width), m_height(height), m_histogram
                    (new int[Mandelbrot::MAX_ITERATIONS]{0}),m_fractal
                    (new int[m_width*m_height]{0}), m_bitmap(m_width, m_height), m_zoomList(m_width,m_height){
                    m_zoomList.add(Zoom(m_width/2,m_height/2,4.0/m_width));   
}

void FractalCreator::calculateIterations(){
    for(int y=0;y<m_height;y++)
    {
        for(int x=0;x<m_width;x++)
        {
//            bitmap.setPixel(x,y, 255,255,255);
            pair<double,double> coords = m_zoomList.doZoom(x,y);
//            double xfractal = (x-WIDTH/2-200)*(2.0/HEIGHT);//as values of xfractal should be between -1 to 1
//            double yfractal = (y-HEIGHT/2)*(2.0/HEIGHT);
            
            int iterations = Mandelbrot::getIterations(coords.first,coords.second);
            m_fractal[y*m_width+x] = iterations;
            if(iterations!= Mandelbrot::MAX_ITERATIONS)
                m_histogram[iterations]++;
        }
    }
}
void FractalCreator::drawFractal()
{
    RGB startColor(0,0,0);
    RGB endColor(0,0,255);
    RGB colorDiff= endColor-startColor;
    
  
            
     for(int y=0;y<m_height;y++)
    {
        for(int x=0;x<m_width;x++)
        {
             int iterations = m_fractal[y*m_width+x];
             uint8_t red = 0;
             uint8_t green = 0;
             uint8_t blue = 0;
             if(iterations!=Mandelbrot::MAX_ITERATIONS)
             {
                  uint8_t color = (uint8_t)(256*(double)iterations/Mandelbrot::MAX_ITERATIONS);
                    double hue = 0.0;
                    for(int i = 0;i < iterations;i++)
                    {
                        hue+=((double)m_histogram[i])/m_total;
                    }
                    red = startColor.r + colorDiff.r*hue;
                    green = startColor.g + colorDiff.g*hue;
                    blue = startColor.b + colorDiff.b*hue;
             }
             
            m_bitmap.setPixel(x,y,red,green,blue);
//            if(color < min ) min = color;
//            if(color > max) max = color;
        }
    }
}
void FractalCreator::calculateRangeTotals()
{
    int rangeIndex = 0;
    for(int i = 0;i <Mandelbrot::MAX_ITERATIONS;i++)
    {
        int pixel = m_histogram[i];
        if(i >=m_ranges[rangeIndex+1])
        {
            rangeIndex++;
        }
        m_rangeTotals[rangeIndex]+=pixels;
    }
    for(int value:m_rangeTotals)
    {
        cout<<"Range total "<<value<<endl; 
    }
}
void FractalCreator::calculateTotalIterations()
{
    for(int i=0;i<Mandelbrot::MAX_ITERATIONS;i++)
    {
        m_total +=m_histogram[i];
    }
}


void FractalCreator::writeBitmap(string name)
{
    m_bitmap.write(name);
}

FractalCreator::~FractalCreator() {
}

}
