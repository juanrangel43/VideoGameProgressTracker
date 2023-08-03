#include "GameProgressStatus.h"

#include <wx/collpane.h>


GameProgressStatus::GameProgressStatus(wxFrame *parent)
	: wxPanel(parent, wxID_ANY, wxPoint(642, 36), wxSize(636, 356))
{
	ProgressDisplay();
}


void GameProgressStatus::ProgressDisplay()
{
	wxCollapsiblePane *mpMainProgress = new wxCollapsiblePane(this, wxID_ANY, "Main", wxDefaultPosition, wxDefaultSize);
	wxWindow *win = mpMainProgress->GetPane();

	wxBoxSizer *mainProgressBS = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *mainProgressSubBS = new wxBoxSizer(wxVERTICAL);
	mainProgressBS->AddSpacer(20);
	mainProgressBS->Add(mainProgressSubBS, 1);

	mainProgressBS->Add(new wxStaticText(win, -1, "Static text"), 0, wxALIGN_LEFT | wxALL, 3);
}


void GameProgressStatus::StatusBar(wxPaintEvent &event)
{
	wxPaintDC dc(this);


}