#pragma once
#include "T_GameObject.h"
#include <stack>


enum MOUSE {
    LMB = 0,
    RMB = 1
};

class InputManager :
    public T_IManager
{
public:

    int GetManagerID() override {return 4;}

    static InputManager* instance;
    static InputManager& GetInstance(){return *instance;}
    bool isKeyDown[256];
    bool isKeyUp[256];
    T_Vector3 mousePos;
    int isMouseDown[3];

    InputManager();
    /// <summary>
    /// ��ȡ�����Ƿ���ѹ
    /// </summary>
    /// <param name="keyType">��������(�ο�wParam)</param>
    /// <returns></returns>
    bool GetKeyDown(int keyType);
    /// <summary>
    /// ��ȡ�����Ƿ���
    /// </summary>
    /// <param name="keyType">��������(�ο�wParam)</param>
    /// <returns></returns>
    bool GetKeyUp(int keyType);
    T_Vector3 GetMousePos();
    bool GetMouseDown(int keyType);
    bool GetMouseUp(int keyType);
    void KeyAction(int KeyType, int Action) override;
    void MouseAction(int x, int y, int Action) override;
    void Update() override;
};

