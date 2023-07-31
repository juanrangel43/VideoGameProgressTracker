#include <wx/wx.h>
#include "VideoGameDisplay.h"
#include "Toolbars.h"


class GameProgressTracker : public wxFrame
{
public:
	GameProgressTracker(const wxString &title);

	void construct();
};