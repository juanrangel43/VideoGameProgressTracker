#include "GameProgressStatus.h"

#include <wx/collpane.h>


GameProgressStatus::GameProgressStatus(wxFrame *parent)
	: wxPanel(parent, wxID_ANY, wxPoint(642, 36), wxSize(636, 356))
{
	mpGPS = this;

	mpMainProgress = new wxCollapsiblePane(mpGPS, wxID_ANY, "Main", wxDefaultPosition, wxDefaultSize);
	pCollapsPaneWin = mpMainProgress->GetPane();

	mpCB = new wxCheckBox(pCollapsPaneWin, ID_CHECKBOX, wxT("Ch. 1"), wxPoint(150, 150));

	ProgressDisplay();
	StatusBar();
	MainProgCheckBoxProperties();
}


void GameProgressStatus::ProgressDisplay()
{
	/*
	wxCollapsiblePane *mpMainProgress = new wxCollapsiblePane(this, wxID_ANY, "Main", wxDefaultPosition, wxDefaultSize);
	pCollapsPaneWin = mpMainProgress->GetPane();
	*/
	wxBoxSizer *mainProgressBS = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *mainProgressSubBS = new wxBoxSizer(wxVERTICAL);
	mainProgressBS->AddSpacer(35);
	mainProgressBS->Add(mainProgressSubBS, 1);

	mainProgressSubBS->Add(new wxStaticText(pCollapsPaneWin, -1, "Static text"),
		0, wxALIGN_LEFT | wxALL, 3);
	mainProgressSubBS->Add(mpCB);

	wxPanel *statusBar = new wxPanel(pCollapsPaneWin);
	mainProgressSubBS->Add(statusBar, 0, wxALIGN_LEFT | wxALL, 3);
	pCollapsPaneWin->SetSizer(mainProgressBS);
}


void GameProgressStatus::StatusBar()
{
	wxPanel *statusBarBase = new wxPanel(mpGPS);
	Connect(wxEVT_PAINT, wxPaintEventHandler(GameProgressStatus::OnPaintDrawStatus));
}


// Placeholder for actual status bar
// Last checked: 8/15/23
void GameProgressStatus::OnPaintDrawStatus(wxPaintEvent &event)
{
	wxPaintDC dc(mpGPS);

	wxCoord x1 = 50, y1 = 300;
	wxCoord x2 = 190, y2 = 300;

	dc.DrawLine(x1, y1, x2, y2);
}


void GameProgressStatus::MainProgCheckBoxProperties()
{
	mpCB->SetValue(true);

	Connect(ID_CHECKBOX, wxEVT_COMMAND_CHECKBOX_CLICKED,
		wxCommandEventHandler(GameProgressStatus::OnToggle));
}


void GameProgressStatus::OnToggle(wxCommandEvent &event)
{

	if (mpCB->GetValue())
	{
		this->Show(true);
	}

	else 
	{
		this->Show(false);
	}
}