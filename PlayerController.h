#pragma once
#include "T_Engine/T_GameObject.h"
class PlayerController:
	public T_Component
{
public:
	/// <summary>
	/// ��������ٶ�
	/// </summary>
	const float v = 0.3;
	void Update() override;
};

