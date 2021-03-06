#ifndef _Camera_H
#define _Camera_H

#define PI 3.14159265358979323846264338327950288		// Define PI for usage in positioning the camera's rotations
#define GLM_FORCE_RADIANS								// Make sure GLM is using radians instead of degrees

#include <fstream>
#include <glm\glm.hpp>									// Used for the GLM math library
#include <glm/gtc/matrix_transform.hpp>					// Used for the GLM math library
#include <glm/gtx/transform2.hpp>						// Used for the GLM math library
using namespace glm;


//////////// *** NEW *** ////////// *** NEW *** ///////////// *** NEW *** ////////////////////

// This is our bare-bones Camera class to manage user movement in our 3D scene.
// The next tutorials will add rotation and mouse support to our class.
class Camera 
{
public:

	Camera();

	// This sets and returns a perspective matrix that is build from the field of fiew, aspect ratio and near/far planes
	mat4 SetPerspective(float fov, float aspectRatio, float nearPlane, float farPlane);

	// This returns the current ProjectionMatrix
	mat4 GetProjectionMatrix() { return ProjectionMatrix; }

	// This returns the current view matrix according to the camera's position and rotation
	mat4 GetViewMatrix();

	// This sets and gets the camera's position
	void SetPosition(vec3 position)	{ Position = position; }
	vec3 GetPosition()	{ return Position; }

	// This calculates the current view vector from the rotation matrix (hard coded for now)
	vec3 GetView();

	// This sets and gets the Yaw and Pitch rotations (in radians)
	float GetYaw() { return Yaw; }
	void SetYaw(float yaw)	{ Yaw = yaw; }
	float GetPitch() { return Pitch; }
	void SetPitch(float pitch) { Pitch = pitch; }
	
	// This sets and gets the camera's movement speed
	void SetSpeed(double speed) { Speed = speed;  }
	double GetSpeed() { return Speed; }

	// This sets the Position and the yaw and pitch rotations (in radians)
	void PositionCamera(float positionX, float positionY, float positionZ, float yaw, float pitch);

	// This will move the camera forward or backwards depending on the speed (negative for backwards)
	void MoveCamera(float speed);

protected:

	mat4 ProjectionMatrix;								// The camera's projection matrix
	vec3 Position;										// The camera's position

	float Speed = 5.0;									// The camera's speed that is used with a time slice
	float Yaw = 0;										// The horizontal rotation angle (in radians), y-axis
	float Pitch = 0;									// The vertical rotation angle (in radians, x-axis
};


#endif 

//////////// *** NEW *** ////////// *** NEW *** ///////////// *** NEW *** ////////////////////


/////////////////////////////////////////////////////////////////////////////////
//
// * QUICK NOTES * 
//
// The camera class is used to be able to move a camera around in the world and
// take input from the user such as arrow keys, WASD keys or the mouse in a later
// tutorial.  Unlike our older tutorials, we now depend on matrices more to be
// able to calculate our camera vectors by our position and yaw/pitch rotations.
// We no longer store a view or up vector, but derive those from our rotation
// matrix which will be defined in the next tutorial.
//
// � 2000-2015 GameTutorials