#pragma once
#include "GLM/glm.hpp"
#include "Ray.h"

class Sphere
{
public:
	Sphere();
	~Sphere();

	glm::vec3 position;
	float radius;

	bool RayIntersect(Ray _ray);
	glm::vec3 Shade(glm::vec3 _intersectPoint);
	glm::vec3 GetNormal(glm::vec3 _point);
};
