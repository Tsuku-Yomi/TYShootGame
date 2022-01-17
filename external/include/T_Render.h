#pragma once
#include "T_GameObject.h"
#include "T_Engine.h"
#include "T_Map.h"


class Camera :
        public T_Component
{
public:
    explicit Camera(T_GameObject& tGameObject);
    string GetComponentName()override{return "camera";}
    float cameraFov=1.5;
    void KeyAction(int KeyType, int ActionType)override;
};
class T_Render :
        public T_IManager
{
public:
    explicit T_Render(T_Map& map);
    void Init(int width,int height);
    int GetManagerID() override {return 1;}
    shared_ptr<Camera> camera=nullptr;
    void RenderUpdate(HDC hdc);
    void Update(HDC hdc)override{ RenderUpdate(hdc);}
    void SetRenderVar(int width,int height);
    T_Map& map;
    HBITMAP backgroundBitmap;
    vector<Rast> wallDepth;
    int screenWidth;
    int screenHeight;

    //常量↓
    //最远视域距离
    constexpr static const float MAX_VISIT_LENGHT=5.0;
    //单步长度
    constexpr static const float LENGHT_SINGLE_VISIT_STEP=0.005;


    static const COLORREF SKY_COLOR_UP=RGB(0,191,255);
    static const COLORREF SKY_COLOR_DOWN=RGB(135,206,235);
    //天空分层数
    static const int SKY_LEVEL=5;
    static const COLORREF GROUND=Color::LawnGreen&0x00FFFFFF;


    //静态绘制函数

    void PaintRaster(HDC destDC);

};

class SpriteManager:
        public T_IManager{
public:
    int GetManagerID() override {return 523;}
    vector<T_Component> spriteImageArray;
};

class Sprite :
        public T_Component
{
    unique_ptr<T_Graph> image;

};