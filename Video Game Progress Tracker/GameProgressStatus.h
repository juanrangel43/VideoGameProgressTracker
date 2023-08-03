#ifndef GAMEPROGRESSSTATUS_H
#define GAMEPROGRESSSTATUS_H


#include <wx/wx.h>
#include <wx/collpane.h>




class GameProgressStatus : public wxPanel
{
public:
	GameProgressStatus(wxFrame *);

	void ProgressDisplay();
	void StatusBar(wxPaintEvent &);

private:
	wxPanel *mpGPS;
};



#endif