#pragma once
#include <vector>
#include <string>

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
     * @param (screenX) �X�N���[�����W�ix�������j
     * @param (screenY) �X�N���[�����W�iy�������j
     */
    void draw(int screenX, int screenY);

    /**
     * @brief �w����W�� MapCollideID ���擾����
     * @param (x) x���W
     * @param (y) y���W
     * @return �}�b�v�����蔻����
     */
    bool checkPassable(int x, int y);

    /**
     * @brief �}�b�v�S�̂̉������擾����
     * @return �}�b�v�S�̂̉���
     */
    int getMapWidth();

    /**
     * @brief �}�b�v�S�̂̏c�����擾����
     * @return �}�b�v�S�̂̏c��
     */
    int getMapHeight();

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

    /** @brief �}�b�v�T�C�Y�ix�������A�P�ʁF�^�C�����j */
    int m_mapSizeX;

    /** @brief �}�b�v�T�C�Y�iy�������A�P�ʁF�^�C�����j */
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