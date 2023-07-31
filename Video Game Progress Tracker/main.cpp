#include "main.h"
#include "GameProgressTracker.h"



IMPLEMENT_APP(RunProgram)

bool RunProgram::OnInit()
{
	GameProgressTracker *gpt = new GameProgressTracker(wxT("Game Progress Tracker"));
	gpt->Centre();
	gpt->Show(true);

	return true;
}