/*
 ==============================================================================
 
 MainWindow.h
 Created: 25 Jul 2017 3:49:59pm
 Author:  Andres Bucci
 
 ==============================================================================
 */

#pragma once

#include "JuceLibraryCode/JuceHeader.h"

#if (JUCE_OPENGL) && (! JUCE_IOS)
#define USE_JUCE_OPENGL
#endif

Component* createMainComponent();

class MainWindow    : public DocumentWindow
{
    
#ifdef USE_JUCE_OPENGL
    OpenGLContext mOpenGLContext;
#endif

public:

    MainWindow (String name);
    
    void closeButtonPressed() override;
    
    /* Note: Be careful if you override any DocumentWindow methods - the base
     class uses a lot of them, so by overriding you might break its functionality.
     It's best to do all your work in your content component instead, but if
     you really have to override any DocumentWindow methods, make sure your
     subclass also calls the superclass's method.
     */
    static bool isRunningOnMobileDevice();

private:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
};
