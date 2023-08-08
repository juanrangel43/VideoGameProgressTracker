#include <wx/wx.h>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <regex>
#include "VideoGameDisplay.h"





VideoGameDisplay::VideoGameDisplay(wxFrame *parent)
	: wxPanel(parent, wxID_ANY, wxPoint(0, 36), wxSize(640, 720))
{
	imgLocation = "C:\\Users\\juanr\\OneDrive\\Documents\\Personal\\Projects\\C++\\Video Game Progress Tracker\\Video Game Progress Tracker\\Img_Games\\Img_Games_Test_Pokeball.png";
	imageIndex = -1;

	pMainFrame = parent;
	pVGDisplay = this;

	imageChangeBtns();

	loadPngImages();
	//displayImage();
	//DisplayTest();
}


void VideoGameDisplay::imageChangeBtns()
{
	/*
		Note to Self:
		Find out why the coordinates don't match up with
		math. Where is the actual origin then???
	*/
	wxButton *Previous = new wxButton(this, Event_DisplayPrevious, wxT("Previous"), wxPoint(475, 610));
	wxButton *Next = new wxButton(this, Event_DisplayNext, wxT("Next"), wxPoint(550, 610));
}


void VideoGameDisplay::displayImage()
{
	wxString convertTxt(imgLocation);

	wxImage::AddHandler(new wxPNGHandler);
	wxBitmap gameImg(convertTxt, wxBITMAP_TYPE_PNG);

	wxStaticBitmap *imageBitmap = new wxStaticBitmap(this, wxID_ANY, gameImg, wxPoint(160, 100));
}


void VideoGameDisplay::loadPngImages()
{
	//std::string pngFolder = "C:\\Users\\juanr\\OneDrive\\Documents\\Personal\\Projects\\C++\\Video Game Progress Tracker\\Video Game Progress Tracker\\Img_Games";
	std::string pngFolder = "C:\\Users\\juanr\\Documents\\Coding\\C++\\VideoGameProgressTracker\\Video Game Progress Tracker\\Img_Games";

	std::filesystem::path gamePngLocation = pngFolder;

	std::smatch m;
	std::regex targetPngFiles("\S*.*[.png]");

	for (const auto &entry : std::filesystem::directory_iterator(gamePngLocation))
	{
		std::string pathToString = entry.path().string();
		

		if (regex_match(pathToString, m, targetPngFiles) == true)
		{
			gameImagePaths.push_back(entry.path());
		} 
	}
}


void VideoGameDisplay::setImgLocation()
{
	getImgIndex();
	imgLocation = gameImagePaths[imageIndex].string();
}


int VideoGameDisplay::getImgIndex()
{
	for (int i = 0; i < gameImagePaths.size(); i++)
	{
		if (imgLocation == gameImagePaths[i].string())
		{
			imageIndex = i;
		}
	}

	return imageIndex;
}


// NOTE TO SELF
/* 
   Need to put some type of exception for going out of bounds
   and how the vectors are keeping tracking of positioning the
   the image within the program
*/
void VideoGameDisplay::displayNext(wxCommandEvent &WXUNUSED(event))
{
	if (getImgIndex() + 1 < gameImagePaths.size())
	{
		imgLocation = gameImagePaths[getImgIndex() + 1].string();
	}

	else
	{
		std::cerr << "Out of Bounds" << std::endl;
	}

	displayImage();
}


void VideoGameDisplay::displayPrevious(wxCommandEvent &WXUNUSED(event))
{
	if (getImgIndex() - 1 >= 0)
	{
		imgLocation = gameImagePaths[getImgIndex() - 1].string();
	}

	else
	{
		std::cerr << "Out of Bounds"<< std::endl;
	}

	displayImage();
}


// ===== Uncomment when time to check if proper files are being read ====

/*
void VideoGameDisplay::DisplayTest()
{
	wxButton *btn1 = new wxButton(this, Event_DisplayInfo, wxT("Info"));

	Connect(wxID_ANY, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(VideoGameDisplay::ShowInfo));
}


void VideoGameDisplay::ShowInfo(wxCommandEvent &event)
{
	std::string pngPath;

	for (int i = 0; i < gameImagePaths.size() - 1; i++)
	{
		pngPath = gameImagePaths[i].string() + gameImagePaths[i + 1].string();
	}

	wxString strToWxStr = pngPath;


	wxMessageDialog *dial = new wxMessageDialog(NULL, strToWxStr, wxT("Info"), wxOK | wxCANCEL);
	dial->ShowModal();
}
*/


BEGIN_EVENT_TABLE(VideoGameDisplay, wxPanel)
	EVT_BUTTON(Event_DisplayPrevious, VideoGameDisplay::displayPrevious)
	EVT_BUTTON(Event_DisplayNext, VideoGameDisplay::displayNext)
	//EVT_BUTTON(Event_DisplayInfo, VideoGameDisplay::ShowInfo)
END_EVENT_TABLE()