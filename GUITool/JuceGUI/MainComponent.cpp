#include "MainComponent.h"
#include "juce_gui_basics/juce_gui_basics.h"
//==============================================================================
MainComponent::MainComponent()
{


	m_FileChooser = std::make_unique <FileChooser>("Select the json file", File::getSpecialLocation(File::userHomeDirectory), "*.json");

	addAndMakeVisible(m_DataTable);

	m_pTableModel = new TableModel();
	m_DataTable.setModel(m_pTableModel);
	m_DataTable.getHeader().addColumn("Name", 1, 100, 50, 200);
	m_DataTable.getHeader().addColumn("x", 2, 50, 20, 60);
	m_DataTable.getHeader().addColumn("y", 3, 50, 20, 60);
	m_DataTable.getHeader().addColumn("z", 4, 50, 20, 60);



	m_SetInputButton = new juce::TextButton("Input Path", "Click this button to set the input path");
	m_SetInputButton->setBounds(10, 10, 100, 50);
	m_SetInputButton->onClick = ([this]() {


		auto folderChooserFlags = FileBrowserComponent::openMode | FileBrowserComponent::canSelectFiles;


		m_FileChooser->launchAsync(folderChooserFlags, [&](const FileChooser& chooser)
			{
				File jsonFile(chooser.getResult());

				if (!jsonFile.existsAsFile())
					return;

				m_ChosenFilePath = jsonFile.getFullPathName();


				std::vector<std::vector<float>> vertices = FileReader::GetJsonVertices(m_ChosenFilePath.toWideCharPointer());

				int verCount{};
				for (auto& vertex : vertices)
				{
					std::string vectorName = "vertex" + std::to_string(verCount);
					m_pTableModel->AddVector({ vectorName,vertex[0], vertex[1], vertex[0] });
					++verCount;
				}

				m_DataTable.updateContent();


			});

		

		});

	addAndMakeVisible(m_SetInputButton);

	m_MakeOutputButton = new juce::TextButton("Convert", "Convert the json into a obj");
	m_MakeOutputButton->setBounds(10, 70, 100, 50);
	m_MakeOutputButton->onClick = ([this]() {

		if (m_ChosenFilePath.isEmpty())
		{
			AlertWindow::showMessageBoxAsync(juce::AlertWindow::WarningIcon,
				"Error",
				"Please choose an input file!",
				"OK");
			return;
		}

		auto folderChooserFlags = FileBrowserComponent::openMode | FileBrowserComponent::canSelectDirectories;

		m_FileChooser->launchAsync(folderChooserFlags, [this](const FileChooser& chooser)
			{
				File DirectoryPath(chooser.getResult());

				if (!DirectoryPath.exists())
					return;

				auto output = DirectoryPath.getFullPathName();


				FileReader::ConvertJSON(m_ChosenFilePath.toWideCharPointer(), output.toWideCharPointer());
			});

		});
	addAndMakeVisible(m_MakeOutputButton);


	// Make sure you set the size of the component after
	// you add any child components.
	setSize(800, 600);
	setFramesPerSecond(60); // This sets the frequency of the update calls.
}

MainComponent::~MainComponent()
{
	//delete m_pTableModel;

	delete m_SetInputButton;
	delete m_MakeOutputButton;
}

//==============================================================================
void MainComponent::update()
{
	// This function is called at the frequency specified by the setFramesPerSecond() call
	// in the constructor. You can use it to update counters, animate values, etc.
}

//==============================================================================
void MainComponent::paint(juce::Graphics& g)
{
	// (Our component is opaque, so we must completely fill the background with a solid colour)
	g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

	// You can add your drawing code here!
}

void MainComponent::resized()
{
	// This is called when the MainContentComponent is resized.
	// If you add any child components, this is where you should
	// update their positions.
	m_DataTable.setBounds(0, 0, getWidth(), getHeight() - 100);


	m_SetInputButton->setBounds(10, getHeight() - 60, 100, 50);
	m_MakeOutputButton->setBounds(150, getHeight() - 60, 100, 50);

}
