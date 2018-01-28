#ifndef __REDSTONE_H
#define __REDSTONE_H

#include "orbitersdk.h"
#include "multi_stage5.h"
#include "mercury_capsule.h"
//#include "OrbiterSoundSDK.h"

const VECTOR3 OFS_RED = {0.0, 0.0, -9.76};
const VECTOR3 OFS_ADAPTRING1 = {-0.61, 0.35,  -0.93};
const VECTOR3 OFS_ADAPTRING2 = {0.0, -0.82,  -0.93};
const VECTOR3 OFS_ADAPTRING3 = {0.61, 0.35,  -0.93};
const VECTOR3 OFS_ADAPTCOVER1 = {0.0, 0.91, -0.9};
const VECTOR3 OFS_ADAPTCOVER2 = {-0.74, -0.43,  -0.9};
const VECTOR3 OFS_ADAPTCOVER3 = {0.74, -0.43,  -0.9};

const double  STAGE1_LENGTH      = 18.2;
const VECTOR3 STAGE1_OFS         = { 0.0     , 0.0     , MERCURY_OFS_CAPSULE.z-MERCURY_LENGTH_CAPSULE / 2 - STAGE1_LENGTH / 2};
const VECTOR3 STAGE1_OFS_FLAME   = { 0.0     , 0.0     , STAGE1_OFS.z-STAGE1_LENGTH/2};
const VECTOR3 STAGE1_FLAME_DIR   = { 0.0     , 0.0     , 1.0};
const double  STAGE1_MASS        = 28440*KG;
const double  STAGE1_MASS_EMPTY  = 3125*KG;
const double  STAGE1_MASS_FUEL   = STAGE1_MASS-STAGE1_MASS_EMPTY;
const double  STAGE1_ISP_SL      = 235*SEC;
const double  STAGE1_ISP_VAC     = 265*SEC;
const double  STAGE1_THRUST_VAC  = 42251*KGF;



#define N	19	// flight plan table size

void AddRedstone(VESSEL *vessel)
{
	vessel->AddMesh (oapiLoadMeshGlobal("merc_redstone"), &STAGE1_OFS);
	vessel->AddMesh (oapiLoadMeshGlobal("merc_adaptcover1"), &OFS_ADAPTCOVER1);
	vessel->AddMesh (oapiLoadMeshGlobal("merc_adaptcover2"), &OFS_ADAPTCOVER2);
	vessel->AddMesh (oapiLoadMeshGlobal("merc_adaptcover3"), &OFS_ADAPTCOVER3);
	vessel->AddMesh (oapiLoadMeshGlobal("merc_adaptring1"), &OFS_ADAPTRING1);
	vessel->AddMesh (oapiLoadMeshGlobal("merc_adaptring2"), &OFS_ADAPTRING2);
	vessel->AddMesh (oapiLoadMeshGlobal("merc_adaptring3"), &OFS_ADAPTRING3);
};

void JettisonMercury(VESSEL *vessel)
{
	//PlayVesselWave(SOUND_MERCSEP);
	vessel->SetAttitudeRotLevel(0, 0);
	VESSELSTATUS vs;
	VECTOR3 ofs = _V(OFS_RED.x,OFS_RED.y,OFS_RED.z-0.5);
	VECTOR3 vel = _V(0,0,0);
	vessel->GetStatus (vs);
	vs.eng_main = vs.eng_hovr = 0.0;
	vessel->SetEngineLevel(ENGINE_MAIN, 0);
	StageTransform(vessel,&vs,ofs,vel);
	vs.vrot.x = 0.0;
	vs.vrot.y = 0.0;
	vs.vrot.z = 0.0;
	char name[256];
	strcpy (name, vessel->GetName()); strcat (name, "-Redstone");
	VESSEL::Create (name, "Mercury_RedstoneBooster", vs);

	vel = _V(0,.95,0);
	vessel->GetStatus (vs);
	vs.eng_main = vs.eng_hovr = 0.0;
	ofs = OFS_ADAPTCOVER1;
	StageTransform(vessel,&vs,ofs,vel);
	strcpy (name, vessel->GetName()); strcat (name, "-AdaptCover1");
	VESSEL::Create (name, "Mercury_AdaptCover1", vs);

	vel = _V(-0.823,-0.475,0);
	vessel->GetStatus (vs);
	vs.eng_main = vs.eng_hovr = 0.0;
	ofs = OFS_ADAPTCOVER2;	
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


class Redstone:public IStage
{
public:
	Redstone(Mercury_ControlPanel *Panel);
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
	void SetRedstone(VESSEL *vessel);
	void SetRedstoneNoAbort(VESSEL *vessel);
	bool bAbortJettisoned;
	bool bAbortSeparate;
	bool bCapsuleSeparate;
	bool bAbort;
	bool doAbort;
	bool bEngineIgnited;
	bool bAutoPilot;
	double ignition_time;
	double LaunchHeading;
	double last_simt;
	bool bThrustCutOff;
	double ThrustCutOffTime;
	double CapsuleSeparateTime;
	void TEST_HANDLE();
	void AutoPilot(VESSEL *vessel, double t);
	double GetCPitch(double t);
	PROPELLANT_HANDLE main_tank;
	THRUSTER_HANDLE main_engine;
	THGROUP_HANDLE main_engine_group;
	THRUSTER_HANDLE th_main[1];
	Mercury_ControlPanel *ControlPanel;
	enum FStatus {F_LEFT, F_RIGHT} f_status;
	double met[N] ;   
	double cpitch[N];	
	int first_time;
	int out_level;
	double last_time;
	double total_off;
};

/*
double Redstone::GetCPitch(double t)
{
	int i;
	if (t>met[N-1]) return cpitch[N-1];
	i=1;
	while (met[i]<t) i++;
	return cpitch[i-1]+(cpitch[i]-cpitch[i-1])/(met[i]-met[i-1])*(t-met[i-1]);
}
*/

double Redstone::GetCPitch(double t)
{
	int i;
	if (t>met[N-1]) return cpitch[N-1];
	i=1;
	while (met[i]<t) i++;
	return cpitch[i];
}

void Redstone::AutoPilot(VESSEL *vessel, double t)
{

	double level=0.;
	double pitch;
	double pitch_c;
	char current_key=0;
	VECTOR3 ang_vel;
	double drop_vel = 0.0;
	double tempD = 0.0;
//	VECTOR3 ang_vel;
 // suggestion : you could also check here for minimum eccentricity with the new API
 // and cut off when reached.

	// navigation
	oapiGetFocusPitch(&pitch);
	pitch=pitch*180./PI;
//	vessel->GetAngularVel(ang_vel);

 // guidance
	pitch_c=GetCPitch(t);
	vessel->GetAngularVel(ang_vel);

 // control
	if (t<24.)
	{
		vessel->SetThrusterDir(main_engine,_V(0,0,1));
	} else {
		level = pitch_c - pitch;
		if (level>.1) 
			drop_vel = .67*RAD;
		else if (level<-0.1) 
			drop_vel = -.67*RAD;
		else 
			drop_vel = 0*RAD;
		
		if (ang_vel.x > drop_vel+.0005 ) 
			tempD = 0.00075;
		else if (ang_vel.x < drop_vel - .0005)
			tempD = -0.00075;
		
		vessel->SetThrusterDir(main_engine,_V(0,tempD,1));


	}

}

Redstone::Redstone(Mercury_ControlPanel *Panel)
{
	ControlPanel = Panel;
	ControlPanel->retro_simt = 285.0;
	Init();
}

void Redstone::Init ()
{
	fuel_auto = 0;
	fuel_manual = 0;
	bAbortJettisoned=false;
	bCapsuleSeparate = false;
	bAbortSeparate = false;
	bAbort=false;
	doAbort=false;
	ignition_time = 0.0;
	bEngineIgnited = false;
	bAutoPilot = true;
	last_simt = 0.0;
	bThrustCutOff = false;
	ThrustCutOffTime = 0.0;
	CapsuleSeparateTime = 0.0;
	f_status = F_LEFT;
	ControlPanel->CountDownTime = 0.0;
	ControlPanel->bDoCountDown = false;
	//OutputValue("merc", "aborted", 0.0);
//	RequestLoadVesselWave(SOUND_COUNTDOWN,"Sound\\mercury\\merccountdown.wav");
	met[0] = 0;   // MET in sec
	met[1] = 24;
	met[2] = 30;
	met[3] = 35;
	met[4] = 40;
	met[5] = 45;
	met[6] = 50;
	met[7] = 55;
	met[8] = 60;
	met[9] = 68;
	met[10] = 76;
	met[11] = 84;
	met[12] = 92;
	met[13] = 100;
	met[14] = 110;
	met[15] = 116;
	met[16] = 122;
	met[17] = 132;
	met[18] = 142.5;
	cpitch[0] = 90;// Commanded pitch in �
	cpitch[1] = 89;
	cpitch[2] = 88;
	cpitch[3] = 87;
	cpitch[4] = 86;
	cpitch[5] = 84;
	cpitch[6] = 82;
	cpitch[7] = 80;
	cpitch[8] = 76;	
	cpitch[9] = 72;	
	cpitch[10] = 68;	
	cpitch[11] = 64;	
	cpitch[12] = 60;	
	cpitch[13] = 56;	
	cpitch[14] = 54;	
	cpitch[15] = 52;	
	cpitch[16] = 50;	
	cpitch[17] = 49;	
	cpitch[18] = 49;	
	first_time=1;
	out_level=0;
	last_time=0.0;
	total_off=0.0;
};

void Redstone::Exit (VESSEL *vessel)
{
};

void Redstone::Setup (VESSEL *vessel, double stage_sep_time)
{
	SetRedstone(vessel);
};

void Redstone::ParseLine (VESSEL *vessel, char *line, void *vs)
{
	double tempD=0.0;
    if (!_strnicmp (line, "ABORT_JETT", 10)) {
        sscanf (line+10, "%lf", &tempD);
		if (tempD == 1)
		{
			bAbortJettisoned=true;
			SetRedstoneNoAbort(vessel);
		};
    } else if (!_strnicmp (line, "ITIME", 5)) {
        sscanf (line+5, "%lf", &tempD);
		ignition_time=-tempD;
    } else if (!_strnicmp (line, "ENGINE_IGNITED", 14)) {
        sscanf (line+14, "%lf", &tempD);
		if (tempD == 1)
		{
			bEngineIgnited = true;
		}
    } else {
        vessel->ParseScenarioLineEx (line, vs);
    }

};
void Redstone::SaveState (VESSEL *vessel, FILEHANDLE scn)
{
	oapiWriteScenario_int (scn, "CONFIGURATION", 0);
	oapiWriteScenario_float (scn, "ABORT_JETT", bAbortJettisoned);	
	oapiWriteScenario_float (scn, "ITIME", last_simt-ignition_time);
	oapiWriteScenario_float (scn, "ENGINE_IGNITED", bEngineIgnited);
};

void Redstone::Timestep (VESSEL *vessel, double simt)
{
	Mercury_Capsule *capsule;
	double tempD;

	//bAutoPilot = ControlPanel->switch_autopilot;

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
			       && simt - ThrustCutOffTime > 10.0 
				   && ControlPanel->Failure != FAIL_CAP_SEP
				  )
		{
			bCapsuleSeparate = true;
			CapsuleSeparateTime = simt;
			ControlPanel->CapsuleWarn();
		}
	}

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
			capsule->MissionType = MISSION_SUBORBITAL;
		}
		((Multi_Stage*)vessel)->SetStage(capsule,simt);
		return;
	}

	if (((simt-ignition_time) > 142.5 || vessel->GetFuelMass() == 0) && !bThrustCutOff && bEngineIgnited) {
		bThrustCutOff = true;
		vessel->SetThrusterLevel(main_engine, 0.0);
		ThrustCutOffTime = simt;
		ControlPanel->AbortWarn();
	}



	if (!bAbortJettisoned)
	{
		if (   (   bThrustCutOff 
			    && simt - ThrustCutOffTime > 2.0 
				&& ControlPanel->Failure != FAIL_TOWER_JETT
			   )
			|| (
			       ControlPanel->switch_jettisonabort 
				&& ControlPanel->EscapeRcktFuse == FUSE_TWO
				&& ControlPanel->TowerSepContrlFuse == FUSE_TWO
				&& ControlPanel->EmerTowerSepFuse == FUSE_TWO
			   )
			
			|| (
			       ControlPanel->switch_jettisonabort 
				&& ControlPanel->EscapeRcktFuse != FUSE_OFF
				&& ControlPanel->TowerSepContrlFuse != FUSE_OFF
				&& ControlPanel->EmerTowerSepFuse != FUSE_OFF
				&& ControlPanel->Failure != FAIL_TOWER_JETT
			   )
	       ) 
		{
			JettisonTower(vessel);
			SetRedstoneNoAbort(vessel);
			bAbortSeparate=false;
			bAbortJettisoned=true;
			ControlPanel->AbortJettisoned();
			//OutputValue("merc", "aborted", 1.0);
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
		ControlPanel->CapsuleWarn();
		//OutputValue("merc", "aborted", 1.0);
	} else if (
		         (   doAbort 
				  && ControlPanel->Failure != FAIL_ABORT_CAP_SEP
				 ) 
		      || (
			         ControlPanel->EmerCapSepFuse == FUSE_TWO 
				  && ControlPanel->EscapeRcktFuse == FUSE_TWO
				  && ControlPanel->switch_capsulesep
				 )
			  )
	{
		ControlPanel->Aborted();
		ControlPanel->CapsuleSep();
		if (bAbortJettisoned) {
			JettisonMercury(vessel);
			bAutoPilot = false;
			capsule = new Mercury_Capsule((Mercury_ControlPanel*)((Multi_Stage*)vessel)->GetPanel());
			capsule->Init();
			capsule->bSalvoRetros = true;
			capsule->MissionType = MISSION_SUBORBITAL;
			((Multi_Stage*)vessel)->SetStage(capsule,simt);
		} else {
			JettisonMercury(vessel);
			bAutoPilot = false;
			capsule = new Mercury_Capsule((Mercury_ControlPanel*)((Multi_Stage*)vessel)->GetPanel());
			capsule->Init();
			capsule->bAbortJettisoned=false;
			capsule->MissionType = MISSION_SUBORBITAL;
			((Multi_Stage*)vessel)->SetStage(capsule,simt);
		}
		return;
	}

	if (vessel->GetEngineLevel(ENGINE_MAIN) > .25) {
			//PlayVesselWave(SOUND_RATTLE, LOOP);
	} else {
		//if (IsPlaying(SOUND_RATTLE))
			//StopVesselWave(SOUND_RATTLE);
	}


	if (vessel->GetEngineLevel(ENGINE_MAIN) > .05 && !bEngineIgnited)
	{
		vessel->SetThrusterLevel(main_engine, 1.0);
		ignition_time = simt;
		bEngineIgnited = true;
		oapiGetFocusHeading(&LaunchHeading);
		LaunchHeading=(LaunchHeading/(2*PI))*360;
		ControlPanel->StartClock();
	}

	if (bAutoPilot  && bEngineIgnited)
		AutoPilot(vessel, simt-ignition_time);
	else {
		tempD = vessel->GetManualControlLevel(THGROUP_ATT_PITCHDOWN, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE) - vessel->GetManualControlLevel(THGROUP_ATT_PITCHUP, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE);
		vessel->SetThrusterDir(main_engine,_V(0,0.002*tempD,1));
	}

	if (!ControlPanel->bDoCountDown && !bEngineIgnited) {
		if (ControlPanel->switch_autopilot) {
			ControlPanel->CountDownTime = oapiGetSimTime();
			ControlPanel->bDoCountDown = true;
			//PlayVesselWave(SOUND_COUNTDOWN);
		}

	}


	if (ControlPanel->bDoCountDown && !bEngineIgnited) {
		if (simt - ControlPanel->CountDownTime > 293.0) {
			vessel->SetThrusterLevel(main_engine,1.0);
		} else if (simt - ControlPanel->CountDownTime > 291.0) {
			vessel->SetThrusterLevel(main_engine,.01);
		}
		if (!ControlPanel->switch_autopilot) {
			//StopVesselWave(SOUND_COUNTDOWN);
			ControlPanel->bDoCountDown = false;
			ControlPanel->CountDownTime = 0.0;
		}
		//sprintf(oapiDebugString(),"countdown %f", simt-ControlPanel->CountDownTime);
	}

		
	last_simt = simt;

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
			f_status = F_RIGHT;
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
			f_status = F_LEFT;
		}
	}
	/*if (GetValue("merc", "cabort") == 1.0) {
		OutputValue("merc", "cabort", 0.0);
		bAbort = true;
	}*/


};



void Redstone::Animate (VESSEL *vessel, double simt)
{
};
void Redstone::VisualCreated (VESSEL *vessel, VISHANDLE vis, int refcount)
{
};
void Redstone::VisualDestroyed (VESSEL *vessel, VISHANDLE vis, int refcount)
{
};
int Redstone::ConsumeKey (VESSEL *vessel, const char *keystate)
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

int Redstone::ConsumeBufferedKey (VESSEL *vessel, DWORD key, bool down, char *kstate)
{
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
			return 1;
		}

		if (key == OAPI_KEY_A) { 
			ControlPanel->switch_jettisonabort = true;
			return 1;
		}

		if (key == OAPI_KEY_L) { 
			ControlPanel->CountDownTime = oapiGetSimTime();
			//PlayVesselWave(SOUND_COUNTDOWN);
			ControlPanel->bDoCountDown = true;
			ControlPanel->setAutoPilot(ControlPanel->bDoCountDown);
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
		if (key == OAPI_KEY_P) // "autoPilot" 
		{
			if (bAutoPilot){
				bAutoPilot = false;
			} else
				bAutoPilot = true;
			ControlPanel->setAutoPilot(bAutoPilot);
			return 1;			
		}
		if (key == OAPI_KEY_Q) { 
			sprintf(oapiDebugString(),"fmode %d", ControlPanel->Failure);
		}
	}	
	return 0;
};

void Redstone::SetRedstone(VESSEL *vessel)
{
	PARTICLESTREAMSPEC red_ground = {
		0, 8.0, 5, 150, 0.3, 4.0, 4, 3.0, PARTICLESTREAMSPEC::DIFFUSE,
		PARTICLESTREAMSPEC::LVL_SQRT, 0, 1,
		PARTICLESTREAMSPEC::ATM_PLOG, 1e-4, 1
	};
/*	PARTICLESTREAMSPEC exhaust_main = {
		0, 2.0, 20, 150, 0.1, 0.2, 16, 1.0, PARTICLESTREAMSPEC::EMISSIVE,
		PARTICLESTREAMSPEC::LVL_SQRT, 0, 1,
		PARTICLESTREAMSPEC::ATM_PLOG, 1e-5, 0.1
	};
	
	PARTICLESTREAMSPEC red_contrail = {
		0, 2.0, 5, 150, 0.3, 1.0, 4, 3.0, PARTICLESTREAMSPEC::DIFFUSE,
		PARTICLESTREAMSPEC::LVL_SQRT, 0, 1,
		PARTICLESTREAMSPEC::ATM_PLOG, 1e-4, 1
	};



	PARTICLESTREAMSPEC srb_exhaust = {
		0, 0.1, 120, 50.0, 0, 0.05, 10, 0.5, PARTICLESTREAMSPEC::EMISSIVE,
		PARTICLESTREAMSPEC::LVL_PSQRT, 0, 0.5,
		PARTICLESTREAMSPEC::ATM_PLOG, 1e-6, 0.1
	};
	*/

	PARTICLESTREAMSPEC red_contrail = {
		0, 1, 5, 5.0, 0, 1, 50, 5, PARTICLESTREAMSPEC::DIFFUSE,
		PARTICLESTREAMSPEC::LVL_PSQRT, 0, 0.5,
		PARTICLESTREAMSPEC::ATM_PLOG, 1.22, 1.25
	};

	PARTICLESTREAMSPEC red_exhaust = {
		0, .65, 5000, 25.0, 0, 0.2, -1, 0.0, PARTICLESTREAMSPEC::EMISSIVE,
		PARTICLESTREAMSPEC::LVL_PSQRT, 0, 0.5,
		PARTICLESTREAMSPEC::ATM_PLOG, 1e-6, 0.1
	};
//	srb_exhaust.tex = oapiRegisterParticleTexture ("Contrail1");
	red_exhaust.tex = oapiRegisterParticleTexture ("Contrail2");

// ==============================================================
	vessel->SetSize ((MERCURY_LENGTH_CAPSULE + STAGE1_LENGTH) / 2);
	//vessel->SetCOG_elev (MERCURY_LENGTH_CAPSULE / 2 + STAGE1_LENGTH / 2);
	vessel->SetCOG_elev(-STAGE1_LENGTH);
	vessel->SetEmptyMass (MERCURY_MASS + STAGE1_MASS_EMPTY );
	vessel->SetMaxThrust (ENGINE_ATTITUDE, 5e3);
// ==============================================================
// This is from the altanis launch config and is what makes the V-2 launch vertically
// The Z values you use to set the rocket up into the air and align with the height of 
// your launch platform. In this case the Pad 39A.
	vessel->SetTouchdownPoints (_V(0,-1.0,STAGE1_OFS.z-8.2), _V(-.7,.7,STAGE1_OFS.z-8.2), _V(.7,.7,STAGE1_OFS.z-8.2));
// ==============================================================
// This from running the mesh through the shipedit program
	vessel->SetPMI (_V(33.0,33.0,0.51));
	vessel->SetCrossSections (_V(38.4,38.4,4.04));
// ==============================================================
// This is based off of the SRB and Main Shuttle Tank as 
// they are the nearest thing to V-2 that I have stats for.
	vessel->SetCW (1.0, .1, .3, .3);
	vessel->SetRotDrag (_V(0.7,0.7,1.2));
	vessel->SetPitchMomentScale (0);
	vessel->SetBankMomentScale (0);
	vessel->SetLiftCoeffFunc (0); 
// ==============================================================
	vessel->ClearMeshes();
	vessel->ClearExhaustRefs();
	vessel->ClearAttExhaustRefs();
	vessel->ClearPropellantResources();
	vessel->ClearThrusterDefinitions();
	UINT abortmesh = 0;
	abortmesh = AddAbortTower(vessel);
	vessel->SetMeshVisibilityMode(abortmesh, MESHVIS_ALWAYS);
	vessel->SetCameraOffset(_V(0,.75,-.75));
	AddCapsule(vessel, ControlPanel->CapsuleNumber);
	AddAntennaHousing(vessel);
	AddRedstone(vessel);
	main_tank = vessel->CreatePropellantResource(STAGE1_MASS_FUEL);
	main_engine = vessel->CreateThruster(STAGE1_OFS_FLAME, STAGE1_FLAME_DIR, STAGE1_THRUST_VAC, main_tank, STAGE1_ISP_VAC, STAGE1_ISP_SL);
	th_main[0] = main_engine;
	main_engine_group = vessel->CreateThrusterGroup(th_main,1,THGROUP_MAIN);
	//vessel->AddExhaust(main_engine,4.0,0.5);
	vessel->AddExhaustStream (th_main[0], STAGE1_OFS_FLAME, &red_contrail);
	vessel->AddExhaustStream (th_main[0], STAGE1_OFS_FLAME, &red_exhaust);
	//vessel->AddExhaustStream (th_main[0], STAGE1_OFS_FLAME, &red_ground);
};

void Redstone::SetRedstoneNoAbort(VESSEL *vessel)
{
	double cur_mass = vessel->GetPropellantMass(main_tank);
// ==============================================================
	vessel->SetSize ((MERCURY_LENGTH_CAPSULE+STAGE1_LENGTH) / 2);
	vessel->SetCOG_elev(-STAGE1_LENGTH);
	vessel->SetEmptyMass (MERCURY_MASS + STAGE1_MASS_EMPTY - ABORT_MASS);
// ==============================================================
// This is from the altanis launch config and is what makes the V-2 launch vertically
// The Z values you use to set the rocket up into the air and align with the height of 
// your launch platform. In this case the Pad 39A.
	vessel->SetTouchdownPoints (_V(0,-1.0,-2.5), _V(-.7,.7,-2.5), _V(.7,.7,-2.5));
// ==============================================================
// This from running the mesh through the shipedit program
	vessel->SetPMI (_V(31.3,31.3,0.51));
	vessel->SetCrossSections (_V(37.5,37.5,4.04));
// ==============================================================
// This is based off of the SRB and Main Shuttle Tank as 
// they are the nearest thing to V-2 that I have stats for.
	vessel->SetCW (1.0, 0.1, 0.3, 0.3);
	vessel->SetRotDrag (_V(0.7,0.7,1.2));
	vessel->SetPitchMomentScale (0);
	vessel->SetBankMomentScale (0);
	vessel->SetLiftCoeffFunc (0); 
// ==============================================================
	vessel->ClearMeshes();
	AddCapsule(vessel, ControlPanel->CapsuleNumber);
	AddAntennaHousing(vessel);
	AddDrogueCover(vessel);
	AddRedstone(vessel);
};

#endif 
