#pragma once
#include "Map.h"
#include "Player.h"
#include "EnemyMushroom.h"
#include <memory>

class Map;

/** @brief �Q�[���S�̂��Ǘ�����}�l�[�W���N���X */
class GameManager {
public:
	/**
	 * @brief �Q�[���̃��C������
	 */
	void main();

private:
	/**
	 * @brief ����������
	 */
	void init();

	/**
	 * @brief �`��O�̍X�V����
	 */
	void update();

	/**
	 * @brief �`�揈��
	 */
	void draw();

	/** @brief ���݂̃}�b�v���w���|�C���^ */
	std::unique_ptr<Map> mapPtr;

	/** @brief �v���C���[�L�����N�^�[���w���|�C���^ */
	std::unique_ptr<Player> playerPtr;

	//�ETODO�FEnemy��Manager�Ǘ��ɂ���
	/** @brief �G�L�����N�^�[���Ǘ�����}�l�[�W�����w���|�C���^ */
	std::unique_ptr<EnemyMushroom> mushroomPtr;
};

/** @brief �Q�[���}�l�[�W�� */
extern std::unique_ptr<GameManager> gameManagerPtr;