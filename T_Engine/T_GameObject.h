#pragma once
#include "T_Config.h"
#include "T_Vector3.h"
#include "T_Graph.h"
/*
* 
* ����ECS�ܹ�����ά���
* 
*/

/// <summary>
/// ��Ϸʵ��
/// </summary>
class T_GameObject{
public:
	T_GameObject();
	string name;
	T_Transform transform;
	vector<unique_ptr<T_Component>> componentArray;
	bool isDestroy = false;
	bool isActive = true;

};
/// <summary>
/// �������ӿ�
/// </summary>
class T_IManager {
public:
 	virtual void GetManagerID() = 0;
	virtual void Update() = 0;
	virtual void UpdateLate() = 0;
	virtual void FixedUpdate() = 0;
	virtual void KeyAction(int ActionType) = 0;
	virtual void MouseAction(int x, int y, int ActionType) = 0;
};
/// <summary>
/// ��������
/// </summary>
class T_Scene {
public:
	virtual void LoadScene() = 0;
	unordered_map<int, unique_ptr<T_IManager> > ManagerMap;
};
/// <summary>
/// ��Ϸʵ���������������ID:42
/// </summary>
class T_GameObjectManager:
	public T_IManager
{
public:
	vector<unique_ptr<T_GameObject>> gameObjectArray;
	unique_ptr<T_GameObject>& AddGameObject(unique_ptr<T_GameObject> sprite);
	void ClearGameObject();
	unique_ptr<T_GameObject>& FindGameObject(string name);

};

class T_Component
{
public:
	T_GameObject& gameObject;
	virtual void Start();
	/// <summary>
	/// ÿ֡��Ⱦǰ����һ��
	/// </summary>
	virtual void Update();
	/// <summary>
	/// ÿ֡��Ⱦ�����һ��
	/// </summary>
	virtual void UpdateLate();
	/// <summary>
	/// �̶�ÿ���������
	/// </summary>
	virtual void FixedUpdate();
	/// <summary>
	/// ��Ʒ�ݻ�ǰ����һ��
	/// </summary>
	virtual void OnDestroy();
	/// <summary>
	/// ����������ص���Ϸ������
	/// </summary>
	/// <param name="gameObject">�����ص���Ϸ����</param>
	void JoinTo(unique_ptr<T_GameObject> gameObject);
};
/// <summary>
/// ת��
/// </summary>
class T_Transform {
public:
	T_Vector3 position;
	T_Vector3 rotation;
};

