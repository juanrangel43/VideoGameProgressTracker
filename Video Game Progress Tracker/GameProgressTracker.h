#include <wx/wx.h>



class GameProgressTracker : public wxFrame
{
public:
	GameProgressTracker(const wxString &title);

	void construct();
};