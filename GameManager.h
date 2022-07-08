#pragma once
#include "Player.h"
#include "EnemyMushroom.h"
#include <memory>

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

	/** @brief �v���C���[�L�����N�^�[���w���|�C���^ */
	std::unique_ptr<Player> playerPtr;

	//�ETODO�FEnemy��Manager�Ǘ��ɂ���
	/** @brief �G�L�����N�^�[���Ǘ�����}�l�[�W�����w���|�C���^ */
	std::unique_ptr<EnemyMushroom> mushroomPtr;
};