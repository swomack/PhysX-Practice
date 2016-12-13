#include <iostream>
#include <PxPhysicsAPI.h>

using namespace std;
using namespace physx;

int finish()
{
	getchar();
	return 0;
}

int main()
{
	// create foundation
	static PxDefaultErrorCallback gDefaultErrorCallback;
	static PxDefaultAllocator gDefaultAllocator;
	static PxFoundation* gFoundation = NULL;

	gFoundation = PxCreateFoundation(PX_PHYSICS_VERSION, 
		gDefaultAllocator, gDefaultErrorCallback);

	if (gFoundation == NULL)
	{
		cout << "Error creating foundation!"<<endl;
		return finish();
	}


	// create physX SDK
	static PxPhysics* gPhysicsSDK = NULL;

	gPhysicsSDK = PxCreatePhysics(PX_PHYSICS_VERSION, 
		*gFoundation, PxTolerancesScale());

	if (gPhysicsSDK == NULL)
	{
		cout << "Error creating Physics SDK!" << endl;
		return finish();
	}

	// create scene
	PxScene* gScene = NULL;
	PxSceneDesc gSceneDesc(gPhysicsSDK->getTolerancesScale());
	gSceneDesc.gravity = PxVec3(0, -9.8f, 0);
	gSceneDesc.cpuDispatcher = PxDefaultCpuDispatcherCreate(1);
	gSceneDesc.filterShader = PxDefaultSimulationFilterShader;

	gScene = gPhysicsSDK->createScene(gSceneDesc);
	
	if (gScene == NULL)
	{
		cout << "Error creating physX Scene!" << endl;
		return finish();
	}

	// Creating material for actor
	// three parameters are satatic friction, dynamic frixtion and restitution(bounciness)
	PxMaterial* gMaterial = gPhysicsSDK->createMaterial(0.5, 0.5, 0.5);


	// Create Plane - static rigid body (actor)
	// First position in the world then rotation as quaternion
	PxTransform gPlaneTransform(PxVec3(0.0f, 0.0f, 0.0f),
		PxQuat(PxHalfPi, PxVec3(0.0f, 0.0f, 1.0f)));

	PxRigidStatic* plane = gPhysicsSDK->createRigidStatic(gPlaneTransform);
	plane->createShape(PxPlaneGeometry(), *gMaterial);
	
	// add plane to the scene
	gScene->addActor(*plane);


	return finish();
}