
#include "FractalCreator.h"

namespace fractal{
    
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
                    green = hue*255;
             }
             
            m_bitmap.setPixel(x,y,red,green,blue);
//            if(color < min ) min = color;
//            if(color > max) max = color;
        }
    }
}
void FractalCreator::calculateTotalIterations()
{
    for(int i=0;i<Mandelbrot::MAX_ITERATIONS;i++)
    {
        m_total +=m_histogram[i];
    }
}
void FractalCreator::addZoom(const Zoom& zoom)
{
  m_zoomList.add(zoom);   
}
void FractalCreator::writeBitmap(string name)
{
    m_bitmap.write(name);
}

FractalCreator::~FractalCreator() {
}

}
