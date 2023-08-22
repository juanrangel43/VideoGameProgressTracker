#ifndef GAMEPROGRESSSTATUS_H
#define GAMEPROGRESSSTATUS_H


#include <wx/wx.h>
#include <wx/collpane.h>




class GameProgressStatus : public wxPanel
{
public:
	GameProgressStatus(wxFrame *);
	void ProgressDisplay();

	void StatusBar();
	void OnPaintDrawStatus(wxPaintEvent &event);

	void MainProgCheckBoxProperties();
	void OnToggle(wxCommandEvent &event);

	void ProgressCounter();

private:
	wxPanel *mpGPS;

	wxWindow *pCollapsPaneWin;
	wxCollapsiblePane *mpMainProgress;
	wxCheckBox *mpCB1, *mpCB2;

	// Status Bar Variables
	double completenessValue;
	int rectWidth;

	// progressCounter Variables
	int numOfTickedBoxes;
	int totalCheckBoxes;
};

const int ID_CHECKBOX = 100;


#endif