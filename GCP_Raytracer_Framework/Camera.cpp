#include "Camera.h"

Camera::Camera()
{

}

Camera::~Camera()
{
}

Ray Camera::GetRay(glm::ivec2 _windowPosition)
{
	Ray r;
	r.origin = glm::vec3(0,0,0);
	r.direction = glm::vec3(0, 0, -1);

	return Ray();
}
