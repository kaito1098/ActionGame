#pragma once
#include <vector>
#include <string>

/** @brief マップの基底クラス */
class Map {
public:
    /**
     * @brief コンストラクタ
     * @param (datFilePath) datファイルパス
     * @details タイルセット画像の読込処理はここで行っている。
     */
    Map(std::string datFilePath);

    /**
     * @brief 【仮想関数】デストラクタ
     */
    virtual ~Map() = default;

    /**
     * @brief マップの描画処理
     */
    void draw();

    /**
     * @brief 指定座標の MapCollideID を取得する
     * @param (x) x座標
     * @param (y) y座標
     * @return マップ当たり判定種別
     */
    bool checkPassable(int x, int y);

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

    /** @brief マップサイズ（x軸方向、単位：タイル数） */
    int m_mapSizeX;

    /** @brief マップサイズ（y軸方向、単位：タイル数） */
    int m_mapSizeY;

    /** @brief マップデータ（１マスごとに指定されるタイルIDのリスト） */
    std::vector<int> m_mapData;

    /**
     * @brief 通行設定（１マスごとに指定される通行設定）
     * @details 通行設定は列挙帯MapCollideIDによって表現される
     */
    std::vector<MapCollideID> m_passData;

    /**
     * @brief マップデータの読込処理
     * @param (datFilePath) datファイルパス
     */
    void loadMapData();
};