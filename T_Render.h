#pragma once
#include "T_Engine/T_GameObject.h"
class T_Render :
    public T_IManager
{
public:
    unique_ptr<Camera> camera;
    void RenderUpdate(HDC hdc);
private:
    
};

class Image :
    public T_Component
{
    unique_ptr<T_Graph> image;

};
/// <summary>
/// С�׳���ԭ���͸��������
/// </summary>
/// ����Ļ����ʾ��Ļ
class Camera :
    public T_Component 
{
public:
    //����Ϊ������ڲ�

    /// <summary>
    /// ����Ļ���������
    /// </summary>
    float closeScreen;
    /// <summary>
    /// Զ��Ļ������ľ���
    /// </summary>
    float farScreen;
    /// <summary>
    /// ����Ļ����ʾ��Ļ����
    /// </summary>
    int screenX;
    /// <summary>
    /// ����Ļ��
    /// </summary>
    int screenY;
    /// <summary>
    /// һ��λ����ת��Ϊ������Ļ���صı���
    /// </summary>
    float screenRate;
    //TODO ��д�����������

    
};
