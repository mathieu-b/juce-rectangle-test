
#include "RectanglesMatrix.h"

RectanglesMatrix::RectanglesMatrix ()
{
}

RectanglesMatrix::~RectanglesMatrix()
{
}

//==============================================================================
void RectanglesMatrix::paint (Graphics& g)
{
    g.getInternalContext().setInterpolationQuality(Graphics::ResamplingQuality::lowResamplingQuality);

    const int nx = 10;
    const int ny = 10;
    
    const auto & bounds = getLocalBounds();
    
    const int rect_width = bounds.getWidth() / nx;
    const int rect_height = bounds.getHeight() / ny;
    
    const auto & top_left = bounds.getTopLeft();
    
    g.setColour(Colours::cyan);
    
    for (int j = 0, y = top_left.getY(); j < ny; j++, y += rect_height)
    {
        for (int i = 0, x = top_left.getX(); i < nx; i++, x += rect_width)
        {
            g.fillRect(x, y, rect_width - 1, rect_height - 1);
        }
    }
    
    repaint();
}

void RectanglesMatrix::resized()
{

}
