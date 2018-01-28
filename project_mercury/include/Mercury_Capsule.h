#ifndef __MERCURY_CAPSULE_H
#define __MERCURY_CAPSULE_H
	
#include "orbitersdk.h"
#include "multi_stage5.h"
#include "mercury_sequencer.h"
#include "mercury_systems.h"
//#include "OrbIPCC.h"
//#include "OrbiterSoundSDK.h"
const double MERC_DRAG=0.65;

const int ASCS_SLAVE_SCAN  = -1; //A
const int ASCS_POSIDAMP    = 0;  //B
const int ASCS_TURNAROUND  = 1;  //C
const int ASCS_INITIAL_ATT = 2;  //D
const int ASCS_ORBITAL_ATT = 3;  //E
const int ASCS_RETROGRADE  = 4;  //F
const int ASCS_REENTRY_ATT = 5;  //G
const int ASCS_05G_ROLL    = 6;  //H
const int ASCS_LANDING     = 7;  //I

const double CHUTE_OPERATING_SPEED = 0.4;
const double LB_OPERATING_SPEED = 0.2;
//const double  MERCURY_CHUTE_MAIN   = 290;
//const double  MERCURY_CHUTE_DROGUE = 2.627;
const double  MERCURY_CHUTE_MAIN   = 145.5;
const double  MERCURY_CHUTE_DROGUE = 3.0;


const double MERCURY_LENGTH_CAPSULE       = 2.3042;
const double MERCURY_LENGTH_ABORT         = 5.1604;
const double MERCURY_LENGTH_ANTHOUSE      = 0.687;
const double MERCURY_LENGTH_SHIELD        = 0.29;
const double MERCURY_LENGTH_LANDBAG       = 0.97;
const double MERCURY_LENGTH_RETRO         = 0.50;

const double POSIGRADE_MASS_FUEL     = 10.0*KG;
const double POSIGRADE_ISP           = 51*SEC;
const double POSIGRADE_THRUST        = 170*KGF;

//const double RETRO_MASS              = 267*KG;
//const double RETRO_MASS_FUEL         = 68.33*KG;
//const double RETRO_MASS_FUEL         = 19.73*KG;
//const double RETRO_ISP               = 230*SEC;
//const double RETRO_THRUST            = 1578*KGF;
//const double RETRO_THRUST            = 454*KGF;
const double RETRO_MASS              = 130.54*KG;
const double RETRO_MASS_FUEL         = 25.84*KG;
const double RETRO_MASS_EMPTY        = RETRO_MASS-RETRO_MASS_FUEL*3-POSIGRADE_MASS_FUEL *3;
const double RETRO_ISP               = 233*SEC;
const double RETRO_THRUST            = 485.42*KGF;

const int    MISSION_SUBORBITAL = 0;
const int    MISSION_ORBITAL = 1;

const double ABORT_MASS_FUEL         = 75*KG;
const double ABORT_ISP               = 300*SEC;
const double ABORT_THRUST            = 7886*KGF;
const double ABORT_MASS              = 580*KG;

const VECTOR3 MERCURY_OFS_CAPSULE      = { 0.0, 0.0, 0.0};
const VECTOR3 MERCURY_OFS_FILTER      = { 0.0, 1.0, 0.0};
const VECTOR3 MERCURY_OFS_SHIELD       = { 0.0, 0.0, MERCURY_OFS_CAPSULE.z - MERCURY_LENGTH_CAPSULE / 2 -  MERCURY_LENGTH_SHIELD / 2 + MERCURY_LENGTH_SHIELD -.05};
const VECTOR3 MERCURY_OFS_ANTHOUSE     = { 0.0, 0.0, MERCURY_OFS_CAPSULE.z + MERCURY_LENGTH_CAPSULE / 2 + MERCURY_LENGTH_ANTHOUSE / 2};
const VECTOR3 MERCURY_OFS_ABORT        = { 0.0, -0.04, MERCURY_OFS_CAPSULE.z + MERCURY_LENGTH_CAPSULE / 2 + MERCURY_LENGTH_ABORT / 2};
const VECTOR3 MERCURY_OFS_MAINCHUTE    = { 0.0, 0.0, MERCURY_OFS_CAPSULE.z + MERCURY_LENGTH_CAPSULE / 2-.05};
const VECTOR3 MERCURY_OFS_DROUGE       = { -0.12, 0.08, -.2+MERCURY_LENGTH_ANTHOUSE / 2};
const VECTOR3 MERCURY_OFS_DROGUECOVER  = { -0.12, 0.08, -0.07+MERCURY_OFS_ANTHOUSE.z + MERCURY_LENGTH_ANTHOUSE / 2};
const VECTOR3 MERCURY_OFS_LANDBAG      = { 0.0, 0.0, MERCURY_OFS_CAPSULE.z - MERCURY_LENGTH_CAPSULE / 2 + MERCURY_LENGTH_SHIELD -.05 - MERCURY_LENGTH_LANDBAG / 2};
const VECTOR3 MERCURY_OFS_RETRO        = { 0.0, 0.025, MERCURY_OFS_CAPSULE.z - MERCURY_LENGTH_CAPSULE / 2 - MERCURY_LENGTH_RETRO / 2  +.15};
const VECTOR3 MERCURY_OFS_BEACON       = { 0.0, 0.425, MERCURY_OFS_RETRO.z};
const VECTOR3 MERCURY_OFS_RETROCOVER1  = { -0.196, MERCURY_OFS_RETRO.y+0.091, MERCURY_OFS_RETRO.z-.2};
const VECTOR3 MERCURY_OFS_RETROCOVER2  = { -0.005, MERCURY_OFS_RETRO.y-0.23, MERCURY_OFS_RETRO.z-.2};
const VECTOR3 MERCURY_OFS_RETROCOVER3  = { 0.175, MERCURY_OFS_RETRO.y+0.091, MERCURY_OFS_RETRO.z-.2};
const VECTOR3 MERCURY_OFS_RETROSTRAP1  = { -0.03, MERCURY_OFS_RETRO.y+0.46, MERCURY_OFS_RETRO.z+.093};
const VECTOR3 MERCURY_OFS_RETROSTRAP2  = { -0.417, MERCURY_OFS_RETRO.y-0.287, MERCURY_OFS_RETRO.z+.093};
const VECTOR3 MERCURY_OFS_RETROSTRAP3  = { 0.425, MERCURY_OFS_RETRO.y-0.27, MERCURY_OFS_RETRO.z+.093};
const VECTOR3 MERCURY_OFS_EXPLOSIVEBOLT = { 0.0, 0.0, MERCURY_OFS_RETRO.z-.18};

//nst double MERCURY_MASS_CAPSULE    = 1104*KG;
const double MERCURY_MASS_CAPSULE    = 1224.24*KG;
const double MERCURY_FUEL_MASS_AUTO  = 15.8 * KG;
const double MERCURY_FUEL_MASS_MAN   = 11.3 * KG;
const double MERCURY_MASS = MERCURY_MASS_CAPSULE + RETRO_MASS_EMPTY;
const double MERCURY_THRUST_ATT      = 10.88621928 * KGF;
const double MERCURY_THRUST_ROLL_ATT = 2.721555 * KGF;
const double MERCURY_ISP_ATT         = 220 * SEC;
const double MERCURY_THRUST_ATT_LOW  = 0.454 *KGF;

UINT lb_mesh_number     = 0;
UINT capsule_mesh_number= 0;
UINT chute_mesh_number  = 0;
UINT drogue_mesh_number = 0;
UINT filter_mesh_number = 0;
bool bRetroCover1Jett = false;
bool bRetroCover2Jett = false;
bool bRetroCover3Jett = false;

void JettisonTowerAbort(VESSEL *vessel)
{
	//PlayVesselWave(SOUND_TOWERJETT);
	VESSELSTATUS vs;
	VECTOR3 ofs = _V(0,0,0);
	VECTOR3 vel = _V(0,0,0);
	vessel->GetStatus (vs);
	vs.eng_main = vs.eng_hovr = 1.0;
	ofs = MERCURY_OFS_ABORT;		
	ofs.z += 4;
	//ofs.z=-ofs.z;
	vel = _V(0,1,0);	
	StageTransform(vessel,&vs,ofs,vel);
	vs.vrot.x = 0.0;	
	vs.vrot.y = 0.0;	
	vs.vrot.z = 0.0;	
	vs.eng_main=1.0;
	vs.fuel=1.0;
	char name[256];
	strcpy (name, vessel->GetName()); strcat (name, "-TowerAbort");
	VESSEL::Create (name, "Mercury_TowerAbort", vs);
};

void JettisonTower(VESSEL *vessel)
{
	//PlayVesselWave(SOUND_TOWERJETT);
	VESSELSTATUS vs;
	VECTOR3 ofs = _V(0,0,0);
	VECTOR3 vel = _V(0,0,0);
	vessel->GetStatus (vs);
	vs.eng_main = vs.eng_hovr = 1.0;
	ofs = MERCURY_OFS_ABORT;
	ofs.z += 4;
	vel = _V(0,0,0);	
	StageTransform(vessel,&vs,ofs,vel);
	vs.vrot.x = 0.0;	
	vs.vrot.y = 0.0;	
	vs.vrot.z = 0.0;	
	vs.eng_main=1.0;
	vs.fuel=1.0;
	char name[256];
	strcpy (name, vessel->GetName()); strcat (name, "-Tower");
	VESSEL::Create (name, "Mercury_Tower", vs);
};

void JettisonRetro(VESSEL *vessel)
{
	//PlayVesselWave(SOUND_RETROSEP);
	VESSELSTATUS vs;
	VECTOR3 ofs = _V(0,0,0);
	VECTOR3 vel = _V(0,0,0);
	vessel->GetStatus (vs);
	vs.eng_main = vs.eng_hovr = 0.0;
	ofs = MERCURY_OFS_RETRO;
	vel = _V(0,0,-1);
	vessel->SetEngineLevel(ENGINE_MAIN, 0);
	StageTransform(vessel,&vs,ofs,vel);
	vs.vrot.x = 0.0;
	vs.vrot.y = 0.0;
	vs.vrot.z = 0.0;
	char name[256];
	strcpy (name, vessel->GetName()); strcat (name, "-Retro");
	VESSEL::Create (name, "Mercury_Retro", vs);

	vel = _V(0,.75,-1);
	vessel->GetStatus (vs);
	vs.eng_main = vs.eng_hovr = 0.0;
	ofs = MERCURY_OFS_RETROSTRAP1;
	StageTransform(vessel,&vs,ofs,vel);
	vs.vrot.x = -1.0;
	vs.vrot.y = 0.0;
	strcpy (name, vessel->GetName()); strcat (name, "-RetroStrap1");
	VESSEL::Create (name, "Mercury_RetroStrap1", vs);

	vel = _V(-.65,-.375,-1);
	vessel->GetStatus (vs);
	vs.eng_main = vs.eng_hovr = 0.0;
	ofs = MERCURY_OFS_RETROSTRAP2;
	StageTransform(vessel,&vs,ofs,vel);
	vs.vrot.x = 0.33;
	vs.vrot.y = -0.66;
	strcpy (name, vessel->GetName()); strcat (name, "-RetroStrap2");
	VESSEL::Create (name, "Mercury_RetroStrap2", vs);

	vel = _V(0.65,-.375,-1);
	vessel->GetStatus (vs);
	vs.eng_main = vs.eng_hovr = 0.0;
	ofs = MERCURY_OFS_RETROSTRAP3;
	StageTransform(vessel,&vs,ofs,vel);
	vs.vrot.x = 0.33;
	vs.vrot.y = 0.66;
	strcpy (name, vessel->GetName()); strcat (name, "-RetroStrap3");
	VESSEL::Create (name, "Mercury_RetroStrap3", vs);

	if (!bRetroCover1Jett)
	{
		vel = _V(0,0,-1);
		vessel->GetStatus (vs);
		vs.eng_main = vs.eng_hovr = 0.0;
		ofs = MERCURY_OFS_RETROCOVER1;
		StageTransform(vessel,&vs,ofs,vel);
		strcpy (name, vessel->GetName()); strcat (name, "-RetroCover1");
		VESSEL::Create (name, "Mercury_RetroCover1", vs);
	}
	if (!bRetroCover2Jett)
	{
		vel = _V(0,0,-1);
		vessel->GetStatus (vs);
		vs.eng_main = vs.eng_hovr = 0.0;
		ofs = MERCURY_OFS_RETROCOVER2;
		StageTransform(vessel,&vs,ofs,vel);
		strcpy (name, vessel->GetName()); strcat (name, "-RetroCover2");
		VESSEL::Create (name, "Mercury_RetroCover2", vs);
	}
	if (!bRetroCover3Jett)
	{
		vel = _V(0,0,-1);
		vessel->GetStatus (vs);
		vs.eng_main = vs.eng_hovr = 0.0;
		ofs = MERCURY_OFS_RETROCOVER3;
		StageTransform(vessel,&vs,ofs,vel);
		strcpy (name, vessel->GetName()); strcat (name, "-RetroCover3");
		VESSEL::Create (name, "Mercury_RetroCover3", vs);
	}
}

void JettisonRetroCover1(VESSEL *vessel)
{
	if (!bRetroCover1Jett)
	{
		//PlayVesselWave(SOUND_RETRO1);
		VESSELSTATUS vs;
		VECTOR3 ofs = MERCURY_OFS_RETROCOVER1;
		VECTOR3 vel = _V(-1.8,.872,-13.34);
		vessel->GetStatus (vs);
		vs.eng_main = vs.eng_hovr = 0.0;
		vessel->SetEngineLevel(ENGINE_MAIN, 0);
		StageTransform(vessel,&vs,ofs,vel);
		vs.vrot.x = -1.65;
		vs.vrot.y = -3.3;
		vs.vrot.z = 0.0;
		char name[256];
		strcpy (name, vessel->GetName()); strcat (name, "-RetroCover1");
		VESSEL::Create (name, "Mercury_RetroCover1", vs);
		bRetroCover1Jett = true;
	}
}

void JettisonRetroCover2(VESSEL *vessel)
{
	if (!bRetroCover2Jett)
	{
		//PlayVesselWave(SOUND_RETRO2);
		VESSELSTATUS vs;
		VECTOR3 ofs = MERCURY_OFS_RETROCOVER2;
		VECTOR3 vel = _V(-0.052,-2,-15.3);
		vessel->GetStatus (vs);
		vs.eng_main = vs.eng_hovr = 0.0;
		vessel->SetEngineLevel(ENGINE_MAIN, 0);
		StageTransform(vessel,&vs,ofs,vel);
		vs.vrot.x = 5.0;
		vs.vrot.y = 0.0;
		vs.vrot.z = 0.0;
		char name[256];
		strcpy (name, vessel->GetName()); strcat (name, "-RetroCover2");
		VESSEL::Create (name, "Mercury_RetroCover2", vs);
		bRetroCover2Jett = true;
	}
}
void JettisonRetroCover3(VESSEL *vessel)
{
	if (!bRetroCover3Jett)
	{
		//PlayVesselWave(SOUND_RETRO3);
		VESSELSTATUS vs;
		VECTOR3 ofs = MERCURY_OFS_RETROCOVER3;
		VECTOR3 vel = _V(1.706,1.044,-14.16);
		vessel->GetStatus (vs);
		vs.eng_main = vs.eng_hovr = 0.0;
		vessel->SetEngineLevel(ENGINE_MAIN, 0);
		StageTransform(vessel,&vs,ofs,vel);
		vs.vrot.x = -1.65;
		vs.vrot.y = 3.3;
		vs.vrot.z = 0.0;
		char name[256];
		strcpy (name, vessel->GetName()); strcat (name, "-RetroCover3");
		VESSEL::Create (name, "Mercury_RetroCover3", vs);
		bRetroCover3Jett = true;
	}
}


void JettisonDrogue(VESSEL *vessel)
{
	VESSELSTATUS vs;
	VECTOR3 ofs = _V(0,0,0);
	VECTOR3 vel = _V(0,0,0);
	//PlayVesselWave(SOUND_DROGUE);
	vessel->GetStatus (vs);
	vs.eng_main = vs.eng_hovr = 0.0;
	vel = _V(0,1,0);	
	ofs = MERCURY_OFS_ANTHOUSE;	
	StageTransform(vessel,&vs,ofs,vel);
	vs.vrot.x = 0.0;	
	vs.vrot.y = 0.0;	
	vs.vrot.z = 0.0;	
	char name[256];	
	strcpy (name, vessel->GetName()); strcat (name, "-Antenna");
	VESSEL::Create (name, "Mercury_Antenna", vs);
};

void JettisonDrogueCover(VESSEL *vessel)
{
	VESSELSTATUS vs;
	VECTOR3 ofs = MERCURY_OFS_DROGUECOVER;
	VECTOR3 vel = _V(0,1,0);
	//PlayVesselWave(SOUND_DROGUE);
	vessel->GetStatus (vs);
	vs.eng_main = vs.eng_hovr = 0.0;
	StageTransform(vessel,&vs,ofs,vel);
	vs.vrot.x = 0.0;	
	vs.vrot.y = 0.0;	
	vs.vrot.z = 0.0;
	char name[256];
	strcpy (name, vessel->GetName()); strcat (name, "-DrogueCover");
	VESSEL::Create (name, "Mercury_DrogueCover", vs);
};

void JettisonMain(VESSEL *vessel)
{
	VESSELSTATUS vs;
	VECTOR3 ofs = _V(0,0,0);
	VECTOR3 vel = _V(0,0,0);
	vessel->GetStatus (vs);
	vs.eng_main = vs.eng_hovr = 0.0;
	ofs = MERCURY_OFS_MAINCHUTE;		
	ofs.y+=0;
	vel = _V(0,5,0);	
	StageTransform(vessel,&vs,ofs,vel);
	vs.vrot.x = 0.0;	
	vs.vrot.y = 0.0;	
	vs.vrot.z = 0.0;	
	vs.eng_main=1.0;
	vs.fuel=1.0;
	char name[256];
	strcpy (name, vessel->GetName()); strcat (name, "-Main");
	VESSEL::Create (name, "Mercury_Chute", vs);
};


void JettisonAntenna(VESSEL *vessel)
{
	VESSELSTATUS vs;
	VECTOR3 ofs = _V(0,0,0);
	VECTOR3 vel = _V(50,0,0);
	vessel->GetStatus (vs);
	vs.eng_main = vs.eng_hovr = 0.0;
	ofs = MERCURY_OFS_ANTHOUSE;		
	vel = _V(0,	0,0);	
	StageTransform(vessel,&vs,ofs,vel);
	vs.vrot.x = 0.0;	
	vs.vrot.y = 0.0;	
	vs.vrot.z = 0.0;	
	vs.eng_main=1.0;
	vs.fuel=1.0;
	char name[256];
	strcpy (name, vessel->GetName()); strcat (name, "-Antenna");
	VESSEL::Create (name, "Mercury_Antenna", vs);
};

void JettisonBeacon(VESSEL *vessel)
{
	VESSELSTATUS vs;
	VECTOR3 ofs = _V(0,0,0);
	VECTOR3 vel = _V(0,0,0);
	vessel->GetStatus (vs);
	vs.eng_main = vs.eng_hovr = 0.0;
	ofs = MERCURY_OFS_BEACON;		
	vel = _V(0,.1,0);	
	StageTransform(vessel,&vs,ofs,vel);
	vs.vrot.x = 0.0;	
	vs.vrot.y = 0.0;	
	vs.vrot.z = 0.0;	
	vs.eng_main=1.0;
	vs.fuel=1.0;
	char name[256];
	strcpy (name, vessel->GetName()); strcat (name, "-Beacon");
	VESSEL::Create (name, "Mercury_Beacon", vs);
};

void AddFilter(VESSEL *vessel) {
	filter_mesh_number = vessel->AddMesh(oapiLoadMeshGlobal("merc_filter2"), &MERCURY_OFS_FILTER);
	vessel->SetMeshVisibilityMode(filter_mesh_number, MESHVIS_COCKPIT);
}

void AddCapsule(VESSEL *vessel, int capsule)
{
	AddFilter(vessel);
	if (capsule == 7)
		capsule_mesh_number = vessel->AddMesh (oapiLoadMeshGlobal("merc_Freedom7"), &MERCURY_OFS_CAPSULE);
	else if (capsule == 11)
		capsule_mesh_number = vessel->AddMesh (oapiLoadMeshGlobal("merc_LibertyBell7"), &MERCURY_OFS_CAPSULE);
	else if (capsule == 13)
		capsule_mesh_number = vessel->AddMesh (oapiLoadMeshGlobal("merc_Friendship7"), &MERCURY_OFS_CAPSULE);
	else if (capsule == 18)
		capsule_mesh_number = vessel->AddMesh (oapiLoadMeshGlobal("merc_Aurora7"), &MERCURY_OFS_CAPSULE);
	else if (capsule == 16)
		capsule_mesh_number = vessel->AddMesh (oapiLoadMeshGlobal("merc_Sigma7"), &MERCURY_OFS_CAPSULE);
	else if (capsule == 20)
		capsule_mesh_number = vessel->AddMesh (oapiLoadMeshGlobal("merc_Faith7"), &MERCURY_OFS_CAPSULE);
	else if (capsule == 15)
		capsule_mesh_number = vessel->AddMesh (oapiLoadMeshGlobal("merc_FreedomII7"), &MERCURY_OFS_CAPSULE);
	else
		capsule_mesh_number = vessel->AddMesh (oapiLoadMeshGlobal("merc_Friendship7"), &MERCURY_OFS_CAPSULE);

};

void AddAntennaHousing(VESSEL *vessel)
{
	vessel->AddMesh (oapiLoadMeshGlobal("merc_anthouse"), &MERCURY_OFS_ANTHOUSE);
};

void AddDrogueCover(VESSEL *vessel)
{
	vessel->AddMesh (oapiLoadMeshGlobal("merc_DrogueCover"), &MERCURY_OFS_DROGUECOVER);
}

void AddRetro(VESSEL *vessel)
{
	vessel->AddMesh (oapiLoadMeshGlobal("merc_retro"), &MERCURY_OFS_RETRO);
	vessel->AddMesh (oapiLoadMeshGlobal("merc_strap1"), &MERCURY_OFS_RETROSTRAP1);
	vessel->AddMesh (oapiLoadMeshGlobal("merc_strap2"), &MERCURY_OFS_RETROSTRAP2);
	vessel->AddMesh (oapiLoadMeshGlobal("merc_strap3"), &MERCURY_OFS_RETROSTRAP3);
	vessel->AddMesh (oapiLoadMeshGlobal("merc_explosivebolt"), &MERCURY_OFS_EXPLOSIVEBOLT);
};

void AddRetroCover1(VESSEL *vessel)
{
	vessel->AddMesh (oapiLoadMeshGlobal("merc_retrocover1"), &MERCURY_OFS_RETROCOVER1);
};

void AddRetroCover2(VESSEL *vessel)
{
	vessel->AddMesh (oapiLoadMeshGlobal("merc_retrocover2"), &MERCURY_OFS_RETROCOVER2);
};

void AddRetroCover3(VESSEL *vessel)
{
	vessel->AddMesh (oapiLoadMeshGlobal("merc_retrocover3"), &MERCURY_OFS_RETROCOVER3);
};

UINT AddAbortTower(VESSEL *vessel)
{
	return vessel->AddMesh (oapiLoadMeshGlobal("merc_tower"), &MERCURY_OFS_ABORT);
	
};

void AddLandingBag(VESSEL *vessel)
{
	lb_mesh_number = vessel->AddMesh (oapiLoadMeshGlobal("merc_landingbag"), &MERCURY_OFS_LANDBAG);
};

void AddBeacon(VESSEL *vessel)
{
	vessel->AddMesh (oapiLoadMeshGlobal("beacon"), &MERCURY_OFS_BEACON);
};


void AddRetroRockets(VESSEL *vessel)
{
	VECTOR3 m_exhaust_pos;
	VECTOR3 m_exhaust_ref;

	m_exhaust_pos= _V(-.196,0.095,MERCURY_OFS_RETRO.z-.2);
	m_exhaust_ref = _V(.9,-.436,6.7);
	thruster_retro[0] = vessel->CreateThruster(m_exhaust_pos, m_exhaust_ref, RETRO_THRUST, fuel_retro[0], RETRO_ISP);
	vessel->AddExhaust(thruster_retro[0],1.8, 0.05);

	m_exhaust_pos= _V(-0.005,-0.19,MERCURY_OFS_RETRO.z-.2);
	m_exhaust_ref = _V(0.026,1,7.7);
	thruster_retro[1] = vessel->CreateThruster(m_exhaust_pos, m_exhaust_ref, RETRO_THRUST, fuel_retro[1], RETRO_ISP); 
	vessel->AddExhaust(thruster_retro[1],1.8, 0.05);

	m_exhaust_pos= _V(.175,0.107,MERCURY_OFS_RETRO.z-.2);
	m_exhaust_ref = _V(-.853,-0.522,7.1);
	thruster_retro[2] = vessel->CreateThruster(m_exhaust_pos, m_exhaust_ref, RETRO_THRUST, fuel_retro[2], RETRO_ISP);
	vessel->AddExhaust(thruster_retro[2],1.8, 0.05);

/*	
    m_exhaust_pos= _V(-.196,0.095,MERCURY_OFS_RETRO.z-.2);
	m_exhaust_ref = _V(.9,-.436,6.67);
	thruster_retro[0] = vessel->CreateThruster(m_exhaust_pos, m_exhaust_ref, RETRO_THRUST, fuel_retro[0], RETRO_ISP);
	vessel->AddExhaust(thruster_retro[0],1.8, 0.05);

	m_exhaust_pos= _V(-0.005,-0.19,MERCURY_OFS_RETRO.z-.2);
	m_exhaust_ref = _V(0.026,1,7.65);
	thruster_retro[1] = vessel->CreateThruster(m_exhaust_pos, m_exhaust_ref, RETRO_THRUST, fuel_retro[1], RETRO_ISP);	
	vessel->AddExhaust(thruster_retro[1],1.8, 0.05);

	m_exhaust_pos= _V(.175,0.107,MERCURY_OFS_RETRO.z-.2);
	m_exhaust_ref = _V(-.853,-0.522,7.08);
	thruster_retro[2] = vessel->CreateThruster(m_exhaust_pos, m_exhaust_ref, RETRO_THRUST, fuel_retro[2], RETRO_ISP);
	vessel->AddExhaust(thruster_retro[2],1.8, 0.05);
*/
	th_group[0] = thruster_retro[0];
	group_retro[0] = vessel->CreateThrusterGroup(th_group,1,THGROUP_USER);
	
	th_group[0] = thruster_retro[1];
	group_retro[1] = vessel->CreateThrusterGroup(th_group,1,THGROUP_USER);

	th_group[0] = thruster_retro[2];
	group_retro[2] = vessel->CreateThrusterGroup(th_group,1,THGROUP_USER);

// Posigrade
	
	m_exhaust_pos= _V(-.305,MERCURY_OFS_RETRO.y-.11,MERCURY_OFS_RETRO.z-.2);
	m_exhaust_ref = _V(.329,.119,.95);
	thruster_posigrade[0] = vessel->CreateThruster(m_exhaust_pos, m_exhaust_ref, POSIGRADE_THRUST, fuel_posigrade[0], POSIGRADE_ISP);
	vessel->AddExhaust(thruster_posigrade[0],.5,.02);
	
	m_exhaust_pos= _V(.065,MERCURY_OFS_RETRO.y+0.285,MERCURY_OFS_RETRO.z-.2);
	m_exhaust_ref = _V(-.075,-0.337,.95);
	thruster_posigrade[1] = vessel->CreateThruster(m_exhaust_pos, m_exhaust_ref, POSIGRADE_THRUST, fuel_posigrade[1], POSIGRADE_ISP);
	vessel->AddExhaust(thruster_posigrade[1], .5,.02);
	
	m_exhaust_pos= _V(.214,MERCURY_OFS_RETRO.y-0.23,MERCURY_OFS_RETRO.z-.2);
	m_exhaust_ref = _V(-.235,0.253,.95);
	thruster_posigrade[2] = vessel->CreateThruster(m_exhaust_pos, m_exhaust_ref, POSIGRADE_THRUST, fuel_posigrade[2], POSIGRADE_ISP);
	vessel->AddExhaust(thruster_posigrade[2], .5,.02);

	th_group[0] = thruster_posigrade[0];
	th_group[1] = thruster_posigrade[1];
	th_group[2] = thruster_posigrade[2];
	group_posigrade = vessel->CreateThrusterGroup(th_group,3,THGROUP_USER);
// Adapter Pyros

 	m_exhaust_pos = _V(0.35, 0.85, -0.9);
 	m_exhaust_ref = _V(0,0,1);
 	thruster_adaptPyro[0] = vessel->CreateThruster(m_exhaust_pos, m_exhaust_ref, 1, fuel_adaptPyro, .5);
 	vessel->AddExhaust(thruster_adaptPyro[0], .05, .05);

 	m_exhaust_pos = _V(-0.35, 0.85, -0.9);
 	m_exhaust_ref = _V(0,0,1);
 	thruster_adaptPyro[1] = vessel->CreateThruster(m_exhaust_pos, m_exhaust_ref, 1, fuel_adaptPyro, .5);
 	vessel->AddExhaust(thruster_adaptPyro[1], .05, .05);

 	m_exhaust_pos = _V(-0.91, -0.12, -0.9);
 	m_exhaust_ref = _V(0,0,1);
 	thruster_adaptPyro[2] = vessel->CreateThruster(m_exhaust_pos, m_exhaust_ref, 1, fuel_adaptPyro, .5);
 	vessel->AddExhaust(thruster_adaptPyro[2], .05, .05);

 	m_exhaust_pos = _V(-0.56, -0.73, -0.9);
 	m_exhaust_ref = _V(0,0,1);
 	thruster_adaptPyro[3] = vessel->CreateThruster(m_exhaust_pos, m_exhaust_ref, 1, fuel_adaptPyro, .5);
 	vessel->AddExhaust(thruster_adaptPyro[3], .05, .05);
  	m_exhaust_pos = _V(0.91, -0.12, -0.9);
 	m_exhaust_ref = _V(0,0,1);
 	thruster_adaptPyro[4] = vessel->CreateThruster(m_exhaust_pos, m_exhaust_ref, 1, fuel_adaptPyro, .5);
 	vessel->AddExhaust(thruster_adaptPyro[4], .05, .05);

 	m_exhaust_pos = _V(0.56, -0.73, -0.9);
 	m_exhaust_ref = _V(0,0,1);
 	thruster_adaptPyro[5] = vessel->CreateThruster(m_exhaust_pos, m_exhaust_ref, 1, fuel_adaptPyro, .5);
 	vessel->AddExhaust(thruster_adaptPyro[5], .05, .05);

 	th_group[0] = thruster_adaptPyro[0];
 	th_group[1] = thruster_adaptPyro[1];
 	th_group[2] = thruster_adaptPyro[2];
 	th_group[3] = thruster_adaptPyro[3];
 	th_group[4] = thruster_adaptPyro[4];
 	th_group[5] = thruster_adaptPyro[5];
 	group_adaptPyro = vessel->CreateThrusterGroup(th_group, 6, THGROUP_USER);

// Retro Pack Pyros

 	m_exhaust_pos = _V(0.0, 0.94, -0.9);
 	m_exhaust_ref = _V(0,0,1);
 	thruster_RetroPyro[0] = vessel->CreateThruster(m_exhaust_pos, m_exhaust_ref, 1, fuel_RetroPyro, .35);
 	vessel->AddExhaust(thruster_RetroPyro[0], .05, .05);

 	m_exhaust_pos = _V(-0.80, -0.47, -0.9);
 	m_exhaust_ref = _V(0,0,1);
 	thruster_RetroPyro[1] = vessel->CreateThruster(m_exhaust_pos, m_exhaust_ref, 1, fuel_RetroPyro, .35);
 	vessel->AddExhaust(thruster_RetroPyro[1], .05, .05);

 	m_exhaust_pos = _V(0.80, -0.47, -0.9);
 	m_exhaust_ref = _V(0,0,1);
 	thruster_RetroPyro[2] = vessel->CreateThruster(m_exhaust_pos, m_exhaust_ref, 1, fuel_RetroPyro, .35);
 	vessel->AddExhaust(thruster_RetroPyro[2], .05, .03);

 	m_exhaust_pos = MERCURY_OFS_EXPLOSIVEBOLT;
 	m_exhaust_ref = _V(0,0,1);
 	thruster_RetroPyro[3] = vessel->CreateThruster(m_exhaust_pos, m_exhaust_ref, 1, fuel_RetroPyro, .35);
 	vessel->AddExhaust(thruster_RetroPyro[3], .05, .05);

 	th_group[0] = thruster_RetroPyro[0];
 	th_group[1] = thruster_RetroPyro[1];
 	th_group[2] = thruster_RetroPyro[2];
 	th_group[3] = thruster_RetroPyro[3];
 	group_RetroPyro = vessel->CreateThrusterGroup(th_group, 4, THGROUP_USER);

}

void AddAbortRocket(VESSEL *vessel)
{
	PARTICLESTREAMSPEC srb_contrail = {
		0, 0.1, 5, 50.0, 0.3, 8.0, 8, 3.0, PARTICLESTREAMSPEC::DIFFUSE,
		PARTICLESTREAMSPEC::LVL_PSQRT, 0, 0.5,
		PARTICLESTREAMSPEC::ATM_PLOG, 1e-6, 0.1
	};
	PARTICLESTREAMSPEC srb_exhaust = {
		0, 0.1, 120, 100.0, 0, 0.1, 30, 0.5, PARTICLESTREAMSPEC::EMISSIVE,
		PARTICLESTREAMSPEC::LVL_PSQRT, 0, 0.5,
		PARTICLESTREAMSPEC::ATM_PLOG, 1e-6, 0.1
	};
	srb_exhaust.tex = oapiRegisterParticleTexture ("Contrail3");
	SURFHANDLE tex = oapiRegisterExhaustTexture ("Exhaust2");

	VECTOR3 m_exhaust_pos;
	VECTOR3 m_exhaust_ref; 


	m_exhaust_pos= _V(0.0,-.300,-.018702+1.48+1.35);
	m_exhaust_ref = _V(0,.300,.946);
	thruster_abort[0] = vessel->CreateThruster(m_exhaust_pos, m_exhaust_ref, ABORT_THRUST, fuel_abort, ABORT_ISP);
	vessel->AddExhaust(thruster_abort[0],9.0,.45, tex);
	
	m_exhaust_pos= _V(0.25980762,.150,-.018702+1.48+1.35);
	m_exhaust_ref = _V(-0.25980762,-.150,.946);
	thruster_abort[1] = vessel->CreateThruster(m_exhaust_pos, m_exhaust_ref, ABORT_THRUST, fuel_abort, ABORT_ISP);
	vessel->AddExhaust(thruster_abort[1], 9.0,.45, tex);
	
	m_exhaust_pos= _V(-0.25980762,.150,-.018702+1.48+1.35);
	m_exhaust_ref = _V(0.25980762,-.150,.946);
	thruster_abort[2] = vessel->CreateThruster(m_exhaust_pos, m_exhaust_ref, ABORT_THRUST, fuel_abort, ABORT_ISP);
	vessel->AddExhaust(thruster_abort[2], 9.0,.45, tex);

	vessel->AddExhaustStream (thruster_abort[0], &srb_contrail);
	vessel->AddExhaustStream (thruster_abort[0], &srb_exhaust);
	vessel->AddExhaustStream (thruster_abort[1], &srb_contrail);
	vessel->AddExhaustStream (thruster_abort[1], &srb_exhaust);
	vessel->AddExhaustStream (thruster_abort[2], &srb_contrail);
	vessel->AddExhaustStream (thruster_abort[2], &srb_exhaust);

	th_group[0] = thruster_abort[0];
	th_group[1] = thruster_abort[1];
	th_group[2] = thruster_abort[2];
	group_abort = vessel->CreateThrusterGroup(th_group,3,THGROUP_USER);
}
void SetManualThrusters(VESSEL *vessel)
{
	vessel->DelThrusterGroup(THGROUP_ATT_PITCHUP);
	vessel->DelThrusterGroup(THGROUP_ATT_PITCHDOWN);
	vessel->DelThrusterGroup(THGROUP_ATT_YAWRIGHT);
	vessel->DelThrusterGroup(THGROUP_ATT_YAWLEFT);
	vessel->DelThrusterGroup(THGROUP_ATT_BANKRIGHT);
	vessel->DelThrusterGroup(THGROUP_ATT_BANKLEFT);

	th_group[0] = thruster_man_py[0];
	man_pitch_up = vessel->CreateThrusterGroup(th_group,1,THGROUP_USER);
	th_group[0] = thruster_man_py[1];
	man_pitch_down = vessel->CreateThrusterGroup(th_group,1,THGROUP_USER);
	th_group[0] = thruster_man_py[2];
	man_yaw_right = vessel->CreateThrusterGroup(th_group,1,THGROUP_USER);
	th_group[0] = thruster_man_py[3];
	man_yaw_left = vessel->CreateThrusterGroup(th_group,1,THGROUP_USER);
	th_group[0] = thruster_man_roll[0];
	man_roll_right = vessel->CreateThrusterGroup(th_group,1,THGROUP_USER);
	th_group[0] = thruster_man_roll[1];
	man_roll_left = vessel->CreateThrusterGroup(th_group,1,THGROUP_USER);
}

void SetAutoThrusters(VESSEL *vessel)
{
	th_group[0] = thruster_auto_py[0];
	auto_pitch_up = vessel->CreateThrusterGroup(th_group,1,THGROUP_USER);
	th_group[0] = thruster_auto_py[1];
	auto_pitch_down = vessel->CreateThrusterGroup(th_group,1,THGROUP_USER);
	th_group[0] = thruster_auto_py[2];
	auto_yaw_right = vessel->CreateThrusterGroup(th_group,1,THGROUP_USER);
	th_group[0] = thruster_auto_py[3];
	auto_yaw_left = vessel->CreateThrusterGroup(th_group,1,THGROUP_USER);
	th_group[0] = thruster_auto_roll[0];
	auto_roll_right = vessel->CreateThrusterGroup(th_group,1,THGROUP_USER);
	th_group[0] = thruster_auto_roll[1];
	auto_roll_left = vessel->CreateThrusterGroup(th_group,1,THGROUP_USER);

	th_group[0] = thruster_auto_py_1lb[0];
	auto_pitch_up_1lb = vessel->CreateThrusterGroup(th_group,1,THGROUP_USER);
	th_group[0] = thruster_auto_py_1lb[1];
	auto_pitch_down_1lb = vessel->CreateThrusterGroup(th_group,1,THGROUP_USER);
	th_group[0] = thruster_auto_py_1lb[2];
	auto_yaw_right_1lb = vessel->CreateThrusterGroup(th_group,1,THGROUP_USER);
	th_group[0] = thruster_auto_py_1lb[3];
	auto_yaw_left_1lb = vessel->CreateThrusterGroup(th_group,1,THGROUP_USER);
	th_group[0] = thruster_auto_roll_1lb[0];
	auto_roll_right_1lb = vessel->CreateThrusterGroup(th_group,1,THGROUP_USER);
	th_group[0] = thruster_auto_roll_1lb[1];
	auto_roll_left_1lb = vessel->CreateThrusterGroup(th_group,1,THGROUP_USER);
}

void AddAttitudeJets(VESSEL *vessel)
{
	
	VECTOR3 att_ref;
	VECTOR3 att_dir;

	att_ref = _V(0.0,-.41,1.05);
	att_dir = _V(0,1,0);
	thruster_man_py[0] = vessel->CreateThruster(att_ref, att_dir, MERCURY_THRUST_ATT, fuel_manual, MERCURY_ISP_ATT);
	att_ref = _V(-0.06,-.41,1.05);
	att_dir = _V(0,-1,0);
	vessel->AddExhaust(thruster_man_py[0], .2,.02, att_ref, att_dir);

	att_ref = _V(0.0,.41,1.05);
	att_dir = _V(0,-1,0);
	thruster_man_py[1] = vessel->CreateThruster(att_ref, att_dir, MERCURY_THRUST_ATT, fuel_manual, MERCURY_ISP_ATT);
	att_ref = _V(0.06,.41,1.05);
	att_dir = _V(0,1,0);
	vessel->AddExhaust(thruster_man_py[1], .2,.02, att_ref, att_dir);

	att_ref = _V(-.41,0.0,1.05);
	att_dir = _V(1,0,0);
	thruster_man_py[2] = vessel->CreateThruster(att_ref, att_dir, MERCURY_THRUST_ATT, fuel_manual, MERCURY_ISP_ATT);
	att_ref = _V(-.41,0.06,1.05);
	att_dir = _V(-1,0,0);
	vessel->AddExhaust(thruster_man_py[2], .2,.02, att_ref, att_dir);

	att_ref = _V(.41,0.0,1.05);
	att_dir = _V(-1,0,0);
	thruster_man_py[3] = vessel->CreateThruster(att_ref, att_dir, MERCURY_THRUST_ATT, fuel_manual, MERCURY_ISP_ATT);
	att_ref = _V(.41,-0.06,1.05);
	att_dir = _V(1,0,0);
	vessel->AddExhaust(thruster_man_py[3], .2,.02, att_ref, att_dir);

	att_ref = _V(0.80,.05, 0.0);
	att_dir = _V(0,-1,0);
	thruster_man_roll[0] = vessel->CreateThruster(att_ref, att_dir, MERCURY_THRUST_ROLL_ATT, fuel_manual, MERCURY_ISP_ATT);
	att_ref = _V(0.80,.05,-.6);
	att_dir = _V(0,1,0);
	vessel->AddExhaust(thruster_man_roll[0], .2,.02, att_ref, att_dir);

	att_ref = _V(0.80,-.05, 0.0);
	att_dir = _V(0,1,0);
	thruster_man_roll[1] = vessel->CreateThruster(att_ref, att_dir, MERCURY_THRUST_ROLL_ATT, fuel_manual, MERCURY_ISP_ATT);
	att_ref = _V(0.80,-.05,-.6);
	att_dir = _V(0,-1,0);
	vessel->AddExhaust(thruster_man_roll[1], .2,.02, att_ref, att_dir);

	att_ref = _V(0.0,-.41,1.05);
	att_dir = _V(0,1,0);
	thruster_auto_py[0] = vessel->CreateThruster(att_ref, att_dir, MERCURY_THRUST_ATT, fuel_auto, MERCURY_ISP_ATT);
	att_dir = _V(0,-1,0);
	vessel->AddExhaust(thruster_auto_py[0], .2,.02, att_ref, att_dir);
	
	att_ref = _V(0.0,-.41,1.05);
	att_dir = _V(0,1,0);
	thruster_auto_py_1lb[0] = vessel->CreateThruster(att_ref, att_dir, MERCURY_THRUST_ATT_LOW, fuel_auto, MERCURY_ISP_ATT);
	att_ref = _V(0.07,-.41,1.05);
	//att_ref = _V(0.07,-.41,1.05);
	att_dir = _V(0,-1,0);
	vessel->AddExhaust(thruster_auto_py_1lb[0], .07,.02, att_ref, att_dir);

	att_ref = _V(0.0,.41,1.05);
	att_dir = _V(0,-1,0);
	thruster_auto_py[1] = vessel->CreateThruster(att_ref, att_dir, MERCURY_THRUST_ATT, fuel_auto, MERCURY_ISP_ATT);
	att_dir = _V(0,1,0);
	vessel->AddExhaust(thruster_auto_py[1], .2,.02, att_ref, att_dir);
	
	att_ref = _V(0.0,.41,1.05);
	att_dir = _V(0,-1,0);
	thruster_auto_py_1lb[1] = vessel->CreateThruster(att_ref, att_dir, MERCURY_THRUST_ATT_LOW, fuel_auto, MERCURY_ISP_ATT);
	att_ref = _V(-0.07,.41,1.05);
	//att_ref = _V(-0.12,.41,1.05);
	att_dir = _V(0,1,0);
	vessel->AddExhaust(thruster_auto_py_1lb[1], .07,.02, att_ref, att_dir);

	att_ref = _V(-.41,0.0,1.05);
	att_dir = _V(1,0,0);
	thruster_auto_py[2] = vessel->CreateThruster(att_ref, att_dir, MERCURY_THRUST_ATT, fuel_auto, MERCURY_ISP_ATT);
	att_dir = _V(-1,0,0);
	vessel->AddExhaust(thruster_auto_py[2], .2,.02, att_ref, att_dir);
	
	att_ref = _V(-.41,0.0,1.05);
	att_dir = _V(1,0,0);
	thruster_auto_py_1lb[2] = vessel->CreateThruster(att_ref, att_dir, MERCURY_THRUST_ATT_LOW, fuel_auto, MERCURY_ISP_ATT);
	att_ref = _V(-.41,-0.07,1.05);
	att_dir = _V(-1,0,0);
	vessel->AddExhaust(thruster_auto_py_1lb[2], .07,.02, att_ref, att_dir);

	att_ref = _V(.41,0.0,1.05);
	att_dir = _V(-1,0,0);
	thruster_auto_py[3] = vessel->CreateThruster(att_ref, att_dir, MERCURY_THRUST_ATT, fuel_auto, MERCURY_ISP_ATT);
	att_dir = _V(1,0,0);
	vessel->AddExhaust(thruster_auto_py[3], .2,.02, att_ref, att_dir);
	
	att_ref = _V(.41,0.0,1.05);
	att_dir = _V(-1,0,0);
	thruster_auto_py_1lb[3] = vessel->CreateThruster(att_ref, att_dir, MERCURY_THRUST_ATT_LOW, fuel_auto, MERCURY_ISP_ATT);
	att_ref = _V(.41,0.07,1.05);
	att_dir = _V(1,0,0);
	vessel->AddExhaust(thruster_auto_py_1lb[3], .07,.02, att_ref, att_dir);

    att_ref = _V(-0.80,-.05,0.0);
	att_dir = _V(0,1,0);
	thruster_auto_roll[0] = vessel->CreateThruster(att_ref, att_dir, MERCURY_THRUST_ROLL_ATT, fuel_auto, MERCURY_ISP_ATT);	
    att_ref = _V(-0.80,-.05,-.6);
	att_dir = _V(0,-1,0);
	vessel->AddExhaust(thruster_auto_roll[0], .2,.02, att_ref, att_dir);
    
	att_ref = _V(-0.80,-.05,0.0);
	att_dir = _V(0,1,0);
	thruster_auto_roll_1lb[0] = vessel->CreateThruster(att_ref, att_dir, MERCURY_THRUST_ATT_LOW, fuel_auto, MERCURY_ISP_ATT);
	att_ref = _V(-0.80,-.05,-.63);
	att_dir = _V(0,-1,0);
	vessel->AddExhaust(thruster_auto_roll_1lb[0], .07,.02, att_ref, att_dir);

	att_ref = _V(-0.80,.05,0);
	att_dir = _V(0,-1,0);
	thruster_auto_roll[1] = vessel->CreateThruster(att_ref, att_dir, MERCURY_THRUST_ROLL_ATT, fuel_auto, MERCURY_ISP_ATT);
	att_ref = _V(-0.80,.05,-.6);
	att_dir = _V(0,1,0);
	vessel->AddExhaust(thruster_auto_roll[1], .2,.02, att_ref, att_dir);
	
	att_ref = _V(-0.80,.05, 0.0);
	att_dir = _V(0,-1,0);
	thruster_auto_roll_1lb[1] = vessel->CreateThruster(att_ref, att_dir, MERCURY_THRUST_ATT_LOW, fuel_auto, MERCURY_ISP_ATT);
	att_ref = _V(-0.80,.05,-.63);
	att_dir = _V(0,1,0);
	vessel->AddExhaust(thruster_auto_roll_1lb[1], .07,.02, att_ref, att_dir);

	SetAutoThrusters(vessel);
	SetManualThrusters(vessel);
}

void ClearAbort(VESSEL *vessel)
{
	vessel->DelThrusterGroup(group_abort, THGROUP_USER, true);
	if (fuel_abort != 0) {
		vessel->DelPropellantResource(fuel_abort);
		fuel_abort = 0;
	}
}

void ClearRetro(VESSEL *vessel)
{
	vessel->DelThrusterGroup(group_posigrade,THGROUP_USER, true);
	for (int i = 0; i == 2; i++) {
		vessel->DelThrusterGroup(group_retro[i],THGROUP_USER, true);
		if (fuel_retro[i] != 0) {
			vessel->DelPropellantResource(fuel_retro[i]);
			fuel_retro[i] = 0;
		}
		if (fuel_posigrade[i] != 0) {
			vessel->DelPropellantResource(fuel_posigrade[i]);
			fuel_posigrade[i] = 0;
		}
	}
}

class Mercury_Capsule:public IStage
{
public:
	Mercury_Capsule();
	Mercury_Capsule(Mercury_ControlPanel *Panel);
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
	bool bSalvoRetros;
	bool bAbortJettisoned;
	int  MissionType;
	bool bRetroJettisoned;
	bool bBeaconJettisoned;
private:
	//void LiftCoeffR (double aoa, double M, double Re, double *cl, double *cm, double *cd);
	//void LiftCoeffA (double aoa, double M, double Re, double *cl, double *cm, double *cd);
	void SetCapsuleWithRetroC3 (VESSEL *vessel, bool withBeacon);
	void SetCapsuleWithRetroC2 (VESSEL *vessel, bool withBeacon);
	void SetCapsuleWithRetroC1 (VESSEL *vessel, bool withBeacon);
	void SetCapsuleWithRetroC0 (VESSEL *vessel, bool withBeacon);
	void SetCapsule(VESSEL *vessel);
	void SetCapsuleMain(VESSEL *vessel);
	void SetAbortStage(VESSEL *vessel) ;
	void DeployDrogue(VESSEL *vessel);
	void DeployMain(VESSEL *vessel);
	void SepParachute(VESSEL *vessel, bool do_jettison);
	void DoCapsuleThrusters(VESSEL *vessel);
	void DoASCS (VESSEL *vessel, double simt);
	void DoAuxDamp (VESSEL *vessel, double simt);
	void DoPosigradeDamping(VESSEL *vessel, double simt);
	void DoTurnAround(VESSEL *vessel, double simt);
	void DoHighTorqueAttitude(VESSEL *vessel, double simt);
	void DoLowTorqueAttitude(VESSEL *vessel, double simt);
	void DoPitchAttitude(VESSEL *vessel, double simt);
	void Do05Roll(VESSEL *vessel, double simt);
	void OpenChute (VESSEL *vessel);
	void OpenDrogue (VESSEL *vessel);
	void OpenLandingBag (VESSEL *vessel);
	void UpdateMesh(VESSEL *vessel);
	void AddChute (VESSEL *vessel);
	void AddDrogue (VESSEL *vessel);

	void TimestepTelemetry(VESSEL *vessel, double simt);
	void TimestepAnimation(VESSEL *vessel, double simt);
	void DoAbortSequence(VESSEL *vessel, double simt);
	void DoLandingSequence(VESSEL *vessel, double simt);
	void DoRetroSequence(VESSEL *vessel, double simt);
	void DoRetroPack(VESSEL *vessel, double simt);


	bool bRetroSeparate;
	bool bJettisonBeacon;
	double PressDelta;
	double LastPress;
	double last_simt;
	bool bParachute;
	bool bParachuteJettisoned;
	bool bSquibArmed;
	VECTOR3 old_vel;
	double old_alt;
//---------------	
	bool RetroSeq;
	bool DoAttPermission;
	bool EmerRetroSeq;
	bool RetroDelay;
	int retro_seq;
	double retro_timer;
	double retro_fire_timer;
	double retro_jett_timer;
	double retro_seq_timer;
	bool bDonePosigradeDamp;
	bool bDrogueDeployed;
	bool bMainDeployed;
	bool bDrogueJettisoned;
	bool bDeployMainChute;
	bool bMainJettisoned;
	bool bBackupDeployed;
	bool bBackupJettisoned;
	bool bDoneTurnAround;
	bool bSplashdown;
	int abort_seq;
	double landingbag_timer;
	double PosigradeDampTimer;
	bool bLandingBagDeployed;
	bool bLBTimerActive;
	bool bDonePosigrade;
	bool bDoAutoRetroJettison;
	int ascs_mode;
	double init_att_time;
	enum DrogueStatus { DROGUE_CLOSED, DROGUE_DEPLOYED, DROGUE_OPENING, DROGUE_REEFED, DROGUE_UNREEFING, DROGUE_OPENED } drogue_status;
	double drogue_proc, vdrogue_proc; 
	bool drogue_moving;             
	bool drogue_endanim;            
	double drogue_reefed;
	enum ChuteStatus { CHUTE_CLOSED, CHUTE_DEPLOYED, CHUTE_OPENING, CHUTE_REEFED, CHUTE_UNREEFING, CHUTE_OPENED } chute_status;
	double chute_proc, vchute_proc; 
	bool chute_moving;             
	bool chute_endanim;            
	double chute_reefed;
	enum LBStatus { LB_CLOSED, LB_DEPLOYED, LB_OPENING, LB_OPENED } lb_status;
	enum FStatus {F_LEFT, F_RIGHT} f_status;
	double lb_proc, vlb_proc; 
	bool lb_moving;             
	bool lb_endanim;            
	Mercury_ControlPanel *ControlPanel;
	bool doSound[18];
	bool bC1Set;
	bool retro_fired1;
	bool retro_fired2;
	bool retro_fired3;
	bool retro_fire1;
	bool retro_fire2;
	bool retro_fire3;
	double retro_timer2;
	double retro_timer3;
	bool DoEmerRetroFire;
	bool DoRetroFire;
	bool retro_in_attitude;
};
/*Mercury_Capsule::Mercury_Capsule()
{
	Init();
};*/

Mercury_Capsule::Mercury_Capsule(Mercury_ControlPanel *Panel)
{
	ControlPanel = Panel;
	Init();
};

void Mercury_Capsule::Init ()
{
//	RequestLoadVesselWave(VESSELSOUND1,		"Sound\\Vessel\\attfire.wav");
	for (int i=0; i> 18;i++)
		doSound[i] = false;
	bRetroSeparate = false;
	RetroSeq = false;
	DoAttPermission = false;
	EmerRetroSeq = false;
	RetroDelay = false;
	bDonePosigrade = false;
	retro_timer = 0.0;
	retro_seq_timer  = 0.0;
	retro_fire_timer = 0.0;
	retro_jett_timer = 0.0;
	retro_seq = 0;
	bBeaconJettisoned=false;
	bJettisonBeacon=false;
	PressDelta = 0.0;
	LastPress = 0.0;
	mercury_att_mode = MERCURY_ATT_MANUAL;
	bDrogueDeployed = false;
	bMainDeployed = false;
	bParachute = false;
	bDrogueJettisoned=false;
	bMainJettisoned=false;
	bSplashdown=false;
	bBackupJettisoned=false;
	bBackupDeployed=false;
	bParachuteJettisoned=false;
	bDeployMainChute = false;
	bRetroJettisoned= false;
	bAbortJettisoned = true;
	bSquibArmed = false;
	bSalvoRetros = false;
	abort_seq = 0;
	landingbag_timer = 0.0;
	bLandingBagDeployed = false;
	bLBTimerActive = false;
	last_simt = 0.0;
	bDonePosigradeDamp = false;
	PosigradeDampTimer = 0.0;
	bDoneTurnAround = false;
	old_vel = _V(0,0,0);
	old_alt = 0.0;
	MissionType = MISSION_SUBORBITAL;
	bDoAutoRetroJettison = false;
	ascs_mode = ASCS_SLAVE_SCAN;
	init_att_time = 0.0;
	chute_status = CHUTE_CLOSED;
	chute_moving=false;
	chute_endanim=false;
	chute_proc=0;
	chute_reefed=0;
	vchute_proc=0;
	drogue_status = DROGUE_CLOSED;
	drogue_moving=false;
	drogue_endanim=false;
	drogue_proc=0;
	drogue_reefed=0;
	vdrogue_proc=0;
	lb_status = LB_CLOSED;
	f_status = F_LEFT;
	lb_moving=false;
	lb_endanim=false;
	lb_proc=0;
	vlb_proc=0;
	bC1Set=false;

	retro_fired1 = false;
	retro_fired2 = false;
	retro_fired3 = false;

	retro_fire1  = false;
	retro_fire2  = false;
	retro_fire3  = false;

	retro_timer2 = 0.0;
	retro_timer3 = 0.0;
	DoEmerRetroFire = false;
	DoRetroFire     = false;

	//bool retro_in_attitude;


}

void Mercury_Capsule::Exit(VESSEL *vessel)
{

}

void Mercury_Capsule::Setup (VESSEL *vessel, double stage_sep_time)
{
	vessel->ClearMeshes();
	vessel->ClearExhaustRefs();
	vessel->ClearPropellantResources();
	vessel->ClearThrusterDefinitions();
	if (bAbortJettisoned) {
		fuel_auto = vessel->CreatePropellantResource(MERCURY_FUEL_MASS_AUTO, MERCURY_FUEL_MASS_AUTO);
		fuel_manual = vessel->CreatePropellantResource(MERCURY_FUEL_MASS_MAN, MERCURY_FUEL_MASS_MAN);
		if (!bRetroJettisoned) {
			fuel_retro[0] = vessel->CreatePropellantResource(RETRO_MASS_FUEL, RETRO_MASS_FUEL);
			fuel_retro[1] = vessel->CreatePropellantResource(RETRO_MASS_FUEL, RETRO_MASS_FUEL);
			fuel_retro[2] = vessel->CreatePropellantResource(RETRO_MASS_FUEL, RETRO_MASS_FUEL);
			fuel_posigrade[0] = vessel->CreatePropellantResource(POSIGRADE_MASS_FUEL, POSIGRADE_MASS_FUEL);
			fuel_posigrade[1] = vessel->CreatePropellantResource(POSIGRADE_MASS_FUEL, POSIGRADE_MASS_FUEL);
			fuel_posigrade[2] = vessel->CreatePropellantResource(POSIGRADE_MASS_FUEL, POSIGRADE_MASS_FUEL);
	 		fuel_adaptPyro = vessel->CreatePropellantResource(1);
			fuel_RetroPyro = vessel->CreatePropellantResource(1);
			SetCapsuleWithRetroC3(vessel,true);
		} else {
			if (bMainJettisoned)
				SetCapsuleMain(vessel);
			else
				SetCapsule(vessel);
		}
	} else {
		fuel_auto = vessel->CreatePropellantResource(MERCURY_FUEL_MASS_AUTO, MERCURY_FUEL_MASS_AUTO);
		fuel_manual = vessel->CreatePropellantResource(MERCURY_FUEL_MASS_MAN, MERCURY_FUEL_MASS_MAN);
		fuel_retro[0] = vessel->CreatePropellantResource(RETRO_MASS_FUEL, RETRO_MASS_FUEL);
		fuel_retro[1] = vessel->CreatePropellantResource(RETRO_MASS_FUEL, RETRO_MASS_FUEL);
		fuel_retro[2] = vessel->CreatePropellantResource(RETRO_MASS_FUEL, RETRO_MASS_FUEL);
		fuel_posigrade[0] = vessel->CreatePropellantResource(POSIGRADE_MASS_FUEL, POSIGRADE_MASS_FUEL);
		fuel_posigrade[1] = vessel->CreatePropellantResource(POSIGRADE_MASS_FUEL, POSIGRADE_MASS_FUEL);
		fuel_posigrade[2] = vessel->CreatePropellantResource(POSIGRADE_MASS_FUEL, POSIGRADE_MASS_FUEL);
		fuel_abort = vessel->CreatePropellantResource(ABORT_MASS_FUEL, ABORT_MASS_FUEL);
 		fuel_adaptPyro = vessel->CreatePropellantResource(1);
		fuel_RetroPyro = vessel->CreatePropellantResource(1);
		SetAbortStage(vessel);
 		vessel->SetThrusterGroupLevel(group_abort, 1.0);
 		vessel->SetThrusterGroupLevel(group_adaptPyro, 1.0);
	}
	LastPress=vessel->GetAtmPressure();
}

void Mercury_Capsule::ParseLine (VESSEL *vessel, char *line, void *vs)
{
	double tempD=0.0;
    if (!_strnicmp (line, "ABORT_SEQ", 9)) {
//	oapiWriteScenario_int   (scn, "ABORT_SEQ", abort_seq);
		sscanf (line+9, "%d", &abort_seq);
    } else if (!_strnicmp (line, "RETRO_SALVO", 11)) {
//	oapiWriteScenario_float (scn, "RETRO_SALVO", bSalvoRetros);
        sscanf (line+11, "%lf", &tempD);
		if (tempD == 1)
			bSalvoRetros = true;
		else
			bSalvoRetros = false;
    } else if (!_strnicmp (line, "ABORT_JETT", 10)) {
//	oapiWriteScenario_float (scn, "ABORT_JETT", bAbortJettisoned);
        sscanf (line+10, "%lf", &tempD);
		if (tempD == 1)
			bAbortJettisoned = true;
		else
			bAbortJettisoned = false;

    } else if (!_strnicmp (line, "POSI_DAMP_TIMER", 15)) {
//	oapiWriteScenario_float (scn, "POSI_DAMP_TIMER", last_simt - PosigradeDampTimer);
        sscanf (line+15, "%lf", &tempD);
		PosigradeDampTimer = -tempD;
    } else if (!_strnicmp (line, "AUTO_POSIDAMP", 13)) {
//	oapiWriteScenario_float (scn, "AUTO_POSIDAMP", bDonePosigradeDamp);
        sscanf (line+13, "%lf", &tempD);
		if (tempD == 1)
			bDonePosigradeDamp = true;
		else
			bDonePosigradeDamp = false;
    } else if (!_strnicmp (line, "AUTO_TURNAROUND", 15)) {
//	oapiWriteScenario_float (scn, "AUTO_TURNAROUND", bDoneTurnAround);
        sscanf (line+15, "%lf", &tempD);
		if (tempD == 1)
			bDoneTurnAround = true;
		else
			bDoneTurnAround = false;
    } else if (!_strnicmp (line, "POSI_DONE", 9)) {
//	oapiWriteScenario_float (scn, "POSI_DONE", bDonePosigrade);
        sscanf (line+9, "%lf", &tempD);
		if (tempD == 1)
			bDonePosigrade = true;
		else
			bDonePosigrade = false;
    } else if (!_strnicmp (line, "RETRO_ACTIVE", 12)) {
        sscanf (line+12, "%lf", &tempD);
		if (tempD == 1)
			RetroSeq = true;
		else
			RetroSeq = false;
    } else if (!_strnicmp (line, "EMER_RETRO_ACTIVE", 17)) {
        sscanf (line+17, "%lf", &tempD);
		if (tempD == 1)
			EmerRetroSeq = true;
		else
			EmerRetroSeq = false;
    } else if (!_strnicmp (line, "RETRO_JETTISON", 14)) {
//	oapiWriteScenario_float (scn, "RETRO_JETT", bRetroJettisoned);
        sscanf (line+14, "%lf", &tempD);
		if (tempD == 1) {
			bRetroJettisoned = true;
		} else{
			bRetroJettisoned = false;
		}
    } else if (!_strnicmp (line, "RETRO_SEQ", 9)) {
//	oapiWriteScenario_int   (scn, "RETRO_SEQ", retro_seq);
		sscanf (line+9, "%d", &retro_seq);
    } else if (!_strnicmp (line, "RETRO_TIMER", 11)) {
//	oapiWriteScenario_float (scn, "RETRO_TIMER", last_simt - retro_timer);
        sscanf (line+11, "%lf", &tempD);
		retro_timer = -tempD;
    } else if (!_strnicmp (line, "RETRO_FIRE_TIMER", 16)) {
        sscanf (line+16, "%lf", &tempD);
		retro_fire_timer = -tempD;
    } else if (!_strnicmp (line, "RETRO_SEQ_TIMER", 15)) {
        sscanf (line+15, "%lf", &tempD);
		retro_seq_timer = -tempD;
    } else if (!_strnicmp (line, "RETRO_JETT_TIMER", 16)) {
        sscanf (line+16, "%lf", &tempD);
		retro_jett_timer = -tempD;
    } else if (!_strnicmp (line, "BEACON_JETT", 11)) {
//	oapiWriteScenario_float (scn, "BEACON_JETT", bBeaconJettisoned);
        sscanf (line+11, "%lf", &tempD);
		if (tempD == 1)
			bBeaconJettisoned = true;
		else
			bBeaconJettisoned = false;
    } else if (!_strnicmp (line, "DROGUE_DEP", 10)) {
//	oapiWriteScenario_float (scn, "DROGUE_DEP", bDrogueDeployed);
        sscanf (line+10, "%lf", &tempD);
		if (tempD == 1)
			bDrogueDeployed = true;
		else
			bDrogueDeployed = false;
    } else if (!_strnicmp (line, "DROGUE_JETT", 11)) {
//	oapiWriteScenario_float (scn, "DROGUE_JETT", bDrogueJettisoned);
        sscanf (line+11, "%lf", &tempD);
		if (tempD == 1)
			bDrogueJettisoned = true;
		else
			bDrogueJettisoned = false;
    } else if (!_strnicmp (line, "DEPLOY_MAIN_CHUTE", 17)) {
//	oapiWriteScenario_float (scn, "CHUTEHOUSE_JETT", bDeployMainChute);
        sscanf (line+17, "%lf", &tempD);
		if (tempD == 1)
			bDeployMainChute = true;
		else
			bDeployMainChute = false;
    } else if (!_strnicmp (line, "MAIN_DEPLOY", 11)) {
//	oapiWriteScenario_float (scn, "MAIN_DEPLOY", bMainDeployed);
        sscanf (line+11, "%lf", &tempD);
		if (tempD == 1)
			bMainDeployed = true;
		else
			bMainDeployed = false;
    } else if (!_strnicmp (line, "MAIN_JETT", 9)) {
//	oapiWriteScenario_float (scn, "MAIN_JETT", bMainJettisoned);
        sscanf (line+9, "%lf", &tempD);
		if (tempD == 1)
			bMainJettisoned = true;
		else
			bMainJettisoned = false;
    } else if (!_strnicmp (line, "BACKUP_DEPLOY", 13)) {
//	oapiWriteScenario_float (scn, "BACKUP_DEPLOY", bBackupDeployed);
        sscanf (line+13, "%lf", &tempD);
		if (tempD == 1)
			bBackupDeployed = true;
		else
			bBackupDeployed = false;
    } else if (!_strnicmp (line, "BACKUP_JETT", 11)) {
//	oapiWriteScenario_float (scn, "BACKUP_JETT", bBackupJettisoned);
        sscanf (line+11, "%lf", &tempD);
		if (tempD == 1)
			bBackupJettisoned = true;
		else
			bBackupJettisoned = false;
    } else if (!_strnicmp (line, "LB_TIMER", 8)) {
//	oapiWriteScenario_float (scn, "LB_TIMER", last_simt - landingbag_timer);
        sscanf (line+8, "%lf", &tempD);
		landingbag_timer = -tempD;
    } else if (!_strnicmp (line, "LB_DEPLOYED", 11)) {
//	oapiWriteScenario_float (scn, "LB_DEPLOYED", bLandingBagDeployed);
        sscanf (line+11, "%lf", &tempD);
		if (tempD == 1)
			bLandingBagDeployed = true;
		else
			bLandingBagDeployed = false;
    } else if (!_strnicmp (line, "LB_TIMER_ACTIVE", 15)) {
        sscanf (line+15, "%lf", &tempD);
		if (tempD == 1)
			bLBTimerActive = true;
		else
			bLBTimerActive = false;
    } else if (!_strnicmp (line, "RETRO_DOAUTO", 12)) {
        sscanf (line+12, "%lf", &tempD);
		if (tempD == 1)
			bDoAutoRetroJettison = true;
		else
			bDoAutoRetroJettison = false;
    } else if (!_strnicmp (line, "MISSION_TYPE", 12)) {
        sscanf (line+12, "%d", &MissionType);
	} else if (!_strnicmp (line, "ASCS_MODE", 9)) {
		sscanf (line+9,  "%d", &ascs_mode);
    } else if (!_strnicmp (line, "INIT_ATT_TIME", 13)) {
        sscanf (line+13, "%lf", &init_att_time);
    } else {
        vessel->ParseScenarioLineEx (line, vs);
    }
//	this->Setup(vessel,0);
}

void Mercury_Capsule::SaveState (VESSEL *vessel, FILEHANDLE scn)
{
	oapiWriteScenario_int (scn, "CONFIGURATION", 4);

	oapiWriteScenario_int   (scn, "ABORT_SEQ", abort_seq);
	oapiWriteScenario_float (scn, "RETRO_SALVO", bSalvoRetros);
	oapiWriteScenario_float (scn, "ABORT_JETT", bAbortJettisoned);

	oapiWriteScenario_float (scn, "POSI_DAMP_TIMER", last_simt - PosigradeDampTimer);
	oapiWriteScenario_float (scn, "AUTO_POSIDAMP", bDonePosigradeDamp);
	oapiWriteScenario_float (scn, "AUTO_TURNAROUND", bDoneTurnAround);

	oapiWriteScenario_float (scn, "POSI_DONE", bDonePosigrade);
	oapiWriteScenario_float (scn, "RETRO_ACTIVE", RetroSeq);
	oapiWriteScenario_float (scn, "EMER_RETRO_ACTIVE", EmerRetroSeq);
	oapiWriteScenario_float (scn, "RETRO_JETTISON", bRetroJettisoned);
	oapiWriteScenario_int   (scn, "RETRO_SEQ", retro_seq);
	oapiWriteScenario_float (scn, "RETRO_TIMER", last_simt - retro_timer);
	oapiWriteScenario_float (scn, "RETRO_SEQ_TIMER",  last_simt - retro_seq_timer);
	oapiWriteScenario_float (scn, "RETRO_FIRE_TIMER", last_simt - retro_fire_timer);
	oapiWriteScenario_float (scn, "RETRO_JETT_TIMER", last_simt - retro_jett_timer);
	oapiWriteScenario_float (scn, "BEACON_JETT", bBeaconJettisoned);


	oapiWriteScenario_float (scn, "DROGUE_DEP", bDrogueDeployed);
	oapiWriteScenario_float (scn, "DROGUE_JETT", bDrogueJettisoned);
	oapiWriteScenario_float (scn, "DEPLOY_MAIN_CHUTE", bDeployMainChute);
	oapiWriteScenario_float (scn, "MAIN_DEPLOY", bMainDeployed);
	oapiWriteScenario_float (scn, "MAIN_JETT", bMainJettisoned);
	oapiWriteScenario_float (scn, "BACKUP_DEPLOY", bBackupDeployed);
	oapiWriteScenario_float (scn, "BACKUP_JETT", bBackupJettisoned);
	oapiWriteScenario_float (scn, "LB_TIMER", last_simt - landingbag_timer);
	oapiWriteScenario_float (scn, "LB_DEPLOYED", bLandingBagDeployed);
	oapiWriteScenario_float (scn, "LB_TIMER_ACTIVE", bLBTimerActive);
	oapiWriteScenario_int   (scn, "MISSION_TYPE", MissionType);
	oapiWriteScenario_float (scn, "RETRO_DOAUTO", bDoAutoRetroJettison);
	oapiWriteScenario_int   (scn, "ASCS_MODE", ascs_mode);
	oapiWriteScenario_float (scn, "INIT_ATT_TIME", last_simt - init_att_time);

}

void Mercury_Capsule::DoCapsuleThrusters(VESSEL *vessel)
{


	if (ControlPanel->pull_manualmode == MANUAL_DIRECT ) {
		vessel->SetThrusterGroupLevel(man_pitch_up, 0.0);
		vessel->SetThrusterGroupLevel(man_pitch_down, 0.0);
		vessel->SetThrusterGroupLevel(man_yaw_left, 0.0);
		vessel->SetThrusterGroupLevel(man_yaw_right, 0.0);
		vessel->SetThrusterGroupLevel(man_roll_left, 0.0);
		vessel->SetThrusterGroupLevel(man_roll_right, 0.0);
		vessel->SetThrusterGroupLevel(man_pitch_up, vessel->GetManualControlLevel(THGROUP_ATT_PITCHUP, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE));
		vessel->SetThrusterGroupLevel(man_pitch_down, vessel->GetManualControlLevel(THGROUP_ATT_PITCHDOWN, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE));
		vessel->SetThrusterGroupLevel(man_yaw_left, vessel->GetManualControlLevel(THGROUP_ATT_YAWLEFT, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE));
		vessel->SetThrusterGroupLevel(man_yaw_right, vessel->GetManualControlLevel(THGROUP_ATT_YAWRIGHT, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE));
		vessel->SetThrusterGroupLevel(man_roll_left, vessel->GetManualControlLevel(THGROUP_ATT_BANKLEFT, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE));
		vessel->SetThrusterGroupLevel(man_roll_right, vessel->GetManualControlLevel(THGROUP_ATT_BANKRIGHT, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE));
	}

	if (ControlPanel->switch_automaticmode == AUTO_FBW)	{
		vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
		vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 0.0);
		vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
		vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 0.0);
		vessel->SetThrusterGroupLevel(auto_yaw_left, 0.0);
		vessel->SetThrusterGroupLevel(auto_yaw_left_1lb, 0.0);
		vessel->SetThrusterGroupLevel(auto_yaw_right, 0.0);
		vessel->SetThrusterGroupLevel(auto_yaw_right_1lb, 0.0);
		vessel->SetThrusterGroupLevel(auto_roll_left, 0.0);
		vessel->SetThrusterGroupLevel(auto_roll_left_1lb, 0.0);
		vessel->SetThrusterGroupLevel(auto_roll_right, 0.0);
		vessel->SetThrusterGroupLevel(auto_roll_right_1lb, 0.0);

		if (vessel->GetManualControlLevel(THGROUP_ATT_PITCHUP, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE) > .75)
			vessel->SetThrusterGroupLevel(auto_pitch_up, 1.0);
		else if (vessel->GetManualControlLevel(THGROUP_ATT_PITCHUP, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE) > .3)
			vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 1.0);

		if (vessel->GetManualControlLevel(THGROUP_ATT_PITCHDOWN, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE) > .75)
			vessel->SetThrusterGroupLevel(auto_pitch_down, 1.0);
		else if (vessel->GetManualControlLevel(THGROUP_ATT_PITCHDOWN, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE) > .3)
			vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 1.0);
		if (vessel->GetManualControlLevel(THGROUP_ATT_YAWLEFT, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE) > .75)
			vessel->SetThrusterGroupLevel(auto_yaw_left, 1.0);
		else if (vessel->GetManualControlLevel(THGROUP_ATT_YAWLEFT, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE) > .3)
			vessel->SetThrusterGroupLevel(auto_yaw_left_1lb, 1.0);
		if (vessel->GetManualControlLevel(THGROUP_ATT_YAWRIGHT, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE) > .75)
			vessel->SetThrusterGroupLevel(auto_yaw_right, 1.0);
		else if (vessel->GetManualControlLevel(THGROUP_ATT_YAWRIGHT, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE) > .3)
			vessel->SetThrusterGroupLevel(auto_yaw_right_1lb, 1.0);
		if (vessel->GetManualControlLevel(THGROUP_ATT_BANKLEFT, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE) > .75)
			vessel->SetThrusterGroupLevel(auto_roll_left, 1.0);
		else if (vessel->GetManualControlLevel(THGROUP_ATT_BANKLEFT, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE) > .3)
			vessel->SetThrusterGroupLevel(auto_roll_left_1lb, 1.0);

		if (vessel->GetManualControlLevel(THGROUP_ATT_BANKRIGHT, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE) > .75)
			vessel->SetThrusterGroupLevel(auto_roll_right, 1.0);
		else if (vessel->GetManualControlLevel(THGROUP_ATT_BANKRIGHT, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE) > .3)
			vessel->SetThrusterGroupLevel(auto_roll_right_1lb, 1.0);
	}

	if(ControlPanel->pull_autopitchmode == AUTO_OFF || (ControlPanel->switch_automaticmode != AUTO_FBW && (ascs_mode == ASCS_05G_ROLL || ascs_mode == ASCS_LANDING)) )
	{
		vessel->SetThrusterResource(thruster_auto_py[0], 0);
		vessel->SetThrusterResource(thruster_auto_py_1lb[0], 0);
		vessel->SetThrusterResource(thruster_auto_py[1], 0);
		vessel->SetThrusterResource(thruster_auto_py_1lb[1], 0);
		vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
		vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 0.0);
		vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
		vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 0.0);
	} else {
		vessel->SetThrusterResource(thruster_auto_py[0], fuel_auto);
		vessel->SetThrusterResource(thruster_auto_py_1lb[0], fuel_auto);
		vessel->SetThrusterResource(thruster_auto_py[1], fuel_auto);
		vessel->SetThrusterResource(thruster_auto_py_1lb[1], fuel_auto);


	
	
	}

	if(ControlPanel->pull_autoyawmode == AUTO_OFF || (ControlPanel->switch_automaticmode != AUTO_FBW && (ascs_mode == ASCS_05G_ROLL || ascs_mode == ASCS_LANDING)))
	{
		vessel->SetThrusterResource(thruster_auto_py[2], 0);
		vessel->SetThrusterResource(thruster_auto_py_1lb[2], 0);
		vessel->SetThrusterResource(thruster_auto_py[3], 0);
		vessel->SetThrusterResource(thruster_auto_py_1lb[3], 0);
		vessel->SetThrusterGroupLevel(auto_yaw_left, 0.0);
		vessel->SetThrusterGroupLevel(auto_yaw_left_1lb, 0.0);
		vessel->SetThrusterGroupLevel(auto_yaw_right, 0.0);
		vessel->SetThrusterGroupLevel(auto_yaw_right_1lb, 0.0);
	} else {
		vessel->SetThrusterResource(thruster_auto_py[2], fuel_auto);
		vessel->SetThrusterResource(thruster_auto_py_1lb[2], fuel_auto);
		vessel->SetThrusterResource(thruster_auto_py[3], fuel_auto);
		vessel->SetThrusterResource(thruster_auto_py_1lb[3], fuel_auto);
	}

	if(ControlPanel->pull_autorollmode == AUTO_OFF || (ControlPanel->switch_automaticmode != AUTO_FBW && ascs_mode == ASCS_LANDING))
	{
		vessel->SetThrusterResource(thruster_auto_roll[0],0);
		vessel->SetThrusterResource(thruster_auto_roll_1lb[0],0);
		vessel->SetThrusterResource(thruster_auto_roll[1],0);
		vessel->SetThrusterResource(thruster_auto_roll_1lb[1],0);
		vessel->SetThrusterGroupLevel(auto_roll_left, 0.0);
		vessel->SetThrusterGroupLevel(auto_roll_left_1lb, 0.0);
		vessel->SetThrusterGroupLevel(auto_roll_right, 0.0);
		vessel->SetThrusterGroupLevel(auto_roll_right_1lb, 0.0);
	} else {
		vessel->SetThrusterResource(thruster_auto_roll[0], fuel_auto);
		vessel->SetThrusterResource(thruster_auto_roll_1lb[0], fuel_auto);
		vessel->SetThrusterResource(thruster_auto_roll[1], fuel_auto);
		vessel->SetThrusterResource(thruster_auto_roll_1lb[1], fuel_auto);
	}
		



	/*if (!IsPlaying(VESSELSOUND1)) {
		bool bDoSound = false ;
		if (vessel->GetThrusterGroupLevel(auto_pitch_up) > 0.0 && !doSound[0]) {
				doSound[0] = true;
				bDoSound = true;
		}
		if (vessel->GetThrusterGroupLevel(auto_pitch_down) > 0.0 && !doSound[1]) {
				doSound[1] = true;
				bDoSound = true;
		}
		if (vessel->GetThrusterGroupLevel(auto_yaw_left) > 0.0   && !doSound[2]) {
				doSound[2] = true;
				bDoSound = true;
		}
		if (vessel->GetThrusterGroupLevel(auto_yaw_right) > 0.0  && !doSound[3]) {
				doSound[3] = true;
				bDoSound = true;
		}
		if (vessel->GetThrusterGroupLevel(auto_roll_left) > 0.0  && !doSound[4]) {
				doSound[4] = true;
				bDoSound = true;
		}
		if (vessel->GetThrusterGroupLevel(auto_roll_right) > 0.0 && !doSound[5]) {
				doSound[5] = true;
				bDoSound = true;
		}

		if (vessel->GetThrusterGroupLevel(auto_pitch_up_1lb) > 0.0   && !doSound[6]) {
				doSound[6] = true;
				bDoSound = true;
		}
		if (vessel->GetThrusterGroupLevel(auto_pitch_down_1lb) > 0.0 && !doSound[7]) {
				doSound[7] = true;
				bDoSound = true;
		}
		if (vessel->GetThrusterGroupLevel(auto_yaw_left_1lb) > 0.0   && !doSound[8]) {
				doSound[8] = true;
				bDoSound = true;
		}
		if (vessel->GetThrusterGroupLevel(auto_yaw_right_1lb) > 0.0  && !doSound[9]) {
				doSound[9] = true;
				bDoSound = true;
		}
		if (vessel->GetThrusterGroupLevel(auto_roll_left_1lb) > 0.0  && !doSound[10]) {
				doSound[10] = true;
				bDoSound = true;
		}
		if (vessel->GetThrusterGroupLevel(auto_roll_right_1lb) > 0.0 && !doSound[11]) {
				doSound[11] = true;
				bDoSound = true;
		}

		if (vessel->GetThrusterGroupLevel(man_pitch_up) > 0.0   && !doSound[12]) {
				doSound[12] = true;
				bDoSound = true;
		}
		if (vessel->GetThrusterGroupLevel(man_pitch_down) > 0.0 && !doSound[13]) {
				doSound[13] = true;
				bDoSound = true;
		}
		if (vessel->GetThrusterGroupLevel(man_yaw_left) > 0.0   && !doSound[14]) {
				doSound[14] = true;
				bDoSound = true;
		}
		if (vessel->GetThrusterGroupLevel(man_yaw_right) > 0.0  && !doSound[15]) {
				doSound[15] = true;
				bDoSound = true;
		}
		if (vessel->GetThrusterGroupLevel(man_roll_left) > 0.0  && !doSound[16]) {
				doSound[16] = true;
				bDoSound = true;
		}
		if (vessel->GetThrusterGroupLevel(man_roll_right) > 0.0 && !doSound[17]) {
				doSound[17] = true;
				bDoSound = true;
		}

		if (bDoSound)
			//PlayVesselWave(VESSELSOUND1);


		if (vessel->GetThrusterGroupLevel(auto_pitch_up) == 0.0   && doSound[0]) doSound[0] = false;
		if (vessel->GetThrusterGroupLevel(auto_pitch_down) == 0.0 && doSound[1]) doSound[1] = false;
		if (vessel->GetThrusterGroupLevel(auto_yaw_left) == 0.0   && doSound[2]) doSound[2] = false;
		if (vessel->GetThrusterGroupLevel(auto_yaw_right) == 0.0  && doSound[3]) doSound[3] = false;
		if (vessel->GetThrusterGroupLevel(auto_roll_left) == 0.0  && doSound[4]) doSound[4] = false;
		if (vessel->GetThrusterGroupLevel(auto_roll_right) == 0.0 && doSound[5]) doSound[5] = false;

		if (vessel->GetThrusterGroupLevel(auto_pitch_up_1lb) == 0.0   && doSound[6]) doSound[6] = false;
		if (vessel->GetThrusterGroupLevel(auto_pitch_down_1lb) == 0.0 && doSound[7]) doSound[7] = false;
		if (vessel->GetThrusterGroupLevel(auto_yaw_left_1lb) == 0.0   && doSound[8]) doSound[8] = false;
		if (vessel->GetThrusterGroupLevel(auto_yaw_right_1lb) == 0.0  && doSound[9]) doSound[9] = false;
		if (vessel->GetThrusterGroupLevel(auto_roll_left_1lb) == 0.0  && doSound[10]) doSound[10] = false;
		if (vessel->GetThrusterGroupLevel(auto_roll_right_1lb) == 0.0 && doSound[11]) doSound[11] = false;

		if (vessel->GetThrusterGroupLevel(man_pitch_up) == 0.0   && doSound[12]) doSound[12] = false;
		if (vessel->GetThrusterGroupLevel(man_pitch_down) == 0.0 && doSound[13]) doSound[13] = false;
		if (vessel->GetThrusterGroupLevel(man_yaw_left) == 0.0   && doSound[14]) doSound[14] = false;
		if (vessel->GetThrusterGroupLevel(man_yaw_right) == 0.0  && doSound[15]) doSound[15] = false;
		if (vessel->GetThrusterGroupLevel(man_roll_left) == 0.0  && doSound[16]) doSound[16] = false;
		if (vessel->GetThrusterGroupLevel(man_roll_right) == 0.0 && doSound[17]) doSound[17] = false;


	} */
}

void Mercury_Capsule::TimestepTelemetry(VESSEL *vessel, double simt){
	/*double tempD = 0.0;

	if (   retro_fired1 
		&& retro_fired2
		&& retro_fired3 
       )
		OutputValue("merc", "capretrofire", 1.0);
	else
		OutputValue("merc", "capretrofire", 0.0);

	if (retro_in_attitude)
		OutputValue("merc", "capretroatt", 1.0);
	else
		OutputValue("merc", "capretroatt", 0.0);

	if (bRetroJettisoned)
		OutputValue("merc", "capretrojett", 1.0);
	else
		OutputValue("merc", "capretrojett", 0.0);

	if (GetValue("merc", "cretroatt") == 1.0) {
		OutputValue("merc", "cretroatt", 0.0);
		ascs_mode = ASCS_RETROGRADE;
	}*/
}

void Mercury_Capsule::TimestepAnimation(VESSEL *vessel, double simt){

	if (drogue_moving) {
		double ct = oapiGetSimStep();
		double ca = ct * CHUTE_OPERATING_SPEED;
		//sprintf(oapiDebugString(),"Reef Time %f %f", ct, chute_reefed);
		if (drogue_status == DROGUE_OPENING) {
			if (drogue_endanim) {
				drogue_status = DROGUE_REEFED;
				drogue_reefed = oapiGetSimTime();
				//chute_moving = true;
				drogue_endanim = false;
				vessel->UnregisterAnimation();
				if ( MERCURY_CHUTE_DROGUE * 0.12 <2.8 )
					vessel->SetCrossSections (_V(2.8,2.8,2.8));
				else
					vessel->SetCrossSections (_V(2.8,2.8,MERCURY_CHUTE_DROGUE * 0.12));
				vessel->SetCW (1.5, 1.5, .3, 0.3);
			} else if ((drogue_proc += ca) >= 1.0) {
				drogue_proc   = 1.0;
				drogue_endanim = true;
			} else {
				if (MERCURY_CHUTE_DROGUE * 0.12 * drogue_proc < 2.8) 
					vessel->SetCrossSections (_V(2.8,2.8,2.8));
				else
					vessel->SetCrossSections (_V(2.8,2.8,MERCURY_CHUTE_DROGUE * 0.12 * drogue_proc));
			}
		} else if(drogue_status == DROGUE_REEFED && oapiGetSimTime() - drogue_reefed > 0.0) {
			drogue_status = DROGUE_UNREEFING;
			vdrogue_proc = 0.12;
			drogue_proc = 0.12;
			vessel->RegisterAnimation();
		} else if (drogue_status == DROGUE_UNREEFING) {
			if (drogue_endanim) {
				drogue_status = DROGUE_OPENED;
				drogue_moving = false;
				drogue_endanim = false;
				vessel->UnregisterAnimation();
				vessel->SetCrossSections (_V(2.8,2.8,MERCURY_CHUTE_DROGUE));
				vessel->SetCW (1.5, 1.5, .3, 0.3);
			} else if ((drogue_proc += ca) >= 1.0) {
				drogue_proc   = 1.0;
				drogue_endanim = true;
			} else {
				if ((MERCURY_CHUTE_DROGUE- (MERCURY_CHUTE_DROGUE * 0.12)) * drogue_proc + (MERCURY_CHUTE_DROGUE * 0.12) < 2.8) 
					vessel->SetCrossSections (_V(2.8,2.8,2.8));
				else
					vessel->SetCrossSections (_V(2.8,2.8,(MERCURY_CHUTE_DROGUE- (MERCURY_CHUTE_DROGUE * 0.12)) * drogue_proc + (MERCURY_CHUTE_DROGUE * 0.12)));
			}
		}
	}
	if (chute_moving) {
		double ct = oapiGetSimStep();
		double ca = ct * CHUTE_OPERATING_SPEED;
		//sprintf(oapiDebugString(),"Reef Time %f %f", ct, chute_reefed);
		if (chute_status == CHUTE_OPENING) {
			if (chute_endanim) {
				chute_status = CHUTE_REEFED;
				chute_reefed = oapiGetSimTime();
				//chute_moving = true;
				chute_endanim = false;
				vessel->UnregisterAnimation();
				if ( MERCURY_CHUTE_MAIN * 0.12 <2.8 )
					vessel->SetCrossSections (_V(2.8,2.8,2.8));
				else
					vessel->SetCrossSections (_V(2.8,2.8,MERCURY_CHUTE_MAIN * 0.12));
				vessel->SetCW (1.5, 1.5, .3, 0.3);
			} else if ((chute_proc += ca) >= 1.0) {
				chute_proc   = 1.0;
				chute_endanim = true;
			} else {
				if (MERCURY_CHUTE_MAIN * 0.12 * chute_proc < 2.8) 
					vessel->SetCrossSections (_V(2.8,2.8,2.8));
				else
					vessel->SetCrossSections (_V(2.8,2.8,MERCURY_CHUTE_MAIN * 0.12 * chute_proc));
			}
		} else if(chute_status == CHUTE_REEFED && oapiGetSimTime() - chute_reefed > 4.0) {
			chute_status = CHUTE_UNREEFING;
			vchute_proc = 0.12;
			chute_proc = 0.12;
			vessel->RegisterAnimation();
		} else if (chute_status == CHUTE_UNREEFING) {
			if (chute_endanim) {
				chute_status = CHUTE_OPENED;
				chute_moving = false;
				chute_endanim = false;
				vessel->UnregisterAnimation();
				vessel->SetCrossSections (_V(2.8,2.8,MERCURY_CHUTE_MAIN));
				vessel->SetCW (1.5, 1.5, .3, 0.3);
			} else if ((chute_proc += ca) >= 1.0) {
				chute_proc   = 1.0;
				chute_endanim = true;
			} else {
				if ((MERCURY_CHUTE_MAIN- (MERCURY_CHUTE_MAIN * 0.12)) * chute_proc + (MERCURY_CHUTE_MAIN * 0.12) < 2.8)
					vessel->SetCrossSections (_V(2.8,2.8,2.8));
				else
					vessel->SetCrossSections (_V(2.8,2.8,(MERCURY_CHUTE_MAIN- (MERCURY_CHUTE_MAIN * 0.12)) * chute_proc + (MERCURY_CHUTE_MAIN * 0.12)));
			}
		}
	}

	if (lb_moving) {
		double ct = oapiGetSimStep();
		double ca = ct * LB_OPERATING_SPEED;
		if (lb_status == LB_OPENING) {
			if (lb_endanim) {
				lb_status = LB_OPENED;
				lb_moving  = false;
				lb_endanim = false;
				vessel->UnregisterAnimation();
			} else if ((lb_proc += ca) >= 1.0) {
				lb_proc   = 1.0;
				lb_endanim = true;
			}
		}
	}
	if (chute_status == CHUTE_DEPLOYED) {
		OpenChute(vessel);
	};

	if (drogue_status == DROGUE_DEPLOYED) {
		OpenDrogue(vessel);
	};

	if (lb_status == LB_DEPLOYED) {
		OpenLandingBag(vessel);
	};
}

void Mercury_Capsule::DoAbortSequence(VESSEL *vessel, double simt){
	bDonePosigrade = true;
		 
	if (   (   vessel->GetPropellantMass(fuel_abort) == 0
			&& ControlPanel->TowerSepContrlFuse != FUSE_OFF 
	        && ControlPanel->EmerTowerSepFuse != FUSE_OFF
		    && ControlPanel->EmerTowerJettFuse != FUSE_OFF
			&& ControlPanel->Failure != FAIL_ABORT_TOWER_JETT
		   )
	    || (   vessel->GetPropellantMass(fuel_abort) == 0
			&& ControlPanel->TowerSepContrlFuse == FUSE_TWO 
	        && ControlPanel->EmerTowerSepFuse == FUSE_TWO 
		    && ControlPanel->EmerTowerJettFuse == FUSE_TWO
		   )
	    )
	{
		ControlPanel->AbortJettisoned();
		vessel->SetThrusterGroupLevel(group_abort,0.0);
		JettisonTowerAbort(vessel);
		ControlPanel->RetroJett(false);
		vessel->SetThrusterGroupLevel(group_RetroPyro, 1.0);
		bRetroJettisoned = true;
		JettisonRetro(vessel);
		if (vessel->GetAtmPressure() > 68000)
		{
			bDrogueDeployed = true;
			bDrogueJettisoned=true;
			bDeployMainChute=true;
			JettisonAntenna(vessel);
			SetCapsuleMain(vessel);
		} else {
			SetCapsule(vessel);
		}
		ascs_mode = ASCS_LANDING;
		vessel->SetThrusterGroupLevel(auto_roll_right, 0.0);
		bAbortJettisoned = true;
	}

}
void Mercury_Capsule::DoLandingSequence(VESSEL *vessel, double simt){
	
	if (   (  (   vessel->GetAtmPressure() > 40000 
		       && ControlPanel->Failure != FAIL_DROGUE 
			   && ControlPanel->EmerDrougeDeployFuse != FUSE_OFF
			  ) 
		    || 
			  (   ControlPanel->push_drogue == PUSH_DOWN 
			   && ControlPanel->Failure != FAIL_DROGUE 
			   && ControlPanel->EmerDrougeDeployFuse != FUSE_OFF
			  )
		    || 
		      (   ControlPanel->push_drogue == PUSH_DOWN 
			   && ControlPanel->EmerDrougeDeployFuse == FUSE_TWO
			  )
		   ) 
		 && !bDrogueDeployed 
		 && PressDelta < 0
	  )
	{
		bDrogueDeployed = true;
		DeployDrogue(vessel);
	};

	if (   (   vessel->GetAtmPressure() > 68000 
		    && ControlPanel->Failure != FAIL_MAIN 
			&& ControlPanel->EmerMainDeployFuse != FUSE_OFF
		   ) 
		|| (   ControlPanel->EmerMainDeployFuse != FUSE_OFF 
		    && ControlPanel->switch_main 
			&& ControlPanel->Failure != FAIL_MAIN
		   ) 
		|| (   ControlPanel->EmerMainDeployFuse == FUSE_TWO 
		    && ControlPanel->switch_main 
		   ) 
	   ) 
	{		
		if (!bMainDeployed && PressDelta < 0 && bDeployMainChute)
		{
			ControlPanel->MainChute();
			bMainDeployed=true;
			DeployMain(vessel);
		};


		if (!bDeployMainChute && PressDelta < 0)
		{
			bDeployMainChute=true;
			SetCapsuleMain(vessel);
		};

		if (!bDrogueJettisoned && PressDelta < 0)
		{
			bDrogueJettisoned=true;
			JettisonDrogue(vessel);
			drogue_proc = 0.0;
			SetCapsuleMain(vessel);
		};
	}

	if (bDeployMainChute && !bLandingBagDeployed && ControlPanel->switch_landingbag == LB_MAN)
	{
		bLandingBagDeployed =true;
		lb_status = LB_DEPLOYED;
		if ((bMainDeployed && !bMainJettisoned) || (bBackupDeployed && !bBackupJettisoned) )
			//AddChute(vessel);
			AddLandingBag(vessel);
		else if (bDrogueDeployed && !bDrogueJettisoned)
			AddDrogue(vessel);
		else if (bDrogueJettisoned)
			SetCapsuleMain(vessel);
		else
			SetCapsule(vessel);
		ControlPanel->LandingBag();
	}

	if (   bDeployMainChute 
		&& !bLBTimerActive 
		&& ControlPanel->switch_landingbag == LB_AUTO 
		&& !bLandingBagDeployed 
		&& ControlPanel->Failure != FAIL_LAND_BAG
	   )
	{
		bLBTimerActive = true;
		landingbag_timer = simt;
	}
	if (bMainDeployed && simt - landingbag_timer > 12.0 && bLBTimerActive && !bLandingBagDeployed)
	{
		bLBTimerActive = false;
		bLandingBagDeployed=true;
		lb_status = LB_DEPLOYED;
		ControlPanel->LandingBag();
		//AddChute(vessel);
		AddLandingBag(vessel);
	} else if (bMainDeployed && simt - landingbag_timer > 10.0 && bLBTimerActive && !bLandingBagDeployed) {
		ControlPanel->LandingBagWarn();
	}

	if ((bParachute || ControlPanel->switch_reserve) && !bBackupDeployed && bMainJettisoned && PressDelta < 0)
	{
		bBackupDeployed=true;
		DeployMain(vessel);
	};


	if ((bParachuteJettisoned) && (bMainDeployed || bBackupDeployed || bDrogueDeployed))
	{
		bParachuteJettisoned=false;
		SepParachute(vessel, true);
	};

	double altitude=0;
	oapiGetAltitude(vessel->GetHandle(),&altitude);
	if (altitude < 3 && !bSplashdown) {
		if (bMainDeployed && !bMainJettisoned) {
			bSplashdown = true;
			SepParachute(vessel, false);
			//PlayVesselWave(SOUND_SPLASHDOWN);
		} else if (bBackupDeployed && !bBackupJettisoned) {
			bSplashdown = true;
			SepParachute(vessel, false);
			//PlayVesselWave(SOUND_SPLASHDOWN);
		}
	}

	if (altitude > 3 && bSplashdown) {
		vessel->ActivateNavmode(NAVMODE_HOLDALT);
	}

}

void Mercury_Capsule::DoRetroSequence(VESSEL *vessel, double simt){
	double cur_time   = simt - ControlPanel->clock_simt;

	if (   !bDonePosigrade 
		&& ControlPanel->EmerPosgrdFuse != FUSE_OFF
       )
	{
		vessel->SetThrusterGroupLevel(group_posigrade,1.0);
		vessel->SetThrusterGroupLevel(group_adaptPyro,1.0);
		bDonePosigrade = true;
	}

	if (   ( cur_time >= ControlPanel->retro_simt 
		     && ControlPanel->Failure != FAIL_RETRO_SEQ 
			 && !RetroDelay
		   ) 
	       || (    ControlPanel->push_retrosequence == PUSH_DOWN 
			    && ControlPanel->EmerRetroSeqFuse != FUSE_OFF
				&& !RetroDelay
   		        && ControlPanel->Failure != FAIL_RETRO_SEQ 
			  )
	       || (    ControlPanel->push_retrosequence == PUSH_DOWN 
			    && ControlPanel->EmerRetroSeqFuse == FUSE_TWO
				&& !RetroDelay
			  )/*

		   || (    GetValue("merc", "cretroseq") == 1.0
		        && ControlPanel->Failure != FAIL_RETRO_SEQ 
  			    && !RetroDelay
		      )*/
	    )
	{
		RetroDelay = true;
		retro_seq_timer = simt;
		ascs_mode = ASCS_RETROGRADE;
		ControlPanel->RetroSequence();
		if (   ControlPanel->switch_retrodelay == RETRO_INST 
			&& ControlPanel->Failure != FAIL_RETRO_FIRE
		   )
		{
			DoRetroFire     = true;
			retro_timer2 = simt;
			retro_timer3 = simt;
			DoAttPermission = true;
			ControlPanel->RetroFire(SEQ_RED);
			ControlPanel->RetroWarn(WARN_ON);
		}
	}

	if (RetroDelay) {
		if (   simt - retro_seq_timer > 30.0 
			&& !DoRetroFire 
			&& ControlPanel->Failure != FAIL_RETRO_FIRE
		   )
		{
			DoRetroFire     = true;
			retro_timer2 = simt;
			retro_timer3 = simt;
		}

		if ( simt - retro_seq_timer > 20.0 && !DoRetroFire) {
			ControlPanel->RetroFire(SEQ_RED);
			ControlPanel->RetroWarn(WARN_ON);
		}

		if ( simt - retro_seq_timer > 10.0 && !DoAttPermission)
			DoAttPermission = true;
	}

	if (   ControlPanel->push_retrofire == PUSH_DOWN 
		&& ControlPanel->RetroManFuse != FUSE_OFF
	   )
	{
		ascs_mode = ASCS_RETROGRADE;
		if (   ControlPanel->switch_retroattitude == RETROATT_BYPASS
			/*|| GetValue("merc", "cretrobypass") == 1.0*/
		   )
		{
			DoEmerRetroFire = true;
			retro_timer2 = simt;
			retro_timer3 = simt;
			ControlPanel->RetroFire(SEQ_RED);
			ControlPanel->RetroWarn(WARN_ON);
		} else if (ControlPanel->switch_retroattitude == RETROATT_AUTO) {
			DoRetroFire     = true;
			retro_timer2 = simt;
			retro_timer3 = simt;
			RetroDelay = true;
			DoAttPermission = true;
			ControlPanel->RetroFire(SEQ_RED);
			ControlPanel->RetroWarn(WARN_ON);
		}

	}

	if (DoAttPermission) {
		bool abort_retro = false;

		if (ControlPanel->x_pitch_heading < 313*RAD || ControlPanel->x_pitch_heading > 343*RAD)
			abort_retro = true;

		if (ControlPanel->y_yaw_heading < 345*RAD && ControlPanel->y_yaw_heading > 15*RAD)
			abort_retro = true;

		
		if (abort_retro) {
			ControlPanel->RetroAttitude(false);
			retro_in_attitude = false;
		} else {
			retro_in_attitude = true;
			ControlPanel->RetroAttitude(true);
		}


	}



	if (   (   ControlPanel->RetroOneFuse == FUSE_TWO 
		    || (   ControlPanel->Failure != FAIL_RETRO_FIRE 
			    && ControlPanel->RetroOneFuse == FUSE_ONE
			   )
		   )
		 & (DoEmerRetroFire || DoRetroFire) && !retro_fire1) 
	{
		retro_fire1 = true;
	} else {
		retro_fire1 = false;
	}

	if (   (   ControlPanel->RetroTwoFuse == FUSE_TWO 
		    || (   ControlPanel->Failure != FAIL_RETRO_FIRE 
			    && ControlPanel->RetroTwoFuse == FUSE_ONE
			   )
		   )
		 & (DoEmerRetroFire || DoRetroFire) && !retro_fire1) 
	{
		retro_fire2 = true;
	} else {
		retro_fire2 = false;
	}

	if (   (   ControlPanel->RetroThreeFuse == FUSE_TWO 
		    || (   ControlPanel->Failure != FAIL_RETRO_FIRE 
			    && ControlPanel->RetroThreeFuse == FUSE_ONE
			   )
		   )
		 & (DoEmerRetroFire || DoRetroFire) && !retro_fire1) 
	{
		retro_fire3 = true;
	} else {
		retro_fire3 = false;
	}

	if (!retro_in_attitude){
		retro_fire1 = false;
		retro_fire2 = false;
		retro_fire3 = false;
	}

	if (retro_fire1 && !retro_fired1 ) {
		JettisonRetroCover1(vessel);
		SetCapsuleWithRetroC2(vessel,true);
		vessel->SetThrusterGroupLevel(group_retro[0],1.0);
		retro_fired1 = true;
	}

	if (retro_fire2 && !retro_fired2 && simt-retro_timer2 >= 5) {
		JettisonRetroCover2(vessel);
		SetCapsuleWithRetroC1(vessel,true);
		vessel->SetThrusterGroupLevel(group_retro[1],1.0);
		retro_fired2 = true;
	}

	if (retro_fire3 && !retro_fired3 && simt-retro_timer3 >= 10) {
		JettisonRetroCover3(vessel);
		SetCapsuleWithRetroC0(vessel,true);
		vessel->SetThrusterGroupLevel(group_retro[2],1.0);
		retro_fired3 = true;
		ControlPanel->RetroFire(SEQ_GREEN);
	}

}


void Mercury_Capsule::DoRetroPack(VESSEL *vessel, double simt){
	if (!bRetroJettisoned) {
		DoRetroSequence(vessel,simt);
	}
	
	if (   (   DoRetroFire 
		    || DoEmerRetroFire
		   )
		&& !bDoAutoRetroJettison 
		&& ControlPanel->Failure != FAIL_RETRO_JETT
	   )
	{
		bDoAutoRetroJettison = true;
		retro_jett_timer =simt;
	}

	if (   bDoAutoRetroJettison 
		&& simt - retro_jett_timer > 60.0 
		&& !bRetroSeparate 
		&& ControlPanel->switch_retroautojett
	   )
		bRetroSeparate = true;

	if (bDoAutoRetroJettison && simt - retro_jett_timer > 58.0 && !bRetroSeparate)
		ControlPanel->RetroJett(true);
	
	if (   ControlPanel->push_retrojett == PUSH_DOWN 
		&& ControlPanel->RetroJettFuse != FUSE_OFF 
	   ) 
	{
		bRetroSeparate = true;
	}

	if (bRetroSeparate && !ControlPanel->switch_squib) {
		bRetroSeparate = false;
		bDoAutoRetroJettison = false;
		ControlPanel->RetroJett(true);
	}

	if (   bRetroSeparate 
		&& !bRetroJettisoned 
		&& (   ControlPanel->Failure != FAIL_RETRO_JETT 
		    || ControlPanel->EmerRetroJettFuse == FUSE_TWO
		   )
		)
	{
		bRetroSeparate=false;
		ControlPanel->RetroJett(false);
		vessel->SetThrusterGroupLevel(group_RetroPyro, 1.0);
		JettisonRetro(vessel);
		bRetroJettisoned = true;
		SetCapsule(vessel);
		ControlPanel->RetroFire(SEQ_CLEAR);
	}
}


void Mercury_Capsule::Timestep (VESSEL *vessel, double simt)
{
	int i = 0;
	double cur_time   = simt - ControlPanel->clock_simt;

	PressDelta = LastPress - vessel->GetAtmPressure();
	LastPress  = vessel->GetAtmPressure();


	if (PressDelta < 0) {
		vessel->SetPitchMomentScale (-1e-2);
		vessel->SetBankMomentScale (-1e-2);
	} else {
		vessel->SetPitchMomentScale (0);
		vessel->SetBankMomentScale (0);
	}

	if(ControlPanel->switch_snorkel == true)
		ControlPanel->O2EmergWarn(WARN_ON);


	

	DoASCS(vessel, simt);

	DoCapsuleThrusters(vessel);

	TimestepAnimation(vessel, simt);



	if (bRetroJettisoned && bAbortJettisoned) 
		DoLandingSequence(vessel, simt);

	if (!bAbortJettisoned) 
		DoAbortSequence(vessel, simt);

	if (!bRetroJettisoned) 
		DoRetroPack(vessel, simt);

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
			//vessel->SetMeshVisibilityMode(filter_mesh_number, 0);
			f_status = F_LEFT;
		}
	}

	TimestepTelemetry(vessel, simt);

	if (ControlPanel->long_accel < -1.5) {
		//PlayVesselWave(SOUND_RE_RATTLE, LOOP);
	} else {
		//if (IsPlaying(SOUND_RE_RATTLE))
		//	StopVesselWave(SOUND_RE_RATTLE);
	}

	last_simt = simt;
}

void Mercury_Capsule::DoAuxDamp (VESSEL *vessel, double simt)
{
	VECTOR3 ang_vel = {0.0, 0.0, 0.0};
	if (ControlPanel->switch_maneuver)
		vessel->GetAngularVel(ang_vel);
	if (ControlPanel->switch_rscs == RSCS_AUTO)
	{
		if (ang_vel.x > .009)
			vessel->SetThrusterGroupLevel(auto_pitch_down, 1.0);
		else
			vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);

		if (ang_vel.x < -.009)
			vessel->SetThrusterGroupLevel(auto_pitch_up, 1.0);
		else
			vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
		if (ang_vel.y > .009)
			vessel->SetThrusterGroupLevel(auto_yaw_right, 1.0);
		else
			vessel->SetThrusterGroupLevel(auto_yaw_right, 0.0);
		if (ang_vel.y < -.009)
			vessel->SetThrusterGroupLevel(auto_yaw_left, 1.0);
		else
			vessel->SetThrusterGroupLevel(auto_yaw_left, 0.0);
		if (ang_vel.z > .009)
			vessel->SetThrusterGroupLevel(auto_roll_left, 1.0);
		else
			vessel->SetThrusterGroupLevel(auto_roll_left, 0.0);
		if (ang_vel.z < -.009)
			vessel->SetThrusterGroupLevel(auto_roll_right, 1.0);
		else
			vessel->SetThrusterGroupLevel(auto_roll_right, 0.0);
	}
}

void Mercury_Capsule::DoASCS (VESSEL *vessel, double simt)
{
	int i = 0;
	double x_rate = 0.0;
	double y_rate = 0.0;
	double z_rate = 0.0;
	double tempD = 0.0;
	VECTOR3 ang_vel = {0.0, 0.0, 0.0};
	if (ControlPanel->switch_maneuver)
		vessel->GetAngularVel(ang_vel);
	tempD = vessel->GetPitch() * DEG;
	
	if (ControlPanel->ACBusSwitch == SWITCH_MIDDLE)
		return;
	
	if (ControlPanel->pull_manualmode == MANUAL_RATECMD && ControlPanel->switch_rscs == RSCS_RATE) {
		x_rate = RSCS_MAXRATE * vessel->GetManualControlLevel(THGROUP_ATT_PITCHUP, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE);
		if (x_rate == 0)
			x_rate = RSCS_MAXRATE * -vessel->GetManualControlLevel(THGROUP_ATT_PITCHDOWN, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE);
		x_rate -= .001175;
		y_rate = RSCS_MAXRATE * vessel->GetManualControlLevel(THGROUP_ATT_YAWLEFT, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE); 
		if (y_rate == 0)
			y_rate = RSCS_MAXRATE * -vessel->GetManualControlLevel(THGROUP_ATT_YAWRIGHT, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE);
		z_rate = RSCS_MAXRATE * -vessel->GetManualControlLevel(THGROUP_ATT_BANKLEFT, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE);
		if (z_rate == 0)
			z_rate = RSCS_MAXRATE * vessel->GetManualControlLevel(THGROUP_ATT_BANKRIGHT, MANCTRL_ANYDEVICE, MANCTRL_ANYMODE);

		if (ang_vel.x > x_rate +.002)
			vessel->SetThrusterGroupLevel(man_pitch_down, 1.0);
		else
			vessel->SetThrusterGroupLevel(man_pitch_down, 0.0);
		if (ang_vel.x < x_rate -.002)
			vessel->SetThrusterGroupLevel(man_pitch_up, 1.0);
		else
			vessel->SetThrusterGroupLevel(man_pitch_up, 0.0);

		if (ang_vel.y > y_rate + .002)
			vessel->SetThrusterGroupLevel(man_yaw_right, 1.0);
		else
			vessel->SetThrusterGroupLevel(man_yaw_right, 0.0);
		if (ang_vel.y < y_rate - .002)
			vessel->SetThrusterGroupLevel(man_yaw_left, 1.0);
		else
			vessel->SetThrusterGroupLevel(man_yaw_left, 0.0);

		if (ang_vel.z > z_rate +.002)
			
			vessel->SetThrusterGroupLevel(man_roll_left, 1.0);
		else
			vessel->SetThrusterGroupLevel(man_roll_left, 0.0);
		if (ang_vel.z < z_rate -.002)
			vessel->SetThrusterGroupLevel(man_roll_right, 1.0);
		else
			vessel->SetThrusterGroupLevel(man_roll_right, 0.0);
	} else if (ControlPanel->switch_rscs == RSCS_AUTO && ControlPanel->switch_automaticmode == AUTO_AUXDAMP) {
		DoAuxDamp(vessel, simt);
	} else if (ControlPanel->switch_automaticmode == AUTO_ASCS && ControlPanel->switch_rscs == RSCS_AUTO) {
		if (ascs_mode == ASCS_POSIDAMP)
			DoPosigradeDamping(vessel, simt);
		else if (ascs_mode == ASCS_TURNAROUND)
			DoTurnAround(vessel, simt);
		else if (ascs_mode == ASCS_INITIAL_ATT)
			DoHighTorqueAttitude(vessel, simt);
		else if (ascs_mode == ASCS_ORBITAL_ATT)
			DoLowTorqueAttitude(vessel, simt);
		else if (ascs_mode == ASCS_RETROGRADE)
			DoHighTorqueAttitude(vessel, simt);
		else if (ascs_mode == ASCS_REENTRY_ATT) 
			DoHighTorqueAttitude(vessel, simt);
		else if (ascs_mode == ASCS_05G_ROLL)
			Do05Roll(vessel,simt);
	}

	if (ascs_mode == ASCS_SLAVE_SCAN) {
		ascs_mode = ASCS_POSIDAMP;
	} else if (ascs_mode == ASCS_POSIDAMP) {
		if (bDonePosigradeDamp && bDonePosigrade && simt - PosigradeDampTimer > 5.0)
			ascs_mode = ASCS_TURNAROUND;
	} else if (ascs_mode == ASCS_TURNAROUND) {
		if (ControlPanel->y_yaw_heading > 359.5*RAD || ControlPanel->y_yaw_heading < 0.5) {
			ascs_mode = ASCS_INITIAL_ATT;
			init_att_time = oapiGetSimTime();
		}
	} else if (ascs_mode == ASCS_INITIAL_ATT) {
		if ((oapiGetSimTime() - init_att_time > 270.0) || bRetroJettisoned)
			ascs_mode = ASCS_ORBITAL_ATT;
	} else if (ascs_mode == ASCS_ORBITAL_ATT) {
		if (retro_seq > 0 || bRetroJettisoned)
			ascs_mode = ASCS_RETROGRADE;
	} else if (ascs_mode == ASCS_RETROGRADE) {
		if (bRetroJettisoned)
			ascs_mode = ASCS_REENTRY_ATT;
	} else if (ascs_mode == ASCS_REENTRY_ATT) {
		if (   (   (   ControlPanel->long_accel < -.05 
			        || ControlPanel->push_05G == PUSH_DOWN
				   ) 
				&& ControlPanel->Failure != FAIL_05G_ROLL
			   ) 
		    || (   ControlPanel->push_05G == PUSH_DOWN 
			    && ControlPanel->Emer05GFuse == FUSE_TWO 
				&& ControlPanel->ASCS05GFuse == FUSE_TWO
			   )
		    || (   ControlPanel->push_05G == PUSH_DOWN 
			    && ControlPanel->Emer05GFuse != FUSE_OFF 
				&& ControlPanel->ASCS05GFuse != FUSE_OFF
				&& ControlPanel->Failure != FAIL_05G_ROLL
			   )
			)
		{
			ascs_mode = ASCS_05G_ROLL;
			ControlPanel->Roll05G();
		}
	} else if (ascs_mode == ASCS_05G_ROLL) {
		if (bMainDeployed) {
			ascs_mode = ASCS_LANDING;
			vessel->SetThrusterGroupLevel(auto_roll_right, 0.0);
		}
	}
	

	if (ControlPanel->Emer05GFuse == FUSE_TWO && ControlPanel->ASCS05GFuse == FUSE_TWO) {
		ascs_mode = ASCS_05G_ROLL;
		ControlPanel->Roll05G();
	}
		
}

void Mercury_Capsule::DoPosigradeDamping(VESSEL *vessel, double simt)
{
	if (!bDonePosigradeDamp)
	{
		PosigradeDampTimer = simt;
		bDonePosigradeDamp = true;
	} else 
		DoAuxDamp(vessel, simt);
}

void Mercury_Capsule::DoTurnAround(VESSEL *vessel, double simt)
{
	VECTOR3 ang_vel = {0.0, 0.0, 0.0};
	if (ControlPanel->switch_maneuver)
		vessel->GetAngularVel(ang_vel);
	double auto_vel = 0.0;
	double tempD = 0.0;
	if (ControlPanel->y_yaw_heading < 359.5*RAD && ControlPanel->y_yaw_heading > 0.5*RAD)
	{/*
		if (ControlPanel->y_yaw_heading < 160*RAD) // YAW RIGHT 
		{
			if (ControlPanel->y_yaw_heading > 10*RAD)
				auto_vel = 10*RAD;
			else if (ControlPanel->y_yaw_heading > 5*RAD)
				auto_vel = 5*RAD;
			else
				auto_vel = .5*RAD;
			if (ang_vel.y < 0) {
				vessel->SetThrusterGroupLevel(auto_yaw_left, 1.0);
				vessel->SetThrusterGroupLevel(auto_yaw_right, 0.0);
			} else if (ang_vel.y > 0 && ang_vel.y < auto_vel ) {
				vessel->SetThrusterGroupLevel(auto_yaw_left, 1.0);
				vessel->SetThrusterGroupLevel(auto_yaw_right, 0.0);
			} else if (ang_vel.y > 0 && ang_vel.y >= auto_vel ) {
				vessel->SetThrusterGroupLevel(auto_yaw_left, 0.0);
				vessel->SetThrusterGroupLevel(auto_yaw_right, 0.0);
			}

		} else { //YAW LEFT*/
			if (ControlPanel->y_yaw_heading < 350*RAD)
				auto_vel = -10*RAD;
			else if (ControlPanel->y_yaw_heading < 355*RAD)
				auto_vel = -5*RAD;
			else
				auto_vel = -.5*RAD;
			if (ang_vel.y > 0) {
				vessel->SetThrusterGroupLevel(auto_yaw_left, 0.0);
				vessel->SetThrusterGroupLevel(auto_yaw_right, 1.0);
			} else if (ang_vel.y < 0 && ang_vel.y > auto_vel ) {
				vessel->SetThrusterGroupLevel(auto_yaw_left, 0.0);
				vessel->SetThrusterGroupLevel(auto_yaw_right, 1.0);
			} else if (ang_vel.y < 0 && ang_vel.y <= auto_vel ) {
				vessel->SetThrusterGroupLevel(auto_yaw_left, 0.0);
				vessel->SetThrusterGroupLevel(auto_yaw_right, 0.0);
			}
		//}
	} else {
		vessel->SetThrusterGroupLevel(auto_yaw_left, 0.0);
		vessel->SetThrusterGroupLevel(auto_yaw_right, 0.0);
		if (ang_vel.y > .002) {
			vessel->SetThrusterGroupLevel(auto_yaw_left_1lb, 0.0);
			vessel->SetThrusterGroupLevel(auto_yaw_right_1lb, 1.0);
		} else if (ang_vel.y < -.002) {
			vessel->SetThrusterGroupLevel(auto_yaw_left_1lb, 1.0);
			vessel->SetThrusterGroupLevel(auto_yaw_right_1lb, 0.0);
		} else {
			vessel->SetThrusterGroupLevel(auto_yaw_left_1lb, 0.0);
			vessel->SetThrusterGroupLevel(auto_yaw_right_1lb, 0.0);
		}
	}

}
void Mercury_Capsule::DoHighTorqueAttitude(VESSEL *vessel, double simt)
{
	VECTOR3 ang_vel = {0.0, 0.0, 0.0};
	if (ControlPanel->switch_maneuver)
		vessel->GetAngularVel(ang_vel);
	double auto_vel = 0.0;
	double tempD = 0.0;
	vessel->SetThrusterGroupLevel(auto_yaw_left, 0.0);
	vessel->SetThrusterGroupLevel(auto_yaw_right, 0.0);
	vessel->SetThrusterGroupLevel(auto_yaw_left_1lb, 0.0);
	vessel->SetThrusterGroupLevel(auto_yaw_right_1lb, 0.0);
	vessel->SetThrusterGroupLevel(auto_roll_left, 0.0);
	vessel->SetThrusterGroupLevel(auto_roll_right, 0.0);
	vessel->SetThrusterGroupLevel(auto_roll_left_1lb, 0.0);
	vessel->SetThrusterGroupLevel(auto_roll_right_1lb, 0.0);
	//ROLL
	if (ControlPanel->z_roll_heading < 359.5*RAD && ControlPanel->z_roll_heading > 0.5*RAD)
	{
		if (ControlPanel->z_roll_heading > 180*RAD) // ROLL LEFT
		{
			if (ControlPanel->z_roll_heading < 350*RAD)
				auto_vel = -5*RAD;
			else if (ControlPanel->z_roll_heading < 355*RAD)
				auto_vel = -2*RAD;
			else
				auto_vel = -.5*RAD;
			if (ang_vel.z > 0) {
				vessel->SetThrusterGroupLevel(auto_roll_left, 1.0);
				vessel->SetThrusterGroupLevel(auto_roll_right, 0.0);
			} else if (ang_vel.z < 0 && ang_vel.z > auto_vel) {
				vessel->SetThrusterGroupLevel(auto_roll_left, 1.0);
				vessel->SetThrusterGroupLevel(auto_roll_right, 0.0);
			} else if (ang_vel.z < 0 && ang_vel.z <= auto_vel) {
				vessel->SetThrusterGroupLevel(auto_roll_left, 0.0);
				vessel->SetThrusterGroupLevel(auto_roll_right, 0.0);
			}

		} else { //ROLL RIGHT
			if (ControlPanel->z_roll_heading > 10*RAD)
				auto_vel = 5*RAD;
			else if (ControlPanel->z_roll_heading > 5*RAD)
				auto_vel = 2*RAD;
			else
				auto_vel = .5*RAD;
			if (ang_vel.z < 0) {
				vessel->SetThrusterGroupLevel(auto_roll_left, 0.0);
				vessel->SetThrusterGroupLevel(auto_roll_right, 1.0);
			} else if (ang_vel.z > 0 && ang_vel.z < auto_vel) {
				vessel->SetThrusterGroupLevel(auto_roll_left, 0.0);
				vessel->SetThrusterGroupLevel(auto_roll_right, 1.0);
			} else if (ang_vel.z > 0 && ang_vel.z >= auto_vel) {
				vessel->SetThrusterGroupLevel(auto_roll_left, 0.0);
				vessel->SetThrusterGroupLevel(auto_roll_right, 0.0);
			}
		}
	} else {
		if (ang_vel.z > .005) {
			vessel->SetThrusterGroupLevel(auto_roll_left, 1.0);
			vessel->SetThrusterGroupLevel(auto_roll_right, 0.0);
		} else if (ang_vel.z < -.005) {
			vessel->SetThrusterGroupLevel(auto_roll_left, 0.0);
			vessel->SetThrusterGroupLevel(auto_roll_right, 1.0);
		} else if (ang_vel.z > .001) {
			vessel->SetThrusterGroupLevel(auto_roll_left_1lb, 1.0);
			vessel->SetThrusterGroupLevel(auto_roll_right_1lb, 0.0);
		} else if (ang_vel.z < -.001) {
			vessel->SetThrusterGroupLevel(auto_roll_left_1lb, 0.0);
			vessel->SetThrusterGroupLevel(auto_roll_right_1lb, 1.0);
		} else {
			vessel->SetThrusterGroupLevel(auto_roll_left_1lb, 0.0);
			vessel->SetThrusterGroupLevel(auto_roll_right_1lb, 0.0);
		}
	}
	if (ControlPanel->y_yaw_heading < 359.5*RAD && ControlPanel->y_yaw_heading > 0.5*RAD)
	{
		if (ControlPanel->y_yaw_heading < 180*RAD) // YAW RIGHT 
		{
			if (ControlPanel->y_yaw_heading > 10*RAD)
				auto_vel = 5*RAD;
			else if (ControlPanel->y_yaw_heading > 5*RAD)
				auto_vel = 2*RAD;
			else
				auto_vel = .5*RAD;
			if (ang_vel.y < 0) {
				vessel->SetThrusterGroupLevel(auto_yaw_left, 1.0);
				vessel->SetThrusterGroupLevel(auto_yaw_right, 0.0);
			} else if (ang_vel.y > 0 && ang_vel.y < auto_vel ) {
				vessel->SetThrusterGroupLevel(auto_yaw_left, 1.0);
				vessel->SetThrusterGroupLevel(auto_yaw_right, 0.0);
			} else if (ang_vel.y > 0 && ang_vel.y >= auto_vel ) {
				vessel->SetThrusterGroupLevel(auto_yaw_left, 0.0);
				vessel->SetThrusterGroupLevel(auto_yaw_right, 0.0);
			}

		} else { //YAW LEFT
			if (ControlPanel->y_yaw_heading < 350*RAD)
				auto_vel = -5*RAD;
			else if (ControlPanel->y_yaw_heading < 355*RAD)
				auto_vel = -2*RAD;
			else
				auto_vel = -.5*RAD;
			if (ang_vel.y > 0) {
				vessel->SetThrusterGroupLevel(auto_yaw_left, 0.0);
				vessel->SetThrusterGroupLevel(auto_yaw_right, 1.0);
			} else if (ang_vel.y < 0 && ang_vel.y > auto_vel ) {
				vessel->SetThrusterGroupLevel(auto_yaw_left, 0.0);
				vessel->SetThrusterGroupLevel(auto_yaw_right, 1.0);
			} else if (ang_vel.y < 0 && ang_vel.y <= auto_vel ) {
				vessel->SetThrusterGroupLevel(auto_yaw_left, 0.0);
				vessel->SetThrusterGroupLevel(auto_yaw_right, 0.0);
			}
		}
	} else {
		vessel->SetThrusterGroupLevel(auto_yaw_left, 0.0);
		vessel->SetThrusterGroupLevel(auto_yaw_right, 0.0);
		vessel->SetThrusterGroupLevel(auto_yaw_left_1lb, 0.0);
		vessel->SetThrusterGroupLevel(auto_yaw_right_1lb, 0.0);
		if (ang_vel.y > .005) {
			vessel->SetThrusterGroupLevel(auto_yaw_left, 0.0);
			vessel->SetThrusterGroupLevel(auto_yaw_right, 1.0);
		} else if (ang_vel.y < -.005) {
			vessel->SetThrusterGroupLevel(auto_yaw_left, 1.0);
			vessel->SetThrusterGroupLevel(auto_yaw_right, 0.0);
		} else if (ang_vel.y > .001) {
			vessel->SetThrusterGroupLevel(auto_yaw_left_1lb, 0.0);
			vessel->SetThrusterGroupLevel(auto_yaw_right_1lb, 1.0);
		} else if (ang_vel.y < -.001) {
			vessel->SetThrusterGroupLevel(auto_yaw_left_1lb, 1.0);
			vessel->SetThrusterGroupLevel(auto_yaw_right_1lb, 0.0);
		} else {
			vessel->SetThrusterGroupLevel(auto_yaw_left_1lb, 0.0);
			vessel->SetThrusterGroupLevel(auto_yaw_right_1lb, 0.0);
		}
	}
	DoPitchAttitude(vessel, simt);
}

void Mercury_Capsule::DoLowTorqueAttitude(VESSEL *vessel, double simt)
{
	VECTOR3 ang_vel = {0.0, 0.0, 0.0};
	if (ControlPanel->switch_maneuver)
		vessel->GetAngularVel(ang_vel);
	double auto_vel = 0.0;
	double tempD = 0.0;
	//ROLL
	if (ControlPanel->z_roll_heading < 330*RAD && ControlPanel->z_roll_heading > 30*RAD)
	{
		if (ControlPanel->z_roll_heading > 180*RAD) // ROLL LEFT
		{
			auto_vel = -.5*RAD;
			if (ang_vel.z > 0) {
				vessel->SetThrusterGroupLevel(auto_roll_left_1lb, 1.0);
				vessel->SetThrusterGroupLevel(auto_roll_right_1lb, 0.0);
			} else if (ang_vel.z < 0 && ang_vel.z > auto_vel) {
				vessel->SetThrusterGroupLevel(auto_roll_left_1lb, 1.0);
				vessel->SetThrusterGroupLevel(auto_roll_right_1lb, 0.0);
			} else if (ang_vel.z < 0 && ang_vel.z <= auto_vel) {
				vessel->SetThrusterGroupLevel(auto_roll_left_1lb, 0.0);
				vessel->SetThrusterGroupLevel(auto_roll_right_1lb, 0.0);
			}

		} else { //ROLL RIGHT
			auto_vel = .5*RAD;
			if (ang_vel.z < 0) {
				vessel->SetThrusterGroupLevel(auto_roll_left_1lb, 0.0);
				vessel->SetThrusterGroupLevel(auto_roll_right_1lb, 1.0);
			} else if (ang_vel.z > 0 && ang_vel.z < auto_vel) {
				vessel->SetThrusterGroupLevel(auto_roll_left_1lb, 0.0);
				vessel->SetThrusterGroupLevel(auto_roll_right_1lb, 1.0);
			} else if (ang_vel.z > 0 && ang_vel.z >= auto_vel) {
				vessel->SetThrusterGroupLevel(auto_roll_left_1lb, 0.0);
				vessel->SetThrusterGroupLevel(auto_roll_right_1lb, 0.0);
			}
		}
	} else {
		vessel->SetThrusterGroupLevel(auto_roll_left_1lb, 0.0);
		vessel->SetThrusterGroupLevel(auto_roll_right_1lb, 0.0);
	}
	if (ControlPanel->y_yaw_heading < 330*RAD && ControlPanel->y_yaw_heading > 30*RAD)
	{
		if (ControlPanel->y_yaw_heading < 180*RAD) // YAW RIGHT 
		{
			auto_vel = .5*RAD;
			if (ang_vel.y < 0) {
				vessel->SetThrusterGroupLevel(auto_yaw_left_1lb, 1.0);
				vessel->SetThrusterGroupLevel(auto_yaw_right_1lb, 0.0);
			} else if (ang_vel.y > 0 && ang_vel.y < auto_vel ) {
				vessel->SetThrusterGroupLevel(auto_yaw_left_1lb, 1.0);
				vessel->SetThrusterGroupLevel(auto_yaw_right_1lb, 0.0);
			} else if (ang_vel.y > 0 && ang_vel.y >= auto_vel ) {
				vessel->SetThrusterGroupLevel(auto_yaw_left_1lb, 0.0);
				vessel->SetThrusterGroupLevel(auto_yaw_right_1lb, 0.0);
			}

		} else { //YAW LEFT
			auto_vel = -.5*RAD;
			if (ang_vel.y > 0) {
				vessel->SetThrusterGroupLevel(auto_yaw_left_1lb, 0.0);
				vessel->SetThrusterGroupLevel(auto_yaw_right_1lb, 1.0);
			} else if (ang_vel.y < 0 && ang_vel.y > auto_vel ) {
				vessel->SetThrusterGroupLevel(auto_yaw_left_1lb, 0.0);
				vessel->SetThrusterGroupLevel(auto_yaw_right_1lb, 1.0);
			} else if (ang_vel.y < 0 && ang_vel.y <= auto_vel ) {
				vessel->SetThrusterGroupLevel(auto_yaw_left_1lb, 0.0);
				vessel->SetThrusterGroupLevel(auto_yaw_right_1lb, 0.0);
			}
		}
	} else {
		vessel->SetThrusterGroupLevel(auto_yaw_left_1lb, 0.0);
		vessel->SetThrusterGroupLevel(auto_yaw_right_1lb, 0.0);
	}

	if (ControlPanel->x_pitch_heading < 314*RAD || ControlPanel->x_pitch_heading > 338*RAD)
	{
		if (ControlPanel->x_pitch_heading > 148*RAD && ControlPanel->x_pitch_heading < 328*RAD) 
		{
			auto_vel = .5*RAD;
			if (ang_vel.x < 0) {
				vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 1.0);
				vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 0.0);
			} else if (ang_vel.x > 0 && ang_vel.x < auto_vel ) {
				vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 1.0);
				vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 0.0);
			} else if (ang_vel.x > 0 && ang_vel.x >= auto_vel) {
				vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 0.0);
				vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 0.0);
			}

		} else {
			auto_vel = -.5*RAD;
			if (ang_vel.x > 0) {
				vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 0.0);
				vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 1.0);
			} else if (ang_vel.x < 0 && ang_vel.x > auto_vel ) {
				vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 0.0);
				vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 1.0);
			} else if (ang_vel.x < 0 && ang_vel.x <= auto_vel ) {
				vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 0.0);
				vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 0.0);
			}
		}
	} else {
		vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 0.0);
		vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 0.0);
	}
}

void Mercury_Capsule::DoPitchAttitude(VESSEL *vessel, double simt)
{
	VECTOR3 ang_vel = {0.0, 0.0, 0.0};
	if (ControlPanel->switch_maneuver)
		vessel->GetAngularVel(ang_vel);
	double auto_vel = 0.0;
	double tempD = 0.0;
	vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
	vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
	vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 0.0);
	vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 0.0);
	if (ascs_mode == ASCS_REENTRY_ATT) {
		if (MissionType == MISSION_SUBORBITAL) {
			if (ControlPanel->x_pitch_heading < 39.5*RAD || ControlPanel->x_pitch_heading > 40.5*RAD)
			{
				if (ControlPanel->x_pitch_heading >= 220*RAD || ControlPanel->x_pitch_heading < 40*RAD) 
				{
					if (ControlPanel->x_pitch_heading >= 210*RAD || ControlPanel->x_pitch_heading < 30*RAD)
						auto_vel = 5*RAD;
					else if (ControlPanel->x_pitch_heading < 35*RAD)
						auto_vel = 2*RAD;
					else
						auto_vel = .05*RAD;
					if (ang_vel.x < 0) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 1.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
					} else if (ang_vel.x > 0 && ang_vel.x < auto_vel ) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 1.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
					} else if (ang_vel.x > 0 && ang_vel.x >= auto_vel) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
					}

				} else {
					if (ControlPanel->x_pitch_heading > 50*RAD)
						auto_vel = -5*RAD;
					else if (ControlPanel->x_pitch_heading > 45*RAD)
						auto_vel = -2*RAD;
					else
						auto_vel = -.05*RAD;
					if (ang_vel.x > 0) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 1.0);
					} else if (ang_vel.x < 0 && ang_vel.x > auto_vel ) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 1.0);
					} else if (ang_vel.x < 0 && ang_vel.x <= auto_vel ) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
					}
				}
			} else {
				vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
				vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
				vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 0.0);
				vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 0.0);
				//.001175
				if (ang_vel.x > .005) {
					vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
					vessel->SetThrusterGroupLevel(auto_pitch_down, 1.0);
				} else if (ang_vel.x < -.005) {
					vessel->SetThrusterGroupLevel(auto_pitch_up, 1.0);
					vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
				} else if (ang_vel.x > .001) {
					vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 0.0);
					vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 1.0);
				} else if (ang_vel.x < -.001) {
					vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 1.0);
					vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 0.0);
				} else {
					vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
					vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
					vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 0.0);
					vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 0.0);
				}
			}
		} else {
			if (ControlPanel->x_pitch_heading < 1.0*RAD || ControlPanel->x_pitch_heading > 2.0*RAD)
			{
				if (ControlPanel->x_pitch_heading >= 181.0*RAD || ControlPanel->x_pitch_heading < 1.5*RAD) 
				{
					if (ControlPanel->x_pitch_heading >= 181*RAD && ControlPanel->x_pitch_heading < 350*RAD)
						auto_vel = 5*RAD;
					else if (ControlPanel->x_pitch_heading >= 181*RAD && ControlPanel->x_pitch_heading < 355*RAD)
						auto_vel = 2*RAD;
					else
						auto_vel = .05*RAD;
					if (ang_vel.x < 0) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 1.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
					} else if (ang_vel.x > 0 && ang_vel.x < auto_vel ) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 1.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
					} else if (ang_vel.x > 0 && ang_vel.x >= auto_vel) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
					}

				} else {
					if (ControlPanel->x_pitch_heading > 11.5*RAD)
						auto_vel = -5*RAD;
					else if (ControlPanel->x_pitch_heading > 6.5*RAD)
						auto_vel = -2*RAD;
					else
						auto_vel = -.05*RAD;
					if (ang_vel.x > 0) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 1.0);
					} else if (ang_vel.x < 0 && ang_vel.x > auto_vel ) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 1.0);
					} else if (ang_vel.x < 0 && ang_vel.x <= auto_vel ) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
					}
				}
			} else {
				vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
				vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
				vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 0.0);
				vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 0.0);
				//.001175
				if (ang_vel.x > .005) {
					vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
					vessel->SetThrusterGroupLevel(auto_pitch_down, 1.0);
				} else if (ang_vel.x < -.005) {
					vessel->SetThrusterGroupLevel(auto_pitch_up, 1.0);
					vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
				} else if (ang_vel.x > .001375) {
					vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 0.0);
					vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 1.0);
				} else if (ang_vel.x < .001075) {
					vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 1.0);
					vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 0.0);
				} else {
					vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 0.0);
					vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 0.0);
				}
			}
		}
	} else {
		if (MissionType == MISSION_SUBORBITAL  && ascs_mode != ASCS_RETROGRADE && ControlPanel->CapsuleNumber == 7) {
			if (ControlPanel->x_pitch_heading < 345.0*RAD || ControlPanel->x_pitch_heading > 346.0*RAD)
			{
				if (ControlPanel->x_pitch_heading > 165*RAD && ControlPanel->x_pitch_heading < 345*RAD) 
				{
					if (ControlPanel->x_pitch_heading < 330*RAD)
						auto_vel = 5*RAD;
					else if (ControlPanel->x_pitch_heading < 335*RAD)
						auto_vel = 2*RAD;
					else
						auto_vel = .05*RAD;
					if (ang_vel.x < 0) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 1.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
					} else if (ang_vel.x > 0 && ang_vel.x < auto_vel ) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 1.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
					} else if (ang_vel.x > 0 && ang_vel.x >= auto_vel) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
					}

				} else {
					if (ControlPanel->x_pitch_heading > 1*RAD && ControlPanel->x_pitch_heading <= 165*RAD )
						auto_vel = -5*RAD;
					else if (ControlPanel->x_pitch_heading > 356*RAD)
						auto_vel = -2*RAD;
					else if (ControlPanel->x_pitch_heading <= 1*RAD)
						auto_vel = -2*RAD;
					else
						auto_vel = -.05*RAD;
					if (ang_vel.x > 0) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 1.0);
					} else if (ang_vel.x < 0 && ang_vel.x > auto_vel ) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 1.0);
					} else if (ang_vel.x < 0 && ang_vel.x <= auto_vel ) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
					}
				}
			} else {
				vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
				vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
				vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 0.0);
				vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 0.0);
				//.001175
				if (ang_vel.x > .005) {
					vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
					vessel->SetThrusterGroupLevel(auto_pitch_down, 1.0);
				} else if (ang_vel.x < -.005) {
					vessel->SetThrusterGroupLevel(auto_pitch_up, 1.0);
					vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
				} else if (ang_vel.x > .001375) {
					vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 0.0);
					vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 1.0);
				} else if (ang_vel.x < .001075) {
					vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 1.0);
					vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 0.0);
				} else {
					vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 0.0);
					vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 0.0);
				}
			}		
		} else {
			if (ControlPanel->x_pitch_heading < 327.5*RAD || ControlPanel->x_pitch_heading > 328.5*RAD)
			{
				if (ControlPanel->x_pitch_heading > 148*RAD && ControlPanel->x_pitch_heading < 328*RAD) 
				{
					if (ControlPanel->x_pitch_heading < 318*RAD)
						auto_vel = 5*RAD;
					else if (ControlPanel->x_pitch_heading < 323*RAD)
						auto_vel = 2*RAD;
					else
						auto_vel = .05*RAD;
					if (ang_vel.x < 0) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 1.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
					} else if (ang_vel.x > 0 && ang_vel.x < auto_vel ) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 1.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
					} else if (ang_vel.x > 0 && ang_vel.x >= auto_vel) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
					}

				} else {
					if (ControlPanel->x_pitch_heading > 338*RAD || ControlPanel->x_pitch_heading <= 148*RAD )
						auto_vel = -5*RAD;
					else if (ControlPanel->x_pitch_heading > 333*RAD)
						auto_vel = -2*RAD;
					else
						auto_vel = -.05*RAD;
					if (ang_vel.x > 0) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 1.0);
					} else if (ang_vel.x < 0 && ang_vel.x > auto_vel ) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 1.0);
					} else if (ang_vel.x < 0 && ang_vel.x <= auto_vel ) {
						vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
						vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
					}
				}
			} else {
				vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
				vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
				vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 0.0);
				vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 0.0);
				//.001175
				if (ang_vel.x > .005) {
					vessel->SetThrusterGroupLevel(auto_pitch_up, 0.0);
					vessel->SetThrusterGroupLevel(auto_pitch_down, 1.0);
				} else if (ang_vel.x < -.005) {
					vessel->SetThrusterGroupLevel(auto_pitch_up, 1.0);
					vessel->SetThrusterGroupLevel(auto_pitch_down, 0.0);
				} else if (ang_vel.x > .001375) {
					vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 0.0);
					vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 1.0);
				} else if (ang_vel.x < .001075) {
					vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 1.0);
					vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 0.0);
				} else {
					vessel->SetThrusterGroupLevel(auto_pitch_up_1lb, 0.0);
					vessel->SetThrusterGroupLevel(auto_pitch_down_1lb, 0.0);
				}
			}
		}
	}

}

void Mercury_Capsule::Do05Roll(VESSEL *vessel, double simt)
{
	VECTOR3 ang_vel = {0.0, 0.0, 0.0};
	if (ControlPanel->switch_maneuver)
		vessel->GetAngularVel(ang_vel);
	if (ang_vel.z < 10*RAD)
		vessel->SetThrusterGroupLevel(auto_roll_right, 1.0);
	else {
		vessel->SetThrusterGroupLevel(auto_roll_right, 0.0);
	}
}



void Mercury_Capsule::Animate (VESSEL *vessel, double simt)
{
	UpdateMesh(vessel);
}

void Mercury_Capsule::VisualCreated (VESSEL *vessel, VISHANDLE vis, int refcount)
{
	UpdateMesh(vessel);
}

void Mercury_Capsule::VisualDestroyed (VESSEL *vessel, VISHANDLE vis, int refcount)

{

}

void Mercury_Capsule::UpdateMesh (VESSEL *vessel)
{
	double delta = 0;
	float da = 0;
	int i = 0;
	if (delta = chute_proc-vchute_proc) {
		if (chute_status == CHUTE_OPENING) {
			if (vchute_proc > 0) {
				MESHGROUP_TRANSFORM mt;
				mt.nmesh = chute_mesh_number;
				mt.ngrp = -1;
				mt.transform = MESHGROUP_TRANSFORM::SCALE;
				mt.P.scaleparam.scale.x	=1;
				mt.P.scaleparam.scale.y	=1;
				mt.P.scaleparam.scale.z	=(1 / vchute_proc);
				vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);
			}
			if (chute_proc > 0) {
				MESHGROUP_TRANSFORM mt;
				mt.nmesh = chute_mesh_number;
				mt.ngrp = -1;
				mt.transform = MESHGROUP_TRANSFORM::SCALE;
				mt.P.scaleparam.scale.x	=1;
				mt.P.scaleparam.scale.y	=1;
				mt.P.scaleparam.scale.z	=chute_proc;
				vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);
			}
		} else if (chute_status == CHUTE_UNREEFING) {
			if (vchute_proc > 0) {
				MESHGROUP_TRANSFORM mt;
				mt.nmesh = chute_mesh_number;
				mt.ngrp = -1;
				mt.transform = MESHGROUP_TRANSFORM::SCALE;
				mt.P.scaleparam.scale.x	=(1 / vchute_proc);
				mt.P.scaleparam.scale.y	=(1 / vchute_proc);
				mt.P.scaleparam.scale.z	=1;
				vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);
			}
			if (chute_proc > 0) {
				MESHGROUP_TRANSFORM mt;
				mt.nmesh = chute_mesh_number;
				mt.ngrp = -1;
				mt.transform = MESHGROUP_TRANSFORM::SCALE;
				mt.P.scaleparam.scale.x	=chute_proc;
				mt.P.scaleparam.scale.y	=chute_proc;
				mt.P.scaleparam.scale.z	=1;
				vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);
			}
		}
		vchute_proc = chute_proc;
	}

	if (delta = drogue_proc-vdrogue_proc) {
		if (drogue_status == DROGUE_OPENING) {
			if (vdrogue_proc > 0) {
				MESHGROUP_TRANSFORM mt;
				mt.nmesh = drogue_mesh_number;
				mt.ngrp = -1;
				mt.transform = MESHGROUP_TRANSFORM::SCALE;
				mt.P.scaleparam.scale.x	=1;
				mt.P.scaleparam.scale.y	=1;
				mt.P.scaleparam.scale.z	=(1 / vdrogue_proc);
				vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);
			}
			if (drogue_proc > 0) {
				MESHGROUP_TRANSFORM mt;
				mt.nmesh = drogue_mesh_number;
				mt.ngrp = -1;
				mt.transform = MESHGROUP_TRANSFORM::SCALE;
				mt.P.scaleparam.scale.x	=1;
				mt.P.scaleparam.scale.y	=1;
				mt.P.scaleparam.scale.z	=drogue_proc;
				vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);
			}
		} else if (drogue_status == DROGUE_UNREEFING) {
			if (vdrogue_proc > 0) {
				MESHGROUP_TRANSFORM mt;
				mt.nmesh = drogue_mesh_number;
				mt.ngrp = -1;
				mt.transform = MESHGROUP_TRANSFORM::SCALE;
				mt.P.scaleparam.scale.x	=(1 / vdrogue_proc);
				mt.P.scaleparam.scale.y	=(1 / vdrogue_proc);
				mt.P.scaleparam.scale.z	=1;
				vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);
			}
			if (drogue_proc > 0) {
				MESHGROUP_TRANSFORM mt;
				mt.nmesh = drogue_mesh_number;
				mt.ngrp = -1;
				mt.transform = MESHGROUP_TRANSFORM::SCALE;
				mt.P.scaleparam.scale.x	=drogue_proc;
				mt.P.scaleparam.scale.y	=drogue_proc;
				mt.P.scaleparam.scale.z	=1;
				vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);
			}
		}
		vdrogue_proc = drogue_proc;
	}

	if (delta = lb_proc-vlb_proc) {
		if (lb_status == LB_OPENING) {
			if (vlb_proc > 0) {
				MESHGROUP_TRANSFORM mt;
				mt.nmesh = capsule_mesh_number;
				mt.ngrp = 5;
				mt.transform = MESHGROUP_TRANSFORM::TRANSLATE;
				mt.P.transparam.shift.x	=0.0;
				mt.P.transparam.shift.y	=0.0;
				mt.P.transparam.shift.z	= (MERCURY_LENGTH_LANDBAG * vlb_proc);
				vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);

				mt.nmesh = capsule_mesh_number;
				mt.ngrp = 5;
				mt.transform = MESHGROUP_TRANSFORM::TRANSLATE;
				mt.P.transparam.shift.x	=0.0;
				mt.P.transparam.shift.y	=0.0;
				mt.P.transparam.shift.z	= -MERCURY_LENGTH_LANDBAG;
				vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);

				mt.nmesh = lb_mesh_number;
				mt.ngrp = -1;
				mt.transform = MESHGROUP_TRANSFORM::TRANSLATE;
				mt.P.transparam.shift.x	=0.0;
				mt.P.transparam.shift.y	=0.0;
				mt.P.transparam.shift.z	= (MERCURY_LENGTH_LANDBAG * vlb_proc) /2;
				vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);

				mt.nmesh = lb_mesh_number;
				mt.ngrp = -1;
				mt.transform = MESHGROUP_TRANSFORM::TRANSLATE;
				mt.P.transparam.shift.x	=0.0;
				mt.P.transparam.shift.y	=0.0;
				mt.P.transparam.shift.z	=-MERCURY_LENGTH_LANDBAG/2;
				vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);

				mt.nmesh = lb_mesh_number;
				mt.ngrp = -1;
				mt.transform = MESHGROUP_TRANSFORM::SCALE;
				mt.P.scaleparam.scale.x	=1.0;
				mt.P.scaleparam.scale.y	=1.0;
				mt.P.scaleparam.scale.z	=(1 / vlb_proc);
				vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);

			}
			if (lb_proc > 0) {
				MESHGROUP_TRANSFORM mt;

				mt.nmesh = lb_mesh_number;
				mt.ngrp = -1;
				mt.transform = MESHGROUP_TRANSFORM::SCALE;
				mt.P.scaleparam.scale.x	=1;
				mt.P.scaleparam.scale.y	=1;
				mt.P.scaleparam.scale.z	=lb_proc;
				vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);

				mt.nmesh = lb_mesh_number;
				mt.ngrp = -1;
				mt.transform = MESHGROUP_TRANSFORM::TRANSLATE;
				mt.P.transparam.shift.x	=0.0;
				mt.P.transparam.shift.y	=0.0;
				mt.P.transparam.shift.z	=MERCURY_LENGTH_LANDBAG/2;
				vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);

				mt.nmesh = lb_mesh_number;
				mt.ngrp = -1;
				mt.transform = MESHGROUP_TRANSFORM::TRANSLATE;
				mt.P.transparam.shift.x	=0.0;
				mt.P.transparam.shift.y	=0.0;
				mt.P.transparam.shift.z	= (-MERCURY_LENGTH_LANDBAG * lb_proc) /2;
				vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);

				mt.nmesh = capsule_mesh_number;
				mt.ngrp = 5;
				mt.transform = MESHGROUP_TRANSFORM::TRANSLATE;
				mt.P.transparam.shift.x	=0.0;
				mt.P.transparam.shift.y	=0.0;
				mt.P.transparam.shift.z	= MERCURY_LENGTH_LANDBAG;
				vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);

				mt.nmesh = capsule_mesh_number;
				mt.ngrp = 5;
				mt.transform = MESHGROUP_TRANSFORM::TRANSLATE;
				mt.P.transparam.shift.x	=0.0;
				mt.P.transparam.shift.y	=0.0;
				mt.P.transparam.shift.z	= (-MERCURY_LENGTH_LANDBAG * lb_proc);
				vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);
			}
		}
		vlb_proc = lb_proc;
	}


}


int Mercury_Capsule::ConsumeKey (VESSEL *vessel, const char *keystate)
{
	return 0;
};


int Mercury_Capsule::ConsumeBufferedKey (VESSEL *vessel, DWORD key, bool down, char *kstate)
{
	if (KEYMOD_SHIFT (kstate)) 
	{
/*		if (key == OAPI_KEY_S) { 
			MESHGROUP_TRANSFORM mt;
			mt.nmesh = 2;
			mt.ngrp = -1;
			mt.transform = MESHGROUP_TRANSFORM::SCALE;
			mt.P.scaleparam.scale.x	=1.1;
			mt.P.scaleparam.scale.y	=1.1;
			mt.P.scaleparam.scale.z	=1;
			vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);
			return 1;
		}
*/
		if (key == OAPI_KEY_C) { 
			MESHGROUP_TRANSFORM mt;
			mt.nmesh = 3;
			mt.ngrp = -1;
			mt.transform = MESHGROUP_TRANSFORM::SCALE;
			mt.P.scaleparam.scale.x	=1;
			mt.P.scaleparam.scale.y	=1;
			mt.P.scaleparam.scale.z	=1.1;
			vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);
			return 1;
		}
	}
	else if (KEYMOD_CONTROL (kstate)) 
	{
		// insert ctrl key combinations here
	}
	else 
	{ // unmodified keys
		if (key == OAPI_KEY_J) { 
			if (bRetroJettisoned)
				bParachuteJettisoned = true;
			else
				bRetroSeparate = true;
			return 1;
		}
		if (key == OAPI_KEY_D) { 
			EmerRetroSeq = true;
			return 1;
		}
		if (key == OAPI_KEY_E) { 
			ControlPanel->CalcPrimaryRetro(vessel);
			return 1;
		}
/*		
		ap_dist = Orbit->getapodistance();
		if (ap_dist >= 6621000.0) {
			bAutoPilot=false;
			int tempI = 0.0;
			Orbit->gettimeorbit(&tempI,&OrbitTime,0);
			Thi = acos(Orbit->getcurrcosthi());
			if (Orbit->getcurrsinthi() < 0) 
				Thi = -Thi;

			vessel->GetEquPos(longitude, latitude, radius);
			tempD = Target - (longitude - (OrbitTime*3*DegPerSec));
			Thi += tempD;
			tempD = Orbit->GetTimeToThi(cos(Thi),sin(Thi));
			//tempD = 0;
			ControlPanel->retro_simt=OrbitTime * 3 + tempD + (simt - ControlPanel->clock_simt);
			vessel->SetEngineLevel(ENGINE_MAIN,0.0);
			bThrustCutOff = true;
			ThrustCutOffTime = simt;

		if (key == OAPI_KEY_S) { 
			MESHGROUP_TRANSFORM mt;
			mt.nmesh = 2;
			mt.ngrp = -1;
			mt.transform = MESHGROUP_TRANSFORM::SCALE;
			mt.P.scaleparam.scale.x	=.9;
			mt.P.scaleparam.scale.y	=.9;
			mt.P.scaleparam.scale.z	=1;
			vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);
			return 1;
		}
*/
		if (key == OAPI_KEY_C) { 
			if (ControlPanel->CameraPanel) 
				GetScreen(0);
			return 1;
		}
		if (key == OAPI_KEY_Q) { 
			sprintf(oapiDebugString(),"fmode %d", ControlPanel->Failure);
//			srand ( time(NULL) );
//			sprintf(oapiDebugString(),"failmode %d", rand() % 12 + 1);
		}
		if (key == OAPI_KEY_B) 
		{
			bJettisonBeacon = true;
			return 1;			
		}

		if (key == OAPI_KEY_P) { 
			if (bRetroJettisoned)
				bParachute = true;
			return 1;
		}

		if (key == OAPI_KEY_1) 
		{
			mercury_att_mode = MERCURY_ATT_AUTO;
			//SetAutoThrusters(vessel);
			return 1;			
		}
		if (key == OAPI_KEY_2) 
		{
			mercury_att_mode = MERCURY_ATT_MANUAL;
			//SetManualThrusters(vessel);
			return 1;			
		}
		if (key == OAPI_KEY_3) 
		{
			JettisonRetroCover1(vessel);
			SetCapsuleWithRetroC2(vessel,true);
			vessel->SetThrusterGroupLevel(group_retro[0],1.0);
			return 1;			
		}
		if (key == OAPI_KEY_4) 
		{			
			JettisonRetroCover2(vessel);
			SetCapsuleWithRetroC1(vessel,true);
			vessel->SetThrusterGroupLevel(group_retro[1],1.0);
			return 1;			
		}
		if (key == OAPI_KEY_5) 
		{			
			JettisonRetroCover3(vessel);
			SetCapsuleWithRetroC0(vessel,true);
			vessel->SetThrusterGroupLevel(group_retro[2],1.0);
			return 1;			
		}
		if (key == OAPI_KEY_6) 
		{
			JettisonRetroCover1(vessel);			
			JettisonRetroCover2(vessel);			
			JettisonRetroCover3(vessel);
			vessel->SetThrusterGroupLevel(group_retro[0],1.0);
			vessel->SetThrusterGroupLevel(group_retro[1],1.0);
			vessel->SetThrusterGroupLevel(group_retro[2],1.0);
			SetCapsuleWithRetroC0(vessel,true);
			return 1;			
		}
		if (key == OAPI_KEY_7) 
		{
			vessel->SetThrusterGroupLevel(group_posigrade,1.0);
			return 1;			
		}
	}	
	return 0;
};

void Mercury_Capsule::SetCapsuleWithRetroC3 (VESSEL *vessel, bool withBeacon)
{
// ==============================================================
	vessel->SetSize (1.75);
	vessel->SetCOG_elev (-1.5);
	vessel->SetEmptyMass (MERCURY_MASS);
// ==============================================================
// This is from the altanis launch config and is what makes the V-2 launch vertically
// The Z values you use to set the rocket up into the air and align with the height of 
// your launch platform. In this case the Pad 39A.
	vessel->SetTouchdownPoints (_V(0,-1.0,-1.5), _V(-.7,.7,-1.5), _V(.7,.7,-1.5));
// ==============================================================
// This from running the mesh through the shipedit program
	vessel->SetPMI (_V(0.68,0.63,.303));
	vessel->SetCrossSections (_V(3.5,3.37,2.8));
// ==============================================================
// This is based off of the SRB and Main Shuttle Tank as 
// they are the nearest thing to V-2 that I have stats for.
	vessel->SetCW (.1, MERC_DRAG, 0.3, .3);
	vessel->SetRotDrag (_V(0.7,0.7,.1));
	vessel->SetLiftCoeffFunc (0); 
// ==============================================================
	vessel->ClearMeshes();
	vessel->ClearThrusterDefinitions();
	vessel->ClearAirfoilDefinitions();
	AddAntennaHousing(vessel);
	AddDrogueCover(vessel);
	AddCapsule(vessel, ControlPanel->CapsuleNumber);
	AddRetro(vessel);
	AddRetroCover1(vessel);
	AddRetroCover2(vessel);
	AddRetroCover3(vessel);
	AddRetroRockets(vessel);
	AddAttitudeJets(vessel);
	ClearAbort(vessel);
	//if (withBeacon)
	//	AddBeacon(vessel);
	ControlPanel->bDoThrusterChange = true;
}

void Mercury_Capsule::SetCapsuleWithRetroC2 (VESSEL *vessel, bool withBeacon)
{
// ==============================================================
	vessel->SetSize (1.75);
	vessel->SetCOG_elev (-1.5);
	vessel->SetEmptyMass (MERCURY_MASS);
// ==============================================================
// This is from the altanis launch config and is what makes the V-2 launch vertically
// The Z values you use to set the rocket up into the air and align with the height of 
// your launch platform. In this case the Pad 39A.
	vessel->SetTouchdownPoints (_V(0,-1.0,-1.5), _V(-.7,.7,-1.5), _V(.7,.7,-1.5));
// ==============================================================
// This from running the mesh through the shipedit program
	vessel->SetPMI (_V(0.68,0.63,.303));
	vessel->SetCrossSections (_V(3.5,3.37,2.8));
// ==============================================================
// This is based off of the SRB and Main Shuttle Tank as 
// they are the nearest thing to V-2 that I have stats for.
	vessel->SetCW (MERC_DRAG, MERC_DRAG, 0.3, .3);
	vessel->SetRotDrag (_V(0.7,0.7,.1));
	vessel->SetLiftCoeffFunc (0); 
// ==============================================================
	vessel->ClearMeshes();
	//vessel->ClearThrusterDefinitions();
	AddAntennaHousing(vessel);
	AddDrogueCover(vessel);
	AddCapsule(vessel, ControlPanel->CapsuleNumber);
	AddRetro(vessel);
	AddRetroCover2(vessel);
	AddRetroCover3(vessel);
	//AddRetroRockets(vessel);
	//AddAttitudeJets(vessel);
	ClearAbort(vessel);
	//if (withBeacon)
	//	AddBeacon(vessel);
	ControlPanel->bDoThrusterChange = true;
}

void Mercury_Capsule::SetCapsuleWithRetroC1 (VESSEL *vessel, bool withBeacon)
{
// ==============================================================
	vessel->SetSize (1.75);
	vessel->SetCOG_elev (-1.5);
	vessel->SetEmptyMass (MERCURY_MASS);
// ==============================================================
// This is from the altanis launch config and is what makes the V-2 launch vertically
// The Z values you use to set the rocket up into the air and align with the height of 
// your launch platform. In this case the Pad 39A.
	vessel->SetTouchdownPoints (_V(0,-1.0,-1.5), _V(-.7,.7,-1.5), _V(.7,.7,-1.5));
// ==============================================================
// This from running the mesh through the shipedit program
	vessel->SetPMI (_V(0.68,0.63,.303));
	vessel->SetCrossSections (_V(3.5,3.37,2.81));
// ==============================================================
// This is based off of the SRB and Main Shuttle Tank as 
// they are the nearest thing to V-2 that I have stats for.
	vessel->SetCW (MERC_DRAG, MERC_DRAG, 0.3, .3);
	vessel->SetRotDrag (_V(0.7,0.7,.1));
	vessel->SetLiftCoeffFunc (0); 
// ==============================================================
	vessel->ClearMeshes();
	//vessel->ClearThrusterDefinitions();
	AddAntennaHousing(vessel);
	AddDrogueCover(vessel);
	AddCapsule(vessel, ControlPanel->CapsuleNumber);
	AddRetro(vessel);
	AddRetroCover3(vessel);
	//AddRetroRockets(vessel);
	//AddAttitudeJets(vessel);
	ClearAbort(vessel);
	//if (withBeacon)
	//	AddBeacon(vessel);
	ControlPanel->bDoThrusterChange = true;
}

void Mercury_Capsule::SetCapsuleWithRetroC0 (VESSEL *vessel, bool withBeacon)
{
// ==============================================================
	vessel->SetSize (1.75);
	vessel->SetCOG_elev (-1.5);
	vessel->SetEmptyMass (MERCURY_MASS);
// ==============================================================
// This is from the altanis launch config and is what makes the V-2 launch vertically
// The Z values you use to set the rocket up into the air and align with the height of 
// your launch platform. In this case the Pad 39A.
	vessel->SetTouchdownPoints (_V(0,-1.0,-1.5), _V(-.7,.7,-1.5), _V(.7,.7,-1.5));
// ==============================================================
// This from running the mesh through the shipedit program
	vessel->SetPMI (_V(0.68,0.63,.303));
	vessel->SetCrossSections (_V(3.5,3.37,2.81));
// ==============================================================
// This is based off of the SRB and Main Shuttle Tank as 
// they are the nearest thing to V-2 that I have stats for.
	vessel->SetCW (MERC_DRAG, MERC_DRAG, 0.3, .3);
	vessel->SetRotDrag (_V(0.7,0.7,.1));
	vessel->SetLiftCoeffFunc (0); 
// ==============================================================
	vessel->ClearMeshes();
	//vessel->ClearThrusterDefinitions();
	AddAntennaHousing(vessel);
	AddDrogueCover(vessel);
	AddCapsule(vessel, ControlPanel->CapsuleNumber);
	AddRetro(vessel);
	//AddRetroRockets(vessel);
	//AddAttitudeJets(vessel);
	ClearAbort(vessel);
	//if (withBeacon)
	//	AddBeacon(vessel);
	ControlPanel->bDoThrusterChange = true;
}

void Mercury_Capsule::SetCapsuleMain(VESSEL *vessel)
{
	PROPELLANT_HANDLE main_tank;
	THRUSTER_HANDLE main_engine[1];
// ==============================================================
	vessel->SetSize (1.75);
	vessel->SetCOG_elev (-1.5);
	vessel->SetEmptyMass (MERCURY_MASS_CAPSULE);
// ==============================================================
// This is from the altanis launch config and is what makes the V-2 launch vertically
// The Z values you use to set the rocket up into the air and align with the height of 
// your launch platform. In this case the Pad 39A.
	vessel->SetTouchdownPoints (_V(0,-1.0,-.8), _V(-.7,.7,-.8), _V(.7,.7,-.8));
// ==============================================================
// This from running the mesh through the shipedit program
	vessel->SetPMI (_V(0.66,0.66,.33));
	vessel->SetCrossSections (_V(2.8,2.8,2.8));
// ==============================================================
// This is based off of the SRB and Main Shuttle Tank as 
// they are the nearest thing to V-2 that I have stats for.
	vessel->SetCW (.01, MERC_DRAG, 0.1, 0.1);
	vessel->SetRotDrag (_V(0.7,0.7,.1));
	vessel->SetLiftCoeffFunc (0); 
// ==============================================================
// Setup Parachutes
	vessel->ClearMeshes();
	vessel->ClearThrusterDefinitions();
	//vessel->ClearAirfoilDefinitions();
	//vessel->ClearVariableDragElements();
	//vessel->CreateVariableDragElement(&chute_proc,.7,_V(0,0,MERCURY_OFS_MAINCHUTE.z+18));
	PARTICLESTREAMSPEC rps = {
		0, 4, 100, 0, 0.03, 5, 100, 3, PARTICLESTREAMSPEC::DIFFUSE,
		PARTICLESTREAMSPEC::LVL_FLAT, 1, 1, PARTICLESTREAMSPEC::ATM_PLIN, 6e7, 12e7
	};
	vessel->AddReentryStream (&rps);	
	ClearAbort(vessel);
	ClearRetro(vessel);
	AddCapsule(vessel, ControlPanel->CapsuleNumber);
	if (bLandingBagDeployed)
		AddLandingBag(vessel);
	AddAttitudeJets(vessel);

	vessel->CreateDock(_V(0,0,-0.5),_V(0,0,1),_V(0,1,0));
	main_tank = vessel->CreatePropellantResource(10.0);
	main_engine[0] = vessel->CreateThruster(_V(0,0,0), _V(0,0,1), 50000.0, main_tank, 100000000.0, 100000000.0);
	vessel->CreateThrusterGroup (main_engine, 1, THGROUP_HOVER);

//	if (vessel->AttachmentCount(true) == 0) {
//		vessel->CreateAttachment(true, _V(0,0,2),_V(0,0,1),_V(0,1,0),"HOOKBAR");
//	}
	
}
void LiftCoeff (double aoa, double M, double Re, double *cl, double *cm, double *cd)
{
	int i;
	const int nabsc = 9;
	static const double AOA[nabsc] = {-180*RAD,-150*RAD,-130*RAD,-15*RAD, 0*RAD, 15*RAD,130*RAD,150*RAD,180*RAD};
	static const double CM[nabsc]  = {    .0002,    .0002,     0.0, 0.0002,  0.00,  -0.0002,      0,  -.0002,  -.0002};

	for (i = 0; i < nabsc-1 && AOA[i+1] < aoa; i++);
	double f = (aoa-AOA[i]) / (AOA[i+1]-AOA[i]);

	*cl = 0;
	*cm = CM[i] + (CM[i+1]-CM[i]) * f;  // aoa-dependent moment coefficient
	*cd = MERC_DRAG;//*5.0;//*2.5;
	//sprintf(oapiDebugString(),"CD %f ", MERC_DRAG + oapiGetWaveDrag (M, 1.1, 1.0, 1.1, 10.0));
	*cd = MERC_DRAG + oapiGetWaveDrag (M, 1.1, 15.0, 30.0, 2.5);
}

void Mercury_Capsule::SetCapsule(VESSEL *vessel)
{
// ==============================================================
	vessel->SetSize (1.75);
	vessel->SetCOG_elev (-1.5);
	vessel->SetEmptyMass (MERCURY_MASS_CAPSULE);
	
	vessel->CreateAirfoil(LIFT_VERTICAL,_V(0,0,.635), LiftCoeff, 2.34, 0, 1);
	vessel->CreateAirfoil(LIFT_HORIZONTAL,_V(0,0,.635), LiftCoeff, 2.34, 0, 1);

	vessel->CreateVariableDragElement(&drogue_proc,.7,_V(0,0,MERCURY_OFS_DROUGE.z+13));
	vessel->CreateVariableDragElement(&chute_proc,.7,_V(0,0,MERCURY_OFS_MAINCHUTE.z+18));
// ==============================================================
// This is from the altanis launch config and is what makes the V-2 launch vertically
// The Z values you use to set the rocket up into the air and align with the height of 
// your launch platform. In this case the Pad 39A.
	vessel->SetTouchdownPoints (_V(0,-1.0,-1.5), _V(-.7,.7,-1.5), _V(.7,.7,-1.5));
// ==============================================================
// This from running the mesh through the shipedit program
	vessel->SetPMI (_V(0.66,0.66,.33));
	vessel->SetCrossSections (_V(2.8,2.8,2.8));
// ==============================================================
// This is based off of the SRB and Main Shuttle Tank as 
// they are the nearest thing to V-2 that I have stats for.
	vessel->SetCW (.1, MERC_DRAG, 0.3, .3);
	vessel->SetRotDrag (_V(0.7,0.7,.1));
	vessel->SetLiftCoeffFunc (0); 
// ==============================================================
	SURFHANDLE tex = oapiRegisterReentryTexture("reentry");
	vessel->SetReentryTexture(tex, 1e6, 9, 2);
	PARTICLESTREAMSPEC rps = {
		0, 4, 100, 0, 0.03, 5, 100, 3, PARTICLESTREAMSPEC::DIFFUSE,
		PARTICLESTREAMSPEC::LVL_FLAT, 1, 1, PARTICLESTREAMSPEC::ATM_PLIN, 1e6, 2e7
	};
	vessel->AddReentryStream (&rps);	
// Setup Parachutes
	vessel->ClearMeshes();
	vessel->ClearThrusterDefinitions();
	ClearAbort(vessel);
	ClearRetro(vessel);
	AddCapsule(vessel, ControlPanel->CapsuleNumber);
	AddDrogueCover(vessel);
	AddAntennaHousing(vessel);
	AddAttitudeJets(vessel);	
	if (bLandingBagDeployed)
		AddLandingBag(vessel);
	ControlPanel->bDoThrusterChange = true;

}

void Mercury_Capsule::OpenChute (VESSEL *vessel)
{
	MESHGROUP_TRANSFORM mt;
	mt.nmesh = chute_mesh_number;
	mt.ngrp = -1;
	mt.transform = MESHGROUP_TRANSFORM::SCALE;
	mt.P.scaleparam.scale.x	=.12;
	mt.P.scaleparam.scale.y	=.12;
	mt.P.scaleparam.scale.z	=0.01;
	//vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);
	vchute_proc = 0.01;
	chute_proc = 0.01;
	chute_moving = true;
	chute_status = CHUTE_OPENING;
	vessel->RegisterAnimation();
}

void Mercury_Capsule::OpenDrogue (VESSEL *vessel)
{
	MESHGROUP_TRANSFORM mt;
	mt.nmesh = drogue_mesh_number;
	mt.ngrp = -1;
	mt.transform = MESHGROUP_TRANSFORM::SCALE;
	mt.P.scaleparam.scale.x	=.12;
	mt.P.scaleparam.scale.y	=.12;
	mt.P.scaleparam.scale.z	=0.01;
	//vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);
	vdrogue_proc = 0.01;
	drogue_proc = 0.01;
	drogue_moving = true;
	drogue_status = DROGUE_OPENING;
	vessel->RegisterAnimation();
	JettisonDrogueCover(vessel);
}

void Mercury_Capsule::OpenLandingBag (VESSEL *vessel)
{
	MESHGROUP_TRANSFORM mt;
	
	
	mt.nmesh = lb_mesh_number;
	mt.ngrp = -1;
	mt.transform = MESHGROUP_TRANSFORM::SCALE;
	mt.P.scaleparam.scale.x	=1.0;
	mt.P.scaleparam.scale.y	=1.0;
	mt.P.scaleparam.scale.z	=0.01;
	vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);

	mt.nmesh = lb_mesh_number;
	mt.ngrp = -1;
	mt.transform = MESHGROUP_TRANSFORM::TRANSLATE;
	mt.P.transparam.shift.x	=0.0;
	mt.P.transparam.shift.y	=0.0;
	mt.P.transparam.shift.z	=MERCURY_LENGTH_LANDBAG/2;
	vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);

	mt.nmesh = lb_mesh_number;
	mt.ngrp = -1;
	mt.transform = MESHGROUP_TRANSFORM::TRANSLATE;
	mt.P.transparam.shift.x	=0.0;
	mt.P.transparam.shift.y	=0.0;
	mt.P.transparam.shift.z	= (-MERCURY_LENGTH_LANDBAG * .01) /2;
	vessel->MeshgroupTransform (((Multi_Stage*)vessel)->hVis, mt);

	vlb_proc = 0.01;
	lb_proc = 0.01;
	lb_moving = true;
	lb_status = LB_OPENING;
	vessel->RegisterAnimation();
}

void Mercury_Capsule::DeployDrogue(VESSEL *vessel)
{
	AddDrogue(vessel);
	drogue_status = DROGUE_DEPLOYED;
}

void Mercury_Capsule::DeployMain(VESSEL *vessel)
{
	//PlayVesselWave(SOUND_CHUTE);
	AddChute(vessel);
	//AddDrogue(vessel);
	chute_status = CHUTE_DEPLOYED;
}

void Mercury_Capsule::AddDrogue(VESSEL *vessel)
{
// ==============================================================
// This from running the mesh through the shipedit program
	vessel->SetCrossSections (_V(2.8,2.8,MERCURY_CHUTE_DROGUE));
	vessel->SetCW (1.5, 1.5, 0.3, 0.3);
// ==============================================================
	vessel->SetSize (9);
	vessel->ClearMeshes();
	AddAntennaHousing(vessel);
	AddCapsule(vessel, ControlPanel->CapsuleNumber);
	drogue_mesh_number = vessel->AddMesh (oapiLoadMeshGlobal("merc_drogues"), &MERCURY_OFS_DROUGE);
	vessel->SetMeshVisibleInternal(drogue_mesh_number,true);
	if (bLandingBagDeployed)
		AddLandingBag(vessel);

}

void Mercury_Capsule::AddChute(VESSEL *vessel)
{
	vessel->SetCrossSections (_V(2.8,2.8,MERCURY_CHUTE_MAIN));
	vessel->SetCW (1.5, 1.5, .3, 0.3);
	vessel->SetSize (12);
	vessel->ClearMeshes();
	AddCapsule(vessel, ControlPanel->CapsuleNumber);
	VECTOR3 mesh_dir=MERCURY_OFS_MAINCHUTE;
	chute_mesh_number = vessel->AddMesh (oapiLoadMeshGlobal("merc_chutes"), &mesh_dir);
	//sprintf(oapiDebugString(), "mesh num: %d", chute_mesh_number);
	vessel->SetMeshVisibleInternal(chute_mesh_number,true);
	if (bLandingBagDeployed)
		AddLandingBag(vessel);
}

void Mercury_Capsule::SepParachute(VESSEL *vessel, bool do_jettison)
{
	if (!bMainDeployed && bDrogueDeployed && !bDrogueJettisoned)
	{
		if (do_jettison)
			JettisonDrogue(vessel);
		drogue_proc = 0.0;
		bDrogueJettisoned=true;
		SetCapsuleMain(vessel);
	}
	else if (bMainDeployed && !bMainJettisoned)
	{
		if (do_jettison)
			JettisonMain(vessel);
		chute_proc = 0.0;
		SetCapsuleMain(vessel);
		bMainJettisoned=true;
	}
	else if (bBackupDeployed && !bBackupJettisoned)
	{
		if (do_jettison)
			JettisonMain(vessel);
		chute_proc = 0.0;
		SetCapsuleMain(vessel);
		bBackupJettisoned=true;
	}
}

void Mercury_Capsule::SetAbortStage(VESSEL *vessel)
{
	UINT abortmesh;
// ==============================================================
	vessel->SetSize (1.5+1.9);
	vessel->SetCOG_elev (-1.5);
	vessel->SetEmptyMass (1355.0+145.0);
// ==============================================================
// This is from the altanis launch config and is what makes the V-2 launch vertically
// The Z values you use to set the rocket up into the air and align with the height of 
// your launch platform. In this case the Pad 39A.
	vessel->SetTouchdownPoints (_V(0,-1.0,-1.48), _V(-.7,.7,-1.48), _V(.7,.7,-1.48));
// ==============================================================
// This from running the mesh through the shipedit program
	vessel->SetPMI (_V(.707,.707,0.03));
	vessel->SetCrossSections (_V(4.25,4.25,2.8));
// ==============================================================
// This is based off of the SRB and Main Shuttle Tank as 
// they are the nearest thing to V-2 that I have stats for.
	vessel->SetCW (0.01, .01, 0.03, .03);
	vessel->SetRotDrag (_V(0.7,0.7,.1));
	vessel->SetPitchMomentScale (0);
	vessel->SetBankMomentScale (0);
	vessel->SetLiftCoeffFunc (0); 
// ==============================================================
	vessel->ClearMeshes();
	vessel->ClearThrusterDefinitions();
	AddAntennaHousing(vessel);
	AddCapsule(vessel, ControlPanel->CapsuleNumber);
	AddDrogueCover(vessel);
	AddRetro(vessel);
	AddRetroCover1(vessel);
	AddRetroCover2(vessel);
	AddRetroCover3(vessel);
	AddRetroRockets(vessel);
	abortmesh = AddAbortTower(vessel);
	vessel->SetMeshVisibilityMode(abortmesh, MESHVIS_ALWAYS);
	//vessel->SetCameraOffset(_V(0,.75,-.75));
	AddAttitudeJets(vessel);
	AddAbortRocket(vessel);
	ControlPanel->bDoThrusterChange = true;
};

#endif // !__MULTI_STAGE_H
