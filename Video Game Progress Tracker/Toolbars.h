#ifndef TOOLBARS_H
#define TOOLBARS_H


#include <wx/wx.h>




class Toolbars : public wxPanel
{
public:
	Toolbars(wxFrame *parent);

	void OnQuit(wxCommandEvent &event);
	void constructToolBar();

	wxToolBar *toolbar1;

private:
	wxFrame *pMainFrame;

	std::string open;
	std::string exit;
	//wxToolBar *toolbar2;

	//wxDECLARE_EVENT_TABLE();
};

#endif