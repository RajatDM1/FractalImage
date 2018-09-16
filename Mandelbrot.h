
#ifndef MANDELBROT_H
#define MANDELBROT_H
namespace fractal{
class Mandelbrot {
public:
    static const int MAX_ITERATIONS = 1000;
public:
    Mandelbrot();
//    Mandelbrot(const Mandelbrot& orig);
    virtual ~Mandelbrot();
    
    static int getIterations(double x , double y);
};
}

#endif /* MANDELBROT_H */

