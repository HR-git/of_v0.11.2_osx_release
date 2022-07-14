#include "ofApp.h"

void ofApp::setup() {
    ofSetFrameRate(60);
    ofBackground(0);
    fft.setup();
    fft.setNumFFTBins(16);
    fft.setNormalize(true);
    ofIcoSpherePrimitive sphere;
    sphere.setRadius(100);
    sphere.setResolution(4);
    mesh = sphere.getMesh();
    light.setPosition(-400, 400, 800);
    light.enable();
    material.setAmbientColor(ofColor(127, 127, 255));
    material.setDiffuseColor(ofColor(0, 127, 255));
    material.setSpecularColor(ofColor(255, 255, 0, 127));
    material.setShininess(120);
}

void ofApp::update() {
    fft.update();
    
    float lowDiv = 900.0;
    float lowSize = ofMap(fft.getLowVal(), 0, 1, 10.0, 100.0);
    float midDiv = 300.0;
    float midSize = ofMap(fft.getMidVal(), 0, 1, 10.0, 400.0);
    float highDiv = 100.0;
    float highSize = ofMap(fft.getHighVal(), 0, 1, 10.0, 600.0);
    for (int i = 0; i < mesh.getVertices().size(); i++) {
        glm::vec3 loc = mesh.getVertices()[i];
        float low = ofMap(ofNoise(loc.x / lowDiv, loc.y / lowDiv, loc.z / lowDiv, ofGetElapsedTimef()), 0, 1, lowSize / 2.0, lowSize);
        float mid = ofMap(ofNoise(loc.x / midDiv, loc.y / midDiv, loc.z / midDiv, ofGetElapsedTimef()), 0, 1, midSize / 2.0, midSize);
        float high = ofMap(ofNoise(loc.x / highDiv, loc.y / highDiv, loc.z / highDiv, ofGetElapsedTimef()), 0, 1, highSize / 2.0, highSize);
        float noise = low + mid + high;
        glm::vec3 newLoc = glm::normalize(loc) * noise;
        mesh.setVertex(i, newLoc);
    }
}

void ofApp::draw() {
    ofEnableDepthTest();
    material.begin();
    cam.begin();
    ofRotateXDeg(ofGetElapsedTimef() * 10.0);
    ofRotateYDeg(ofGetElapsedTimef() * 15.0);
    mesh.drawWireframe();
    cam.end();
    material.end();
    ofDisableDepthTest();
}

