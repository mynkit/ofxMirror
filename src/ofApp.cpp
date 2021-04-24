#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(189, 205, 238);
    
    box.set(5);
    box.setPosition(20, 0, 0);
    sphere.set(10, 10);
    sphere.setPosition(10, 0, -20);
    
    fbo.allocate(300, 300, GL_RGBA);
    
    
    // camera setting
    azimuth = 0;
    elevation = 0;
    viewerCam.setScale(ofVec3f(0.01, 0.01, 0.01));
    mirrorCam.setScale(ofVec3f(0.01, 0.01, 0.01));
    
    cameraPositionX = 10;
    cameraPositionY = 0;
    cameraPositionZ = 20;
    
    mirrorCamPositionX = 0;
    mirrorCamPositionY = 0;
    mirrorCamPositionZ = 0;
    
    plane.set(10, 10);
    plane.setPosition(mirrorCamPositionX, mirrorCamPositionY, mirrorCamPositionZ);
    plane.rotate(90, ofVec3f(0, 1, 0));
    
    mirrorCam.setPosition(mirrorCamPositionX, mirrorCamPositionY, mirrorCamPositionZ);
    
    ofEnableNormalizedTexCoords();
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::drawSetup(){
    ofSetColor(100, 200, 255);
    sphere.drawWireframe();
    ofSetColor(50, 55, 255);
    box.drawWireframe();
}

//--------------------------------------------------------------
void ofApp::update(){
    viewerCam.setPosition(cameraPositionX, cameraPositionY, cameraPositionZ);

    mirrorCam.lookAt(ofVec3f(
                             cameraPositionX,
                             mirrorCamPositionY + (mirrorCamPositionY - cameraPositionY),
                             mirrorCamPositionZ + (mirrorCamPositionZ - cameraPositionZ)
                             ));
    
    fbo.begin();
    ofClear(184, 200, 233);
    mirrorCam.begin();
    drawSetup();
    mirrorCam.end();
    fbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);

    ofPixels pixels;
    fbo.readToPixels(pixels);
    ofImage image;
    image.setFromPixels(pixels);
    image.mirror(0, 1);

    viewerCam.begin();
    
    ofSetColor(184, 200, 233);
    plane.draw();
    image.bind();
    plane.draw();
    image.unbind();

    drawSetup();
    
    viewerCam.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    float positionVerocity = 1;
    int degreeVerocity = 10;
    switch (key) {
    case 'w':
        cameraPositionZ -= cos(ofDegToRad(azimuth)) * positionVerocity;
        cameraPositionX -= sin(ofDegToRad(azimuth)) * positionVerocity;
        break;
    case 'a':
        cameraPositionX -= cos(ofDegToRad(azimuth)) * positionVerocity;
        cameraPositionZ += sin(ofDegToRad(azimuth)) * positionVerocity;
        break;
    case 's':
        cameraPositionZ += cos(ofDegToRad(azimuth)) * positionVerocity;
        cameraPositionX += sin(ofDegToRad(azimuth)) * positionVerocity;
        break;
    case 'd':
        cameraPositionX += cos(ofDegToRad(azimuth)) * positionVerocity;
        cameraPositionZ -= sin(ofDegToRad(azimuth)) * positionVerocity;
        break;
    case OF_KEY_UP:
        if(elevation<90){
            viewerCam.rotate(degreeVerocity, ofVec3f(cos(ofDegToRad(azimuth)), 0, -sin(ofDegToRad(azimuth))));
            elevation += degreeVerocity;
        }
        break;
    case OF_KEY_DOWN:
        if(elevation>-90){
            viewerCam.rotate(-degreeVerocity, ofVec3f(cos(ofDegToRad(azimuth)), 0, -sin(ofDegToRad(azimuth))));
            elevation -= degreeVerocity;
        }
        break;
    case OF_KEY_LEFT:
        viewerCam.rotate(degreeVerocity, ofVec3f(0, 1, 0));
        azimuth += degreeVerocity;
        break;
    case OF_KEY_RIGHT:
        viewerCam.rotate(-degreeVerocity, ofVec3f(0, 1, 0));
        azimuth -= degreeVerocity;
        break;
    case 'k':
        cameraPositionY += positionVerocity;
        break;
    case 'j':
        cameraPositionY -= positionVerocity;
        break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
