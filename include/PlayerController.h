#pragma once
#include "T_GameObject.h"
class PlayerController:
	public T_Component
{
public:
	/// <summary>
	/// ��������ٶ�
	/// </summary>
	explicit PlayerController(T_GameObject& gameObject) :T_Component(gameObject) {};
	const float v = 0.05;
	void Update() override;
};

