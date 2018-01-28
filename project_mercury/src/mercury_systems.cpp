#include "mercury_systems.h"
#include "orbitersdk.h"
#include <string.h>
#include <stdio.h>

mSubstance::mSubstance(int iSubstType, double iMass, double iTemp) {
	this->SubstType = iSubstType;
	this->Mass      = iMass;
	this->SetTemp(iTemp);
}

void mSubstance::operator+= (mSubstance Add) { 
	if (Add.SubstType == SubstType){
		Mass += Add.Mass;
		Q    += Add.Q;
	}
};

void mSubstance::operator-= (mSubstance Minus) { 
	if (Minus.SubstType == SubstType){
		Mass -= Minus.Mass;
		Q    -= Minus.Q;
	}
};

mSubstance mSubstance::operator *(double Ratio){
	mSubstance Temp;

	Temp.Mass       = Mass * Ratio;
	Temp.Q          = Q * Ratio;
	Temp.SubstType  = SubstType;
	return Temp;
};


void mSubstance::SetTemp(double iTemp) {
	Q = iTemp * Mass * SPECIFICC[SubstType];
}

double mSubstance::GetTemp() {
	    if (Mass * SPECIFICC[SubstType] == 0 )
			return 0;
        else
            return Q / (Mass * SPECIFICC[SubstType]);
}

mVolume::mVolume(){
	SetParams(0);
}

mVolume::mVolume(double iVol){
	SetParams(iVol);
}

void mVolume::SetParams(double iVol) {
	for (int i=0;i<MAX_SUB;i++) {
		Composition[i].SubstType = i;
		Composition[i].Mass      = 0;
		Composition[i].Q         = 0;
	};
	Volume= iVol;
};

int mVolume::GetMaxSub() {
	int MaxSub=0;
	for (int i=0;i<MAX_SUB;i++) {
		if (Composition[i].Mass > 0) 
			MaxSub++;
	}
	return 0;
};

void mVolume::operator +=(mSubstance Add) {
	Composition[Add.SubstType]+=Add;
};


void mVolume::operator +=(mVolume Add) {
	for (int i=0;i<MAX_SUB;i++)
		Composition[i]+=Add.Composition[i];
};

mVolume mVolume::Break(double Vol,int * Mask) { 
	mVolume Temp;
	double Ratio=Vol/Volume;
	if (Ratio>1) 
		Ratio=1.;
	for (int i=0;i<MAX_SUB;i++){
		Temp+=Composition[i]*Ratio*Mask[i];
		Composition[i]-=Temp.Composition[i];
	}
	return Temp;   //then feed it to the requester
};


double mVolume::GetMass() { 
	double Mass=0;
	for (int i=0;i<MAX_SUB;i++)
			Mass+=Composition[i].Mass;
	return Mass;
};

double mVolume::GetPress() { 
	double Press=0;
	for (int i=0;i<MAX_SUB;i++)
			Press+=Composition[i].Press;
	return Press;
};

double mVolume::GetTemp() {
	double AvgC=0;
	double Mass = 0;
	double TempD = 0.0;
	for (int i=0;i<MAX_SUB;i++)
		AvgC+=Composition[i].Mass*SPECIFICC[Composition[i].SubstType];
	
	Mass = GetMass();
	
	if (Mass > 0) {
		AvgC  = AvgC / Mass;	        //weighted average heat capacity.. gives us averaged temp (ideal case)
		TempD = GetQ() / AvgC / Mass; //average Temp of substances
	} else {
		TempD=0;
	}
	return TempD;
}

double mVolume::GetQ(){ 
	double Q=0;
	for (int i=0;i<MAX_SUB;i++)
			Q+=Composition[i].Q;
	return Q;
};


void mVolume::Compute(double DT) 
{
	double nM = 0;
	for (int i=0;i<MAX_SUB;i++) {
		nM = Composition[i].Mass / MMASS[Composition[i].SubstType];
        Composition[i].Press = (nM * R_CONST * Composition[i].GetTemp()) / Volume;
	}

}

void mVolume::Void() {
	SetParams(Volume);
};

mShipSystems::~mShipSystems(){
	mSystemObject *runner;
	mSystemObject *gone;
	runner = List.nextPtr;
	while (runner != 0) {
		gone=runner;
		runner=runner->nextPtr;
		delete gone;
	};
};



mSystemObject* mShipSystems::AddSystem(mSystemObject *object){ 
	mSystemObject *runner;
	runner=&List;
	while (runner->nextPtr != 0) 
		runner=runner->nextPtr;
	runner->nextPtr=object;
	object->nextPtr=NULL;
	return object;
};

void* mShipSystems::GetComponent(char *component_name){
	mSystemObject*runner;
	runner=List.nextPtr;
	while (runner != 0){ 
		if (strcmp(runner->name, component_name) == 0)
			return runner;
		runner=runner->nextPtr;
	}
	return NULL;
}

void mShipSystems::Refresh(double dt){ 
	mSystemObject*runner;
	runner=List.nextPtr;
	while (runner != 0){ 
		runner->Refresh(dt);
		runner=runner->nextPtr;
	}
};

void mShipSystems::Load(FILEHANDLE scn) { 
	char *line;
//	char name[25];
	char string1[25];
//	char string2[25];

	oapiReadScenario_nextline (scn, line);

	while (_strnicmp(line,"</SYSTEMS>",10)) {

		if (!_strnicmp (line, "<TANK>",6 )) {
			double volume;
			int one;
			int two;
			mTank *tank;
			sscanf(line+6,"%s %lf %i %i",string1,&volume,&one,&two);
			tank = (mTank*) this->GetComponent(string1);
			if (tank != 0) {
				tank->Load(scn);
				tank->Space.Volume  = volume;
				tank->InValve.Open  = one;
				tank->OutValve.Open = two;
			}
		} else 	if (!_strnicmp (line, "<BATTERY>",9 )) {
			double power;
			mBattery *btty;
			sscanf(line+9,"%s %lf ",string1,&power);
			btty = (mBattery*) this->GetComponent(string1);
			if (btty != 0) {
				btty->Power = power;
			}
		}
		oapiReadScenario_nextline (scn, line);
	}
};

void mShipSystems::Save(FILEHANDLE scn) {
	mSystemObject *runner;
	runner=List.nextPtr;
	oapiWriteScenario_string(scn, "<SYSTEMS>","");
	while (runner != 0){ 
		runner->Save(scn);
		runner=runner->nextPtr;
	}
	oapiWriteScenario_string(scn, "</SYSTEMS>","");
};

mValve::mValve() {
	Set(0, 0, NULL);
}

mValve::mValve(int iOpen, double iSize, mTank *iParent) {
	Set(iOpen, iSize, iParent);
}

void mValve::Set(int iOpen, double iSize, mTank *iParent) {
	Open   = iOpen;
	Size   = iSize;
	Parent = iParent;
}

double mValve::GetPress() {
	if (Open != 0 && Parent != NULL) 
		return Parent->Space.GetPress();
	else
		return 0;
}

double mValve::GetTemp() {
	if (Parent != NULL)
		return Parent->Space.GetTemp();
	else
		return 0;
}

int mValve::Flow(mVolume Block){
	if (Open != 0 && Parent != NULL) 
		return Parent->Flow(Block);
	else
		return 0;
}

mVolume mValve::GetFlow(double dPdT){
	double vol = dPdT * Size / 1000;
	if (Open == 0) 
		vol = 0;
	if (Parent != NULL)
		return Parent->GetFlow(vol);
	else
		return NULL;
}

mTank::mTank(){
	strcpy(&name[0], "");
	Space.Volume = 0;
	LeakRate = 0;
	InValve.Set (0, 1.0, this);
	OutValve.Set(0, 1.0, this);
	VentValve.Set(0, 1.0, this);
	for (int i=0;i<MAX_SUB;i++) {
		OutFlowMask[i] = 1;
		InFlowMask[i] = 1;
	}
}

mTank::mTank(char *iName, double iVol, double iLeakRate){
	strcpy(&name[0], iName);
	Space.Volume = iVol;
	InValve.Set (0, 1.0, this);
	OutValve.Set(0, 1.0, this);
	VentValve.Set(0, 1.0, this);
	for (int i=0;i<MAX_SUB;i++) {
		OutFlowMask[i] = 1;
		InFlowMask[i] = 1;
	}
	LeakRate = iLeakRate;
}

void mTank::operator+= (mSubstance Add) { 
	Space += Add;
};

void mTank::Save(FILEHANDLE scn) {
	char text[100];
	
	sprintf(text," %s %f %i %i", name, Space.Volume, InValve.Open, OutValve.Open);										 	
	oapiWriteScenario_string(scn, "   <TANK>",text);

	for (int i=0;i<MAX_SUB;i++)
		if (Space.Composition[i].Mass > 0) {
			sprintf(text,"   %i %8.4f %8.4f",
							  Space.Composition[i].SubstType,
							  Space.Composition[i].Mass,
							  Space.Composition[i].Q);							
			oapiWriteScenario_string(scn, "      CHM", text);
		};
	oapiWriteScenario_string(scn, "   </TANK>","");
}

void mTank::Load(FILEHANDLE scn) {
	char *line;
	mSubstance loaded_sub;

	oapiReadScenario_nextline (scn, line);
	Space.Void(); //empty the space
	while (_strnicmp(line,"</TANK>",7)) {
		if (!_strnicmp (line, "CHM",3 )) {
            sscanf (line+3, "   %i %lf %lf",
						&loaded_sub.SubstType,
						&loaded_sub.Mass,
						&loaded_sub.Q);
			Space+=loaded_sub;
		}
		oapiReadScenario_nextline (scn, line);
	}
	Space.Compute(1);
}

void mTank::Refresh(double dt) {
	if (LeakRate > 0){
		this->GetFlow(LeakRate);
	}
	Space.Compute(dt);

}

int mTank::Flow(mVolume Block) {
	Space += Block;
	return 1;
}

mVolume mTank::GetFlow(double vol){
	mVolume temp = Space.Break(vol,OutFlowMask);
	return temp;
}

mPipe::mPipe() {

	InValve  = 0;
	OutValve = 0;
	Max      = 0;
	Min      = 0;

}

mPipe::mPipe(char *iName, mValve* iIn, mValve* iOut, double iMax, double iMin){
	strcpy(&name[0], iName);
	SetParams(iIn, iOut, iMax, iMin);
}

void mPipe::SetParams(mValve* iIn, mValve* iOut, double iMax, double iMin){
	InValve  = iIn;
	OutValve = iOut;
	Max      = iMax;
	Min      = iMin;
}

void mPipe::Refresh(double dt){
	if (dt == 0)
		return;

	if ((InValve->Open == 1) && (OutValve->Open == 1) && Open == 1)
	{
		double InP = InValve->GetPress();
		double OutP = OutValve->GetPress();
		if (TypePipe == 1) {
			if (InP > Max)
				InP = Max;
		} else if (TypePipe == 2) {
			if (InP > Max)
				InP = Max;
			if (OutP < Min)
				return;
		} else if (TypePipe == 0) {
			//sprintf(oapiDebugString(), "Pipe: %f, %f", InP, OutP);
		}

		if (InP > OutP) {
			double tdt = 0.0;
			double tFactor = .001;
			while (tdt < dt &&  OutP < InP) {
				mVolume tVol = InValve->GetFlow(tFactor * (InP - OutP));// * (InValve->Size / 1000));
				tVol.Compute(1);
				OutValve->Flow(tVol);
				InValve->Parent->Space.Compute(tFactor);
				OutValve->Parent->Space.Compute(tFactor);
				tdt += .001;
				if (TypePipe == 0) 
					InP = InValve->GetPress();
				OutP = OutValve->GetPress();
			}
		} 
	}
}


mVent::mVent() {

	InValve  = 0;
	Max = 0;
	Min = 0;
}

mVent::mVent(char *iName, mValve* iIn, double iMax, double iMin){
	strcpy(&name[0], iName);
	SetParams(iIn, iMax, iMin);
}

void mVent::SetParams(mValve* iIn, double iMax, double iMin){
	InValve  = iIn;
	Max      = iMax;
	Min      = iMin;
}

void mVent::Refresh(double dt){
	double Press = 0;
	double Density = 0;
	double InP = InValve->GetPress();
	double OutP = 0;//Press;

	if (dt == 0)
		return;

	if (InValve->Open == 1 && (Open == 1 || (InP > Max && Max != 0)))
	{
		//oapiGetFocusAtmPressureDensity(&Press, &Density);
		if (InP < Min) 
			return;


		if (InP > OutP) {
			double tdt = 0.0;
			double tFactor = .001;
			while (tdt < dt &&  OutP < InP) {
				mVolume tVol = InValve->GetFlow(tFactor * (InP - OutP));// * (InValve->Size / 1000));
				tVol.Compute(1);
				InValve->Parent->Space.Compute(tFactor);
				tdt += .001;
				InP = InValve->GetPress();
			}
		} 
	}
}

mCrew::mCrew(char *iName, mTank* iSRC){
	strcpy(&name[0], iName);
	SRC = iSRC;
}

void mCrew::Refresh(double dt){
	if (SRC == 0) 
		return;
	if (dt == 0)
		return;

	double Oxygen = 0.178 * dt;

	if (SRC->Space.Composition[SUBSTANCE_O2].Mass < Oxygen)
		Oxygen = SRC->Space.Composition[SUBSTANCE_O2].Mass;


	double tQ = 0.0;
	
	if (SRC->Space.Composition[SUBSTANCE_O2].Mass!=0) 
		tQ = SRC->Space.Composition[SUBSTANCE_O2].Q * (Oxygen / SRC->Space.Composition[SUBSTANCE_O2].Mass);


	SRC->Space.Composition[SUBSTANCE_O2].Mass -= Oxygen;
	SRC->Space.Composition[SUBSTANCE_O2].Q -= tQ;
/*
	SRC->Space.Composition[SUBSTANCE_CO2].Mass += Oxygen;
	SRC->Space.Composition[SUBSTANCE_CO2].Q += 300 * Oxygen * SPECIFICC[SUBSTANCE_CO2];
/*
	SRC->Space.Composition[SUBSTANCE_H20].Mass += Oxygen * 0.01;
	SRC->Space.Composition[SUBSTANCE_H20].Q += 300 * Oxygen * 0.01 * SPECIFICC[SUBSTANCE_H20];
*/
}

mElectricObject::mElectricObject() {
	SRC      = 0; 
	DrawAmps = 0; 
	PowerOn  = 0;
};

mElectricObject::mElectricObject(char *iName, mElectricObject* iSRC, double iDrawAmps) {
	strcpy(&name[0], iName);
	SRC = iSRC; 
	DrawAmps = iDrawAmps; 
	PowerOn = 1;
};

void mElectricObject::Refresh(double dt){ 
	if (SRC != 0 && PowerOn == 1) 
		if (SRC->Volt > 0) 
			SRC->LoadPower(DrawAmps * dt); 
	Volt = SRC->Volt;
//	sprintf(oapiDebugString(), "Batt: %f", DrawAmps * dt);
};

void mElectricObject::LoadPower(double Amps) {
 };

void mElectricObject::Connect(mElectricObject* NewSRC) { 
	SRC = NewSRC; 
};


mBus::mBus(char *iName){
	strcpy(&name[0], iName);
	DrawAmps = 0;
	PowerOn  = 1;
	for (int i = 0; i < 20; i++)
		SRCs[i] = 0;
	power_load = 0;
}

mBus::~mBus(){
	for (int i = 0; i < 20; i++)
		if (SRCs[i] != 0)
			delete SRCs[i];
};


void mBus::LoadPower(double Amps){
	int count = Count();
	power_load += Amps;
	if (count > 0 && PowerOn == 1){
		double tAmps = Amps / count;
		for (int i = 0; i < 20; i++)
			if (SRCs[i] != 0)
				if (SRCs[i]->PowerOn == 1)
					SRCs[i]->LoadPower(tAmps);
				else
					i = 20;
	}
};

void mBus::Connect(mElectricObject* NewSRC){
	for (int i = 0; i < 20; i++){
		if (SRCs[i] == 0) {
			SRCs[i] = NewSRC;
			return;
		}
	}
};

void mBus::Refresh(double dt){
	Volt = 0;
	power_load = 0;
	if (PowerOn == 1) {
		for (int i = 0; i < 20; i++){
			if (SRCs[i] != 0) {
				if (SRCs[i]->Volt > Volt) {
					Volt = SRCs[i]->Volt;
				} 
			} else {
				i = 20;
			}
		}
	}
}

int mBus::Count(){
	int count = 0;
	for (int i = 0; i < 20; i++) {
		if (SRCs[i] != 0) {
			if (SRCs[i]->PowerOn == 1)
				count += 1;
		} else {
			i = 20;
		}
	}
	return count;
}

mBattery::mBattery(char *iName, double iPower, double iVoltage){
	strcpy(&name[0], iName);
	SRC     = 0;
	Power   = iPower;
	Voltage = iVoltage;
	PowerOn = 1;
	power_load = 0;
}


void mBattery::Refresh(double dt){
	power_load = 0;
	if (Power > 0 && PowerOn == 1) {
		double iVoltage = Power / (200000 / Voltage);

		if (iVoltage < Voltage)
			Volt = iVoltage;
		else
			Volt = Voltage;
	} else {
		Volt = 0;
	}
}

void mBattery::LoadPower(double Amps){
	power_load += Amps;
	if (PowerOn == 1) {
		Power -= Amps * Voltage;
	} 

	if (Power < 0) { 
		Power   = 0;
		PowerOn = 0;
	}
}

void mBattery::Save(FILEHANDLE scn) {
	char text[100];	
	sprintf(text," %s %f", name, Power);										 	
	oapiWriteScenario_string(scn, "   <BATTERY>",text);
	oapiWriteScenario_string(scn, "   </BATTERY>","");
}

void mBattery::Load(FILEHANDLE scn) {
}


/*mBattery::mBattery(){
	SRC = 0;
	PowerLoad = 0.0;
	Power = 0;
	Loading = 0;
	Voltage = 28.8;
	DrawAmps = 30;
	LoadHandle = 0;
	LoadCB = 0;
	Breaker = 1;
}

mBattery::mBattery(mElectricObject* iSRC, double iPower, double iVoltage, double iDrawAmps){
	SRC = iSRC;
	PowerLoad = 0.0;
	Power = iPower;
	Loading = 0;
	Voltage = iVoltage;
	DrawAmps = iDrawAmps;
	LoadHandle = 0;
	LoadCB = 0;
	Breaker = 1;
}

void mBattery::pLoad(double Amps) {
	PowerLoad += Amps;
}

void mBattery::pUnLoad(double Amps) {
	PowerLoad -= Amps;
}

void mBattery::Connect(mElectricObject* NewSRC){
	if (Loading != 0)
		SRC->pUnLoad(DrawAmps);
	SRC = NewSRC;
	if (Loading != 0)
		SRC->pLoad(DrawAmps);
}

void mBattery::Refresh(double dt){
	Amperes = PowerLoad;
	Volts = Voltage * Breaker;
	Power -= Amperes * Volts * dt;
	if (Power < 0) {
		Power = 0;
		Amperes = 0;
		Volts = 0;
	}

	if (LoadHandle == 1 && SRC != 0 && Loading != 0) {
		SRC->pLoad(DrawAmps);
		LoadHandle = 0;
		Loading = 1;
	}
	if (LoadHandle == -1 && SRC != 0 && Loading == 0) {
		SRC->pUnLoad(DrawAmps);
		LoadHandle = 0;
		Loading = 0;
	}

	if (Loading == 1) {
		if (LoadCB != 0){
			Power += DrawAmps * (SRC->Volts) * dt;
		} else {
			LoadHandle = -1;
		}
	}

}
*/

/*mCompressor::mCompressor(){
	SRC = 0;
	InValve = 0;
	OutValve = 0;
	Pumping = 0;
	Max = 0;
	Voltage = 28.8;
	DrawAmps = 30.0;
	Loading = 0;
	LoadHandle = 0;
	Level = 1;
}

mCompressor::mCompressor(mElectricObject* iSRC, mValve* iIn, mValve *iOut, double iMax, double iVoltage, double iDrawAmps){
	SRC = iSRC;
	InValve = iIn;
	OutValve = iOut;
	Max = iMax;
	Voltage = iVoltage;
	DrawAmps = iDrawAmps;
	Loading = 0;
	LoadHandle = 0;
	Level = 1;
}

void mCompressor::pLoad(double Amps) {

}

void mCompressor::pUnLoad(double Amps) {

}

void mCompressor::Connect(mElectricObject* NewSRC){
	if (Loading != 0)
		SRC->pUnLoad(DrawAmps);
	SRC = NewSRC;
	if (Loading != 0)
		SRC->pLoad(DrawAmps);
}

void mCompressor::Refresh(double dt){

	if (LoadHandle == 1 && SRC != 0 && Loading == 0) {
		SRC->pLoad(DrawAmps);
		LoadHandle = 0;
		Loading = 1;
	}
	if (LoadHandle == -1 && SRC != 0 && Loading != 0) {
		SRC->pUnLoad(DrawAmps);
		LoadHandle = 0;
		Loading = 0;
	}

	if (Loading == 1 && SRC->Volts > 20.0) {
        if(InValve->Open == 1 && OutValve->Open == 1) {
            double delta_p = InValve->GetPress() - OutValve->GetPress() + (Max * Level);
            if (delta_p < 0)
				delta_p = 0;

			double tdt = 0.0;
			double tFactor = .001;
			double new_delta_p = delta_p;
			while (tdt < dt && new_delta_p > 0) {
				mVolume Fanned = InValve->GetFlow(delta_p * tFactor);
				InValve->Parent->Space.Compute(tFactor);
				OutValve->Flow(Fanned);
				OutValve->Parent->Space.Compute(tFactor);
				tdt += .001;
				new_delta_p = InValve->GetPress() - OutValve->GetPress() + (Max * Level);
			}            
        } else {
            double delta_p = InValve->GetPress() - OutValve->GetPress();
            if (delta_p < 0)
				delta_p = 0;

			double tdt = 0.0;
			double tFactor = .001;
			double new_delta_p = delta_p;
			while (tdt < dt && new_delta_p > 0) {
				mVolume Fanned = InValve->GetFlow(delta_p * tFactor);
				InValve->Parent->Space.Compute(tFactor);
				OutValve->Flow(Fanned);
				OutValve->Parent->Space.Compute(tFactor);
				tdt += .001;
				new_delta_p = InValve->GetPress() - OutValve->GetPress() + (Max * Level);
			}            
		}

	}

}

mLiOHScrubber::mLiOHScrubber(){
	Space.Volume = 0;
	InValve.Set (0, 1.0, this);
	OutValve.Set(0, 1.0, this);
	LiOH_Mass = 0;
	for (int i=0;i<MAX_SUB;i++) {
		OutFlowMask[i] = 1;
		InFlowMask[i] = 1;
	}
}

mLiOHScrubber::mLiOHScrubber(double iVol, double iLiOH){
	LiOH_Mass = iLiOH;
	Space.Volume = iVol;
	InValve.Set (0, 1.0, this);
	OutValve.Set(0, 1.0, this);
	for (int i=0;i<MAX_SUB;i++) {
		OutFlowMask[i] = 1;
		InFlowMask[i] = 1;
	}
}

void mLiOHScrubber::Refresh(double dt) {

	if (LiOH_Mass > 0){
		double CO2_Mass = Space.Composition[SUBSTANCE_CO2].Mass;
		double CO2_Q = Space.Composition[SUBSTANCE_CO2].Q;
		double H20_Q = 0;
		double Consumed = CO2_Mass * (24.0 / 44.0);
		if (Consumed > LiOH_Mass){
			Consumed = LiOH_Mass;
		}
		double H2O_Produced = Consumed * (18.0 / 24.0);
		LiOH_Mass -= Consumed;
		Space.Composition[SUBSTANCE_CO2].Mass = 0; //Consumed * (44.0 / 24.0);
		Space.Composition[SUBSTANCE_CO2].Q = 0;
		//Space.Composition[SUBSTANCE_H2O].Mass = H2O_Produced;
		//Space.Composition[SUBSTANCE_H2O].Q = CO2_Q - (Consumed * (44.0 / 24.0) * -2036.307272727;

	}

	Space.Compute(dt);

}
*/
