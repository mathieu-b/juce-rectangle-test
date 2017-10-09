/*
  ==============================================================================

    MainApplication.h
    Created: 25 Jul 2017 4:44:23pm
    Author:  Andres Bucci

  ==============================================================================
*/

#pragma once

#include "JuceLibraryCode/JuceHeader.h"

class MainWindow;

class MainApplication : public JUCEApplication
{
public:
    
    MainApplication();
    
    //
    // JUCEApplication interface:
    //
    const String getApplicationName() override;
    const String getApplicationVersion() override;
    bool moreThanOneInstanceAllowed() override;
    void initialise (const String& command_line) override;
    void shutdown() override;
    void systemRequestedQuit() override;
    void anotherInstanceStarted (const String& commandLine) override;
    void backButtonPressed() override;
    void suspended() override;
    void resumed() override;

private:

    ScopedPointer<MainWindow> mainWindow;
    
    bool mApplicationWasRunningOnSuspend = false;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainApplication)
    
};
