/*
  ==============================================================================

    MainWindow.cpp
    Created: 25 Jul 2017 3:49:59pm
    Author:  Andres Bucci

  ==============================================================================
*/

#ifndef JUCE_IOS

#include "MainWindow.h"
#include "MainApplication.h"

bool MainWindow::isRunningOnMobileDevice()
{
#if defined(JUCE_IOS) || defined (JUCE_ANDROID)
    return true;
#else
    return false;
#endif
}

MainWindow::MainWindow (String name) :
DocumentWindow (name, Colours::lightgrey, DocumentWindow::allButtons)
{
    setUsingNativeTitleBar (false);
    
    setContentOwned (createMainComponent(), true);
    
#ifdef USE_JUCE_OPENGL
    mOpenGLContext.attachTo(*getTopLevelComponent());
#endif
    
    setUsingNativeTitleBar (true);
    
    if (MainWindow::isRunningOnMobileDevice())
    {
#ifdef JUCE_ANDROID
        /*
         * from fabian@ROLI
         *
         * From testing we know that some phones (for example Nexus 5X) will dramatically throttle there processor speed when not "touched"
         * or when not using a lot of CPU. Once you touch them it takes a fraction of a second for the processor to fire up again.
         * This has been annoying us for a while now. A workaround is to call Desktop::getInstance().setScreenSaverEnabled (false); to your code:
         * this will inject spurious touch events to keep the CPU running.
         */
        Desktop::getInstance().setScreenSaverEnabled (false);
#endif
        setFullScreen (true); // Required for receiving the resize() callback orientation updates
    }
    else
    {
        setResizable (true, true);
        centreWithSize (getWidth(), getHeight());
    }
    
    setVisible (true);
}

void MainWindow::closeButtonPressed()
{
    // This is called when the user tries to close this window. Here, we'll just
    // ask the app to quit when this happens, but you can change this to do
    // whatever you need.
    JUCEApplication::getInstance()->systemRequestedQuit();
}

//==============================================================================

// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION (MainApplication)

#endif // #if JUCE_IOS
