#pragma once
#include "Common.h"
#include <vector>
#include <string>

enum class MapCollideID;

/** @brief �}�b�v�̊��N���X */
class Map {
public:
    /**
     * @brief �R���X�g���N�^
     * @param (datFilePath) dat�t�@�C���p�X
     * @details �^�C���Z�b�g�摜�̓Ǎ������͂����ōs���Ă���B
     */
    Map(std::string datFilePath);

    /**
     * @brief �y���z�֐��z�f�X�g���N�^
     */
    virtual ~Map() = default;

    /**
     * @brief �}�b�v�̕`�揈��
     */
    void draw();

private:
    /** @brief dat�t�@�C���p�X */
    std::string m_datFilePath;

    /** @brief �^�C���Z�b�g�t�@�C���p�X */
    std::string m_tilesetFilePath;

    /** @brief �^�C���Z�b�g�n���h�� */
    std::vector<int> m_tilesetHandle;

    /** @brief �^�C���T�C�Y�ix�������j */
    int m_tileSizeX;

    /** @brief �^�C���T�C�Y�iy�������j */
    int m_tileSizeY;

    /** @brief �^�C���������ix�������j */
    int m_tileNumX;

    /** @brief �^�C���������iy�������j */
    int m_tileNumY;

    /** @brief �}�b�v�T�C�Y�ix�������j */
    int m_mapSizeX;

    /** @brief �}�b�v�T�C�Y�iy�������j */
    int m_mapSizeY;

    /** @brief �}�b�v�f�[�^�i�P�}�X���ƂɎw�肳���^�C��ID�̃��X�g�j */
    std::vector<int> m_mapData;

    /**
     * @brief �ʍs�ݒ�i�P�}�X���ƂɎw�肳���ʍs�ݒ�j
     * @details �ʍs�ݒ�͗񋓑�MapCollideID�ɂ���ĕ\�������
     */
    std::vector<MapCollideID> m_passData;

    /**
     * @brief �}�b�v�f�[�^�̓Ǎ�����
     * @param (datFilePath) dat�t�@�C���p�X
     */
    void loadMapData();
};