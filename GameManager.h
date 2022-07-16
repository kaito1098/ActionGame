#pragma once
#include <memory>

class Map;
class Player;
class EnemyMushroom;

/** @brief �Q�[���S�̂��Ǘ�����}�l�[�W���N���X */
class GameManager {
public:
	/**
	 * @brief �Q�[���̃��C������
	 */
	void main();

	/**
	 * @brief ���݂̃}�b�v���w���|�C���^���擾
	 * @return ���݂̃}�b�v���w���|�C���^
	 */
	std::shared_ptr<Map> getMapPtr();

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
	std::shared_ptr<Map> mapPtr;

	/** @brief �v���C���[�L�����N�^�[���w���|�C���^ */
	std::unique_ptr<Player> playerPtr;

	//�ETODO�FEnemy��Manager�Ǘ��ɂ���
	/** @brief �G�L�����N�^�[���Ǘ�����}�l�[�W�����w���|�C���^ */
	std::unique_ptr<EnemyMushroom> mushroomPtr;
};

/** @brief �Q�[���}�l�[�W�� */
extern std::unique_ptr<GameManager> gameManagerPtr;