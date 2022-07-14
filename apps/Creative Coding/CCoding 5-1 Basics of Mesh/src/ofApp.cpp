#include "ofApp.h"

void ofApp::setup(){
    plane.set(1000, 1000, 100, 100);
    mesh = plane.getMesh();
}

void ofApp::update(){
}

void ofApp::draw(){
    cam.begin();
    vector<glm::vec3> vertices = mesh.getVertices();
    float freq = 0.02;
    float height = 50.0;
    for (int i = 0; i < vertices.size(); i++) {
        float x = vertices[i].x;
        float y = vertices[i].y;
        float zx = sin(x * freq + ofGetElapsedTimef()) * height;
        float zy = sin(y * freq + ofGetElapsedTimef()) * height;
        float z = zx + zy;
        mesh.setVertex(i, glm::vec3(x, y, z));
    }
    mesh.drawWireframe();
    cam.end();
}
