#pragma once

#include <vector>
#include "GLM/glm.hpp"
#include "Sphere.h"
#include "Ray.h"

class RayTracer
{
public:
	RayTracer();
	~RayTracer();
	
	std::vector<Sphere*>objects;

	glm::vec3 TraceRay(Ray _ray);

};