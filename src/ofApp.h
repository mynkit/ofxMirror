#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
        void drawSetup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
        ofCamera mirrorCam;
        ofCamera viewerCam;
        ofFbo fbo;
    
        ofSpherePrimitive sphere;
        ofBoxPrimitive box;
        ofPlanePrimitive plane;
    
        float cameraPositionX;
        float cameraPositionY;
        float cameraPositionZ;
        float mirrorCamPositionX;
        float mirrorCamPositionY;
        float mirrorCamPositionZ;
        int azimuth;
        int elevation;
};
