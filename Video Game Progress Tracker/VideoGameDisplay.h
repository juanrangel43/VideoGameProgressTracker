#ifndef VIDEOGAMEDISPLAY_H
#define VIDEOGAMEDISPLAY_H

#include <wx/wx.h>
#include <string>
#include <filesystem>




class VideoGameDisplay : public wxPanel
{
public:
	VideoGameDisplay(wxFrame *);

	void imageChangeBtns();

	int getImgIndex();

	void loadPngImages();
	void displayImage();
	void displayNext(wxCommandEvent &);
	void displayPrevious(wxCommandEvent &);
	/*
	void DisplayTest();
	void ShowInfo(wxCommandEvent &);
	*/

private:
	wxFrame *pMainFrame;
	wxPanel *pVGDisplay;

	std::string imgLocation;
	void setImgLocation();

	int imageIndex;
	std::vector<std::filesystem::path> gameImagePaths;

	DECLARE_EVENT_TABLE()
};

enum
{
	Event_DisplayNext,
	Event_DisplayPrevious,
	Event_DisplayInfo
};





#endif