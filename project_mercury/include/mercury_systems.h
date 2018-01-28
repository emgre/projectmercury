#ifndef _SYSTEMS

#define _SYSTEMS

#include "orbitersdk.h"

#define NULL 0

#define MAX_SUB					5

#define SUBSTANCE_O2			0
#define SUBSTANCE_H2			1
#define SUBSTANCE_H2O			2
#define SUBSTANCE_N2			3
#define SUBSTANCE_CO2			4

#define R_CONST					8309.280615

							//		O2			H2			H20			N2			CO2
const double MMASS		[MAX_SUB]=	{32,		2,			18,			28,			44};	
const double SPECIFICC	[MAX_SUB]=	{0.918,		1.434,		4.18,		1.040,		0.858};		//J/g-K .. assume constant
const double VAPENTH	[MAX_SUB]=	{213.13,	445.46,		2260,		198.83,		347};		//J/g
const double VAPPRESS	[MAX_SUB]=	{1314841,	4925221,	39441,		1528361,	493284};	//Pa @ 273.00K
const double VAPGRAD	[MAX_SUB]=	{6556,		19045,		680,		7228,		4800};		//Pa/K.. assume linear dependence of PV / K
const double L_DENSITY	[MAX_SUB]=	{1141,		70,			1000,		807,		1014};		//g/L @ 103kPa ..assume constant wrt. temp
const double BULK_MOD	[MAX_SUB]=	{32e6,		23e6,		2.18e6,		32e6,		32e6};		//Pa .. assume constant
const double CRITICAL_P [MAX_SUB]=  {350115,	89631,		1523741,	234421,		508833};	//Pa.. critical pressure
const double CRITICAL_T [MAX_SUB]=  {154.7,		33.2,		647.3,		126.2,		304.4};		//K


class mSubstance { 
public:
    mSubstance(){ };
	mSubstance(int iSubstType, double iMass, double iTemp);
	int SubstType;					//index of substance type
	double Mass;					// (gr)
	double Q;						// (J) total enthalpy (NOT thermal energy) 	
	double Press;					// partial pressure (Pa), computed using current Q ..
	
	void operator+= (mSubstance);	//add some block to this..
	void operator-= (mSubstance);   //substact this block from itself
	mSubstance operator* (double);	//returns a subst block that is "Ratio" part of the main (ie. 0.5 will generate half of the block)

	void SetTemp(double iTemp);		
	double GetTemp();		
};


class mVolume	{
public:
	mVolume();
	mVolume(double iVol);
	
	mSubstance Composition[MAX_SUB];      //all the substances can co-exist :)
	double Volume;					      //liters

	void operator+=(mVolume);		      //add two volumes together
	void operator+=(mSubstance);	      //or simply add some sub. to the volume 
	
	mVolume Break(double Vol, int* Mask); //break 'vol' liters from the volume ..into another volume
	
	int    GetMaxSub();				      //re-computes number of substances present in the volume
	double GetMass();				      //total mass inside the volume
	double GetQ();
	double GetPress();
	double GetTemp();

	void Compute(double DT);		      //levels temp troughout all subst...much like stirring a tank,only instanaeously
	void Void();					      //empty all inside the volume
private:
	void SetParams(double iVol);
};


class mSystemObject {
public:
	char         name[25];

	mSystemObject() { nextPtr = 0; };
	mSystemObject *nextPtr;		//the objects are linked..

	virtual void Refresh(double dt){ };
	virtual void Load(FILEHANDLE scn) { };
	virtual void Save(FILEHANDLE scn) { };
};

class mShipSystems { 
public:
	mSystemObject List;

	mShipSystems() { };
	~mShipSystems();


	mSystemObject* AddSystem(mSystemObject *object);
	void* GetComponent(char *component_name);
	void Refresh(double dt);
	void Load(FILEHANDLE scn);
	void Save(FILEHANDLE scn);
};



class mHydralicObject:public mSystemObject { 
public:
	mHydralicObject() { };
	virtual void Refresh(double dt){ };
};

class mTank;
class mValve				//valves are not h_objects, just "sockets" for piping
{
public:
	mValve();
	mValve  (int iOpen, double iSize, mTank* iParent);	
	void Set(int iOpen, double iSize, mTank* iParent);

	mTank* Parent;		          //pointer to the tank to which they belong
	int Open;	
	double Size;

	double GetPress();	          //press is used by Pipe to compute flow
	double GetTemp();
	
	int Flow(mVolume Block);     //block of substance flowing INTO  the valve
	mVolume GetFlow(double dPdT); //deltaP * deltaT gives us flow rate OUTOF(in volume)

};

class mTank:public mHydralicObject {
public:
	int InFlowMask[MAX_SUB];
	int OutFlowMask[MAX_SUB];
	double LeakRate; //gm/sec
	mVolume Space;
	mValve  InValve;
	mValve  OutValve;
	mValve  VentValve;

	mTank();
	mTank(char *iName, double iVol, double iLeakRate);

	virtual void operator+=(mSubstance);	      //or simply add some sub. to the Tank 

	virtual void Refresh(double dt);

	virtual int Flow(mVolume Block);
	virtual mVolume GetFlow(double vol);

	virtual void Load(FILEHANDLE scn);
	virtual void Save(FILEHANDLE scn);
};


class mPipe:public mHydralicObject {
public:
	int TypePipe;
	double Max;
	double Min;
	int Open;
	mValve* InValve;
	mValve* OutValve;

	mPipe();
	mPipe(char* iName, mValve* iIn, mValve* iOut, double iMax, double iMin);

	virtual void Refresh(double dt);
private:
	void SetParams(mValve* iIn, mValve* iOut, double iMax, double iMin);
};


class mVent:public mHydralicObject {
public:
	int Open;
	mValve* InValve;
	double Max;
	double Min;

	mVent();
	mVent(char* iName, mValve* iIn, double iMax, double iMin);

	virtual void Refresh(double dt);
private:
	void SetParams(mValve* iIn, double iMax, double iMin);
};


class mCrew: public mHydralicObject {
public:
	mTank* SRC;

	mCrew() { SRC = 0; };
	mCrew(char *iName, mTank* iSRC);

	virtual void Refresh(double dt);
};

class mElectricObject:public mSystemObject { 
public:
	mElectricObject* SRC;
	double DrawAmps;
	int PowerOn;
	double Volt;
	mElectricObject();
	mElectricObject(char *iName, mElectricObject* iSRC, double iDrawAmps);
	virtual void Refresh(double dt);
	virtual void LoadPower(double Amps);
	virtual void Connect(mElectricObject* NewSRC);
};

class mBus:public mElectricObject { 
public:
	mBus(char *iName);
	~mBus();
	virtual void Refresh(double dt);
	virtual void LoadPower(double Amps);
	virtual void Connect(mElectricObject* NewSRC);
	int Count();
	virtual void Load(FILEHANDLE scn) { };
	virtual void Save(FILEHANDLE scn) { };
	double power_load;	
private:
	mElectricObject* SRCs[20];
};

class mBattery: public mElectricObject {
public:
	mBattery(char* iName,double iPower, double iVoltage);
	double Power;
	double Voltage;
	virtual void LoadPower(double Amps);
	virtual void Refresh(double dt);
	virtual void Load(FILEHANDLE scn);
	virtual void Save(FILEHANDLE scn);
	double power_load;
};

/*
class mBattery: public mElectricObject {
public:
	double Power;
	int LoadCB;

	mBattery();
	mBattery(mElectricObject* iSRC, double iPower, double iVoltage, double iDrawAmps);
	virtual void pLoad(double Amps);
	virtual void pUnLoad(double Amps);
	virtual void Connect(mElectricObject* NewSRC);
	virtual void Refresh(double dt);
};

class mCompressor:public mElectricObject{
public:
	double Max;
	double Level;
	int Pumping;
	int Loaded;
	mValve* InValve;
	mValve* OutValve;

	mCompressor();
	mCompressor(mElectricObject* iSRC, mValve* iIn, mValve* iOut, double iMax, double iVoltage, double iDrawAmps);
	virtual void pLoad(double Amps);
	virtual void pUnLoad(double Amps);
	virtual void Connect(mElectricObject* NewSRC);
	virtual void Refresh(double dt);
};

class mLiOHScrubber:public mTank {
public:
	double  LiOH_Mass;
	mLiOHScrubber();
	mLiOHScrubber(double iVol, double iLiOH);

	virtual void Refresh(double dt);

};

*/
#endif 
