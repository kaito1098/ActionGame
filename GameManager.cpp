#include "Common.h"
#include "DxLib.h"

void GameManager::main() {
	init();
	SetDrawScreen(DX_SCREEN_BACK);

	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {
		update();
		draw();
	}
}

std::shared_ptr<Map> GameManager::getMapPtr() {
	return mapPtr;
}

void GameManager::init() {
	//�E�I�u�W�F�N�g����
	mapPtr = std::make_shared<Map>("Data/Tileset/mapA.dat");
	playerPtr = std::make_unique<Player>(100, 200);
	mushroomPtr = std::make_unique<EnemyMushroom>(500, GROUND_HEIGHT);
	//�E���y��炷�iTODO�F���y�̓V�[���}�l�[�W���Ƃ��ŊǗ��H�j
	int sound = LoadSoundMem("Data/Test/Forest.wav");
	SetLoopSamplePosSoundMem(384000, sound);
	ChangeVolumeSoundMem(128, sound);
	PlaySoundMem(sound, DX_PLAYTYPE_LOOP);
}

void GameManager::update() {
	playerPtr->update();
	mushroomPtr->update();
}

void GameManager::draw() {
	//�ETODO�F�v���C���[�̒��S���W���擾���郁�\�b�h���~����
	//�E�X�N���[���ʒu�̐ݒ�i�v���C���[�𒆐S�ɁB�������}�b�v�̈�O�͉f���Ȃ��j
	std::array<int, 2> pos = playerPtr->getCenterPosition();
	screenX = min(mapPtr->getMapWidth() - SCREEN_WIDTH, max(0, pos[0] - SCREEN_WIDTH / 2));
	screenY = min(mapPtr->getMapHeight() - SCREEN_HEIGHT, max(0, pos[1] - SCREEN_HEIGHT / 2));
	//�ETODO�F�edraw�ŃI�t�Z�b�g�̐ݒ肪�ł���悤��
	mapPtr->draw(screenX, screenY);
	playerPtr->draw(screenX, screenY);
	mushroomPtr->draw(screenX, screenY);
}

std::unique_ptr<GameManager> gameManagerPtr = std::make_unique<GameManager>();