#pragma once

#include "ofMain.h"

#include "ofxAutoControlPanel.h"
#include "DepthVisualizerInput.h"
#include "btBulletDynamicsCommon.h"
#include "btHeightfieldTerrainShape.h"
#include "ballMotionState.cpp"
#include "btGhostObject.h"
#include "ofxOBJModel.h"
#include "ofxVec3f.h"

#include "ofxQTVideoSaver.h"


class testApp : public ofBaseApp {
	
	public:

		void setup();
		void update();
		void draw();
		void exit();
  
    void setupBulletWorld();
    void localCreateRigidBody(btHeightfieldTerrainShape *t);

		void keyPressed  (int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);

  
  ofColor colorFromVertex(float v);

  void dropBalls();
  
		ofxAutoControlPanel panel;
  
    btDiscreteDynamicsWorld* dynamicsWorld;
    
    vector<btRigidBody*> fallRigidBodies;
  
    vector<ballMotionState*> ballMSes;
    vector<ofPoint> ballPositions;
      
    GLUquadricObj *quadratic;


    bool heightFieldCreated;
    btHeightfieldTerrainShape * heightfieldShape;
		DepthVisualizerInput input;
  
  
  btBroadphaseInterface* broadphase;
  btDefaultCollisionConfiguration* collisionConfiguration;
  btCollisionDispatcher* dispatcher;
  btSequentialImpulseConstraintSolver* solver;
  btCollisionShape* fallShape;
  btCollisionShape* groundShape;
  btRigidBody* groundRigidBody;
  btDefaultMotionState* groundMotionState;
  
  ofxOBJModel model;

  ofImage skyImage;
  ofTexture skyTexture;
  ofTextureData skyTextureData;
  
  
  // VIDEO
//  ofVideoGrabber vid;

  
  ofxQtVideoSaver saver;
  bool bRecording;
  ofImage fullAppBuffer;
};
