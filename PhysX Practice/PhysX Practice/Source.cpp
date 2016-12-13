#include <iostream>
#include <PxPhysicsAPI.h>

using namespace std;
using namespace physx;

int main()
{
	static PxDefaultErrorCallback gDefaultErrorCallback;
	static PxDefaultAllocator gDefaultAllocator;

	static PxFoundation* gFoundation = NULL;

	gFoundation = PxCreateFoundation(PX_PHYSICS_VERSION, gDefaultAllocator, gDefaultErrorCallback);



	return 0;
}