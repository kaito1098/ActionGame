#include "DxLib.h"
#include "BaseMap.h"
#include <fstream>
#include <sstream>

BaseMap::BaseMap(std::string datFilePath) :
    m_datFilePath(datFilePath) {
    loadMapData();
    m_tilesetHandle = std::vector<int>(m_tileNumX * m_tileNumY);
    LoadDivGraph(m_tilesetFilePath.c_str(), m_tileNumX * m_tileNumY, m_tileNumX, m_tileNumY, m_tileSizeX, m_tileSizeY, m_tilesetHandle.data());
}

void BaseMap::draw() {
    for (int i = 0; i < m_mapSizeX; i++) {
        for (int j = 0; j < m_mapSizeY; j++) {
            DrawGraph(m_tileSizeX * i, m_tileSizeY * j, m_tilesetHandle[m_mapData[i + j * 20]], TRUE);
        }
    }
}

void BaseMap::loadMapData() {
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
        while (std::getline(ifs, line)) {
            iss = std::istringstream(line);
            while (std::getline(iss, field, DELIMITER)) {
                m_mapData.emplace_back(stoi(field));
            }
        }
    }
}