//
// Created by yang on 2022/1/18.
//

#include "PlayerLogic.h"
#include "T_Scene.h"
#include "InputManager.h"
#include "Ghost.h"

void PlayerLogic::Update()
{
	bool shot = false;
	if (InputManager::GetInstance().GetKeyDown('J')) {
		shot = true;
	}
	for (auto& gameObject : T_Scene::activeScene->gameObjectManager->gameObjectArray) {
		if (gameObject->name == "Ghost") {
			if (shot) {
				float Pi = 3.14159265;
				float dir = atan2(
					gameObject->transform.position.z - this->gameObject.transform.position.z,
					gameObject->transform.position.x - this->gameObject.transform.position.x
				);
				float rot = this->gameObject.transform.rotation.x;
				while (dir - rot > Pi) dir -= 2 * Pi;
				while (dir - rot < -Pi) dir += 2 * Pi;
				if (dir - rot<0.5f && dir - rot>-0.5f) {
					for (auto& component : gameObject->componentArray) {
						if (component->GetComponentName() == "Ghost") {
							kill+=std::dynamic_pointer_cast<Ghost>(component)->BeHit();
							break;
						}
					}
				}
			}
			float tx = gameObject->transform.position.x - this->gameObject.transform.position.x;
			float tz = gameObject->transform.position.z - this->gameObject.transform.position.z;
			if (tx * tx + tz * tz < 4) {
				T_Scene::activeScene->renderManager->topText = L"��������Ӧ����������";
			}
			else {
				if (kill <= 5)
					T_Scene::activeScene->renderManager->topText = L"����Ҫ��ɱ��ֻ��������������";
				else
					T_Scene::activeScene->renderManager->topText = L"�쵽��������ȥ";
			}
			if (tx * tx + tz * tz < 0.09) {
				if (IDOK == MessageBox(NULL, L"�㱻����ץס��", L"������",
					MB_OKCANCEL)) {
					exit(0);
				}
			}
			else {
				float dirG = atan2(
					gameObject->transform.position.z - this->gameObject.transform.position.z,
					gameObject->transform.position.x - this->gameObject.transform.position.x
				)+3.1415926;
				gameObject->transform.position.x += 0.02 * cosf(dirG);
				gameObject->transform.position.z += 0.02 * sinf(dirG);
			}
		}
		if (gameObject->name == "Flag") {
			if (kill > 5) {
				float tx = gameObject->transform.position.x - this->gameObject.transform.position.x;
				float tz = gameObject->transform.position.z - this->gameObject.transform.position.z;
				if (tx * tx + tz * tz <= 0.25) {
					if (IDOK == MessageBox(NULL, L"������������", L"��Ӯ��",
						MB_OKCANCEL)) {
						exit(0);
					}
				}
			}
		}
	}
}
