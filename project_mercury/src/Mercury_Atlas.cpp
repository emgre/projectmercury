// ==============================================================
// ORBITER vessel module: Mercury Redstone
// ==============================================================
#define ORBITER_MODULE
#include "orbitersdk.h"
#include "multi_stage5.h"
#include "mercury_capsule.h"
#include "mercury_sequencer.h"
#include "atlas.h"

DLLCLBK void InitModule (HINSTANCE hModule)
{
	g_Param.hDLL = hModule;
	// allocate GDI resources
	g_Param.col[2] = oapiGetColour(80,80,224);
	g_Param.col[3] = oapiGetColour(160,120,64);
	g_Param.font[0]  = CreateFont (-8, 0, 0, 0, 400, 0, 0, 0, 0, 0, 0, 0, 0, "Arial");
	g_Param.font[1]  = CreateFont (-10, 0, 0, 0, 800, 0, 0, 0, 0, 0, 0, 0, 0, "Arial");
	g_Param.brush[0] = CreateSolidBrush (RGB(0,255,0));    // green
	g_Param.brush[1] = CreateSolidBrush (RGB(255,0,0));    // red
	g_Param.brush[2] = CreateSolidBrush (RGB(80,80,224));  // blue
	g_Param.brush[3] = CreateSolidBrush (RGB(160,120,64));  // brown
	g_Param.brush[4] = CreateSolidBrush (RGB(0,0,0));  // brown
	g_Param.pen[0] = CreatePen (PS_SOLID, 1, RGB(224,224,224));
	g_Param.pen[1] = CreatePen (PS_SOLID, 3, RGB(164,164,164));
	g_Param.pen[2] = CreatePen (PS_SOLID, 2, RGB(255,255,254));
	g_Param.pen[3] = CreatePen (PS_SOLID, 1, RGB(255,255,254));
	fuel_auto = 0;
	fuel_manual = 0;
}

DLLCLBK void ExitModule (HINSTANCE hModule)
{
	// deallocate GDI resources
	int i;
	for (i = 0; i < 2; i++) DeleteObject (g_Param.font[i]);
	for (i = 0; i < 5; i++) DeleteObject (g_Param.brush[i]);
	for (i = 0; i < 4; i++) DeleteObject (g_Param.pen[i]);
}

// Initialisation
DLLCLBK VESSEL *ovcInit (OBJHANDLE hvessel, int flightmodel)
{
	Multi_Stage *Vessel;
	//ConnectToOrbiterSoundDLL();
	//SoundOptionOnOff(PLAYCOUNTDOWNWHENTAKEOFF,FALSE);
	//SoundOptionOnOff(PLAYRADARBIP,FALSE);
	//SoundOptionOnOff(PLAYRADIOATC,FALSE);
	Mercury_ControlPanel *ControlPanel;
	//Multi_Stage *Vessel;
	ControlPanel  = new Mercury_ControlPanel();
	Vessel = new Multi_Stage(hvessel);
	Vessel->SetPanel(ControlPanel);
	return Vessel;
}

// Cleanup
DLLCLBK void ovcExit (VESSEL *vessel)
{
	if (vessel) delete (Multi_Stage*) vessel;
}

// Keyboard interface handler
int Multi_Stage::clbkConsumeKey (const char *keystate)
{
	ConsumeKey(keystate);
	return 0;
}

int Multi_Stage::clbkConsumeBufferedKey (DWORD key, bool down, char *kstate)
{
	if (!down) return 0; // only process keydown events

	return ConsumeBufferedKey(key, down, kstate);
}
// Set the capabilities of the vessel class
//DLLCLBK void ovcSetClassCaps (VESSEL *vessel, FILEHANDLE cfg)
void Multi_Stage::clbkSetClassCaps (FILEHANDLE cfg)
{
	IStage *newStage;
	//RequestLoadVesselWave(SOUND_THRUSTER,		"Sound\\Vessel\\attfire.wav");
	//RequestLoadVesselWave(SOUND_COUNTDOWN,      "Sound\\mercury\\atlascountdown.wav");
	//RequestLoadVesselWave(SOUND_STAGESEP,       "Sound\\mercury\\stagesep.wav");
	//RequestLoadVesselWave(SOUND_TOWERJETT,      "Sound\\mercury\\towerjet.wav");
	//RequestLoadVesselWave(SOUND_MERCSEP,        "Sound\\mercury\\mercsep.wav");
	//RequestLoadVesselWave(SOUND_DECOMP,			"Sound\\mercury\\decomp.wav");
	//RequestLoadVesselWave(SOUND_REPRESS,        "Sound\\mercury\\repress.wav");
	//RequestLoadVesselWave(SOUND_FUSECLICK,      "Sound\\mercury\\fuseclick.wav");
	//RequestLoadVesselWave(SOUND_PULLPUSH,       "Sound\\mercury\\pullpush.wav");
	//RequestLoadVesselWave(SOUND_RINGPULL,       "Sound\\mercury\\ringpull.wav");
	//RequestLoadVesselWave(SOUND_SWITCH,         "Sound\\mercury\\switch.wav");
	//RequestLoadVesselWave(SOUND_WARNING,        "Sound\\mercury\\warning.wav");
	//RequestLoadVesselWave(SOUND_DROGUE,         "Sound\\mercury\\drogue.wav");
	//RequestLoadVesselWave(SOUND_RETRO1,         "Sound\\mercury\\retro1.wav");
	//RequestLoadVesselWave(SOUND_RETRO2,         "Sound\\mercury\\retro2.wav");
	//RequestLoadVesselWave(SOUND_RETRO3,         "Sound\\mercury\\retro3.wav");
	//RequestLoadVesselWave(SOUND_RETROSEP,       "Sound\\mercury\\retrosep.wav");
	//RequestLoadVesselWave(SOUND_COMMCHECK,      "Sound\\mercury\\commcheck.wav");
	//RequestLoadVesselWave(SOUND_SPLASHDOWN,     "Sound\\mercury\\splashdown.wav");
	//RequestLoadVesselWave(SOUND_CHUTE,          "Sound\\mercury\\chute.wav");
	//RequestLoadVesselWave(SOUND_LANDINGBAG,     "Sound\\mercury\\landingbag.wav");
	//RequestLoadVesselWave(SOUND_BLOODPRESS,     "Sound\\mercury\\bloodpress.wav");
	//RequestLoadVesselWave(SOUND_RATTLE,         "Sound\\mercury\\rattle.wav");
	//RequestLoadVesselWave(SOUND_RE_RATTLE,      "Sound\\mercury\\reenty_rattle.wav");
	
	newStage = new AtlasD((Mercury_ControlPanel*)GetPanel());
	SetStage(newStage,0);
}


void Multi_Stage::clbkPostStep(double simt, double simdt, double mjd)
{
	Timestep(simt);
}


void Multi_Stage::clbkLoadStateEx (FILEHANDLE scn, void * vs)
{
    char *line;
	int status = 0;
	bool setconfiguration=false;
	double test=0.0;
	IStage *newStage;
	while (oapiReadScenario_nextline (scn, line)) {
		if (setconfiguration) {
			if (!_strnicmp (line, "<SYSTEMS>", 9)) {
				ParseSystem(scn);
			} else {
				ParseLine(line, vs);
			}
		} else {
			if (!_strnicmp (line, "CONFIGURATION", 13)) {
				sscanf (line+13, "%d", &status);
				switch (status) {
				case 0:
					newStage = new AtlasD((Mercury_ControlPanel*)GetPanel());
					break;
				case 1:
					newStage = new AtlasD((Mercury_ControlPanel*)GetPanel());
					break;
				case 3:
					newStage = new Mercury_Capsule((Mercury_ControlPanel*)GetPanel());
					break;
				case 4:
					newStage = new Mercury_Capsule((Mercury_ControlPanel*)GetPanel());
					break;
				case 5:
					newStage = new Mercury_Capsule((Mercury_ControlPanel*)GetPanel());
					break;
				}
				SetStage(newStage,oapiGetSimTime());
				setconfiguration=true;
			} else {
				ParseScenarioLineEx (line, vs);
			}
		}
    }
	Setup(oapiGetSimTime());
}

// Save status to scenario file
void Multi_Stage::clbkSaveState (FILEHANDLE scn)
{
	SaveDefaultState(scn);
	SaveState(scn);
}

bool Multi_Stage::clbkLoadPanel (int id)
{
	return LoadPanel(id); //ControlPanel->LoadPanel(vessel, id);
}

bool Multi_Stage::clbkPanelRedrawEvent (int id, int event, SURFHANDLE surf)
{
	return PanelRedrawEvent(id,event,surf);
}


bool Multi_Stage::clbkPanelMouseEvent (int id, int event, int mx, int my)
{
	return PanelMouseEvent(id,event,mx,my);
}

void Multi_Stage::clbkAnimate (double simt)
{
	Animate(simt);
}

void Multi_Stage::clbkVisualCreated (VISHANDLE vis, int refcount)
{
	VisualCreated(vis,refcount);
}

void Multi_Stage::clbkVisualDestroyed (VISHANDLE vis, int refcount)
{
	VisualDestroyed(vis,refcount);
}
