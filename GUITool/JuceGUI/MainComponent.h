#pragma once

#include <JuceHeader.h>
#include "TableModel.h"
#include <memory>

#include <FileReader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::AnimatedAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void update() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...
    juce::TableListBox m_DataTable;
    TableModel* m_pTableModel;

    std::unique_ptr<FileChooser> m_FileChooser{};
    juce::String m_ChosenFilePath{};


    juce::TextButton* m_SetInputButton{};
    juce::TextButton* m_MakeOutputButton{};


    juce::String m_Path;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
