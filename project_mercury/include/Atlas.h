#ifndef __ATLAS_H
#define __ATLAS_H

#include "orbitersdk.h"
#include "multi_stage5.h"
#include "mercury_capsule.h"
#include "orbitelements.h"
//#include "OrbiterSoundSDK.h"

const double  STAGE1_MASS        = 113050*KG;
const double  STAGE1_MASS_EMPTY  = 2347.0*KG;
const double  STAGE1_MASS_FUEL   = STAGE1_MASS-STAGE1_MASS_EMPTY;

const double  SUBSTAINER_ISP_SL      = 215*SEC;
const double  SUBSTAINER_ISP_VAC     = 309*SEC;
const double  SUBSTAINER_THRUST_VAC  = 37038*KGF;
const VECTOR3 SUBSTAINER_OFS_FLAME  = { 0.0, 0.0, -22.34};
const VECTOR3 SUBSTAINER_FLAME_DIR  = { 0.0, 0.0, 1.0};

const double  VERNIER_THRUST_VAC    = 453.592*KGF;
const double  VERNIER_ISP_SL      = 279*SEC;
const double  VERNIER_ISP_VAC     = 300*SEC;

const double  BOOSTER_LENGTH     = 1.93;
const double  BOOSTER_MASS       = 3050.0*KG;
const double  BOOSTER_MASS_EMPTY = 3050.0*KG;
const double  BOOSTER_ISP_SL     = 248*SEC;
const double  BOOSTER_ISP_VAC    = 282*SEC;
const double  BOOSTER_THRUST_VAC = 154734*KGF / 2;

const VECTOR3 OFS_ATLAS = { 0.0, 0.0, -11.6};
const VECTOR3 OFS_BOOSTER = { 0.0, 0.0, -20.2};
const VECTOR3 OFS_ADAPTER = { 0.0, 0.0, -1.55};

const VECTOR3 BOOSTER1_OFS_FLAME  = {-1.5, 0.0, -22.34};;
const VECTOR3 BOOSTER2_OFS_FLAME  = { 1.5, 0.0, -22.34};;
const VECTOR3 BOOSTER_FLAME_DIR  = { 0.0, 0.0, 1.0};

const VECTOR3 VERNIER1_OFS_FLAME  = {0,0,-20.44};;
const VECTOR3 VERNIER1_FLAME_DIR  = { 0,-.866,.5};
const VECTOR3 VERNIER2_OFS_FLAME  = {0,0,-20.44};;
const VECTOR3 VERNIER2_FLAME_DIR  = { 0,.866,.5};

const VECTOR3 OFS_ADAPTRING1 = {-0.61, 0.35,  -0.93};
const VECTOR3 OFS_ADAPTRING2 = {0.0, -0.82,  -0.93};
const VECTOR3 OFS_ADAPTRING3 = {0.61, 0.35,  -0.93};
const VECTOR3 OFS_ADAPTCOVER1 = {0.0, 0.91, -0.9};
const VECTOR3 OFS_ADAPTCOVER2 = {-0.74, -0.43,  -0.9};
const VECTOR3 OFS_ADAPTCOVER3 = {0.74, -0.43,  -0.9};

//double const slBooster  = 667234.0;
//double const vacBooster = 758711.0;
//double const slSub      = 252717.0;
//double const vacSub     = 363218.0;
//double const boosterISP = 286;
//double const vacISP     = 303;

#define N	10	// flight plan table size
//const double met[N]    = { 0, 15, 55, 115, 205, 215, 225, 257, 267, 300};   // MET in sec
//const double cpitch[N] = {90, 90, 60,  30,   0,   0, -12, -12,   0,   0};	// Commanded pitch in °
const double met[N]    = { 0, 15, 55, 115, 205, 245, 250, 257, 267, 300};   // MET in sec
const double cpitch[N] = {90, 90, 60,  30,   5,   5, -12, -12,   0,   0};	// Commanded pitch in °


static void AutoPilot(VESSEL *vessel, double t, THRUSTER_HANDLE main_engine)
{
	static int first_time=1;
	static double last_time;
	static double total_off;
	static bool done_kill_velocity;
	double level=0.;
	double pitch;
	double target_att;
	double drop_vel;
	double airspeed;
	VECTOR3 ang_vel;
	char current_key=0;
 // suggestion : you could also check here for minimum eccentricity with the new API
 // and cut off when reached.
	if (t > 319.0)	// stop any rotation 1 sec before SECO
	{
		if (first_time) 
		{
			vessel->SetThrusterDir(main_engine,_V(0,-total_off,1));
			first_time=0;
		}
		return;
	}
 // navigation
	oapiGetFocusPitch(&pitch);
	pitch=pitch*DEG;
	oapiGetAirspeed(vessel->GetHandle(), &airspeed);

 // guidance
	vessel->GetAngularVel(ang_vel);
	//sprintf(oapiDebugString(), "Time: %f, Pitch: %f x: %f, y: %f, z: %f",t, pitch, ang_vel.x, ang_vel.y, ang_vel.z);
	drop_vel = -0.0125;
	target_att = -5.0;
	drop_vel = -0.0120;
	target_att = -4;
 // control
	if (t<16.) {
		vessel->SetThrusterDir(main_engine,_V(0,0,1));
		total_off = 0.0;
	} else if (pitch > (target_att - 0.5) && pitch < (target_att + 0.5)) {
		if (ang_vel.x > .001) 
			current_key = OAPI_KEY_NUMPAD2;
		else if (ang_vel.x < -.001)
			current_key = OAPI_KEY_NUMPAD8;
		else
			current_key = OAPI_KEY_NUMPAD5;
	} else if (pitch < (target_att - 0.5)) {
		if (ang_vel.x > -drop_vel +.0005) 
			current_key = OAPI_KEY_NUMPAD2;
		else if (ang_vel.x < -drop_vel-.0005)
			current_key = OAPI_KEY_NUMPAD8;
		else
			current_key = OAPI_KEY_NUMPAD5;
	} else {
		if (ang_vel.x > drop_vel +.0005) 
			current_key = OAPI_KEY_NUMPAD2;
		else if (ang_vel.x < drop_vel - .0005)
			current_key = OAPI_KEY_NUMPAD8;
		else
			current_key = OAPI_KEY_NUMPAD5;
	}
	if (current_key == OAPI_KEY_NUMPAD2) {
		vessel->SetThrusterDir(main_engine,_V(0,0.01,1));
		total_off += .01 * (t-last_time);
	} else if (current_key == OAPI_KEY_NUMPAD5) {
		vessel->SetThrusterDir(main_engine,_V(0,0,1));
		total_off = 0;
	} else if (current_key == OAPI_KEY_NUMPAD8) {
		vessel->SetThrusterDir(main_engine,_V(0,-0.01,1));
		total_off -= .01 * (t-last_time);
	} else {
		vessel->SetThrusterDir(main_engine,_V(0,0,1));
	}
	last_time = t;	
}

static void AutoPilot2(VESSEL *vessel, double t, THRUSTER_HANDLE main_engine) {
	double pitch = 0.0;
	double target_att = 0.0;
	bool do_att = false;
	double drop_vel = 0.0;
	double tempD = 0.0;
	static double targetP = 0.0;
	static double endP = 0.0;
	static double last_alt = 0.0;
	VECTOR3 ang_vel;

// navigation
	oapiGetFocusPitch(&pitch);
	pitch=pitch*DEG;

 // guidance
	vessel->GetAngularVel(ang_vel);
	target_att = 0.0;
	do_att = false;
 // control
	if (t<15.0) {
		vessel->SetThrusterDir(main_engine,_V(0,0,1));
	} else {
// guidance
		vessel->GetAngularVel(ang_vel);

		if (t < 27.0) {
			targetP  = 0.0;
			endP  = 0.0;
			drop_vel = -.96*RAD;
		} else if (t < 39.0) {
			drop_vel = -.76*RAD;
		} else if (t < 64.0) {
			drop_vel = -.64*RAD;
		} else if (t < 79.0) {
			drop_vel = -.72*RAD;
		} else if (t < 89.0) {
			drop_vel = -.68*RAD;
		} else if (t < 105.0) {
			drop_vel = -.40*RAD;
		} else if (t < 120.0) {
			drop_vel = -.28*RAD;
		} else if (t < 131.34) {
			drop_vel = -.24*RAD;
		} else if (t < 136.34) {
			targetP = pitch;
			targetP = vessel->GetAltitude();

			drop_vel = 0.0;
		} else if (t < 136.34 + 15) {

		//} else if (t < 136.34 + ((targetP - -6) / 2)) {
			drop_vel = -2.0*RAD;
			endP = pitch;
			endP = vessel->GetAltitude();
		} else {
			do_att = true;
			target_att = -4;
			drop_vel = 0.0;
			//AutoPilot(vessel, t, main_engine);
			//return;
		}
 // control
		if (do_att) {
			if (pitch > (target_att - 0.5) && pitch < (target_att + 0.5)) {
				if (ang_vel.x > .0005) 
					tempD = .01;
				else if (ang_vel.x < -.0005)
					tempD = -.01;
			} else if (pitch < (target_att - 0.5)) {
				tempD = -.01;
			} else if (pitch > (target_att + 0.5)) {
				tempD = .01;
			}
		} else {
			if (ang_vel.x > drop_vel+.0005 ) 
				tempD = 0.01;
			else if (ang_vel.x < drop_vel - .0005)
				tempD = -0.01;
		}

		
		vessel->SetThrusterDir(main_engine,_V(0,tempD,1));
	}
	//sprintf(oapiDebugString(), "Time: %f, Pitch: %f alt: %f, tp: %f, ep: %f dv: %f",t, pitch, 0.0, targetP, endP, drop_vel*DEG);
	last_alt = vessel->GetAltitude();
}

void AddAtlas(VESSEL *vessel)
{
	VECTOR3 mesh_dir;
	mesh_dir=OFS_ADAPTER;
	vessel->AddMesh ("merc_atl_adapt", &mesh_dir);
	mesh_dir=OFS_ATLAS;
	vessel->AddMesh ("merc_atl_main", &mesh_dir);
	vessel->AddMesh (oapiLoadMeshGlobal("merc_adaptcover1"), &OFS_ADAPTCOVER1);
	vessel->AddMesh (oapiLoadMeshGlobal("merc_adaptcover2"), &OFS_ADAPTCOVER2);
	vessel->AddMesh (oapiLoadMeshGlobal("merc_adaptcover3"), &OFS_ADAPTCOVER3);
	vessel->AddMesh (oapiLoadMeshGlobal("merc_adaptring1"), &OFS_ADAPTRING1);
	vessel->AddMesh (oapiLoadMeshGlobal("merc_adaptring2"), &OFS_ADAPTRING2);
	vessel->AddMesh (oapiLoadMeshGlobal("merc_adaptring3"), &OFS_ADAPTRING3);
};


void AddBooster(VESSEL *vessel)
{
	VECTOR3 mesh_dir;
	mesh_dir=OFS_BOOSTER;
	vessel->AddMesh ("merc_atl_boost", &mesh_dir);
	VECTOR3 m_exhaust_pos;
	VECTOR3 m_exhaust_ref;
	m_exhaust_pos= _V(0,0,-22.6-1.1-1.64);
	m_exhaust_ref = _V(0,0,-1);
	vessel->AddExhaustRef (EXHAUST_MAIN, m_exhaust_pos, 4.0, 0.5, &m_exhaust_ref);
	m_exhaust_pos= _V(-1.5,0,-22.6-1.1-1.64);
	m_exhaust_ref = _V(0,0,-1);
	vessel->AddExhaustRef (EXHAUST_MAIN, m_exhaust_pos, 4.0, 0.5, &m_exhaust_ref);
	m_exhaust_pos= _V(1.5,0,-22.6-1.1-1.64);
	m_exhaust_ref = _V(0,0,-1);
	vessel->AddExhaustRef (EXHAUST_MAIN, m_exhaust_pos, 4.0, 0.5, &m_exhaust_ref);

	m_exhaust_pos= _V(0,0,-17.7-1.1-1.64);
	m_exhaust_ref = _V(0,.866,-.5);
	vessel->AddExhaustRef (EXHAUST_MAIN, m_exhaust_pos, 5.8, 0.075, &m_exhaust_ref);
	m_exhaust_pos= _V(0,0,-17.7-1.1-1.64);
	m_exhaust_ref = _V(0,-.866,-.5);
	vessel->AddExhaustRef (EXHAUST_MAIN, m_exhaust_pos, 5.8, 0.075, &m_exhaust_ref);
};

void AddSubstainer(VESSEL *vessel)
{
	VECTOR3 m_exhaust_pos;
	VECTOR3 m_exhaust_ref;
	m_exhaust_pos= _V(0,0,-22.6-1.1-1.64);
	m_exhaust_ref = _V(0,0,-1);
	vessel->AddExhaustRef (EXHAUST_MAIN, m_exhaust_pos, 4.0, 0.5, &m_exhaust_ref);

	m_exhaust_pos= _V(0,0,-17.7-1.1-1.64);
	m_exhaust_ref = _V(0,.866,-.5);
	vessel->AddExhaustRef (EXHAUST_MAIN, m_exhaust_pos, 5.8, 0.075, &m_exhaust_ref);
	m_exhaust_pos= _V(0,0,-17.7-1.1-1.64);
	m_exhaust_ref = _V(0,-.866,-.5);
	vessel->AddExhaustRef (EXHAUST_MAIN, m_exhaust_pos, 5.8, 0.075, &m_exhaust_ref);

};

class AtlasD:public IStage
{
public:
	AtlasD(Mercury_ControlPanel *Panel);
	void Init ();
	void Exit (VESSEL *vessel);
	void Setup (VESSEL *vessel, double stage_sep_time);
	void ParseLine (VESSEL *vessel, char *line, void *vs);
	void SaveState (VESSEL *vessel, FILEHANDLE scn);
	void Timestep (VESSEL *vessel, double simt);
	void Animate (VESSEL *vessel, double simt);
	void VisualCreated (VESSEL *vessel, VISHANDLE vis, int refcount);
	void VisualDestroyed (VESSEL *vessel, VISHANDLE vis, int refcount);
	int ConsumeKey (VESSEL *vessel, const char *keystate);
	int ConsumeBufferedKey (VESSEL *vessel, DWORD key, bool down, char *kstate);
private:
	void SetAtlasD(VESSEL *vessel);
	void SetSubstainer(VESSEL *vessel);
	void SetNoAbort(VESSEL *vessel);
	void JettisonMercury(VESSEL *vessel);
	void JettisonBooster(VESSEL *vessel);
	bool bCapsuleSeparate;
	bool bBoosterSeparate;
	bool bAbortSeparate;
	bool bInitBoosterJett;
	double last_simt;
	bool bAbort;
	bool doAbort;
	bool bAbortJettisoned;
	bool bBoosterJettisoned;
	bool bAutoPilot;
	bool bThrustCutOff;
	bool bDoAbortJettison;
	bool bDoAbortWarn;
	double ThrustCutOffTime;
	double CapsuleSeparateTime;
	double AbortJettisonTime;
	PROPELLANT_HANDLE main_tank;
	THRUSTER_HANDLE substainer_engine;
	THRUSTER_HANDLE booster_engine[2];
	THRUSTER_HANDLE vernier_engine[2];
	THGROUP_HANDLE main_engine_group;
	THRUSTER_HANDLE sub_main[5];
	THRUSTER_HANDLE booster_main[5];
	Mercury_ControlPanel *ControlPanel;
	double ignition_time;
	double bEngineIgnited;
	enum FStatus {F_LEFT, F_RIGHT} f_status;
	bool bDoCountDown;
	double CountDownTime;
};

AtlasD::AtlasD(Mercury_ControlPanel *Panel)
{
	ControlPanel = Panel;
	Init();
}
void AtlasD::Init ()
{
	fuel_auto = 0;
	fuel_manual = 0;
	bAbortSeparate = false;
	bBoosterSeparate = false;
	bCapsuleSeparate = false;
	bAbort=false;
	doAbort=false;
	ignition_time=0.0;
	last_simt=0;
	bEngineIgnited = false;
	bAbortJettisoned = false;
	bBoosterJettisoned = false;
	bThrustCutOff = false;
	ThrustCutOffTime = 0.0;
	CapsuleSeparateTime = 0.0;
	bDoAbortJettison = false;
	AbortJettisonTime = 0.0;
	bDoAbortWarn = false;
	bInitBoosterJett = false;
	f_status = F_LEFT;
	CountDownTime = 0.0;
	bDoCountDown = false;
	ControlPanel->retro_simt = 16380.0;
	bAutoPilot = true;
	//OutputValue("merc", "aborted", 0.0);
	//RequestLoadVesselWave(SOUND_COUNTDOWN,"Sound\\mercury\\merccountdown.wav");
};
void AtlasD::Exit (VESSEL *vessel)
{
};
void AtlasD::Setup (VESSEL *vessel, double stage_sep_time)
{
	SetAtlasD(vessel);
};
void AtlasD::ParseLine (VESSEL *vessel, char *line, void *vs)
{
	double tempD=0.0;
//	sprintf(oapiDebugString(), "AtlasD parse line");
    if (!_strnicmp (line, "ITIME", 5)) {
        sscanf (line+5, "%lf", &tempD);
		ignition_time=-tempD;
    } else if (!_strnicmp (line, "ENGINE_IGNITED", 14)) {
        sscanf (line+14, "%lf", &tempD);
		if (tempD == 1)
			bEngineIgnited = true;
		else
			bEngineIgnited = false;
    } else if (!_strnicmp (line, "ABORT_JETTISONED", 16)) {
        sscanf (line+16, "%lf", &tempD);
		if (tempD == 1)
			bAbortJettisoned = true;
		else
			bAbortJettisoned = false;
    } else if (!_strnicmp (line, "INIT_BOOSTER_JETT", 17)) {
        sscanf (line+17, "%lf", &tempD);
		if (tempD == 1)
			bInitBoosterJett = true;
		else
			bInitBoosterJett = false;
    } else if (!_strnicmp (line, "BOOSTER_JETTISONED", 18)) {
        sscanf (line+18, "%lf", &tempD);
		if (tempD == 1)
			bBoosterJettisoned = true;
		else
			bBoosterJettisoned = false;
    } else {
        vessel->ParseScenarioLineEx (line, vs);
    }
};

void AtlasD::SaveState (VESSEL *vessel, FILEHANDLE scn)
{
	oapiWriteScenario_int (scn, "CONFIGURATION", 0);
	oapiWriteScenario_float (scn, "ITIME", last_simt-ignition_time);
	oapiWriteScenario_float (scn, "ENGINE_IGNITED", bEngineIgnited);
	oapiWriteScenario_float (scn, "ABORT_JETTISONED", bAbortJettisoned);
	oapiWriteScenario_float (scn, "INIT_BOOSTER_JETT", bInitBoosterJett);
	oapiWriteScenario_float (scn, "BOOSTER_JETTISONED", bBoosterJettisoned);
};

void AtlasD::Timestep (VESSEL *vessel, double simt)
{
	Mercury_Capsule *capsule;
	double airspeed;
	//bAutoPilot = ControlPanel->switch_autopilot;
	bAbortSeparate = ControlPanel->switch_jettisonabort;
	
	if (!bCapsuleSeparate) {
		if (   ControlPanel->switch_capsulesep 
			&& ControlPanel->EmerCapSepFuse == FUSE_TWO
		   ) 
		{
			bCapsuleSeparate = true;
			CapsuleSeparateTime = simt;
			ControlPanel->CapsuleWarn();
		} else if (   ControlPanel->switch_capsulesep 
			       && ControlPanel->EmerCapSepFuse != FUSE_OFF
				   && ControlPanel->Failure != FAIL_CAP_SEP
				  ) 
		{
			bCapsuleSeparate = true;
			CapsuleSeparateTime = simt;
			ControlPanel->CapsuleWarn();
		} else if (   bThrustCutOff 
			       && simt - ThrustCutOffTime > 1.0 
				   && ControlPanel->Failure != FAIL_CAP_SEP
				  )
		{
			bCapsuleSeparate = true;
			CapsuleSeparateTime = simt;
			ControlPanel->CapsuleWarn();
		}
	}
	
	oapiGetAirspeed(vessel->GetHandle(), &airspeed);
	if (!bAutoPilot)
		airspeed = 0;

	if (bCapsuleSeparate && simt - CapsuleSeparateTime > 1.0) {
		ControlPanel->CapsuleSep();
		bCapsuleSeparate=false;
		if (!bAbortJettisoned) {
			JettisonMercury(vessel);
			bAutoPilot = false;
			capsule = new Mercury_Capsule((Mercury_ControlPanel*)((Multi_Stage*)vessel)->GetPanel());
			capsule->Init();
			capsule->bAbortJettisoned=false;
			capsule->MissionType = MISSION_SUBORBITAL;
		} else {
			JettisonMercury(vessel);
			capsule = new Mercury_Capsule((Mercury_ControlPanel*)((Multi_Stage*)vessel)->GetPanel());
			capsule->Init();
			capsule->MissionType = MISSION_ORBITAL;
		}
		((Multi_Stage*)vessel)->SetStage(capsule,simt);
		return;
	}
//		sprintf(oapiDebugString(), "Test: %f %f %f", Orbit->getcurrcosthi(), longitude, radius);

	if (vessel->GetFuelMass() == 0 && !bThrustCutOff) {
		bThrustCutOff = true;
		ThrustCutOffTime = simt;
	} else if (airspeed >= 6210 && !bThrustCutOff) {
		double ap_dist = 0.0;
		orbitelements *Orbit;
		Orbit = new orbitelements;
		Orbit->init(vessel->GetGravityRef(), vessel->GetHandle());
		ap_dist = Orbit->getapodistance();
//		if (simt-ignition_time > (303.8)) {
		if (ap_dist >= 6621000.0) {
			bAutoPilot=false;
			double OrbitTime =0.0;
			double longitude = 0.0;
			double latitude = 0.0;
			double radius = 0.0;
			double tempD = 0.0;
//			double Target = -127.5*RAD;
			double Target = -129.5*RAD;
//			double Target = -135.5*RAD;
//			double Target = -137.5*RAD;
			double Thi = 0;
			double TimeToTarget = 0.0;
			double nOrbits = 3;
			int tempI = 0;
			const double DegPerSec = (15.0*RAD) / 3600.0; // 15 deg/hr divied by 3600 seconds in a hour.
			Orbit->gettimeorbit(&tempI,&OrbitTime,0);
			Thi = acos(Orbit->getcurrcosthi());
			if (Orbit->getcurrsinthi() < 0) 
				Thi = -Thi;

			vessel->GetEquPos(longitude, latitude, radius);
			ControlPanel->retro_simt = 16380;
			if (ControlPanel->CapsuleNumber== 20) {
				//nOrbits = 22;
				//Target = 112*RAD;
				ControlPanel->retro_simt=31800;
				
			}

			if (ControlPanel->CapsuleNumber== 16) {
				//nOrbits = 6;
				//Target = 112*RAD;
				ControlPanel->retro_simt=90240;
				
			}

			tempD = Target - (longitude - (OrbitTime*nOrbits*DegPerSec));
			//tempD = 5*RAD;
			Thi += tempD;
			ControlPanel->startTime = simt - ControlPanel->clock_simt;
			//ControlPanel->retro_simt=OrbitTime * nOrbits + Orbit->GetTimeToThi(cos(Thi),sin(Thi)) + (simt - ControlPanel->clock_simt);
			vessel->SetEngineLevel(ENGINE_MAIN,0.0);
			bThrustCutOff = true;
			ThrustCutOffTime = simt;
		}
	}


	if (!bDoCountDown && !bEngineIgnited) {
		if (ControlPanel->switch_autopilot) {
			CountDownTime = oapiGetSimTime();
			bDoCountDown = true;
			//PlayVesselWave(SOUND_COUNTDOWN);
		}

	}

	if (bDoCountDown && !bEngineIgnited) {
		if (simt - CountDownTime > 295.0) {
			vessel->SetEngineLevel(ENGINE_MAIN, 1.0);
		} else if (simt -CountDownTime > 290.0) {
			vessel->SetEngineLevel(ENGINE_MAIN, 0.01);
		}
		if (!ControlPanel->switch_autopilot) {
			//StopVesselWave(SOUND_COUNTDOWN);
			bDoCountDown = false;
			CountDownTime = 0.0;
		}
		//sprintf(oapiDebugString(),"countdown %f", 295.0-(simt-CountDownTime));
		//sprintf(oapiDebugString(),"countdown %f", (simt-CountDownTime));
	}

	if (vessel->GetEngineLevel(ENGINE_MAIN) > .25) {
			//PlayVesselWave(SOUND_RATTLE, LOOP);
	} else {
		//if (IsPlaying(SOUND_RATTLE))
			//StopVesselWave(SOUND_RATTLE);

	if (!bAbortJettisoned)	{
		if (   (   bDoAbortJettison 
			    && simt-AbortJettisonTime > 20.0 
				&& ControlPanel->Failure !=FAIL_TOWER_JETT
			   ) 
	        || (   ControlPanel->EscapeRcktFuse     != FUSE_OFF 
			    && ControlPanel->TowerSepContrlFuse != FUSE_OFF
				&& ControlPanel->EmerTowerSepFuse   != FUSE_OFF
				&& ControlPanel->switch_jettisonabort
				&& ControlPanel->Failure !=FAIL_TOWER_JETT
			   )
	        || (   ControlPanel->EscapeRcktFuse     == FUSE_TWO 
			    && ControlPanel->TowerSepContrlFuse == FUSE_TWO 
				&& ControlPanel->EmerTowerSepFuse   == FUSE_TWO 
				&& ControlPanel->switch_jettisonabort
			   )
		   ) 
		{
			ControlPanel->AbortJettisoned();
			JettisonTower(vessel);
			SetNoAbort(vessel);
			bAbortJettisoned=true;
			bDoAbortJettison=false;
			//OutputValue("merc", "aborted", 0.0);
		} else if (bDoAbortJettison && simt-AbortJettisonTime > 18.0 && bDoAbortWarn) {
			bDoAbortWarn = false;
			ControlPanel->AbortWarn();
		}
	}

	if (   bAbort 
		|| ControlPanel->Failure == FAIL_ABORT
		|| (   ControlPanel->switch_capsulesep
			&& ControlPanel->EmerCapSepFuse != FUSE_OFF 
			&& ControlPanel->EscapeRcktFuse == FUSE_TWO
		    && (   ControlPanel->Failure != FAIL_CAP_SEP
			    || ControlPanel->EmerCapSepFuse == FUSE_TWO
			   )
		   )
	   )
	{
		vessel->SetEngineLevel(ENGINE_MAIN,0);	
		bAbort = false;
		doAbort = true;
		ControlPanel->Aborted();
	} else if (doAbort)	{
		ControlPanel->CapsuleSep();
		if (bAbortJettisoned) {
			JettisonMercury(vessel);
			bAutoPilot=false;
			capsule = new Mercury_Capsule((Mercury_ControlPanel*)((Multi_Stage*)vessel)->GetPanel());
			capsule->Init();
			//capsule->bSalvoRetros = true;
			capsule->MissionType = MISSION_SUBORBITAL;
			//if (IsPlaying(SOUND_RATTLE))
				//StopVesselWave(SOUND_RATTLE);
			((Multi_Stage*)vessel)->SetStage(capsule,simt);
		} else {
			JettisonMercury(vessel);
			bAutoPilot=false;
			capsule = new Mercury_Capsule((Mercury_ControlPanel*)((Multi_Stage*)vessel)->GetPanel());
			capsule->Init();
			capsule->bAbortJettisoned=false;
			capsule->MissionType = MISSION_SUBORBITAL;
			//if (IsPlaying(SOUND_RATTLE))
				//StopVesselWave(SOUND_RATTLE);
			((Multi_Stage*)vessel)->SetStage(capsule,simt);
		}
		return;
	}
	if (ControlPanel->push_timezero == PUSH_DOWN)
		ControlPanel->StartClock();
	}

	if (bEngineIgnited)	{
		if (!bBoosterJettisoned)
			if ((simt-ignition_time > 131.34 || bBoosterSeparate) && !bInitBoosterJett) {
				AbortJettisonTime = simt;
				bDoAbortJettison = true;
				bDoAbortWarn = true;
				bInitBoosterJett = true;
				vessel->SetEngineLevel(ENGINE_MAIN,0.0);
				vessel->SetThrusterLevel(booster_engine[0], 0.0);
				vessel->SetThrusterLevel(booster_engine[1], 0.0);
				vessel->SetThrusterLevel(substainer_engine, 1.0);
			} else if (simt-ignition_time > 134.34 && bInitBoosterJett) {
				JettisonBooster(vessel);
				SetSubstainer(vessel);
				bBoosterJettisoned = true;
				vessel->SetEngineLevel(ENGINE_MAIN,1.0);
			}
		if (vessel->GetAltitude() > 25.05)
			ControlPanel->StartClock();
	} else {
		if (vessel->GetEngineLevel(ENGINE_MAIN) > .05 && !bEngineIgnited) {
			ignition_time=simt;
			bEngineIgnited=true;
			vessel->SetEngineLevel(ENGINE_MAIN, 1.0);
		};
	};

	if (bAutoPilot  && bEngineIgnited)
		AutoPilot2(vessel, simt-ignition_time, substainer_engine);
	else if (bEngineIgnited) {
		double tempP = 0.0;
		double tempY = 0.0;
		double tempR = 0.0;
		tempP = vessel->GetManualControlLevel(THGROUP_ATT_PITCHDOWN, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE) - vessel->GetManualControlLevel(THGROUP_ATT_PITCHUP, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE);
		tempY = vessel->GetManualControlLevel(THGROUP_ATT_YAWLEFT, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE) - vessel->GetManualControlLevel(THGROUP_ATT_YAWRIGHT, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE);
		tempR = vessel->GetManualControlLevel(THGROUP_ATT_BANKLEFT, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE) - vessel->GetManualControlLevel(THGROUP_ATT_BANKRIGHT, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE);
		vessel->SetThrusterDir(substainer_engine,_V(0.01*tempY,0.01*tempP,1));
		if (!bBoosterJettisoned) {
			vessel->SetThrusterDir(booster_engine[0],_V(0,0.05*tempR,1));
			vessel->SetThrusterDir(booster_engine[1],_V(0,-0.05*tempR,1));
		}
	}
	last_simt=simt;
	if (filter_mesh_number != 0) {
		if (ControlPanel->switch_filter == SWITCH_LEFT && f_status == F_RIGHT) {
			MESHGROUP_TRANSFORM mt;
			mt.nmesh = filter_mesh_number;
			mt.ngrp = -1;
			mt.transform = MESHGROUP_TRANSFORM::TRANSLATE;
			mt.P.transparam.shift.x	=0.0;
			mt.P.transparam.shift.y	=3.5;
			mt.P.transparam.shift.z	= 0.0;
			vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);
			//vessel->SetMeshVisibilityMode(filter_mesh_number, 0);
			//sprintf(oapiDebugString(),"Left");
			f_status = F_LEFT;
		} else if (ControlPanel->switch_filter == SWITCH_RIGHT && f_status == F_LEFT) {
			MESHGROUP_TRANSFORM mt;
			mt.nmesh = filter_mesh_number;
			mt.ngrp = -1;
			mt.transform = MESHGROUP_TRANSFORM::TRANSLATE;
			mt.P.transparam.shift.x	=0.0;
			mt.P.transparam.shift.y	=-3.5;
			mt.P.transparam.shift.z	= 0.0;
			vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);
			//vessel->SetMeshVisibilityMode(filter_mesh_number, MESHVIS_COCKPIT);			
			f_status = F_RIGHT;
			//sprintf(oapiDebugString(),"Right");
		}

		if (f_status == F_RIGHT && ControlPanel->PeriscopePanel == false) {
			MESHGROUP_TRANSFORM mt;
			mt.nmesh = filter_mesh_number;
			mt.ngrp = -1;
			mt.transform = MESHGROUP_TRANSFORM::TRANSLATE;
			mt.P.transparam.shift.x	=0.0;
			mt.P.transparam.shift.y	=3.5;
			mt.P.transparam.shift.z	= 0.0;
			vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);
			//sprintf(oapiDebugString(),"Left");
			//vessel->SetMeshVisibilityMode(filter_mesh_number, 0);
			f_status = F_LEFT;
		}
	}

};
void AtlasD::Animate (VESSEL *vessel, double simt)
{
};
void AtlasD::VisualCreated (VESSEL *vessel, VISHANDLE vis, int refcount)
{
};
void AtlasD::VisualDestroyed (VESSEL *vessel, VISHANDLE vis, int refcount)
{
};
int AtlasD::ConsumeKey (VESSEL *vessel, const char *keystate)
{
	if (KEYMOD_SHIFT (keystate)) 
	{
		return 0; // shift combinations are reserved
	}
	else if (KEYMOD_CONTROL (keystate)) 
	{
		// insert ctrl key combinations here
	}
	else 
	{ // unmodified keys
		if (KEYDOWN (keystate, OAPI_KEY_DIVIDE)) { // "Disable Laterals"
			oapiSetAttitudeMode(vessel->GetHandle(),ATTMODE_ROT);
			return 0;
		}
	}
	return 0;
};

int AtlasD::ConsumeBufferedKey (VESSEL *vessel, DWORD key, bool down, char *kstate)
{
	if (KEYMOD_SHIFT (kstate) && KEYMOD_CONTROL (kstate)) 
	{
		if (key == OAPI_KEY_J) { 
			JettisonTower(vessel);
			return 1;
		}
	}

	if (KEYMOD_SHIFT (kstate)) 
	{

	}
	else if (KEYMOD_CONTROL (kstate)) 
	{
		// insert ctrl key combinations here
	}
	else 
	{ // unmodified keys
		if (key == OAPI_KEY_J) { 
			ControlPanel->switch_capsulesep = true;
			//JettisonTower(vessel);
			return 1;
		}

		if (key == OAPI_KEY_A) { 
			ControlPanel->switch_jettisonabort = true;
			return 1;
		}

		if (key == OAPI_KEY_B) { 
			bBoosterSeparate = true;
			return 1;
		}

		if (key == OAPI_KEY_L) { 

			CountDownTime = oapiGetSimTime();
			//PlayVesselWave(SOUND_COUNTDOWN);
			//PlaySound("Sound\\mercury\\atlascountdown.wav",NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
			bDoCountDown = true;
			ControlPanel->setAutoPilot(bDoCountDown);

			return 1;
		}

		if (key == OAPI_KEY_C) { 
			if (!bEngineIgnited && ControlPanel->TransmitSwitch != SWITCH_MIDDLE)
				//PlayVesselWave(SOUND_COMMCHECK);
			return 1;
		}

		if (key == OAPI_KEY_E) { 
			bAbort = true;
			return 1;
		}
		if (key == OAPI_KEY_1) { 
			//vessel->SetThrusterDir(main_engine,_V(0,.0349,.9994));
			vessel->SetThrusterDir(substainer_engine,_V(0,0.001,1));
			return 1;
		}
		if (key == OAPI_KEY_2) { 
			vessel->SetThrusterDir(substainer_engine,_V(0,0,1));
			return 1;
		}
		if (key == OAPI_KEY_3) { 
			//vessel->SetThrusterDir(main_engine,_V(0,-.0349,.9994));
			vessel->SetThrusterDir(substainer_engine,_V(0,-.001,1));
			return 1;
		}
		if (key == OAPI_KEY_P) // "autoPilot" 
		{
			if (bAutoPilot){
				bAutoPilot = false;
			} else
				bAutoPilot = true;
			//ControlPanel->setAutoPilot(bAutoPilot);
			return 1;			
		}
	}	
	return 0;
};

void AtlasD::SetSubstainer(VESSEL *vessel)
{
	if (bAbortJettisoned)
		vessel->SetEmptyMass   (STAGE1_MASS_EMPTY+MERCURY_MASS);
	else
		vessel->SetEmptyMass   (STAGE1_MASS_EMPTY+MERCURY_MASS-ABORT_MASS);
	vessel->DelExhaust(1);
	vessel->DelExhaust(2);
	vessel->DelThrusterGroup(main_engine_group,THGROUP_MAIN);
	vessel->DelThruster(booster_engine[0]);
	vessel->DelThruster(booster_engine[1]);
	main_engine_group = vessel->CreateThrusterGroup(sub_main,1,THGROUP_MAIN);
	vessel->ClearMeshes();
	if (!bAbortJettisoned) {
		UINT abortmesh = 0;
		abortmesh = AddAbortTower(vessel);
		vessel->SetMeshVisibilityMode(abortmesh, MESHVIS_ALWAYS);
	}
	//vessel->SetCameraOffset(_V(0,.75,-.75));
	AddAntennaHousing(vessel);
	AddCapsule(vessel, ControlPanel->CapsuleNumber);
//	AddChuteHousing(vessel);
	AddAtlas(vessel);
}

void AtlasD::SetNoAbort(VESSEL *vessel)
{
	vessel->SetEmptyMass   (STAGE1_MASS_EMPTY+MERCURY_MASS-ABORT_MASS);
	vessel->ClearMeshes();
	AddAntennaHousing(vessel);
	AddCapsule(vessel, ControlPanel->CapsuleNumber);
//	AddChuteHousing(vessel);
	AddAtlas(vessel);
	if (!bBoosterJettisoned)
		AddBooster(vessel);
}

void AtlasD::SetAtlasD(VESSEL *vessel)
{

/*	PARTICLESTREAMSPEC srb_contrail = {
		0, 1, 1, 50.0, 1, 10, 50, 5, PARTICLESTREAMSPEC::DIFFUSE,
		PARTICLESTREAMSPEC::LVL_PSQRT, 0, 0.5,
		PARTICLESTREAMSPEC::ATM_PLOG, 1.2, 1.25
	};
*/
	THRUSTER_HANDLE steam_trail;
	PARTICLESTREAMSPEC srb_contrail = {
		0, 1, 1, 5.0, 1, 10, 50, 5, PARTICLESTREAMSPEC::DIFFUSE,
		PARTICLESTREAMSPEC::LVL_PSQRT, 0, 0.5,
		PARTICLESTREAMSPEC::ATM_PLOG, 1.2, 1.25
	};


	PARTICLESTREAMSPEC srb_exhaust = {
		0, 0.5, 30, 100.0, 0, 0.1, 30, 0.5, PARTICLESTREAMSPEC::EMISSIVE,
		PARTICLESTREAMSPEC::LVL_PSQRT, 0, 0.5,
		PARTICLESTREAMSPEC::ATM_PLOG, 1e-6, 0.1
	};

	PARTICLESTREAMSPEC atlas_exhaust = {
		0, .65, 5000, 25.0, 0.0, 0.2, -0.5, 0.0, PARTICLESTREAMSPEC::EMISSIVE,
			PARTICLESTREAMSPEC::LVL_PSQRT, 0, 0.1,
		PARTICLESTREAMSPEC::ATM_PLOG, 0, 0
	};

	//srb_exhaust.tex = oapiRegisterParticleTexture ("Contrail_yellow");
	srb_exhaust.tex = oapiRegisterParticleTexture ("Contrail2");
	atlas_exhaust.tex = oapiRegisterParticleTexture ("Contrail3");
	srb_contrail.tex = oapiRegisterParticleTexture ("contrail1");
	SURFHANDLE tex = oapiRegisterExhaustTexture ("Exhaust2");
// ==============================================================
	vessel->SetSize        (11.0+0.82+1.2+1.9);
	vessel->SetCOG_elev    (11.0+0.82+1.2);
	if (!bBoosterJettisoned)
		vessel->SetEmptyMass   (STAGE1_MASS_EMPTY+BOOSTER_MASS_EMPTY+MERCURY_MASS);
	else
		if (bAbortJettisoned)
			vessel->SetEmptyMass   (STAGE1_MASS_EMPTY+MERCURY_MASS-ABORT_MASS);
		else
			vessel->SetEmptyMass   (STAGE1_MASS_EMPTY+MERCURY_MASS);
// ==============================================================
// This is from the altanis launch config and is what makes the V-2 launch vertically
// The Z values you use to set the rocket up into the air and align with the height of 
// your launch platform. In this case the Pad 39A.
	vessel->SetTouchdownPoints (_V(0,-1.0,OFS_ATLAS.z-11.0), _V(-.7,.7,OFS_ATLAS.z-11.0), _V(.7,.7,OFS_ATLAS.z-11.0));
// ==============================================================
// This from running the mesh through the shipedit program
	vessel->SetPMI (_V(39.7,39.7,1.45));
	vessel->SetCrossSections (_V(80.15,85.27,10.89));
// ==============================================================
// This is based off of the SRB and Main Shuttle Tank as 
// they are the nearest thing to V-2 that I have stats for.
//	vessel->SetCW (0.1, 0.3, MERC_DRAG, MERC_DRAG);
	vessel->SetCW (0.075, 0.3, MERC_DRAG, MERC_DRAG);
	vessel->SetRotDrag (_V(0.7,0.7,1.2));
	vessel->SetPitchMomentScale (0);
	vessel->SetBankMomentScale (0);
	vessel->SetLiftCoeffFunc (0); 
// ==============================================================
	vessel->ClearMeshes();
	vessel->ClearPropellantResources();
	vessel->ClearThrusterDefinitions();


	if (!bAbortJettisoned) {
		UINT abortmesh = 0;
		abortmesh = AddAbortTower(vessel);
		vessel->SetMeshVisibilityMode(abortmesh, MESHVIS_ALWAYS);
	}
	//vessel->SetCameraOffset(_V(0,.75,-.75));
	AddAntennaHousing(vessel);
	AddCapsule(vessel, ControlPanel->CapsuleNumber);
//	AddChuteHousing(vessel);
	AddAtlas(vessel);
	if (!bBoosterJettisoned)
		AddBooster(vessel);

	main_tank = vessel->CreatePropellantResource(STAGE1_MASS_FUEL);
	substainer_engine = vessel->CreateThruster(SUBSTAINER_OFS_FLAME, SUBSTAINER_FLAME_DIR, SUBSTAINER_THRUST_VAC, main_tank, SUBSTAINER_ISP_VAC, SUBSTAINER_ISP_SL);
	vernier_engine[0] = vessel->CreateThruster(SUBSTAINER_OFS_FLAME, SUBSTAINER_FLAME_DIR, VERNIER_THRUST_VAC, main_tank, VERNIER_ISP_VAC, VERNIER_ISP_SL);
	vernier_engine[1] = vessel->CreateThruster(SUBSTAINER_OFS_FLAME, SUBSTAINER_FLAME_DIR, VERNIER_THRUST_VAC, main_tank, VERNIER_ISP_VAC, VERNIER_ISP_SL);
	steam_trail = vessel->CreateThruster(SUBSTAINER_OFS_FLAME, _V(0,1,0), 0.00001, main_tank, SUBSTAINER_ISP_VAC*1000, SUBSTAINER_ISP_VAC*1000);
	sub_main[0] = substainer_engine;
	sub_main[1] = vernier_engine[0];
	sub_main[2] = vernier_engine[1];
	if (bBoosterJettisoned) {
		main_engine_group = vessel->CreateThrusterGroup(sub_main,3,THGROUP_MAIN);
		vessel->AddExhaust(substainer_engine,4.0,0.5);
	} else {
		booster_engine[0] = vessel->CreateThruster(BOOSTER1_OFS_FLAME, BOOSTER_FLAME_DIR, BOOSTER_THRUST_VAC, main_tank, BOOSTER_ISP_VAC, BOOSTER_ISP_SL);
		booster_engine[1] = vessel->CreateThruster(BOOSTER2_OFS_FLAME, BOOSTER_FLAME_DIR, BOOSTER_THRUST_VAC, main_tank, BOOSTER_ISP_VAC, BOOSTER_ISP_SL);
		booster_main[0] = substainer_engine;
		booster_main[1] = booster_engine[0];
		booster_main[2] = booster_engine[1];
		booster_main[3] = vernier_engine[0];
		booster_main[4] = vernier_engine[1];
		VECTOR3 exhaust_dir = _V(0,1,0);
		main_engine_group = vessel->CreateThrusterGroup(booster_main,5,THGROUP_MAIN);
		//vessel->AddExhaust(substainer_engine,4.0,0.5, tex);
		//vessel->AddExhaust(booster_main[1]  ,4.0,0.5, tex);
		//vessel->AddExhaust(booster_main[2]  ,4.0,0.5, tex);
		vessel->AddExhaustStream(substainer_engine, &atlas_exhaust);
		vessel->AddExhaustStream(substainer_engine, &srb_exhaust);
		vessel->AddExhaustStream(booster_main[1], &atlas_exhaust);
		vessel->AddExhaustStream(booster_main[1], &srb_exhaust);
		vessel->AddExhaustStream(booster_main[1], &srb_contrail);
		vessel->AddExhaustStream(booster_main[2], &atlas_exhaust);
		vessel->AddExhaustStream(booster_main[2], &srb_exhaust);
		vessel->AddExhaustStream(booster_main[2], &srb_contrail);
	}
};


void AtlasD::JettisonMercury(VESSEL *vessel)
{

	VESSELSTATUS vs;
	VECTOR3 ofs = _V(0,0,0);
	VECTOR3 vel = _V(0,0,0);
	char name[256];
	//PlayVesselWave(SOUND_MERCSEP);
	vessel->GetStatus (vs);

	vs.vrot.x = 0.0;
	vs.vrot.y = 0.0;
	vs.vrot.z = 0.0;


	if (!bBoosterJettisoned) {
		ofs = OFS_BOOSTER;
		vel = _V(0,0,-0.5);
		vs.eng_main = vs.eng_hovr = 0.0;
		vessel->SetEngineLevel(ENGINE_MAIN, 0);
		StageTransform(vessel,&vs,ofs,vel);
		strcpy (name, vessel->GetName()); strcat (name, "-Booster");
		VESSEL::Create (name, "Mercury_Atlas_Booster", vs);
	}

	ofs = OFS_ATLAS;
	vel = _V(0,0,0);
	vs.eng_main = vs.eng_hovr = 0.0;
	vessel->SetEngineLevel(ENGINE_MAIN, 0);
	StageTransform(vessel,&vs,ofs,vel);
	strcpy (name, vessel->GetName()); strcat (name, "-Atlas");
	VESSEL::Create (name, "Mercury_Atlas_Main", vs);

	ofs = OFS_ADAPTER;
	vel = _V(0,0,0);
	vs.eng_main = vs.eng_hovr = 0.0;
	vessel->SetEngineLevel(ENGINE_MAIN, 0);
	StageTransform(vessel,&vs,ofs,vel);
	strcpy (name, vessel->GetName()); strcat (name, "-Adapter");
	VESSEL::Create (name, "Mercury_Atlas_Adapter", vs);

	vel = _V(0,.95,0);
	vessel->GetStatus (vs);
	vs.eng_main = vs.eng_hovr = 0.0;
	ofs = OFS_ADAPTCOVER1;
	StageTransform(vessel,&vs,ofs,vel);
	strcpy (name, vessel->GetName()); strcat (name, "-AdaptCover1");
	VESSEL::Create (name, "Mercury_AdaptCover1", vs);

	vel = _V(-0.823,-0.475,0);
	vessel->GetStatus (vs);
	ofs = OFS_ADAPTCOVER2;		
	vel = _V(-0.823,-0.475,0);	
	StageTransform(vessel,&vs,ofs,vel);
	strcpy (name, vessel->GetName()); strcat (name, "-AdaptCover2");
	VESSEL::Create (name, "Mercury_AdaptCover2", vs);

	vel = _V(0.823,-0.475,0);
	vessel->GetStatus (vs);
	vs.eng_main = vs.eng_hovr = 0.0;
	ofs = OFS_ADAPTCOVER3;
	StageTransform(vessel,&vs,ofs,vel);
	strcpy (name, vessel->GetName()); strcat (name, "-AdaptCover3");
	VESSEL::Create (name, "Mercury_AdaptCover3", vs);

	vel = _V(-0.823,0.475,0);
	vessel->GetStatus (vs);
	vs.eng_main = vs.eng_hovr = 0.0;
	ofs = OFS_ADAPTRING1;
	StageTransform(vessel,&vs,ofs,vel);
	strcpy (name, vessel->GetName()); strcat (name, "-AdaptRing1");
	VESSEL::Create (name, "Mercury_AdaptRing1", vs);

	vel = _V(0.0,-0.95,0);
	vessel->GetStatus (vs);
	vs.eng_main = vs.eng_hovr = 0.0;
	ofs = OFS_ADAPTRING2;
	StageTransform(vessel,&vs,ofs,vel);
	strcpy (name, vessel->GetName()); strcat (name, "-AdaptRing2");
	VESSEL::Create (name, "Mercury_AdaptRing2", vs);

	vel = _V(0.823,0.475,0);
	vessel->GetStatus (vs);
	vs.eng_main = vs.eng_hovr = 0.0;
	ofs = OFS_ADAPTRING3;	
	StageTransform(vessel,&vs,ofs,vel);
	strcpy (name, vessel->GetName()); strcat (name, "-AdaptRing3");
	VESSEL::Create (name, "Mercury_AdaptRing3", vs);
};

void AtlasD::JettisonBooster(VESSEL *vessel)
{
	VESSELSTATUS vs;
	VECTOR3 ofs = _V(0,0,0);
	VECTOR3 vel = _V(0,0,-0.5);
	//PlayVesselWave(SOUND_STAGESEP);
	ofs = OFS_BOOSTER;
	vel = _V(0,0,-0.5);
	vessel->GetStatus (vs);
	vs.eng_main = vs.eng_hovr = 0.0;
	vessel->SetEngineLevel(ENGINE_MAIN, 0);
	StageTransform(vessel,&vs,ofs,vel);
	vs.vrot.x = 0.0;
	vs.vrot.y = 0.0;
	vs.vrot.z = 0.0;
	char name[256];
	strcpy (name, vessel->GetName()); strcat (name, "-Booster");
	VESSEL::Create (name, "Mercury_Atlas_Booster", vs);
};

#endif 
