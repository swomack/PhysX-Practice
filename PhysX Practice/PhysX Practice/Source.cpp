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
	static PxDefaultErrorCallback gDefaultErrorCallback;
	static PxDefaultAllocator gDefaultAllocator;

	static PxFoundation* gFoundation = NULL;

	gFoundation = PxCreateFoundation(PX_PHYSICS_VERSION, gDefaultAllocator, gDefaultErrorCallback);

	if (gFoundation == NULL)
	{
		cout << "Error creating foundation!"<<endl;
		return finish();
	}


	static PxPhysics* gPhysicsSDK = NULL;

	gPhysicsSDK = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale());

	if (gPhysicsSDK == NULL)
	{
		cout << "Error creating Physics SDK!" << endl;
		return finish();
	}




	return finish();
}