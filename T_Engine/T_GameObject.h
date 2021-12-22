#pragma once
#include "T_Config.h"
#include "T_Vector3.h"
#include "T_Graph.h"

class T_GameObject{
public:
	T_GameObject();
	string name;
	T_Transform transform;
	vector<unique_ptr<T_Component>> componentArray;
	bool isDestroy = false;
	bool isActive = true;

};

static class T_GameObjectManager {
public:
	static vector<unique_ptr<T_GameObject>> gameObjectArray;
	static unique_ptr<T_GameObject>& AddGameObject(unique_ptr<T_GameObject> sprite);
	static void ClearGameObject();
	static unique_ptr<T_GameObject>& FindGameObject(string name);

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

class T_Transform {
public:
	T_Vector3 position;
	T_Vector3 rotation;
};

