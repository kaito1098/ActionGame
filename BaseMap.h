#pragma once
#include <vector>
#include <string>

/** @brief マップの基底クラス */
class BaseMap {
public:
    /**
     * @brief コンストラクタ
     * @param () datファイルパス
     * @details タイルセット画像の読込処理はここで行っている。
     */
    BaseMap(std::string datFilePath);

    /**
     * @brief マップの描画処理
     */
    void draw();
    
private:
    /** @brief datファイルパス */
    std::string m_datFilePath;

    /** @brief タイルセットファイルパス */
    std::string m_tilesetFilePath;

    /** @brief タイルセットハンドル */
    std::vector<int> m_tilesetHandle;

    /** @brief タイルサイズ（x軸方向） */
    int m_tileSizeX;

    /** @brief タイルサイズ（y軸方向） */
    int m_tileSizeY;

    /** @brief タイル分割数（x軸方向） */
    int m_tileNumX;

    /** @brief タイル分割数（y軸方向） */
    int m_tileNumY;

    /** @brief マップサイズ（x軸方向） */
    int m_mapSizeX;

    /** @brief マップサイズ（y軸方向） */
    int m_mapSizeY;

    /** @brief マップデータ（１マスごとに指定されるタイルIDのリスト） */
    std::vector<int> m_mapData;

    /**
     * @brief マップデータの読込処理
     * @param (datFilePath) datファイルパス
     * @return 戻り値の説明
     */
    void loadMapData();
};