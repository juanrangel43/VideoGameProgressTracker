#include "GameProgressTracker.h"
#include "VideoGameDisplay.h"
#include "Toolbars.h"




GameProgressTracker::GameProgressTracker(const wxString &title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(1280, 720))
{
    construct();
}


void GameProgressTracker::construct()
{
    Toolbars *toolbars = new Toolbars(this);
    VideoGameDisplay *leftDisplay = new VideoGameDisplay(this);
}