/*
  ==============================================================================

    Main Component

  ==============================================================================
*/

#pragma once

#include "JuceLibraryCode/JuceHeader.h"

#include <vector>

class RectanglesMatrix;

/// This Component can be in charge of switching between one or more views
class MainComponent :
public juce::Component,
private juce::Timer
{
public:

    MainComponent();
    ~MainComponent();
    
    void paint (Graphics& g) override;
    void resized() override;
    void mouseDown (const MouseEvent& event) override;
    
private:
    
    void timerCallback() override;
    
    
    ScopedPointer<RectanglesMatrix> mRectangles;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

