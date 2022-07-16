#include "Common.h"
#include "DxLib.h"
#include <fstream>
#include <sstream>

Map::Map(std::string datFilePath) :
    m_datFilePath(datFilePath) {
    loadMapData();
    m_tilesetHandle = std::vector<int>(m_tileNumX * m_tileNumY);
    LoadDivGraph(m_tilesetFilePath.c_str(), m_tileNumX * m_tileNumY, m_tileNumX, m_tileNumY, m_tileSizeX, m_tileSizeY, m_tilesetHandle.data());
}

void Map::draw() {
    for (int i = 0; i < m_mapSizeY; i++) {
        for (int j = 0; j < m_mapSizeX; j++) {
            DrawGraph(m_tileSizeX * j, m_tileSizeY * i, m_tilesetHandle[m_mapData[j + i * m_mapSizeX]], TRUE);
        }
    }
}

MapCollideID Map::getMapCollideID(int x, int y) {
    int numX = x / m_tileSizeX;
    int numY = y / m_tileSizeY;
    if (numX < m_mapSizeX && numY < m_mapSizeY) {
        return m_passData[numX + numY * m_mapSizeX];
    }
    return MapCollideID::impassable;    //・マップ範囲外は通行不可
}

void Map::loadMapData() {
    const char DELIMITER = ',';
    std::ifstream ifs(m_datFilePath);
    std::istringstream iss;
    std::string line, field;

    if (ifs) {
        //・1行目：タイルセットファイルパス
        std::getline(ifs, line);
        m_tilesetFilePath = line;

        //・2行目：タイルサイズ、タイル数
        int i = 0;
        std::getline(ifs, line);
        iss = std::istringstream(line);
        while (std::getline(iss, field, DELIMITER)) {
            switch (i++) {
            case 0:
                m_tileSizeX = stoi(field);
                break;
            case 1:
                m_tileSizeY = stoi(field);
                break;
            case 2:
                m_tileNumX = stoi(field);
                break;
            default:
                m_tileNumY = stoi(field);
            }
        }

        //・3行目：マップサイズ
        i = 0;
        std::getline(ifs, line);
        iss = std::istringstream(line);
        while (std::getline(iss, field, DELIMITER)) {
            switch (i++) {
            case 0:
                m_mapSizeX = stoi(field);
                break;
            default:
                m_mapSizeY = stoi(field);
            }
        }

        //・4行目以降：マップデータ
        for (int i = 0; i < m_mapSizeY; i++) {
            std::getline(ifs, line);
            iss = std::istringstream(line);
            for (int j = 0; j < m_mapSizeX; j++) {
                std::getline(iss, field, DELIMITER);
                m_mapData.emplace_back(stoi(field));
            }
        }
        //・通行設定
        for (int i = 0; i < m_mapSizeY; i++) {
            std::getline(ifs, line);
            iss = std::istringstream(line);
            for (int j = 0; j < m_mapSizeX; j++) {
                std::getline(iss, field, DELIMITER);
                m_passData.emplace_back(static_cast<MapCollideID>(stoi(field)));
            }
        }
    }
}