
#include "ZoomList.h"
#include "zoom.h"
#include <iostream>
using namespace std;
namespace fractal{
ZoomList::ZoomList(int width, int height):m_height(height), m_width(width){
}

void ZoomList::add(const Zoom& zoom){
    zooms.push_back(zoom);
    m_xCenter  +=(zoom.x - m_width/2)*m_scale;//how far from center point has user clicked
    m_yCenter  +=(zoom.y - m_height/2)*m_scale;
    cout<<m_scale<<endl;
    cout<<zoom.scale<<endl;
    m_scale *= zoom.scale;//new scale
    cout<<m_xCenter<<","<<m_yCenter<<","<<m_scale<<endl;
}

pair<double,double> ZoomList::doZoom(int x,int y){
    double xFractal = (x-m_width/2)*m_scale+m_xCenter;//we can apply scale only about the center
    double yFractal = (y-m_height/2)*m_scale+m_yCenter;
    
    return pair<double,double>(xFractal,yFractal);
}
//ZoomList::ZoomList(const ZoomList& orig) {
//}
}


