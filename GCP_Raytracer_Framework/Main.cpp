
#include "GCP_GFX_Framework.h"
#include "Ray.h"
#include "Ray_Tracer.h"
#include "Sphere.h"
#include "Camera.h"




int main(int argc, char* argv[])
{
	// Set window size
	glm::ivec2 winSize(640, 480);

	// This will handle rendering to screen
	GCP_Framework _myFramework;

	// Initialises SDL and OpenGL and sets up a framebuffer
	if (!_myFramework.Init(winSize))
	{
		return -1;
	}




	// Preparing a position to draw a pixel
	glm::ivec2 pixelPosition = winSize / 2;

	// Preparing a colour to draw
	// Colours are RGB, each value ranges between 0 and 1
	glm::vec3 pixelColour(1, 0, 0);


	// Sets all pixels the same colour
	_myFramework.SetAllPixels( glm::vec3(0.1f,0.1f,0.3f) );

	// Draws a single pixel
	_myFramework.DrawPixel(pixelPosition, pixelColour);

	RayTracer rayTracer;
	Camera camera;

	for (unsigned int x = 0; x < winSize.x; x++)
	{
		for (unsigned int y = 0; y < winSize.y; y++)
		{
			Ray r = camera.GetRay(glm::ivec2(x,y));
			glm::vec3 colour = rayTracer.TraceRay(r); /*glm::vec3(x / (float)winSize.x, y / (float)winSize.y, 1.0f)*/;
			_myFramework.DrawPixel(glm::ivec2(x,y), colour);
		}
	}
	

	// Pushes the framebuffer to OpenGL and renders to screen
	// Also contains an event loop that keeps the window going until it's closed
	_myFramework.ShowAndHold();
	return 0;


}
