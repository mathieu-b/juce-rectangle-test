
#pragma once

#include "JuceLibraryCode/JuceHeader.h"


class RectanglesMatrix  : public Component
{
    
public:

    RectanglesMatrix ();
    ~RectanglesMatrix();

    void paint (Graphics& g) override;
    void resized() override;

private:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RectanglesMatrix)
    
};

