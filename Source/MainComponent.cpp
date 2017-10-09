/*
  ==============================================================================

    MainComponent.cpp
    Created: 26 Jun 2017 3:15:14pm
    Author:  Mathieu Bosi

  ==============================================================================
*/

#include "MainComponent.h"

#include "RectanglesMatrix.h"


// (This function is called by the app startup code to create our main component)
Component* createMainComponent()
{
    return new MainComponent();
}

MainComponent::MainComponent():
juce::Component("MainComponent")
{
    addAndMakeVisible(mRectangles = new RectanglesMatrix());
    
#if defined(JUCE_IOS) || defined (JUCE_ANDROID)
    // Go full-parent size
    setSize(getParentWidth(), getParentHeight());
#else
    // Properly resize the window
    setSize(1024, 768);
#endif
    
}

MainComponent::~MainComponent()
{
}

float sin01(double a)
{
    return (std::sin(a) + 1.0) * 0.5;
}

float cos01(double a)
{
    return (std::cos(a) + 1.0) * 0.5;
}

void MainComponent::paint (Graphics& g)
{
    const double ts = Time::getMillisecondCounterHiRes() / 1000.0;
    
    g.fillAll(juce::Colours::black);
    
    auto new_bounds = getBounds();
    
    const double t = ts * 0.05;
    
    new_bounds.reduce(sin01(t) * 100.0, cos01(t*0.93) * 100.0);
    new_bounds.translate(cos01(t*1.1) * 25.0, sin01(t * 1.11) * 25.0);
    
    mRectangles->setBounds(new_bounds);
    
    g.setColour(juce::Colours::yellow);
    
    g.drawRect(mRectangles->getBounds());
}

void MainComponent::resized()
{
    repaint();
}

#pragma mark - Mouse Listener

void MainComponent::mouseDown(const juce::MouseEvent &event)
{

}

void MainComponent::timerCallback()
{
    
}

