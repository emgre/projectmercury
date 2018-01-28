#ifndef __MERCURY_SEQUENCER_H
#define __MERCURY_SEQUENCER_H

#include "resource.h"
#include "orbitersdk.h"
#include "multi_stage5.h"
#include "matrix.h"
#include "vectors.h"
#include < GL\gl.h >                                
#include < GL\glu.h >
#include <math.h>
#include "orbitelements.h"
//#include "OrbiterSoundSDK.h"
#include "mercury_systems.h"
//#include "OrbIPCC.h"
#include <stdlib.h>
#include <time.h>
#include <windows.h>

const int SOUND_THRUSTER   = 1;
const int SOUND_COUNTDOWN  = 2;
const int SOUND_STAGESEP   = 3;
const int SOUND_TOWERJETT  = 4;
const int SOUND_MERCSEP    = 5;
const int SOUND_DECOMP     = 6;
const int SOUND_REPRESS    = 7;
const int SOUND_FUSECLICK  = 8;
const int SOUND_PULLPUSH   = 9;
const int SOUND_RINGPULL   = 10;
const int SOUND_SWITCH     = 11;
const int SOUND_WARNING    = 12;
const int SOUND_DROGUE     = 13;
const int SOUND_RETRO1     = 14;
const int SOUND_RETRO2     = 15;
const int SOUND_RETRO3     = 16;
const int SOUND_RETROSEP   = 17;
const int SOUND_COMMCHECK  = 18;
const int SOUND_SPLASHDOWN = 19;
const int SOUND_CHUTE      = 20;
const int SOUND_LANDINGBAG = 21;
const int SOUND_BLOODPRESS = 22;
const int SOUND_RATTLE     = 23;
const int SOUND_RE_RATTLE  = 24;


PROPELLANT_HANDLE fuel_auto;
PROPELLANT_HANDLE fuel_manual;
PROPELLANT_HANDLE fuel_retro[3];
PROPELLANT_HANDLE fuel_posigrade[3];
PROPELLANT_HANDLE fuel_abort;
PROPELLANT_HANDLE fuel_adaptPyro;
PROPELLANT_HANDLE fuel_RetroPyro;

THRUSTER_HANDLE thruster_man_py[4];
THRUSTER_HANDLE thruster_man_roll[4];
THRUSTER_HANDLE thruster_auto_py[4];
THRUSTER_HANDLE thruster_auto_roll[4];
THRUSTER_HANDLE thruster_auto_py_1lb[4];
THRUSTER_HANDLE thruster_auto_roll_1lb[4];
THRUSTER_HANDLE thruster_abort[3];
THRUSTER_HANDLE thruster_retro[3];
THRUSTER_HANDLE thruster_posigrade[3];
THRUSTER_HANDLE thruster_adaptPyro[3];
THRUSTER_HANDLE thruster_RetroPyro[3]; 

THGROUP_HANDLE group_retro[3];
THGROUP_HANDLE group_posigrade;
THGROUP_HANDLE group_pitch_up;
THGROUP_HANDLE group_pitch_down;
THGROUP_HANDLE group_yaw_left;
THGROUP_HANDLE group_yaw_right;
THGROUP_HANDLE group_roll_left;
THGROUP_HANDLE group_roll_right;
THGROUP_HANDLE group_abort;
THGROUP_HANDLE auto_pitch_up;
THGROUP_HANDLE auto_pitch_down;
THGROUP_HANDLE auto_yaw_left;
THGROUP_HANDLE auto_yaw_right;
THGROUP_HANDLE auto_roll_left;
THGROUP_HANDLE auto_roll_right;
THGROUP_HANDLE group_adaptPyro;
THGROUP_HANDLE group_RetroPyro;

THGROUP_HANDLE auto_pitch_up_1lb;
THGROUP_HANDLE auto_pitch_down_1lb;
THGROUP_HANDLE auto_yaw_left_1lb;
THGROUP_HANDLE auto_yaw_right_1lb;
THGROUP_HANDLE auto_roll_left_1lb;
THGROUP_HANDLE auto_roll_right_1lb;

THGROUP_HANDLE man_pitch_up;
THGROUP_HANDLE man_pitch_down;
THGROUP_HANDLE man_yaw_left;
THGROUP_HANDLE man_yaw_right;
THGROUP_HANDLE man_roll_left;
THGROUP_HANDLE man_roll_right;


THRUSTER_HANDLE th_group[4];

const int MERCURY_ATT_AUTO = 0;
const int MERCURY_ATT_MANUAL = 1;
int    mercury_att_mode = MERCURY_ATT_AUTO;


const int PITCH_AXIS = 0;
const int YAW_AXIS   = 1;
const int ROLL_AXIS  = 2;

const double AXIS_CLOCK      = -1;
const double AXIS_COUNTER    = 1;
const double AXIS_CLOCKLOW   = -.1;
const double AXIS_COUNTERLOW = .1;
const double AXIS_STOP       = 0;

const int MANUAL_RATECMD = 0;
const int MANUAL_DIRECT = 1;

const int AUTO_ON = 0;
const int AUTO_OFF = 1;

const int ASCS_SEP      = 0;
const int ASCS_DAMP     = 1;
const int ASCS_RETROATT = 2;
const int ASCS_REENTRY  = 3;
const int ASCS_ROLL     = 4;

const int LIGHTS_ON  = 0;
const int LIGHTS_OFF = 1;
const int LIGHTS_BOTH = 2;


const int IND_ABORTJETTISONED  = 0;
const int IND_CAPSULESEP       = 1;
const int IND_RETROSEQUENCE    = 2;
const int IND_RETROATTITUDE    = 3;
const int IND_RETROFIRE        = 4;
const int IND_RETROJETT        = 5;
const int IND_05G              = 6;
const int IND_MAIN             = 7;
const int IND_LANDINGBAG       = 8;
const int IND_RESCUE           = 9;


const int WARN_STBYACAUTO      = 0;
const int WARN_CABIN_PRESS     = 1;
const int WARN_O2_EMER         = 2;
const int WARN_SUIT_H20        = 3;
const int WARN_CABIN_H20       = 4;
const int WARN_FUEL_QUAN       = 5;
const int WARN_RETRO_WARN      = 6;
const int WARN_RETRO_RESET     = 7;

const double RSCS_MAXRATE = 10*RAD; //10 DEG/SEC

#define AID_AUTOPILOT 0
#define AID_GLOBEPANEL 1
#define AID_GAUGE_ROLL 2
#define AID_GAUGE_YAW 3
#define AID_GAUGE_PITCH 4
#define AID_GAUGE_RATE 5
#define AID_GAUGE_FUEL 6
#define AID_GAUGE_ALT 7
#define AID_ABORT 8
#define AID_SEQ_ABORTJETT 9
#define AID_SEQ_CAPSULESEP 10
#define AID_SWITCH_ABORTJETT 11
#define AID_SWITCH_CAPSULESEP 12
#define AID_SWITCH_AUTOMATICMODE 13
#define AID_PULL_MANUAL_MODE 14
#define AID_PULL_AUTO_ROLL_MODE 15
#define AID_PULL_AUTO_YAW_MODE 16
#define AID_PULL_AUTO_PITCH_MODE 17
#define FC_GAUGE_ROLL 18
#define FC_GAUGE_YAW 19
#define FC_GAUGE_PITCH 20
#define FC_GAUGE_RATE 21
#define FC_GAUGE_FUEL 22
#define AID_SWITCH_SQUIB 23
#define AID_SWITCH_RETROAUTOJETT 24
#define AID_SWITCH_RETRODELAY 25
#define AID_PUSH_RETROSEQUENCE 26
#define AID_SWITCH_RETROATTITUDE 27
#define AID_PUSH_RETROFIRE 28
#define AID_PUSH_RETROJETT 29
#define AID_SEQ_RETROSEQUENCE 30
#define AID_SEQ_RETROATTITUDE 31
#define AID_SEQ_RETROFIRE 32
#define AID_SEQ_RETROJETT 33
#define AID_PUSH_05G 34
#define AID_PUSH_DROGUE 35
#define AID_SWITCH_SNORKEL 36
#define AID_SWITCH_MAIN 37
#define AID_SWITCH_RESERVE 38
#define AID_SWITCH_LANDINGBAG 39
#define AID_SEQ_05G 40
#define AID_SEQ_MAIN 41
#define AID_SEQ_LANDINGBAG 42

#define AID_SWITCH_RSCS 43
#define AID_GAUGE_ACCEL 44
#define AID_GAUGE_DESCENT 45
#define AID_SWITCH_GYRO 46
#define AID_RETROGRADE_TIMER 47
#define AID_PUSH_TIMEZERO 48
#define FC_TIMER 49
#define AID_SEQ_RESCUE 50
#define AID_SWITCH_RESCUE 51
#define AID_SWITCH_PHOTO_LIGHTS 52
#define AID_SWITCH_LIGHTS 53
#define AID_SWITCH_TLM_FREQ 54
#define AID_SWITCH_LIGHT_TEST 55
#define AID_SWITCH_MANEUVER 56
#define AID_HANDLE_DECOMP 57
#define AID_HANDLE_REPRESS 58
#define PERI_VIEW_SWITCH 59
#define PERI_ALT_KNOB 60
#define PERI_ALTITUDE 61
#define PERI_ALT_IND 62

#define AID_GAUGE_CABIN_PRESS 63
#define AID_GAUGE_CABIN_TEMP  64
#define AID_GAUGE_STEAM_TEMP  65
#define AID_GAUGE_SUIT 66
#define AID_GAUGE_OXYGEN 67
#define AID_SWITCH_SUIT_FAN 68
#define AID_SWITCH_CABIN_FAN 69

#define AID_GAUGE_DC_VOLTS 70
#define AID_KNOB_DC_VOLTS 71
#define AID_GAUGE_DC_AMPS 72
#define AID_GAUGE_AC_VOLTS 73
#define AID_KNOB_AC_VOLTS 74
#define AID_SWITCH_INLET_VALVE 75
#define AID_SWITCH_AUDIO_BUS 76
#define AID_SWITCH_AC_BUS 77
#define AID_SWITCH_AMMETER 78
#define AID_SWITCH_STBY_BTRY 79
#define AID_SWITCH_ISOL_BTRY 80
#define AID_WARN_STBY_AC_AUTO 81
#define AID_SWITCH_FANS_AC_BUS 82

#define AID_PUSH_KEY 83
#define AID_SWITCH_COMM_SELECT 84
#define AID_SWITCH_UHF_SELECT 85
#define AID_SWITCH_TRANSMIT 86
#define AID_SWITCH_COMM_BEACON 87
#define AID_SWITCH_VOX 88


#define AID_SWITCH_WARN_LIGHTS 89
#define AID_WARN_CABIN_PRESS 90
#define AID_WARN_O2_EMER 91
#define AID_WARN_SUIT_H20 92
#define AID_WARN_CABIN_H20 93
#define AID_WARN_FUEL_QUAN 94
#define AID_WARN_RETRO_WARN 95
#define AID_WARN_RETRO_RESET 96
#define AID_SWITCH_CABIN_PRESS 97
#define AID_SWITCH_O2_EMER 98
#define AID_SWITCH_SUIT_H20 99
#define AID_SWITCH_CABIN_H20 100
#define AID_SWITCH_FUEL_QUAN 101
#define AID_SWITCH_RETRO_WARN 102
#define AID_SWITCH_RETRO_RESET 103
#define AID_PUSH_BLOOD_PRESS_START 104
#define AID_PUSH_BLOOD_PRESS_STOP 105
#define AID_FUSE_SUIT_FAN 106
#define AID_FUSE_INVR_CONTROL 107
#define AID_FUSE_RETRO_JETT 108
#define AID_FUSE_RETRO_MAN 109
#define AID_FUSE_PROGRAMMER 110
#define AID_FUSE_BLOOD_PRESS 111


#define AID_FUSE_PHASE_SHIFTER 112
#define AID_FUSE_EMER_CAP_SEP 113
#define AID_FUSE_EMER_ESCAPE_RCKT 114
#define AID_FUSE_TOWER_SEP_CONTRL 115
#define AID_FUSE_EMER_TOWER_SEP 116
#define AID_FUSE_EMER_TOWER_JETT 117
#define AID_FUSE_EMER_POSGRD 118
#define AID_FUSE_AUX_BCN 119
#define AID_FUSE_RETRO_ONE 120
#define AID_FUSE_RETRO_TWO 121
#define AID_FUSE_RETRO_THREE 122
#define AID_FUSE_EMER_RETRO_SEQ 123
#define AID_FUSE_EMER_RETRO_JETT 124
#define AID_FUSE_ASCS_05G 125
#define AID_FUSE_EMER_05G 126
#define AID_FUSE_EMER_DROUGE_DEPLOY 127
#define AID_FUSE_EMER_MAIN_DEPLOY 128
#define AID_FUSE_RESERVE_DEPLOY 129
#define AID_FUSE_EMER_RESERVE_DEPLOY 130
#define AID_FUSE_EMER_LAND_BAG 131
#define AID_FUSE_EMER_RESCUE_AIDS 132
#define AID_FUSE_PERISCOPE 133
#define AID_FUSE_ANT_SWITCH 134
#define AID_FUSE_COMV_RCVRA 135
#define AID_FUSE_TRIM_HIFREQ 136
#define PERI_FILTER_SWITCH 137

const int FAIL_NONE             = 0;
const int FAIL_TOWER_JETT       = 1;
const int FAIL_CAP_SEP          = 2;
const int FAIL_RETRO_SEQ        = 3;
const int FAIL_RETRO_FIRE       = 4;
const int FAIL_RETRO_JETT       = 5;
const int FAIL_05G_ROLL         = 6;
const int FAIL_DROGUE           = 7;
const int FAIL_MAIN             = 8;
const int FAIL_LAND_BAG         = 9;
const int FAIL_ABORT            = 10;
const int FAIL_ABORT_TOWER_JETT = 11;
const int FAIL_ABORT_CAP_SEP    = 12;


const int STAGE_ATLAS_BOOSTER    = 0;
const int STAGE_ATLAS_SUBSTAINER = 1;
const int STAGE_MERCURY_ABORT    = 3;
const int STAGE_MERCURY_RETRO    = 4;
const int STAGE_MERCURY_CAPSULE  = 5;

const int FUSE_ONE = 0;
const int FUSE_OFF = 1;
const int FUSE_TWO = 2;

const int WARN_OFF = 0;
const int WARN_ON  = 1;

const int SEQ_CLEAR = 0;
const int SEQ_RED = 1;
const int SEQ_GREEN = 2;

const int AUTO_ASCS    = 0;
const int AUTO_AUXDAMP = 1;
const int AUTO_FBW     = 2;

const int SWITCH_LEFT   = 0;
const int SWITCH_MIDDLE = 1;
const int SWITCH_RIGHT  = 2;

const int PUSH_COVERED = 0;
const int PUSH_UP      = 1;
const int PUSH_DOWN    = 2;

const int RETRO_NORM = 0;
const int RETRO_INST = 1;

const int RETROATT_AUTO   = 0;
const int RETROATT_BYPASS = 1;

const int SWITCH_ARM   = 0;
const int SWITCH_OFF   = 1;

const int LB_AUTO = 0;
const int LB_OFF  = 1;
const int LB_MAN  = 2;

const int RSCS_AUTO = 0;
const int RSCS_RATE = 1;

const int RESCUE_AUTO   = 0;
const int RESCUE_MAN    = 1;

const int GYRO_NORM = 0;
const int GYRO_FREE = 1;
const int GYRO_CAGED = 2;

const int RETRO_INC_MIN  = 0;
const int RETRO_INC_SEC  = 1;
const int RETRO_OFF      = 2;
const int RETRO_DEC_SEC  = 3;
const int RETRO_DEC_MIN  = 4;


typedef struct {
	HINSTANCE hDLL;
	HFONT font[2];
	DWORD col[4];
	HBRUSH brush[5];
	HPEN pen[4];
} GDIParams;

GDIParams g_Param;

void DrawLine (HDC hDC, int x1, int y1, int x2, double y2, HPEN pen)
{
	HGDIOBJ oldObj;
	oldObj = SelectObject (hDC, pen);
	MoveToEx (hDC, x1, y1, 0); 
	LineTo (hDC, x2, (int)y2);
	SelectObject (hDC, oldObj);
}


int LoadOGLBitmap(char *filename)
{
   unsigned char *l_texture;
   int l_index, l_index2=0;
   FILE *file;
   BITMAPFILEHEADER fileheader; 
   BITMAPINFOHEADER infoheader;
   RGBTRIPLE rgb; 
   int num_texture=1; //we only use one OGL texture ,so...
   

   if( (file = fopen(filename, "rb"))==NULL) return (-1); 
   fread(&fileheader, sizeof(fileheader), 1, file); 
   fseek(file, sizeof(fileheader), SEEK_SET);
   fread(&infoheader, sizeof(infoheader), 1, file);

   l_texture = (byte *) malloc(infoheader.biWidth * infoheader.biHeight * 4);
   memset(l_texture, 0, infoheader.biWidth * infoheader.biHeight * 4);

   for (l_index=0; l_index < infoheader.biWidth*infoheader.biHeight; l_index++)
   { 
      fread(&rgb, sizeof(rgb), 1, file); 

      l_texture[l_index2+0] = rgb.rgbtRed; // Red component
      l_texture[l_index2+1] = rgb.rgbtGreen; // Green component
      l_texture[l_index2+2] = rgb.rgbtBlue; // Blue component
      l_texture[l_index2+3] = 255; // Alpha value
      l_index2 += 4; // Go to the next position
   }

   fclose(file); // Closes the file stream

   glBindTexture(GL_TEXTURE_2D, num_texture);
   
   glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
   glTexImage2D(GL_TEXTURE_2D, 0, 4, infoheader.biWidth, infoheader.biHeight, 
	                               0, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);
   


   free(l_texture); 

return (num_texture);
};


class ADI{
public:
   void *void_hpbuffer;
   int type;							//instrument registration number for run-time ID
   int ScrX;
   int ScrY;			//coords on screen
   int idx;			//index on the panel list 
   int init;
   float sphere_vert[256][3];
   float sphere_norm[256][3];
   float sphere_tex[256][2];
   unsigned int sphere_index[600];
   void *p_tex;
   int tri; //number of triangle strip
   int list_name; //we store the rendering into a display list
   double radius;
   int function_mode;	//reference / GDC / Horizon
   int orbital_ecliptic;//orbital GDC or ecliptic
   vector3 reference;
   vector3 now;
   vector3 target;
   double over_rate;
   //some stuff for OpenGL
   HDC		   hDC2;
   HGLRC       hRC;
   HBITMAP	   hBMP;
   HBITMAP hBMP_old;
   ADI(int x,int y);
   virtual ~ADI();
   void InitGL();
   void MoveBall();
   void SetOrbital(VESSEL *vessel);
   void SetLocation(VESSEL *vessel);
   void SetEcliptic(VESSEL *vessel);
   void SetEquatorial(VESSEL *vessel);
   void SetReference(VESSEL *vessel);
   void GetReference(VESSEL *vessel);
   void RegisterMe(int index);
   void PaintMe(VESSEL *vessel, SURFHANDLE surf, SURFHANDLE hBorder);
   void RefreshMe(VESSEL *vessel, SURFHANDLE surf, SURFHANDLE hBorder);
};

ADI::ADI(int x,int y)
{
	type= 44; //ADI ball
	init=0;
	ScrX=x;
	ScrY=y;
	radius=10;
	int i;
	float trad;
	//double Pi=acos(-1);
	int indx;
	function_mode=0;//GDC;
	orbital_ecliptic=-1; //orbital GDC;
	reference.x=0.0;
	reference.y=0.0;
	reference.z=0.0;//ecliptic is also first reference
	now.x=0.37;now.y=-1.2;now.z=0.5;
	
	float norm;
	//we define the ADI sphere to be rendered by OpenGL
	//we use a 6 by 12 sphere, with 84 vertices and 72 triangles
	//bottom point
	tri=0;//number of triangle strips
	for (i=0;i<16;i++)
		for (int j=0;j<16;j++) { 
			trad=(float)(cos(-PI/2+PI/15*i)*radius);
			indx=i*16+j;
//			sphere_vert[indx][0]=cos(2*acos(-1)/16*j)*trad;
//			sphere_vert[indx][1]=sin(2*acos(-1)/16*j)*trad;
//			sphere_vert[indx][2]=sin(-PI/2+PI/15*i)*radius;
//			sphere_tex[indx][0]=j/16.0;
//			sphere_tex[indx][1]=i/15.0;

			sphere_vert[indx][0]=(float)(cos(2*PI/15*j)*trad);
			sphere_vert[indx][1]=(float)(sin(2*PI/15*j)*trad);
		 	sphere_vert[indx][2]=(float)(sin(-PI/2+PI/15*i)*radius);
		 	sphere_tex[indx][0]=j/15.0f;
		 	sphere_tex[indx][1]=i/15.0f;			
			norm=sqrt(pow(sphere_vert[indx][0],2)+
				   pow(sphere_vert[indx][1],2)+
				   pow(sphere_vert[indx][2],2));
			sphere_norm[indx][0]=sphere_vert[indx][0]/norm;
			sphere_norm[indx][1]=sphere_vert[indx][1]/norm;
			sphere_norm[indx][2]=sphere_vert[indx][2]/norm;
			if (i>0) {
				sphere_index[tri++]=indx;
				sphere_index[tri++]=indx-16;
			};
		};

};

void ADI::InitGL() {
	GLuint      PixelFormat;  
	BITMAPINFOHEADER BIH;
	int iSize=sizeof(BITMAPINFOHEADER);
	BIH.biSize=iSize;
	BIH.biWidth=160;				//size of the sphere is 160x160
	BIH.biHeight=160;
	BIH.biPlanes=1;
	BIH.biBitCount=16;//default is 16.
	BIH.biCompression=BI_RGB;
	BIH.biSizeImage=0;
	void* m_pBits;
	hDC2=CreateCompatibleDC(NULL);//we make a new DC and DIbitmap for OpenGL to draw onto
	static  PIXELFORMATDESCRIPTOR pfd2;
	DescribePixelFormat(hDC2,1,sizeof(PIXELFORMATDESCRIPTOR),&pfd2);//just get a random pixel format.. 
	BIH.biBitCount=pfd2.cColorBits;//to get the current bit depth.. !?
	hBMP=CreateDIBSection(hDC2,(BITMAPINFO*)&BIH,DIB_RGB_COLORS,&m_pBits,NULL,0);
	hBMP_old=(HBITMAP)SelectObject(hDC2,hBMP);
	static  PIXELFORMATDESCRIPTOR pfd={                             // pfd Tells Windows How We Want Things To Be
        sizeof(PIXELFORMATDESCRIPTOR),                              // Size Of This Pixel Format Descriptor
        1,                                                          // Version Number
		PFD_DRAW_TO_BITMAP |                                        // Format Must Support Bitmap Rendering
        PFD_SUPPORT_OPENGL |									
		PFD_SUPPORT_GDI,											// Format Must Support OpenGL,                                           
		0,//        PFD_TYPE_RGBA,                                              // Request An RGBA Format
        16,															// Select Our Color Depth
        0, 0, 0, 0, 0, 0,                                           // Color Bits Ignored
        0,//1,                                                          // No Alpha Buffer
        0,                                                          // Shift Bit Ignored
        0,                                                          // No Accumulation Buffer
        0, 0, 0, 0,                                                 // Accumulation Bits Ignored
        0,//16,                                                         // 16Bit Z-Buffer (Depth Buffer)  
        0,                                                          // No Stencil Buffer
        0,                                                          // No Auxiliary Buffer
        0,//PFD_MAIN_PLANE,                                             // Main Drawing Layer
        0,                                                          // Reserved
        0, 0, 0                                                     // Layer Masks Ignored
    };
	pfd.cColorBits=pfd2.cColorBits;//same color depth needed.
	DWORD code;
	code=GetLastError();
	PixelFormat=ChoosePixelFormat(hDC2,&pfd);// now pretend we want a new format
	int ret;
	ret=SetPixelFormat(hDC2,PixelFormat,&pfd);
	code=GetLastError();
	hRC=wglCreateContext(hDC2);
	ret=wglMakeCurrent(hDC2,hRC);					//all standard OpenGL init so far

//We load the texture
	int texture_index=LoadOGLBitmap("Textures\\merc_globe.dds");
	if (texture_index>0) glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);                        // Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);           // Panel Background color
	glClearDepth(1.0f);                             // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);                        // Enables Depth Testing
	glDepthFunc(GL_LESS);                           // The Type Of Depth Testing To Do
	glViewport(0,0,160,160);                       // Reset The Current Viewport
	glMatrixMode(GL_PROJECTION);                        // Select The Projection Matrix
	glLoadIdentity();                                   // Reset The Projection Matrix
	gluPerspective(45.0f,1.0,1.0f,1000.0f);      
	glMatrixMode(GL_MODELVIEW);                         // Select The Modelview Matrix          
	glLoadIdentity();                                   // Reset The Projection Matrix

	//some ambiental setup
	GLfloat light_position[]={10.0,20.0f,10.0f,0.0f};
	GLfloat light_diffuse[]={1.0f,0.2f,0.2f,1.0f};
	GLfloat light_ambient[]={0.8f,0.6f,0.6f,1.0f};
	GLfloat mat_specular[]={0.3f,0.3f,0.3f,1.0f};
	GLfloat mat_shin[]={5.0f};
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	//glEnable(GL_LIGHTING);
	//glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
	//glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	//glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
	//glLightfv(GL_LIGHT0,GL_SPECULAR,mat_specular);
	//glEnable(GL_LIGHT0);


	//defining our geometry and composing a display list;
	glEnableClientState(GL_NORMAL_ARRAY);
	if (texture_index>0) glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3,GL_FLOAT,0,sphere_vert);
	glNormalPointer(GL_FLOAT,0,sphere_norm);
	if (texture_index>0) glTexCoordPointer(2,GL_FLOAT,0,sphere_tex);
	list_name=glGenLists(1);
	glNewList(list_name,GL_COMPILE);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);             // Clear The Screen And The Depth Buffer        
		glColor3f(1.0,1.0,1.0);   
		glDrawElements(GL_TRIANGLE_STRIP,tri,GL_UNSIGNED_INT,sphere_index);
	glEndList();

	init=1;		//that's it. If we made it so far, we can use OpenGL
};

ADI::~ADI()
{
	wglMakeCurrent(NULL,NULL);	//standard OpenGL release
	wglDeleteContext(hRC);
	hRC=NULL;
	SelectObject(hDC2,hBMP_old);//remember to delete DC and bitmap memory we created
	DeleteObject(hBMP);
	DeleteDC(hDC2);

};
void ADI::RegisterMe(int index) {
	oapiRegisterPanelArea(index,_R(ScrX,ScrY,ScrX+141,ScrY+141),PANEL_REDRAW_ALWAYS,PANEL_MOUSE_IGNORE,PANEL_MAP_CURRENT);
	idx=index;
};
void ADI::SetOrbital(VESSEL *vessel)//this is quite heavy. API could use a way to get orientation w.r.t. orbit
{
	OBJHANDLE planet=vessel->GetGravityRef();
	VECTOR3 gpos,pos,vel,vel2;
	vector3 Vpos,Vvel,Vnorm;
	vessel->GetGlobalPos(gpos);
	vessel->GetRelativePos(planet,pos);
	vessel->GetRelativeVel(planet,vel);
	Vpos=_vector3(pos.x,pos.y,pos.z);
	Vnorm=_vector3(vel.x,vel.y,vel.z);
	Vnorm=Vpos*Vnorm;//this is normal on orbital plane;
	Vnorm.selfnormalize();
 
	vel.x+=gpos.x;vel.y+=gpos.y;vel.z+=gpos.z;
	vessel->Global2Local(vel,vel2);
	Vvel=_vector3(vel2.x,vel2.y,vel2.z);//this is V vector in local frame
	Vvel.selfnormalize();
	Vnorm.x+=gpos.x;Vnorm.y+=gpos.y;Vnorm.z+=gpos.z;
	vessel->Global2Local(_V(Vnorm.x,Vnorm.y,Vnorm.z),vel2);
	Vnorm=_vector3(vel2.x,vel2.y,vel2.z);//and this is N vector in local frame
	Vnorm.selfnormalize();
	vector3 local_up=Vnorm;
	vector3 local_front=Vnorm*_vector3(0,0,1);
 
	Vnorm.z=0;Vnorm.selfnormalize();//all we need from here is roll now
 // ***********************
	double roll=PI-atan2(Vnorm.x,Vnorm.y);
 // ************************
	double pitch=-(PI/2-local_up.angle(_vector3(0,0,1)));
 //*************************
 
	double heading=Vvel.angle(local_front);
	vector3 local_head=local_front*Vvel;
	local_head.selfnormalize();//need to bring heading to quadtrant. ugly...
	if (local_head.z*local_up.z>0) heading=-heading;
	target.x=heading+PI;
	target.y=pitch;
	target.z=roll;
};
 
void ADI::SetLocation(VESSEL *vessel)//this is quite heavy. API could use a way to get orientation w.r.t. orbit
{

	double longitude = 0.0;
	double latitude = 0.0;
	double radius = 0.0;
	double heading = 0.0;
	double tempD = 0.0;
	 
	vessel->GetEquPos(longitude, latitude, radius);
	target.x=-longitude;//heading+PI;
	target.y=latitude;//pitch;
	target.z=heading;//roll;
	target.x+=PI/2;//long;
	target.y+=0;//lat
	target.z+=-PI/2;
};


void ADI::SetEcliptic(VESSEL *vessel) {	
	
    VESSELSTATUS vstat;vessel->GetStatus(vstat);
	vstat.arot.z+=PI/2; //roll is referenced to horizontal ?!!?
	vstat.arot.x+=PI/2;
	vstat.arot.x=2*PI-vstat.arot.x;
	target.x=vstat.arot.x;
	target.y=vstat.arot.y;
	target.z=vstat.arot.z;

};
void ADI::SetReference(VESSEL *vessel) {	
	VESSELSTATUS vstat;vessel->GetStatus(vstat);
	vstat.arot.z+=acos(-1.0f)/2; //roll is referenced to horizontal ?!!?
	vstat.arot.x+=PI/2;
	vstat.arot.x=2*PI-vstat.arot.x;
	vstat.arot.x-=reference.x;vstat.arot.y-=reference.y;vstat.arot.z-=reference.z;
	target.x=vstat.arot.x;//*cos(vstat.arot.z)+sin(vstat.arot.z)*vstat.arot.y;
	target.y=vstat.arot.y;//*cos(vstat.arot.z)-sin(vstat.arot.z)*vstat.arot.x;
	target.z=vstat.arot.z;

};
void ADI::SetEquatorial(VESSEL *vessel){
	double pitch=vessel->GetPitch();
	double heading;
	oapiGetHeading(vessel->GetHandle(),&heading);
	heading+=PI/2;
	heading=2*PI-heading;
	//heading+=PI;
	double bank=-(vessel->GetBank());
	target.x=heading;
	target.y=pitch;
	target.z=bank;
}

void ADI::GetReference(VESSEL *vessel) {	
	VESSELSTATUS vstat;vessel->GetStatus(vstat);
	vstat.arot.z+=acos(-1.0f)/2;
	//vstat.arot.x+=PI	/2;
	vstat.arot.x=2*PI-vstat.arot.x;
	reference.x=vstat.arot.x;
	reference.y=vstat.arot.y;
	reference.z=vstat.arot.z;

}
void ADI::MoveBall() {
	double delta;
	
    over_rate=0.0;
    delta=target.z-now.z;
	if (delta>0.05) {if (delta>PI) {now.z+=2*PI;MoveBall();
									return;}
						now.z+=0.05;over_rate=1.;}
	else if (delta<-0.05){ if (delta<-PI) {now.z-=2*PI;MoveBall();
								return;}
						now.z-=0.05;over_rate=1.;}
	else now.z+=delta;

	delta=target.y-now.y;
	if (delta>0.05) {if (delta>PI) {now.y+=2*PI;MoveBall();
										return;}
					now.y+=0.05;over_rate=1.;}
	else if (delta<-0.05) {if (delta<-PI) {now.y-=2*PI;MoveBall();
								return;}
						now.y-=0.05;over_rate=1.;}
	else now.y+=delta;

	delta=target.x-now.x;
	if (delta>0.05) {if (delta>PI) {now.x+=2*PI;MoveBall();
									return;}
						now.x+=0.05;over_rate=1.;}
	else if (delta<-0.05) {if (delta<-PI) {now.x-=2*PI;MoveBall();
								return;}
						now.x-=0.05;over_rate=1.;}
	else now.x+=delta;

	glLoadIdentity(); 
	gluLookAt(0.0,-35.0,0.0, 0.0,0.0,0.0,0.0,0.0,1.0);
	glRotatef((GLfloat)(-now.z/PI*180.0),0.0f,1.0f,0.0f);
	glRotatef((GLfloat)(now.y/PI*180.0),1.0f,0.0f,0.0f);
	glRotatef((GLfloat)(now.x/PI*180.0),0.0f,0.0f,1.0f);

}

void ADI::PaintMe(VESSEL *vessel, SURFHANDLE surf, SURFHANDLE hBorder)
{
	HGDIOBJ oldObj;
	if (!init) InitGL();
  
	SetLocation(vessel);
	MoveBall();
	glCallList(list_name);	//render
	glFlush();
	glFinish();

	HDC hDC=oapiGetDC(surf);

	BitBlt(hDC,5,5,130,130,hDC2,15,15,SRCCOPY);//then we bitblt onto the panel. wish there

	oldObj = SelectObject (hDC, g_Param.pen[0]);
	MoveToEx(hDC, 71, 0, 0);
	LineTo(hDC,71,141);
	MoveToEx(hDC, 0, 71, 0);
	LineTo(hDC,141,71);
	SelectObject(hDC, oldObj);
	oldObj = SelectObject (hDC, g_Param.pen[0]);
	//Arc (hDC, 32, 74, 92, 134, 62, 74, 62, 74);
	Arc (hDC, 56, 56, 86, 86, 71, 56, 71, 56);
	SelectObject(hDC, oldObj);

	oapiReleaseDC(surf,hDC);		   // was a faster way ...
	oapiBlt(surf,hBorder,0,0,0,0,139,139,0xFFFFFF);

}

void ADI::RefreshMe(VESSEL *vessel, SURFHANDLE surf, SURFHANDLE hBorder)
{
	PaintMe(vessel, surf, hBorder);
}


const int nsurf = 28; // number of bitmap handles
const int nprimary = 3; // number of bitmap handles

class Mercury_ControlPanel: public IControlPanel
{
public:
	SURFHANDLE srf[nsurf];  // handles for panel bitmaps
	MESHHANDLE hPanelMesh;
	Mercury_ControlPanel();
	~Mercury_ControlPanel();
	void ParseSystem(VESSEL *vessel, FILEHANDLE scn);
	void ParseLine (VESSEL *vessel, char *line, void *vs);
	void SaveState (VESSEL *vessel, FILEHANDLE scn);
	void Timestep (VESSEL *vessel, double simt);
	void DoTelemetry ();
	//bool LoadPanel (VESSEL *vessel, int id, PANELHANDLE hPanel, DWORD viewW, DWORD viewH);
	bool LoadPanel (VESSEL *vessel, int id);
	bool PanelRedrawEvent (VESSEL *vessel, int id, int event, SURFHANDLE surf);
	bool PanelMouseEvent (VESSEL *vessel, int id, int event, int mx, int my);
	void ReleaseSurfaces();
	void Aborted();
	void AbortJettisoned();
	void AbortWarn();
	void CapsuleSep();
	void CapsuleWarn();
	void RetroSequence();
	void RetroAttitude(bool in_attitude);
	void RetroFire(int retro_abort);
	void RetroJett(bool jett_abort);
	void CabinPressWarn(int warning) ;
	void FuelQuanWarn(int warning);
	void RetroWarn(int warning);
	void O2EmergWarn(int warning);
	void Roll05G();
	void MainChute();
	void LandingBag();
	void LandingBagWarn();
	void StartClock();
	void setAutoPilot(bool autopilot);
	void setCapsuleSep(bool capsulesep);
	void setAbortJettisoned(bool abortjettisoned);
	void CalcPrimaryRetro(VESSEL *vessel);
	void CalcLandingRetro(VESSEL *vessel);
	bool switch_autopilot;
	bool switch_jettisonabort;
	bool switch_capsulesep;

	bool switch_photo_lights;
	int  switch_lights;
	bool switch_tlm_freq;
	int  switch_light_test;
	bool switch_maneuver;	

	int  switch_automaticmode;
	int  pull_manualmode;
	int  pull_autorollmode;
	int  pull_autoyawmode;
	int  pull_autopitchmode;
	int  pull_decomp;
	int  pull_repress;
	int  push_retrosequence;
	int  switch_retrodelay;
	int  switch_retroattitude;
	int  push_retrofire;
	int  push_retrojett;
	bool switch_squib;
	bool switch_retroautojett;
	int  push_05G;
	int  push_drogue;
	int  push_timezero;
	bool  switch_snorkel; 
	bool  switch_main;
	bool  switch_reserve;
	int   switch_landingbag;
	int   switch_rscs;
	int   switch_rescue;
	bool  bDoThrusterChange;
	double descent_rate;
	double long_accel;
	double x_pitch_heading;
	double y_yaw_heading;
	double z_roll_heading;
	double clock_simt;
	double retro_simt;
	double startTime;
	int switch_gyro;
	int switch_filter;
	int CapsuleNumber;
	UINT FilterNumber;

	int SuitFanSwitch;
	int CabinFanSwitch;

	int DCVoltsKnob;
	int ACVoltsKnob;
	int InletValveSwitch;
	int AudioBusSwitch;
	int ACBusSwitch;
	int AmmeterSwitch;
	int StbyBtrySwitch;
	int IsolBtrySwitch;
	int FansACBusSwitch;

	int PushCommKey;
	int CommSelectSwitch;
	int UHFSelectSwitch;
	int TransmitSwitch;
	int CommBeaconSwitch;
	int VOXSwitch;

	int WarnLightSwitch;
	int CabinPressWarnSwitch;
	int O2EmerWarnSwitch;
	int SuitH2OWarnSwitch;
	int CabinH2OWarnSwitch;
	int FuelQuanWarnSwitch;
	int RetroWarnSwitch;
	int RetroResetWarnSwitch;
	int BloodPressStartPush;
	int BloodPressStopPush;
	int SuitFanFuse;
	int InvrControlFuse;
	int RetroJettFuse;
	int RetroManFuse;
	int ProgrammerFuse;
	int BloodPressFuse;

	int PhaseShifterFuse;
	int EmerCapSepFuse;
	int EscapeRcktFuse;
	int TowerSepContrlFuse;
	int EmerTowerSepFuse;
	int EmerTowerJettFuse;
	int EmerPosgrdFuse;
	int AuxBcnFuse;
	int RetroOneFuse;
	int RetroTwoFuse;
	int RetroThreeFuse;
	int EmerRetroSeqFuse;
	int EmerRetroJettFuse;
	int ASCS05GFuse;
	int Emer05GFuse;
	int EmerDrougeDeployFuse;
	int EmerMainDeployFuse;
	int ReserveDeployFuse;
	int EmerReserveDeployFuse;
	int EmerLandBagFuse;
	int EmerRescueAidsFuse;
	int PeriscopeFuse;
	int AntSwitchFuse;
	int ComVRcvrAFuse;
	int TrimHiFreqFuse;

	bool PeriscopePanel;
	bool CameraPanel;

	int Failure;

	double CountDownTime;
	bool bDoCountDown;

	mShipSystems *Systems;


private:
	void DrawGlobeMap(VESSEL *vessel,  SURFHANDLE surf);
	void DrawGlobe(VESSEL *vessel,  SURFHANDLE surf);
	void RedrawPanel_Roll(VESSEL *vessel, SURFHANDLE surf);
	void RedrawPanel_Pitch(VESSEL *vessel, SURFHANDLE surf);
	void RedrawPanel_Yaw(VESSEL *vessel, SURFHANDLE surf);
	void RedrawPanel_Rate(VESSEL *vessel, SURFHANDLE surf);
	void RedrawPanel_Fuel(VESSEL *vessel, SURFHANDLE surf);
	void RedrawPanel_Accel(VESSEL *vessel, SURFHANDLE surf);
	void RedrawPanel_Descent(VESSEL *vessel, SURFHANDLE surf);
	void RedrawPanel_FCRoll(VESSEL *vessel, SURFHANDLE surf);
	void RedrawPanel_FCPitch(VESSEL *vessel, SURFHANDLE surf);
	void RedrawPanel_FCYaw(VESSEL *vessel, SURFHANDLE surf);
	void RedrawPanel_FCRate(VESSEL *vessel, SURFHANDLE surf);
	void RedrawPanel_FCFuel(VESSEL *vessel, SURFHANDLE surf);
	bool RedrawPanel_Alt(VESSEL *vessel, SURFHANDLE surf);
	void RedrawPanel_RetrogradeTimer(VESSEL *vessel, SURFHANDLE surf);
	void RedrawPanel_PeriscopeAltitude(VESSEL *vessel, SURFHANDLE surf);
	void RedrawPanel_FCTimer(VESSEL *vessel, SURFHANDLE surf);
	void RedrawPanel_RoundGauge(VESSEL *vessel, SURFHANDLE surf, double position);
	void RedrawPanel_DualGauge(VESSEL *vessel, SURFHANDLE surf, double position1, double position2);
	void RedrawPanel_BottomGauge(VESSEL *vessel, SURFHANDLE surf, double position);
	void RedrawPanel_DrawFuse(SURFHANDLE surf, int position);
	void RedrawPanel_DrawStripedFuse(SURFHANDLE surf, int position);
	void Redraw_SequenceLight(int value, char *caption, SURFHANDLE surf);
	void Redraw_WarningLight(int value, char *caption1, char *caption2, SURFHANDLE surf);
	void Redraw_WarningLight(int value, char *caption, SURFHANDLE surf);
	void Redraw_RingSwitch(bool value, SURFHANDLE surf);
	void Redraw_FlightSwitch(int value, SURFHANDLE surf);
	void Redraw_SeqSwitch(int value, SURFHANDLE surf);
	void Redraw_SeqPush(int value, SURFHANDLE surf);
	void Redraw_FlightPush(int value, SURFHANDLE surf);	
	void Redraw_GaugeKnob(int value, SURFHANDLE knob, SURFHANDLE surf);
	void Systems_Init();
	void TimeStepSystem(VESSEL *vessel, double simt);
	void FuseMouseEvent(int &position, int event);
	bool ind_aborted;
/*	int  IND_ABORTJETTISONED;
	int  IND_CAPSULESEP;
	int  IND_RETROSEQUENCE;
	int  IND_RETROATTITUDE;
	int  IND_RETROFIRE;
	int  IND_RETROJETT;
	int  IND_05G;
	int  IND_MAIN;
	int  IND_LANDINGBAG;
	int  IND_RESCUE;
*/	
	int  ind_status[10];
	int  warn_status[8];
	int  lever_retro;
	double primaryzone[nprimary];
	double landingzone[3][6];
	VECTOR3 old_vel;
	double old_alt;
	double old_speed;
	double last_simt;
	double culm_simt;
	bool bClockStarted;
	double retro_set_simt;
	double retro_step_simt;
	int alt_knob;
	int view_switch;
	int alt_indicator;
	ADI* adi;
	UINT AbortMesh;
	double oldAlt;

};

Mercury_ControlPanel::Mercury_ControlPanel()
{

	hPanelMesh = NULL;
	srand ( (unsigned int)(time(NULL)) );

	
	int i = 0;
	for (i = 0; i < nsurf; i++) srf[i] = 0;
	
	Systems = new mShipSystems();

	primaryzone[0] = -114;
	primaryzone[1] = -119.8;
	primaryzone[2] = -127.5;

	landingzone[0][0] = -78;
	landingzone[0][1] = -24.6;
	landingzone[0][2] = 52;
	landingzone[0][3] = 123.5;
	landingzone[0][4] = -174;
	landingzone[0][5] = -114;

	landingzone[1][0] = -78;
	landingzone[1][1] = -24;
	landingzone[1][2] = 51;
	landingzone[1][3] = 146;
	landingzone[1][4] = -179;
	landingzone[1][5] = -119.8;

	landingzone[2][0] = -73;
	landingzone[2][1] = -23;
	landingzone[2][2] = 51;
	landingzone[2][3] = 140;
	landingzone[2][4] = -180;
	landingzone[2][5] = -127.5;

	retro_set_simt  = 0.0;
	retro_step_simt = 0.0;

	startTime=0.0;

	ind_aborted          = false;

	for (i = 0; i < 10; i++) 
		ind_status[i] = SEQ_CLEAR;

	for (i = 0; i < 10; i++) 
		warn_status[i] = WARN_OFF;

	switch_autopilot     = false;
	switch_jettisonabort = false;
	switch_capsulesep    = false;
	switch_automaticmode = AUTO_ASCS;
	pull_manualmode      = MANUAL_RATECMD;
	pull_autorollmode    = AUTO_ON; 
	pull_autoyawmode     = AUTO_ON;
	pull_autopitchmode   = AUTO_ON;
	pull_decomp          = AUTO_OFF;
	pull_repress         = AUTO_OFF;

	push_retrosequence   = PUSH_COVERED;
	push_retrofire       = PUSH_COVERED;
	push_retrojett       = PUSH_COVERED;

	switch_squib         = true;	
	switch_retroautojett = true;	
	switch_retrodelay	 = false;
	switch_retroattitude = RETROATT_AUTO;
	switch_photo_lights = false;
	switch_lights = LIGHTS_BOTH;
	switch_tlm_freq = false;
	switch_light_test = SEQ_CLEAR;
	switch_maneuver = true;


	push_05G             = PUSH_COVERED;
	push_drogue          = PUSH_COVERED;
	push_timezero        = PUSH_COVERED;
	switch_snorkel       = false; 
	switch_main          = false;
	switch_reserve       = false;
	switch_landingbag    = LB_AUTO;

	lever_retro          = RETRO_OFF;
	
	switch_rscs          = RSCS_AUTO;
	bDoThrusterChange    = true;

	switch_rescue        = RESCUE_AUTO;

	switch_gyro          = GYRO_NORM;
	oapiTriggerPanelRedrawArea (0, AID_GAUGE_FUEL);
	oapiTriggerPanelRedrawArea (1, FC_GAUGE_FUEL);

	descent_rate = 0;
	long_accel = 0;

	old_vel = _V(0,0,0);
	old_alt = 0.0;
	old_speed = 0.0;
	culm_simt = 0.0;
	last_simt = 0.0;

	clock_simt = 0.0;
	retro_simt = 16510.0;
	bClockStarted = false;

	x_pitch_heading = 90*RAD;
	y_yaw_heading = 180*RAD;
	z_roll_heading = 0.0;

	alt_knob = 0;
	view_switch = 0;
	switch_filter = SWITCH_LEFT;
	alt_indicator = 362;
	
	adi = new ADI(820, 540);

	SuitFanSwitch  = SWITCH_RIGHT;
	CabinFanSwitch = SWITCH_RIGHT;
	
	DCVoltsKnob      = 0;
	ACVoltsKnob      = 0;
	InletValveSwitch = SWITCH_RIGHT;
	AudioBusSwitch   = SWITCH_RIGHT;
	ACBusSwitch      = SWITCH_RIGHT;
	AmmeterSwitch    = SWITCH_RIGHT;
	StbyBtrySwitch   = SWITCH_RIGHT;
	IsolBtrySwitch   = SWITCH_RIGHT;
	FansACBusSwitch  = SWITCH_RIGHT;


	PushCommKey      = PUSH_UP;
	CommSelectSwitch = SWITCH_RIGHT;
	UHFSelectSwitch  = SWITCH_RIGHT;
	TransmitSwitch   = SWITCH_RIGHT;
	CommBeaconSwitch = SWITCH_RIGHT;
	VOXSwitch        = SWITCH_RIGHT;

	WarnLightSwitch      = SWITCH_RIGHT;
	CabinPressWarnSwitch = SWITCH_RIGHT;
	O2EmerWarnSwitch     = SWITCH_RIGHT;
	SuitH2OWarnSwitch    = SWITCH_RIGHT;
	CabinH2OWarnSwitch   = SWITCH_RIGHT;
	FuelQuanWarnSwitch   = SWITCH_RIGHT;
	RetroWarnSwitch      = SWITCH_RIGHT;
	RetroResetWarnSwitch = SWITCH_RIGHT;
	BloodPressStartPush  = PUSH_UP;
	BloodPressStopPush   = PUSH_UP;
	SuitFanFuse          = FUSE_ONE;
	InvrControlFuse      = FUSE_ONE;
	RetroJettFuse        = FUSE_ONE;
	RetroManFuse         = FUSE_ONE;
	ProgrammerFuse       = FUSE_ONE;
	BloodPressFuse       = FUSE_ONE;
	PhaseShifterFuse     = FUSE_ONE;
	EmerCapSepFuse       = FUSE_ONE;
	EscapeRcktFuse       = FUSE_ONE;
	TowerSepContrlFuse   = FUSE_ONE;
	EmerTowerSepFuse     = FUSE_ONE;
	EmerTowerJettFuse    = FUSE_ONE;
	EmerPosgrdFuse       = FUSE_ONE;
	AuxBcnFuse           = FUSE_ONE;
	RetroOneFuse         = FUSE_ONE;
	RetroTwoFuse         = FUSE_ONE;
	RetroThreeFuse       = FUSE_ONE;
	EmerRetroSeqFuse     = FUSE_ONE;
	EmerRetroJettFuse    = FUSE_ONE;
	ASCS05GFuse          = FUSE_ONE;
	Emer05GFuse          = FUSE_ONE;
	EmerDrougeDeployFuse = FUSE_ONE;
	EmerMainDeployFuse   = FUSE_ONE;
	ReserveDeployFuse    = FUSE_ONE;
	EmerReserveDeployFuse = FUSE_ONE;
	EmerLandBagFuse       = FUSE_ONE;
	EmerRescueAidsFuse    = FUSE_ONE;
	PeriscopeFuse         = FUSE_ONE;
	AntSwitchFuse         = FUSE_ONE;
	ComVRcvrAFuse         = FUSE_ONE;
	TrimHiFreqFuse        = FUSE_ONE;

	PeriscopePanel        = false;
	CameraPanel           = false;
	Failure               = 0;//rand() % 12 + 1;

	AbortMesh = -1;
	Systems_Init();
	CountDownTime = 0.0;
	bDoCountDown = true;

}

Mercury_ControlPanel::~Mercury_ControlPanel()
{
	if (hPanelMesh) oapiDeleteMesh (hPanelMesh);
	ReleaseSurfaces();
	delete adi;
	delete Systems;
}

void Mercury_ControlPanel::ParseSystem(VESSEL *vessel, FILEHANDLE scn){
	Systems->Load(scn);
}

void Mercury_ControlPanel::ParseLine (VESSEL *vessel, char *line, void *vs)
{
	double tempD=0.0;
    if (!_strnicmp (line, "SWITCH_AUTOPILOT", 16)) {
//	oapiWriteScenario_float (scn, "SWITCH_AUTOPILOT", switch_autopilot);
        sscanf (line+16, "%lf", &tempD);
		if (tempD == 1)
			switch_autopilot = true;
		else
			switch_autopilot = false;
    } else if (!_strnicmp (line, "SWITCH_ABORT_JETT", 17)) {
//	oapiWriteScenario_float (scn, "SWITCH_ABORT_JETT", switch_jettisonabort);
        sscanf (line+17, "%lf", &tempD);
		if (tempD == 1)
			switch_jettisonabort = true;
		else
			switch_jettisonabort = false;
    } else if (!_strnicmp (line, "SWITCH_CAPSULE_SEP", 18)) {
//	oapiWriteScenario_float (scn, "SWITCH_CAPSULE_SEP", switch_capsulesep);
        sscanf (line+18, "%lf", &tempD);
		if (tempD == 1)
			switch_capsulesep = true;
		else
			switch_capsulesep = false;
    } else if (!_strnicmp (line, "SWITCH_AUTOMODE", 15)) {
//	oapiWriteScenario_int   (scn, "SWITCH_AUTOMODE", switch_automaticmode);
        sscanf (line+15, "%d", &switch_automaticmode);
    } else if (!_strnicmp (line, "PULL_MANUAL", 11)) {
//	oapiWriteScenario_int   (scn, "PULL_MANUAL", pull_manualmode);
        sscanf (line+11, "%d", &pull_manualmode);
    } else if (!_strnicmp (line, "PULL_AUTO_ROLL", 14)) {
//	oapiWriteScenario_int   (scn, "PULL_AUTO_ROLL", pull_autorollmode);
        sscanf (line+14, "%d", &pull_autorollmode);
    } else if (!_strnicmp (line, "PULL_AUTO_YAW", 13)) {
//	oapiWriteScenario_int   (scn, "PULL_AUTO_YAW", pull_autoyawmode);
        sscanf (line+13, "%d", &pull_autoyawmode);
    } else if (!_strnicmp (line, "PULL_AUTO_PITCH", 15)) {
//	oapiWriteScenario_int   (scn, "PULL_AUTO_PITCH", pull_autopitchmode);
        sscanf (line+15, "%d", &pull_autopitchmode);
    } else if (!_strnicmp (line, "PULL_DECOMP", 11)) {
//	oapiWriteScenario_int   (scn, "PULL_AUTO_YAW", pull_autoyawmode);
        sscanf (line+11, "%d", &pull_decomp);
    } else if (!_strnicmp (line, "PULL_REPRESS", 12)) {
//	oapiWriteScenario_int   (scn, "PULL_AUTO_PITCH", pull_autopitchmode);
        sscanf (line+12, "%d", &pull_repress);
    } else if (!_strnicmp (line, "PUSH_RETRO_SEQ", 14)) {
//	oapiWriteScenario_int   (scn, "PUSH_RETRO_SEQ", push_retrosequence);
        sscanf (line+14, "%d", &push_retrosequence);
    } else if (!_strnicmp (line, "SWITCH_RETRO_DELAY", 18)) {
//	oapiWriteScenario_int   (scn, "SWITCH_RETRO_DELAY", switch_retrodelay);
        sscanf (line+18, "%d", &switch_retrodelay);
    } else if (!_strnicmp (line, "SWITCH_PHOTO_LIGHTS", 19)) {
//	oapiWriteScenario_float (scn, "SWITCH_SQUIB", switch_squib);
        sscanf (line+19, "%lf", &tempD);
		if (tempD == 1)
			switch_photo_lights = true;
		else
			switch_photo_lights = false;
    } else if (!_strnicmp (line, "SWITCH_LIGHTS", 13)) {
//	oapiWriteScenario_int   (scn, "SWITCH_RETRO_DELAY", switch_retrodelay);
        sscanf (line+13, "%d", &switch_lights);
    } else if (!_strnicmp (line, "SWITCH_TLM_FREQ", 15)) {
//	oapiWriteScenario_float (scn, "SWITCH_SQUIB", switch_squib);
        sscanf (line+15, "%lf", &tempD);
		if (tempD == 1)
			switch_tlm_freq = true;
		else
			switch_tlm_freq = false;
    } else if (!_strnicmp (line, "SWITCH_LIGHT_TEST", 17)) {
//	oapiWriteScenario_int   (scn, "SWITCH_RETRO_DELAY", switch_retrodelay);
        sscanf (line+17, "%d", &switch_light_test);
    } else if (!_strnicmp (line, "SWITCH_MANEUVER", 15)) {
//	oapiWriteScenario_float (scn, "SWITCH_SQUIB", switch_squib);
        sscanf (line+15, "%lf", &tempD);
		if (tempD == 1)
			switch_maneuver = true;
		else
			switch_maneuver = false;
    } else if (!_strnicmp (line, "SWITCH_RETRO_ATT", 16)) {
//	oapiWriteScenario_int   (scn, "SWITCH_RETRO_ATT", switch_retroattitude);
        sscanf (line+16, "%d", &switch_retroattitude);
    } else if (!_strnicmp (line, "PUSH_RETRO_FIRE", 15)) {
//	oapiWriteScenario_int   (scn, "PUSH_RETRO_FIRE", push_retrofire);
        sscanf (line+15, "%d", &push_retrofire);
    } else if (!_strnicmp (line, "PUSH_RETRO_JETT", 15)) {
//	oapiWriteScenario_int   (scn, "PUSH_RETRO_JETT", push_retrojett);
        sscanf (line+15, "%d", &push_retrojett);
    } else if (!_strnicmp (line, "SWITCH_SQUIB", 12)) {
//	oapiWriteScenario_float (scn, "SWITCH_SQUIB", switch_squib);
        sscanf (line+12, "%lf", &tempD);
		if (tempD == 1)
			switch_squib = true;
		else
			switch_squib = false;
    } else if (!_strnicmp (line, "SWITCH_RETRO_AUTOJETT", 21)) {
//	oapiWriteScenario_float (scn, "SWITCH_RETRO_AUTOJETT", switch_retroautojett);
        sscanf (line+21, "%lf", &tempD);
		if (tempD == 1)
			switch_retroautojett = true;
		else
			switch_retroautojett = false;
    } else if (!_strnicmp (line, "PUSH_05G", 8)) {
//	oapiWriteScenario_int   (scn, "PUSH_05G", push_05G);
        sscanf (line+8, "%d", &push_05G);
    } else if (!_strnicmp (line, "PUSH_DROGUE", 11)) {
//	oapiWriteScenario_int   (scn, "PUSH_DROGUE", push_drogue);
        sscanf (line+11, "%d", &push_drogue);
    } else if (!_strnicmp (line, "PUSH_TIMEZERO", 13)) {
//	oapiWriteScenario_int   (scn, "PUSH_TIMEZERO", push_timezero);
        sscanf (line+13, "%d", &push_timezero);
    } else if (!_strnicmp (line, "SWITCH_SNORKEL", 14)) {
//	oapiWriteScenario_float (scn, "SWITCH_SNORKEL", switch_snorkel); 
        sscanf (line+14, "%lf", &tempD);
		if (tempD == 1)
			switch_snorkel = true;
		else
			switch_snorkel = false;
    } else if (!_strnicmp (line, "SWITCH_MAIN", 11)) {
//	oapiWriteScenario_float (scn, "SWITCH_MAIN", switch_main);
        sscanf (line+11, "%lf", &tempD);
		if (tempD == 1)
			switch_main = true;
		else
			switch_main = false;
    } else if (!_strnicmp (line, "SWITCH_RESERVE", 14)) {
//	oapiWriteScenario_float (scn, "SWITCH_RESERVE", switch_reserve);
        sscanf (line+14, "%lf", &tempD);
		if (tempD == 1)
			switch_reserve = true;
		else
			switch_reserve = false;
    } else if (!_strnicmp (line, "SWITCH_LB", 9)) {
//	oapiWriteScenario_int   (scn, "SWITCH_LB", switch_landingbag);
        sscanf (line+9, "%d", &switch_landingbag);
    } else if (!_strnicmp (line, "SWITCH_RSCS", 11)) {
//	oapiWriteScenario_int   (scn, "SWITCH_RSCS", switch_rscs);
        sscanf (line+11, "%d", &switch_rscs);
    } else if (!_strnicmp (line, "SWITCH_RESCUE", 13)) {
//	oapiWriteScenario_int   (scn, "SWITCH_RSCS", switch_rscs);
        sscanf (line+13, "%d", &switch_rescue);
//	//double
    } else if (!_strnicmp (line, "HEADING_PITCH", 13)) {
//	oapiWriteScenario_float (scn, "HEADING_PITCH", x_pitch_heading);
        sscanf (line+13, "%lf", &x_pitch_heading);
    } else if (!_strnicmp (line, "HEADING_YAW", 11)) {
//	oapiWriteScenario_float (scn, "HEADING_YAW", y_yaw_heading);
        sscanf (line+11, "%lf", &y_yaw_heading);
    } else if (!_strnicmp (line, "HEADING_ROLL", 12)) {
//	oapiWriteScenario_float (scn, "HEADING_ROLL", z_roll_heading);
        sscanf (line+12, "%lf", &z_roll_heading);
//	//end double
    } else if (!_strnicmp (line, "SWITCH_GYRO", 11)) {
//	oapiWriteScenario_int   (scn, "SWITCH_GYRO", switch_gyro);
        sscanf (line+11, "%d", &switch_gyro);
    } else if (!_strnicmp (line, "IND_ABORTED", 11)) {
//	oapiWriteScenario_float (scn, "IND_ABORTED", ind_aborted);
        sscanf (line+11, "%lf", &tempD);
		if (tempD == 1)
			ind_aborted = true;
		else
			ind_aborted = false;
    } else if (!_strnicmp (line, "IND_ABORT_JETT", 14)) {
//	oapiWriteScenario_int   (scn, "IND_ABORT_JETT", IND_ABORTJETTISONED);
        sscanf (line+14, "%d", &ind_status[IND_ABORTJETTISONED]);
    } else if (!_strnicmp (line, "IND_CAPSULE_SEP", 15)) {
//	oapiWriteScenario_int   (scn, "IND_CAPSULE_SEP", IND_CAPSULESEP);
        sscanf (line+15, "%d", &ind_status[IND_CAPSULESEP]);
    } else if (!_strnicmp (line, "IND_RETRO_SEQ", 13)) {
//	oapiWriteScenario_int   (scn, "IND_RETRO_SEQ", IND_RETROSEQUENCE);
        sscanf (line+13, "%d", &ind_status[IND_RETROSEQUENCE]);
    } else if (!_strnicmp (line, "IND_RETRO_ATT", 13)) {
//	oapiWriteScenario_int   (scn, "IND_RETRO_ATT", IND_RETROATTITUDE);
        sscanf (line+13, "%d", &ind_status[IND_RETROATTITUDE]);
    } else if (!_strnicmp (line, "IND_RETRO_FIRE", 14)) {
//	oapiWriteScenario_int   (scn, "IND_RETRO_FIRE", IND_RETROFIRE);
        sscanf (line+14, "%d", &ind_status[IND_RETROFIRE]);
    } else if (!_strnicmp (line, "IND_RETRO_JETT", 14)) {
//	oapiWriteScenario_int   (scn, "IND_RETRO_JETT", IND_RETROJETT);
        sscanf (line+14, "%d", &ind_status[IND_RETROJETT]);
    } else if (!_strnicmp (line, "IND_05G", 7)) {
//	oapiWriteScenario_int   (scn, "IND_05G", IND_05G);
        sscanf (line+7, "%d", &ind_status[IND_05G]);
    } else if (!_strnicmp (line, "IND_MAIN", 8)) {
//	oapiWriteScenario_int   (scn, "IND_MAIN", IND_MAIN);
        sscanf (line+8, "%d", &ind_status[IND_MAIN]);
    } else if (!_strnicmp (line, "IND_LB", 6)) {
//	oapiWriteScenario_int   (scn, "IND_LB", IND_LANDINGBAG);
        sscanf (line+6, "%d", &ind_status[IND_LANDINGBAG]);
    } else if (!_strnicmp (line, "IND_RESCUE", 6)) {
//	oapiWriteScenario_int   (scn, "IND_LB", IND_LANDINGBAG);
        sscanf (line+6, "%d", &ind_status[IND_RESCUE]);
    } else if (!_strnicmp (line, "TIME_CULM", 9)) {
//	oapiWriteScenario_float (scn, "TIME_CULM", clock_simt);
        sscanf (line+9, "%lf", &tempD);
		clock_simt = -tempD;
    } else if (!_strnicmp (line, "TIME_RETRO", 10)) {
//	oapiWriteScenario_float (scn, "TIME_RETRO", retro_simt);
        sscanf (line+10, "%lf", &tempD);
		retro_simt = tempD;
    } else if (!_strnicmp (line, "CLOCK_STARTED", 13)) {
//	oapiWriteScenario_float (scn, "CLOCK_STARTED", bClockStarted);
        sscanf (line+13, "%lf", &tempD);
		if (tempD == 1)
			bClockStarted = true;
		else
			bClockStarted = false;
    } else if (!_strnicmp (line, "START_TIME", 10)) {
//	oapiWriteScenario_float (scn, "START_THI", startTime);
        sscanf (line+10, "%lf", &startTime);
    } else if (!_strnicmp (line, "LEVER_RETRO", 11)) {
        sscanf (line+11, "%d", &lever_retro);
    } else if (!_strnicmp (line, "ALT_KNOB", 8)) {
        sscanf (line+8, "%d", &alt_knob);
    } else if (!_strnicmp (line, "VIEW_SWITCH", 11)) {
        sscanf (line+11, "%d", &view_switch);
//    } else if (!_strnicmp (line, "SWITCH_FILTER", 13)) {
//        sscanf (line+13, "%d", &switch_filter);
    } else if (!_strnicmp (line, "ALT_INDICATOR", 13)) {
        sscanf (line+13, "%d", &alt_indicator);
	} else if (!_strnicmp (line, "CAPSULE_NUMBER", 14)) {
		sscanf (line+14,  "%d", &CapsuleNumber);
	} else if (!_strnicmp (line, "DC_VOLTS_KNOB", 13)) {
		sscanf (line+13,  "%d", &DCVoltsKnob);
	} else if (!_strnicmp (line, "AC_VOLTS_KNOB", 13)) {
		sscanf (line+13,  "%d", &ACVoltsKnob);
	} else if (!_strnicmp (line, "INLET_VALVE_SWITCH", 18)) {
		sscanf (line+18,  "%d", &InletValveSwitch);
	} else if (!_strnicmp (line, "AUDIO_BUS_SWITCH", 16)) {
		sscanf (line+16,  "%d", &AudioBusSwitch);
	} else if (!_strnicmp (line, "AC_BUS_SWITCH", 13)) {
		sscanf (line+13,  "%d", &ACBusSwitch);
	} else if (!_strnicmp (line, "AMMETER_SWITCH", 14)) {
		sscanf (line+14,  "%d", &AmmeterSwitch);
	} else if (!_strnicmp (line, "STBY_BTRY_SWITCH", 16)) {
		sscanf (line+16,  "%d", &StbyBtrySwitch);
	} else if (!_strnicmp (line, "ISOL_BTRY_SWITCH", 16)) {
		sscanf (line+16,  "%d", &IsolBtrySwitch);
	} else if (!_strnicmp (line, "FANS_AC_BUS_SWITCH", 18)) {
		sscanf (line+18,  "%d", &FansACBusSwitch);
	} else if (!_strnicmp (line, "COMM_SELECT_SWITCH", 18)) {
		sscanf (line+18,  "%d", &CommSelectSwitch);
	} else if (!_strnicmp (line, "UHF_SELECT_SWITCH", 17)) {
		sscanf (line+17,  "%d", &UHFSelectSwitch);
	} else if (!_strnicmp (line, "TRANSMIT_SWITCH", 15)) {
		sscanf (line+15,  "%d", &TransmitSwitch);
	} else if (!_strnicmp (line, "COMM_BEACON_SWITCH", 18)) {
		sscanf (line+18,  "%d", &CommBeaconSwitch);
	} else if (!_strnicmp (line, "VOX_SWITCH", 10)) {
		sscanf (line+10,  "%d", &VOXSwitch);
	} else if (!_strnicmp (line, "WARN_LIGHT_SWITCH", 17)) {
		sscanf (line+17,  "%d", &WarnLightSwitch);      
	} else if (!_strnicmp (line, "CABIN_PRESS_WARN_SWITCH", 23)) {
		sscanf (line+23,  "%d", &CabinPressWarnSwitch);
	} else if (!_strnicmp (line, "O2_EMER_WARN_SWITCH", 19)) {
		sscanf (line+19,  "%d", &O2EmerWarnSwitch);
	} else if (!_strnicmp (line, "SUIT_H2O_WARN_SWITCH", 20)) {
		sscanf (line+20,  "%d", &SuitH2OWarnSwitch);   
	} else if (!_strnicmp (line, "CABIN_H2O_WARN_SWITCH", 21)) {
		sscanf (line+21,  "%d", &CabinH2OWarnSwitch);  
	} else if (!_strnicmp (line, "FUEL_QUAN_WARN_SWITCH", 21)) {
		sscanf (line+21,  "%d", &FuelQuanWarnSwitch); 
	} else if (!_strnicmp (line, "RETRO_WARN_SWITCH", 17)) {
		sscanf (line+17,  "%d", &RetroWarnSwitch);      
	} else if (!_strnicmp (line, "RETRO_RESET_WARN_SWITCH", 23)) {
		sscanf (line+23,  "%d", &RetroResetWarnSwitch);
	} else if (!_strnicmp (line, "SUIT_FAN_FUSE", 13)) {
		sscanf (line+13,  "%d", &SuitFanFuse);
	} else if (!_strnicmp (line, "INVR_CONTROL_FUSE", 17)) {
		sscanf (line+17,  "%d", &InvrControlFuse);
	} else if (!_strnicmp (line, "RETRO_JETT_FUSE", 15)) {
		sscanf (line+15,  "%d", &RetroJettFuse);    
	} else if (!_strnicmp (line, "RETRO_MAN_FUSE", 14)) {
		sscanf (line+14,  "%d", &RetroManFuse);      
	} else if (!_strnicmp (line, "PROGRAMMER_FUSE", 15)) {
		sscanf (line+15,  "%d", &ProgrammerFuse);       
	} else if (!_strnicmp (line, "BLOOD_PRESS_FUSE", 16)) {
		sscanf (line+16,  "%d", &BloodPressFuse);     
	} else if (!_strnicmp (line, "PHASE_SHIFTER_FUSE", 18)) {
		sscanf (line+18,  "%d", &PhaseShifterFuse);
	} else if (!_strnicmp (line, "EMER_CAP_SEP_FUSE", 17)) {
		sscanf (line+17,  "%d", &EmerCapSepFuse);
	} else if (!_strnicmp (line, "ESCAPE_RCKT_FUSE", 16)) {
		sscanf (line+16,  "%d", &EscapeRcktFuse);
	} else if (!_strnicmp (line, "TOWER_SEP_CONTRL_FUSE", 21)) {
		sscanf (line+21,  "%d", &TowerSepContrlFuse);
	} else if (!_strnicmp (line, "EMER_TOWER_SEP_FUSE", 19)) {
		sscanf (line+19,  "%d", &EmerTowerSepFuse);
	} else if (!_strnicmp (line, "EMER_TOWER_JETT_FUSE", 20)) {
		sscanf (line+20,  "%d", &EmerTowerJettFuse);
	} else if (!_strnicmp (line, "EMER_POSGRD_FUSE", 16)) {
		sscanf (line+16,  "%d", &EmerPosgrdFuse);
	} else if (!_strnicmp (line, "AUX_BCN_FUSE", 12)) {
		sscanf (line+12,  "%d", &AuxBcnFuse);
	} else if (!_strnicmp (line, "RETRO_ONE_FUSE", 14)) {
		sscanf (line+14,  "%d", &RetroOneFuse);
	} else if (!_strnicmp (line, "RETRO_TWO_FUSE", 14)) {
		sscanf (line+14,  "%d", &RetroTwoFuse);
	} else if (!_strnicmp (line, "RETRO_THREE_FUSE", 16)) {
		sscanf (line+16,  "%d", &RetroThreeFuse);
	} else if (!_strnicmp (line, "EMER_RETRO_SEQ_FUSE", 19)) {
		sscanf (line+19,  "%d", &EmerRetroSeqFuse);
	} else if (!_strnicmp (line, "EMER_RETRO_JETT_FUSE", 20)) {
		sscanf (line+20,  "%d", &EmerRetroJettFuse);
	} else if (!_strnicmp (line, "ASCS_05G_FUSE", 13)) {
		sscanf (line+13,  "%d", &ASCS05GFuse);
	} else if (!_strnicmp (line, "EMER_05G_FUSE", 13)) {
		sscanf (line+13,  "%d", &Emer05GFuse);
	} else if (!_strnicmp (line, "EMER_DROUGE_DEPLOY_FUSE", 23)) {
		sscanf (line+23,  "%d", &EmerDrougeDeployFuse);
	} else if (!_strnicmp (line, "EMER_MAIN_DEPLOY_FUSE", 21)) {
		sscanf (line+21,  "%d", &EmerMainDeployFuse);
	} else if (!_strnicmp (line, "RESERVE_DEPLOY_FUSE", 19)) {
		sscanf (line+19,  "%d", &ReserveDeployFuse);
	} else if (!_strnicmp (line, "EMER_RESERVE_DEPLOY_FUSE", 24)) {
		sscanf (line+24,  "%d", &EmerReserveDeployFuse);
	} else if (!_strnicmp (line, "EMER_LAND_BAG_FUSE", 18)) {
		sscanf (line+18,  "%d", &EmerLandBagFuse);
	} else if (!_strnicmp (line, "EMER_RESCUE_AIDS_FUSE", 21)) {
		sscanf (line+21,  "%d", &EmerRescueAidsFuse);
	} else if (!_strnicmp (line, "PERISCOPE_FUSE", 14)) {
		sscanf (line+14,  "%d", &PeriscopeFuse);
	} else if (!_strnicmp (line, "ANT_SWITCH_FUSE", 15)) {
		sscanf (line+15,  "%d", &AntSwitchFuse);
	} else if (!_strnicmp (line, "COMV_RCVRA_FUSE", 15)) {
		sscanf (line+15,  "%d", &ComVRcvrAFuse);
	} else if (!_strnicmp (line, "TRIM_HI_FREQ_FUSE", 17)) {
		sscanf (line+17,  "%d", &TrimHiFreqFuse);
	} else if (!_strnicmp (line, "FAILURE_MODE", 12)) {
		sscanf (line+12,  "%d", &Failure);
		if (Failure == -1) {
			Failure = rand() % 12 + 1;
		}
	} else {
        vessel->ParseScenarioLineEx (line, vs);
    }
	int i;
	i = 0;
};
void Mercury_ControlPanel::SaveState (VESSEL *vessel, FILEHANDLE scn)
{
	oapiWriteScenario_float (scn, "SWITCH_AUTOPILOT",   switch_autopilot);
	oapiWriteScenario_float (scn, "SWITCH_ABORT_JETT",  switch_jettisonabort);
	oapiWriteScenario_float (scn, "SWITCH_CAPSULE_SEP", switch_capsulesep);
	oapiWriteScenario_int   (scn, "SWITCH_AUTOMODE",    switch_automaticmode);
	oapiWriteScenario_int   (scn, "PULL_MANUAL",        pull_manualmode);
	oapiWriteScenario_int   (scn, "PULL_AUTO_ROLL",     pull_autorollmode);
	oapiWriteScenario_int   (scn, "PULL_AUTO_YAW",      pull_autoyawmode);
	oapiWriteScenario_int   (scn, "PULL_AUTO_PITCH",    pull_autopitchmode);
	oapiWriteScenario_int   (scn, "PULL_DECOMP",        pull_decomp);
	oapiWriteScenario_int   (scn, "PULL_REPRESS",       pull_repress);
	oapiWriteScenario_int   (scn, "PUSH_RETRO_SEQ",     push_retrosequence);
	oapiWriteScenario_int   (scn, "SWITCH_RETRO_DELAY", switch_retrodelay);
	oapiWriteScenario_int   (scn, "SWITCH_RETRO_ATT",   switch_retroattitude);
	
	oapiWriteScenario_float (scn, "SWITCH_PHOTO_LIGHTS", switch_photo_lights);
	oapiWriteScenario_int   (scn, "SWITCH_LIGHTS",       switch_lights);
	oapiWriteScenario_float (scn, "SWITCH_TLM_FREQ",     switch_tlm_freq);
	oapiWriteScenario_int   (scn, "SWITCH_LIGHT_TEST",   switch_light_test);
	oapiWriteScenario_float (scn, "SWITCH_MANEUVER",     switch_maneuver);	

	
	oapiWriteScenario_int   (scn, "PUSH_RETRO_FIRE",       push_retrofire);
	oapiWriteScenario_int   (scn, "PUSH_RETRO_JETT",       push_retrojett);
	oapiWriteScenario_float (scn, "SWITCH_SQUIB",          switch_squib);
	oapiWriteScenario_float (scn, "SWITCH_RETRO_AUTOJETT", switch_retroautojett);
	oapiWriteScenario_int   (scn, "PUSH_05G",              push_05G);
	oapiWriteScenario_int   (scn, "PUSH_DROGUE",           push_drogue);
	oapiWriteScenario_int   (scn, "PUSH_TIMEZERO",         push_timezero);
	oapiWriteScenario_float (scn, "SWITCH_SNORKEL",        switch_snorkel); 
	oapiWriteScenario_float (scn, "SWITCH_MAIN",           switch_main);
	oapiWriteScenario_float (scn, "SWITCH_RESERVE",        switch_reserve);
	oapiWriteScenario_int   (scn, "SWITCH_LB",             switch_landingbag);
	oapiWriteScenario_int   (scn, "SWITCH_RSCS",           switch_rscs);
	oapiWriteScenario_int   (scn, "SWITCH_RESCUE",         switch_rescue);
	//double
	oapiWriteScenario_float (scn, "HEADING_PITCH", x_pitch_heading);
	oapiWriteScenario_float (scn, "HEADING_YAW",   y_yaw_heading);
	oapiWriteScenario_float (scn, "HEADING_ROLL",  z_roll_heading);
	//end double
	oapiWriteScenario_int   (scn, "SWITCH_GYRO",     switch_gyro);
	oapiWriteScenario_float (scn, "IND_ABORTED",     ind_aborted);
	oapiWriteScenario_int   (scn, "IND_ABORT_JETT",  ind_status[IND_ABORTJETTISONED]);
	oapiWriteScenario_int   (scn, "IND_CAPSULE_SEP", ind_status[IND_CAPSULESEP]);
	oapiWriteScenario_int   (scn, "IND_RETRO_SEQ",   ind_status[IND_RETROSEQUENCE]);
	oapiWriteScenario_int   (scn, "IND_RETRO_ATT",   ind_status[IND_RETROATTITUDE]);
	oapiWriteScenario_int   (scn, "IND_RETRO_FIRE",  ind_status[IND_RETROFIRE]);
	oapiWriteScenario_int   (scn, "IND_RETRO_JETT",  ind_status[IND_RETROJETT]);
	oapiWriteScenario_int   (scn, "IND_05G",         ind_status[IND_05G]);
	oapiWriteScenario_int   (scn, "IND_MAIN",        ind_status[IND_MAIN]);
	oapiWriteScenario_int   (scn, "IND_LB",          ind_status[IND_LANDINGBAG]);
	oapiWriteScenario_int   (scn, "IND_RESCUE",      ind_status[IND_RESCUE]);
	oapiWriteScenario_float (scn, "TIME_CULM",       oapiGetSimTime()  - clock_simt);
	oapiWriteScenario_float (scn, "TIME_RETRO",      retro_simt);
	oapiWriteScenario_float (scn, "CLOCK_STARTED",   bClockStarted);
	oapiWriteScenario_float (scn, "START_TIME",      startTime);
	oapiWriteScenario_int   (scn, "LEVER_RETRO",     lever_retro);
	oapiWriteScenario_int   (scn, "ALT_KNOB",        alt_knob);
	oapiWriteScenario_int   (scn, "VIEW_SWITCH",     view_switch);
	oapiWriteScenario_int   (scn, "SWITCH_FILTER",   switch_filter);
	oapiWriteScenario_int   (scn, "ALT_INDICATOR",   alt_indicator);
	oapiWriteScenario_int   (scn, "CAPSULE_NUMBER",  CapsuleNumber);

	oapiWriteScenario_int   (scn, "DC_VOLTS_KNOB",      DCVoltsKnob);
	oapiWriteScenario_int   (scn, "AC_VOLTS_KNOB",      ACVoltsKnob);
	oapiWriteScenario_int   (scn, "INLET_VALVE_SWITCH", InletValveSwitch);
	oapiWriteScenario_int   (scn, "AUDIO_BUS_SWITCH",   AudioBusSwitch);
	oapiWriteScenario_int   (scn, "AC_BUS_SWITCH",      ACBusSwitch);
	oapiWriteScenario_int   (scn, "AMMETER_SWITCH",     AmmeterSwitch);
	oapiWriteScenario_int   (scn, "STBY_BTRY_SWITCH",   StbyBtrySwitch);
	oapiWriteScenario_int   (scn, "ISOL_BTRY_SWITCH",   IsolBtrySwitch);
	oapiWriteScenario_int   (scn, "FANS_AC_BUS_SWITCH", FansACBusSwitch);
	oapiWriteScenario_int   (scn, "COMM_SELECT_SWITCH", CommSelectSwitch);
	oapiWriteScenario_int   (scn, "UHF_SELECT_SWITCH",  UHFSelectSwitch);
	oapiWriteScenario_int   (scn, "TRANSMIT_SWITCH",    TransmitSwitch);
	oapiWriteScenario_int   (scn, "COMM_BEACON_SWITCH", CommBeaconSwitch);
	oapiWriteScenario_int   (scn, "VOX_SWITCH",         VOXSwitch);

	oapiWriteScenario_int   (scn, "WARN_LIGHT_SWITCH",        WarnLightSwitch);      
	oapiWriteScenario_int   (scn, "CABIN_PRESS_WARN_SWITCH",  CabinPressWarnSwitch);
	oapiWriteScenario_int   (scn, "O2_EMER_WARN_SWITCH",      O2EmerWarnSwitch);
	oapiWriteScenario_int   (scn, "SUIT_H2O_WARN_SWITCH",     SuitH2OWarnSwitch);   
	oapiWriteScenario_int   (scn, "CABIN_H2O_WARN_SWITCH",    CabinH2OWarnSwitch);  
	oapiWriteScenario_int   (scn, "FUEL_QUAN_WARN_SWITCH",    FuelQuanWarnSwitch); 
	oapiWriteScenario_int   (scn, "RETRO_WARN_SWITCH",        RetroWarnSwitch);      
	oapiWriteScenario_int   (scn, "RETRO_RESET_WARN_SWITCH",  RetroResetWarnSwitch);
	oapiWriteScenario_int   (scn, "SUIT_FAN_FUSE",            SuitFanFuse);
	oapiWriteScenario_int   (scn, "INVR_CONTROL_FUSE",        InvrControlFuse);
	oapiWriteScenario_int   (scn, "RETRO_JETT_FUSE",          RetroJettFuse);    
	oapiWriteScenario_int   (scn, "RETRO_MAN_FUSE",           RetroManFuse);      
	oapiWriteScenario_int   (scn, "PROGRAMMER_FUSE",          ProgrammerFuse);       
	oapiWriteScenario_int   (scn, "BLOOD_PRESS_FUSE",         BloodPressFuse);     
	oapiWriteScenario_int   (scn, "PHASE_SHIFTER_FUSE",       PhaseShifterFuse);
	oapiWriteScenario_int   (scn, "EMER_CAP_SEP_FUSE",        EmerCapSepFuse);
	oapiWriteScenario_int   (scn, "ESCAPE_RCKT_FUSE",         EscapeRcktFuse);
	oapiWriteScenario_int   (scn, "TOWER_SEP_CONTRL_FUSE",    TowerSepContrlFuse);
	oapiWriteScenario_int   (scn, "EMER_TOWER_SEP_FUSE",      EmerTowerSepFuse);
	oapiWriteScenario_int   (scn, "EMER_TOWER_JETT_FUSE",     EmerTowerJettFuse);
	oapiWriteScenario_int   (scn, "EMER_POSGRD_FUSE",         EmerPosgrdFuse);
	oapiWriteScenario_int   (scn, "AUX_BCN_FUSE",             AuxBcnFuse);
	oapiWriteScenario_int   (scn, "RETRO_ONE_FUSE",           RetroOneFuse);
	oapiWriteScenario_int   (scn, "RETRO_TWO_FUSE",           RetroTwoFuse);
	oapiWriteScenario_int   (scn, "RETRO_THREE_FUSE",         RetroThreeFuse);
	oapiWriteScenario_int   (scn, "EMER_RETRO_SEQ_FUSE",      EmerRetroSeqFuse);
	oapiWriteScenario_int   (scn, "EMER_RETRO_JETT_FUSE",     EmerRetroJettFuse);
	oapiWriteScenario_int   (scn, "ASCS_05G_FUSE",            ASCS05GFuse);
	oapiWriteScenario_int   (scn, "EMER_05G_FUSE",            Emer05GFuse);
	oapiWriteScenario_int   (scn, "EMER_DROUGE_DEPLOY_FUSE",  EmerDrougeDeployFuse);
	oapiWriteScenario_int   (scn, "EMER_MAIN_DEPLOY_FUSE",    EmerMainDeployFuse);
	oapiWriteScenario_int   (scn, "RESERVE_DEPLOY_FUSE",      ReserveDeployFuse);
	oapiWriteScenario_int   (scn, "EMER_RESERVE_DEPLOY_FUSE", EmerReserveDeployFuse);
	oapiWriteScenario_int   (scn, "EMER_LAND_BAG_FUSE",       EmerLandBagFuse);
	oapiWriteScenario_int   (scn, "EMER_RESCUE_AIDS_FUSE",    EmerRescueAidsFuse);
	oapiWriteScenario_int   (scn, "PERISCOPE_FUSE",           PeriscopeFuse);
	oapiWriteScenario_int   (scn, "ANT_SWITCH_FUSE",          AntSwitchFuse);
	oapiWriteScenario_int   (scn, "COMV_RCVRA_FUSE",          ComVRcvrAFuse);
	oapiWriteScenario_int   (scn, "TRIM_HI_FREQ_FUSE",        TrimHiFreqFuse);
	
	oapiWriteScenario_int   (scn, "FAILURE_MODE",             Failure);
	Systems->Save(scn);
};

void Mercury_ControlPanel::CalcPrimaryRetro(VESSEL *vessel)
{
	orbitelements *Orbit;
	double OrbitTime =0.0;
	double longitude = 0.0;
	double latitude = 0.0;
	double radius = 0.0;
	double tempD = 0.0;
	int nOrbit = 0;
	double cur_time   = oapiGetSimTime() - clock_simt;
	int tempI;
	double Target = 0.0;
	double Thi = 0;
	double TimeToTarget = 0.0;
	const double DegPerSec = (15.0*RAD) / 3600.0; // 15 deg/hr divied by 3600 seconds in a hour.

	Orbit = new orbitelements;
	Orbit->init(vessel->GetGravityRef(), vessel->GetHandle());
	Orbit->gettimeorbit(&tempI,&OrbitTime,0);
	nOrbit = (int) floor((cur_time - startTime) / OrbitTime);
	Thi = acos(Orbit->getcurrcosthi());
	if (Orbit->getcurrsinthi() < 0) 
		Thi = -Thi;
	vessel->GetEquPos(longitude, latitude, radius);
	Target = primaryzone[nOrbit]*RAD;
	if (Target < 0)
		Target += 2*PI;

	tempD = Target - longitude ;
	if (tempD > 0) {
		if (tempD > 2*PI)
			tempD -= 2*PI;

		Thi += tempD + ((tempD / (2*PI)) * OrbitTime * DegPerSec);
		retro_simt=Orbit->GetTimeToThi(cos(Thi),sin(Thi)) + cur_time;
//		sprintf(oapiDebugString(), "Orbit %d %f %f %f %f", nOrbit, (tempD / (2*PI)), Orbit->GetTimeToThi(cos(Thi),sin(Thi)), primaryzone[nOrbit], tempD*DEG);
	}
}

void Mercury_ControlPanel::CalcLandingRetro(VESSEL *vessel)
{
	orbitelements *Orbit;
	double OrbitTime =0.0;
	double nOrbit = 0.0;
	int tempI;

	Orbit = new orbitelements;
	Orbit->init(vessel->GetGravityRef(), vessel->GetHandle());
	Orbit->gettimeorbit(&tempI,&OrbitTime,0);
	nOrbit = floor((clock_simt - startTime) / OrbitTime);
	//sprintf(oapiDebugString(), "Orbit %f", nOrbit);
}

void Mercury_ControlPanel::Systems_Init(){
	mSubstance aSub;

	mTank *PrimaryOxygenTank;
	mTank *SecondaryOxygenTank;
	mTank *MercurySuit;
	mTank *Capsule;
	mPipe *PrimarySuitFeed;
	mPipe *SecondarySuitFeed;
	mPipe *PrimaryCapsuleFeed;
	mPipe *SecondaryCapsuleFeed;
	mVent *CapsuleVent;
	mCrew *Astronaut;
	mBattery *Main1;
	mBattery *Main2;
	mBattery *Main3;
	mBattery *Stby1;
	mBattery *Stby2;
	mBattery *Iso1;
	mBus     *MainBty;
	mBus     *StbyBty;
	mBus     *IsoBty;
	mBus     *DCMain;
	mBus     *IsoStbyBus;
	mBus     *StbyBus;
	//mBus     *CommBus;

	//mElectricObject *Test;
	//mElectricObject *Test2;
	mElectricObject *SysObj;

	aSub.SubstType = SUBSTANCE_O2;
	aSub.Mass=1814;
	aSub.SetTemp(294.259);

	PrimaryOxygenTank = new mTank("PriOxyTank", 2.683010261, 0);
	PrimaryOxygenTank->OutValve.Size = .02;
	*PrimaryOxygenTank += aSub;
	PrimaryOxygenTank->OutValve.Open = 1;

	SecondaryOxygenTank = new mTank("SecOxyTank", 2.683010261, 0);
	SecondaryOxygenTank->OutValve.Size = .02;
	*SecondaryOxygenTank += aSub;
	SecondaryOxygenTank->OutValve.Open = 1;

	aSub.SubstType = SUBSTANCE_O2;
	aSub.Mass=1;
	aSub.SetTemp(294.259);

	MercurySuit = new mTank("MercSuit", 2, 0);
	*MercurySuit += aSub;
	MercurySuit->InValve.Open = 1;

	aSub.SubstType = SUBSTANCE_O2;
	aSub.Mass=800;
	aSub.SetTemp(294.259);
	Capsule = new mTank("Capsule", 1700, 0.5/3600.0);
	Capsule->InValve.Open = 1;
	Capsule->VentValve.Open = 1;
	Capsule->VentValve.Size = 25;
	*Capsule += aSub;

	PrimarySuitFeed = new mPipe("PriSuitFeed", &PrimaryOxygenTank->OutValve,&MercurySuit->InValve, 35000, 0);
	PrimarySuitFeed->TypePipe = 1;
	PrimarySuitFeed->Open = 1;
	SecondarySuitFeed = new mPipe("SecSuitFeed", &SecondaryOxygenTank->OutValve,&MercurySuit->InValve, 35900, 0);
	SecondarySuitFeed ->TypePipe = 1;
	SecondarySuitFeed ->Open = 1;

	PrimaryCapsuleFeed = new mPipe("PriCapFeed", &PrimaryOxygenTank->OutValve,&Capsule->InValve, 35000, 28300);
	PrimaryCapsuleFeed->TypePipe = 2;
	PrimaryCapsuleFeed ->Open = 1;
	SecondaryCapsuleFeed = new mPipe("SecCapFeed", &SecondaryOxygenTank->OutValve,&Capsule->InValve, 34900, 28300);
	SecondaryCapsuleFeed ->TypePipe = 2;
	SecondaryCapsuleFeed ->Open = 1;

	CapsuleVent = new mVent("CapsuleVent", &Capsule->VentValve, 38000, 0);

	Astronaut = new mCrew("Astronaut", MercurySuit);

	Main1 = new mBattery("Main1", 3000 * 3600, 24);
	Main2 = new mBattery("Main2", 3000 * 3600, 24);
	Main3 = new mBattery("Main3", 3000 * 3600, 24);
	Stby1 = new mBattery("Stby1", 1500 * 3600, 24);
	Stby2 = new mBattery("Stby2", 1500 * 3600, 24);
	Iso1 = new mBattery("Iso1", 1500 * 3600, 24);
	
	
	DCMain  = new mBus("DCMainBus");
	MainBty = new mBus("MainBty");
	StbyBty = new mBus("StbyBty");
	IsoBty  = new mBus("IsoBty");
	StbyBus = new mBus("StbyBus");
	IsoStbyBus  = new mBus("IsoStbyBus");
	//CommBus     = new mBus("CommBus");

	MainBty->Connect(Main1);
	MainBty->Connect(Main2);
	MainBty->Connect(Main3);
	//Bus2->PowerOn = 0;
	StbyBty->Connect(Stby1);
	StbyBty->Connect(Stby2);

	StbyBus->Connect(Stby1);
	StbyBus->Connect(Stby2);

	IsoStbyBus->Connect(Stby1);
	IsoStbyBus->Connect(Stby2);
	
	IsoBty->Connect(Iso1);
	IsoBty->Connect(IsoStbyBus);

	DCMain->Connect(MainBty);
	DCMain->Connect(StbyBty);

	//CommBus->Connect(DCMain);




	Systems->AddSystem(PrimaryOxygenTank);
	Systems->AddSystem(SecondaryOxygenTank);
	Systems->AddSystem(Capsule);
	Systems->AddSystem(MercurySuit);
	Systems->AddSystem(Astronaut);
	Systems->AddSystem(CapsuleVent);
	Systems->AddSystem(PrimarySuitFeed);
	Systems->AddSystem(SecondarySuitFeed);
	Systems->AddSystem(PrimaryCapsuleFeed);
	Systems->AddSystem(SecondaryCapsuleFeed);
	Systems->AddSystem(Main1);
	Systems->AddSystem(Main2);
	Systems->AddSystem(Main3);
	Systems->AddSystem(Stby1);
	Systems->AddSystem(Stby2);
	Systems->AddSystem(Iso1);
	Systems->AddSystem(MainBty);
	Systems->AddSystem(StbyBty);
	Systems->AddSystem(IsoBty);
	Systems->AddSystem(DCMain);
	Systems->AddSystem(StbyBus);
	Systems->AddSystem(IsoStbyBus);

	SysObj = new mElectricObject("Background",DCMain, 10);
	Systems->AddSystem(SysObj);

	SysObj = new mElectricObject("Beacon",DCMain, 1);
	Systems->AddSystem(SysObj);

	SysObj = new mElectricObject("UHF_DF",DCMain, 1);
	Systems->AddSystem(SysObj);

	SysObj = new mElectricObject("Vox",DCMain, 1);
	Systems->AddSystem(SysObj);

	SysObj = new mElectricObject("Transmit",DCMain, 1);
	Systems->AddSystem(SysObj);

	SysObj = new mElectricObject("TLM_LoFreq",DCMain, 1);
	Systems->AddSystem(SysObj);

	SysObj = new mElectricObject("Aux_Bcn",DCMain, 1);
	Systems->AddSystem(SysObj);

	SysObj = new mElectricObject("Trim_HiFreq",DCMain, 1);
	Systems->AddSystem(SysObj);

	SysObj = new mElectricObject("Comm_RcvrA",DCMain, 1);
	Systems->AddSystem(SysObj);

	SysObj = new mElectricObject("Cabin_Fans",DCMain, 1);
	Systems->AddSystem(SysObj);

	SysObj = new mElectricObject("Suit_Fans",DCMain, 1);
	Systems->AddSystem(SysObj);

	SysObj = new mElectricObject("ASCS_Bus",DCMain, 4);
	Systems->AddSystem(SysObj);
	
	SysObj = new mElectricObject("Ang_Rate_Ind",DCMain, 4);
	Systems->AddSystem(SysObj);

	SysObj = new mElectricObject("Programmer",DCMain, 5);
	Systems->AddSystem(SysObj);

	//	Test = new mElectricObject("eTest", DCMain, 10);
//	Test2 = new mElectricObject("eTestIso", IsoBty, 1);

}


void Mercury_ControlPanel::TimeStepSystem(VESSEL *vessel, double simt){

	mElectricObject* SysObj;
	mBus *DCMainBus = (mBus*) Systems->GetComponent("DCMainBus");
	mBus *StbyBus = (mBus*) Systems->GetComponent("StbyBus");

	if(pull_decomp == AUTO_ON) {
		mVent *Vent = (mVent*) Systems->GetComponent("CapsuleVent");
		Vent->Open = 1;
	} else if(pull_decomp == AUTO_OFF) {
		mVent *Vent = (mVent*) Systems->GetComponent("CapsuleVent");
		Vent->Open = 0;
	}

	mBus* StbyBty = (mBus*) Systems->GetComponent("StbyBty");
	
	if (StbyBtrySwitch == SWITCH_LEFT) {
		StbyBty->PowerOn=1;

	} else if (StbyBtrySwitch == SWITCH_RIGHT){
		StbyBty->PowerOn=0;
	}

	mBus* IsoStbyBus = (mBus*) Systems->GetComponent("IsoStbyBus");
	
	if (IsolBtrySwitch == SWITCH_LEFT) {
		IsoStbyBus->PowerOn=1;

	} else if (IsolBtrySwitch == SWITCH_RIGHT){
		IsoStbyBus->PowerOn=0;
	}

	SysObj = (mElectricObject*) Systems->GetComponent("Beacon");
	if (AudioBusSwitch == SWITCH_LEFT) {
		SysObj->SRC =  StbyBus;
	} else if (AudioBusSwitch == SWITCH_RIGHT) {
		SysObj->SRC =  DCMainBus;
	}

	if (CommBeaconSwitch == SWITCH_LEFT) {
		SysObj->PowerOn = 0;
	} else if (CommBeaconSwitch == SWITCH_RIGHT) {
		SysObj->PowerOn = 1;
	}

	SysObj = (mElectricObject*) Systems->GetComponent("Vox");
	if (AudioBusSwitch == SWITCH_LEFT) {
		SysObj->SRC =  StbyBus;
	} else if (AudioBusSwitch == SWITCH_RIGHT) {
		SysObj->SRC =  DCMainBus;
	}

	if (VOXSwitch == SWITCH_LEFT) {
		SysObj->PowerOn = 1;
		SysObj->DrawAmps = 0.5;
	} else if (VOXSwitch == SWITCH_RIGHT) {
		SysObj->PowerOn = 1;
		SysObj->DrawAmps = 1.5;
	} else if (VOXSwitch == SWITCH_MIDDLE) {
		SysObj->PowerOn = 0;
	}

	SysObj = (mElectricObject*) Systems->GetComponent("UHF_DF");
	if (AudioBusSwitch == SWITCH_LEFT) {
		SysObj->SRC =  StbyBus;
	} else if (AudioBusSwitch == SWITCH_RIGHT) {
		SysObj->SRC =  DCMainBus;
	}
	if (CommSelectSwitch == SWITCH_LEFT) {
		SysObj->PowerOn = 0;
	} else if (CommSelectSwitch == SWITCH_RIGHT) {
		SysObj->PowerOn = 1;
	}

	SysObj = (mElectricObject*) Systems->GetComponent("Transmit");
	if (AudioBusSwitch == SWITCH_LEFT) {
		SysObj->SRC =  StbyBus;
	} else if (AudioBusSwitch == SWITCH_RIGHT) {
		SysObj->SRC =  DCMainBus;
	}

	if (TransmitSwitch == SWITCH_LEFT) {
		SysObj->PowerOn = 1;
		SysObj->DrawAmps = 1;
	} else if (TransmitSwitch == SWITCH_RIGHT) {
		SysObj->PowerOn = 1;
		if (UHFSelectSwitch == SWITCH_LEFT) {
			SysObj->DrawAmps = 1;
		} else if (UHFSelectSwitch == SWITCH_RIGHT) {
			SysObj->DrawAmps = 2;
		};
	} else if (TransmitSwitch == SWITCH_MIDDLE) {
		SysObj->PowerOn = 0;
	}


	SysObj = (mElectricObject*) Systems->GetComponent("TLM_LoFreq");
	if (AudioBusSwitch == SWITCH_LEFT) {
		SysObj->SRC =  StbyBus;
	} else if (AudioBusSwitch == SWITCH_RIGHT) {
		SysObj->SRC =  DCMainBus;
	}
	if (switch_tlm_freq) {
		SysObj->PowerOn = 1;
	} else {
		SysObj->PowerOn = 0;
	}


	SysObj = (mElectricObject*) Systems->GetComponent("Aux_Bcn");
	if (AudioBusSwitch == SWITCH_LEFT) {
		SysObj->SRC =  StbyBus;
	} else if (AudioBusSwitch == SWITCH_RIGHT) {
		SysObj->SRC =  DCMainBus;
	}
	if(AuxBcnFuse == FUSE_OFF) {
		SysObj->PowerOn = 0;
	} else {
		SysObj->PowerOn = 1;
	}

	SysObj = (mElectricObject*) Systems->GetComponent("Trim_HiFreq");
	if (AudioBusSwitch == SWITCH_LEFT) {
		SysObj->SRC =  StbyBus;
	} else if (AudioBusSwitch == SWITCH_RIGHT) {
		SysObj->SRC =  DCMainBus;
	}
	if(TrimHiFreqFuse == FUSE_OFF) {
		SysObj->PowerOn = 0;
	} else {
		SysObj->PowerOn = 1;
	}

	SysObj = (mElectricObject*) Systems->GetComponent("Comm_RcvrA");
	if (AudioBusSwitch == SWITCH_LEFT) {
		SysObj->SRC =  StbyBus;
	} else if (AudioBusSwitch == SWITCH_RIGHT) {
		SysObj->SRC =  DCMainBus;
	}
	if(ComVRcvrAFuse == FUSE_OFF) {
		SysObj->PowerOn = 0;
	} else {
		SysObj->PowerOn = 1;
	}


	SysObj = (mElectricObject*) Systems->GetComponent("Cabin_Fans");
	if (FansACBusSwitch == SWITCH_MIDDLE ||	CabinFanSwitch == SWITCH_LEFT) {
		SysObj->PowerOn = 0;
	} else {
		SysObj->PowerOn = 1;
	}

	SysObj = (mElectricObject*) Systems->GetComponent("Suit_Fans");
	if (FansACBusSwitch == SWITCH_MIDDLE || SuitFanFuse == FUSE_OFF) {
		SysObj->PowerOn = 0;
	} else {
		SysObj->PowerOn = 1;
	}

	SysObj = (mElectricObject*) Systems->GetComponent("ASCS_Bus");
	if (ACBusSwitch == SWITCH_MIDDLE) {
		SysObj->PowerOn = 0;
	} else {
		SysObj->PowerOn = 1;
	}
	
	SysObj = (mElectricObject*) Systems->GetComponent("Ang_Rate_Ind");
	if (switch_maneuver == false ||	ACBusSwitch == SWITCH_MIDDLE) {
		SysObj->PowerOn = 0;
	} else {
		SysObj->PowerOn = 1;
	}

	SysObj = (mElectricObject*) Systems->GetComponent("Programmer");
	if (ProgrammerFuse == FUSE_OFF) {
		SysObj->PowerOn = 0;
	} else {
		SysObj->PowerOn = 1;
	}
	
	
	if(this->pull_repress == AUTO_ON) {
		mPipe *Feed1 = (mPipe*) Systems->GetComponent("PriCapFeed");
		mPipe *Feed2 = (mPipe*) Systems->GetComponent("SecCapFeed");
		Feed1->TypePipe = 1;
		Feed2->TypePipe = 1;
	} else if(pull_decomp == AUTO_OFF) {
		mPipe *Feed1 = (mPipe*) Systems->GetComponent("PriCapFeed");
		mPipe *Feed2 = (mPipe*) Systems->GetComponent("SecCapFeed");
		Feed1->TypePipe = 2;
		Feed2->TypePipe = 2;
	}
	
	mBattery *Temp1 = (mBattery*) Systems->GetComponent("Main1");
	mBattery *Temp2 = (mBattery*) Systems->GetComponent("Main2");
	mBattery *Temp3 = (mBattery*) Systems->GetComponent("Main3");
	mBattery *Temp4 = (mBattery*) Systems->GetComponent("Stby1");
	mBattery *Temp5 = (mBattery*) Systems->GetComponent("Stby2");
	mBattery *Temp6 = (mBattery*) Systems->GetComponent("Iso1");
	mBus *tBus1 = (mBus*) Systems->GetComponent("DCMainBus");


	Systems->Refresh(oapiGetSimStep());

	//sprintf(oapiDebugString(), "Batt: %f, %f, %f, %f, %f, %f, %f", Temp1->Power, Temp2->Power, Temp3->Power, Temp4->Power, Temp5->Power, Temp1->power_load / oapiGetSimStep(), tBus1->power_load / oapiGetSimStep() );

}

void Mercury_ControlPanel::DoTelemetry () {
	/*double telRetroSeq = 0.0;
	double cur_time   = oapiGetSimTime() - clock_simt;
	double countdown = oapiGetSimTime() - CountDownTime;
	double retro_countdown = retro_simt - cur_time;
	double tempD  = 0.0;

	tempD = GetValue("merc", "cretrotimer");
	if (tempD == 1.0) {
		OutputValue("merc", "cretrotimer", 0.0);
		retro_simt = GetValue("merc", "cretrotime");
	}

	if (!bClockStarted ) cur_time = 0.0;
	if (!bClockStarted ) retro_countdown = 0.0;
	if (!bDoCountDown) countdown = 295.0;
	telRetroSeq = GetValue("merc", "rseq");
	OutputValue("merc", "rcountdown", retro_countdown);
	OutputValue("merc", "rtime", retro_simt);
	OutputValue("merc", "countdown", countdown);
	OutputValue("merc", "curtime", cur_time);



	//sprintf(oapiDebugString(),"tel: %f", telRetroSeq);
	if (telRetroSeq == 1.0) {
		push_retrosequence = PUSH_DOWN;
	}*/
}


void Mercury_ControlPanel::Timestep (VESSEL *vessel, double simt)
{
	VECTOR3 new_vel;
	double new_speed;
	double new_alt;
	double tempD;

	DoTelemetry();
	TimeStepSystem(vessel, simt);	

	oapiTriggerPanelRedrawArea (0, AID_GAUGE_FUEL);
	oapiTriggerPanelRedrawArea (1, FC_GAUGE_FUEL);
	oapiTriggerPanelRedrawArea (0, AID_RETROGRADE_TIMER);

/*  oapiTriggerPanelRedrawArea (5, AID_GAUGE_CABIN_PRESS);
	oapiTriggerPanelRedrawArea (5, AID_GAUGE_SUIT);
	oapiTriggerPanelRedrawArea (5, AID_GAUGE_OXYGEN);

	oapiTriggerPanelRedrawArea (5, AID_GAUGE_DC_VOLTS);
	oapiTriggerPanelRedrawArea (5, AID_GAUGE_DC_AMPS);
	oapiTriggerPanelRedrawArea (5, AID_GAUGE_AC_VOLTS);
*/
	new_alt = vessel->GetAltitude();
	if (simt - last_simt > 0)
		descent_rate = (new_alt - old_alt) / oapiGetSimStep();;


	oapiTriggerPanelRedrawArea (0, AID_GAUGE_DESCENT);
	old_alt = new_alt;

	if (push_timezero == PUSH_DOWN)
		StartClock();

	culm_simt += oapiGetSimStep();
	if (culm_simt > 0.1) {
		vessel->GetShipAirspeedVector(new_vel);
		old_speed = sqrt(old_vel.x * old_vel.x + old_vel.y * old_vel.y + old_vel.z * old_vel.z);
		new_speed = sqrt(new_vel.x * new_vel.x + new_vel.y * new_vel.y + new_vel.z * new_vel.z);// / oapiGetSimStep();
		tempD = ((new_speed-old_speed) / culm_simt)/ G, culm_simt;
		long_accel = (long_accel + tempD) / 2 ;
		//sprintf(oapiDebugString(),"OS: %f, NS: %f, LA: %f OA: %f CS: %f",old_speed,new_speed,long_accel, ((new_speed-old_speed) / culm_simt)/ G, culm_simt);
		old_vel.x = new_vel.x;
		old_vel.y = new_vel.y;
		old_vel.z = new_vel.z;
		culm_simt = 0;
	}

	vessel->GetAngularVel(new_vel);
	if (this->switch_gyro == GYRO_NORM && IND_05G != SEQ_GREEN) 
	{
		tempD = vessel->GetPitch();
		if (fabs(tempD) <= 55.0*RAD)
			x_pitch_heading = tempD;
		else
			x_pitch_heading += new_vel.x * (simt - last_simt);
		x_pitch_heading = tempD;

		tempD = vessel->GetSlipAngle()-PI;
		if (fabs(vessel->GetBank()) <= 55.0*RAD)
			y_yaw_heading = tempD;
		else
			y_yaw_heading -= new_vel.y * (simt - last_simt);


		tempD = vessel->GetBank();
		if (fabs(tempD) <= 55.0*RAD)
			z_roll_heading = tempD;
		else
			z_roll_heading -= new_vel.z * (simt - last_simt);

	} else if (this->switch_gyro == GYRO_CAGED){
		x_pitch_heading = 0;
		y_yaw_heading = 0;
		z_roll_heading = 0;
	} else {
		x_pitch_heading += new_vel.x * (simt - last_simt);
		y_yaw_heading -= new_vel.y * (simt - last_simt);
		z_roll_heading -= new_vel.z * (simt - last_simt);
	}

	//vector3 vHeading = GetVesselHeading(vessel);
	//x_pitch_heading = vHeading.x-90*RAD;
	//y_yaw_heading = vHeading.y;
	//z_roll_heading = vHeading.z+90*RAD;
	

	if (x_pitch_heading >= 2*PI)
		x_pitch_heading -= 2*PI;
	if (x_pitch_heading < 0)
		x_pitch_heading += 2*PI;

	if (y_yaw_heading >= 2*PI)
		y_yaw_heading -= 2*PI;
	if (y_yaw_heading < 0)
		y_yaw_heading += 2*PI;

	if (z_roll_heading >= 2*PI)
		z_roll_heading -= 2*PI;
	if (z_roll_heading < 0)
		z_roll_heading += 2*PI;
	//sprintf(oapiDebugString(), "horz: %f, %f, %f | vel: %f, %f, %f", x_pitch_heading * DEG, y_yaw_heading*DEG, z_roll_heading*DEG, new_vel.x*DEG, new_vel.y*DEG, new_vel.z*DEG);	


	if (warn_status[WARN_RETRO_WARN] == WARN_ON) {
		//if(IsPlaying(SOUND_WARNING) == 0 && RetroWarnSwitch == SWITCH_RIGHT) {
			//PlayVesselWave(SOUND_WARNING, LOOP);
		//}
	}

	if (warn_status[WARN_O2_EMER] == WARN_ON) {
		//if(IsPlaying(SOUND_WARNING) == 0 && O2EmerWarnSwitch == SWITCH_RIGHT) {
			//PlayVesselWave(SOUND_WARNING, LOOP);
		//}
	}

	if (warn_status[WARN_CABIN_PRESS] == WARN_ON) {
		//if(IsPlaying(SOUND_WARNING) == 0 && CabinPressWarnSwitch == SWITCH_RIGHT) {
			//PlayVesselWave(SOUND_WARNING, LOOP);
		//}
	}

	if (warn_status[WARN_FUEL_QUAN] == WARN_ON) {
		//if(IsPlaying(SOUND_WARNING) == 0 && FuelQuanWarnSwitch == SWITCH_RIGHT) {
			//PlayVesselWave(SOUND_WARNING, LOOP);
		//}
	}

	int warn_total = 0;
	if (RetroWarnSwitch == SWITCH_RIGHT) {
		warn_total += warn_status[WARN_RETRO_WARN];
	}

	if (O2EmerWarnSwitch == SWITCH_RIGHT) {
		warn_total += warn_status[WARN_O2_EMER];
	}

	if (CabinPressWarnSwitch == SWITCH_RIGHT) {
		warn_total += warn_status[WARN_CABIN_PRESS];
	}
	if (FuelQuanWarnSwitch == SWITCH_RIGHT) {
		warn_total += warn_status[WARN_FUEL_QUAN];
	}
	//sprintf(oapiDebugString(),"status %d switch %d playing %d total %d",warn_status[WARN_RETRO_WARN],RetroWarnSwitch,IsPlaying(SOUND_WARNING), warn_total);

	//if (warn_total == 0)
		//StopVesselWave(SOUND_WARNING);

	last_simt = simt;
}
bool Mercury_ControlPanel::LoadPanel (VESSEL *vessel, int id)
{
	ReleaseSurfaces();
	HBITMAP hBmp;
	switch (id) {	
	case 0:
		oldAlt = -1;
		PeriscopePanel = false;
		CameraPanel    = false;
		oapiCameraAttach(vessel->GetHandle(),0);
		vessel->SetCameraOffset(_V(0,.75,-.75));
		oapiCameraSetAperture(RAD*(60/2));
		hBmp = LoadBitmap (g_Param.hDLL, MAKEINTRESOURCE (IDB_MAINPANEL));
		oapiRegisterPanelBackground (hBmp, PANEL_ATTACH_TOP|PANEL_ATTACH_BOTTOM|PANEL_ATTACH_LEFT|PANEL_ATTACH_RIGHT, 0xff00ff);
		oapiSetPanelNeighbours (3,4,1,2);
		oapiRegisterPanelArea (AID_AUTOPILOT,            _R( 464, 37, 497, 60)  , PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN, PANEL_MAP_BACKGROUND);

		adi->ScrX = 820;
		adi->ScrY = 540;
		adi->RegisterMe(AID_GLOBEPANEL);
		oapiRegisterPanelArea (AID_GAUGE_ROLL,           _R( 766, 56, 834, 124) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_GAUGE_YAW,            _R( 836, 104, 904, 172), PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_GAUGE_PITCH,          _R( 904, 56, 972, 124) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_GAUGE_RATE,           _R( 848, 57, 891, 100) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_GAUGE_FUEL,           _R( 560, 201, 689, 300), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_GAUGE_ALT,            _R( 546, 445, 703, 602), PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);


		oapiRegisterPanelArea (AID_GAUGE_ACCEL,           _R( 579, 100, 670, 191) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_GAUGE_DESCENT,         _R( 579, 340, 670, 431) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);

	
		oapiRegisterPanelArea (AID_ABORT,                _R( 580, 25, 637, 89) , PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SEQ_ABORTJETT,        _R( 439, 124, 528, 156), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SEQ_CAPSULESEP,       _R( 439, 169, 528, 201), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_ABORTJETT,     _R( 402, 121, 436, 163), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_CAPSULESEP,    _R( 402, 166, 436, 207), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);

		oapiRegisterPanelArea (AID_SWITCH_AUTOMATICMODE, _R( 53, 307, 86, 330) , PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_PULL_MANUAL_MODE,     _R( 256, 409, 312, 497), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_PULL_AUTO_ROLL_MODE,  _R( 256, 499, 312, 587), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_PULL_AUTO_YAW_MODE,   _R( 256, 589, 312, 677), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_PULL_AUTO_PITCH_MODE, _R( 256, 679, 312, 767), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);

		oapiRegisterPanelArea (AID_HANDLE_DECOMP,        _R(  50, 408, 144, 530), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_HANDLE_REPRESS,       _R( 145, 408, 244, 530), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);

		oapiRegisterPanelArea (AID_SWITCH_SQUIB,         _R( 263, 224, 296, 247), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_RETROAUTOJETT, _R( 263, 274, 296, 297), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_RETRODELAY,    _R( 184, 546, 217, 569), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_PUSH_RETROSEQUENCE,   _R( 405, 215, 436, 246), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN + PANEL_MOUSE_UP, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_RETROATTITUDE, _R( 389, 262, 422, 285), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_PUSH_RETROFIRE,       _R( 405, 305, 436, 336), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN + PANEL_MOUSE_UP, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_PUSH_RETROJETT,       _R( 405, 350, 436, 381), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN + PANEL_MOUSE_UP, PANEL_MAP_BACKGROUND);

		oapiRegisterPanelArea (AID_SWITCH_PHOTO_LIGHTS,  _R(  80, 650, 113, 673), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_LIGHTS,        _R( 185, 645, 218, 668), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_TLM_FREQ,      _R( 188, 722, 221, 755), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_LIGHT_TEST,    _R( 576, 656, 609, 679), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_MANEUVER,      _R( 641, 656, 674, 679), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		
		oapiRegisterPanelArea (AID_SEQ_RETROSEQUENCE,    _R( 439, 214, 528, 246), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SEQ_RETROATTITUDE,    _R( 439, 259, 528, 291), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SEQ_RETROFIRE,        _R( 439, 304, 528, 336), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SEQ_RETROJETT,        _R( 439, 349, 528, 381), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);

		oapiRegisterPanelArea (AID_PUSH_05G,             _R( 405, 440, 436, 471), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN + PANEL_MOUSE_UP, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_PUSH_DROGUE,          _R( 405, 485, 436, 516), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN + PANEL_MOUSE_UP, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_SNORKEL,       _R( 397, 525, 436, 566), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_MAIN,          _R( 397, 570, 436, 611), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_RESERVE,       _R( 397, 615, 436, 656), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_LANDINGBAG,    _R( 374, 674, 407, 697), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);

		oapiRegisterPanelArea (AID_SEQ_05G,              _R( 439, 439, 528, 471), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SEQ_MAIN,             _R( 439, 574, 528, 606), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SEQ_LANDINGBAG,       _R( 439, 664, 528, 696), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);

		oapiRegisterPanelArea (AID_SWITCH_RSCS,          _R( 153, 307, 186, 330), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_GYRO,          _R( 104, 366, 137, 389), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_RETROGRADE_TIMER,     _R( 770, 241,1010, 500), PANEL_REDRAW_ALWAYS, PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_PUSH_TIMEZERO,        _R(1010, 138,1041, 169), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN + PANEL_MOUSE_UP, PANEL_MAP_BACKGROUND);

		oapiRegisterPanelArea (AID_SEQ_RESCUE,           _R( 63, 696, 153, 729), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_RESCUE,        _R( 91, 732, 124, 755), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);

		//oapiRegisterPanelArea (AID_GLOBE,                _R( 820, 540, 960, 680), PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		
		srf[0]  = oapiCreateSurface (LOADBMP (IDB_MAINPANEL));
		srf[1]  = oapiCreateSurface (LOADBMP (IDB_SEQSWITCH));
		srf[2]  = oapiCreateSurface (LOADBMP (IDB_EARTHGLOBE));
		srf[3]  = oapiCreateSurface (LOADBMP (IDB_ABORT));
		srf[4]  = oapiCreateSurface (LOADBMP (IDB_SEQLIGHT));
		srf[5]  = oapiCreateSurface (LOADBMP (IDB_RINGSWITCH));
		srf[6]  = oapiCreateSurface (LOADBMP (IDB_FLIGHTSWITCH));
		srf[7]  = oapiCreateSurface (LOADBMP (IDB_PULLHANDLE));
		srf[8]  = oapiCreateSurface (LOADBMP (IDB_PUSHBUTTON));
		srf[9]  = oapiCreateSurface (LOADBMP (IDB_RDGLOBEPANEL));
		srf[10] = oapiCreateSurface (LOADBMP (IDB_RETROGRADEPANEL));
		srf[11] = oapiCreateSurface (LOADBMP (IDB_RETROHANDLEINCMIN));
		srf[12] = oapiCreateSurface (LOADBMP (IDB_RETROHANDLEINCSEC));
		srf[13] = oapiCreateSurface (LOADBMP (IDB_RETROHANDLEOFF));
		srf[14] = oapiCreateSurface (LOADBMP (IDB_RETROHANDLEDECSEC));
		srf[15] = oapiCreateSurface (LOADBMP (IDB_RETROHANDLEDECMIN));
		srf[16] = oapiCreateSurface (LOADBMP (IDB_RETRONUMBERS));
		srf[17] = oapiCreateSurface (LOADBMP (IDB_RETROWARN));
		srf[18] = oapiCreateSurface (LOADBMP (IDB_PUSHBUTTON_FLIGHT));
		srf[19] = oapiCreateSurface (LOADBMP (IDB_RETRONUMBERS));
		srf[20] = oapiCreateSurface (LOADBMP (IDB_DECOMP_HANDLE));
		srf[21] = oapiCreateSurface (LOADBMP (IDB_REPRESS_HANDLE));
		srf[22] = oapiCreateSurface (LOADBMP (IDB_ALT_KNOB));
		srf[23] = oapiCreateSurface (LOADBMP (IDB_KNOBAC));
		srf[24] = oapiCreateSurface (LOADBMP (IDB_KNOBDC));
		srf[25] = oapiCreateSurface (LOADBMP (IDB_FUSESWITCHSTRIP));
		srf[26] = oapiCreateSurface (LOADBMP (IDB_FUSESWITCHWHITE));
		srf[27] = oapiCreateSurface (LOADBMP (IDB_WARNLIGHTS));
		break;
	case 1:
		PeriscopePanel = false;
		CameraPanel    = false;
		oapiCameraAttach(vessel->GetHandle(),0);
		vessel->SetCameraOffset(_V(0,.75,-.75));
		vessel->SetCameraDefaultDirection(_V(0,sin(20.5*RAD),cos(20.5*RAD)));
		oapiCameraSetCockpitDir(0,0);
		//vessel->SetCameraDefaultDirection(_V(0,0,1));
		vessel->SetCameraRotationRange(0.0,0.0,0.0,0.0);
		oapiCameraSetAperture(RAD*35);
		if (CapsuleNumber == 7) {
			hBmp = LoadBitmap (g_Param.hDLL, MAKEINTRESOURCE (IDB_FLIGHTCONTROL7));
		} else {
			hBmp = LoadBitmap (g_Param.hDLL, MAKEINTRESOURCE (IDB_FLIGHTCONTROL));
		}
		oapiRegisterPanelBackground (hBmp, PANEL_ATTACH_TOP|PANEL_ATTACH_BOTTOM|PANEL_ATTACH_LEFT|PANEL_ATTACH_RIGHT, 0xff00ff);
		oapiSetPanelNeighbours (-1,-1,-1,0);

		oapiRegisterPanelArea (AID_AUTOPILOT,            _R( 121, 562, 155, 596)  , PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_GAUGE_ROLL,           _R( 424, 585, 492, 654) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_GAUGE_YAW,            _R( 493, 634, 563, 713), PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_GAUGE_PITCH,          _R( 562, 585, 631, 655) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_GAUGE_RATE,           _R( 506, 587, 549, 630) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_GAUGE_ACCEL,          _R( 236, 627, 327, 715) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_ABORT,                _R( 237, 552, 294, 616) , PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SEQ_ABORTJETT,        _R(  95, 650, 185, 683), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SEQ_CAPSULESEP,       _R(  95, 695, 185, 738), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_ABORTJETT,     _R(  58, 647,  92, 689), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_CAPSULESEP,    _R(  58, 692,  92, 734), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);

		oapiRegisterPanelArea (AID_GAUGE_CABIN_PRESS,    _R( 728,  624, 820, 716) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_GAUGE_CABIN_TEMP,     _R( 818,  624, 908, 716) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);

		oapiRegisterPanelArea (FC_GAUGE_ROLL,           _R( 87, 96, 294, 302) ,  PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (FC_GAUGE_YAW,            _R( 297, 244, 503, 446), PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (FC_GAUGE_PITCH,          _R( 502, 96, 708, 302) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);

		oapiRegisterPanelArea (AID_PUSH_TIMEZERO,       _R( 667, 669, 698, 700), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN + PANEL_MOUSE_UP,PANEL_MAP_BACKGROUND);

		
		if (CapsuleNumber == 7) {
			oapiRegisterPanelArea (FC_GAUGE_RATE,           _R( 452, 328, 589, 472) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
			oapiRegisterPanelArea (FC_GAUGE_FUEL,           _R( 756, 80, 1146, 468), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
			oapiRegisterPanelArea (FC_TIMER,				_R( 472, 510, 564, 524), PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		} else {
			oapiRegisterPanelArea (FC_GAUGE_RATE,           _R( 904, 362, 1038, 506) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
			oapiRegisterPanelArea (FC_GAUGE_FUEL,           _R( 756,  80, 1146, 468), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
			oapiRegisterPanelArea (FC_TIMER,				_R( 924, 544, 1017, 578), PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		}
		srf[1]  = oapiCreateSurface (LOADBMP (IDB_SEQSWITCH));
		srf[3]  = oapiCreateSurface (LOADBMP (IDB_ABORT));
		srf[4]  = oapiCreateSurface (LOADBMP (IDB_SEQLIGHT));
		srf[5]  = oapiCreateSurface (LOADBMP (IDB_RINGSWITCH));
		srf[6]  = oapiCreateSurface (LOADBMP (IDB_FLIGHTSWITCH));
		srf[8]  = oapiCreateSurface (LOADBMP (IDB_PUSHBUTTON));
		srf[16] = oapiCreateSurface (LOADBMP (IDB_RETRONUMBERS));
		srf[18] = oapiCreateSurface (LOADBMP (IDB_PUSHBUTTON_FLIGHT));


		break;
	case 2:
		PeriscopePanel = true;
		CameraPanel    = false;
		oapiCameraAttach(vessel->GetHandle(),0);
		vessel->SetCameraOffset(_V(0,.75 * sin(-75.5*RAD),.75 * cos(-75.5*RAD)));
		vessel->SetCameraDefaultDirection(_V(0,sin(-75.5*RAD),cos(-75.5*RAD)));
		oapiCameraSetCockpitDir(0,0);
		vessel->SetCameraRotationRange(0.0,0.0,0.0,0.0);
		if (view_switch == 0)
			oapiCameraSetAperture(RAD*(157/2));
		else
			oapiCameraSetAperture(RAD*(20/2));
		hBmp = LoadBitmap (g_Param.hDLL, MAKEINTRESOURCE (IDB_PERISCOPE));
		oapiRegisterPanelBackground (hBmp, PANEL_ATTACH_TOP|PANEL_ATTACH_BOTTOM|PANEL_ATTACH_LEFT|PANEL_ATTACH_RIGHT, 0xffffff);
		oapiSetPanelNeighbours (-1,-1,0,5);

		srf[0]  = oapiCreateSurface (LOADBMP (IDB_PERISCOPE));
		srf[6]  = oapiCreateSurface (LOADBMP (IDB_FLIGHTSWITCH));
		srf[16] = oapiCreateSurface (LOADBMP (IDB_RETRONUMBERS));
		srf[22] = oapiCreateSurface (LOADBMP (IDB_ALT_KNOB));

		oapiRegisterPanelArea (PERI_FILTER_SWITCH,_R( 960, 700, 993, 723), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (PERI_VIEW_SWITCH,  _R( 900, 700, 933, 723), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (PERI_ALT_KNOB,     _R(  26, 568, 108, 646), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (PERI_ALTITUDE,     _R(  39, 712,  89, 726), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (PERI_ALT_IND,      _R( 163,  15, 889, 741), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		break;
	case 3:
		PeriscopePanel = false;
		CameraPanel    = false;
		hBmp = LoadBitmap (g_Param.hDLL, MAKEINTRESOURCE (IDB_FUSEPANEL));
		oapiRegisterPanelBackground (hBmp, PANEL_ATTACH_TOP|PANEL_ATTACH_BOTTOM|PANEL_ATTACH_LEFT|PANEL_ATTACH_RIGHT, 0xff00ff);
		oapiSetPanelNeighbours (-1,0,-1,-1);
		vessel->SetCameraDefaultDirection(_V(0,0,1));
		vessel->SetCameraRotationRange(.8*PI,.8*PI,.4*PI,.4*PI);
		vessel->SetCameraOffset(_V(0,.75,-.75));



		oapiRegisterPanelArea (AID_FUSE_PHASE_SHIFTER,        _R( 579,  57, 615,  88), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_EMER_CAP_SEP,         _R( 626,  57, 662,  88), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_EMER_ESCAPE_RCKT,     _R( 673,  57, 709,  88), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_TOWER_SEP_CONTRL,     _R( 720,  57, 756,  88), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_EMER_TOWER_SEP,       _R( 762,  57, 798,  88), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_EMER_TOWER_JETT,      _R( 809,  57, 845,  88), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_EMER_POSGRD,          _R( 859,  57, 895,  88), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);

		oapiRegisterPanelArea (AID_FUSE_AUX_BCN,              _R( 579, 216, 615, 247), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_RETRO_ONE,            _R( 626, 216, 662, 247), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_RETRO_TWO,            _R( 673, 216, 709, 247), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_RETRO_THREE,          _R( 720, 216, 756, 247), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_EMER_RETRO_SEQ,       _R( 762, 216, 798, 247), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_EMER_RETRO_JETT,      _R( 809, 216, 845, 247), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);

		oapiRegisterPanelArea (AID_FUSE_ASCS_05G,             _R( 579, 373, 615, 404), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_EMER_05G,             _R( 626, 373, 662, 404), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_EMER_DROUGE_DEPLOY,   _R( 673, 373, 709, 404), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_EMER_MAIN_DEPLOY,     _R( 720, 373, 756, 404), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_RESERVE_DEPLOY,       _R( 762, 373, 798, 404), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		

		oapiRegisterPanelArea (AID_FUSE_EMER_RESERVE_DEPLOY,  _R( 579, 524, 615, 555), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_EMER_LAND_BAG,        _R( 626, 524, 662, 555), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_EMER_RESCUE_AIDS,     _R( 673, 524, 709, 555), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_PERISCOPE,            _R( 720, 524, 756, 555), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);

		oapiRegisterPanelArea (AID_FUSE_ANT_SWITCH,           _R( 579, 686, 615, 717), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_COMV_RCVRA,           _R( 626, 686, 662, 717), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_TRIM_HIFREQ,          _R( 673, 686, 709, 717), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		
		srf[25] = oapiCreateSurface (LOADBMP (IDB_FUSESWITCHSTRIP));
		srf[26] = oapiCreateSurface (LOADBMP (IDB_FUSESWITCHWHITE));
		
		break;
	case 4:
		PeriscopePanel = false;
		CameraPanel    = false;
		hBmp = LoadBitmap (g_Param.hDLL, MAKEINTRESOURCE (IDB_RIGHTPANEL));
		oapiRegisterPanelBackground (hBmp, PANEL_ATTACH_TOP|PANEL_ATTACH_BOTTOM|PANEL_ATTACH_LEFT|PANEL_ATTACH_RIGHT, 0xff00ff);
		oapiSetPanelNeighbours (0,-1,-1,-1);
		vessel->SetCameraDefaultDirection(_V(0,0,1));
		vessel->SetCameraRotationRange(.8*PI,.8*PI,.4*PI,.4*PI);
		vessel->SetCameraOffset(_V(0,.75,-.75));


		adi->ScrX =  59;
		adi->ScrY = 543;
		adi->RegisterMe(AID_GLOBEPANEL);
		oapiRegisterPanelArea (AID_GAUGE_ROLL,           _R(   5,  58,  73, 126) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_GAUGE_YAW,            _R(  75, 106, 143, 174), PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_GAUGE_PITCH,          _R( 143,  56, 211, 126) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_GAUGE_RATE,           _R(  87,  59, 130, 102) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);

		oapiRegisterPanelArea (AID_RETROGRADE_TIMER,     _R(  9,  244, 249, 503), PANEL_REDRAW_ALWAYS, PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_PUSH_TIMEZERO,        _R(249,  141, 280, 172), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN + PANEL_MOUSE_UP, PANEL_MAP_BACKGROUND);
		
		oapiRegisterPanelArea (AID_GAUGE_CABIN_PRESS,    _R( 308,  95, 400, 187) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_GAUGE_CABIN_TEMP,     _R( 401,  95, 491, 187) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_GAUGE_STEAM_TEMP,     _R( 401, 195, 491, 287) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_GAUGE_SUIT,           _R( 493, 195, 584, 287) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_GAUGE_OXYGEN,         _R( 401, 302, 491, 393) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_SUIT_FAN,      _R( 521, 311, 554, 334), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_CABIN_FAN,     _R( 521, 366, 554, 389), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);

		//47,81
		oapiRegisterPanelArea (AID_GAUGE_DC_VOLTS,       _R( 308, 401, 399, 493) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_KNOB_DC_VOLTS,        _R( 321, 495, 386, 560), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_GAUGE_DC_AMPS,        _R( 401, 401, 492, 493) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_GAUGE_AC_VOLTS,       _R( 401, 524, 492, 616) , PANEL_REDRAW_ALWAYS, PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_KNOB_AC_VOLTS,        _R( 414, 618, 479, 683), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_INLET_VALVE,   _R( 336, 585, 369, 608), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_AUDIO_BUS,     _R( 338, 637, 371, 660), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_AC_BUS,        _R( 522, 412, 555, 435), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_AMMETER,       _R( 521, 461, 554, 484), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_STBY_BTRY,     _R( 521, 514, 554, 537), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_ISOL_BTRY,     _R( 520, 555, 553, 578), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_WARN_STBY_AC_AUTO,    _R( 509, 588, 565, 623), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_FANS_AC_BUS,   _R( 522, 643, 555, 666), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);

		oapiRegisterPanelArea (AID_PUSH_KEY,             _R( 314, 714, 345, 745), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN + PANEL_MOUSE_UP, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_COMM_SELECT,   _R( 498, 718, 531, 741), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_UHF_SELECT,    _R( 563, 720, 596, 743), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_TRANSMIT,      _R( 628, 720, 661, 743), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_COMM_BEACON,   _R( 695, 720, 728, 743), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_VOX,           _R( 672, 655, 705, 678), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);


		oapiRegisterPanelArea (AID_SWITCH_WARN_LIGHTS,     _R( 626, 189, 659, 212), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_WARN_CABIN_PRESS,       _R( 592, 249, 648, 284), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_WARN_O2_EMER,           _R( 592, 327, 648, 362), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_WARN_SUIT_H20,          _R( 592, 366, 648, 401), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_WARN_CABIN_H20,         _R( 592, 404, 648, 439), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_WARN_FUEL_QUAN,         _R( 592, 442, 648, 477), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_WARN_RETRO_WARN,        _R( 592, 480, 648, 515), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_WARN_RETRO_RESET,       _R( 592, 518, 648, 553), PANEL_REDRAW_USER  , PANEL_MOUSE_IGNORE, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_CABIN_PRESS,     _R( 683, 254, 716, 277), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_O2_EMER,         _R( 683, 332, 716, 355), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_SUIT_H20,        _R( 683, 371, 716, 394), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_CABIN_H20,       _R( 683, 409, 716, 432), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_FUEL_QUAN,       _R( 683, 447, 716, 470), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_RETRO_WARN ,     _R( 683, 485, 716, 508), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_SWITCH_RETRO_RESET,     _R( 683, 523, 716, 546), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_PUSH_BLOOD_PRESS_START, _R( 611, 583, 642, 614), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN + PANEL_MOUSE_UP, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_PUSH_BLOOD_PRESS_STOP,  _R( 689, 583, 720, 614), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN + PANEL_MOUSE_UP, PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_SUIT_FAN,          _R( 766, 420, 802, 450), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_INVR_CONTROL,      _R( 816, 420, 852, 451), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_RETRO_JETT,        _R( 766, 545, 802, 576), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_RETRO_MAN,         _R( 816, 545, 852, 576), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_PROGRAMMER,        _R( 766, 664, 802, 695), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);
		oapiRegisterPanelArea (AID_FUSE_BLOOD_PRESS,       _R( 816, 664, 852, 695), PANEL_REDRAW_MOUSE , PANEL_MOUSE_DOWN  , PANEL_MAP_BACKGROUND);



		srf[0]  = oapiCreateSurface (LOADBMP (IDB_RIGHTPANEL));
		srf[1]  = oapiCreateSurface (LOADBMP (IDB_SEQSWITCH));
		srf[2]  = oapiCreateSurface (LOADBMP (IDB_EARTHGLOBE));
		srf[3]  = oapiCreateSurface (LOADBMP (IDB_ABORT));
		srf[4]  = oapiCreateSurface (LOADBMP (IDB_SEQLIGHT));
		srf[5]  = oapiCreateSurface (LOADBMP (IDB_RINGSWITCH));
		srf[6]  = oapiCreateSurface (LOADBMP (IDB_FLIGHTSWITCH));
		srf[7]  = oapiCreateSurface (LOADBMP (IDB_PULLHANDLE));
		srf[8]  = oapiCreateSurface (LOADBMP (IDB_PUSHBUTTON));
		srf[9]  = oapiCreateSurface (LOADBMP (IDB_RDGLOBEPANEL));
		srf[10] = oapiCreateSurface (LOADBMP (IDB_RETROGRADEPANEL));
		srf[11] = oapiCreateSurface (LOADBMP (IDB_RETROHANDLEINCMIN));
		srf[12] = oapiCreateSurface (LOADBMP (IDB_RETROHANDLEINCSEC));
		srf[13] = oapiCreateSurface (LOADBMP (IDB_RETROHANDLEOFF));
		srf[14] = oapiCreateSurface (LOADBMP (IDB_RETROHANDLEDECSEC));
		srf[15] = oapiCreateSurface (LOADBMP (IDB_RETROHANDLEDECMIN));
		srf[16] = oapiCreateSurface (LOADBMP (IDB_RETRONUMBERS));
		srf[17] = oapiCreateSurface (LOADBMP (IDB_RETROWARN));
		srf[18] = oapiCreateSurface (LOADBMP (IDB_PUSHBUTTON_FLIGHT));
		srf[19] = oapiCreateSurface (LOADBMP (IDB_RETRONUMBERS));
		srf[20] = oapiCreateSurface (LOADBMP (IDB_DECOMP_HANDLE));
		srf[21] = oapiCreateSurface (LOADBMP (IDB_REPRESS_HANDLE));
		srf[22] = oapiCreateSurface (LOADBMP (IDB_ALT_KNOB));
		srf[23] = oapiCreateSurface (LOADBMP (IDB_KNOBAC));
		srf[24] = oapiCreateSurface (LOADBMP (IDB_KNOBDC));
		srf[25] = oapiCreateSurface (LOADBMP (IDB_FUSESWITCHSTRIP));
		srf[26] = oapiCreateSurface (LOADBMP (IDB_FUSESWITCHWHITE));
		srf[27] = oapiCreateSurface (LOADBMP (IDB_WARNLIGHTS));
		break;
	case 5:
		PeriscopePanel = false;
		CameraPanel    = true;
		hBmp = LoadBitmap (g_Param.hDLL, MAKEINTRESOURCE (IDB_CAMERAPANEL));
		oapiRegisterPanelBackground (hBmp, PANEL_ATTACH_TOP|PANEL_ATTACH_BOTTOM|PANEL_ATTACH_LEFT|PANEL_ATTACH_RIGHT, 0xffffff);
		oapiSetPanelNeighbours (-1,-1,2,-1);
		oapiCameraAttach(vessel->GetHandle(),0);
		oapiCameraSetAperture(RAD*(30/2));
		vessel->SetCameraRotationRange(0.0,0.0,0.0,0.0);	
		vessel->SetCameraDefaultDirection(_V(sin(73.0*RAD),0,cos(73.0*RAD)));
		oapiCameraSetCockpitDir(0,0);
		vessel->SetCameraOffset(_V(0,.75 * sin(-75.5*RAD),.75 * cos(-75.5*RAD)));
		break;
	}
	return hBmp != NULL;
}

bool Mercury_ControlPanel::PanelRedrawEvent (VESSEL *vessel, int id, int event, SURFHANDLE surf)
{
HDC hDC =0;
double TempD = 0.0;
double sValue = 0.0;
double pValue = 0.0;

switch (id) {
	// panel 0 events:
	case AID_SWITCH_LANDINGBAG:
		if (switch_landingbag == LB_AUTO)
			Redraw_SeqSwitch(SWITCH_LEFT, surf);
		else if (switch_landingbag == LB_OFF)
			Redraw_SeqSwitch(SWITCH_MIDDLE, surf);
		else if (switch_landingbag == LB_MAN)
			Redraw_SeqSwitch(SWITCH_RIGHT, surf);
		return true;
	case AID_AUTOPILOT:
		oapiCameraAttach(vessel->GetHandle(),0);
		oapiCameraSetAperture(RAD*(60/2));
		if (switch_autopilot)
			Redraw_SeqSwitch(SWITCH_LEFT, surf);
		else
			Redraw_SeqSwitch(SWITCH_RIGHT, surf);
		return true;
	case AID_GLOBEPANEL:
		adi->PaintMe(vessel,surf, srf[9]);
		return true;
	case AID_GAUGE_ROLL:
		RedrawPanel_Roll(vessel, surf);
		return true;
	case AID_GAUGE_YAW:
		RedrawPanel_Yaw(vessel, surf);
		return true;
	case AID_GAUGE_PITCH:
		RedrawPanel_Pitch(vessel, surf);
		return true;
	case AID_GAUGE_RATE:
		RedrawPanel_Rate(vessel, surf);
		return true;
	case AID_GAUGE_FUEL:
		RedrawPanel_Fuel(vessel, surf);
		return true;
	case AID_GAUGE_ALT:
		return RedrawPanel_Alt(vessel, surf);
	case AID_ABORT:
		if (ind_aborted)
			oapiBlt (surf, srf[3], 0, 0, 58, 0, 57, 64, 0xFFFFFF);
		else
			oapiBlt (surf, srf[3], 0, 0, 0, 0, 57, 64, 0xFFFFFF);
		return true;
	case AID_SEQ_ABORTJETT:
		Redraw_SequenceLight (ind_status[IND_ABORTJETTISONED], "JETT TOWER", surf);
		return true;
	case AID_SEQ_CAPSULESEP:
		Redraw_SequenceLight (ind_status[IND_CAPSULESEP], "CAPSULE SEP", surf);
		return true;
	case AID_SWITCH_ABORTJETT:
		Redraw_RingSwitch(switch_jettisonabort, surf);
		return true;
	case AID_SWITCH_CAPSULESEP:
		Redraw_RingSwitch(switch_capsulesep, surf);
		return true;
	case AID_SWITCH_AUTOMATICMODE:
		if (switch_automaticmode == AUTO_ASCS)
			Redraw_FlightSwitch(SWITCH_LEFT, surf);
		else if (switch_automaticmode == AUTO_AUXDAMP)
			Redraw_FlightSwitch(SWITCH_MIDDLE, surf);
		else if (switch_automaticmode == AUTO_FBW)
			Redraw_FlightSwitch(SWITCH_RIGHT, surf);
		return true;
	case AID_SWITCH_GYRO:
		if (switch_gyro == GYRO_NORM)
			Redraw_FlightSwitch(SWITCH_LEFT, surf);
		else if (switch_gyro == GYRO_FREE)
			Redraw_FlightSwitch(SWITCH_MIDDLE, surf);
		else if (switch_gyro == GYRO_CAGED)
			Redraw_FlightSwitch(SWITCH_RIGHT, surf);
		return true;
	case AID_PULL_MANUAL_MODE:
		if (pull_manualmode == MANUAL_RATECMD)
			oapiBlt (surf, srf[7], 0, 0, 1, 1, 56, 88,0xFFFFFF);
		else if (pull_manualmode == MANUAL_DIRECT)
			oapiBlt (surf, srf[7], 0, 0, 58, 1, 56, 88,0xFFFFFF);
		return true;
	case AID_PULL_AUTO_ROLL_MODE:
		if (pull_autorollmode == AUTO_ON)
			oapiBlt (surf, srf[7], 0, 0, 229, 1, 56, 88,0xFFFFFF);
		else if (pull_autorollmode == AUTO_OFF)
			oapiBlt (surf, srf[7], 0, 0, 286, 1, 56, 88,0xFFFFFF);
		return true;
	case AID_PULL_AUTO_YAW_MODE:
		if (pull_autoyawmode == AUTO_ON)
			oapiBlt (surf, srf[7], 0, 0, 115, 1, 56, 88,0xFFFFFF);
		else if (pull_autoyawmode == AUTO_OFF)
			oapiBlt (surf, srf[7], 0, 0, 172, 1, 56, 88,0xFFFFFF);
		return true;
	case AID_PULL_AUTO_PITCH_MODE:
		if (pull_autopitchmode == AUTO_ON)
			oapiBlt (surf, srf[7], 0, 0, 343, 1, 56, 88,0xFFFFFF);
		else if (pull_autopitchmode == AUTO_OFF)
			oapiBlt (surf, srf[7], 0, 0, 400, 1, 56, 88,0xFFFFFF);
		return true;
	case AID_SWITCH_SQUIB:
		if (switch_squib)
			Redraw_FlightSwitch(SWITCH_LEFT, surf);
		else
			Redraw_FlightSwitch(SWITCH_RIGHT, surf);
		return true;
	case AID_SWITCH_RETROAUTOJETT:
		if (switch_retroautojett)
			Redraw_FlightSwitch(SWITCH_LEFT, surf);
		else
			Redraw_FlightSwitch(SWITCH_RIGHT, surf);
		return true;
	case AID_SWITCH_RETRODELAY:
		if (switch_retrodelay == RETRO_NORM)
			Redraw_FlightSwitch(SWITCH_LEFT, surf);
		else
			Redraw_FlightSwitch(SWITCH_RIGHT, surf);
		return true;
	case AID_SWITCH_RETROATTITUDE:
		if (switch_retroattitude == RETROATT_AUTO)
			Redraw_SeqSwitch(SWITCH_LEFT, surf);
		else
			Redraw_SeqSwitch(SWITCH_RIGHT, surf);
		return true;
	case AID_PUSH_RETROSEQUENCE:
		Redraw_SeqPush(push_retrosequence, surf);
		return true;
	case AID_PUSH_RETROFIRE:
		Redraw_SeqPush(push_retrofire, surf);
		return true;
	case AID_PUSH_RETROJETT:
		Redraw_SeqPush(push_retrojett, surf);
		return true;
	case FC_GAUGE_ROLL:
		//RedrawPanel_FCRoll(vessel, surf);
		return true;
	case FC_GAUGE_YAW:
		//RedrawPanel_FCYaw(vessel, surf);
		return true;
	case FC_GAUGE_PITCH:
		//RedrawPanel_FCPitch(vessel, surf);
		return true;
	case FC_GAUGE_RATE:
		RedrawPanel_FCRate(vessel, surf);
		return true;
	case FC_GAUGE_FUEL:
		//RedrawPanel_FCFuel(vessel, surf);
		return true;
	case AID_SEQ_RETROSEQUENCE:
		Redraw_SequenceLight (ind_status[IND_RETROSEQUENCE], "RETRO SEQ", surf);
		return true;
	case AID_SEQ_RETROATTITUDE:
		Redraw_SequenceLight (ind_status[IND_RETROATTITUDE], "RETRO ATT", surf);
		return true;
	case AID_SEQ_RETROFIRE:
		Redraw_SequenceLight (ind_status[IND_RETROFIRE], "FIRE RETRO", surf);
		return true;
	case AID_SEQ_RETROJETT:	
		Redraw_SequenceLight (ind_status[IND_RETROJETT], "JETT RETRO", surf);
		return true;
	case AID_PUSH_05G:
		Redraw_SeqPush(push_05G, surf);
		return true;
	case AID_PUSH_DROGUE:
		Redraw_SeqPush(push_drogue, surf);
		return true;
	case AID_SWITCH_SNORKEL:
		Redraw_RingSwitch(switch_snorkel, surf);
		return true;
	case AID_SWITCH_MAIN:
		Redraw_RingSwitch(switch_main, surf);
		return true;
	case AID_SWITCH_RESERVE:
		Redraw_RingSwitch(switch_reserve, surf);
		return true;
	case AID_SEQ_05G:
		Redraw_SequenceLight (ind_status[IND_05G], ".05 G", surf);
		return true;
	case AID_SEQ_MAIN:
		Redraw_SequenceLight (ind_status[IND_MAIN], "MAIN", surf);
		return true;
	case AID_SEQ_LANDINGBAG:
		Redraw_SequenceLight (ind_status[IND_LANDINGBAG], "LANDING BAG", surf);
		return true;
	case AID_SWITCH_RSCS:
		if (switch_rscs == RSCS_AUTO)
			Redraw_FlightSwitch(SWITCH_LEFT, surf);
		else
			Redraw_FlightSwitch(SWITCH_RIGHT, surf);
		return true;
	case AID_GAUGE_ACCEL:
		RedrawPanel_Accel(vessel, surf);
		return true;
	case AID_GAUGE_DESCENT:
		RedrawPanel_Descent(vessel, surf);
		return true;
	case AID_PUSH_TIMEZERO:
		Redraw_FlightPush(push_timezero, surf);
		return true;
	case AID_RETROGRADE_TIMER:
		RedrawPanel_RetrogradeTimer(vessel, surf);
		return true;
	case FC_TIMER:
		RedrawPanel_FCTimer(vessel, surf);
		return true;
	case AID_SEQ_RESCUE:
		Redraw_SequenceLight (ind_status[IND_RESCUE], "RESCUE", surf);
		return true;
	case AID_SWITCH_RESCUE:
		if (switch_rescue == RESCUE_AUTO)
			Redraw_FlightSwitch(SWITCH_LEFT, surf);
		else
			Redraw_FlightSwitch(SWITCH_RIGHT, surf);
		return true;
	case AID_SWITCH_PHOTO_LIGHTS:
		if (switch_photo_lights)
			Redraw_FlightSwitch(SWITCH_LEFT, surf);
		else
			Redraw_FlightSwitch(SWITCH_RIGHT, surf);
		return true;
	case AID_SWITCH_LIGHTS:
		if (switch_lights == LIGHTS_BOTH)
			Redraw_FlightSwitch(SWITCH_LEFT, surf);
		else if (switch_lights == LIGHTS_OFF)
			Redraw_FlightSwitch(SWITCH_MIDDLE, surf);
		else if (switch_lights == LIGHTS_ON)
			Redraw_FlightSwitch(SWITCH_RIGHT, surf);
		return true;
	case AID_SWITCH_TLM_FREQ:
		if (switch_tlm_freq)
			Redraw_FlightSwitch(SWITCH_LEFT, surf);
		else
			Redraw_FlightSwitch(SWITCH_RIGHT, surf);
		return true;
	case AID_SWITCH_LIGHT_TEST:
		int i;
		i = 0;
		
	
		if (switch_light_test == SEQ_GREEN) {
			Redraw_FlightSwitch(SWITCH_LEFT, surf);
		} else if (switch_light_test == SEQ_CLEAR) {
			Redraw_FlightSwitch(SWITCH_MIDDLE, surf);
		} else if (switch_light_test == SEQ_RED) {
			Redraw_FlightSwitch(SWITCH_RIGHT, surf);
		}
		oapiTriggerPanelRedrawArea (0, AID_SEQ_ABORTJETT);
		oapiTriggerPanelRedrawArea (0, AID_SEQ_CAPSULESEP);
		oapiTriggerPanelRedrawArea (0, AID_SEQ_RETROSEQUENCE);
		oapiTriggerPanelRedrawArea (0, AID_SEQ_RETROATTITUDE);
		oapiTriggerPanelRedrawArea (0, AID_SEQ_RETROFIRE);
		oapiTriggerPanelRedrawArea (0, AID_SEQ_RETROJETT);
		oapiTriggerPanelRedrawArea (0, AID_SEQ_05G);
		oapiTriggerPanelRedrawArea (0, AID_SEQ_MAIN);
		oapiTriggerPanelRedrawArea (0, AID_SEQ_LANDINGBAG);
		oapiTriggerPanelRedrawArea (0, AID_SEQ_RESCUE);
		oapiTriggerPanelRedrawArea (1, AID_SEQ_ABORTJETT);
		oapiTriggerPanelRedrawArea (1, AID_SEQ_CAPSULESEP);
		oapiTriggerPanelRedrawArea (4, AID_WARN_STBY_AC_AUTO);
		oapiTriggerPanelRedrawArea (4, AID_WARN_CABIN_PRESS);
		oapiTriggerPanelRedrawArea (4, AID_WARN_O2_EMER);
		oapiTriggerPanelRedrawArea (4, AID_WARN_SUIT_H20);
		oapiTriggerPanelRedrawArea (4, AID_WARN_CABIN_H20);
		oapiTriggerPanelRedrawArea (4, AID_WARN_FUEL_QUAN);
		oapiTriggerPanelRedrawArea (4, AID_WARN_RETRO_WARN);
		oapiTriggerPanelRedrawArea (4, AID_WARN_RETRO_RESET);
		return true;
	case  AID_SWITCH_MANEUVER:
		if (switch_maneuver)
			Redraw_FlightSwitch(SWITCH_RIGHT, surf);
		else
			Redraw_FlightSwitch(SWITCH_LEFT, surf);
		return true;
	case AID_HANDLE_DECOMP:
		if (pull_decomp == AUTO_ON)
			oapiBlt (surf, srf[20], 0, 0, 0, 0, 84, 109,0xFFFFFF);
		else if (pull_decomp == AUTO_OFF)
			oapiBlt (surf, srf[20], 0, 0, 84, 0, 84, 109,0xFFFFFF);
		return true;
	case AID_HANDLE_REPRESS:
		if (pull_repress == AUTO_ON)
			oapiBlt (surf, srf[21], 0, 0, 0, 0, 84, 109,0xFFFFFF);
		else if (pull_repress == AUTO_OFF)
			oapiBlt (surf, srf[21], 0, 0, 84, 0, 84, 109,0xFFFFFF);
		return true;
	case PERI_VIEW_SWITCH:
		if (view_switch == 0) {
			Redraw_FlightSwitch(SWITCH_LEFT, surf);			
		} else {
			Redraw_FlightSwitch(SWITCH_RIGHT, surf);
		}
		return true;
	case PERI_FILTER_SWITCH:
		if (switch_filter == SWITCH_LEFT) {
			Redraw_FlightSwitch(SWITCH_LEFT, surf);			
		} else {
			Redraw_FlightSwitch(SWITCH_RIGHT, surf);
		}
		return true;
	case PERI_ALT_KNOB:
		oapiBlt (surf, srf[22], 0, 0, alt_knob * 81, 0, 81, 77,0xFFFFFF);
		return true;
	case PERI_ALTITUDE:
		RedrawPanel_PeriscopeAltitude(vessel, surf);
		return true;
	case PERI_ALT_IND:
		hDC = oapiGetDC (surf);
		DrawLine(hDC, 362 + alt_indicator, 0, 362 + alt_indicator, 724, g_Param.pen[3]);
		DrawLine(hDC, 362 - alt_indicator, 0, 362 - alt_indicator, 724, g_Param.pen[3]);
		DrawLine(hDC, 0, 362 + alt_indicator, 724, 362 + alt_indicator, g_Param.pen[3]);
		DrawLine(hDC, 0, 362 - alt_indicator, 724, 362 - alt_indicator, g_Param.pen[3]);
		oapiReleaseDC (surf, hDC);
		//oapiBlt (surf, srf[21], 0, 0, 0, 0, 84, 109,0xFFFFFF);
		oapiBlt(surf, srf[0], 0, 0, 163, 15, 725, 725, 0xFFFFFF);
		//sprintf(oapiDebugString(), "Alt: %d", alt_indicator);
	
		return true;
	case AID_GAUGE_CABIN_PRESS:
		mTank *Capsule;
		Capsule = (mTank*) Systems->GetComponent("Capsule");
		TempD = 0.0;
		if (Capsule != 0) {
			TempD = Capsule->Space.GetPress();
			TempD /= (6.894758813 * 1000.0);
			if (TempD < 5.0) {
				this->CabinPressWarn(WARN_ON);
			} else {
				this->CabinPressWarn(WARN_OFF);
			}

			TempD = 75*RAD -((TempD / 15.0) * 225*RAD);
		}

		RedrawPanel_RoundGauge(vessel,surf, TempD);
		return true;
	case AID_GAUGE_CABIN_TEMP:
		RedrawPanel_RoundGauge(vessel,surf, -30*RAD);
		return true;
	case AID_GAUGE_STEAM_TEMP:
		RedrawPanel_DualGauge(vessel,surf, 60*RAD, -60*RAD);
		return true;
	case AID_GAUGE_SUIT:
		mTank *Suit;
		Suit = (mTank*) Systems->GetComponent("MercSuit");
		TempD = 0.0;
		if (Suit != 0) {
			TempD = Suit->Space.GetPress();
			TempD /= (6.894758813 * 1000.0);
			TempD = 60*RAD - ((TempD / 8.0) * 120*RAD + 5*RAD);
		}
		RedrawPanel_DualGauge(vessel,surf, 0, TempD);
		return true;
	case AID_GAUGE_OXYGEN:
		mTank *pOxy;
		mTank *sOxy;
		pOxy = (mTank*) Systems->GetComponent("PriOxyTank");
		sOxy = (mTank*) Systems->GetComponent("SecOxyTank");
		sValue = 0.0;
		pValue = 0.0;
		if (pOxy != 0 && sOxy != 0) {
			sValue = sOxy->Space.GetPress();
			sValue /= (6.894758813 * 1000.0);
			sValue = 60*RAD - ((sValue / 7500.0) * 120*RAD);

			pValue = pOxy->Space.GetPress();
			pValue /= (6.894758813 * 1000.0);
			//sprintf(oapiDebugString(), "press: %f %f %f", pValue, pOxy->Space.Composition[0].Mass, oapiGetSimStep());
			pValue = ((pValue / 7500.0) * 120*RAD) - 60*RAD;
		}
		RedrawPanel_DualGauge(vessel,surf, pValue, sValue);
		return true;
	case AID_SWITCH_SUIT_FAN:
		Redraw_FlightSwitch(SuitFanSwitch, surf);			
		return true;
	case AID_SWITCH_CABIN_FAN:
		Redraw_FlightSwitch(CabinFanSwitch, surf);			
		return true;
	case AID_GAUGE_DC_VOLTS:
	{
		double Value = 0.0;
		if (DCVoltsKnob == 0) {
			mBattery *mBtty = (mBattery*) Systems->GetComponent("Main1");
			Value = mBtty->Volt;
		} else if (DCVoltsKnob == 1) {
			mBattery *mBtty = (mBattery*) Systems->GetComponent("Main2");
			Value = mBtty->Volt;
		} else if (DCVoltsKnob == 2) {
			mBattery *mBtty = (mBattery*) Systems->GetComponent("Main3");
			Value = mBtty->Volt;
		} else if (DCVoltsKnob == 3) {
			mBattery *mBtty = (mBattery*) Systems->GetComponent("Stby1");
			Value = mBtty->Volt;
		} else if (DCVoltsKnob == 4) {
			mBattery *mBtty = (mBattery*) Systems->GetComponent("Stby2");
			Value = mBtty->Volt;
		} else if (DCVoltsKnob == 5) {
			mBattery *mBtty = (mBattery*) Systems->GetComponent("Iso1");
			Value = mBtty->Volt;
		} else if (DCVoltsKnob == 6) {
			Value = 0.0;
		} else if (DCVoltsKnob == 7) {
			mBus *mBus1 = (mBus*) Systems->GetComponent("DCMainBus");
			Value = mBus1->Volt;
		}
		if (Value > 30) Value = 30;
		if (Value < 0) Value = 0;
		double tempD;
		tempD = 45*RAD - ((Value / 30) * (90*RAD));
		RedrawPanel_BottomGauge(vessel,surf, tempD);
		return true;
	}
	case AID_KNOB_DC_VOLTS:
		Redraw_GaugeKnob(DCVoltsKnob, srf[24], surf);
		return true;
	case AID_GAUGE_DC_AMPS:
	{
		double Value = 0.0;
		double tempD;
		if (AmmeterSwitch== SWITCH_RIGHT) {
			if (DCVoltsKnob == 0) {
				mBattery *mBtty = (mBattery*) Systems->GetComponent("Main1");
				Value = mBtty->power_load;
			} else if (DCVoltsKnob == 1) {
				mBattery *mBtty = (mBattery*) Systems->GetComponent("Main2");
				Value = mBtty->power_load;
			} else if (DCVoltsKnob == 2) {
				mBattery *mBtty = (mBattery*) Systems->GetComponent("Main3");
				Value = mBtty->power_load;
			} else if (DCVoltsKnob == 3) {
				mBattery *mBtty = (mBattery*) Systems->GetComponent("Stby1");
				Value = mBtty->power_load;
			} else if (DCVoltsKnob == 4) {
				mBattery *mBtty = (mBattery*) Systems->GetComponent("Stby2");
				Value = mBtty->power_load;
			} else if (DCVoltsKnob == 5) {
				mBattery *mBtty = (mBattery*) Systems->GetComponent("Iso1");
				Value = mBtty->power_load;
			} else if (DCVoltsKnob == 6) {
				Value = 0.0;
			} else if (DCVoltsKnob == 7) {
				mBus *mBus1 = (mBus*) Systems->GetComponent("DCMainBus");
				Value = mBus1->power_load;
			}
			if (Value > 45) Value = 45;
			if (Value < 0) Value = 0;
			Value = Value / oapiGetSimStep();
			tempD = 45*RAD - ((Value / 45) * (90*RAD));
		} else {
			tempD = 45*RAD;
		}
		RedrawPanel_BottomGauge(vessel,surf, tempD);
		return true;
	}
	case AID_GAUGE_AC_VOLTS:
	{
		if (DCVoltsKnob == 0) {
		} else if (DCVoltsKnob == 1) {
		} else if (DCVoltsKnob == 2) {
		} else if (DCVoltsKnob == 3) {
		} else if (DCVoltsKnob == 4) {
		} else if (DCVoltsKnob == 5) {
		} else if (DCVoltsKnob == 6) {
		} else if (DCVoltsKnob == 7) {
		}
		RedrawPanel_BottomGauge(vessel,surf, -45*RAD);
		return true;
	}
	case AID_KNOB_AC_VOLTS:
		Redraw_GaugeKnob(ACVoltsKnob, srf[23], surf);
		return true;
	case AID_SWITCH_INLET_VALVE:
		Redraw_FlightSwitch(InletValveSwitch, surf);			
		return true;
	case AID_SWITCH_AUDIO_BUS:
		Redraw_FlightSwitch(AudioBusSwitch, surf);			
		return true;
	case AID_SWITCH_AC_BUS:
		Redraw_FlightSwitch(ACBusSwitch, surf);			
		return true;
	case AID_SWITCH_AMMETER:
		Redraw_FlightSwitch(AmmeterSwitch, surf);			
		return true;
	case AID_SWITCH_STBY_BTRY:
		Redraw_FlightSwitch(StbyBtrySwitch, surf);			
		return true;
	case AID_SWITCH_ISOL_BTRY:
		Redraw_FlightSwitch(IsolBtrySwitch, surf);			
		return true;
	case AID_WARN_STBY_AC_AUTO:
		Redraw_WarningLight(warn_status[WARN_STBYACAUTO], "STBY", "AC AUTO", surf);
		return true;
	case AID_SWITCH_FANS_AC_BUS:
		Redraw_FlightSwitch(FansACBusSwitch, surf);			
		return true;
	case AID_PUSH_KEY:
		Redraw_SeqPush(PushCommKey, surf);
		return true;
	case AID_SWITCH_COMM_SELECT:
		Redraw_FlightSwitch(CommSelectSwitch, surf);			
		return true;
	case AID_SWITCH_UHF_SELECT:
		Redraw_FlightSwitch(UHFSelectSwitch, surf);			
		return true;
	case AID_SWITCH_TRANSMIT:
		Redraw_FlightSwitch(TransmitSwitch, surf);			
		return true;
	case AID_SWITCH_COMM_BEACON:
		Redraw_FlightSwitch(CommBeaconSwitch, surf);			
		return true;
	case AID_SWITCH_VOX:
		Redraw_FlightSwitch(VOXSwitch, surf);			
		return true;
	case AID_SWITCH_WARN_LIGHTS:
		Redraw_FlightSwitch(WarnLightSwitch, surf);			
		return true;
	case AID_WARN_CABIN_PRESS:
		Redraw_WarningLight(warn_status[WARN_CABIN_PRESS], "CABIN", "PRESS", surf);
		return true;
	case AID_WARN_O2_EMER:
		Redraw_WarningLight(warn_status[WARN_O2_EMER], "O2 EMER", surf);
		return true;
	case AID_WARN_SUIT_H20:
		Redraw_WarningLight(warn_status[WARN_SUIT_H20], "EXCESS", "SUIT H20", surf);
		return true;
	case AID_WARN_CABIN_H20:
		Redraw_WarningLight(warn_status[WARN_CABIN_H20], "EXCESS", "CABIN H20", surf);
		return true;
	case AID_WARN_FUEL_QUAN:
		Redraw_WarningLight(warn_status[WARN_FUEL_QUAN], "FUEL QUAN", surf);
		return true;
	case AID_WARN_RETRO_WARN:
		Redraw_WarningLight(warn_status[WARN_RETRO_WARN], "RETRO", "WARN", surf);
		return true;
	case AID_WARN_RETRO_RESET:
		Redraw_WarningLight(warn_status[WARN_RETRO_RESET], "RETRO", "RESET", surf);
		return true;
	case AID_SWITCH_CABIN_PRESS:
		Redraw_FlightSwitch(CabinPressWarnSwitch, surf);			
		return true;
	case AID_SWITCH_O2_EMER:
		Redraw_FlightSwitch(O2EmerWarnSwitch, surf);			
		return true;
	case AID_SWITCH_SUIT_H20:
		Redraw_FlightSwitch(SuitH2OWarnSwitch, surf);			
		return true;
	case AID_SWITCH_CABIN_H20:
		Redraw_FlightSwitch(CabinH2OWarnSwitch, surf);			
		return true;
	case AID_SWITCH_FUEL_QUAN:
		Redraw_FlightSwitch(FuelQuanWarnSwitch, surf);			
		return true;
	case AID_SWITCH_RETRO_WARN:
		Redraw_FlightSwitch(RetroWarnSwitch, surf);			
		return true;
	case AID_SWITCH_RETRO_RESET:
		Redraw_FlightSwitch(RetroResetWarnSwitch, surf);			
		return true;
	case AID_PUSH_BLOOD_PRESS_START:
		Redraw_SeqPush(BloodPressStartPush, surf);
		return true;
	case AID_PUSH_BLOOD_PRESS_STOP:
		Redraw_SeqPush(BloodPressStopPush, surf);
		return true;
	case AID_FUSE_SUIT_FAN:
		RedrawPanel_DrawFuse(surf, SuitFanFuse);
		return true;
	case AID_FUSE_INVR_CONTROL:
		RedrawPanel_DrawFuse(surf, InvrControlFuse);
		return true;
	case AID_FUSE_RETRO_JETT:
		RedrawPanel_DrawFuse(surf, RetroJettFuse);
		return true;
	case AID_FUSE_RETRO_MAN:
		RedrawPanel_DrawFuse(surf, RetroManFuse);
		return true;
	case AID_FUSE_PROGRAMMER:
		RedrawPanel_DrawFuse(surf, ProgrammerFuse);
		return true;
	case AID_FUSE_BLOOD_PRESS:
		RedrawPanel_DrawFuse(surf, BloodPressFuse);
		return true;
	case AID_FUSE_PHASE_SHIFTER:
		RedrawPanel_DrawFuse(surf, PhaseShifterFuse);
		return true;
	case AID_FUSE_EMER_CAP_SEP:
		RedrawPanel_DrawFuse(surf, EmerCapSepFuse);
		return true;
	case AID_FUSE_EMER_ESCAPE_RCKT:
		RedrawPanel_DrawFuse(surf, EscapeRcktFuse);
		return true;
	case AID_FUSE_TOWER_SEP_CONTRL:
		RedrawPanel_DrawFuse(surf, TowerSepContrlFuse);
		return true;
	case AID_FUSE_EMER_TOWER_SEP:
		RedrawPanel_DrawFuse(surf, EmerTowerSepFuse);
		return true;
	case AID_FUSE_EMER_TOWER_JETT:
		RedrawPanel_DrawFuse(surf, EmerTowerJettFuse);
		return true;
	case AID_FUSE_EMER_POSGRD:
		RedrawPanel_DrawFuse(surf, EmerPosgrdFuse);
		return true;
	case AID_FUSE_AUX_BCN:
		RedrawPanel_DrawFuse(surf, AuxBcnFuse);
		return true;
	case AID_FUSE_RETRO_ONE:
		RedrawPanel_DrawFuse(surf, RetroOneFuse);
		return true;
	case AID_FUSE_RETRO_TWO:
		RedrawPanel_DrawFuse(surf, RetroTwoFuse);
		return true;
	case AID_FUSE_RETRO_THREE:
		RedrawPanel_DrawFuse(surf, RetroThreeFuse);
		return true;
	case AID_FUSE_EMER_RETRO_SEQ:
		RedrawPanel_DrawStripedFuse(surf, EmerRetroSeqFuse);
		return true;
	case AID_FUSE_EMER_RETRO_JETT:
		RedrawPanel_DrawFuse(surf, EmerRetroJettFuse);
		return true;
	case AID_FUSE_ASCS_05G:
		RedrawPanel_DrawFuse(surf, ASCS05GFuse);
		return true;
	case AID_FUSE_EMER_05G:
		RedrawPanel_DrawFuse(surf, Emer05GFuse);
		return true;
	case AID_FUSE_EMER_DROUGE_DEPLOY:
		RedrawPanel_DrawFuse(surf, EmerDrougeDeployFuse);
		return true;
	case AID_FUSE_EMER_MAIN_DEPLOY:
		RedrawPanel_DrawStripedFuse(surf, EmerMainDeployFuse);
		return true;
	case AID_FUSE_RESERVE_DEPLOY:
		RedrawPanel_DrawStripedFuse(surf, ReserveDeployFuse);
		return true;
	case AID_FUSE_EMER_RESERVE_DEPLOY:
		RedrawPanel_DrawStripedFuse(surf, EmerReserveDeployFuse);
		return true;
	case AID_FUSE_EMER_LAND_BAG:
		RedrawPanel_DrawFuse(surf, EmerLandBagFuse);
		return true;
	case AID_FUSE_EMER_RESCUE_AIDS:
		RedrawPanel_DrawFuse(surf, EmerRescueAidsFuse);
		return true;
	case AID_FUSE_PERISCOPE:
		RedrawPanel_DrawFuse(surf, PeriscopeFuse);
		return true;
	case AID_FUSE_ANT_SWITCH:
		RedrawPanel_DrawFuse(surf, AntSwitchFuse);
		return true;
	case AID_FUSE_COMV_RCVRA:
		RedrawPanel_DrawFuse(surf, ComVRcvrAFuse);
		return true;
	case AID_FUSE_TRIM_HIFREQ:
		RedrawPanel_DrawFuse(surf, TrimHiFreqFuse);
		return true;
	}
	return false;

}

void Mercury_ControlPanel::FuseMouseEvent(int &position, int event){
		if (event & PANEL_MOUSE_LBDOWN) 
		{
			position--;
			if (position < FUSE_ONE)
				position = FUSE_ONE;
		}

		if (event & PANEL_MOUSE_RBDOWN) 
		{
			position++;
			if (position > FUSE_TWO)
				position = FUSE_TWO;
		}
}
bool Mercury_ControlPanel::PanelMouseEvent (VESSEL *vessel, int id, int event, int mx, int my)
{
	switch (id) {
	case AID_AUTOPILOT:
		if (event & PANEL_MOUSE_LBDOWN) 
			switch_autopilot = true;
		if (event & PANEL_MOUSE_RBDOWN) 
			switch_autopilot = false;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_ABORTJETT:
		if (event & PANEL_MOUSE_LBDOWN) 
			if (!switch_jettisonabort)
				switch_jettisonabort = true;
		//PlayVesselWave(SOUND_RINGPULL);
		return true;
	case AID_SWITCH_CAPSULESEP:
		if (event & PANEL_MOUSE_LBDOWN) 
			if (!switch_capsulesep)
				switch_capsulesep = true;
		//PlayVesselWave(SOUND_RINGPULL);
		return true;
	case AID_SWITCH_AUTOMATICMODE:
		if (event & PANEL_MOUSE_LBDOWN) 
		{
			if (switch_automaticmode == AUTO_FBW)
				switch_automaticmode = AUTO_AUXDAMP;
			else if (switch_automaticmode == AUTO_AUXDAMP)
				switch_automaticmode = AUTO_ASCS;
		}

		if (event & PANEL_MOUSE_RBDOWN) 
		{
			if (switch_automaticmode == AUTO_ASCS)
				switch_automaticmode = AUTO_AUXDAMP;
			else if (switch_automaticmode == AUTO_AUXDAMP)
				switch_automaticmode = AUTO_FBW;
		}
		//PlayVesselWave(SOUND_SWITCH);
		bDoThrusterChange = true;
		return true;
	case AID_SWITCH_GYRO:
		if (event & PANEL_MOUSE_LBDOWN) 
		{
			if (switch_gyro == GYRO_CAGED)
				switch_gyro = GYRO_FREE;
			else if (switch_gyro == GYRO_FREE)
				switch_gyro = GYRO_NORM;
		}

		if (event & PANEL_MOUSE_RBDOWN) 
		{
			if (switch_gyro == GYRO_NORM)
				switch_gyro = GYRO_FREE;
			else if (switch_gyro == GYRO_FREE)
				switch_gyro = GYRO_CAGED;
		}
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_PULL_MANUAL_MODE:
		if (event & PANEL_MOUSE_LBDOWN) 
			pull_manualmode = MANUAL_DIRECT;
		if (event & PANEL_MOUSE_RBDOWN) 
			pull_manualmode = MANUAL_RATECMD;
		bDoThrusterChange = true;
		//PlayVesselWave(SOUND_PULLPUSH);
		return true;
	case AID_PULL_AUTO_ROLL_MODE:
		if (event & PANEL_MOUSE_LBDOWN) 
			pull_autorollmode = AUTO_OFF;
		if (event & PANEL_MOUSE_RBDOWN) 
			pull_autorollmode = AUTO_ON;
		bDoThrusterChange = true;
		//PlayVesselWave(SOUND_PULLPUSH);
		return true;
	case AID_PULL_AUTO_YAW_MODE:
		if (event & PANEL_MOUSE_LBDOWN) 
			pull_autoyawmode = AUTO_OFF;
		if (event & PANEL_MOUSE_RBDOWN) 
			pull_autoyawmode = AUTO_ON;
		bDoThrusterChange = true;
		//PlayVesselWave(SOUND_PULLPUSH);
		return true;
	case AID_PULL_AUTO_PITCH_MODE:
		if (event & PANEL_MOUSE_LBDOWN) 
			pull_autopitchmode = AUTO_OFF;
		if (event & PANEL_MOUSE_RBDOWN) 
			pull_autopitchmode = AUTO_ON;
		bDoThrusterChange = true;
		//PlayVesselWave(SOUND_PULLPUSH);
		return true;
	case AID_SWITCH_SQUIB:
		if (event & PANEL_MOUSE_LBDOWN) 
			switch_squib = true;
		if (event & PANEL_MOUSE_RBDOWN) 
			switch_squib = false;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_RETROAUTOJETT:
		if (event & PANEL_MOUSE_LBDOWN) 
			switch_retroautojett = true;
		if (event & PANEL_MOUSE_RBDOWN) 
			switch_retroautojett = false;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_RETRODELAY:
		if (event & PANEL_MOUSE_LBDOWN) 
			switch_retrodelay = RETRO_NORM;
		if (event & PANEL_MOUSE_RBDOWN) 
			switch_retrodelay = RETRO_INST;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_RETROATTITUDE:
		if (event & PANEL_MOUSE_LBDOWN) 
			switch_retroattitude = RETROATT_AUTO;
		if (event & PANEL_MOUSE_RBDOWN) 
			switch_retroattitude = RETROATT_BYPASS;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_PUSH_RETROSEQUENCE:
		if (event & PANEL_MOUSE_LBDOWN) 
			if (push_retrosequence == PUSH_COVERED)
				push_retrosequence = PUSH_UP;
			else
				push_retrosequence = PUSH_DOWN;
		if (event & PANEL_MOUSE_LBUP)
			push_retrosequence = PUSH_UP;
		//PlayVesselWave(SOUND_PULLPUSH);
		return true;
	case AID_PUSH_RETROFIRE:
		if (event & PANEL_MOUSE_LBDOWN) 
			if (push_retrofire == PUSH_COVERED)
				push_retrofire = PUSH_UP;
			else
				push_retrofire = PUSH_DOWN;
		if (event & PANEL_MOUSE_LBUP)
			push_retrofire = PUSH_UP;
		//PlayVesselWave(SOUND_PULLPUSH);
		return true;
	case AID_PUSH_RETROJETT:
		if (event & PANEL_MOUSE_LBDOWN) 
			if (push_retrojett == PUSH_COVERED)
				push_retrojett = PUSH_UP;
			else
				push_retrojett = PUSH_DOWN;
		if (event & PANEL_MOUSE_LBUP)
			push_retrojett = PUSH_UP;
		return true;
	case AID_PUSH_05G:
		if (event & PANEL_MOUSE_LBDOWN) 
			if (push_05G == PUSH_COVERED)
				push_05G = PUSH_UP;
			else
				push_05G = PUSH_DOWN;
		if (event & PANEL_MOUSE_LBUP)
			push_05G = PUSH_UP;
		//PlayVesselWave(SOUND_PULLPUSH);
		return true;
	case AID_PUSH_DROGUE:
		if (event & PANEL_MOUSE_LBDOWN) 
			if (push_drogue == PUSH_COVERED)
				push_drogue = PUSH_UP;
			else
				push_drogue = PUSH_DOWN;
		if (event & PANEL_MOUSE_LBUP)
			push_drogue = PUSH_UP;
		//PlayVesselWave(SOUND_PULLPUSH);
		return true;
	case AID_SWITCH_SNORKEL:
		if (event & PANEL_MOUSE_LBDOWN) 
			if (!switch_snorkel)
				switch_snorkel = true;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_MAIN:
		if (event & PANEL_MOUSE_LBDOWN) 
			if (!switch_main)
				switch_main = true;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_RESERVE:
		if (event & PANEL_MOUSE_LBDOWN) 
			if (!switch_reserve)
				switch_reserve = true;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_LANDINGBAG:
		if (event & PANEL_MOUSE_LBDOWN) 
		{
			if (switch_landingbag == LB_MAN)
				switch_landingbag = LB_OFF;
			else if (switch_landingbag == LB_OFF)
				switch_landingbag = LB_AUTO;
		}

		if (event & PANEL_MOUSE_RBDOWN) 
		{
			if (switch_landingbag == LB_AUTO)
				switch_landingbag = LB_OFF;
			else if (switch_landingbag == LB_OFF)
				switch_landingbag = LB_MAN;
		}
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_RSCS:
		if (event & PANEL_MOUSE_LBDOWN) 
			switch_rscs = RSCS_AUTO;
		if (event & PANEL_MOUSE_RBDOWN) 
			switch_rscs = RSCS_RATE;
		bDoThrusterChange = true;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_RETROGRADE_TIMER:
		if (event & PANEL_MOUSE_LBDOWN) {
			switch_rscs = RSCS_RATE;
			switch (lever_retro) {
			case RETRO_INC_MIN:
				retro_set_simt = oapiGetSimTime();
				lever_retro = RETRO_INC_SEC;
				break;
			case RETRO_INC_SEC:
				lever_retro = RETRO_OFF;
				break;
			case RETRO_OFF:
				retro_set_simt = oapiGetSimTime();
				lever_retro = RETRO_DEC_SEC;
				break;
			case RETRO_DEC_SEC:
				retro_set_simt = oapiGetSimTime();
				lever_retro = RETRO_DEC_MIN;
				break;
			case RETRO_DEC_MIN:
				break;
			}
		} else if (event & PANEL_MOUSE_RBDOWN) {
			switch_rscs = RSCS_RATE;
			switch (lever_retro) {
			case RETRO_INC_MIN:
				break;
			case RETRO_INC_SEC:
				retro_set_simt = oapiGetSimTime();
				lever_retro = RETRO_INC_MIN;
				break;
			case RETRO_OFF:
				retro_set_simt = oapiGetSimTime();
				lever_retro = RETRO_INC_SEC;
				break;
			case RETRO_DEC_SEC:
				lever_retro = RETRO_OFF;
				break;
			case RETRO_DEC_MIN:
				retro_set_simt = oapiGetSimTime();
				lever_retro = RETRO_DEC_SEC;
				break;
			}
		}
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_PUSH_TIMEZERO:
		if (event & PANEL_MOUSE_LBDOWN) 
			if (push_timezero == PUSH_COVERED)
				push_timezero = PUSH_UP;
			else
				push_timezero = PUSH_DOWN;
		if (event & PANEL_MOUSE_LBUP)
			push_timezero = PUSH_UP;
		//PlayVesselWave(SOUND_PULLPUSH);
		return true;
	case AID_SWITCH_RESCUE:
		if (event & PANEL_MOUSE_LBDOWN) {
			switch_rescue = RESCUE_AUTO;
		}
		if (event & PANEL_MOUSE_RBDOWN) {
			switch_rescue = RESCUE_MAN;
		}
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_PHOTO_LIGHTS:
		if (event & PANEL_MOUSE_LBDOWN) 
			switch_photo_lights = true;
		if (event & PANEL_MOUSE_RBDOWN) 
			switch_photo_lights = false;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_LIGHTS:
		if (event & PANEL_MOUSE_LBDOWN) 
		{
			if (switch_lights == LIGHTS_ON)
				switch_lights = LIGHTS_OFF;
			else if (switch_lights == LIGHTS_OFF)
				switch_lights = LIGHTS_BOTH;
		}

		if (event & PANEL_MOUSE_RBDOWN) 
		{
			if (switch_lights == LIGHTS_BOTH)
				switch_lights = LIGHTS_OFF;
			else if (switch_lights == LIGHTS_OFF)
				switch_lights = LIGHTS_ON;
		}
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_TLM_FREQ:
		if (event & PANEL_MOUSE_LBDOWN) 
			switch_tlm_freq = true;
		if (event & PANEL_MOUSE_RBDOWN) 
			switch_tlm_freq = false;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_LIGHT_TEST:
		if (event & PANEL_MOUSE_LBDOWN) 
		{
			if (switch_light_test == SEQ_RED)
				switch_light_test = SEQ_CLEAR;
			else if (switch_light_test == SEQ_CLEAR)
				switch_light_test = SEQ_GREEN;
		}

		if (event & PANEL_MOUSE_RBDOWN) 
		{
			if (switch_light_test == SEQ_GREEN)
				switch_light_test = SEQ_CLEAR;
			else if (switch_light_test == SEQ_CLEAR)
				switch_light_test = SEQ_RED;
		}
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case  AID_SWITCH_MANEUVER:
		if (event & PANEL_MOUSE_LBDOWN) 
			switch_maneuver = false;
		if (event & PANEL_MOUSE_RBDOWN) 
			switch_maneuver = true;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_HANDLE_DECOMP:
		if (event & PANEL_MOUSE_LBDOWN) {
			pull_decomp = AUTO_OFF;
			//StopVesselWave(SOUND_DECOMP);
		}
		if (event & PANEL_MOUSE_RBDOWN) {
			pull_decomp = AUTO_ON;
			//PlayVesselWave(SOUND_DECOMP);
		}
		//PlayVesselWave(SOUND_PULLPUSH);
		return true;
	case AID_HANDLE_REPRESS:
		if (event & PANEL_MOUSE_LBDOWN){ 
			pull_repress = AUTO_OFF;
			//StopVesselWave(SOUND_REPRESS);
		}
		if (event & PANEL_MOUSE_RBDOWN) {
			pull_repress = AUTO_ON;
			//PlayVesselWave(SOUND_REPRESS);
		}
		//PlayVesselWave(SOUND_PULLPUSH);
		return true;
	case PERI_VIEW_SWITCH:
		if (event & PANEL_MOUSE_LBDOWN) 
			view_switch = 0;
		if (event & PANEL_MOUSE_RBDOWN) 
			view_switch = 1;

		//oapiCameraAttach(vessel->GetHandle(),0);
		if (view_switch == 0) 
			oapiCameraSetAperture(RAD*(157/2));
		else
			oapiCameraSetAperture(RAD*(20/2));
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case PERI_FILTER_SWITCH:
		if (event & PANEL_MOUSE_LBDOWN) 
			switch_filter = SWITCH_LEFT;
		if (event & PANEL_MOUSE_RBDOWN) 
			switch_filter = SWITCH_RIGHT;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case PERI_ALT_KNOB:
		if (event & PANEL_MOUSE_LBDOWN) {
			alt_indicator +=1;
			if (alt_indicator > 362)
				alt_indicator = 362;
			if (alt_knob == 0) {
				alt_knob = 1;
			} else if (alt_knob == 1) {
				alt_knob = 2;
			} else if (alt_knob == 2) {
				alt_knob = 3;
			} else if (alt_knob == 3) {
				alt_knob = 0;
			}
		}
		if (event & PANEL_MOUSE_RBDOWN) {
			alt_indicator -=1;
			if (alt_indicator < 0)
				alt_indicator = 0;
			if (alt_knob == 0) {
				alt_knob = 3;
			} else if (alt_knob == 1) {
				alt_knob = 0;
			} else if (alt_knob == 2) {
				alt_knob = 1;
			} else if (alt_knob == 3) {
				alt_knob = 2;
			}
		}
		oapiTriggerPanelRedrawArea (2, PERI_ALT_IND);
		oapiTriggerPanelRedrawArea (2, PERI_ALTITUDE);
		return true;
	case AID_GAUGE_CABIN_PRESS:
		return true;
	case AID_GAUGE_CABIN_TEMP:
		return true;
	case AID_GAUGE_STEAM_TEMP:
		return true;
	case AID_GAUGE_SUIT:
		return true;
	case AID_GAUGE_OXYGEN:
		return true;
	case AID_SWITCH_SUIT_FAN:
		if (event & PANEL_MOUSE_LBDOWN) 
		{
			if (SuitFanSwitch == SWITCH_RIGHT)
				SuitFanSwitch = SWITCH_MIDDLE;
			else if (SuitFanSwitch == SWITCH_MIDDLE)
				SuitFanSwitch = SWITCH_LEFT;
		}

		if (event & PANEL_MOUSE_RBDOWN) 
		{
			if (SuitFanSwitch == SWITCH_LEFT)
				SuitFanSwitch = SWITCH_MIDDLE;
			else if (SuitFanSwitch == SWITCH_MIDDLE)
				SuitFanSwitch = SWITCH_RIGHT;
		}
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_CABIN_FAN:
		if (event & PANEL_MOUSE_LBDOWN) 
			CabinFanSwitch = SWITCH_LEFT;
		if (event & PANEL_MOUSE_RBDOWN) 
			CabinFanSwitch = SWITCH_RIGHT;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_GAUGE_DC_VOLTS:
		return true;
	case AID_KNOB_DC_VOLTS:
		if (event & PANEL_MOUSE_LBDOWN) {
			DCVoltsKnob++;
			if (DCVoltsKnob > 7)
				DCVoltsKnob = 0;
		}
		if (event & PANEL_MOUSE_RBDOWN) {
			DCVoltsKnob--;
			if (DCVoltsKnob < 0)
				DCVoltsKnob = 7;
		}
		return true;
	case AID_GAUGE_DC_AMPS:
		return true;
	case AID_GAUGE_AC_VOLTS:
		return true;
	case AID_KNOB_AC_VOLTS:
		if (event & PANEL_MOUSE_LBDOWN) {
			ACVoltsKnob++;
			if (ACVoltsKnob > 7)
				ACVoltsKnob = 0;
		}
		if (event & PANEL_MOUSE_RBDOWN) {
			ACVoltsKnob--;
			if (ACVoltsKnob < 0)
				ACVoltsKnob = 7;
		}
		return true;
	case AID_SWITCH_INLET_VALVE:
		if (event & PANEL_MOUSE_LBDOWN) 
			InletValveSwitch = SWITCH_LEFT;
		if (event & PANEL_MOUSE_RBDOWN) 
			InletValveSwitch = SWITCH_RIGHT;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_AUDIO_BUS:
		if (event & PANEL_MOUSE_LBDOWN) 
			AudioBusSwitch = SWITCH_LEFT;
		if (event & PANEL_MOUSE_RBDOWN) 
			AudioBusSwitch = SWITCH_RIGHT;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_AC_BUS:
		if (event & PANEL_MOUSE_LBDOWN) 
		{
			if (ACBusSwitch == SWITCH_RIGHT)
				ACBusSwitch = SWITCH_MIDDLE;
			else if (ACBusSwitch == SWITCH_MIDDLE)
				ACBusSwitch = SWITCH_LEFT;
		}

		if (event & PANEL_MOUSE_RBDOWN) 
		{
			if (ACBusSwitch == SWITCH_LEFT)
				ACBusSwitch = SWITCH_MIDDLE;
			else if (ACBusSwitch == SWITCH_MIDDLE)
				ACBusSwitch = SWITCH_RIGHT;
		}
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_AMMETER:
		if (event & PANEL_MOUSE_LBDOWN) 
		{
			if (AmmeterSwitch == SWITCH_RIGHT)
				AmmeterSwitch = SWITCH_MIDDLE;
			else if (AmmeterSwitch == SWITCH_MIDDLE)
				AmmeterSwitch = SWITCH_LEFT;
		}

		if (event & PANEL_MOUSE_RBDOWN) 
		{
			if (AmmeterSwitch == SWITCH_LEFT)
				AmmeterSwitch = SWITCH_MIDDLE;
			else if (AmmeterSwitch == SWITCH_MIDDLE)
				AmmeterSwitch = SWITCH_RIGHT;
		}
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_STBY_BTRY:
		if (event & PANEL_MOUSE_LBDOWN) 
			StbyBtrySwitch = SWITCH_LEFT;
		if (event & PANEL_MOUSE_RBDOWN) 
			StbyBtrySwitch = SWITCH_RIGHT;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_ISOL_BTRY:
		if (event & PANEL_MOUSE_LBDOWN) 
			IsolBtrySwitch = SWITCH_LEFT;
		if (event & PANEL_MOUSE_RBDOWN) 
			IsolBtrySwitch = SWITCH_RIGHT;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_WARN_STBY_AC_AUTO:
		return true;
	case AID_SWITCH_FANS_AC_BUS:
		if (event & PANEL_MOUSE_LBDOWN) 
		{
			if (FansACBusSwitch == SWITCH_RIGHT)
				FansACBusSwitch = SWITCH_MIDDLE;
			else if (FansACBusSwitch == SWITCH_MIDDLE)
				FansACBusSwitch = SWITCH_LEFT;
		}

		if (event & PANEL_MOUSE_RBDOWN) 
		{
			if (FansACBusSwitch == SWITCH_LEFT)
				FansACBusSwitch = SWITCH_MIDDLE;
			else if (FansACBusSwitch == SWITCH_MIDDLE)
				FansACBusSwitch = SWITCH_RIGHT;
		}
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_PUSH_KEY:
		if (event & PANEL_MOUSE_LBDOWN) 
			PushCommKey = PUSH_DOWN;
		if (event & PANEL_MOUSE_LBUP)
			PushCommKey = PUSH_UP;
		//PlayVesselWave(SOUND_PULLPUSH);
		return true;
	case AID_SWITCH_COMM_SELECT:
		if (event & PANEL_MOUSE_LBDOWN) 
			CommSelectSwitch = SWITCH_LEFT;
		if (event & PANEL_MOUSE_RBDOWN) 
			CommSelectSwitch = SWITCH_RIGHT;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
		/*if (event & PANEL_MOUSE_LBDOWN) 
		{
			if (CommSelectSwitch == SWITCH_RIGHT)
				CommSelectSwitch = SWITCH_MIDDLE;
			else if (CommSelectSwitch == SWITCH_MIDDLE)
				CommSelectSwitch = SWITCH_LEFT;
		}

		if (event & PANEL_MOUSE_RBDOWN) 
		{
			if (CommSelectSwitch == SWITCH_LEFT)
				CommSelectSwitch = SWITCH_MIDDLE;
			else if (CommSelectSwitch == SWITCH_MIDDLE)
				CommSelectSwitch = SWITCH_RIGHT;
		}
		return true;*/
	case AID_SWITCH_UHF_SELECT:
		if (event & PANEL_MOUSE_LBDOWN) 
			UHFSelectSwitch = SWITCH_LEFT;
		if (event & PANEL_MOUSE_RBDOWN) 
			UHFSelectSwitch = SWITCH_RIGHT;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_TRANSMIT:
		if (event & PANEL_MOUSE_LBDOWN) 
		{
			if (TransmitSwitch == SWITCH_RIGHT)
				TransmitSwitch = SWITCH_MIDDLE;
			else if (TransmitSwitch == SWITCH_MIDDLE)
				TransmitSwitch = SWITCH_LEFT;
		}

		if (event & PANEL_MOUSE_RBDOWN) 
		{
			if (TransmitSwitch == SWITCH_LEFT)
				TransmitSwitch = SWITCH_MIDDLE;
			else if (TransmitSwitch == SWITCH_MIDDLE)
				TransmitSwitch = SWITCH_RIGHT;
		}
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_COMM_BEACON:
		if (event & PANEL_MOUSE_LBDOWN) 
			CommBeaconSwitch = SWITCH_LEFT;
		if (event & PANEL_MOUSE_RBDOWN) 
			CommBeaconSwitch = SWITCH_RIGHT;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_VOX:
		if (event & PANEL_MOUSE_LBDOWN) 
		{
			if (VOXSwitch == SWITCH_RIGHT)
				VOXSwitch = SWITCH_MIDDLE;
			else if (VOXSwitch == SWITCH_MIDDLE)
				VOXSwitch = SWITCH_LEFT;
		}

		if (event & PANEL_MOUSE_RBDOWN) 
		{
			if (VOXSwitch == SWITCH_LEFT)
				VOXSwitch = SWITCH_MIDDLE;
			else if (VOXSwitch == SWITCH_MIDDLE)
				VOXSwitch = SWITCH_RIGHT;
		}
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_WARN_LIGHTS:
		if (event & PANEL_MOUSE_LBDOWN) 
			WarnLightSwitch = SWITCH_LEFT;
		if (event & PANEL_MOUSE_RBDOWN) 
			WarnLightSwitch = SWITCH_RIGHT;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_WARN_CABIN_PRESS:
		return true;
	case AID_WARN_O2_EMER:
		return true;
	case AID_WARN_SUIT_H20:
		return true;
	case AID_WARN_CABIN_H20:
		return true;
	case AID_WARN_FUEL_QUAN:
		return true;
	case AID_WARN_RETRO_WARN:
		return true;
	case AID_WARN_RETRO_RESET:
		return true;
	case AID_SWITCH_CABIN_PRESS:
		if (event & PANEL_MOUSE_LBDOWN) 
			CabinPressWarnSwitch = SWITCH_LEFT;
		if (event & PANEL_MOUSE_RBDOWN) 
			CabinPressWarnSwitch = SWITCH_RIGHT;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_O2_EMER:
		if (event & PANEL_MOUSE_LBDOWN) 
			O2EmerWarnSwitch = SWITCH_LEFT;
		if (event & PANEL_MOUSE_RBDOWN) 
			O2EmerWarnSwitch = SWITCH_RIGHT;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_SUIT_H20:
		if (event & PANEL_MOUSE_LBDOWN) 
			SuitH2OWarnSwitch = SWITCH_LEFT;
		if (event & PANEL_MOUSE_RBDOWN) 
			SuitH2OWarnSwitch = SWITCH_RIGHT;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_CABIN_H20:
		if (event & PANEL_MOUSE_LBDOWN) 
			CabinH2OWarnSwitch = SWITCH_LEFT;
		if (event & PANEL_MOUSE_RBDOWN) 
			CabinH2OWarnSwitch = SWITCH_RIGHT;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_FUEL_QUAN:
		if (event & PANEL_MOUSE_LBDOWN) 
			FuelQuanWarnSwitch = SWITCH_LEFT;
		if (event & PANEL_MOUSE_RBDOWN) 
			FuelQuanWarnSwitch = SWITCH_RIGHT;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_RETRO_WARN:
		if (event & PANEL_MOUSE_LBDOWN) 
			RetroWarnSwitch = SWITCH_LEFT;
		if (event & PANEL_MOUSE_RBDOWN) 
			RetroWarnSwitch = SWITCH_RIGHT;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_SWITCH_RETRO_RESET:
		if (event & PANEL_MOUSE_LBDOWN) 
			RetroResetWarnSwitch = SWITCH_LEFT;
		if (event & PANEL_MOUSE_RBDOWN) 
			RetroResetWarnSwitch = SWITCH_RIGHT;
		//PlayVesselWave(SOUND_SWITCH);
		return true;
	case AID_PUSH_BLOOD_PRESS_START:
		if (event & PANEL_MOUSE_LBDOWN) {
			//if(IsPlaying(SOUND_BLOODPRESS) == 0) {
				//PlayVesselWave(SOUND_BLOODPRESS);
			//}
			BloodPressStartPush = PUSH_DOWN;
		}
		if (event & PANEL_MOUSE_LBUP)
			BloodPressStartPush = PUSH_UP;
		//PlayVesselWave(SOUND_PULLPUSH);
		return true;
	case AID_PUSH_BLOOD_PRESS_STOP:
		if (event & PANEL_MOUSE_LBDOWN) 
			BloodPressStopPush = PUSH_DOWN;
		if (event & PANEL_MOUSE_LBUP)
			BloodPressStopPush = PUSH_UP;
		//PlayVesselWave(SOUND_PULLPUSH);
		return true;
	case AID_FUSE_SUIT_FAN:
		FuseMouseEvent(SuitFanFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_INVR_CONTROL:
		FuseMouseEvent(InvrControlFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_RETRO_JETT:
		FuseMouseEvent(RetroJettFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_RETRO_MAN:
		FuseMouseEvent(RetroManFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_PROGRAMMER:
		FuseMouseEvent(ProgrammerFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_BLOOD_PRESS:
		FuseMouseEvent(BloodPressFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_PHASE_SHIFTER:
		FuseMouseEvent(PhaseShifterFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_EMER_CAP_SEP:
		FuseMouseEvent(EmerCapSepFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_EMER_ESCAPE_RCKT:
		FuseMouseEvent(EscapeRcktFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_TOWER_SEP_CONTRL:
		FuseMouseEvent(TowerSepContrlFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_EMER_TOWER_SEP:
		FuseMouseEvent(EmerTowerSepFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_EMER_TOWER_JETT:
		FuseMouseEvent(EmerTowerJettFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_EMER_POSGRD:
		FuseMouseEvent(EmerPosgrdFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_AUX_BCN:
		FuseMouseEvent(AuxBcnFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_RETRO_ONE:
		FuseMouseEvent(RetroOneFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_RETRO_TWO:
		FuseMouseEvent(RetroTwoFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_RETRO_THREE:
		FuseMouseEvent(RetroThreeFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_EMER_RETRO_SEQ:
		FuseMouseEvent(EmerRetroSeqFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_EMER_RETRO_JETT:
		FuseMouseEvent(EmerRetroJettFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_ASCS_05G:
		FuseMouseEvent(ASCS05GFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_EMER_05G:
		FuseMouseEvent(Emer05GFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_EMER_DROUGE_DEPLOY:
		FuseMouseEvent(EmerDrougeDeployFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_EMER_MAIN_DEPLOY:
		FuseMouseEvent(EmerMainDeployFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_RESERVE_DEPLOY:
		FuseMouseEvent(ReserveDeployFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_EMER_RESERVE_DEPLOY:
		FuseMouseEvent(EmerReserveDeployFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_EMER_LAND_BAG:
		FuseMouseEvent(EmerLandBagFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_EMER_RESCUE_AIDS:
		FuseMouseEvent(EmerRescueAidsFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_PERISCOPE:
		FuseMouseEvent(PeriscopeFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_ANT_SWITCH:
		FuseMouseEvent(AntSwitchFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_COMV_RCVRA:
		FuseMouseEvent(ComVRcvrAFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	case AID_FUSE_TRIM_HIFREQ:
		FuseMouseEvent(TrimHiFreqFuse, event);
		//PlayVesselWave(SOUND_FUSECLICK);
		return true;
	}
	return false;
}

void Mercury_ControlPanel::ReleaseSurfaces ()
{
	for (int i = 0; i < nsurf; i++)
		if (srf[i]) {
			oapiDestroySurface (srf[i]);
			srf[i] = 0;
		}
}


void Mercury_ControlPanel::Aborted()
{
	ind_aborted = true;
	oapiTriggerPanelRedrawArea (0, AID_ABORT);
	oapiTriggerPanelRedrawArea (1, AID_ABORT);
}

void Mercury_ControlPanel::AbortJettisoned()
{
	ind_status[IND_ABORTJETTISONED] = SEQ_GREEN;
	oapiTriggerPanelRedrawArea (0, AID_SEQ_ABORTJETT);
	oapiTriggerPanelRedrawArea (1, AID_SEQ_ABORTJETT);
}

void Mercury_ControlPanel::AbortWarn()
{
	ind_status[IND_ABORTJETTISONED] = SEQ_RED;
	oapiTriggerPanelRedrawArea (0, AID_SEQ_ABORTJETT);
	oapiTriggerPanelRedrawArea (1, AID_SEQ_ABORTJETT);
}

void Mercury_ControlPanel::CapsuleSep()
{
	ind_status[IND_CAPSULESEP] = SEQ_GREEN;
	oapiTriggerPanelRedrawArea (0, AID_SEQ_CAPSULESEP);
	oapiTriggerPanelRedrawArea (1, AID_SEQ_CAPSULESEP);
}

void Mercury_ControlPanel::CapsuleWarn()
{
	ind_status[IND_CAPSULESEP] = SEQ_RED;
	oapiTriggerPanelRedrawArea (0, AID_SEQ_CAPSULESEP);
	oapiTriggerPanelRedrawArea (1, AID_SEQ_CAPSULESEP);
}

void Mercury_ControlPanel::RetroSequence()
{
	ind_status[IND_RETROSEQUENCE] = SEQ_GREEN;
	oapiTriggerPanelRedrawArea (0, AID_SEQ_RETROSEQUENCE);
}

void Mercury_ControlPanel::RetroAttitude(bool in_attitude)
{
	if (in_attitude)
		ind_status[IND_RETROATTITUDE] = SEQ_GREEN;
	else 
		ind_status[IND_RETROATTITUDE] = SEQ_RED;
	oapiTriggerPanelRedrawArea (0, AID_SEQ_RETROATTITUDE);
}


void Mercury_ControlPanel::RetroFire(int retro_abort)
{
	ind_status[IND_RETROFIRE] = retro_abort;
	oapiTriggerPanelRedrawArea (0, AID_SEQ_RETROFIRE);
}

void Mercury_ControlPanel::RetroJett(bool jett_abort)
{
	if (jett_abort)
		ind_status[IND_RETROJETT] = SEQ_RED;
	else
		ind_status[IND_RETROJETT] = SEQ_GREEN;
	oapiTriggerPanelRedrawArea (0, AID_SEQ_RETROJETT);
}

void Mercury_ControlPanel::CabinPressWarn(int warning) 
{
	warn_status[WARN_CABIN_PRESS] = warning;
	oapiTriggerPanelRedrawArea (4, AID_WARN_CABIN_PRESS);
}

void Mercury_ControlPanel::FuelQuanWarn(int warning) 
{
	warn_status[WARN_FUEL_QUAN] = warning;
	oapiTriggerPanelRedrawArea (4, AID_WARN_FUEL_QUAN);
}

void Mercury_ControlPanel::RetroWarn(int warning)
{
	warn_status[WARN_RETRO_WARN] = warning;
	oapiTriggerPanelRedrawArea (4, AID_WARN_RETRO_WARN);
}



void Mercury_ControlPanel::O2EmergWarn(int warning)
{
	warn_status[WARN_O2_EMER] = warning;
	oapiTriggerPanelRedrawArea (4, AID_WARN_O2_EMER);
}

void Mercury_ControlPanel::Roll05G()
{
	ind_status[IND_05G] = SEQ_GREEN;
	oapiTriggerPanelRedrawArea (0, AID_SEQ_05G);
}

void Mercury_ControlPanel::MainChute()
{
	ind_status[IND_MAIN] = SEQ_GREEN;
	oapiTriggerPanelRedrawArea (0, AID_SEQ_MAIN);
}

void Mercury_ControlPanel::LandingBag()
{
	ind_status[IND_LANDINGBAG] = SEQ_GREEN;
	oapiTriggerPanelRedrawArea (0, AID_SEQ_LANDINGBAG);
	//PlayVesselWave(SOUND_LANDINGBAG);
}

void Mercury_ControlPanel::LandingBagWarn()
{
	ind_status[IND_LANDINGBAG] = SEQ_RED;
	oapiTriggerPanelRedrawArea (0, AID_SEQ_LANDINGBAG);
}

void Mercury_ControlPanel::StartClock()
{
	if (!bClockStarted) {
		bClockStarted = true;
		clock_simt = oapiGetSimTime();
	}
}

void Mercury_ControlPanel::setAutoPilot(bool autopilot)
{
	switch_autopilot = autopilot;
	oapiTriggerPanelRedrawArea (0, AID_AUTOPILOT);
}

void Mercury_ControlPanel::setCapsuleSep(bool capsulesep)
{
	switch_capsulesep = capsulesep;
	oapiTriggerPanelRedrawArea (0, AID_SEQ_CAPSULESEP);
}

void Mercury_ControlPanel::setAbortJettisoned(bool abortjettisoned)
{
	switch_jettisonabort = abortjettisoned;
	oapiTriggerPanelRedrawArea (0, AID_SEQ_ABORTJETT);
	oapiTriggerPanelRedrawArea (1, AID_SEQ_ABORTJETT);
}

void Mercury_ControlPanel::DrawGlobeMap(VESSEL *vessel,  SURFHANDLE surf)
{
	double longitude = 0.0;
	double latitude = 0.0;
	double radius = 0.0;
	int int_long = 0;
	int int_lat = 0;
	const double rad_per_pixel = .5 * RAD;
	const double half_width = (124 / 4) * RAD;
	const double half_height = (208 / 4) * RAD;
	HGDIOBJ oldObj;
	vessel->GetEquPos(longitude, latitude, radius);
	longitude -= half_height;
	latitude -= half_width;
	int_long = int(longitude / rad_per_pixel);
	int_lat = int(latitude / rad_per_pixel);
	int_long += 360;
	int_lat +=180;
	if (int_long < 0)
		int_long += 720;
	if (int_long > (720-208))
	{
		oapiBlt (surf, srf[2], 0, 0, int_lat, int_long, 124, (720-int_long));
		oapiBlt (surf, srf[2], 0, (720-int_long), int_lat, 0, 124, 208 - (720-int_long));
	}
	else
		oapiBlt (surf, srf[2], 0, 0, int_lat, int_long, 124, 208);
	HDC hDC = oapiGetDC (surf);
	oldObj = SelectObject (hDC, g_Param.pen[2]);
	MoveToEx(hDC, 62, 0, 0);
	LineTo(hDC,62,207);
	MoveToEx(hDC, 0, 104, 0);
	LineTo(hDC,123,104);
	SelectObject(hDC, oldObj);
	oldObj = SelectObject (hDC, g_Param.pen[0]);
	Arc (hDC, 32, 74, 92, 134, 62, 74, 62, 74);
	SelectObject(hDC, oldObj);
	oapiReleaseDC (surf, hDC);
}

void Mercury_ControlPanel::DrawGlobe(VESSEL *vessel,  SURFHANDLE surf)
{
	//oapiBlt (surf, srf[2], 0, 0, 0, 0, 140, 140);
}


void Mercury_ControlPanel::RedrawPanel_Roll (VESSEL *vessel, SURFHANDLE surf)
{
	double alpha;
	alpha = z_roll_heading; //vessel->GetBank();
	HDC hDC = oapiGetDC (surf);
	DrawNeedle (hDC, 34, 34, 20.0, (PI / 2) + alpha, g_Param.pen[0], g_Param.pen[1] );
	oapiReleaseDC (surf, hDC);
}

void Mercury_ControlPanel::RedrawPanel_Pitch (VESSEL *vessel, SURFHANDLE surf)
{
	double alpha;
	alpha = x_pitch_heading; //vessel->GetPitch();
	HDC hDC = oapiGetDC (surf);
	DrawNeedle (hDC, 34, 34, 20.0, PI-alpha, g_Param.pen[0], g_Param.pen[1] );
	oapiReleaseDC (surf, hDC);
}

void Mercury_ControlPanel::RedrawPanel_Yaw (VESSEL *vessel, SURFHANDLE surf)
{
	double alpha;
	alpha = y_yaw_heading; //vessel->GetSlipAngle();
	HDC hDC = oapiGetDC (surf);
	DrawNeedle (hDC, 34, 34, 20.0, (PI * 0.5) - alpha, g_Param.pen[0], g_Param.pen[1] );
	oapiReleaseDC (surf, hDC);
}

void Mercury_ControlPanel::RedrawPanel_Rate (VESSEL *vessel, SURFHANDLE surf)
{
	HGDIOBJ oldObj;
	VESSELSTATUS vs;
	VECTOR3 ang_vel;
	vessel->GetStatus(vs);
	vessel->GetAngularVel(ang_vel);
	double time_step = oapiGetSimStep();
	double pitch_rate = -ang_vel.x; 
	double roll_rate =  ang_vel.z; 
	double yaw_rate =   -ang_vel.y; 
	if (switch_maneuver == false && ACBusSwitch == FUSE_OFF) {
		pitch_rate = 0; 
		roll_rate =  0; 
		yaw_rate =   0; 
	}
	int rate = 0;
	pitch_rate = pitch_rate / (PI / 6);
	roll_rate = roll_rate / (PI / 6);
	yaw_rate = yaw_rate / (PI / 6);
	if (pitch_rate > 1)  pitch_rate = 1;
	if (pitch_rate < -1) pitch_rate = -1;
	if (roll_rate > 1)   roll_rate = 1;
	if (roll_rate < -1)  roll_rate = -1;
	if (yaw_rate > 1)    yaw_rate = 1;
	if (yaw_rate < -1)   yaw_rate = -1;

	
	HDC hDC = oapiGetDC (surf);
	oldObj = SelectObject (hDC, g_Param.pen[2]);
	rate = int((pitch_rate * 20) + 22);
	MoveToEx(hDC, 2, rate, 0);
	LineTo(hDC, 43, rate);

	rate = int((roll_rate * 20) + 22);
	MoveToEx(hDC, rate, 2, 0);
	LineTo(hDC, rate, 20);

	rate = int((yaw_rate * 20) + 22);
	MoveToEx(hDC, rate, 24, 0);
	LineTo(hDC, rate, 42);

	SelectObject(hDC, oldObj);
	oapiReleaseDC (surf, hDC);
}

void Mercury_ControlPanel::RedrawPanel_Fuel (VESSEL *vessel, SURFHANDLE surf)
{
	double range = 120 * RAD ;
	double auto_fuel = 0;
	double man_fuel =  0;
	if (fuel_auto == 0 || fuel_manual == 0)
	{
		auto_fuel = 1;
		man_fuel  = 1;
	} else {
		auto_fuel = vessel->GetPropellantMass(fuel_auto) / vessel->GetPropellantMaxMass(fuel_auto);
		man_fuel  = vessel->GetPropellantMass(fuel_manual) / vessel->GetPropellantMaxMass(fuel_manual);
	}
	if (auto_fuel < .25 || man_fuel < .25) {
		this->FuelQuanWarn(WARN_ON);
	}
	HDC hDC = oapiGetDC (surf);
	DrawNeedle (hDC, 10, 65, 45.0, (auto_fuel * range)-60*RAD, g_Param.pen[0], g_Param.pen[1] );
	DrawNeedle (hDC, 120, 65, 45.0, PI - (man_fuel * range)+60*RAD, g_Param.pen[0], g_Param.pen[1] );
	oapiReleaseDC (surf, hDC);
}

void Mercury_ControlPanel::RedrawPanel_Accel(VESSEL *vessel, SURFHANDLE surf)
{
	double alpha = 0.0;
	alpha = -long_accel;
	if (alpha > 14.0)
		alpha = 120*RAD;
	else if (alpha < -18.0)
		alpha = 180*RAD;
	else
		alpha = alpha * (180*RAD / 18.0);
	HDC hDC = oapiGetDC (surf);
	DrawNeedle (hDC, 43, 46, 40.0, alpha + PI, g_Param.pen[0], g_Param.pen[1] );
	oapiReleaseDC (surf, hDC);
}

void Mercury_ControlPanel::RedrawPanel_Descent(VESSEL *vessel, SURFHANDLE surf)
{
	double alpha;
	double altitude = 0.0;
	alpha = descent_rate * 3.3 / 10.0 ;
	altitude = vessel->GetAltitude();
	if (alpha > 0) {
		alpha = 0;
	} else if (alpha >= -6)	{
		alpha = -alpha * (120 *RAD / 6.0);
	} else if (alpha >= -14) {
		alpha = (-alpha - 6) * (60*RAD / 8.0) + 120*RAD;
	} else if (alpha < -14) {
		alpha = 180*RAD;
	}
	if (altitude > 100000) 
		alpha = 0;
//	else if (altitude < 100000 && altitude > 100000) 
//		alpha = alpha * (1 - (50000.0/ (altitude - 100000)));


	HDC hDC = oapiGetDC (surf);
	DrawNeedle (hDC, 49, 46, 40.0, alpha + PI, g_Param.pen[0], g_Param.pen[1] );
	oapiReleaseDC (surf, hDC);
}

void Mercury_ControlPanel::RedrawPanel_RetrogradeTimer(VESSEL *vessel, SURFHANDLE surf)
{
	const int RETROCLOCK_MINLENGTH  = 45;
	const int RETROCLOCK_HOURLENGTH = 25;
	const int RETROCLOCK_SECLENGTH  = 55;
	
	double mission_hour = 0.0;
	double mission_min  = 0.0;
	double mission_sec  = 0.0;
	double number_hour  = 0.0;
	double number_min   = 0.0;
	double number_sec   = 0.0;
	double tempD = 0.0;
	double cur_time   = oapiGetSimTime() - clock_simt;
	double retro_countdown = retro_simt - cur_time;
	int num1 = 0;
	int num2 = 0;

	if (!bClockStarted ) cur_time = 0.0;
	if (!bClockStarted ) retro_countdown = 0.0;
	
	if (retro_countdown < 0) retro_countdown = 0.0;

	if (oapiGetSimTime()-retro_set_simt>2.0) {
		switch (lever_retro) {
			case RETRO_INC_MIN:
				retro_step_simt += oapiGetSimStep();
				if (retro_step_simt > 1.0) {
					retro_step_simt =0.0;
					retro_simt += 60;
					retro_countdown = retro_simt - cur_time;
				}
				break;
			case RETRO_INC_SEC:
				retro_step_simt += oapiGetSimStep();
				if (retro_step_simt > 1.0) {
					retro_step_simt =0.0;
					retro_simt += 1;
					retro_countdown = retro_simt - cur_time;
				}
				break;
			case RETRO_OFF:
				break;
			case RETRO_DEC_SEC:
				retro_step_simt += oapiGetSimStep();
				if (retro_step_simt > 1.0) {
					retro_step_simt =0.0;
					retro_simt -= 1;
					retro_countdown = retro_simt - cur_time;
				}
				break;
			case RETRO_DEC_MIN:
				retro_step_simt += oapiGetSimStep();
				if (retro_step_simt > 1.0) {
					retro_step_simt =0.0;
					retro_simt -= 60;
					retro_countdown = retro_simt - cur_time;
				}
				break;
		}
	}
	if (retro_countdown < 0.0) retro_countdown = 0.0;
	mission_sec = modf(cur_time / 60, &mission_min);
	mission_min = modf(mission_min / 60, &mission_hour);
	mission_hour = modf(mission_hour / 24, &tempD);

	tempD = modf(mission_sec * 60, &number_sec);
	tempD = modf(mission_min * 60, &number_min);
	tempD = modf(mission_hour * 24, &number_hour);

	

//	sprintf(oapiDebugString(), "Time: %d, %d. %d", (int) number_hour,(int) number_min,(int) number_sec);

	mission_sec = PI / 2  - (mission_sec  * PI * 2);
	mission_min = PI / 2  - (mission_min  * PI * 2);
	mission_hour = PI / 2 - (mission_hour * PI * 2);

	//oapiSetSurfaceColourKey(surf,0xff00ff);
	oapiBlt(surf, srf[10], 0, 0, 0, 0, 240, 259, 0xFFFFFF);
	
	if (retro_countdown <= 300)
		oapiBlt(surf, srf[17], 177,21, 0,0, 24,25, 0xFFFFFF);
	else
		oapiBlt(surf, srf[17], 177,21, 0,26, 24,25, 0xFFFFFF);

	DrawNumbers(surf,srf[16],number_hour, 18, 167, 31, 167, 11, 13);
	DrawNumbers(surf,srf[16],number_min , 52, 167, 65, 167, 11, 13);
	DrawNumbers(surf,srf[16],number_sec , 86, 167, 99, 167, 11, 13);


	HDC hDC = oapiGetDC (surf);
	DrawNeedle (hDC, 66, 62, RETROCLOCK_MINLENGTH, mission_min, g_Param.pen[0], g_Param.pen[1] );
	DrawNeedle (hDC, 66, 62, RETROCLOCK_HOURLENGTH, mission_hour, g_Param.pen[0], g_Param.pen[1] );
	DrawNeedle (hDC, 66, 62, RETROCLOCK_SECLENGTH, mission_sec, g_Param.pen[0], g_Param.pen[1] );

	oapiReleaseDC (surf, hDC);
//Set Retro Clock
	mission_sec = modf(retro_simt / 60, &mission_min);
	mission_min = modf(mission_min / 60, &mission_hour);
	mission_hour = modf(mission_hour / 24, &tempD);

	tempD = modf(mission_sec * 60, &number_sec);
	tempD = modf(mission_min * 60, &number_min);
	tempD = modf(mission_hour * 24, &number_hour);

	DrawNumbers(surf,srf[16],number_hour, 133, 100, 146, 100, 11, 13);
	DrawNumbers(surf,srf[16],number_min , 167, 100, 180, 100, 11, 13);
	DrawNumbers(surf,srf[16],number_sec , 201, 100, 214, 100, 11, 13);

//Set Retro Countdown
	mission_sec = modf(retro_countdown / 60, &mission_min);
	mission_min = modf(mission_min / 60, &mission_hour);
	mission_hour = modf(mission_hour / 24, &tempD);

	tempD = modf(mission_sec * 60, &number_sec);
	tempD = modf(mission_min * 60, &number_min);
	tempD = modf(mission_hour * 24, &number_hour);

	DrawNumbers(surf,srf[16],number_hour, 133, 167, 146, 167, 11, 13);
	DrawNumbers(surf,srf[16],number_min , 167, 167, 180, 167, 11, 13);
	DrawNumbers(surf,srf[16],number_sec , 201, 167, 214, 167, 11, 13);
	
	switch (lever_retro) {
	case RETRO_INC_MIN:
		oapiBlt(surf, srf[11], 94,186, 0,0, 130,73, 0xFFFFFF);
		break;
	case RETRO_INC_SEC:
		oapiBlt(surf, srf[12], 92,187, 0,0, 137,56, 0xFFFFFF);
		break;
	case RETRO_OFF:
		oapiBlt(surf, srf[13], 92,187, 0,0, 140,44, 0xFFFFFF);
		break;
	case RETRO_DEC_SEC:
		//oapiBlt(surf, srf[14], 93,174, 0,0, 131,73, 0xFFFFFF);
		oapiBlt(surf, srf[14], 93,174, 0,0, 138,58, 0xFFFFFF);
		break;
	case RETRO_DEC_MIN:
		oapiBlt(surf, srf[15], 94,160, 0,0, 131,73, 0xFFFFFF);
		break;
	}
}

void Mercury_ControlPanel::RedrawPanel_PeriscopeAltitude(VESSEL *vessel, SURFHANDLE surf) {

	double tempD = 0.0;
	
	double FOV_fustrum = (768 / 2) / tan((157 * PI / 180) / 2.0);
	double FOV = atan(alt_indicator / FOV_fustrum) * 2;
	double earth_rad = 6471.7;
	double cAlt = (earth_rad / sin(FOV / 2)) - earth_rad;
	
	cAlt = cAlt / 1.609;
	//cAlt = 354.0;

	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;
	
	//sprintf(oapiDebugString(), "Num: %f %f, %d%d%d%d", cAlt, FOV * 180 / PI, num4, num3, num2, num1);

	num4 = ((int) cAlt) / 1000;
	cAlt = cAlt - (num4 * 100);
	num3 = ((int) cAlt) / 100;
	cAlt = cAlt - (num3 * 100);
	num2 = ((int) cAlt) / 10;
	num1 = ((int) cAlt) % 10;

	oapiBlt(surf, srf[16],  0, 0, 11 * num4, 0, 11, 13);
	oapiBlt(surf, srf[16], 12, 0, 11 * num3, 0, 11, 13);
	oapiBlt(surf, srf[16], 24, 0, 11 * num2, 0, 11, 13);
	oapiBlt(surf, srf[16], 36, 0, 11 * num1, 0, 11, 13);

}

void Mercury_ControlPanel::RedrawPanel_FCTimer(VESSEL *vessel, SURFHANDLE surf)
{
	const int RETROCLOCK_MINLENGTH  = 45;
	const int RETROCLOCK_HOURLENGTH = 25;
	const int RETROCLOCK_SECLENGTH  = 55;
	
	double mission_hour = 0.0;
	double mission_min  = 0.0;
	double mission_sec  = 0.0;
	double number_hour  = 0.0;
	double number_min   = 0.0;
	double number_sec   = 0.0;
	double tempD = 0.0;
	double cur_time   = oapiGetSimTime() - clock_simt;
	int num1 = 0;
	int num2 = 0;

	if (!bClockStarted ) cur_time = 0.0;
	mission_sec = modf(cur_time / 60, &mission_min);
	mission_min = modf(mission_min / 60, &mission_hour);
	mission_hour = modf(mission_hour / 24, &tempD);

	tempD = modf(mission_sec * 60, &number_sec);
	tempD = modf(mission_min * 60, &number_min);
	tempD = modf(mission_hour * 24, &number_hour);


	//DrawNumbers(surf,srf[16],number_hour, 18, 167, 31, 167, 11, 13);
	//DrawNumbers(surf,srf[16],number_min , 52, 167, 65, 167, 11, 13);
	//DrawNumbers(surf,srf[16],number_sec , 86, 167, 99, 167, 11, 13);
	DrawNumbers(surf,srf[16], number_hour,  0, 0, 13, 0, 11, 13);
	DrawNumbers(surf,srf[16], number_min , 34, 0, 47, 0, 11, 13);
	DrawNumbers(surf,srf[16], number_sec , 68, 0, 81, 0, 11, 13);
	//sprintf(oapiDebugString(), "Time: %d, %d. %d", (int)number_hour,(int) number_min,(int) number_sec);


}

void Mercury_ControlPanel::RedrawPanel_FCRoll (VESSEL *vessel, SURFHANDLE surf)
{
	double alpha;
	alpha = z_roll_heading; //vessel->GetBank();
	HDC hDC = oapiGetDC (surf);
	DrawNeedle (hDC, 104, 104, 80.0, (PI / 2) + alpha, g_Param.pen[0], g_Param.pen[1] );
	oapiReleaseDC (surf, hDC);
}

void Mercury_ControlPanel::RedrawPanel_FCPitch (VESSEL *vessel, SURFHANDLE surf)
{
	double alpha;
	alpha = x_pitch_heading;    //vessel->GetPitch();
	HDC hDC = oapiGetDC (surf);
	DrawNeedle (hDC, 104, 104, 80.0, PI-alpha, g_Param.pen[0], g_Param.pen[1] );
	oapiReleaseDC (surf, hDC);
}

void Mercury_ControlPanel::RedrawPanel_FCYaw (VESSEL *vessel, SURFHANDLE surf)
{
	double alpha;
	alpha = y_yaw_heading; //vessel->GetSlipAngle();
	HDC hDC = oapiGetDC (surf);
	DrawNeedle (hDC, 104, 104, 80.0, (PI * .5) - alpha, g_Param.pen[0], g_Param.pen[1] );
	oapiReleaseDC (surf, hDC);
}

void Mercury_ControlPanel::RedrawPanel_FCRate (VESSEL *vessel, SURFHANDLE surf)
{
	HGDIOBJ oldObj;
	VESSELSTATUS vs;
	VECTOR3 ang_vel;
	vessel->GetStatus(vs);
	vessel->GetAngularVel(ang_vel);
	double time_step = oapiGetSimStep();
	double pitch_rate = -ang_vel.x; 
	double roll_rate =  ang_vel.z; 
	double yaw_rate =   -ang_vel.y; 
	int rate = 0;

	if (switch_maneuver == false && ACBusSwitch == FUSE_OFF) {
		pitch_rate = 0; 
		roll_rate =  0; 
		yaw_rate =   0; 
	}

	pitch_rate = pitch_rate / (PI / 12);
	roll_rate = roll_rate / (PI / 12);
	yaw_rate = yaw_rate / (PI / 12);

	if (pitch_rate > 1)  pitch_rate = 1;
	if (pitch_rate < -1) pitch_rate = -1;
	if (roll_rate > 1)   roll_rate = 1;
	if (roll_rate < -1)  roll_rate = -1;
	if (yaw_rate > 1)    yaw_rate = 1;
	if (yaw_rate < -1)   yaw_rate = -1;


	HDC hDC = oapiGetDC (surf);
	oldObj = SelectObject (hDC, g_Param.pen[3]);
	rate = int((pitch_rate * 60) + 67);
	MoveToEx(hDC, 2, rate, 0);
	LineTo(hDC, 134, rate);

	rate = int((roll_rate * 60) + 68);
	MoveToEx(hDC, rate, 2, 0);
	LineTo(hDC, rate, 60);

	rate = int((yaw_rate * 60) + 68);
	MoveToEx(hDC, rate, 72, 0);
	LineTo(hDC, rate, 134);

	SelectObject(hDC, oldObj);
	oapiReleaseDC (surf, hDC);
}

void Mercury_ControlPanel::RedrawPanel_FCFuel (VESSEL *vessel, SURFHANDLE surf)
{
	double range = 120 * RAD ;
	double auto_fuel = 0;
	double man_fuel =  0;
	if (fuel_auto == 0 || fuel_manual == 0)
	{
		auto_fuel = 1;
		man_fuel  = 1;
	} else {
		auto_fuel = vessel->GetPropellantMass(fuel_auto) / vessel->GetPropellantMaxMass(fuel_auto);
		man_fuel  = vessel->GetPropellantMass(fuel_manual) / vessel->GetPropellantMaxMass(fuel_manual);
	}
	HDC hDC = oapiGetDC (surf);
	DrawNeedle (hDC, 30, 195, 135.0, (auto_fuel * range)-60*RAD, g_Param.pen[0], g_Param.pen[1] );
	DrawNeedle (hDC, 360, 195, 135.0, PI - (man_fuel * range)+60*RAD, g_Param.pen[0], g_Param.pen[1] );
	oapiReleaseDC (surf, hDC);
}

bool Mercury_ControlPanel::RedrawPanel_Alt (VESSEL *vessel, SURFHANDLE surf)
{
	double alpha;
	double range = 300 * RAD;
	range = range / 100000;
	alpha = vessel->GetAltitude();
	alpha = alpha / 0.305;
	if (alpha > 100000) alpha = 100000;
	alpha = 100000 - alpha;
	if (oldAlt == alpha)
		return false;

	HDC hDC = oapiGetDC (surf);
	double test = (alpha * range)-(PI / 2);
	DrawNeedle (hDC, 79, 79, 55.0, (alpha * range)-(PI / 2), g_Param.pen[0], g_Param.pen[1] );
	oapiReleaseDC (surf, hDC);
	oldAlt = alpha;
	return true;
}

void Mercury_ControlPanel::Redraw_SequenceLight(int value, char *caption, SURFHANDLE surf)
{

	if (switch_light_test == SEQ_RED) {
		oapiBlt (surf, srf[4], 0, 0, 90, 0, 89, 32);
	} else if (switch_light_test == SEQ_GREEN) {
		oapiBlt (surf, srf[4], 0, 0, 180, 0, 89, 32);
	} else {
		switch (value) {
		case SEQ_CLEAR:
			oapiBlt (surf, srf[4], 0, 0, 0, 0, 89, 32);
			break;
		case SEQ_RED:
			oapiBlt (surf, srf[4], 0, 0, 90, 0, 89, 32);
			break;
		case SEQ_GREEN:
			oapiBlt (surf, srf[4], 0, 0, 180, 0, 89, 32);
			break;
		}
	}
	HDC hDC = oapiGetDC (surf);
	SelectObject (hDC, g_Param.font[1]);
	SelectObject (hDC, g_Param.brush[4]);
	SelectObject (hDC, GetStockObject (NULL_PEN));
	SetTextColor (hDC, RGB(0,0,0));
	SetTextAlign (hDC, TA_CENTER);
	SetBkMode (hDC, TRANSPARENT);
	TextOut(hDC, 45, 10, caption, strlen(caption));
	oapiReleaseDC (surf, hDC);

}

void Mercury_ControlPanel::Redraw_WarningLight(int value, char *caption1, char *caption2, SURFHANDLE surf)
{

	if (switch_light_test == SEQ_RED) {
		oapiBlt (surf, srf[27], 0, 0, 56, 0, 56, 35);
	} else if (switch_light_test == SEQ_GREEN) {
		oapiBlt (surf, srf[27], 0, 0, 56, 0, 56, 35);
	} else {
		switch (value) {
		case WARN_OFF:
			oapiBlt (surf, srf[27], 0, 0, 0, 0, 56, 35);
			break;
		case WARN_ON:
			oapiBlt (surf, srf[27], 0, 0, 56, 0, 56, 35);
		}
	}
	HDC hDC = oapiGetDC (surf);
	SelectObject (hDC, g_Param.font[0]);
	SelectObject (hDC, g_Param.brush[4]);
	SelectObject (hDC, GetStockObject (NULL_PEN));
	SetTextColor (hDC, RGB(0,0,0));
	SetTextAlign (hDC, TA_CENTER);
	SetBkMode (hDC, TRANSPARENT);
	TextOut(hDC, 28, 9, caption1, strlen(caption1));
	TextOut(hDC, 28, 20, caption2, strlen(caption2));
	oapiReleaseDC (surf, hDC);

}

void Mercury_ControlPanel::Redraw_WarningLight(int value, char *caption, SURFHANDLE surf)
{

	if (switch_light_test == SEQ_RED) {
		oapiBlt (surf, srf[27], 0, 0, 56, 0, 56, 35);
	} else if (switch_light_test == SEQ_GREEN) {
		oapiBlt (surf, srf[27], 0, 0, 56, 0, 56, 35);
	} else {
		switch (value) {
		case WARN_OFF:
			oapiBlt (surf, srf[27], 0, 0, 0, 0, 56, 35);
			break;
		case WARN_ON:
			oapiBlt (surf, srf[27], 0, 0, 56, 0, 56, 35);
		}
	}
	HDC hDC = oapiGetDC (surf);
	SelectObject (hDC, g_Param.font[0]);
	SelectObject (hDC, g_Param.brush[4]);
	SelectObject (hDC, GetStockObject (NULL_PEN));
	SetTextColor (hDC, RGB(0,0,0));
	SetTextAlign (hDC, TA_CENTER);
	SetBkMode (hDC, TRANSPARENT);
	TextOut(hDC, 28, 15, caption, strlen(caption));
	oapiReleaseDC (surf, hDC);

}

void Mercury_ControlPanel::Redraw_RingSwitch(bool value, SURFHANDLE surf)
{
	if (value)
		oapiBlt (surf, srf[5], 0, 0, 36, 1, 34, 41,0xFFFFFF);
	else
		oapiBlt (surf, srf[5], 0, 0, 1, 1, 34, 41,0xFFFFFF);
}

void Mercury_ControlPanel::Redraw_SeqSwitch(int value, SURFHANDLE surf)
{
	if (value == SWITCH_LEFT)
		oapiBlt (surf, srf[1], 0, 0, 0, 0, 33, 23, 0xFFFFFF);
	else if (value == SWITCH_RIGHT)
		oapiBlt (surf, srf[1], 0, 0, 0, 23, 33, 23, 0xFFFFFF);
	else if (value == SWITCH_MIDDLE)
		oapiBlt (surf, srf[1], 0, 0, 0, 46, 33, 23, 0xFFFFFF);
}

void Mercury_ControlPanel::Redraw_FlightSwitch(int value, SURFHANDLE surf)
{
	if (value == SWITCH_LEFT)
		oapiBlt (surf, srf[6], 0, 0, 0, 0, 33, 23, 0xFFFFFF);
	else if (value == SWITCH_RIGHT)
		oapiBlt (surf, srf[6], 0, 0, 0, 23, 33, 23, 0xFFFFFF);
	else if (value == SWITCH_MIDDLE)
		oapiBlt (surf, srf[6], 0, 0, 0, 46, 33, 23, 0xFFFFFF);
}

void Mercury_ControlPanel::Redraw_GaugeKnob(int value, SURFHANDLE knob, SURFHANDLE surf){
	oapiBlt(surf, knob, 0, 0, value * 65, 0, 65, 65, 0xFFFFFF);
}

void Mercury_ControlPanel::Redraw_SeqPush(int value, SURFHANDLE surf)
{
	if (value == PUSH_COVERED)
		oapiBlt (surf, srf[8], 0, 0, 62, 0, 31, 31,0xFFFFFF);
	else if (value == PUSH_UP)
		oapiBlt (surf, srf[8], 0, 0, 0, 0, 31, 31,0xFFFFFF);
	else 
		oapiBlt (surf, srf[8], 0, 0, 31, 0, 31, 31,0xFFFFFF);
}

void Mercury_ControlPanel::Redraw_FlightPush(int value, SURFHANDLE surf)
{
	if (value == PUSH_COVERED)
		oapiBlt (surf, srf[18], 0, 0, 62, 0, 31, 31, 0xFFFFFF);
	else if (value == PUSH_UP)
		oapiBlt (surf, srf[18], 0, 0, 0, 0, 31, 31, 0xFFFFFF);
	else 
		oapiBlt (surf, srf[18], 0, 0, 31, 0, 31, 31, 0xFFFFFF);
}

void Mercury_ControlPanel::RedrawPanel_RoundGauge(VESSEL *vessel, SURFHANDLE surf, double position){
	double alpha;
	alpha = position;    
	HDC hDC = oapiGetDC (surf);
	DrawNeedle (hDC, 46, 46, 40.0, alpha + PI, g_Param.pen[0], g_Param.pen[1] );
	oapiReleaseDC (surf, hDC);

}

void Mercury_ControlPanel::RedrawPanel_DualGauge(VESSEL *vessel, SURFHANDLE surf, double position1, double position2){
	HDC hDC = oapiGetDC (surf);
	//position1 = 30*RAD;
	//position2 = -30*RAD;
	DrawNeedle (hDC, 16, 46, 30.0, position1, g_Param.pen[0], g_Param.pen[1] );
	DrawNeedle (hDC, 75, 46, 30.0, position2 - PI, g_Param.pen[0], g_Param.pen[1] );
	oapiReleaseDC (surf, hDC);

}

void Mercury_ControlPanel::RedrawPanel_BottomGauge(VESSEL *vessel, SURFHANDLE surf, double position){
	double alpha;
	alpha = position;    
	HDC hDC = oapiGetDC (surf);
	DrawNeedle (hDC, 46, 79, 40.0, alpha+PI/2, g_Param.pen[0], g_Param.pen[1] );
	oapiReleaseDC (surf, hDC);
}

void Mercury_ControlPanel::RedrawPanel_DrawFuse(SURFHANDLE surf, int position){
	oapiBlt(surf, srf[26], 0, 0, position * 35, 0, 35, 30);
}

void Mercury_ControlPanel::RedrawPanel_DrawStripedFuse(SURFHANDLE surf, int position){
	oapiBlt(surf, srf[25], 0, 0, position * 35, 0, 35, 30);
}

#endif 
