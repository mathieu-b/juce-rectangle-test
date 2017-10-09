/*
  ==============================================================================

    Main Component

  ==============================================================================
*/

#pragma once

#include "JuceLibraryCode/JuceHeader.h"

#include <vector>

class RectanglesMatrix;

class MainComponent :
public juce::Component
{
public:

    MainComponent();
    ~MainComponent();
    
    void paint (Graphics& g) override;
    void resized() override;
    
private:

    ScopedPointer<RectanglesMatrix> mRectangles;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

