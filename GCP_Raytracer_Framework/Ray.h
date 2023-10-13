#pragma once
#include "GLM/glm.hpp"

class Ray
{
public:
	Ray();
	~Ray();
	glm::vec3 origin;
	glm::vec3 direction;

};

