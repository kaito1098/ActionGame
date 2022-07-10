#pragma once
#include <vector>
#include <string>

/** @brief �}�b�v�̊��N���X */
class BaseMap {
public:
    /**
     * @brief �R���X�g���N�^
     * @param (datFilePath) dat�t�@�C���p�X
     * @details �^�C���Z�b�g�摜�̓Ǎ������͂����ōs���Ă���B
     */
    BaseMap(std::string datFilePath);

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
     * @details �ʍs�ݒ��4�r�b�g�ŕ\������B
     * @details 1�r�b�g�ڂ����A�E�A���A���̒ʍs�ݒ�ŁA0�F�ʍs�A1�F�ʍs�s�B
     * @details ��j0000�F�S�����ʍs�A1100�F��ƉE�̂ݒʍs�A1111�F�S�����ʍs�s��
     */
    std::vector<unsigned int> m_passData;

    /**
     * @brief �}�b�v�f�[�^�̓Ǎ�����
     * @param (datFilePath) dat�t�@�C���p�X
     */
    void loadMapData();
};