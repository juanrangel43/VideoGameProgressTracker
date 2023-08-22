#include "GameProgressStatus.h"

#include <wx/collpane.h>


GameProgressStatus::GameProgressStatus(wxFrame *parent)
	: wxPanel(parent, wxID_ANY, wxPoint(642, 36), wxSize(636, 356))
{
	mpGPS = this;

	mpMainProgress = new wxCollapsiblePane(mpGPS, wxID_ANY, "Main", wxDefaultPosition, wxDefaultSize);
	pCollapsPaneWin = mpMainProgress->GetPane();

	mpCB1 = new wxCheckBox(pCollapsPaneWin, ID_CHECKBOX, wxT("Ch. 1"), wxPoint(150, 150));
	mpCB2 = new wxCheckBox(pCollapsPaneWin, ID_CHECKBOX, wxT("Ch. 2"), wxPoint(150, 150));

	// Status Bar Parameters
	rectWidth = 0;

	// Progress Status Parameters
	completenessValue = 0.0;
	numOfTickedBoxes = 0;
	totalCheckBoxes = 2;

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

	mainProgressSubBS->Add(new wxStaticText(pCollapsPaneWin, -1, "Progress"),
		0, wxALIGN_LEFT | wxALL, 3);
	mainProgressSubBS->Add(mpCB1);

	mainProgressSubBS->Add(new wxStaticText(pCollapsPaneWin, -1, "Ch.2"),
		0, wxALIGN_LEFT | wxALL, 3);
	mainProgressSubBS->Add(mpCB2);

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
	/*
	wxColour borderColor; borderColor.Set(wxT("#000000"));
	wxColour barColor;    barColor.Set(wxT("#34E100"));
	
	wxBrush brush(wxColour(5, 216, 19));
	dc.SetBrush(brush);

	dc.SetPen(wxPen(borderColor, 1));
	dc.DrawRectangle(50, 300, 526, 30);
	*/
	wxColour startingValue; startingValue.Set(wxT("#75FD4C"));
	wxColour endingValue;   endingValue.Set(wxT("#34E100"));

	dc.GradientFillLinear(wxRect(50, 300, rectWidth, 40), startingValue, endingValue, wxEAST);
}


void GameProgressStatus::MainProgCheckBoxProperties()
{
	mpCB1->SetValue(false);
	mpCB2->SetValue(false);

	Connect(ID_CHECKBOX, wxEVT_COMMAND_CHECKBOX_CLICKED,
		wxCommandEventHandler(GameProgressStatus::OnToggle));
}


void GameProgressStatus::OnToggle(wxCommandEvent &event)
{

	if (mpCB1->GetValue() == true)
	{
		if (numOfTickedBoxes < totalCheckBoxes)
		{
			numOfTickedBoxes++;
		}

		ProgressCounter();
		rectWidth = 526 * completenessValue;
	}

	else
	{
		if (numOfTickedBoxes >= 0 && numOfTickedBoxes < totalCheckBoxes)
		{
			numOfTickedBoxes++;
		}

		rectWidth = 526 * completenessValue;
	}

	if (mpCB2->GetValue() == true)
	{
		if (numOfTickedBoxes < totalCheckBoxes)
		{
			numOfTickedBoxes++;
		}

		ProgressCounter();
		rectWidth = 526 * completenessValue;
	}

	else
	{
		if (numOfTickedBoxes >= 0)
		{
			numOfTickedBoxes--;
		}

		ProgressCounter();
		rectWidth = 526 * completenessValue;
	}

	Refresh();
}


void GameProgressStatus::ProgressCounter()
{
	completenessValue = numOfTickedBoxes / totalCheckBoxes;
}