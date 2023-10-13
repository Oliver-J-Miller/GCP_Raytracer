#pragma once
#include "GLM/glm.hpp"
#include "Ray.h"

class Camera
{
public:
	Camera();
	~Camera();

	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;
	glm::mat4 modelMatrix;

	Ray GetRay(glm::ivec2 _windowPosition);

};
