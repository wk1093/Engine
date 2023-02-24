#pragma once
#include "apiHeader.h"

#include "Vertex.h"

namespace Engine {

    class Mesh {
    private:
        static std::vector<std::string> split(const std::string& s, char delim) {
            std::vector<std::string> elems;
            std::stringstream ss(s);
            std::string item;
            while (std::getline(ss, item, delim)) {
                elems.push_back(item);
            }
            return elems;
        }
    public:
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        Mesh() = default;
        Mesh(const std::vector<Vertex>& v, const std::vector<unsigned int>& i) {
            vertices = v;
            indices = i;
        }

        Mesh(const std::string& objFile, const Color& c) {
            // Load obj file
            std::ifstream file;
            file.open(objFile);
            if (!file.is_open()) {
                std::cout << "Failed to open file: " << objFile << std::endl;
                return;
            }
            std::string line;
            std::vector<Vector3f> positions;
            std::vector<Vector2f> uvs;
            std::vector<Vector3f> normals;

            std::vector<unsigned int> outi;
            std::vector<Vertex> outv;

            // for each line, add positions, uvs, and normals to their respective vectors
            // for each index in obj file, add the corresponding vertex (generated) to the outv vector if it doesn't already exist, then add the index to the outi vector

            // Read file
            while (std::getline(file, line)) {
                std::stringstream ss(line);
                std::string type;
                ss >> type;
                if (type == "v") {
                    float x, y, z;
                    ss >> x >> y >> z;
                    positions.emplace_back(x, y, z);
                } else if (type == "vt") {
                    float u, v;
                    ss >> u >> v;
                    uvs.emplace_back(u, v);
                } else if (type == "vn") {
                    float x, y, z;
                    ss >> x >> y >> z;
                    normals.emplace_back(x, y, z);
                } else if (type == "f") { // ex f 1/1/1 2/2/2 3/3/3 - each is triangle
                    std::string v1, v2, v3;
                    ss >> v1 >> v2 >> v3;
                    std::vector<std::string> v1s = split(v1, '/'); // ex v1s = {"1", "1", "1"}
                    std::vector<std::string> v2s = split(v2, '/'); // ex v2s = {"2", "2", "2"}
                    std::vector<std::string> v3s = split(v3, '/'); // ex v3s = {"3", "3", "3"}
                    std::vector<std::vector<std::string>> vss = {v1s, v2s, v3s}; // ex vss = {{"1", "1", "1"}, {"2", "2", "2"}, {"3", "3", "3"}}
                    for (auto& vs : vss) {
                        unsigned int n = vs.size();
                        Vertex v;
                        if (n == 0) {
                            std::cout << "Invalid obj file: " << objFile << std::endl;
                            return;
                        }
                        if (n == 1) {
                            v = Vertex(positions[std::stoi(vs[0]) - 1], Vector2f(0, 0), c);
                        }
                        if (n == 2) {
                            v = Vertex(positions[std::stoi(vs[0]) - 1], uvs[std::stoi(vs[1]) - 1], c);
                        }
                        if (n == 3) {
                            v = Vertex(positions[std::stoi(vs[0]) - 1], uvs[std::stoi(vs[1]) - 1], c); // TODO: normals
                        }

                        int index = -1;
                        for (int i = 0; i < outv.size(); i++) {
                            if ((Vertex)outv[i] == (Vertex)v) {
                                index = i;
                                break;
                            }
                        }
                        if (index != -1) {
                            outi.push_back(index);
                            continue;
                        }

                        outv.push_back(v);
                        outi.push_back(outv.size() - 1);
                    }
                }
            }

            vertices = outv;
            indices = outi;


        }
    };
}
