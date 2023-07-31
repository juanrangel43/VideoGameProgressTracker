#include "Toolbars.h"
#include <filesystem>
#include <string>




Toolbars::Toolbars(wxFrame *parent)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(wxEXPAND, 35))
{
    pMainFrame = parent;
    constructToolBar();
}


void Toolbars::constructToolBar()
{
    
    exit = "C:\\Users\\juanr\\OneDrive\\Documents\\Personal\\Projects\\C++\\Video Game Progress Tracker\\Video Game Progress Tracker\\Img_Toolbar\\exit.png";
    wxString wxExit(exit);

    open = "C:\\Users\\juanr\\OneDrive\\Documents\\Personal\\Projects\\C++\\Video Game Progress Tracker\\Video Game Progress Tracker\\Img_Toolbar\\open.png";
    wxString wxOpen(open);

    wxImage::AddHandler(new wxPNGHandler);

    wxBitmap exit(wxExit, wxBITMAP_TYPE_PNG);
    wxBitmap open(wxOpen, wxBITMAP_TYPE_PNG);

    toolbar1 = new wxToolBar(this, wxID_ANY);
    toolbar1->AddTool(wxID_ANY, wxT("Open"), open);
    toolbar1->AddTool(wxID_EXIT, wxT("Exit application"), exit);
    toolbar1->Realize();

    Connect(wxID_EXIT, wxEVT_COMMAND_TOOL_CLICKED,
        wxCommandEventHandler(Toolbars::OnQuit));
}


void Toolbars::OnQuit(wxCommandEvent &WXUNUSED(event))
{
    pMainFrame->Close(true);
}