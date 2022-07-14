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
    float div = 200.0;
    float height = 300.0;
    float speed = 0.25;
    for (int i = 0; i < vertices.size(); i++) {
        float x = vertices[i].x;
        float y = vertices[i].y;
        float z = ofNoise(
            vertices[i].x / div,
            vertices[i].y / div,
            0,
            ofGetElapsedTimef() * speed
        );
        z = ofMap(z, 0, 1, 0, height);
        mesh.setVertex(i, glm::vec3(x, y, z));
    }
    mesh.drawWireframe();
    cam.end();
}
