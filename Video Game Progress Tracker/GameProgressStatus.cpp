#include "GameProgressStatus.h"

#include <wx/collpane.h>


GameProgressStatus::GameProgressStatus(wxFrame *parent)
	: wxPanel(parent, wxID_ANY, wxPoint(642, 36), wxSize(636, 356))
{
	mpGPS = this;

	ProgressDisplay();
	//StatusBar();
}


void GameProgressStatus::ProgressDisplay()
{
	wxCollapsiblePane *mpMainProgress = new wxCollapsiblePane(this, wxID_ANY, "Main", wxDefaultPosition, wxDefaultSize);
	wxWindow *win = mpMainProgress->GetPane();
	
	wxBoxSizer *mainProgressBS = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *mainProgressSubBS = new wxBoxSizer(wxVERTICAL);
	mainProgressBS->AddSpacer(20);
	mainProgressBS->Add(mainProgressSubBS, 1);

	mainProgressSubBS->Add(new wxStaticText(win, -1, "Static text"), 0, wxALIGN_LEFT | wxALL, 3);

	wxPanel *statusBar = new wxPanel(win);
	//statusBar->Connect(wxEVT_PAINT, wxPaintEventHandler(GameProgressStatus::OnPaintDrawStatus));

	mainProgressSubBS->Add(statusBar, 0, wxALIGN_LEFT | wxALL, 3);

	win->SetSizer(mainProgressBS);
}


void GameProgressStatus::StatusBar()
{
	wxPanel *statusBarBase = new wxPanel(mpGPS);
	Connect(wxEVT_PAINT, wxPaintEventHandler(GameProgressStatus::OnPaintDrawStatus));
}


void GameProgressStatus::OnPaintDrawStatus(wxPaintEvent &event)
{
	wxPaintDC dc(mpGPS);

	wxCoord x1 = 50, y1 = 60;
	wxCoord x2 = 190, y2 = 60;

	dc.DrawLine(x1, y1, x2, y2);
}