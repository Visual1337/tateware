#include "win_utils.h"
#include "skStr.h"
#include <dwmapi.h>
#include "Main.h"
#include <sstream>
#include <string>
#include <algorithm>
#include <list>
#include "XorStr.hpp"
#include <iostream>
#include "xorstr.hpp"
#include <tlhelp32.h>
#include <fstream>
#include <filesystem>
#include <Windows.h>
#include <winioctl.h>
#include <lmcons.h>
#include <random>
#include "xorstr.hpp"
#include "icons.h"
#include "Controller.h"
#include "XorStr.hpp"
#include "auth.hpp"

#include "driver/driver.h"
 
std::string tm_to_readable_time(tm ctx);
static std::time_t string_to_timet(std::string timestamp);
static std::tm timet_to_tm(time_t timestamp);
const std::string compilation_date = (std::string)XorStr(__DATE__).c_str();
const std::string compilation_time = (std::string)XorStr(__TIME__).c_str();
using namespace KeyAuth;
std::string F = XorStr("deepware fortnite").c_str();
std::string C = XorStr("zn84DtzHxR").c_str();
std::string B = XorStr("5da2165716bc280675f6cae145ba96788e0ad0b1695d3d8949988ebf96fbc213").c_str();
std::string E = XorStr("1.0").c_str();
std::string D = XorStr("https://keyauth.win/api/1.2/").c_str();
std::string A = XorStr("ssl pin key (optional)").c_str();
api KeyAuthApp(F, C, B, E, D, A);

float redd = 255;
float greenn = 0;
float bluee = 0;

int defaultmainfov;
std::string IsOnScreen = "No";
std::string InGame = "No";
std::string IsAlive = "In Game > False";
std::string IsSliding = "Is Sliding > False";
std::string IsCrouched = "Is Crouched > False";
std::string IsSpectator = "Is Spectator > False";
std::string IsABot = "Is ABot > False";
std::string IsInactive = "Is Inactive > False";




using namespace Controller;
#include <XInput.h>
#include "Protection/protect/protectmain.h"
#include "Movement/MouseController.h"
#include "Security/modules.hpp"
#include "Security/No Access/protect.h"
#pragma comment(lib, "XInput.lib")
#define _XBOX_CONTROLLER_H_

//#define OFFSET_UWORLD = std::stoi(KeyAuthApp.var("uwrlld"));
//#define OFFSET_TEAM = OFFSET_TEAM);

#define OFFSET_UWORLD 0x1078a7d8 // 0x9EC1FE3
#define OFFSET_TEAM 0x10b0


std::string random_string(std::size_t length)
{

    const std::string CHARACTERS = ("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

    std::string random_string;

    for (std::size_t i = 0; i < length; ++i)
    {
        random_string += CHARACTERS[distribution(generator)];
    }

    return random_string;
}

int Menu_BoxInt = 0;
int Menu_AimBoneInt = 0;
int Menu_AimKey = 0;
int Menu_SnapPos = 0;
int Menu_TPPos = 0;

static const char* AimBone_TypeItems[]{
    "   Head",
    "   Neck",
    "   Chest",
    "   Pelvis",
    "   Bottom"
};

static const char* Snaplines_Pos[]{
    "   TOP",
    "   BOTTOM",
    "   CENTER"
};



static const char* TPs_Pos[]{
    "   TP ABOVE",
    "   TP RIGHT",
    "   TP LEFT"
};

static const char* Aimkey_TypeItems[]{
    "   Right Mouse [Default]",
    "   Left Mouse",
    "   SHIFT",
    "   CAPS",
    "   CTRL",
    "   ALT"

};

static const char* Boxtype_TypeItems[]{
    "   No Box",
    "   Box",
    "   Filled Box",
    "   Corner Filled Box",
    "   Corner Box"
};

static const char alphanum[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;


ImFont* m_pFont;

DWORD_PTR Uworlds;
DWORD_PTR LocalPawns;
DWORD_PTR PlayerStates;
DWORD_PTR Localplayers;
DWORD_PTR Rootcomps;
DWORD_PTR PlayerControllers;
DWORD_PTR Persistentlevels;
DWORD_PTR Ulevels;

Vector3 lactorpossssition;

uint64_t TargetPawn;
int localplayerID;

bool isabting;

RECT GameRect = { NULL };
D3DPRESENT_PARAMETERS d3dpp;

DWORD ScreenCenterX;
DWORD ScreenCenterY;
DWORD ScreenCenterZ;

template <typename type>
type rpm(uint64_t src, uint64_t size = sizeof(type)) {
    return rread<type>(src);
}

template <typename type>
void wpm(uint64_t src, type tochange)
{
    //drivers.write<type>(src, tochange);

}

static void gikabjkbdjkas();
static void qaDUOGBVASZ();//xInitD3d
static void ASHGBFKUSDH();

static LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

static HWND Window = NULL;
IDirect3D9Ex* p_Object = NULL;
static LPDIRECT3DDEVICE9 D3dDevice = NULL;
static LPDIRECT3DVERTEXBUFFER9 TriBuf = NULL;

FTransform GetBoneIndex(DWORD_PTR mesh, int index)
{
    DWORD_PTR bonearray = rpm<DWORD_PTR>(mesh + 0x5F0);
    if (bonearray == NULL) {
        bonearray = rpm<DWORD_PTR>(mesh + 0x5F0 + 0x10);// + 0x10
    }
    return rpm<FTransform>(bonearray + (index * 0x60));
}

static ImFont* Verdana, * Verdana2, * DefaultFont;

static auto DrawOutlinedText(ImFont* pFont, const std::string& text, const ImVec2& pos, float size, ImU32 color, bool center) -> VOID
{
    ImGui::PushFont(Verdana);
    std::stringstream stream(text);
    std::string line;

    float y = 0.0f;
    int index = 0;

    while (std::getline(stream, line))
    {
        ImVec2 textSize = pFont->CalcTextSizeA(size, FLT_MAX, 0.0f, line.c_str());

        if (center)
        {
            ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) + 1, (pos.y + textSize.y * index) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
            ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) - 1, (pos.y + textSize.y * index) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
            ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(pos.x - textSize.x / 2.0f, pos.y + textSize.y * index), ImGui::GetColorU32(color), line.c_str());
        }
        else
        {
            ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x) + 1, (pos.y + textSize.y * index) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
            ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x) - 1, (pos.y + textSize.y * index) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
            ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(pos.x, pos.y + textSize.y * index), ImGui::GetColorU32(color), line.c_str());
        }

        y = pos.y + textSize.y * (index + 1);
        index++;
    }
    ImGui::PopFont();
}

Vector3 CamLoc;
Vector3 CamRot;

Vector3 GetBoneWithRotation(DWORD_PTR mesh, int index)
{
    uintptr_t bonearray = 0;
    bonearray = rpm<uintptr_t>(mesh + 0x5f0);
    if (!bonearray) bonearray = rpm<uintptr_t>(mesh + 0x5f0 + 0x10);
    FTransform ComponentToWorld = rpm<FTransform>(mesh + 0x240);
    FTransform bone = rpm<FTransform>(bonearray + (index * 0x60));
    D3DMATRIX Matrix;
    Matrix = MatrixMultiplication(bone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());
    return Vector3(Matrix._41, Matrix._42, Matrix._43);
}

D3DMATRIX Matrix(Vector3 rot, Vector3 origin = Vector3(0, 0, 0)) {
    float radPitch = (rot.x * float(M_PI) / 180.f);
    float radYaw = (rot.y * float(M_PI) / 180.f);
    float radRoll = (rot.z * float(M_PI) / 180.f);

    float SP = sinf(radPitch);
    float CP = cosf(radPitch);
    float SY = sinf(radYaw);
    float CY = cosf(radYaw);
    float SR = sinf(radRoll);
    float CR = cosf(radRoll);

    D3DMATRIX matrix;
    matrix.m[0][0] = CP * CY;
    matrix.m[0][1] = CP * SY;
    matrix.m[0][2] = SP;
    matrix.m[0][3] = 0.f;

    matrix.m[1][0] = SR * SP * CY - CR * SY;
    matrix.m[1][1] = SR * SP * SY + CR * CY;
    matrix.m[1][2] = -SR * CP;
    matrix.m[1][3] = 0.f;

    matrix.m[2][0] = -(CR * SP * CY + SR * SY);
    matrix.m[2][1] = CY * SR - CR * SP * SY;
    matrix.m[2][2] = CR * CP;
    matrix.m[2][3] = 0.f;

    matrix.m[3][0] = origin.x;
    matrix.m[3][1] = origin.y;
    matrix.m[3][2] = origin.z;
    matrix.m[3][3] = 1.f;

    return matrix;
}


void GetDesktopResolution(int& horizontal, int& vertical)
{
    RECT desktop;
    // Get a handle to the desktop window
    const HWND hDesktop = GetDesktopWindow();
    // Get the size of screen to the variable desktop
    GetWindowRect(hDesktop, &desktop);
    // The top left corner will have coordinates (0,0)
    // and the bottom right corner will have coordinates
    // (horizontal, vertical)
    horizontal = desktop.right;
    vertical = desktop.bottom;
}

extern Vector3 CameraEXT(0, 0, 0);



void FilledRect(int x, int y, int w, int h, ImColor color)
{
    ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), 0, 0);
}



struct Cameras
{
    Vector3 Locations;
    Vector3 Rotations;
    float FieldOfViews;
};
Cameras vCameras;
bool inb = true;
struct FMinimalViewInfo
{
    Vector3 Locations;
    Vector3 Rotations;
    float FOVs;
};
Cameras GetCamera(__int64 a1)
{
    Cameras Cam;

    //uint64_t PlayerCameraManager = 0x340;
    //auto CameraCache = drivers.read<FMinimalViewInfo>(PlayerCameraManager + 0x2a80 + 0x10); //LastFrameCameraCachePrivate
    //Cam.Rotations = CameraCache.Rotations;
    //Cam.Locations = CameraCache.Locations;
    //Cam.FieldOfViews = CameraCache.FOVs;


    __int64 v1;
    __int64 v6;
    __int64 v7;
    __int64 v8;
    v1 = rpm<__int64>(Localplayers + 0xd0);
    __int64 v9 = rpm<__int64>(v1 + 0x8);
    Cam.FieldOfViews = 80.0f / (rpm<double>(v9 + 0x7F0) / 1.19f);
    Cam.Rotations.x = rpm<double>(v9 + 0x9C0);
    Cam.Rotations.y = rpm<double>(a1 + 0x148);
    uint64_t Cam_PtrLocation = rpm<uint64_t>(Uworlds + 0x110);
    Cam.Locations = rpm<Vector3>(Cam_PtrLocation);
    return Cam;
}

Vector3 ProjectWorldToTheScreen(Vector3 WorldLocation)
{

        vCameras = GetCamera(Rootcomps);
        vCameras.Rotations.x = (asin(vCameras.Rotations.x)) * (180.0 / M_PI);


        D3DMATRIX tempMatrix = Matrix(vCameras.Rotations);

        Vector3 vAxisX = Vector3(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
        Vector3 vAxisY = Vector3(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
        Vector3 vAxisZ = Vector3(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);

        Vector3 vDelta = WorldLocation - vCameras.Locations;
        Vector3 vTransformed = Vector3(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

        if (vTransformed.z < 1.f)
            vTransformed.z = 1.f;



        return Vector3((Width / 2.0f) + vTransformed.x * (((Width / 2.0f) / tanf(vCameras.FieldOfViews/*vCamera.FieldOfView*/ * (float)M_PI / 360.f))) / vTransformed.z, (Height / 2.0f) - vTransformed.y * (((Width / 2.0f) / tanf(vCameras.FieldOfViews/*vCamera.FieldOfView*/ * (float)M_PI / 360.f))) / vTransformed.z, 0);
}


__int64 __fastcall DecryptAnsi(unsigned __int16* a1, _WORD* a2)
{
    _WORD* v2; // rdi
    int v4; // ebx
    __int64 result; // rax
    int v6; // r8d
    __int16 v7; // dx

    v2 = a2;
    memcpy(
        a2,
        a1 + 2,
        2 * ((unsigned __int64)*a1 >> 6));

    v4 = *a1 >> 6;
    result = rpm<int>(base_address + 0xED83F44) >> 5;
    v6 = 0;
    if (v4)
    {
        do
        {
            v7 = result ^ (*v2 << 8);
            result = (unsigned int)(result + 2 * v6++);
            *v2 = HIBYTE(*v2) | v7 & 0xFF00;
            ++v2;
        } while (v6 < v4);
    }
    return result;
}

__int64 __fastcall DecryptWide(unsigned __int16* a1, char* a2)
{
    char* v2; // rdi
    int v4; // ebx
    unsigned int v5; // eax
    __int64 result; // rax
    int v7; // r8d
    unsigned int v8; // ecx
    char v9; // dl

    v2 = a2;
    memcpy(a2, a1 + 2, (unsigned __int64)*a1 >> 6);
    v4 = *a1 >> 6;
    result = rpm<int>(base_address + 0xED83F44) >> 5;

    v7 = 0;
    if (v4)
    {
        do
        {
            v8 = *v2++;
            v9 = result ^ (16 * v8) ^ (result ^ (v8 >> 4)) & 0xF;
            result = (unsigned int)(result + 2 * v7++);
            *(v2 - 1) = v9;
        } while (v7 < v4);
    }
    return result;
}


DWORD thread(LPVOID in) {
    while (1) {
        if (GetAsyncKeyState(VK_INSERT) & 1) {
            global.menu = !global.menu;
        }
        if (GetAsyncKeyState(VK_INSERT) & 1) {
            global.menu = !global.menu;
        }
        Sleep(2);
    }
}

Vector3 AimbotCorrection(float bulletVelocity, float bulletGravity, float targetDistance, Vector3 targetPosition, Vector3 targetVelocity) {
    Vector3 recalculated = targetPosition;
    float gravity = fabs(bulletGravity);
    float time = targetDistance / fabs(bulletVelocity);
    /* Bullet drop correction */
    float bulletDrop = (gravity / 250) * time * time;
    recalculated.z += bulletDrop * 120;
    /* Player movement correction */
    recalculated.x += time * (targetVelocity.x);
    recalculated.y += time * (targetVelocity.y);
    recalculated.z += time * (targetVelocity.z);
    return recalculated;
}

void aimbot(float x, float y, float z)
{
    float ScreenCenterX = (Width / 2);
    float ScreenCenterY = (Height / 2);
    float ScreenCenterZ = (Depth / 2);
    int AimSpeed = global.Aim_Speed;
    float TargetX = 0;
    float TargetY = 0;
    float TargetZ = 0;

    if (x != 0) {
        if (x > ScreenCenterX) {
            TargetX = -(ScreenCenterX - x);
            TargetX /= AimSpeed;
            if (TargetX + ScreenCenterX > ScreenCenterX * 2) TargetX = 0;
        }

        if (x < ScreenCenterX) {
            TargetX = x - ScreenCenterX;
            TargetX /= AimSpeed;
            if (TargetX + ScreenCenterX < 0) TargetX = 0;
        }
    }

    if (y != 0) {
        if (y > ScreenCenterY) {
            TargetY = -(ScreenCenterY - y);
            TargetY /= AimSpeed;
            if (TargetY + ScreenCenterY > ScreenCenterY * 2) TargetY = 0;
        }

        if (y < ScreenCenterY) {
            TargetY = y - ScreenCenterY;
            TargetY /= AimSpeed;
            if (TargetY + ScreenCenterY < 0) TargetY = 0;
        }
    }

    if (z != 0) {
        if (z > ScreenCenterZ) {
            TargetZ = -(ScreenCenterZ - z);
            TargetZ /= AimSpeed;
            if (TargetZ + ScreenCenterZ > ScreenCenterZ * 2) TargetZ = 0;
        }

        if (z < ScreenCenterZ) {
            TargetZ = z - ScreenCenterZ;
            TargetZ /= AimSpeed;
            if (TargetZ + ScreenCenterZ < 0) TargetZ = 0;
        }
    }

    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dx = static_cast<DWORD>(TargetX);
    input.mi.dy = static_cast<DWORD>(TargetY);
    input.mi.mouseData = NULL;
    input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_VIRTUALDESK;
    input.mi.time = 0;
    input.mi.dwExtraInfo = NULL;
    MouseController::NtUserSendInput(1, &input, sizeof INPUT);


    //SendInput(1, &input, sizeof INPUT);

    if (global.aimline)
    {
        //weapon 
        
        //uint64_t CurrentWeapon22 = rpm<uint64_t>(LocalPawns + 0x8d8);
       // Vector3 mypos = rpm<Vector3>(CurrentWeapon22 + 0x128);
        //ImGui::GetOverlayDrawList()->AddLine(ImVec2(mypos.x, mypos.y), ImVec2(TargetX, TargetY), ImColor(0, 255, 0), 0.6);
    }

    return;
}


double GetCrossDistance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

typedef struct _FNlEntity
{
    uint64_t Actor;
    uint64_t USkeletalMeshComponent;
    DWORD_PTR USceneComponent;
    int ID;
    uint64_t mesh;
} FNlEntity;

std::vector<FNlEntity> entityList;

typedef struct
{
    DWORD R;
    DWORD G;
    DWORD B;
    DWORD A;
}RGBA;

class coleeeer
{
public:
    RGBA NiggaGreen = { 128, 224, 0, 200 };
    RGBA red = { 255,0,0,255 };
    RGBA Magenta = { 255,0,255,255 };
    RGBA yellow = { 255,255,0,255 };
    RGBA grayblue = { 128,128,255,255 };
    RGBA green = { 128,224,0,255 };
    RGBA darkgreen = { 0,224,128,255 };
    RGBA brown = { 192,96,0,255 };
    RGBA pink = { 255,168,255,255 };
    RGBA DarkYellow = { 216,216,0,255 };
    RGBA SilverWhite = { 236,236,236,255 };
    RGBA purple = { 144,0,255,255 };
    RGBA Navy = { 88,48,224,255 };
    RGBA skyblue = { 0,136,255,255 };
    RGBA graygreen = { 128,160,128,255 };
    RGBA blue = { 0,96,192,255 };
    RGBA orange = { 255,128,0,255 };
    RGBA peachred = { 255,80,128,255 };
    RGBA reds = { 255,128,192,255 };
    RGBA darkgray = { 96,96,96,255 };
    RGBA Navys = { 0,0,128,255 };
    RGBA darkgreens = { 0,128,0,255 };
    RGBA darkblue = { 0,128,128,255 };
    RGBA redbrown = { 128,0,0,255 };
    RGBA purplered = { 128,0,128,255 };
    RGBA greens = { 0,255,0,255 };
    RGBA envy = { 0,255,255,255 };
    RGBA black = { 0,0,0,255 };
    RGBA gray = { 128,128,128,255 };
    RGBA white = { 255,255,255,255 };
    RGBA blues = { 30,144,255,255 };
    RGBA lightblue = { 135,206,250,160 };
    RGBA Scarlet = { 220, 20, 60, 160 };
    RGBA white_ = { 255,255,255,200 };
    RGBA gray_ = { 128,128,128,200 };
    RGBA black_ = { 0,0,0,200 };
    RGBA red_ = { 255,0,0,200 };
    RGBA Magenta_ = { 255,0,255,200 };
    RGBA yellow_ = { 255,255,0,200 };
    RGBA grayblue_ = { 128,128,255,200 };
    RGBA green_ = { 128,224,0,200 };
    RGBA darkgreen_ = { 0,224,128,200 };
    RGBA brown_ = { 192,96,0,200 };
    RGBA pink_ = { 255,168,255,200 };
    RGBA darkyellow_ = { 216,216,0,200 };
    RGBA silverwhite_ = { 236,236,236,200 };
    RGBA purple_ = { 144,0,255,200 };
    RGBA Blue_ = { 88,48,224,200 };
    RGBA skyblue_ = { 0,136,255,200 };
    RGBA graygreen_ = { 128,160,128,200 };
    RGBA blue_ = { 0,96,192,200 };
    RGBA orange_ = { 255,128,0,200 };
    RGBA pinks_ = { 255,80,128,200 };
    RGBA Fuhong_ = { 255,128,192,200 };
    RGBA darkgray_ = { 96,96,96,200 };
    RGBA Navy_ = { 0,0,128,200 };
    RGBA darkgreens_ = { 0,128,0,200 };
    RGBA darkblue_ = { 0,128,128,200 };
    RGBA redbrown_ = { 128,0,0,200 };
    RGBA purplered_ = { 128,0,128,200 };
    RGBA greens_ = { 0,255,0,200 };
    RGBA envy_ = { 0,255,255,200 };
    RGBA glassblack = { 0, 0, 0, 160 };
    RGBA GlassBlue = { 65,105,225,80 };
    RGBA glassyellow = { 255,255,0,160 };
    RGBA glass = { 200,200,200,60 };
    RGBA Plum = { 221,160,221,160 };
};

coleeeer Col;


typedef struct _LootEntity {
    std::string GNames;
    uintptr_t ACurrentItem;
} LootEntity;
static std::vector<LootEntity> LootentityList;

void DrawSnapline(int x, int y, int w, int h, int Thickness, RGBA* color)
{
    ImGui::GetOverlayDrawList()->AddLine(ImVec2(x, y), ImVec2(w, h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), Thickness);

}
void AimAt(DWORD_PTR entity)
{
    uint64_t curActorMeshio = rpm<uint64_t>(entity + 0x310);
    auto rootHead = GetBoneWithRotation(curActorMeshio, global.hitbox);
    if (global.PredictAim) {
        float distance = lactorpossssition.Distance(rootHead) / 250;
        uint64_t CurrentActorRootComponent = rpm<uint64_t>(entity + 0x190);
        Vector3 vellocity = rpm<Vector3>(CurrentActorRootComponent + 0x170);
        Vector3 Predicted = AimbotCorrection(30000, -504, distance, rootHead, vellocity);
        Vector3 rootHeadOut = ProjectWorldToTheScreen(Predicted);
        if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
            if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= global.AimFOV * 1)) {
                aimbot(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z);

            }
        }
    }
    else {
        Vector3 rootHeadOut = ProjectWorldToTheScreen(rootHead);
        if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
            if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= global.AimFOV * 1)) {
                aimbot(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z);
            }
        }
    }
}
void Aim3(DWORD_PTR entity, uintptr_t gun, int hitbone)
{
    uint64_t CurrentActorMesh = rpm<uint64_t>(entity + 0x310);
    Vector3 PHitbone = GetBoneWithRotation(CurrentActorMesh, hitbone);
    Vector3 Head = (PHitbone);
    Vector3 rootHeadOut = ProjectWorldToTheScreen(Vector3(Head.x, Head.y, Head.z + 0));
    int wepaon = gun;
    DrawSnapline(wepaon, wepaon, rootHeadOut.x, rootHeadOut.y, 1.0, &Col.green);
}
bool FnameShit = false;

bool silentaim = false;
DWORD_PTR ClosestPawn = NULL;
Vector3 Location; // Camera Location

Vector3 CalculateNewRotation(Vector3& zaz, Vector3& daz) {
    Vector3 dalte = zaz - daz;
    Vector3 ongle;
    float hpm = sqrtf(dalte.x * dalte.x + dalte.y * dalte.y);
    ongle.y = atan(dalte.y / dalte.x) * 57.295779513082f;
    ongle.x = (atan(dalte.z / hpm) * 57.295779513082f) * -1.f;
    if (dalte.x >= 0.f) ongle.y += 180.f;
    return ongle;
}

//Vector3 GetLoc(Vector3 Loc) {
//    Location = Vector3(vCamera.Locations.x, vCamera.Locations.y, vCamera.Locations.z);
//    return Location;
//}


void AimAt2(DWORD_PTR entity) {
    uint64_t curActorMeshio = rpm<uint64_t>(entity + 0x310);
    auto rootHead = GetBoneWithRotation(curActorMeshio, global.hitbox);

    if (global.PredictAim) {
        float distance = lactorpossssition.Distance(rootHead) / 250;
        uint64_t CurrentActorRootComponent = rpm<uint64_t>(entity + 0x190);
        Vector3 vellocity = rpm<Vector3>(CurrentActorRootComponent + 0x170);
        Vector3 Predicted = AimbotCorrection(30000, -504, distance, rootHead, vellocity);
        Vector3 rootHeadOut = ProjectWorldToTheScreen(Predicted);
        if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
            if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= global.AimFOV * 1)) {
                if (global.Aimline) {
                    ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(rootHeadOut.x, rootHeadOut.y), ImGui::GetColorU32({ 255, 255, 255, 1.0f }), 0.5);

                }
            }
        }
    }
    else {
        Vector3 rootHeadOut = ProjectWorldToTheScreen(rootHead);
        if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
            if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= global.AimFOV * 1)) {
                if (global.Aimline) {
                    uint64_t CurrentWeapon22 = rpm<uint64_t>(LocalPawns + 0x8d8);
                    Vector3 mypos = rpm<Vector3>(CurrentWeapon22 + 0x128);
                    ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(rootHeadOut.x, rootHeadOut.y), ImGui::GetColorU32({ 0, 255, 0, 1.0f }), 0.5);
                }
            }
        }
    }
}

void RadarRange(float* x, float* y, float range)
{
    if (fabs((*x)) > range || fabs((*y)) > range)
    {
        if ((*y) > (*x))
        {
            if ((*y) > -(*x))
            {
                (*x) = range * (*x) / (*y);
                (*y) = range;
            }
            else
            {
                (*y) = -range * (*y) / (*x);
                (*x) = -range;
            }
        }
        else
        {
            if ((*y) > -(*x))
            {
                (*y) = range * (*y) / (*x);
                (*x) = range;
            }
            else
            {
                (*x) = -range * (*x) / (*y);
                (*y) = -range;
            }
        }
    }
}

bool radar = true;
bool rect_radar = false;
float radar_position_x{ 84.494f };
float radar_position_y{ 77.841f };
float radar_size{ 150.f };
float RadarDistance = { 700.f };

#define ViewYawMin 0x331C
#define ViewYawMax 0x3320
#define ViewPitchMin 0x3314
#define ViewPitchMax 0x3318
#define AimPitchMin 0x1138
#define AimPitchMax 0x113C

void normalize(Vector3& in)
{
    if (in.x > 89.f) in.x -= 360.f;
    else if (in.x < -89.f) in.x += 360.f;

    while (in.y > 180)in.y -= 360;
    while (in.y < -180)in.y += 360;
    in.z = 0;
}

// Define the '/' operator as a non-member function
Vector3 operator/(const Vector3& v, float scalar) {
    return Vector3{ v.x / scalar, v.y / scalar, v.z / scalar };
}

Vector3 smooth_aim(Vector3 target, float smooth)
{
    Vector3 diff = target - vCameras.Rotations;
    normalize(diff);
    return vCameras.Rotations + diff / smooth;
}

void CalcRadarPoint(Vector3 vOrigin, int& screenx, int& screeny)
{
    Cameras Camera = GetCamera(Rootcomps);
    Vector3 vAngle = Camera.Rotations;
    auto fYaw = vAngle.y * M_PI / 180.0f;
    float dx = vOrigin.x - Camera.Locations.x;
    float dy = vOrigin.y - Camera.Locations.y;

    float fsin_yaw = sinf(fYaw);
    float fminus_cos_yaw = -cosf(fYaw);

    float x = dy * fminus_cos_yaw + dx * fsin_yaw;
    x = -x;
    float y = dx * fminus_cos_yaw - dy * fsin_yaw;

    float range = (float)RadarDistance * 100.f;

    RadarRange(&x, &y, range);

    ImVec2 DrawPos = ImVec2(radar_position_x, radar_position_y);
    ImVec2 DrawSize = ImVec2(radar_size, radar_size);

    int rad_x = (int)DrawPos.x;
    int rad_y = (int)DrawPos.y;

    float r_siz_x = DrawSize.x;
    float r_siz_y = DrawSize.y;

    int x_max = (int)r_siz_x + rad_x - 5;
    int y_max = (int)r_siz_y + rad_y - 5;

    screenx = rad_x + ((int)r_siz_x / 2 + int(x / range * r_siz_x));
    screeny = rad_y + ((int)r_siz_y / 2 + int(y / range * r_siz_y));

    if (screenx > x_max)
        screenx = x_max;

    if (screenx < rad_x)
        screenx = rad_x;

    if (screeny > y_max)
        screeny = y_max;

    if (screeny < rad_y)
        screeny = rad_y;
}

void fortnite_radar(float x, float y, float size, bool rect)
{
    if (radar)
    {
        ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Once);
        ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize, ImGuiCond_Once);
        static const auto flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground;
        ImGui::Begin(("##radar"), nullptr, flags);

        float render_size = 5;
        ImDrawList* drawList = ImGui::GetWindowDrawList();

        if (rect) {
            drawList->AddRectFilled(ImVec2(x, y), ImVec2(x + size, y + size), ImGui::GetColorU32({ 0.13f, 0.13f, 0.13f, 1.f }), 0.0f, 0);
            drawList->AddRect(ImVec2(x, y), ImVec2(x + size, y + size), ImGui::GetColorU32({ 0.f, 0.f, 0.f, 1.f }), 0.0f, 0, 1.0f);
        }
        else {
            drawList->AddCircleFilled(ImVec2(x + size / 2, y + size / 2), size, ImGui::GetColorU32({ 0.0f, 0.0f, 0.0f, 0.5f }), 1000);
            drawList->AddCircleFilled(ImVec2(x + size / 2, y + size / 2), render_size / 2 * sqrt(2), ImGui::GetColorU32({ 1.0f, 1.0f, 1.0f, 1.0f }), 1000);
            drawList->AddCircle(ImVec2(x + size / 2, y + size / 2), size, ImGui::GetColorU32({ 0.1f, 0.1f, 0.1f, 1.0f }), 1000, 5);
        }

        ImGui::End();
    }
}


uintptr_t PlayerCameraManagers;
enum External : uint64_t
{
    PlayerCameraManager = 0x340,
};

void add_players_radar(Vector3 WorldLocation)
{
    if (radar)
    {
        static const auto flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground;
        ImGui::Begin(("##radar"), nullptr, flags);

        int ScreenX, ScreenY = 0;
        const auto& GetWindowDrawList = ImGui::GetWindowDrawList();
        ImDrawList* drawList = ImGui::GetWindowDrawList();

        CalcRadarPoint(WorldLocation, ScreenX, ScreenY);
        if (rect_radar) drawList->AddRectFilled(ImVec2((float)ScreenX - 4.5, (float)ScreenY - 4.5), ImVec2((float)ScreenX + 4.5, (float)ScreenY + 4.5), ImGui::GetColorU32({ 1.f, 1.f, 1.f, 1.f }));
        else drawList->AddCircleFilled(ImVec2(ScreenX, ScreenY), 5, ImGui::GetColorU32({ 1.f, 1.f, 1.f, 1.f }), 12);

        ImGui::End();
    }
}

bool isVisible(DWORD_PTR mesh)
{
    if (!mesh)
        return false;
    float fLastSubmitTime = rpm<float>(mesh + 0x360);// + 20
    float fLastRenderTimeOnScreen = rpm<float>(mesh + 0x368);// + 24
    //AFortPawn	OverlappingBuildings	0x1ae0	TArray<ABuildingActor*>
    //uint64_t OverlappingBuildings = rpm<uint64_t>(ClosestPawn + 0x1ae0);
    const float fVisionTick = 0.06f;
    bool bVisible = fLastRenderTimeOnScreen + fVisionTick >= fLastSubmitTime;
    return bVisible;
}


void draw_cornered_box(int x, int y, int w, int h, ImColor color, int thickness) {

    float line_w = (w / 3);
    float line_h = (h / 3);
    ImGui::GetOverlayDrawList()->AddLine(ImVec2(x, y), ImVec2(x, y + line_h), color, thickness);
    ImGui::GetOverlayDrawList()->AddLine(ImVec2(x, y), ImVec2(x + line_w, y), color, thickness);
    ImGui::GetOverlayDrawList()->AddLine(ImVec2(x + w - line_w, y), ImVec2(x + w, y), color, thickness);
    ImGui::GetOverlayDrawList()->AddLine(ImVec2(x + w, y), ImVec2(x + w, y + line_h), color, thickness);
    ImGui::GetOverlayDrawList()->AddLine(ImVec2(x, y + h - line_h), ImVec2(x, y + h), color, thickness);
    ImGui::GetOverlayDrawList()->AddLine(ImVec2(x, y + h), ImVec2(x + line_w, y + h), color, thickness);
    ImGui::GetOverlayDrawList()->AddLine(ImVec2(x + w - line_w, y + h), ImVec2(x + w, y + h), color, thickness);
    ImGui::GetOverlayDrawList()->AddLine(ImVec2(x + w, y + h - line_h), ImVec2(x + w, y + h), color, thickness);
}


void DrawRect(int x, int y, int w, int h, int thickness)
{
    ImGui::GetOverlayDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImColor(255, 255, 255, 255)), 15, 15, thickness);
}

void DrawCornerBoxFill(int X, int Y, int W, int H, const ImU32& color, int opacity) {
    float lineW = (W / 3);
    float lineH = (H / 3);

    ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::GetColorU32(color), opacity);
    ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::GetColorU32(color), opacity);
    ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::GetColorU32(color), opacity);
    ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::GetColorU32(color), opacity);
    ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::GetColorU32(color), opacity);
    ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::GetColorU32(color), opacity);
    ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), opacity);
    ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), opacity);
}
void DrawCorneredTriangle(int x, int y, int w, int h, ImColor color, int thickness)
{
    ImDrawList* DrawList = ImGui::GetOverlayDrawList();
    float half_w = w / 2;
    DrawList->AddLine(ImVec2(x, y + h), ImVec2(x + half_w, y), color, thickness);
    DrawList->AddLine(ImVec2(x + half_w, y), ImVec2(x + w, y + h), color, thickness);
    DrawList->AddLine(ImVec2(x, y + h), ImVec2(x + w, y + h), color, thickness);
}
ImU32 RGBtoU32(int r, int g, int b)
{
    float fr = (float)r / 255.0;
    float fg = (float)g / 255.0;
    float fb = (float)b / 255.0;
    return ImGui::GetColorU32(ImVec4(fr, fg, fb, 1));
}

struct FCameraCacheEntry
{
    float Timestamp;
    FMinimalViewInfo POV;
};
bool InLobby = false;

void DrawPeople()
{
    int horizontal = 0;
    int vertical = 0;
    GetDesktopResolution(horizontal, vertical);

    float radarWidth = 230;
    float PosDx = 1280;
    float PosDy = 50;
    if (global.DrawFov)
    {
        if (global.FilledFov)
        {
            ImGui::GetOverlayDrawList()->AddCircleFilled(ImVec2(horizontal / 2, vertical / 2), float(global.AimFOV), ImColor(0, 0, 0, 130), global.Shape);
            ImGui::GetOverlayDrawList()->AddCircle(ImVec2(horizontal / 2, vertical / 2), float(global.AimFOV), ImGui::GetColorU32({ global.DrawFOVCircle[0], global.DrawFOVCircle[1], global.DrawFOVCircle[2], 255 }), global.Shape, global.FOVThickness);

        }
        else
        {
            if (global.DrawCircle)
            {
                ImGui::GetOverlayDrawList()->AddCircle(ImVec2(horizontal / 2, vertical / 2), float(global.AimFOV), ImGui::GetColorU32({ global.DrawFOVCircle[0], global.DrawFOVCircle[1], global.DrawFOVCircle[2], 255 }), global.Shape, global.FOVThickness);
                //if (global.DrawSquare)
                //{
                //    ImGui::GetOverlayDrawList()->AddRect(ImVec2(horizontal / 2 - global.AimFOV, vertical / 2 - global.AimFOV), ImVec2(horizontal / 2 + global.AimFOV, vertical / 2 + global.AimFOV), ImGui::GetColorU32({ global.DrawFOVCircle[0], global.DrawFOVCircle[1], global.DrawFOVCircle[2], 255 }), 3.4, 15, global.FOVThickness);
                //}
                //else
                //{
                //    ImGui::GetOverlayDrawList()->AddCircle(ImVec2(horizontal / 2, vertical / 2), float(global.AimFOV), ImGui::GetColorU32({ global.DrawFOVCircle[0], global.DrawFOVCircle[1], global.DrawFOVCircle[2], 255 }), global.Shape, global.FOVThickness);
                //}
            }
        }
    }
    if (global.StreamProof)
    {
        SetWindowDisplayAffinity(Window, WDA_EXCLUDEFROMCAPTURE);
    }
    else
    {
        SetWindowDisplayAffinity(Window, !WDA_EXCLUDEFROMCAPTURE);
    }

    if (global.Crosshair)
    {
        if (global.Crosshair2)
        {
            ImGui::GetOverlayDrawList()->AddCircleFilled(ImVec2(horizontal / 2 + 2, vertical / 2 + 3), 3.9, ImGui::GetColorU32({ global.CrossHair[0], global.CrossHair[1], global.CrossHair[2], 255 }));
        }
        else
        {
            ImGui::GetOverlayDrawList()->AddLine(ImVec2(horizontal / 2, vertical / 2), ImVec2(horizontal / 2 - 7, vertical / 2), ImGui::GetColorU32({ global.CrossHair[0], global.CrossHair[1], global.CrossHair[2], 255 }), global.CrossThickness);

            ImGui::GetOverlayDrawList()->AddLine(ImVec2(horizontal / 2, vertical / 2), ImVec2(horizontal / 2 + 7, vertical / 2), ImGui::GetColorU32({ global.CrossHair[0], global.CrossHair[1], global.CrossHair[2], 255 }), global.CrossThickness);

            ImGui::GetOverlayDrawList()->AddLine(ImVec2(horizontal / 2, vertical / 2), ImVec2(horizontal / 2, vertical / 2 - 7), ImGui::GetColorU32({ global.CrossHair[0], global.CrossHair[1], global.CrossHair[2], 255 }), global.CrossThickness); //change 10

            ImGui::GetOverlayDrawList()->AddLine(ImVec2(horizontal/ 2, vertical / 2), ImVec2(horizontal / 2, vertical / 2 + 7), ImGui::GetColorU32({ global.CrossHair[0], global.CrossHair[1], global.CrossHair[2], 255 }), global.CrossThickness); //change 10
        }
    }



    char dist[64];
    sprintf_s(dist, "\n", ImGui::GetIO().Framerate);
    ImGui::GetOverlayDrawList()->AddText(ImVec2(15, 15), ImGui::GetColorU32({ color.Black[0], color.Black[1], color.Black[2], 4.0f }), dist);

    auto entityListCopy = entityList;
    float closestDistance = FLT_MAX;
    DWORD_PTR closestPawn = NULL;

    for (unsigned long i = 0; i < entityListCopy.size(); ++i) {
        FNlEntity entity = entityListCopy[i];

#define Mesh 0x310
        uint64_t CurrentActor = entity.Actor;
        uint64_t Mesh2 = rpm<uint64_t>(CurrentActor + Mesh);

        uint64_t CurActorRootComponent = rpm<uint64_t>(entity.Actor + 0x190);
        //if (CurActorRootComponent == (uint64_t)nullptr || CurActorRootComponent == -1 || CurActorRootComponent == NULL)
        //	continue;

        Vector3 actorpos = rpm<Vector3>(CurActorRootComponent + 0x128);


        //std::cout << "Position X: " << actorpos.x << " Position Y: " << actorpos.y << " Position Z: " << actorpos.z << std::endl;

        Vector3 actorposW2s = ProjectWorldToTheScreen(actorpos);

        if (!LocalPawns)
        {
            ImGui::GetOverlayDrawList()->AddLine(ImVec2(1920 / 2, 1080 / 2), ImVec2(actorposW2s.x, actorposW2s.y), ImColor(255, 0, 255), 0.4);
        }

        if (Rootcomps)
        {
            IsAlive = "In Game > True";
        }
        else
        {
            IsAlive = "In Game > False";
        }




        //ImGui::GetOverlayDrawList()->AddLine(ImVec2(1920 / 2, 1080 / 2), ImVec2(actorposW2s.x, actorposW2s.y), ImColor(255, 0, 0), 1);



        //std::cout << " actorposW2s x: " << actorposW2s.x << std::endl;
        //std::cout << " actorposW2s y: " << actorposW2s.y << std::endl;
        //std::cout << " actorposW2s z: " << actorposW2s.z << std::endl;

        DWORD64 otherPlayerState = rpm<uint64_t>(entity.Actor + 0x2A8);
        if (otherPlayerState == (uint64_t)nullptr || otherPlayerState == -1 || otherPlayerState == NULL)
            continue;

        lactorpossssition = rpm<Vector3>(Rootcomps + 0x128);//0x11c



        Vector3 bone66 = GetBoneWithRotation(entity.mesh, 66);
        Vector3 bone0 = GetBoneWithRotation(entity.mesh, 0);

        Vector3 top = ProjectWorldToTheScreen(bone66);
        Vector3 chest = ProjectWorldToTheScreen(bone66);
        Vector3 aimbotspot = ProjectWorldToTheScreen(bone66);
        Vector3 bottom = ProjectWorldToTheScreen(bone0);

        Vector3 Head = ProjectWorldToTheScreen(Vector3(bone66.x, bone66.y, bone66.z + 15));

        Vector3 Screen0 = ProjectWorldToTheScreen({ 0,0,0 });

        Vector3 RelativeInternalLocation = rpm<Vector3>(Rootcomps + 0x128);
        if (!RelativeInternalLocation.x && !RelativeInternalLocation.y) {
            continue;
        }

        Vector3 RelativeScreenLocation = ProjectWorldToTheScreen(RelativeInternalLocation);
        if (!RelativeScreenLocation.x && !RelativeScreenLocation.y) {
            continue;
        }

        /*
        * Debugging #2
        *
        */
       // std::cout << "X: " << Screen0.x << " Y: " << Screen0.y << " Z: " << Screen0.z << std::endl;

        //ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(Screen0.x, Screen0.y), ImGui::GetColorU32({ 0, 255, 0, 1.0f }), global.Thickness);
        

        Persistentlevels = rpm<uint64_t>(Uworlds + 0x30);


        uint64_t ActorList = rpm<uint64_t>(Persistentlevels + 0x98);
        uint32_t ActorCount = rpm<uint64_t>(Persistentlevels + 0xA0);


        if (Head.x == NULL || Head.y == 0)
        {
            break;
        }




        float BoxHeight = (float)(Head.y - bottom.y);
        float CornerHeight = abs(Head.y - bottom.y);
        float CornerWidth = BoxHeight * 0.80;
        int myteam = rpm<int>(PlayerStates + OFFSET_TEAM);//LocalPawn
        int PlayerTeam = rpm<int>(rpm<uint64_t>(CurrentActor + 0x2A8) + OFFSET_TEAM);//CurrentActor

        auto NPC = color.Red;
        if (myteam != PlayerTeam)
        {

            if (global.Radar)
            {


            }

            if (global.Esp_line)
            {
                //ImGui::GetOverlayDrawList()->AddLine(ImVec2(SM_CYSCREEN, SM_CXSCREEN), ImVec2(bottom.x - 5, bottom.y - 5), ImGui::GetColorU32({ 0, 0, 0, 255 }), global.ThicknessSnaps);
                //
                // 	ImGui::GetForegroundDrawList()->AddLine(
                if (Menu_SnapPos == 0)
                {
                    //TOP
                    ImGui::GetOverlayDrawList()->AddLine(ImVec2(horizontal / 2, 0), ImVec2(top.x, top.y), ImColor(global.SkeletonColor[0], global.SkeletonColor[1], global.SkeletonColor[2]), global.ThicknessSnaps);
                }
                if (Menu_SnapPos == 1)
                {
                    //BOTTOM
                    ImGui::GetOverlayDrawList()->AddLine(ImVec2(horizontal / 2, vertical), ImVec2(bottom.x, bottom.y), ImColor(global.SkeletonColor[0], global.SkeletonColor[1], global.SkeletonColor[2]), global.ThicknessSnaps);

                }
                if (Menu_SnapPos == 2)
                {
                    //CENTER
                    ImGui::GetOverlayDrawList()->AddLine(ImVec2(horizontal / 2, vertical / 2), ImVec2(top.x, top.y), ImColor(global.SkeletonColor[0], global.SkeletonColor[1], global.SkeletonColor[2]), global.ThicknessSnaps);

                }


            }
            if (global.Esp_Skel)
            {


                Vector3 vHeadBone = GetBoneWithRotation(entity.mesh, 98);
                Vector3 vHip = GetBoneWithRotation(entity.mesh, 2);
                Vector3 vNeck = GetBoneWithRotation(entity.mesh, 66);
                Vector3 vUpperArmLeft = GetBoneWithRotation(entity.mesh, 9);
                Vector3 vUpperArmRight = GetBoneWithRotation(entity.mesh, 38);
                Vector3 vLeftHand = GetBoneWithRotation(entity.mesh, 10);
                Vector3 vRightHand = GetBoneWithRotation(entity.mesh, 39);
                Vector3 vLeftHand1 = GetBoneWithRotation(entity.mesh, 11);
                Vector3 vRightHand1 = GetBoneWithRotation(entity.mesh, 40);
                Vector3 vRightThigh = GetBoneWithRotation(entity.mesh, 77);
                Vector3 vLeftThigh = GetBoneWithRotation(entity.mesh, 84);
                Vector3 vRightCalf = GetBoneWithRotation(entity.mesh, 73);
                Vector3 vLeftCalf = GetBoneWithRotation(entity.mesh, 80);
                Vector3 vLeftFoot = GetBoneWithRotation(entity.mesh, 82);
                Vector3 vRightFoot = GetBoneWithRotation(entity.mesh, 86);
                Vector3 vHeadBoneOut = ProjectWorldToTheScreen(vHeadBone);
                Vector3 vHipOut = ProjectWorldToTheScreen(vHip);
                Vector3 vNeckOut = ProjectWorldToTheScreen(vNeck);
                Vector3 vUpperArmLeftOut = ProjectWorldToTheScreen(vUpperArmLeft);
                Vector3 vUpperArmRightOut = ProjectWorldToTheScreen(vUpperArmRight);
                Vector3 vLeftHandOut = ProjectWorldToTheScreen(vLeftHand);
                Vector3 vRightHandOut = ProjectWorldToTheScreen(vRightHand);
                Vector3 vLeftHandOut1 = ProjectWorldToTheScreen(vLeftHand1);
                Vector3 vRightHandOut1 = ProjectWorldToTheScreen(vRightHand1);
                Vector3 vRightThighOut = ProjectWorldToTheScreen(vRightThigh);
                Vector3 vLeftThighOut = ProjectWorldToTheScreen(vLeftThigh);
                Vector3 vRightCalfOut = ProjectWorldToTheScreen(vRightCalf);
                Vector3 vLeftCalfOut = ProjectWorldToTheScreen(vLeftCalf);
                Vector3 vLeftFootOut = ProjectWorldToTheScreen(vLeftFoot);
                Vector3 vRightFootOut = ProjectWorldToTheScreen(vRightFoot);

                ImGui::GetOverlayDrawList()->AddLine(ImVec2(vHipOut.x, vHipOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ImGui::GetColorU32({ 255, 255, 255, 255 }), global.ThicknessSkel);
                ImGui::GetOverlayDrawList()->AddLine(ImVec2(vUpperArmLeftOut.x, vUpperArmLeftOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ImGui::GetColorU32({ 255, 255, 255, 255 }), global.ThicknessSkel);
                ImGui::GetOverlayDrawList()->AddLine(ImVec2(vUpperArmRightOut.x, vUpperArmRightOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ImGui::GetColorU32({ 255, 255, 255, 255 }), global.ThicknessSkel);
                ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftHandOut.x, vLeftHandOut.y), ImVec2(vUpperArmLeftOut.x, vUpperArmLeftOut.y), ImGui::GetColorU32({ 255, 255, 255, 255 }), global.ThicknessSkel);
                ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightHandOut.x, vRightHandOut.y), ImVec2(vUpperArmRightOut.x, vUpperArmRightOut.y), ImGui::GetColorU32({ 255, 255, 255, 255 }), global.ThicknessSkel);
                ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftHandOut.x, vLeftHandOut.y), ImVec2(vLeftHandOut1.x, vLeftHandOut1.y), ImGui::GetColorU32({ 255, 255, 255, 255 }), global.ThicknessSkel);
                ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightHandOut.x, vRightHandOut.y), ImVec2(vRightHandOut1.x, vRightHandOut1.y), ImGui::GetColorU32({ 255, 255, 255, 255 }), global.ThicknessSkel);
                ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftThighOut.x, vLeftThighOut.y), ImVec2(vHipOut.x, vHipOut.y), ImGui::GetColorU32({ 255, 255, 255, 255 }), global.ThicknessSkel);
                ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightThighOut.x, vRightThighOut.y), ImVec2(vHipOut.x, vHipOut.y), ImGui::GetColorU32({ 255, 255, 255, 255 }), global.ThicknessSkel);
                ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftCalfOut.x, vLeftCalfOut.y), ImVec2(vLeftThighOut.x, vLeftThighOut.y), ImGui::GetColorU32({ 255, 255, 255, 255 }), global.ThicknessSkel);
                ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightCalfOut.x, vRightCalfOut.y), ImVec2(vRightThighOut.x, vRightThighOut.y), ImGui::GetColorU32({ 255, 255, 255, 255 }), global.ThicknessSkel);
                ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftFootOut.x, vLeftFootOut.y), ImVec2(vLeftCalfOut.x, vLeftCalfOut.y), ImGui::GetColorU32({ 255, 255, 255, 255 }), global.ThicknessSkel);
                ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightFootOut.x, vRightFootOut.y), ImVec2(vRightCalfOut.x, vRightCalfOut.y), ImGui::GetColorU32({ 255, 255, 255, 255 }), global.ThicknessSkel);
            }
            if (global.Head_dot)
            {
                ImGui::GetOverlayDrawList()->AddCircle(ImVec2(Head.x, Head.y), float(BoxHeight / 25), ImGui::GetColorU32({ global.Headdot[0], global.Headdot[1], global.Headdot[2], global.Transparency }), 50);
            }

            if (global.muzzle)
            {
                uintptr_t CurrentWeapon = rpm<uintptr_t>(LocalPawns + 0x8F8); // current weapon
                Aim3(closestPawn, CurrentWeapon, Menu_AimBoneInt);
            }


            if (global.Esp_box_fill)
            {
                if (Head.x != 0 || Head.y != 0 || Head.z != 0)
                {
                    ImU32 ESPSkeleton;

                    ESPSkeleton = ImGui::GetColorU32({ global.Espbox[0],global.Espbox[1],global.Espbox[2], 255 });

                    Vector3 bottom1 = ProjectWorldToTheScreen(Vector3(bone0.x + 40, bone0.y - 40, bone0.z));
                    Vector3 bottom2 = ProjectWorldToTheScreen(Vector3(bone0.x - 40, bone0.y - 40, bone0.z));
                    Vector3 bottom3 = ProjectWorldToTheScreen(Vector3(bone0.x - 40, bone0.y + 40, bone0.z));
                    Vector3 bottom4 = ProjectWorldToTheScreen(Vector3(bone0.x + 40, bone0.y + 40, bone0.z));

                    Vector3 top1 = ProjectWorldToTheScreen(Vector3(bone66.x + 40, bone66.y - 40, bone66.z + 15));
                    Vector3 top2 = ProjectWorldToTheScreen(Vector3(bone66.x - 40, bone66.y - 40, bone66.z + 15));
                    Vector3 top3 = ProjectWorldToTheScreen(Vector3(bone66.x - 40, bone66.y + 40, bone66.z + 15));
                    Vector3 top4 = ProjectWorldToTheScreen(Vector3(bone66.x + 40, bone66.y + 40, bone66.z + 15));

                    ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(top1.x, top1.y), ESPSkeleton, 0.8f);
                    ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(top2.x, top2.y), ESPSkeleton, 0.8f);
                    ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(top3.x, top3.y), ESPSkeleton, 0.8f);
                    ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(top4.x, top4.y), ESPSkeleton, 0.8f);

                    ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(bottom2.x, bottom2.y), ESPSkeleton, 0.8f);
                    ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(bottom3.x, bottom3.y), ESPSkeleton, 0.8f);
                    ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(bottom4.x, bottom4.y), ESPSkeleton, 0.8f);
                    ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(bottom1.x, bottom1.y), ESPSkeleton, 0.8f);

                    ImGui::GetOverlayDrawList()->AddLine(ImVec2(top1.x, top1.y), ImVec2(top2.x, top2.y), ESPSkeleton, 0.8f);
                    ImGui::GetOverlayDrawList()->AddLine(ImVec2(top2.x, top2.y), ImVec2(top3.x, top3.y), ESPSkeleton, 0.8f);
                    ImGui::GetOverlayDrawList()->AddLine(ImVec2(top3.x, top3.y), ImVec2(top4.x, top4.y), ESPSkeleton, 0.8f);
                    ImGui::GetOverlayDrawList()->AddLine(ImVec2(top4.x, top4.y), ImVec2(top1.x, top1.y), ESPSkeleton, 0.8f);

                }
            }

            if (global.triangle)
            {
                if (isVisible(Mesh2))
                {
                    DrawCorneredTriangle(Head.x - (CornerWidth / 2), Head.y, CornerWidth, CornerHeight, RGBtoU32(255, 255, 255), global.BoxThickness);
                }
            }

            if (global.Radar)
            {
                add_players_radar(bone0);
            }

            if (global.Esp_box)
            {                   
                    float BoxWidth = BoxHeight * 0.46;

                    ImGui::GetOverlayDrawList()->AddRect(ImVec2(Head.x - (BoxWidth / 2), Head.y), ImVec2(bottom.x + (BoxWidth / 2), bottom.y), ImColor(0, 0, 0, 255), 0, 0, global.BoxThickness + 3);
                    ImGui::GetOverlayDrawList()->AddRect(ImVec2(Head.x - (BoxWidth / 2), Head.y), ImVec2(bottom.x + (BoxWidth / 2), bottom.y), ImGui::GetColorU32({ global.Espbox[0], global.Espbox[1], global.Espbox[2], 255 }), 0, 0, global.BoxThickness);//50, 168, 82   
            }
            if (global.Esp_Corner_Box)
            {

                draw_cornered_box(Head.x - (CornerWidth / 2), Head.y, CornerWidth, CornerHeight, ImColor(255, 0, 0, 255), global.BoxThickness);
                draw_cornered_box(Head.x - (CornerWidth / 2), Head.y, CornerWidth, CornerHeight, ImGui::GetColorU32({ global.Espbox[0],global.Espbox[1],global.Espbox[2], 255 }), global.BoxThickness);
            }

            if (global.Esp_Circle_Fill) {
                ImGui::GetOverlayDrawList()->AddCircleFilled(ImVec2(Head.x, Head.y), float(BoxHeight), ImGui::GetColorU32({ global.EspCircleFill[0], global.EspCircleFill[1], global.EspCircleFill[2], global.Transparency }), global.Shape);
            }
            if (global.Esp_Circle) {
                ImGui::GetOverlayDrawList()->AddCircle(ImVec2(Head.x, Head.y), float(BoxHeight), ImGui::GetColorU32({ global.EspCircle[0], global.EspCircle[1], global.EspCircle[2], 1.0f }), global.Shape, global.Thickness);
            }
            if (global.Distance_Esp)
            {
                char name[64];
                float distance = lactorpossssition.Distance(bone66) / 100.f;
                char dist[255];
                sprintf_s(name, "[ %.f m ]\n", distance);
                
                DrawOutlinedText(ImGui::GetFont(), name, ImVec2(top.x - 15, top.y - 20), 15, ImColor(255, 255, 255, 255), 0);
            }
        }

        if (global.Aimbot) {
            auto dx = aimbotspot.x - (Width / 2);
            auto dy = aimbotspot.y - (Height / 2);
            auto dz = aimbotspot.z - (Depth / 2);
            auto dist = sqrtf(dx * dx + dy * dy + dz * dz) / 100.0f;
            if (dist < global.AimFOV && dist < closestDistance)
            {

                if (global.glow)
                {
                    if (global.vischeck)
                    {
                        if (isVisible(Mesh2))
                        {
                            closestPawn = entity.Actor;
                            redd = 255;
                            greenn = 0;
                            bluee = 0;
                            IsOnScreen = "Yes";
                        }
                        else
                        {
                            redd = 0;
                            greenn = 255;
                            bluee = 0;
                            IsOnScreen = "No";
                        }
                    }
                    else
                    {
                        closestPawn = entity.Actor;
                    }
                }
                else
                {
                    closestDistance = dist;
                    int myteam = rpm<int>(PlayerStates + OFFSET_TEAM);//LocalPawn
                    int PlayerTeam = rpm<int>(rpm<uint64_t>(CurrentActor + 0x2A8) + OFFSET_TEAM);//CurrentActor
                    {
                        {
                            //std::cout << "MyTeam: " << myteam << std::endl;
                            if (myteam == PlayerTeam)
                            {

                            }
                            else
                            {
                                if (global.vischeck)
                                {
                                    if (isVisible(Mesh2))
                                    {
                                        closestPawn = entity.Actor;
                                        redd = 255;
                                        greenn = 0;
                                        bluee = 0;
                                        IsOnScreen = "Yes";
                                    }
                                    else
                                    {
                                        redd = 0;
                                        greenn = 255;
                                        bluee = 0;
                                        IsOnScreen = "No";
                                    }
                                }
                                else
                                {
                                    closestPawn = entity.Actor;
                                }
                            }
                        }
                    }
                }

            }
        }
        if (global.Bigplayer)
        {
            Vector3 EnemyScale = rpm<Vector3>(Rootcomps + 0x158);//RootComp
            //USceneComponent	RelativeScale3D	0x158	FVector
            wpm<Vector3>(Mesh2 + 0x158, Vector3(EnemyScale.x * 3.1, EnemyScale.y * 3.1, EnemyScale.z * 3.1));//maybe 0x17C
        }
        if (global.playertp)
        {
            uint64_t CurrentWeapon = rpm<uint64_t>(LocalPawns + 0x8d8);
            // USkinnedMeshComponent	bForceWireframe : 1	0x7ae	char
             //wpm<char>(Rootcomps + 0x7ae, true);
            if (GetAsyncKeyState(VK_LSHIFT))
            {
                if (lactorpossssition.Distance(bone0) / 100.f <= 10)
                {
                    Vector3 mypos = rpm<Vector3>(Rootcomps + 0x128);
                    wpm<Vector3>(CurActorRootComponent + 0x128, Vector3(mypos.x, mypos.y, mypos.z));
                }
                else
                {
                }
            }
        }

        // Vector3 bone662 = GetBoneWithRotation(entity.mesh, 66);

         //Location = Vector3(vCameras.Locations.x, vCameras.Locations.y, vCameras.Locations.z);

         //uint64_t currentactormesh = drivers.read<uint64_t>(closestPawn + 0x310);
         //Vector3 TargetPosition = GetBoneWithRotation(currentactormesh, 66);
         //Vector3 TargetPositionToScreen = ProjectWorldToTheScreen(TargetPosition);

         //uintptr_t CurrentWeapon = drivers.read<uintptr_t>(LocalPawns + 0x8f0);
         //uintptr_t PlayerCameraManager = drivers.read<uintptr_t>(PlayerControllers + 0x340);

         //uintptr_t ViewYawMin = 0x331c; // APlayerCameraManager - ViewYawMin - 0x331c
         //uintptr_t ViewYawMax = 0x3320; // APlayerCameraManager - ViewYawMax - 0x3320
         //uintptr_t AimPitchMin = 0x10c8; // AFortWeaponRanged - AimPitchMin - 0x10c0
         //uintptr_t AimPitchMax = 0x10cc; // AFortWeaponRanged - AimPitchMax - 0x10c4


         //if (global.playertp && GetAsyncKeyState(VK_RBUTTON) <= global.AimFOV * 1)
         //{
         //   // std::cout << "Camera Location X: " << vCameras.Locations.x << "\nCamera Location Y: " << vCameras.Locations.y << "\nCamera Location Z: " << vCameras.Locations.z << std::endl;




         //    if (TargetPositionToScreen.x != 0 || TargetPositionToScreen.y != 0 || TargetPositionToScreen.z != 0)
         //    {
         //        if (CurrentWeapon && PlayerCameraManager)
         //        {
         //            Vector3 NewRotation = CalculateNewRotation(Location, TargetPosition);

         //            ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(TargetPositionToScreen.x, TargetPositionToScreen.y), ImGui::GetColorU32({ global.LineESP[0], global.LineESP[1], global.LineESP[2], 1.0f }), global.Thickness);


         //            static float OrginalPitchMin = rpm<float>(PlayerCameraManager + ViewYawMin);
         //            static float OrginalPitchMax = rpm<float>(PlayerCameraManager + ViewYawMax);

         //            wpm<float>(CurrentWeapon + AimPitchMin, NewRotation.x);
         //            wpm<float>(CurrentWeapon + AimPitchMax, NewRotation.x);

         //            wpm<float>(PlayerCameraManager + ViewYawMin, NewRotation.y);
         //            wpm<float>(PlayerCameraManager + ViewYawMax, NewRotation.y);


         //  
         //            std::this_thread::sleep_for(std::chrono::milliseconds(5));

         //            wpm<float>(PlayerCameraManager + ViewYawMin, OrginalPitchMin);
         //            wpm<float>(PlayerCameraManager + ViewYawMax, OrginalPitchMax);
         //        }
         //    }
         //}



        if (global.tpplayer)
        {
            int myteam = rpm<int>(PlayerStates + OFFSET_TEAM);//TEAMINDEX
            int PlayerTeam = rpm<int>(rpm<uint64_t>(CurrentActor + 0x2A8) + OFFSET_TEAM);//TEAMINDEX
            {
                {
                    //std::cout << "MyTeam: " << myteam << std::endl;
                    if (myteam == PlayerTeam)
                    {

                    }
                    else
                    {
                        if (GetAsyncKeyState(VK_SHIFT))
                        {
    //                        static const char* TPs_Pos[]{
    //"   TP ABOVE",
    //"   TP RIGHT",
    //"   TP LEFT"
    //                        };

                            if (Menu_TPPos == 0)
                            {
                                Vector3 mypos = rpm<Vector3>(CurActorRootComponent + 0x128);

                                wpm<Vector3>(CurActorRootComponent + 0x128, Vector3(mypos.x, mypos.y, mypos.z + 35));
                            }
                            else if (Menu_TPPos == 1)
                            {
                                Vector3 mypos = rpm<Vector3>(CurActorRootComponent + 0x128);

                                wpm<Vector3>(CurActorRootComponent + 0x128, Vector3(mypos.x, mypos.y + 25, mypos.z));

                            }
                            else if (Menu_TPPos == 2)
                            {
                                Vector3 mypos = rpm<Vector3>(CurActorRootComponent + 0x128);
                                wpm<Vector3>(CurActorRootComponent + 0x128, Vector3(mypos.x, mypos.y - 25, mypos.z));

                            }
                            else
                            {
                                Vector3 mypos = rpm<Vector3>(CurActorRootComponent + 0x128);

                                wpm<Vector3>(CurActorRootComponent + 0x128, Vector3(mypos.x, mypos.y, mypos.z + 35));
                            }


                        }
                    }
                }
            }
            //uintptr_t CurrentItemPawn = rpm<uintptr_t>(entity.Actor + (i * sizeof(uintptr_t)));
            //uintptr_t ProjectileRootComponent = rpm<uintptr_t>(CurrentItemPawn + 0x190);
            //Vector3 mypos = rpm<Vector3>(CurActorRootComponent + 0x128);
            //wpm<Vector3>(ProjectileRootComponent + 0x128, Vector3(bone66.x, bone66.y, bone66.z));
        }

        if (global.CobraSlice)
        {
            int myteam = rpm<int>(PlayerStates + OFFSET_TEAM);//TEAMINDEX
            int PlayerTeam = rpm<int>(rpm<uint64_t>(CurrentActor + 0x2A8) + OFFSET_TEAM);//TEAMINDEX
            //APlayerState	bIsABot : 1	0x292	char
            uint64_t bIsABot = rpm<char>(PlayerStates + 0x292, true);
            {
                {
                    //std::cout << "MyTeam: " << myteam << std::endl;
                    if (myteam == PlayerTeam)
                    {

                    }
                    else
                    {
                        if (GetAsyncKeyState(VK_LCONTROL))
                        {
                            Vector3 mypos = rpm<Vector3>(Rootcomps + 0x128);

                            wpm<Vector3>(CurActorRootComponent + 0x128, Vector3(mypos.x, mypos.y , mypos.z));
                        }

                    }
                }

            }
        }

       




        if (global.Aiminair)
        {
            //wpm<bool>(LocalPawns + 0x4DD6, true);
        }
        if (global.recoil)
        {
            if (LI_FN(GetAsyncKeyState)(VK_LBUTTON))
            {
               // wpm<float>(PlayerControllers + 0x64, -1); // custom time dilation
            }
        }
        if (global.testing1)
        {
            //Vector3 mypos = rpm<Vector3>(Rootcomps + 0x128);

            //wpm<Vector3>(CurActorRootComponent + 0x128, Vector3(mypos.x, mypos.y + 35, mypos.z));

            //AFortPawn

            uint64_t bIsSliding = rpm<char>(LocalPawns + 0x713, true);

            uint64_t bIsCrouched = rpm<char>(LocalPawns + 0x420, true);

            //APlayerState


            //if (bIsSliding)
            //{
            //    IsSliding = "Is Sliding > True";
            //}
            //else
            //{
            //    IsSliding = "Is Sliding > False";
            //}

            //if (bIsCrouched)
            //{
            //    IsCrouched = "Is Crouched > True";
            //}
            //else
            //{
            //    IsCrouched = "Is Crouched > False";
            //}





            //Vector3 mypos = rpm<Vector3>(Rootcomps + 0x128);

            //wpm<Vector3>(CurActorRootComponent + 0x128, Vector3(mypos.x, mypos.y + 15, mypos.z));



            if (GetAsyncKeyState(VK_SHIFT))
            {



                //AFortAthenaZipline    bInitialized    0xcc8    bool
                //UFortPetAnimInstance	bIsZiplining : 1	0x698	char
             
                //drivers.write<bool>(LocalPawns + 0x698, true);

               // ZiplinePostBegin	FMulticastInlineDelegate	0x2228



               // drivers.write<bool>(LocalPawns + 0x2140 + 0x18, true);
                //drivers.write<float>(LocalPawns + 0x223c, 10.f); // ZiplineSpeedFactor

               // rpm<float>(LocalPawns + 0x223c, 1000.f);//ZiplineSpeedFactor
               // drivers.write<bool>(LocalPawns + 0x2140 + 0x18, true);


                //drivers.write<float>(LocalPawns + 0x21b0, 10.0f); //AFortPlayerPawn    ZiplineJumpStrength    0x1c40    FCurveTableRowHandle
                //drivers.write<bool>(LocalPawns + 0x2140 + 0x18, true);






                //AFortPlayerPawn	ZiplineState	0x2140	FZiplinePawnState


                 

                //AFortPlayerPawn	ZiplineSpeedFactor	0x223c	float
               // drivers.write<float>(LocalPawns + 0x223c, 10.f);
            }
            else
            {
                //drivers.write<bool>(LocalPawns + 0x2140 + 0x18, false);
            }



        }
    }

    if (global.Radar)
    {
        fortnite_radar(radar_position_x, radar_position_y, radar_size, rect_radar);
    }

    if (global.muzzle && GetAsyncKeyState(VK_RBUTTON) < 0)
    {
        uintptr_t CurrentWeapon = rpm<uintptr_t>(LocalPawns + 0x8F8); // current weapon
        wpm<float>(CurrentWeapon + 0x64, 99);
    }
    else if (global.muzzle && !GetAsyncKeyState(VK_RBUTTON)) {
        uintptr_t CurrentWeapon = rpm<uintptr_t>(LocalPawns + CurrentWeapon);
        wpm<float>(CurrentWeapon + 0x64, 1);
    }

    if (global.Aimbot) {
        if (closestPawn != 0) {

            if (global.Aimbot && closestPawn && GetAsyncKeyState(global.aimkey) < 0 or Controller::IsPressingLeftTrigger())
            {
                AimAt(closestPawn);

                if (global.tbot)
                {

                }

                


                //PSILENT

                //Location = Vector3(vCameras.Locations.x, vCameras.Locations.y, vCameras.Locations.z);

                //uint64_t currentactormesh = drivers.read<uint64_t>(closestPawn + 0x310);
                //Vector3 TargetPosition = GetBoneWithRotation(currentactormesh, 66);
                //Vector3 TargetPositionToScreen = ProjectWorldToTheScreen(TargetPosition);

                //uintptr_t CurrentWeapon = drivers.read<uintptr_t>(LocalPawns + 0x8f0);
                //uintptr_t PlayerCameraManager = drivers.read<uintptr_t>(PlayerControllers + 0x340);

                //uintptr_t ViewYawMin = 0x331c; // APlayerCameraManager - ViewYawMin - 0x331c
                //uintptr_t ViewYawMax = 0x3320; // APlayerCameraManager - ViewYawMax - 0x3320
                //uintptr_t AimPitchMin = 0x10c8; // AFortWeaponRanged - AimPitchMin - 0x10c0
                //uintptr_t AimPitchMax = 0x10cc; // AFortWeaponRanged - AimPitchMax - 0x10c4


                //if (global.playertp && GetAsyncKeyState(VK_RBUTTON))
                //{
                //    // std::cout << "Camera Location X: " << vCameras.Locations.x << "\nCamera Location Y: " << vCameras.Locations.y << "\nCamera Location Z: " << vCameras.Locations.z << std::endl;


                //    if (LocalPawns)
                //    {

                //    if (TargetPositionToScreen.x != 0 || TargetPositionToScreen.y != 0 || TargetPositionToScreen.z != 0)
                //    {
                //        if (CurrentWeapon && PlayerCameraManager)
                //        {
                //            Vector3 NewRotation = CalculateNewRotation(Location, TargetPosition);

                //            // ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(TargetPositionToScreen.x, TargetPositionToScreen.y), ImGui::GetColorU32({ global.LineESP[0], global.LineESP[1], global.LineESP[2], 1.0f }), global.Thickness);


                //            static float OrginalPitchMin = rpm<float>(PlayerCameraManager + ViewYawMin);
                //            static float OrginalPitchMax = rpm<float>(PlayerCameraManager + ViewYawMax);

                //            wpm<float>(CurrentWeapon + AimPitchMin, NewRotation.x);
                //            wpm<float>(CurrentWeapon + AimPitchMax, NewRotation.x);

                //            wpm<float>(PlayerCameraManager + ViewYawMin, NewRotation.y);
                //            wpm<float>(PlayerCameraManager + ViewYawMax, NewRotation.y);


                //            std::this_thread::sleep_for(std::chrono::milliseconds(5));

                //            wpm<float>(PlayerCameraManager + ViewYawMin, OrginalPitchMin);
                //            wpm<float>(PlayerCameraManager + ViewYawMax, OrginalPitchMax);

                //            wpm<float>(CurrentWeapon + AimPitchMin, OrginalPitchMin);
                //            wpm<float>(CurrentWeapon + AimPitchMax, OrginalPitchMax);
                //        }
                //        }
                //    }
                //}

                //PSILENT




                //AIM
            }
            else {
                isabting = false;
                AimAt2(closestPawn);
            }
        }
    }
}

namespace Globals
{
    static bool Open = true;
    static int Tab = 0;

}

void render() {
    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;

    ImGui::GetOverlayDrawList()->AddText(ImVec2(10, 10), ImGui::GetColorU32({ 255, 255, 255, 255 }), XorStr("> discord.gg/deepware").c_str());

    //ImGui::GetOverlayDrawList()->AddRectFilled()
   // ImGui::GetOverlayDrawList()->AddRect(ImVec2(255, 255), ImVec2(15, 70), ImColor({ 255, 0, 0, 255 }) , 3.4, 0, 1);
   // ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(255, 255), ImVec2(15, 70), ImColor({ 45, 45, 54, 255 }), 3.4, 0);

    if (global.menu) {


        static POINT Mouse;
        GetCursorPos(&Mouse);

        ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(Mouse.x, Mouse.y), ImVec2(Mouse.x + 8, Mouse.y + 8), ImGui::GetColorU32({ 255, 25, 25, 255 }));



        ImGui::SetNextWindowSize({ 700, 370 });//610, 440

        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
        ImGuiStyle* style = &ImGui::GetStyle();

       // style->WindowPadding = ImVec2(15, 15);
        style->WindowRounding = 1.5f;
        //style->FramePadding = ImVec2(5, 5);
        style->FrameRounding = 1.5f;

        //style->ItemSpacing = ImVec2(12, 8);
       //style->ItemInnerSpacing = ImVec2(8, 6);
        style->IndentSpacing = 25.0f;
        //style->ScrollbarSize = 15.0f;
        //style->GrabMinSize = 10.0f;

        style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
        style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.86f, 0.93f, 0.89f, 1.00f);
        style->Colors[ImGuiCol_WindowBg] = ImVec4(0.13f, 0.14f, 0.17f, 1.00f);
        style->Colors[ImGuiCol_Border] = ImColor(249, 5, 249);
        style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        style->Colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
        style->Colors[ImGuiCol_FrameBgHovered] = ImColor(229, 5, 229);
        style->Colors[ImGuiCol_FrameBgActive] = ImColor(229, 5, 229);
        style->Colors[ImGuiCol_TitleBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
        style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
        style->Colors[ImGuiCol_TitleBgActive] = ImColor(229, 5, 229);
        style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
        style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
        style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.09f, 0.15f, 0.16f, 1.00f);
        style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImColor(229, 5, 229);
        style->Colors[ImGuiCol_ScrollbarGrabActive] = ImColor(229, 5, 229);
        style->Colors[ImGuiCol_CheckMark] = ImColor(229, 5, 229);
        style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
        style->Colors[ImGuiCol_SliderGrabActive] = ImColor(229, 5, 229);
        style->Colors[ImGuiCol_Button] = ImColor(249, 5, 249, 255);
        style->Colors[ImGuiCol_ButtonHovered] = ImColor(229, 5, 229);
        style->Colors[ImGuiCol_ButtonActive] = ImColor(229, 5, 229);
        style->Colors[ImGuiCol_Header] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
        style->Colors[ImGuiCol_HeaderHovered] = ImColor(229, 5, 229);
        style->Colors[ImGuiCol_HeaderActive] = ImColor(229, 5, 229);
        style->Colors[ImGuiCol_Separator] = ImVec4(0.14f, 0.16f, 0.19f, 1.00f);
        style->Colors[ImGuiCol_SeparatorHovered] = ImColor(229, 5, 229);
        style->Colors[ImGuiCol_SeparatorActive] = ImColor(229, 5, 229);
        style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.47f, 0.77f, 0.83f, 0.04f);
        style->Colors[ImGuiCol_ResizeGripHovered] = ImColor(229, 5, 229);
        style->Colors[ImGuiCol_ResizeGripActive] = ImColor(229, 5, 229);
        style->Colors[ImGuiCol_PlotLines] = ImVec4(0.86f, 0.93f, 0.89f, 1.00f);
        style->Colors[ImGuiCol_PlotLinesHovered] = ImColor(229, 5, 229);
        style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.86f, 0.93f, 0.89f, 1.00f);
        style->Colors[ImGuiCol_PlotHistogramHovered] = ImColor(229, 5, 229);
        style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
        style->Colors[ImGuiCol_PopupBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
        style->Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
       
        {

            ImGui::SetNextWindowSize({ 700, 370 });//610, 440
            char dist[64];

            ImGui::Begin(XorStr("DeepWare").c_str(), 0, ImGuiWindowFlags_::ImGuiWindowFlags_NoResize | ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);
            ImGui::Text(XorStr("[INSERT TO TOGGLE MENU] ").c_str());
            ImGui::Separator();
            ImGui::Columns(2);
            ImGui::SetColumnOffset(1, 100);
            {
                if (ImGui::Button(ICON_FA_HOME "", ImVec2(100 - 15, 41)))
                    Globals::Tab = 0;
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Dashboard").c_str());
                    ImGui::EndTooltip();
                }
                if (ImGui::Button(ICON_FA_STREET_VIEW "", ImVec2(100 - 15, 41)))
                    Globals::Tab = 1;
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Aim").c_str());
                    ImGui::EndTooltip();
                }

                if (ImGui::Button(ICON_FA_EYE "", ImVec2(100 - 15, 41)))
                    Globals::Tab = 2;
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Visuals").c_str());
                    ImGui::EndTooltip();
                }
                if (ImGui::Button(ICON_FA_UNLOCK "", ImVec2(100 - 15, 41)))
                    Globals::Tab = 3;
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Exploits").c_str());
                    ImGui::EndTooltip();
                }
                if (ImGui::Button(ICON_FA_SLIDERS_H "", ImVec2(100 - 15, 41)))
                    Globals::Tab = 4;
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Visuals Customization").c_str());
                    ImGui::EndTooltip();
                }
                //if (ImGui::Button(ICON_FA_LINK "", ImVec2(100 - 15, 41)))
                //    system("start https://discord.gg/SpiritFN");
                //if (ImGui::IsItemHovered()) {
                //    ImGui::BeginTooltip();
                //    ImGui::Text(XorStr("Discord").c_str());
                //    ImGui::EndTooltip();
                //}
                if (ImGui::Button(ICON_FA_USER "", ImVec2(100 - 15, 41)))
                    Globals::Tab = 6;
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("User Information").c_str());
                    ImGui::EndTooltip();
                }
                ImGui::Spacing();
            }
            ImGui::NextColumn();

            switch (Globals::Tab)
            {
            case 0:
                ImGui::Text(XorStr("[>] [CHANGELOG] \n \n [04/21/2023] > Updated External \n \n [04/22/2023] Released Fortnite External").c_str());
                break;
            case 1:
                ImGui::Text(XorStr("Aim Settings ").c_str());
                ImGui::Checkbox(XorStr("Aimbot").c_str(), &global.Aimbot);
                ImGui::Combo(XorStr("Bone").c_str(), &Menu_AimBoneInt, AimBone_TypeItems, sizeof(AimBone_TypeItems) / sizeof(*AimBone_TypeItems));
                if (Menu_AimBoneInt == 0) global.hitbox = 66;
                if (Menu_AimBoneInt == 1) global.hitbox = 7;
                if (Menu_AimBoneInt == 2) global.hitbox = 6;
                if (Menu_AimBoneInt == 3) global.hitbox = 3;
                if (Menu_AimBoneInt == 4) global.hitbox = 1;
                ImGui::Combo(XorStr("Aim Key").c_str(), &Menu_AimKey, Aimkey_TypeItems, sizeof(Aimkey_TypeItems) / sizeof(*Aimkey_TypeItems));
                if (Menu_AimKey == 0) global.aimkey = VK_RBUTTON;
                if (Menu_AimKey == 1) global.aimkey = VK_LBUTTON;
                if (Menu_AimKey == 2) global.aimkey = VK_SHIFT;
                if (Menu_AimKey == 3) global.aimkey = VK_CAPITAL;
                if (Menu_AimKey == 4) global.aimkey = VK_CONTROL;
                if (Menu_AimKey == 5) global.aimkey = LVKF_ALT;

                ImGui::Spacing();

                ImGui::Text(XorStr("Aim Misc  ").c_str());
                ImGui::Checkbox(XorStr("Vis Check ").c_str(), &global.vischeck);
                ImGui::SameLine();
                ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Aim Locks Only If A Player Is Visible").c_str());
                    ImGui::EndTooltip();
                }
                ImGui::Checkbox(XorStr("Aimline").c_str(), &global.Aimline);
                ImGui::SameLine();
                ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Draws A Line To Selected Target").c_str());
                    ImGui::EndTooltip();
                }
                ImGui::Checkbox(XorStr("Muzzle Line").c_str(), &global.muzzle);
                ImGui::SameLine();
                ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Draws A Line From muzzle").c_str());
                    ImGui::EndTooltip();
                }
                //ImGui::Checkbox(XorStr("Muzzle Line").c_str(), &global.muzzle);
                //ImGui::SameLine();
                //ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                //if (ImGui::IsItemHovered()) {
                //    ImGui::BeginTooltip();
                //    ImGui::Text(XorStr("Draws A Line From Muzzle To Closest Player").c_str());
                //    ImGui::EndTooltip();
                //}
                ImGui::Checkbox(XorStr("Trigger Bot (DISABLED)").c_str(), &global.tbot);
                ImGui::SameLine();
                ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Trigger Bot Allows You To Automaticly Pull The Trigger If An Enemy Is In Your Lock Range!").c_str());
                    ImGui::EndTooltip();
                }
                ImGui::Checkbox(XorStr("FOV").c_str(), &global.DrawFov);
                ImGui::SameLine();
                ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("FOV Circle Is A Circle That Will Lock On To Any Player Inside Of It").c_str());
                    ImGui::EndTooltip();
                }
                ImGui::Checkbox(XorStr("Crosshair").c_str(), &global.Crosshair);
                ImGui::SameLine();
                ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Just A Crosshair").c_str());
                    ImGui::EndTooltip();
                }
                ImGui::SliderFloat(XorStr("Aim Fov").c_str(), &global.AimFOV, 25, 1600);
                if (global.Aim_Speed)
                {
                    ImGui::SliderFloat(XorStr("Smooth").c_str(), &global.Aim_Speed, 2, 50);
                }
                break;
            case 2:
                ImGui::Text(XorStr("ESP ").c_str());
               // ImGui::Checkbox(XorStr("Radar").c_str(), &global.Radar);
                //if (ImGui::Checkbox(XorStr("Glow").c_str(), &global.glow))
                //{
                //	global.Esp_box_fill = false;
                //	global.Esp_box = false;
                //	global.Esp_Corner_Box = false;
                //}
                if (ImGui::Checkbox(XorStr("3D Box").c_str(), &global.Esp_box_fill))
                {
                    global.glow = false;
                    global.Esp_box = false;
                    global.Esp_Corner_Box = false;

                }
                ImGui::SameLine();
                ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Draws A 3D Box Around A Player").c_str());
                    ImGui::EndTooltip();
                }

                if (ImGui::Checkbox(XorStr("2D Box").c_str(), &global.Esp_box))
                {
                    global.glow = false;
                    global.Esp_box_fill = false;
                    global.Esp_Corner_Box = false;
                }
                ImGui::SameLine();
                ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Draws A 2D Box Around A Player").c_str());
                    ImGui::EndTooltip();
                }
                if (ImGui::Checkbox(XorStr("Corner Box").c_str(), &global.Esp_Corner_Box))
                {
                    global.Esp_box_fill = false;
                    global.Esp_box = false;
                    global.glow = false;


                }
                ImGui::SameLine();
                ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Draws A Edged Box Around A Player").c_str());
                    ImGui::EndTooltip();
                }
                if (ImGui::Checkbox(XorStr("Triangle Esp").c_str(), &global.triangle))
                {
                    global.Esp_box_fill = false;
                    global.Esp_box = false;
                    global.glow = false;
                    global.Esp_Corner_Box = false;


                }
                ImGui::SameLine();
                ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Draws A Edged Box Around A Player").c_str());
                    ImGui::EndTooltip();
                }
                ImGui::Checkbox(XorStr("Distance").c_str(), &global.Distance_Esp);
                ImGui::SameLine();
                ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Displays The Distance Of A Player").c_str());
                    ImGui::EndTooltip();
                }
                ImGui::Checkbox(XorStr("Skeleton").c_str(), &global.Esp_Skel);
                ImGui::SameLine();
                ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Draws A Skeleton On A Player").c_str());
                    ImGui::EndTooltip();
                }
                ImGui::Checkbox(XorStr("Snaplines ").c_str(), &global.Esp_line);
                ImGui::SameLine();
                ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Draws Lines To Players").c_str());
                    ImGui::EndTooltip();
                }
                ImGui::SameLine();
                ImGui::Combo(XorStr("Bone").c_str(), &Menu_SnapPos, Snaplines_Pos, sizeof(Snaplines_Pos) / sizeof(*Snaplines_Pos));


                ImGui::Checkbox(XorStr("Glow Esp").c_str(), &global.glow);
                ImGui::SameLine();
                ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Makes Players Glow!").c_str());
                    ImGui::EndTooltip();
                }
                ImGui::Checkbox(XorStr("Head Dot Esp").c_str(), &global.Head_dot);
                ImGui::SameLine();
                ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Draws A Dot Around Players Head!").c_str());
                    ImGui::EndTooltip();
                }
                ImGui::Checkbox(XorStr("Radar").c_str(), &global.Radar);
                ImGui::SameLine();
                ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Draws Circles Into A Circle").c_str());
                    ImGui::EndTooltip();
                }


                break;
            case 3:
                ImGui::Checkbox(XorStr("Pickaxe TP").c_str(), &global.playertp);
                ImGui::SameLine();
                ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Player needs to be within 10M away and hold SHIFT to teleport and swing pickaxe.").c_str());
                    ImGui::EndTooltip();
                }
                ImGui::Checkbox(XorStr("Player TP").c_str(), &global.tpplayer);
                ImGui::SameLine();
                ImGui::Combo(XorStr("").c_str(), &Menu_TPPos, TPs_Pos, sizeof(TPs_Pos) / sizeof(*TPs_Pos));

               /* ImGui::SameLine();
                ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("HOLD LEFT SHIFT ON YOUR KEYBOARD TO TELEPORT THE ENEMIES TO YOUR PERSON AND SHOOT DOWN WITH A DMR!").c_str());
                    ImGui::EndTooltip();
                }*/
                ImGui::Checkbox(XorStr("Cobra Slice (L CTRL)").c_str(), &global.CobraSlice);
                ImGui::SameLine();
                ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Cobra Slice Allows You To Teleport All Players To You And Kill Them All With A Sword").c_str());
                    ImGui::EndTooltip();
                }
                ImGui::Checkbox(XorStr("Big Players").c_str(), &global.Bigplayer);
                ImGui::SameLine();
                ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Big players expand the player's hitbox but can be buggy @ times.").c_str());
                    ImGui::EndTooltip();
                }
                ImGui::Checkbox(XorStr("Player Fly (Buggy)").c_str(), &global.testing1);
                ImGui::SameLine();
                ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("STOPS WORKING MID MATCH, TURN OFF, USE ZIPLINE, TURN BACK ON").c_str());
                    ImGui::EndTooltip();
                }
                ImGui::Checkbox(XorStr("No Recoil").c_str(), &global.recoil);
                ImGui::SameLine();
                ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("Makes Ur Weapon Have No Recoil").c_str());
                    ImGui::EndTooltip();
                }
                ImGui::Checkbox(XorStr("Aim In Air").c_str(), &global.Aiminair);
                ImGui::SameLine();
                ImGui::TextColored(ImColor(229, 5, 229, 255), XorStr("[?]").c_str());
                if (ImGui::IsItemHovered()) {
                    ImGui::BeginTooltip();
                    ImGui::Text(XorStr("You Can ADS In Air").c_str());
                    ImGui::EndTooltip();
                }
                break;
            case 4:


                ImGui::ColorEdit3(XorStr("Crosshair Color").c_str(), (float*)&global.CrossHair);
                ImGui::ColorEdit3(XorStr("FOV Color").c_str(), (float*)&global.DrawFOVCircle);
                ImGui::ColorEdit3(XorStr("Box Color").c_str(), (float*)&global.Espbox);
                ImGui::ColorEdit3(XorStr("Snaplines Color").c_str(), (float*)&global.SkeletonColor);

                ImGui::SliderFloat(XorStr("Box Thickness").c_str(), &global.BoxThickness, 0.5, 4.4);
                ImGui::SliderFloat(XorStr("CrossHair Thickness").c_str(), &global.CrossThickness, 0.5, 4.4);
                ImGui::SliderFloat(XorStr("FOV Thickness").c_str(), &global.FOVThickness, 0.5, 3.4);
                ImGui::SliderFloat(XorStr("Snapline Thickness").c_str(), &global.ThicknessSnaps, 1, 3);
                ImGui::Text(XorStr("Misc").c_str());
                ImGui::Checkbox(XorStr("Stream Proof").c_str(), &global.StreamProof);
                ImGui::Checkbox(XorStr("Filled FOV").c_str(), &global.FilledFov);
                //ImGui::Checkbox(XorStr("Square FOV").c_str(), &global.DrawSquare);
                ImGui::Checkbox(XorStr("Dot Crosshair").c_str(), &global.Crosshair2);


                break;
            case 5:
                break;
            case 6:
                std::string s = tm_to_readable_time(timet_to_tm(string_to_timet(KeyAuthApp.data.createdate.c_str())));
                std::string s2 = tm_to_readable_time(timet_to_tm(string_to_timet(KeyAuthApp.data.lastlogin.c_str())));
                std::string s3 = tm_to_readable_time(timet_to_tm(string_to_timet(KeyAuthApp.data.expiry.c_str())));
                ImGui::Text(XorStr("Username:").c_str());
                ImGui::SameLine();
                ImGui::Text(KeyAuthApp.data.username.c_str());
                ImGui::Text(XorStr("Last Login:").c_str());
                ImGui::SameLine();
                ImGui::Text(s2.c_str());
                ImGui::Text(XorStr("Account Creation Date:").c_str());
                ImGui::SameLine();
                ImGui::Text(s.c_str());
                ImGui::Text(XorStr("Expiry:").c_str());
                ImGui::SameLine();
                ImGui::Text(s3.c_str());
                ImGui::Text(XorStr("Subscription:").c_str());
                ImGui::SameLine();
                ImGui::Text(XorStr("Fortnite").c_str());
                ImGui::NewLine();
                ImGui::Text(XorStr("press end to unload!").c_str());
                break;
            }
            ImGui::End();
        }
    }

    DrawPeople();

    ImGui::EndFrame();
    D3dDevice->SetRenderState(D3DRS_ZENABLE, false);
    D3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
    D3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
    D3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);

    if (D3dDevice->BeginScene() >= 0) {
        ImGui::Render();
        ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
        D3dDevice->EndScene();
    }
    HRESULT result = D3dDevice->Present(NULL, NULL, NULL, NULL);

    if (result == D3DERR_DEVICELOST && D3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
        ImGui_ImplDX9_InvalidateDeviceObjects();
        D3dDevice->Reset(&d3dpp);
        ImGui_ImplDX9_CreateDeviceObjects();
    }
}

void qaDUOGBVASZ()//initd3d
{
    if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &p_Object)))
        exit(3);

    ZeroMemory(&d3dpp, sizeof(d3dpp));
    d3dpp.BackBufferWidth = Width;
    d3dpp.BackBufferHeight = Height;
    d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
    d3dpp.MultiSampleQuality = D3DMULTISAMPLE_NONE;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.EnableAutoDepthStencil = TRUE;
    d3dpp.hDeviceWindow = Window;
    d3dpp.Windowed = TRUE;

    p_Object->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, Window, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &D3dDevice);

    IMGUI_CHECKVERSION();

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;

    ImGui_ImplWin32_Init(Window);
    ImGui_ImplDX9_Init(D3dDevice);

    ImFontConfig font_config;
    font_config.OversampleH = 1;
    font_config.OversampleV = 1;
    font_config.PixelSnapH = true;

    static const ImWchar ranges[] =
    {
        0x0020, 0x00FF,
        0x0400, 0x044F,
        0,
    };



    static const ImWchar icons_ranges[] = { 0xf000, 0xf3ff, 0 };
    ImFontConfig icons_config;

    io.IniFilename = nullptr;
    io.LogFilename = nullptr;

    icons_config.MergeMode = true;
    icons_config.PixelSnapH = true;
    icons_config.OversampleH = 3;
    icons_config.OversampleV = 3;

    ImFontConfig CustomFont;
    CustomFont.FontDataOwnedByAtlas = false;

    io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Custom), sizeof(Custom), 16.0f, &CustomFont);

    io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 19.0f, &icons_config, icons_ranges);
    io.Fonts->AddFontDefault();

    p_Object->Release();
}


typedef struct tarray
{
    uint64_t data;
    int count;
    int max;
};


int width;
int height;

void EntityLoop(int width, int height)
{
    while (true) {


        std::vector<FNlEntity> tmpList;

        Uworlds = rpm<DWORD_PTR>(base_address + OFFSET_UWORLD);


        //std::cout << std::hex << "0x" << base_address << std::endl;
        //std::cout << std::hex << "0x" << base_address << std::endl;

        std::cout << std::hex << "0x" << Uworlds << std::endl;

        DWORD_PTR Gameinstance = rpm<DWORD_PTR>(Uworlds + 0x1b8);
        DWORD_PTR LocalPlayers = rpm<DWORD_PTR>(Gameinstance + 0x38);
        Localplayers = rpm<DWORD_PTR>(LocalPlayers);
        PlayerControllers = rpm<DWORD_PTR>(Localplayers + 0x30);

        LocalPawns = rpm<DWORD_PTR>(PlayerControllers + 0x330);//AcknowledgedPawn

        PlayerStates = rpm<DWORD_PTR>(LocalPawns + 0x2A8);
        Rootcomps = rpm<DWORD_PTR>(LocalPawns + 0x190);

        if (LocalPawns != 0) {
            localplayerID = rpm<int>(LocalPawns + 0x18);
        }
        uint64_t GameStates = rpm<uint64_t>(Uworlds + 0x158);
        tarray PlayerArray = rpm<tarray>(GameStates + 0x2A0);
        for (int i = 0; i < PlayerArray.count; i++)
        {
            uint64_t playerstate = rpm<uint64_t>(PlayerArray.data + i * sizeof(uint64_t));
            uint64_t pawn = rpm<uint64_t>(playerstate + 0x300);//PawnPrivate was 330
            if (pawn == LocalPawns)
            {
                continue;
            }
            FNlEntity fnlEntity{ };
            fnlEntity.Actor = pawn;
            fnlEntity.mesh = rpm<uint64_t>(pawn + 0x310);//mesh
            tmpList.push_back(fnlEntity);
        }
        entityList = tmpList;


        uint64_t bIsSliding = rpm<char>(LocalPawns + 0x713, true);



        /*
        * Debugging #1
        
        std::cout << XorStr("Print World: ").c_str() << Uworlds << std::endl;
        std::cout << XorStr("Game State:").c_str() << GameStates << std::endl;
        std::cout << XorStr("Player Array:").c_str() << PlayerArray.count << std::endl;
        std::cout << XorStr("Player Array Data:").c_str() << PlayerArray.data << std::endl; */
        Sleep(1);
    }


}

void fios()
{
    Sleep(2000);

    MessageBox(NULL, "PRESS OK TO SPOOF AND CLEAN", "[SERENITY SHIELD]", NULL);

    LoadLibraryA(_xor_("User32").c_str());
    if (GlobalFindAtomA(_xor_("spoofcheck").c_str()) == 0) // checks if driver already loaded (resets when windows restarted)
    {
        system("NETSH WINSOCK RESET");
        system("NETSH INT IP RESET");
        system("NETSH INTERFACE IPV4 RESET");
        system("NETSH INTERFACE IPV6 RESET");
        system("NETSH INTERFACE TCP RESET");
        system("IPCONFIG /RELEASE");
        system("IPCONFIG /FLUSHDNS");
        system("NBTSTAT -R");
        system("NBTSTAT -RR");
        system("netsh int ipv6 reset");
        system("netsh winsock reset");
        system("netsh int ip reset");
        system("ipconfig /release");
        system("ipconfig /renew");
        system("cls");

        ShowWindow(GetConsoleWindow(), SW_HIDE);

        std::vector<std::uint8_t> bytes = {};

        bytes = KeyAuthApp.download("118583"); // upload your file to KeyAuth then put driver file ID here


        HANDLE iqvw64e_device_handle2 = intel_driver::Load();

        if (!iqvw64e_device_handle2 || iqvw64e_device_handle2 == INVALID_HANDLE_VALUE)
        {

        }


        if (!kdmapper::MapDriver(iqvw64e_device_handle2, bytes.data()))
        {

        }

        intel_driver::Unload(iqvw64e_device_handle2);

        GlobalAddAtomA(_xor_("spoofcheck").c_str()); // adds atom so we know driver already loaded, and we won't load again until windows restarted

        MessageBox(NULL, XorStr("SUCCESSFULLY SPOOFED!").c_str(), XorStr("FORTNITE").c_str(), NULL);
        Sleep(1500);
        system(_xor_("cls").c_str());

    }
    else
    {
        MessageBox(NULL, XorStr("YOU HAVE ALREADY SPOOFED PLEASE EITHER LAUNCH FORTNITE OR REBOOT AND TRY AGAIN :)").c_str(), XorStr("FORTNITE").c_str(), NULL);
    }

}

std::uint8_t securitythread(client::security security)
{
    while (true)
    {
        security.check();
        Sleep(500);
    }
}

int main() {


        KeyAuthApp.init();

    SetConsoleTitleA("[custom build] INITIALIZING...");
    Sleep(250);
    client::security security = client::security().initialize();
    SetConsoleTitleA("[custom build] INITIALIZING.");
    Sleep(250);
    std::thread security_caller(securitythread, security);
    SetConsoleTitleA("custom build] INITIALIZING..");
    Sleep(250);
    security_caller.detach();
    SetConsoleTitleA("[custom build] INITIALIZING...");
    Sleep(250);
    HANDLE hStdOut24 = GetStdHandle(STD_OUTPUT_HANDLE);

    LI_FN(system)("cls");

    LI_FN(Sleep)(100);

    LI_FN(SetConsoleTextAttribute)(GetStdHandle(-11), 7);



    MessageBoxA(0, XorStr("USER AGREEMENT\n\n\n 1.) TRYING TO CRACK 'deepware' MAY RESULT IN A BAN! \n\n 2.) WE ARE NOT RESPONSIBLE FOR ANY DAMAGES CAUSED (ACCS ETC) \n\n 3.) WE 'DeepWare' HAVE PERMISSION TO BAN YOUR KEY IF WE NOTICE ANY UNUSUAL ACTIVITY! \n\n USER AGREEMENT CAN BE CHANGED AT ANYTIME TO PAY ATTENTION! \n\n BY GOING PASS THIS YOU AGREE TO THE 'USER AGREEMENT'!").c_str(), XorStr("[Serenity Shield]").c_str(), MB_OK);





   // std::string consoleTitle = (std::string)XorStr("discord.gg/SpiritFN on ") + compilation_date + " @ " + compilation_time;
    //SetConsoleTitleA(consoleTitle.c_str());

    LI_FN(system)(XorStr("CLS").c_str());

    std::string s2333333 = XorStr("\n	< -- [+] Checking System Please Be Paitent... -->").c_str();
    int x33333 = 0;
    while (s2333333[x33333] != '\0')
    {
        std::cout << s2333333[x33333];
        LI_FN(Sleep)(35);
        x33333++;
    };
    LI_FN(Sleep)(1500);
    //std::cout << XorStr("[+] Checking System Please Be Paitent").c_str() << std::endl;
    LI_FN(SetConsoleTitleA)("[build] INITIALIZED!");
    LI_FN(Sleep)(1500);
    LI_FN(system)(XorStr("CLS").c_str());

    std::string consoleTitle = (std::string)XorStr("deepware private | Build > ") + compilation_date + " @ " + compilation_time;
    LI_FN(SetConsoleTitleA)(consoleTitle.c_str());
    std::string s233333 = XorStr("\n	< -- [+] Checking Integrity... -->").c_str();
    int x3333 = 0;
    while (s233333[x3333] != '\0')
    { 
        std::cout << s233333[x3333];
        Sleep(35);
        x3333++;
    };
    LI_FN(Sleep)(1500);

    LI_FN(system)(XorStr("CLS").c_str());


    std::string s233 = XorStr("\n	< -- [+] Serenity Shield Started! -->").c_str();
    int x3 = 0;
    while (s233[x3] != '\0')
    {
        std::cout << s233[x3];
        LI_FN(Sleep)(35);
        x3++;
    };
    LI_FN(Sleep)(1500);

    LI_FN(system)(XorStr("CLS").c_str());

    std::string s23 = XorStr("\n	< -- Please Let Us Do The Work... -->").c_str();
    int x = 0;
    while (s23[x] != '\0')
    {
        std::cout << s23[x];
        LI_FN(Sleep)(35);
        x++;
    };
    LI_FN(Sleep)(2500);




    HANDLE hStdOut23 = GetStdHandle(STD_OUTPUT_HANDLE);

    LI_FN(SetConsoleTextAttribute)(hStdOut23, FOREGROUND_GREEN);

    LI_FN(Sleep)(800);


    LI_FN(Sleep)(1000);
    LI_FN(system)(XorStr("CLS").c_str());

    std::string key;


  
    if (std::filesystem::exists(XorStr("C:\\deepware\\license.spirit").c_str())) {
        std::ifstream password_file(XorStr("C:\\deepware\\license.spirit").c_str(), std::ios::in);
        std::getline(password_file, key);
        KeyAuthApp.license(key);
        password_file.close();
        if (!KeyAuthApp.data.success)
        {
            DeleteFileA(XorStr("C:\\deepware\\license.spirit").c_str());
            MessageBoxA(NULL, "YOUR LICENSE HAS EXPIRED AND MAY NO LONGER AUTO LOGIN PLEASE RE-OPEN deepware AND PUT A NEW KEY OR BUY A NEW ONE :)", "[SERENITY SHIELD]", MB_OK);
            LI_FN(exit)(1);
        }
        else
        {
            std::filesystem::create_directories(XorStr("C:\\deepware").c_str());
        }
    }
    else
    { 
        std::cout << XorStr("\n License Key: ");
        std::cin >> key;
        KeyAuthApp.license(key);


        if (!KeyAuthApp.data.success)
        {
            MessageBox(0, XorStr("USER ERROR\n\n\n ERROR LOGGING IN \n\n REASON: INVALID CREDENTIALS").c_str(), XorStr("[Serenity Shield]").c_str(), MB_OK);
            LI_FN(exit)(429);
        }
        else
        {
            if (MessageBox(0, XorStr("USER SUCCESS\n\n\n WELCOME TOdeepware, DO YOU WANNA SAVE YOUR KEY TO SYSTEM? \n\n discord.gg/deepware").c_str(), XorStr("[Serenity Shield]").c_str(), MB_YESNOCANCEL) == IDYES)
            {
                std::filesystem::create_directories(XorStr("C:\\deepware").c_str());
                std::ofstream password_file2(XorStr("C:\\deepwareN\\license.spirit").c_str());
                password_file2 << key;
                password_file2.close();
                MessageBoxA(0, XorStr("USER SUCCESS\n\n\n KEY SAVED! \n\n discord.gg/deepware").c_str(), XorStr("[Serenity Shield]").c_str(), MB_OK);
            }
            else
            {
                MessageBoxA(0, XorStr("USER SUCCESS\n\n\n KEY WAS NOT SAVED! \n\n discord.gg/deepware").c_str(), XorStr("[Serenity Shield]").c_str(), MB_OK);
            }
        }
    }



 
    int choice;
    LI_FN(system)(XorStr("cls").c_str());
    LI_FN(system)(XorStr("color 06").c_str());
    std::cout << XorStr("[1] SPOOF AND CHEAT (NEW)").c_str() << XorStr("\n[2] CHEAT \n[3] EXIT \nInput ---->").c_str();

    std::cin >> choice;


    switch (choice)
    {

    case 1:
    {
        system(_xor_("cls").c_str());
       MessageBoxA(NULL, "Spoofer Is Down For Maintenance", "[SERENITY SHIELD", NULL);
        fios();
    }
    break;
    case 2:
    {
       system(_xor_("cls").c_str());
       ShowWindow(GetConsoleWindow(), SW_HIDE);
    }
    break;
    case 3:
    {
        system(_xor_("cls").c_str());
        exit(1);
    }
    }


    LI_FN(ShowWindow)(GetConsoleWindow(), SW_HIDE);



    LoadLibraryA(XorStr("User32").c_str());
    if (GlobalFindAtomA(XorStr("drivercheck2").c_str()) == 0) // checks if driver already loaded (resets when windows restarted)
    {
        //VIRTUALIZER_EAGLE_BLACK_START

        std::cout << XorStr("\n\n Loading...");

        //KeyAuthApp.check();
        //CHECKS IF KDSTRINKER WAS TRYING TO DUMP YOUR DRIVER

        std::vector<std::uint8_t> bytes = {};

        bytes = KeyAuthApp.download(XorStr("614997").c_str()); // upload your file to KeyAuth then put driver file ID here
        HANDLE iqvw64e_device_handle2 = intel_driver::Load();

        if (!iqvw64e_device_handle2 || iqvw64e_device_handle2 == INVALID_HANDLE_VALUE)
        {

        }

        if (!kdmapper::MapDriver(iqvw64e_device_handle2, bytes.data()))
        {

        }

        intel_driver::Unload(iqvw64e_device_handle2);

        GlobalAddAtomA(XorStr("drivercheck2").c_str()); // adds atom so we know driver already loaded, and we won't load again until windows restarted
    }

   MouseController::Init();

    MessageBoxA(0, XorStr("INFORMATION\n\n\n PLEASE LAUNCH FORTNITE \n\n discord.gg/deepware").c_str(), XorStr("[Serenity Shield]").c_str(), MB_ICONWARNING);

    KeyAuthApp.check();
    Sleep(200);

    ShowWindow(GetConsoleWindow(), SW_HIDE);

    while (hwnd == NULL)
    {
        hwnd = FindWindowA(0, XorStr("Fortnite  ").c_str());


        LI_FN(Sleep)(300);
    }
    GetWindowThreadProcessId(hwnd, (LPDWORD)&pid);

    RECT rect;
    if (GetWindowRect(hwnd, &rect))
    {
        width = rect.right - rect.left;
        height = rect.bottom - rect.top;
    }


    Driver::Init();

    Driver::find_process("FortniteClient-Win64-Shipping.exe");


  //  drivers.DriverAttach(XorStr(L"FortniteClient-Win64-Shipping.exe").c_str());

    base_address = Driver::getbase();

    LI_FN(SetConsoleTitleA)(random_string(20).c_str());
    LI_FN(system)(XorStr("cls").c_str());
    LI_FN(system)(XorStr("color c").c_str());

    LI_FN(SetConsoleTextAttribute)(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);

    std::cout << XorStr("\n\n\n\n [-] Base -> 0x").c_str() << std::hex << base_address << std::endl;

    LI_FN(SetConsoleTextAttribute)(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);

    CreateThread(NULL, NULL, thread, NULL, NULL, NULL);
    GetWindowThreadProcessId(hwnd, (LPDWORD)&pid);

    gikabjkbdjkas();//Create Window
    qaDUOGBVASZ();


    HANDLE han = CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(EntityLoop), nullptr, NULL, nullptr);

   ASHGBFKUSDH();
}

const MARGINS Margin = { -1 };

char genRandom()
{

    return alphanum[rand() % stringLength];
}


void gikabjkbdjkas()
{
    int horizontal = 0;
    int vertical = 0;
    GetDesktopResolution(horizontal, vertical);

    srand(time(0));
    std::string Str;
    for (unsigned int i = 0; i < 10; ++i)
    {
        Str += genRandom();

    }

    WNDCLASSEX wc;
    ZeroMemory(&wc, sizeof(wc));
    wc.cbSize = sizeof(wc);
    wc.lpszClassName = Str.c_str();
    wc.lpfnWndProc = WinProc;
    RegisterClassEx(&wc);

    if (hwnd)
    {
        GetClientRect(hwnd, &GameRect);
        POINT xy;
        ClientToScreen(hwnd, &xy);
        GameRect.left = xy.x;
        GameRect.top = xy.y;

        Width = GameRect.right + 2;
        Height = GameRect.bottom + 2;
    }
    else
        exit(2);

    //	Window = CreateWindowEx(NULL, Str.c_str(), Str.c_str(), WS_POPUP | WS_VISIBLE, -2, -2, 1920 + 2, 1080 + 2, 0, 0, 0, 0);//Str.c_str()


    Window = CreateWindowEx(NULL, Str.c_str(), Str.c_str(), WS_POPUP | WS_VISIBLE, - 3, - 4, horizontal + 2, vertical + 2, 0, 0, 0, 0);//Str.c_str()

    DwmExtendFrameIntoClientArea(Window, &Margin);
    SetWindowLong(Window, GWL_EXSTYLE, WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW | WS_EX_LAYERED);
    ShowWindow(Window, SW_SHOW);
    UpdateWindow(Window);
}

MSG Message = { NULL };

void ASHGBFKUSDH()
{
    static RECT old_rc;
    ZeroMemory(&Message, sizeof(MSG));

    while (Message.message != WM_QUIT)
    {
        if (PeekMessage(&Message, Window, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&Message);
            DispatchMessage(&Message);
        }

        HWND hwnd_active = GetForegroundWindow();

        if (hwnd_active == hwnd) {
            HWND hwndtest = GetWindow(hwnd_active, GW_HWNDPREV);
            LI_FN(SetWindowPos)(Window, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
        }

        if (GetAsyncKeyState(0x23) & 1)
            LI_FN(exit)(8);

        RECT rc;
        POINT xy;

        ZeroMemory(&rc, sizeof(RECT));
        ZeroMemory(&xy, sizeof(POINT));
        GetClientRect(hwnd, &rc);
        ClientToScreen(hwnd, &xy);
        rc.left = xy.x;
        rc.top = xy.y;

        ImGuiIO& io = ImGui::GetIO();
        io.ImeWindowHandle = hwnd;
        io.DeltaTime = 1.0f / 60.0f;

        POINT p;
        GetCursorPos(&p);
        io.MousePos.x = p.x - xy.x;
        io.MousePos.y = p.y - xy.y;

        if (GetAsyncKeyState(VK_LBUTTON)) {
            io.MouseDown[0] = true;
            io.MouseClicked[0] = true;
            io.MouseClickedPos[0].x = io.MousePos.x;
            io.MouseClickedPos[0].x = io.MousePos.y;
        }
        else
            io.MouseDown[0] = false;

        if (rc.left != old_rc.left || rc.right != old_rc.right || rc.top != old_rc.top || rc.bottom != old_rc.bottom)
        {
            old_rc = rc;

            Width = rc.right;
            Height = rc.bottom;

            d3dpp.BackBufferWidth = Width;
            d3dpp.BackBufferHeight = Height;
            //SetWindowPos(Window, (HWND)0, xy.x, xy.y, Width, Height, SWP_NOREDRAW);
            HWND hwndtest = GetWindow(GetForegroundWindow(), GW_HWNDPREV);
            SetWindowPos(Window, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
            D3dDevice->Reset(&d3dpp);
        }
        render();
    }
    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    DestroyWindow(Window);
}


LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, Message, wParam, lParam))
        return true;

    switch (Message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        exit(4);
        break;
    case WM_SIZE:
        if (D3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            ImGui_ImplDX9_InvalidateDeviceObjects();
            d3dpp.BackBufferWidth = LOWORD(lParam);
            d3dpp.BackBufferHeight = HIWORD(lParam);
            HRESULT hr = D3dDevice->Reset(&d3dpp);
            if (hr == D3DERR_INVALIDCALL)
                IM_ASSERT(0);
            ImGui_ImplDX9_CreateDeviceObjects();
        }
        break;
    default:
        return DefWindowProc(hWnd, Message, wParam, lParam);
        break;
    }
    return 0;
}

std::string tm_to_readable_time(tm ctx) {
    char buffer[80];

    strftime(buffer, sizeof(buffer), "%m/%d/%y", &ctx);

    return std::string(buffer);
}

static std::time_t string_to_timet(std::string timestamp) {
    auto cv = strtol(timestamp.c_str(), NULL, 10); // long

    return (time_t)cv;
}

static std::tm timet_to_tm(time_t timestamp) {
    std::tm context;

    localtime_s(&context, &timestamp);

    return context;
}
