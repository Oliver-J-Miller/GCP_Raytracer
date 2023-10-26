#pragma once
#include "GLM/glm.hpp"
#include "Ray.h"


struct RayInfo
{
	bool intersect;
	glm::vec3 iP;
};

class Sphere
{	
public:
	Sphere(glm::vec3 pos, float r, glm::vec3 mat);
	~Sphere();


	RayInfo RayIntersect(Ray _ray);
	glm::vec3 Shade(glm::vec3 _intersectPoint);
	glm::vec3 GetNormal(glm::vec3 _point);

	

protected:

	glm::vec3 position;
	float radius;

	glm::vec3 matColour;
	glm::vec3 lightSource;
};
